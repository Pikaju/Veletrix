#pragma once

#include "XMLRootNode.h"

namespace vt {

	class XMLTree
	{
	public:
		XMLTree();
		~XMLTree();

		void readFromString(const String& string);
	private:
		void readTag(const String& string, size_t& currentChar, size_t& currentLine);
		void readTagAttributes(const String& string, size_t& currentChar, size_t& currentLine);
		void readTagContent(const String& string, size_t& currentChar, size_t& currentLine, String& content);

		XMLRootNode m_root;
	};

}