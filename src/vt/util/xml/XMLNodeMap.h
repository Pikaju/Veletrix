#pragma once

#include "XMLNode.h"
#include "../../Types.h"

namespace vt {

	class XMLTagNode;

	class XMLNodeMap
	{
	public:
		inline XMLNodeMap(XMLNode* owner) : m_owner(owner), m_nodes() {  }
		inline ~XMLNodeMap() { for (size_t i = 0; i < m_nodes.size(); i++) delete m_nodes[i]; }

		inline const XMLNode* getNode(size_t index) const { return m_nodes[index]; }
		inline void addNode(XMLNode* node) { node->setParent(m_owner); m_nodes.pushBack(node); }
		XMLTagNode* findTagNode(const String& name) const;
		inline size_t getNumNodes() const { return m_nodes.size(); }
	private:
		XMLNode* m_owner;
		Vector<XMLNode*> m_nodes;
	};

}