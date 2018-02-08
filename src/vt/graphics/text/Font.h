#pragma once

#include <unordered_map>

#include "../../Build.h"
#include "../../Types.h"

namespace vt {

	class FontCharacter
	{
	public:
		FontCharacter() {  }
		FontCharacter(char character, const i16fv2& offset, const ui16fv2& size, const f32v2& texcoordOffset, const f32v2& texcoordSize, const i16fv2& advance) : m_character(character), m_offset(offset), m_size(size), m_texcoordOffset(texcoordOffset), m_texcoordSize(texcoordSize), m_advance(advance) {  }
		~FontCharacter() {  }

		inline char getCharacter() const { return m_character; }
		inline const i16fv2& getOffset() const { return m_offset; }
		inline const ui16fv2& getSize() const { return m_size; }
		inline const f32v2& getTexcoordOffset() const { return m_texcoordOffset; }
		inline const f32v2& getTexcoordSize() const { return m_texcoordSize; }
		inline const i16fv2& getAdvance() const { return m_advance; }
	private:
		char m_character;
		i16fv2 m_offset;
		ui16fv2 m_size;
		f32v2 m_texcoordOffset;
		f32v2 m_texcoordSize;
		i16fv2 m_advance;
	};

	class Texture;

	class Font
	{
	public:
		Font();
		~Font();

		void initialize();
		void cleanup();

		ui16f getStringWidth(cString string) const;

		inline void addCharacter(const FontCharacter& character) { m_characters[character.getCharacter()] = character; }
		inline const FontCharacter& getCharacter(char character) const { return m_characters.find(character)->second; }

		inline const Texture* getTexture() const { return m_texture; }
		inline void setTexture(Texture* texture) { m_texture = texture; }
	private:
		std::unordered_map<char, FontCharacter> m_characters;
		Texture* m_texture;
	};

}