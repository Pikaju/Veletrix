#include "Input.h"

#include <SDL/SDL_events.h>

#include "Window.h"

namespace vt {
	
	Input::Input(Window* window, const InputCodes& codes) : m_window(window), m_keyStates(), m_keyEvents(), m_buttonStates(), m_buttonEvents(), m_mouseX(0.0), m_mouseY(0.0), m_mouseScroll(0.0), m_mouseLX(0.0), m_mouseLY(0.0), m_mouseLScroll(0.0), m_mouseDX(0.0), m_mouseDY(0.0), m_mouseDScroll(0.0)
	{
		if (codes == INPUTCODES_GLFW) {
			KEY_UNKNOWN = -1;
			KEY_SPACE = 32;
			KEY_APOSTROPHE = 39;
			KEY_COMMA = 44;
			KEY_MINUS = 45;
			KEY_PERIOD = 46;
			KEY_SLASH = 47;
			KEY_0 = 48;
			KEY_1 = 49;
			KEY_2 = 50;
			KEY_3 = 51;
			KEY_4 = 52;
			KEY_5 = 53;
			KEY_6 = 54;
			KEY_7 = 55;
			KEY_8 = 56;
			KEY_9 = 57;
			KEY_SEMICOLON = 59;
			KEY_EQUAL = 61;
			KEY_A = 65;
			KEY_B = 66;
			KEY_C = 67;
			KEY_D = 68;
			KEY_E = 69;
			KEY_F = 70;
			KEY_G = 71;
			KEY_H = 72;
			KEY_I = 73;
			KEY_J = 74;
			KEY_K = 75;
			KEY_L = 76;
			KEY_M = 77;
			KEY_N = 78;
			KEY_O = 79;
			KEY_P = 80;
			KEY_Q = 81;
			KEY_R = 82;
			KEY_S = 83;
			KEY_T = 84;
			KEY_U = 85;
			KEY_V = 86;
			KEY_W = 87;
			KEY_X = 88;
			KEY_Y = 89;
			KEY_Z = 90;
			KEY_LEFT_BRACKET = 91;
			KEY_BACKSLASH = 92;
			KEY_RIGHT_BRACKET = 93;
			KEY_GRAVE_ACCENT = 96;
			KEY_WORLD_1 = 161;
			KEY_WORLD_2 = 162;
			KEY_ESCAPE = 256;
			KEY_ENTER = 257;
			KEY_TAB = 258;
			KEY_BACKSPACE = 259;
			KEY_INSERT = 260;
			KEY_DELETE = 261;
			KEY_RIGHT = 262;
			KEY_LEFT = 263;
			KEY_DOWN = 264;
			KEY_UP = 265;
			KEY_PAGE_UP = 266;
			KEY_PAGE_DOWN = 267;
			KEY_HOME = 268;
			KEY_END = 269;
			KEY_CAPS_LOCK = 280;
			KEY_SCROLL_LOCK = 281;
			KEY_NUM_LOCK = 282;
			KEY_PRINT_SCREEN = 283;
			KEY_PAUSE = 284;
			KEY_F1 = 290;
			KEY_F2 = 291;
			KEY_F3 = 292;
			KEY_F4 = 293;
			KEY_F5 = 294;
			KEY_F6 = 295;
			KEY_F7 = 296;
			KEY_F8 = 297;
			KEY_F9 = 298;
			KEY_F10 = 299;
			KEY_F11 = 300;
			KEY_F12 = 301;
			KEY_F13 = 302;
			KEY_F14 = 303;
			KEY_F15 = 304;
			KEY_F16 = 305;
			KEY_F17 = 306;
			KEY_F18 = 307;
			KEY_F19 = 308;
			KEY_F20 = 309;
			KEY_F21 = 310;
			KEY_F22 = 311;
			KEY_F23 = 312;
			KEY_F24 = 313;
			KEY_F25 = 314;
			KEY_KP_0 = 320;
			KEY_KP_1 = 321;
			KEY_KP_2 = 322;
			KEY_KP_3 = 323;
			KEY_KP_4 = 324;
			KEY_KP_5 = 325;
			KEY_KP_6 = 326;
			KEY_KP_7 = 327;
			KEY_KP_8 = 328;
			KEY_KP_9 = 329;
			KEY_KP_DECIMAL = 330;
			KEY_KP_DIVIDE = 331;
			KEY_KP_MULTIPLY = 332;
			KEY_KP_SUBTRACT = 333;
			KEY_KP_ADD = 334;
			KEY_KP_ENTER = 335;
			KEY_KP_EQUAL = 336;
			KEY_LEFT_SHIFT = 340;
			KEY_LEFT_CONTROL = 341;
			KEY_LEFT_ALT = 342;
			KEY_LEFT_SUPER = 343;
			KEY_RIGHT_SHIFT = 344;
			KEY_RIGHT_CONTROL = 345;
			KEY_RIGHT_ALT = 346;
			KEY_RIGHT_SUPER = 347;
			KEY_MENU = 348;
			KEY_LAST = KEY_MENU;
			MOD_SHIFT = 0x0001;
			MOD_CONTROL = 0x0002;
			MOD_ALT = 0x0004;
			MOD_SUPER = 0x0008;

			MOUSE_BUTTON_1 = 0;
			MOUSE_BUTTON_2 = 1;
			MOUSE_BUTTON_3 = 2;
			MOUSE_BUTTON_4 = 3;
			MOUSE_BUTTON_5 = 4;
			MOUSE_BUTTON_6 = 5;
			MOUSE_BUTTON_7 = 6;
			MOUSE_BUTTON_8 = 7;
			MOUSE_BUTTON_LAST = MOUSE_BUTTON_8;
			MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1;
			MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2;
			MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3;
		}
		else if (codes == INPUTCODES_SDL) {
			KEY_UNKNOWN = SDLK_UNKNOWN;
			KEY_SPACE = SDLK_SPACE;
			KEY_APOSTROPHE = SDLK_UNKNOWN;
			KEY_COMMA = SDLK_COMMA;
			KEY_MINUS = SDLK_MINUS;
			KEY_PERIOD = SDLK_PERIOD;
			KEY_SLASH = SDLK_SLASH;
			KEY_0 = SDLK_0;
			KEY_1 = SDLK_1;
			KEY_2 = SDLK_2;
			KEY_3 = SDLK_3;
			KEY_4 = SDLK_4;
			KEY_5 = SDLK_5;
			KEY_6 = SDLK_6;
			KEY_7 = SDLK_7;
			KEY_8 = SDLK_8;
			KEY_9 = SDLK_9;
			KEY_SEMICOLON = SDLK_SEMICOLON;
			KEY_EQUAL = SDLK_EQUALS;
			KEY_A = SDLK_a;
			KEY_B = SDLK_b;
			KEY_C = SDLK_c;
			KEY_D = SDLK_d;
			KEY_E = SDLK_e;
			KEY_F = SDLK_f;
			KEY_G = SDLK_g;
			KEY_H = SDLK_h;
			KEY_I = SDLK_i;
			KEY_J = SDLK_j;
			KEY_K = SDLK_k;
			KEY_L = SDLK_l;
			KEY_M = SDLK_m;
			KEY_N = SDLK_n;
			KEY_O = SDLK_o;
			KEY_P = SDLK_p;
			KEY_Q = SDLK_q;
			KEY_R = SDLK_r;
			KEY_S = SDLK_s;
			KEY_T = SDLK_t;
			KEY_U = SDLK_u;
			KEY_V = SDLK_v;
			KEY_W = SDLK_w;
			KEY_X = SDLK_x;
			KEY_Y = SDLK_y;
			KEY_Z = SDLK_z;
			KEY_LEFT_BRACKET = SDLK_LEFTBRACKET;
			KEY_BACKSLASH = SDLK_BACKSLASH;
			KEY_RIGHT_BRACKET = SDLK_RIGHTBRACKET;
			KEY_GRAVE_ACCENT = SDLK_UNKNOWN;
			KEY_WORLD_1 = SDLK_UNKNOWN;
			KEY_WORLD_2 = SDLK_UNKNOWN;
			KEY_ESCAPE = SDLK_ESCAPE;
			KEY_ENTER = SDLK_RETURN;
			KEY_TAB = SDLK_TAB;
			KEY_BACKSPACE = SDLK_BACKSPACE;
			KEY_INSERT = SDLK_INSERT;
			KEY_DELETE = SDLK_DELETE;
			KEY_RIGHT = SDLK_RIGHT;
			KEY_LEFT = SDLK_LEFT;
			KEY_DOWN = SDLK_DOWN;
			KEY_UP = SDLK_UP;
			KEY_PAGE_UP = SDLK_PAGEUP;
			KEY_PAGE_DOWN = SDLK_PAGEDOWN;
			KEY_HOME = SDLK_HOME;
			KEY_END = SDLK_END;
			KEY_CAPS_LOCK = SDLK_CAPSLOCK;
			KEY_SCROLL_LOCK = SDLK_SCROLLLOCK;
			KEY_NUM_LOCK = SDLK_NUMLOCKCLEAR;
			KEY_PRINT_SCREEN = SDLK_PRINTSCREEN;
			KEY_PAUSE = SDLK_PAUSE;
			KEY_F1 = SDLK_F1;
			KEY_F2 = SDLK_F2;
			KEY_F3 = SDLK_F3;
			KEY_F4 = SDLK_F4;
			KEY_F5 = SDLK_F5;
			KEY_F6 = SDLK_F6;
			KEY_F7 = SDLK_F7;
			KEY_F8 = SDLK_F8;
			KEY_F9 = SDLK_F9;
			KEY_F10 = SDLK_F10;
			KEY_F11 = SDLK_F11;
			KEY_F12 = SDLK_F12;
			KEY_F13 = SDLK_F13;
			KEY_F14 = SDLK_F14;
			KEY_F15 = SDLK_F15;
			KEY_F16 = SDLK_F16;
			KEY_F17 = SDLK_F17;
			KEY_F18 = SDLK_F18;
			KEY_F19 = SDLK_F19;
			KEY_F20 = SDLK_F20;
			KEY_F21 = SDLK_F21;
			KEY_F22 = SDLK_F22;
			KEY_F23 = SDLK_F23;
			KEY_F24 = SDLK_F24;
			KEY_F25 = SDLK_UNKNOWN;
			KEY_KP_0 = SDLK_KP_0;
			KEY_KP_1 = SDLK_KP_1;
			KEY_KP_2 = SDLK_KP_2;
			KEY_KP_3 = SDLK_KP_3;
			KEY_KP_4 = SDLK_KP_4;
			KEY_KP_5 = SDLK_KP_5;
			KEY_KP_6 = SDLK_KP_6;
			KEY_KP_7 = SDLK_KP_7;
			KEY_KP_8 = SDLK_KP_8;
			KEY_KP_9 = SDLK_KP_9;
			KEY_KP_DECIMAL = SDLK_KP_DECIMAL;
			KEY_KP_DIVIDE = SDLK_KP_DIVIDE;
			KEY_KP_MULTIPLY = SDLK_KP_MULTIPLY;
			KEY_KP_SUBTRACT = SDLK_KP_MINUS;
			KEY_KP_ADD = SDLK_KP_PLUS;
			KEY_KP_ENTER = SDLK_KP_ENTER;
			KEY_KP_EQUAL = SDLK_KP_EQUALS;
			KEY_LEFT_SHIFT = SDLK_LSHIFT;
			KEY_LEFT_CONTROL = SDLK_LCTRL;
			KEY_LEFT_ALT = SDLK_LALT;
			KEY_LEFT_SUPER = SDLK_UNKNOWN;
			KEY_RIGHT_SHIFT = SDLK_RSHIFT;
			KEY_RIGHT_CONTROL = SDLK_RCTRL;
			KEY_RIGHT_ALT = SDLK_RALT;
			KEY_RIGHT_SUPER = SDLK_UNKNOWN;
			KEY_MENU = SDLK_MENU;
			KEY_LAST = KEY_MENU;
			MOD_SHIFT = SDLK_UNKNOWN;
			MOD_CONTROL = SDLK_UNKNOWN;
			MOD_ALT = SDLK_UNKNOWN;
			MOD_SUPER = SDLK_UNKNOWN;

			MOUSE_BUTTON_1 = SDL_BUTTON_LEFT;
			MOUSE_BUTTON_2 = SDL_BUTTON_RIGHT;
			MOUSE_BUTTON_3 = SDL_BUTTON_MIDDLE;
			MOUSE_BUTTON_4 = 3;
			MOUSE_BUTTON_5 = 4;
			MOUSE_BUTTON_6 = 5;
			MOUSE_BUTTON_7 = 6;
			MOUSE_BUTTON_8 = 7;
			MOUSE_BUTTON_LAST = MOUSE_BUTTON_8;
			MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1;
			MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2;
			MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3;
		}
	}

	Input::~Input()
	{
	}

	void Input::preUpdate()
	{
		m_keyEvents.clear();
		m_buttonEvents.clear();
	}

	void Input::postUpdate()
	{
		m_mouseDX = m_mouseX - m_mouseLX;
		m_mouseDY = m_mouseY - m_mouseLY;
		m_mouseDScroll = m_mouseScroll - m_mouseLScroll;
		m_mouseLX = m_mouseX;
		m_mouseLY = m_mouseY;
		m_mouseLScroll = m_mouseScroll;
	}

	void Input::addKeyEvent(i32 key, bool state)
	{
		m_keyStates[key] = state;
		m_keyEvents[key] = state;
	}

	void Input::addButtonEvent(i32 button, bool state)
	{
		m_buttonStates[button] = state;
		m_buttonEvents[button] = state;
	}

	void Input::addMousePositionEvent(f64 x, f64 y)
	{
		m_mouseX = x;
		m_mouseY = y;
	}

	void Input::addMouseScrollEvent(f64 scroll)
	{
		m_mouseScroll = scroll;
	}

	bool Input::getKeyState(i32 key) const
	{
		auto& it = m_keyStates.find(key);
		if (it == m_keyStates.end()) {
			return false;
		}
		return it->second;
	}

	bool Input::getKeyEvent(i32 key, bool state) const
	{
		auto& it = m_keyEvents.find(key);
		if (it == m_keyEvents.end()) {
			return false;
		}
		return it->second == state;
	}

	bool Input::getButtonState(i32 button) const
	{
		auto& it = m_buttonStates.find(button);
		if (it == m_buttonStates.end()) {
			return false;
		}
		return it->second;
	}

	bool Input::getButtonEvent(i32 button, bool state) const
	{
		auto& it = m_buttonEvents.find(button);
		if (it == m_buttonEvents.end()) {
			return false;
		}
		return it->second == state;
	}

	bool Input::isMouseGrabbed() const
	{
		return m_window->isMouseGrabbed();
	}

	void Input::setMouseGrabbed(bool grabbed) const
	{
		m_window->setMouseGrabbed(grabbed);
	}

}