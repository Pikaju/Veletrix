#include "Compiler.h"

#include <fstream>

#include "../util/StringBuilder.h"

namespace vt {

	void Compiler::compile(const char* file)
	{
		StringBuilder builder;
		load(file, builder);
		printf(builder.getString().c_str());
	}

	void Compiler::load(const char* file, StringBuilder& source)
	{
		std::ifstream in(file);
		std::string line;
		while (!in.eof()) {
			std::getline(in, line);
			source.append(line);
		}
	}

}