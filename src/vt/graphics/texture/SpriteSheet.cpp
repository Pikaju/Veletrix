#include "SpriteSheet.h"

#include "../../io/Console.h"

namespace vt {

	static const f32 BORDER = 1.0f / 8192.0f / 8.0f;

	VT_CONSTEXPR SpriteSheet::SpriteSheet() : m_texture(nullptr), m_spritesX(0), m_spritesY(0)
	{
	}
	
	SpriteSheet::~SpriteSheet()
	{
	}

	void SpriteSheet::initialize(Texture* texture, ui32f spritesX, ui32f spritesY)
	{
		m_texture = texture;
		m_spritesX = spritesX;
		m_spritesY = spritesY;
	}

	void SpriteSheet::cleanup()
	{
		m_texture->cleanup();
		delete m_texture;
	}

	f32v2 SpriteSheet::getTextureCoordinates(ui32f spriteX, ui32f spriteY, const SpriteCorner& corner) const
	{
		f32 xs = 1.0f / static_cast<f32>(m_spritesX);
		f32 ys = 1.0f / static_cast<f32>(m_spritesY);

		switch (corner) {
		case SPRITE_CORNER_TL: return f32v2(static_cast<f32>(spriteX) * xs + BORDER, static_cast<f32>(spriteY) * ys + BORDER); break;
		case SPRITE_CORNER_TR: return f32v2(static_cast<f32>(spriteX) * xs + xs - BORDER, static_cast<f32>(spriteY) * ys + BORDER); break;
		case SPRITE_CORNER_BL: return f32v2(static_cast<f32>(spriteX) * xs + BORDER, static_cast<f32>(spriteY) * ys + ys - BORDER); break;
		case SPRITE_CORNER_BR: return f32v2(static_cast<f32>(spriteX) * xs + xs - BORDER, static_cast<f32>(spriteY) * ys + ys - BORDER); break;
		default: log::error("Invalid sprite corner: ", corner); break;
		}
		return f32v2();
	}

	f32v2 SpriteSheet::getTextureCoordinates(ui32f sprite, const SpriteCorner& corner) const
	{
		ui32f spriteX = sprite % m_spritesX;
		ui32f spriteY = sprite / m_spritesX;
		return getTextureCoordinates(spriteX, spriteY, corner);
	}

}