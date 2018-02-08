#include "FontLoader.h"

#pragma comment(lib, "x86/FreeType/freetype.lib")

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../debug/Exception.h"
#include "../graphics/texture/GLTexture.h"

namespace vt {
	namespace io {
		
		void loadGLFont(Font& font, ui16f fontSize, cString file, i32 index)
		{
			FT_Library ft;
			if (FT_Init_FreeType(&ft)) {
				vt::log::fatal("Could not initialize FreeType");
				vt::exception::crash();
			}

			FT_Face face;
			if (FT_New_Face(ft, file, index, &face)) {
				vt::log::fatal("Could not read font file \"", file, "\"");
				vt::exception::crash();
			}

			FT_Set_Pixel_Sizes(face, 0, fontSize);

			ui32f textureWidth = 32;
			ui32f textureHeight = 32;

			const ui16f padding = 1;

			ui16f cx;
			ui16f cy;
			ui16f lineHeight;

			bool widthHeightToggle = true;

			do {
				if (widthHeightToggle) textureWidth *= 2;
				else textureHeight *= 2;
				widthHeightToggle = !widthHeightToggle;

				cx = 0;
				cy = 0;
				lineHeight = 0;

				for (unsigned char c = 0; c < 128; c++) {
					if (FT_Load_Char(face, c, FT_LOAD_BITMAP_METRICS_ONLY)) {
						vt::log::fatal("Could read character '", c, "' from file \"", file, "\"");
						vt::exception::crash();
					}

					if (cx + (face->glyph->metrics.width >> 6) >= textureWidth) {
						cx = 0;
						cy += lineHeight + padding;
						lineHeight = 0;
					}

					cx += (face->glyph->metrics.width >> 6) + padding;
					if ((static_cast<ui16f>(face->glyph->metrics.height) >> 6) > lineHeight) {
						lineHeight = (face->glyph->metrics.height >> 6);
					}
				}

			} while (cy + lineHeight >= textureHeight);
			
			FontCharacter characters[128];
			ui8* textureData = new ui8[textureWidth * textureHeight];
			memset(textureData, 0, sizeof(ui8) * textureWidth * textureHeight);

			cx = 0;
			cy = 0;
			lineHeight = 0;

			for (unsigned char c = 0; c < 128; c++) {
				if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
					vt::log::fatal("Could read character '", c, "' from file \"", file, "\"");
					vt::exception::crash();
				}

				if (cx + face->glyph->bitmap.width >= textureWidth) {
					cx = 0;
					cy += lineHeight + padding;
					lineHeight = 0;
				}

				f32v2 texcoordOffset(static_cast<f32>(cx) / static_cast<f32>(textureWidth), static_cast<f32>(cy) / static_cast<f32>(textureHeight));
				f32v2 texcoordSize(static_cast<f32>(face->glyph->bitmap.width) / static_cast<f32>(textureWidth), static_cast<f32>(face->glyph->bitmap.rows) / static_cast<f32>(textureHeight));

				characters[c] = FontCharacter(c, i16fv2(face->glyph->bitmap_left, face->glyph->bitmap_top), ui16fv2(face->glyph->bitmap.width, face->glyph->bitmap.rows), texcoordOffset, texcoordSize, i16fv2(face->glyph->advance.x >> 6, face->glyph->advance.y >> 6));
			
				for (ui16f px = 0; px < face->glyph->bitmap.width; px++) {
					for (ui16f py = 0; py < face->glyph->bitmap.rows; py++) {
						textureData[(px + cx) + (py + cy) * textureWidth] = face->glyph->bitmap.buffer[px + py * face->glyph->bitmap.width];
					}
				}

				cx += face->glyph->bitmap.width + padding;
				if (face->glyph->bitmap.rows > lineHeight) {
					lineHeight = face->glyph->bitmap.rows;
				}
			}



			GLTexture* texture = new GLTexture();
			texture->initialize();
			texture->setData(textureData, textureWidth, textureHeight, FORMAT_R8, FILTER_LINEAR, ANISOTROPIC_FILTERING_NONE, WRAPPING_CLAMP);
			delete[] textureData;

			for (unsigned char c = 0; c < 128; c++) {
				font.addCharacter(characters[c]);
			}
			font.setTexture(texture);

			FT_Done_Face(face);
			FT_Done_FreeType(ft);
		}

		void loadGLFontUnpacked(UnpackedFont& font, ui16f fontSize, cString file, i32 index)
		{
			FT_Library ft;
			if (FT_Init_FreeType(&ft)) {
				vt::log::fatal("Could not initialize FreeType");
				vt::exception::crash();
			}

			FT_Face face;
			if (FT_New_Face(ft, file, index, &face)) {
				vt::log::fatal("Could not read font file \"", file, "\"");
				vt::exception::crash();
			}

			FT_Set_Pixel_Sizes(face, 0, fontSize);

			for (unsigned char c = 0; c < 128; c++) {
				if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
					vt::log::fatal("Could read character '", c, "' from file \"", file, "\"");
					vt::exception::crash();
				}

				GLTexture* texture = new GLTexture();
				texture->initialize();
				texture->setData(reinterpret_cast<const ui8*>(face->glyph->bitmap.buffer), face->glyph->bitmap.width, face->glyph->bitmap.rows, FORMAT_R8, FILTER_LINEAR, ANISOTROPIC_FILTERING_NONE, WRAPPING_CLAMP);

				font.addCharacter(UnpackedFontCharacter(c, texture, i16fv2(face->glyph->bitmap_left, face->glyph->bitmap_top), ui16fv2(face->glyph->bitmap.width, face->glyph->bitmap.rows), i16fv2(face->glyph->advance.x >> 6, face->glyph->advance.y >> 6)));
			}

			FT_Done_Face(face);
			FT_Done_FreeType(ft);
		}

	}
}