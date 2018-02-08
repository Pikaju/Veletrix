#pragma once

#include "../../Build.h"
#include "../../Types.h"

#include "Texture.h"

namespace vt {

	enum SpriteCorner
	{
		SPRITE_CORNER_TL,
		SPRITE_CORNER_TR,
		SPRITE_CORNER_BL,
		SPRITE_CORNER_BR
	};

	class VT_API SpriteSheet
	{
	public:
		VT_CONSTEXPR SpriteSheet();
		~SpriteSheet();

		void initialize(Texture* texture, ui32f spritesX, ui32f spritesY);
		void cleanup();

		f32v2 getTextureCoordinates(ui32f spriteX, ui32f spriteY, const SpriteCorner& corner) const;
		f32v2 getTextureCoordinates(ui32f sprite, const SpriteCorner& corner) const;

		inline const Texture* getTexture() const { return m_texture; }
	private:
		Texture* m_texture;
		ui32f m_spritesX;
		ui32f m_spritesY;
	};

}