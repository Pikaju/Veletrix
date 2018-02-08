#pragma once

#include "../../Types.h"
#include "XMLNode.h"

namespace vt {

	class XMLContentNode : public XMLNode
	{
	public:
		inline XMLContentNode() : XMLNode(XML_CONTENT_NODE), m_content() {  }
		inline XMLContentNode(const String& content) : XMLNode(XML_CONTENT_NODE), m_content(content) {  }
		inline ~XMLContentNode() override {  }

		inline const String& getContent() const { return m_content; }
	private:
		String m_content;
	};

}