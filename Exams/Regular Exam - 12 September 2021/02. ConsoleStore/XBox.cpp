#include "XBox.h"

Xbox::Xbox(int price, int quality) : 
	Console(price, quality) 
{}

void Xbox::print()
{
	std::cout << "Xbox with ";
	Console::print();
}
