#include "GLShaderProgram.h"

#include <fstream>

#include "../../../glad/glad.h"
#include "../../io/Console.h"

namespace vt {

	GLShaderProgram::GLShaderProgram()
	{
	}

	GLShaderProgram::~GLShaderProgram()
	{
	}

	void GLShaderProgram::initialize()
	{
		m_program = glCreateProgram();
	}

	void GLShaderProgram::cleanup()
	{
		deleteShaders();
		glDeleteProgram(m_program);
	}

	void GLShaderProgram::addShader(const String& source, const ShaderType& type)
	{
		ui32 shader;
		switch (type) {
		case SHADERTYPE_VERTEX: shader = glCreateShader(GL_VERTEX_SHADER); break;
		case SHADERTYPE_FRAGMENT: shader = glCreateShader(GL_FRAGMENT_SHADER); break;
		case SHADERTYPE_GEOMETRY: shader = glCreateShader(GL_GEOMETRY_SHADER); break;
		case SHADERTYPE_COMPUTE: shader = glCreateShader(GL_COMPUTE_SHADER); break;
		default: log::error("Invalid shader type: ", type); break;
		}
		m_shaders.push_back(shader);

		cString cstr = source.c_str();
		glShaderSource(shader, 1, &cstr, nullptr);
		glCompileShader(shader);

		i32 status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			i32 maxLength;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &maxLength, infoLog.data());

			log::error("Failed to compile shader (type: ", type, "):\n\n", infoLog.data(), "\n\n");
		}

		glAttachShader(m_program, shader);

		Vector<String> lines = splitString(source, "\n");
		for (ui32f i = 0; i < lines.size(); i++) {
			Vector<String> tokens = splitString(lines[i], " ");
			if (tokens.size() < 3) continue;
			if (tokens[0] == "uniform") {
				m_uniforms[tokens[2].substr(0, tokens[2].length() - 1)] = 0;
			}
		}
	}

	void GLShaderProgram::loadShader(cString file, const ShaderType& type)
	{
		std::ifstream in(file);
		if (!in.is_open()) {
			log::error(std::string("Could not find shader file: \"") + file + "\"");
			return;
		}
		std::string source;
		std::string line;
		while (std::getline(in, line)) {
			source += line + "\n";
		}
		addShader(source, type);
	}

	void GLShaderProgram::deleteShaders()
	{
		for (ui32f i = 0; i < m_shaders.size(); i++) {
			glDetachShader(m_program, m_shaders[i]);
			glDeleteShader(m_shaders[i]);
		}
		m_shaders.clear();
	}

	void GLShaderProgram::link()
	{
		glLinkProgram(m_program);
		i32 status;
		glGetProgramiv(m_program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			i32 maxLength;
			glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<char> infoLog(maxLength);
			glGetProgramInfoLog(m_program, maxLength, &maxLength, infoLog.data());

			log::error("Failed to link shader program:\n\n", infoLog.data(), "\n\n");
		}

		glValidateProgram(m_program);
		
		deleteShaders();

		for (auto& it = m_uniforms.begin(); it != m_uniforms.end(); it++) {
			it->second = glGetUniformLocation(m_program, it->first.c_str());
		}
	}

	void GLShaderProgram::enable() const
	{
		glUseProgram(m_program);
	}

	void GLShaderProgram::disable() const
	{
		glUseProgram(0);
	}

	void GLShaderProgram::setUniform(cString name, i32 v) const
	{
		glUniform1i(getUniformLocation(name), v);
	}

	void GLShaderProgram::setUniform(cString name, f32 v) const
	{
		glUniform1f(getUniformLocation(name), v);
	}

	void GLShaderProgram::setUniform(cString name, const f32v2& v) const
	{
		glUniform2f(getUniformLocation(name), v.x, v.y);
	}

	void GLShaderProgram::setUniform(cString name, const f32v3& v) const
	{
		glUniform3f(getUniformLocation(name), v.x, v.y, v.z);
	}

	void GLShaderProgram::setUniform(cString name, const f32v4& v) const
	{
		glUniform4f(getUniformLocation(name), v.x, v.y, v.z, v.w);
	}

	void GLShaderProgram::setUniform(cString name, const f32m3& v) const
	{
		glUniformMatrix3fv(getUniformLocation(name), 1, false, v.getData());
	}

	void GLShaderProgram::setUniform(cString name, const f32m4& v) const
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, false, v.getData());
	}

	void GLShaderProgram::setUniform(cString name, const f64v2& v) const
	{
		glUniform2d(getUniformLocation(name), v.x, v.y);
	}

	void GLShaderProgram::setUniform(cString name, const f64v3& v) const
	{
		glUniform3d(getUniformLocation(name), v.x, v.y, v.z);
	}

	void GLShaderProgram::setUniform(cString name, const f64v4& v) const
	{
		glUniform4d(getUniformLocation(name), v.x, v.y, v.z, v.w);
	}

	void GLShaderProgram::setUniform(cString name, const f64m3& v) const
	{
		glUniformMatrix3dv(getUniformLocation(name), 1, false, v.getData());
	}

	void GLShaderProgram::setUniform(cString name, const f64m4& v) const
	{
		glUniformMatrix4dv(getUniformLocation(name), 1, false, v.getData());
	}

	void GLShaderProgram::setUniform(cString name, const f32v2* v, ui32f count) const
	{
		glUniform2fv(getUniformLocation(name), count, &(*v).x);
	}

	void GLShaderProgram::setUniform(cString name, const f32v3* v, ui32f count) const
	{
		glUniform3fv(getUniformLocation(name), count, &(*v).x);
	}

	void GLShaderProgram::setUniform(cString name, const f32v4* v, ui32f count) const
	{
		glUniform4fv(getUniformLocation(name), count, &(*v).x);
	}


	i32 GLShaderProgram::getUniformLocation(const String& name) const
	{
		auto& it = m_uniforms.find(name);
		if (it != m_uniforms.end()) {
			return it->second;
		}
		return glGetUniformLocation(m_program, name.c_str());
	}

}