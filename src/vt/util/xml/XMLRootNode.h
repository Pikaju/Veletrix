#pragma once

#include "XMLNode.h"
#include "XMLNodeMap.h"

namespace vt {

	class XMLRootNode : public XMLNode
	{
	public:
		inline XMLRootNode() : XMLNode(XML_ROOT_NODE), m_nodeMap(this) {  }
		inline ~XMLRootNode() override {  }

		inline XMLNodeMap& getNodeMap() { return m_nodeMap; }
	private:
		XMLNodeMap m_nodeMap;
	};

}