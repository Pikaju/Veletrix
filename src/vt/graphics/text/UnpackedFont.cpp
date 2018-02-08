#include "UnpackedFont.h"

#include "../texture/Texture.h"

namespace vt {

	UnpackedFont::UnpackedFont() : m_characters()
	{
	}

	UnpackedFont::~UnpackedFont()
	{
	}

	void UnpackedFont::initialize()
	{
	}

	void UnpackedFont::cleanup()
	{
		for (auto& it = m_characters.begin(); it != m_characters.end(); it++) {
			it->second.getTexture()->cleanup();
			delete it->second.getTexture();
		}
		m_characters.clear();
	}

	ui16f UnpackedFont::getStringWidth(cString string) const
	{
		ui16f width = 0;
		for (ui16f i = 0; string[i] != '\0'; i++) {
			width += m_characters.find(string[i])->second.getAdvance().x;
		}
		return width;
	}

}