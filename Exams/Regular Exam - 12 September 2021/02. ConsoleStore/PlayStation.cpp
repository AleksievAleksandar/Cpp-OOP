#include "PlayStation.h"
#include <iostream>

PlayStation::PlayStation(const int price, const int quality, const int generation) : 
	Console(price, quality), 
	generation(generation)
{}

void PlayStation::print() const
{
	std::cout << "PS with generation " << this->generation << ", ";
	Console::print();
}
