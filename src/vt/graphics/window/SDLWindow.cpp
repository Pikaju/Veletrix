#include "SDLWindow.h"

#include "../GraphicsAPI.h"

#ifdef VT_GRAPHICS_SDL

#include "../../../glad/glad.h"
#include <SDL/SDL.h>

#include "../../debug/Exception.h"

namespace vt {

	SDLWindow::SDLWindow() : Window(INPUTCODES_SDL), m_window(nullptr), m_context(), m_closeRequested(false)
	{
	}

	SDLWindow::~SDLWindow()
	{
	}

	void SDLWindow::initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VSync& vsync)
	{
		SDL_DisplayMode mode;
		SDL_GetCurrentDisplayMode(0, &mode);

		if (width == WINDOW_MONITOR_RESOLUTION) width = mode.w;
		if (height == WINDOW_MONITOR_RESOLUTION) height = mode.h;

		ui32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
		if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN;
		if (resizable) flags |= SDL_WINDOW_RESIZABLE;

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		m_window = SDL_CreateWindow(title, mode.w / 2 - width / 2, mode.h / 2 - height / 2, width, height, flags);
	
		if (m_window == nullptr) {
			log::fatal("Could not create SDL window");
			exception::crash();
		}

		m_context = SDL_GL_CreateContext(m_window);
		SDL_GL_MakeCurrent(m_window, m_context);

		if (!gladLoadGL()) {
			log::fatal("Could not initialize glad");
			exception::crash();
		}

		SDL_GL_SetSwapInterval(static_cast<int>(vsync));
	}

	void SDLWindow::cleanup()
	{
		m_keyMap.clear();
		m_buttonMap.clear();
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
	}

	void SDLWindow::update()
	{
		m_input.preUpdate();
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT: m_closeRequested = true; break;
			case SDL_KEYDOWN: m_input.addKeyEvent(e.key.keysym.sym, true); break;
			case SDL_KEYUP: m_input.addKeyEvent(e.key.keysym.sym, false); break;
			case SDL_MOUSEBUTTONDOWN: m_input.addButtonEvent(e.button.button, true); break;
			case SDL_MOUSEBUTTONUP: m_input.addButtonEvent(e.button.button, false); break;
			case SDL_MOUSEMOTION:
				if (isMouseGrabbed()) m_input.addMousePositionEvent(static_cast<f64>(e.motion.xrel) + m_input.getMouseX(), static_cast<f64>(e.motion.yrel) + m_input.getMouseY());
				else m_input.addMousePositionEvent(static_cast<f64>(e.motion.x), static_cast<f64>(e.motion.y));
				break;
			}
		}
		m_input.postUpdate();
	}

	void SDLWindow::swap()
	{
		SDL_GL_SwapWindow(m_window);
	}

	void SDLWindow::bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		int width;
		int height;
		SDL_GetWindowSize(m_window, &width, &height);
		glViewport(0, 0, width, height);
	}

	bool SDLWindow::isCloseRequested()
	{
		return m_closeRequested;
	}

	ui16f SDLWindow::getWidth() const
	{
		int width;
		int height;
		SDL_GetWindowSize(m_window, &width, &height);
		return width;
	}

	ui16f SDLWindow::getHeight() const
	{
		int width;
		int height;
		SDL_GetWindowSize(m_window, &width, &height);
		return height;
	}

	f32 SDLWindow::getAspectRatio() const
	{
		int width;
		int height;
		SDL_GetWindowSize(m_window, &width, &height);
		return static_cast<f32>(width) / static_cast<f32>(height);
	}

	bool SDLWindow::isMouseGrabbed() const
	{
		return SDL_GetRelativeMouseMode() == SDL_TRUE;
	}

	void SDLWindow::setMouseGrabbed(bool grabbed) const
	{
		SDL_SetRelativeMouseMode(grabbed ? SDL_TRUE : SDL_FALSE);
	}

	void SDLWindow::captureScreenshot(cString file) const
	{

	}

}

#endif