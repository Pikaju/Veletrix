#pragma once

#include "../../Build.h"
#include "../../Types.h"

namespace vt {

	enum ShaderType
	{
		SHADERTYPE_VERTEX,
		SHADERTYPE_FRAGMENT,
		SHADERTYPE_GEOMETRY,
		SHADERTYPE_COMPUTE
	};

	class VT_API ShaderProgram
	{
	public:
		ShaderProgram() {  }
		~ShaderProgram() {  }

		virtual void initialize() = 0;
		virtual void cleanup() = 0;

		virtual void addShader(const String& source, const ShaderType& type) = 0;
		virtual void loadShader(cString file, const ShaderType& type) = 0;
		virtual void deleteShaders() = 0;

		virtual void link() = 0;

		virtual void enable() const = 0;
		virtual void disable() const = 0;

		virtual void setUniform(cString name, i32f v) const = 0;
		virtual void setUniform(cString name, f32 v) const = 0;
		virtual void setUniform(cString name, const f32v2& v) const = 0;
		virtual void setUniform(cString name, const f32v3& v) const = 0;
		virtual void setUniform(cString name, const f32v4& v) const = 0;
		virtual void setUniform(cString name, const f32m3& v) const = 0;
		virtual void setUniform(cString name, const f32m4& v) const = 0;
		virtual void setUniform(cString name, const f64v2& v) const = 0;
		virtual void setUniform(cString name, const f64v3& v) const = 0;
		virtual void setUniform(cString name, const f64v4& v) const = 0;
		virtual void setUniform(cString name, const f64m3& v) const = 0;
		virtual void setUniform(cString name, const f64m4& v) const = 0;
		virtual void setUniform(cString name, const f32v2* v, ui32f count) const = 0;
		virtual void setUniform(cString name, const f32v3* v, ui32f count) const = 0;
		virtual void setUniform(cString name, const f32v4* v, ui32f count) const = 0;
	};

}