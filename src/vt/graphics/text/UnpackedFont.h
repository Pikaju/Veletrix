#pragma once

#include <unordered_map>

#include "../../Build.h"
#include "../../Types.h"

namespace vt {

	class Texture;

	class UnpackedFontCharacter
	{
	public:
		UnpackedFontCharacter() {  }
		UnpackedFontCharacter(char character, Texture* texture, const i16fv2& offset, const ui16fv2& size, const i16fv2& advance) : m_character(character), m_texture(texture), m_offset(offset), m_size(size), m_advance(advance) {  }
		~UnpackedFontCharacter() {  }

		inline char getCharacter() const { return m_character; }
		inline Texture* getTexture() const { return m_texture; }
		inline const i16fv2& getOffset() const { return m_offset; }
		inline const ui16fv2& getSize() const { return m_size; }
		inline const i16fv2& getAdvance() const { return m_advance; }
	private:
		char m_character;
		Texture* m_texture;
		i16fv2 m_offset;
		ui16fv2 m_size;
		i16fv2 m_advance;
	};

	class VT_API UnpackedFont
	{
	public:
		UnpackedFont();
		~UnpackedFont();

		void initialize();
		void cleanup();

		ui16f getStringWidth(cString string) const;

		inline void addCharacter(const UnpackedFontCharacter& character) { m_characters[character.getCharacter()] = character; }
		inline const UnpackedFontCharacter& getCharacter(char character) const { return m_characters.find(character)->second; }
	private:
		std::unordered_map<char, UnpackedFontCharacter> m_characters;
	};

}