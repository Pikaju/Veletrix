#include "Font.h"

#include "../texture/Texture.h"

namespace vt {

	Font::Font() : m_characters(), m_texture(nullptr)
	{
	}

	Font::~Font()
	{
	}

	void Font::initialize()
	{
	}

	void Font::cleanup()
	{
		if (m_texture != nullptr) {
			m_texture->cleanup();
			delete m_texture;
		}
		m_texture = nullptr;
	}

	ui16f Font::getStringWidth(cString string) const
	{
		ui16f width = 0;
		for (ui16f i = 0; string[i] != '\0'; i++) {
			width += m_characters.find(string[i])->second.getAdvance().x;
		}
		return width;
	}

}
