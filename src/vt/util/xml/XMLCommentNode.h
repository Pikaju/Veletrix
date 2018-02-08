#pragma once

#include "XMLNode.h"

namespace vt {

	class XMLCommentNode : public XMLNode
	{
	public:
		inline XMLCommentNode() : XMLNode(XML_COMMENT_NODE) {  }
		inline XMLCommentNode(const String& comment) : XMLNode(XML_COMMENT_NODE), m_comment(comment) {  }
		inline ~XMLCommentNode() override {  }

		inline const String& getComment() const { return m_comment; }
	private:
		String m_comment;
	}

}