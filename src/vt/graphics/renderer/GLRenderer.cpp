#include "GLRenderer.h"

#include "../../../glad/glad.h"

namespace vt {

	GLRenderer::GLRenderer() : Renderer()
	{
	}

	GLRenderer::~GLRenderer()
	{
	}

	void GLRenderer::setDepthRead(bool flag)
	{
		if (flag)
			glEnable(GL_DEPTH_TEST);
		else
			glDisable(GL_DEPTH_TEST);
		m_flags.depthRead = flag;
	}

	void GLRenderer::setDepthWrite(bool flag)
	{
		glDepthMask(flag);
		m_flags.depthWrite = flag;
	}

	void GLRenderer::setCulling(Culling flag)
	{
		if (flag != CULLING_DISABLED) {
			glEnable(GL_CULL_FACE);
			if (flag == CULLING_FRONT) {
				glCullFace(GL_FRONT);
			}
			else {
				glCullFace(GL_BACK);
			}
		}
		else {
			glDisable(GL_CULL_FACE);
		}
		m_flags.culling = flag;
	}

	void GLRenderer::setWireframe(bool flag)
	{
		if (flag)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		m_flags.wireframe = flag;
	}

	void GLRenderer::setBlending(Blending flag)
	{
		if (flag != BLENDING_DISABLED) {
			glEnablei(GL_BLEND, 0);
			if (flag == BLENDING_TRANSPARENCY) {
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			if (flag == BLENDING_ADDITIVE) {
				glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			}
		}
		else {
			glDisable(GL_BLEND);
		}
		m_flags.blending = flag;
	}

	void GLRenderer::clear(bool color, bool depth, bool stencil)
	{
		ui32 mask = 0;
		if (color)
			mask |= GL_COLOR_BUFFER_BIT;
		if (depth)
			mask |= GL_DEPTH_BUFFER_BIT;
		if (stencil)
			mask |= GL_STENCIL_BUFFER_BIT;
		glClear(mask);
	}

}