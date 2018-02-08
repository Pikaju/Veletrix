#include "GLTextRenderer.h"

#include "../texture/Texture.h"
#include "../shader/GLShaderProgram.h"
#include "../renderer/GLBatchRenderer.h"
#include "../model/Attribute.h"
#include "../../util/Vector.h"

namespace vt {

	void GLTextRenderer::renderText(const Font& font, const GLShaderProgram& shader, cString text, f32 x, f32 y)
	{
		GLBatchRenderer renderer;
		renderer.setBlending(vt::BLENDING_TRANSPARENCY);

		renderer.initialize();
		Vector<Attribute> attributes;
		attributes.pushBack(Attribute(TYPE_FLOAT, 2, false));
		attributes.pushBack(Attribute(TYPE_FLOAT, 2, false));
		renderer.allocate(6 * strlen(text), attributes.data(), attributes.size(), USAGE_HINT_STREAM);

		font.getTexture()->enable(0);

		shader.enable();
		renderer.begin();

		float cx = x;
		float cy = y;

		class FontVertex
		{
		public:
			f32v2 position;
			f32v2 texcoord;

			FontVertex(const f32v2& position, const f32v2& texcoord) : position(position), texcoord(texcoord) {  }
			~FontVertex() {  }
		};

		for (ui16f i = 0; text[i] != '\0'; i++) {
			const FontCharacter& character = font.getCharacter(text[i]);

			FontVertex v0(f32v2(cx + character.getOffset().x, cy - character.getOffset().y), character.getTexcoordOffset());
			FontVertex v1(f32v2(cx + character.getOffset().x, cy - character.getOffset().y + character.getSize().y), character.getTexcoordOffset() + f32v2(0.0f, character.getTexcoordSize().y));
			FontVertex v2(f32v2(cx + character.getOffset().x + character.getSize().x, cy - character.getOffset().y + character.getSize().y), character.getTexcoordOffset() + character.getTexcoordSize());
			FontVertex v3(f32v2(cx + character.getOffset().x + character.getSize().x, cy - character.getOffset().y), character.getTexcoordOffset() + f32v2(character.getTexcoordSize().x, 0.0f));

			renderer.submit(&v0, &v1, &v2);
			renderer.submit(&v0, &v2, &v3);

			cx += character.getAdvance().x;
			cy += character.getAdvance().y;
		}

		renderer.end();

		renderer.cleanup();
		renderer.setBlending(vt::BLENDING_DISABLED);
	}

}