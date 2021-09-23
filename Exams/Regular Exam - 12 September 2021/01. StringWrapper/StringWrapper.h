#ifndef STRING_WRAPPER_H
#define STRING_WRAPPER_H

#include <string>
#include "InputParser.h"

class StringWrapper
{
private:
	Input input;
public:
	StringWrapper() = default;
	StringWrapper(const std::string& line);
	StringWrapper(const char& letter, const int& repetitions);

	StringWrapper& append(Input input);
	Input getContent() const;
	void printContent();
};

#endif // !STRING_WRAPPER_H
