#pragma once

#include <vector>
#include <unordered_map>

#include "ShaderProgram.h"

namespace vt {

	class VT_API GLShaderProgram : public ShaderProgram
	{
	public:
		GLShaderProgram();
		~GLShaderProgram();

		void initialize() override;
		void cleanup() override;

		void addShader(const String& source, const ShaderType& type) override;
		void loadShader(cString file, const ShaderType& type) override;
		void deleteShaders() override;

		void link() override;

		void enable() const override;
		void disable() const override;

		void setUniform(cString name, i32 v) const override;
		void setUniform(cString name, f32 v) const override;
		void setUniform(cString name, const f32v2& v) const override;
		void setUniform(cString name, const f32v3& v) const override;
		void setUniform(cString name, const f32v4& v) const override;
		void setUniform(cString name, const f32m3& v) const override;
		void setUniform(cString name, const f32m4& v) const override;
		void setUniform(cString name, const f64v2& v) const override;
		void setUniform(cString name, const f64v3& v) const override;
		void setUniform(cString name, const f64v4& v) const override;
		void setUniform(cString name, const f64m3& v) const override;
		void setUniform(cString name, const f64m4& v) const override;
		void setUniform(cString name, const f32v2* v, ui32f count) const override;
		void setUniform(cString name, const f32v3* v, ui32f count) const override;
		void setUniform(cString name, const f32v4* v, ui32f count) const override;
	protected:
		i32 getUniformLocation(const String& name) const;
	private:
		ui32 m_program;
		std::vector<ui32> m_shaders;
		std::unordered_map<String, i32> m_uniforms;
	};

}