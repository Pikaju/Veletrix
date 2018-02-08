#include "XMLAttributeMap.h"

namespace vt {

	bool XMLAttributeMap::findAttribute(const String& name, String& result) const
	{
		for (size_t i = 0; i < m_attributes.size(); i++) {
			if (m_attributes[i].getName() == name) {
				result = m_attributes[i].getValue();
				return true;
			}
		}
		return false;
	}

}