#pragma once

#include "XMLAttributeMap.h"
#include "XMLNodeMap.h"

namespace vt {

	class XMLTagNode : public XMLNode
	{
	public:
		inline XMLTagNode() : XMLNode(XML_TAG_NODE), m_name(), m_attributeMap(), m_nodeMap(this) {  }
		inline ~XMLTagNode() override {  }

		inline const String& getName() const { return m_name; }

		inline XMLAttributeMap& getAttributeMap() { return m_attributeMap; }
		inline XMLNodeMap& getNodeMap() { return m_nodeMap; }
	private:
		String m_name;
		XMLAttributeMap m_attributeMap;
		XMLNodeMap m_nodeMap;
	};

}