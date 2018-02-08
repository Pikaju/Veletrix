#include "ImageLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../stb/stb_image.h"

#include "../graphics/texture/GLTexture.h"
#include "../graphics/texture/Format.h"

#include "../io/Console.h"

namespace vt {
	namespace io {

		GLTexture loadGLTexture(cString file, const Filter& filter, const AnisotropicFiltering& anisotropicFiltering, const Wrapping& wrapping)
		{
			GLTexture texture;
			texture.initialize();
			ui8* data;
			ui32f width;
			ui32f height;
			Format format;
			loadImage(file, &data, &width, &height, &format);
			texture.setData(data, width, height, format, filter, anisotropicFiltering, wrapping);
			delete[] data;
			return texture;
		}

		void loadImage(cString file, ui8** data, ui32f* width, ui32f* height, Format* format)
		{
			i32 comp;
			*data = stbi_load(file, reinterpret_cast<int*>(width), reinterpret_cast<int*>(height), &comp, 0);
			switch (comp) {
			case 1: *format = FORMAT_R8; break;
			case 3: *format = FORMAT_RGB8; break;
			case 4: *format = FORMAT_RGBA8; break;
			}
			if (*data == nullptr) {
				log::error("Could not load image file: \"", file, "\"");
			}
		}

	}
}