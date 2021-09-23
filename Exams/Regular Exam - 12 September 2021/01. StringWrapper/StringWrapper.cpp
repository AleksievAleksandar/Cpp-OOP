#include "StringWrapper.h"
#include <iostream>
#include <sstream>
#include <string>

Input readInput()
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream iss(line);

	Input input;
	iss >> input.line >> input.letter >> input.repetitions;

	return input;
}

StringWrapper::StringWrapper(const std::string & line) 
{
	this->input.line = line;
}

StringWrapper::StringWrapper(const char & letter, const int & repetitions)
{
	this->input.letter = letter;
	this->input.repetitions = repetitions;
}

StringWrapper& StringWrapper::append(Input input)
{
	std::string s(input.repetitions, input.letter);
	input.line += s;
	this->input.line += input.line;

	return *this;
}

Input StringWrapper::getContent() const
{
	return this->input;
}

void StringWrapper::printContent() 
{
	std::cout << this->input.line;
}
