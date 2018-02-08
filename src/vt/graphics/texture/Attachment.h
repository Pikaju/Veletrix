#pragma once

#include "../../Types.h"

namespace vt {

	enum Attachment
	{
		ATTACHMENT_COLOR,
		ATTACHMENT_DEPTH,
		ATTACHMENT_COUNT
	};

	namespace attachment {

		extern ui32 getGLAttachment(Attachment attachment, unsigned int index);

	}

}