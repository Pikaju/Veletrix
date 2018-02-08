#include "Attachment.h"

#include "../../../glad/glad.h"

namespace vt {
	namespace attachment {

		ui32 getGLAttachment(Attachment attachment, unsigned int index)
		{
			switch (attachment) {
			case ATTACHMENT_COLOR: return GL_COLOR_ATTACHMENT0 + index;
			case ATTACHMENT_DEPTH: return GL_DEPTH_ATTACHMENT;
			}
			return 0;
		}

	}
}