#pragma once

#include "../../Types.h"

namespace vt {

	class XMLAttribute
	{
	public:
		inline XMLAttribute() {  }
		inline XMLAttribute(const String& name, const String& value) : m_name(name), m_value(value) {  }
		inline ~XMLAttribute() {  }

		inline const String& getName() const { return m_name; }
		inline const String& getValue() const { return m_value; }
	private:
		String m_name;
		String m_value;
	};

	class XMLAttributeMap
	{
	public:
		inline XMLAttributeMap() {  }
		inline ~XMLAttributeMap() {  }

		inline const String& getAttributeName(size_t index) const { return m_attributes[index].getName(); }
		inline const String& getAttributeValue(size_t index) const { return m_attributes[index].getValue(); }
		bool findAttribute(const String& name, String& result) const;
		inline void addAttribute(const String& name, const String& value) { m_attributes.pushBack(XMLAttribute(name, value)); }
		inline size_t getNumAttributes() const { return m_attributes.size(); }
	private:
		Vector<XMLAttribute> m_attributes;
	};

}