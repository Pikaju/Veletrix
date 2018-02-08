#pragma once

#include <unordered_map>

#include "../../Build.h"
#include "../../Types.h"

namespace vt {

	class Window;

	enum InputCodes
	{
		INPUTCODES_GLFW,
		INPUTCODES_SDL
	};

	class VT_API Input
	{
	public:
		Input(Window* window, const InputCodes& codes);
		~Input();

		void preUpdate();
		void postUpdate();

		void addKeyEvent(i32 key, bool state);
		void addButtonEvent(i32 button, bool state);
		void addMousePositionEvent(f64 x, f64 y);
		void addMouseScrollEvent(f64 scroll);

		bool getKeyState(i32 key) const;
		bool getKeyEvent(i32 key, bool state = true) const;
		bool getButtonState(i32 button) const;
		bool getButtonEvent(i32 button, bool state = true) const;

		bool isMouseGrabbed() const;
		void setMouseGrabbed(bool grabbed) const;

		inline f64 getMouseX() const { return m_mouseX; }
		inline f64 getMouseY() const { return m_mouseY; }
		inline f64 getMouseScroll() const { return m_mouseScroll; }

		inline f64 getMouseDX() const { return m_mouseDX; }
		inline f64 getMouseDY() const { return m_mouseDY; }
		inline f64 getMouseDScroll() const { return m_mouseDScroll; }
	private:
		Window* m_window;

		std::unordered_map<i32, bool> m_keyStates;
		std::unordered_map<i32, bool> m_keyEvents;

		std::unordered_map<i32, bool> m_buttonStates;
		std::unordered_map<i32, bool> m_buttonEvents;

		f64 m_mouseX;
		f64 m_mouseY;
		f64 m_mouseScroll;
		f64 m_mouseLX;
		f64 m_mouseLY;
		f64 m_mouseLScroll;
		f64 m_mouseDX;
		f64 m_mouseDY;
		f64 m_mouseDScroll;
	public:
		i32 KEY_UNKNOWN;
		i32 KEY_SPACE;
		i32 KEY_APOSTROPHE;
		i32 KEY_COMMA;
		i32 KEY_MINUS;
		i32 KEY_PERIOD;
		i32 KEY_SLASH;
		i32 KEY_0;
		i32 KEY_1;
		i32 KEY_2;
		i32 KEY_3;
		i32 KEY_4;
		i32 KEY_5;
		i32 KEY_6;
		i32 KEY_7;
		i32 KEY_8;
		i32 KEY_9;
		i32 KEY_SEMICOLON;
		i32 KEY_EQUAL;
		i32 KEY_A;
		i32 KEY_B;
		i32 KEY_C;
		i32 KEY_D;
		i32 KEY_E;
		i32 KEY_F;
		i32 KEY_G;
		i32 KEY_H;
		i32 KEY_I;
		i32 KEY_J;
		i32 KEY_K;
		i32 KEY_L;
		i32 KEY_M;
		i32 KEY_N;
		i32 KEY_O;
		i32 KEY_P;
		i32 KEY_Q;
		i32 KEY_R;
		i32 KEY_S;
		i32 KEY_T;
		i32 KEY_U;
		i32 KEY_V;
		i32 KEY_W;
		i32 KEY_X;
		i32 KEY_Y;
		i32 KEY_Z;
		i32 KEY_LEFT_BRACKET;
		i32 KEY_BACKSLASH;
		i32 KEY_RIGHT_BRACKET;
		i32 KEY_GRAVE_ACCENT;
		i32 KEY_WORLD_1;
		i32 KEY_WORLD_2;
		i32 KEY_ESCAPE;
		i32 KEY_ENTER;
		i32 KEY_TAB;
		i32 KEY_BACKSPACE;
		i32 KEY_INSERT;
		i32 KEY_DELETE;
		i32 KEY_RIGHT;
		i32 KEY_LEFT;
		i32 KEY_DOWN;
		i32 KEY_UP;
		i32 KEY_PAGE_UP;
		i32 KEY_PAGE_DOWN;
		i32 KEY_HOME;
		i32 KEY_END;
		i32 KEY_CAPS_LOCK;
		i32 KEY_SCROLL_LOCK;
		i32 KEY_NUM_LOCK;
		i32 KEY_PRINT_SCREEN;
		i32 KEY_PAUSE;
		i32 KEY_F1;
		i32 KEY_F2;
		i32 KEY_F3;
		i32 KEY_F4;
		i32 KEY_F5;
		i32 KEY_F6;
		i32 KEY_F7;
		i32 KEY_F8;
		i32 KEY_F9;
		i32 KEY_F10;
		i32 KEY_F11;
		i32 KEY_F12;
		i32 KEY_F13;
		i32 KEY_F14;
		i32 KEY_F15;
		i32 KEY_F16;
		i32 KEY_F17;
		i32 KEY_F18;
		i32 KEY_F19;
		i32 KEY_F20;
		i32 KEY_F21;
		i32 KEY_F22;
		i32 KEY_F23;
		i32 KEY_F24;
		i32 KEY_F25;
		i32 KEY_KP_0;
		i32 KEY_KP_1;
		i32 KEY_KP_2;
		i32 KEY_KP_3;
		i32 KEY_KP_4;
		i32 KEY_KP_5;
		i32 KEY_KP_6;
		i32 KEY_KP_7;
		i32 KEY_KP_8;
		i32 KEY_KP_9;
		i32 KEY_KP_DECIMAL;
		i32 KEY_KP_DIVIDE;
		i32 KEY_KP_MULTIPLY;
		i32 KEY_KP_SUBTRACT;
		i32 KEY_KP_ADD;
		i32 KEY_KP_ENTER;
		i32 KEY_KP_EQUAL;
		i32 KEY_LEFT_SHIFT;
		i32 KEY_LEFT_CONTROL;
		i32 KEY_LEFT_ALT;
		i32 KEY_LEFT_SUPER;
		i32 KEY_RIGHT_SHIFT;
		i32 KEY_RIGHT_CONTROL;
		i32 KEY_RIGHT_ALT;
		i32 KEY_RIGHT_SUPER;
		i32 KEY_MENU;
		i32 KEY_LAST;
		i32 MOD_SHIFT;
		i32 MOD_CONTROL;
		i32 MOD_ALT;
		i32 MOD_SUPER;

		i32 MOUSE_BUTTON_1;
		i32 MOUSE_BUTTON_2;
		i32 MOUSE_BUTTON_3;
		i32 MOUSE_BUTTON_4;
		i32 MOUSE_BUTTON_5;
		i32 MOUSE_BUTTON_6;
		i32 MOUSE_BUTTON_7;
		i32 MOUSE_BUTTON_8;
		i32 MOUSE_BUTTON_LAST;
		i32 MOUSE_BUTTON_LEFT;
		i32 MOUSE_BUTTON_RIGHT;
		i32 MOUSE_BUTTON_MIDDLE;
	};

}