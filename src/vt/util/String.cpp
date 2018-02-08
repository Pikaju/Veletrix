#include "String.h"

namespace vt {

	Vector<String> splitString(const String& string, const String& sequence)
	{
		Vector<String> strings;
		ui32f previous = 0;
		ui32f position = 0;
		while ((position = string.find(sequence, previous)) != string.npos) {
			strings.pushBack(string.substr(previous, position - previous));
			previous = position + sequence.length();
		}
		strings.pushBack(string.substr(previous));

		return strings;
	}

}