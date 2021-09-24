#ifndef STORE_H
#define STORE_H

#include "Console.h"
#include "Defines.h"
#include "PlayStation.h"
#include "XBox.h"
#include <vector>

class Store
{
private:
	std::vector<Xbox> xBoxs;
	std::vector<PlayStation> playStations;
public:
	void addPs(const int price, const int quality, const int generation);
	void addXbox(const int price, const int quality);
	void remove(const ConsoleType& consoleType);
	void sortByPrice(const ConsoleType& consoleType);
	void sortByQuality(const ConsoleType& consoleType);
	void print(const ConsoleType& consoleType);
};

#endif // !STORE_H
