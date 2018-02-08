#include "XMLTree.h"

namespace vt {
	
	XMLTree::XMLTree()
	{
	}
	
	XMLTree::~XMLTree()
	{
	}

	void XMLTree::readFromString(const String& string)
	{
		XMLNode* node = &m_root;

		String data0;
		String data1;

		size_t line = 0;
		
	}

	void XMLTree::readTag(const String& string, size_t& currentChar, size_t& currentLine)
	{
		char c;
		while (true) {
			c = string[currentChar];
			if (c == '\n') {
				currentLine++;
				continue;
			}


			currentChar++;
		}
	}

	void XMLTree::readTagContent(const String& string, size_t& currentChar, size_t& currentLine, String& content)
	{
		char c;
		while ((c = string[currentChar]) != '<' && string[currentChar + 1] != '/') {
			if (c == '\n') {
				currentLine++;
				continue;
			}

			if (c == '<') {
				readTag(string, currentChar, currentLine);
				continue;
			}

			content += c;
			currentChar++;
		}
	}

}