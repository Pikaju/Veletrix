#pragma once

namespace vt {

	enum XMLNodeType
	{
		XML_CONTENT_NODE,
		XML_COMMENT_NODE,
		XML_PROCESSING_INSTRUCTION_NODE,
		XML_TAG_NODE,

		XML_ROOT_NODE
	};

	class XMLNode
	{
	public:
		inline XMLNode(XMLNodeType type) : m_type(type) {  }
		virtual inline ~XMLNode() {  }

		inline XMLNodeType getType() const { return m_type; }

		inline XMLNode* getParent() { return m_parent; }
		inline void setParent(XMLNode* parent) { m_parent = parent; }
	private:
		XMLNodeType m_type;
		XMLNode* m_parent;
	};

}