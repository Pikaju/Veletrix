#include "XMLNodeMap.h"

#include "XMLTagNode.h"

namespace vt {

	XMLTagNode* XMLNodeMap::findTagNode(const String& name) const
	{
		for (size_t i = 0; i < m_nodes.size(); i++) {
			if (m_nodes[i]->getType() == XML_TAG_NODE) {
				XMLTagNode* tagNode = reinterpret_cast<XMLTagNode*>(m_nodes[i]);
				if (tagNode->getName() == name) {
					return tagNode;
				}
			}
		}
		return nullptr;
	}

}