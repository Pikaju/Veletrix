#pragma once

#include "XMLNode.h"
#include "XMLAttributeMap.h"

namespace vt {

	class XMLProcessingInstructionNode : public XMLNode
	{
	public:
		inline XMLProcessingInstructionNode() : XMLNode(XML_PROCESSING_INSTRUCTION_NODE), m_name(), m_attributeMap() {  }
		inline ~XMLProcessingInstructionNode() override {  }

		inline const String& getName() const { return m_name; }

		inline XMLAttributeMap& getAttributeMap() { return m_attributeMap; }
	private:
		String m_name;
		XMLAttributeMap m_attributeMap;
	};

}