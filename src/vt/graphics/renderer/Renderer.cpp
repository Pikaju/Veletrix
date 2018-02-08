#include "Renderer.h"

#include "../../io/Console.h"
#include "../../Build.h"

#define VT_MAX_STACK_SIZE 64

namespace vt {

	Renderer::Renderer() : m_flags(), m_stack()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::loadFlags(const RenderingFlags& flags)
	{
		setDepthRead(flags.depthRead);
		setDepthWrite(flags.depthWrite);
		setCulling(flags.culling);
		setWireframe(flags.wireframe);
		setBlending(flags.blending);
	}

	void Renderer::pushFlags()
	{
#ifdef VT_DEBUG
		if (m_stack.size() >= VT_MAX_STACK_SIZE) {
			log::warning("Maximum rendering flag stack size reached: ", m_stack.size());
			return;
		}
#endif
		m_stack.pushBack(m_flags);
	}

	void Renderer::popFlags()
	{
#ifdef VT_DEBUG
		if (m_stack.size() == 0) {
			log::error("Rendering flag stack is empty, flags can't be popped");
			return;
		}
#endif
		m_flags = m_stack.getLastElement();
		m_stack.popBack();
		loadFlags(m_flags);
	}

}