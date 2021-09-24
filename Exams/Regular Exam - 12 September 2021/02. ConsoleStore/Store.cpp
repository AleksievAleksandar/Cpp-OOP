#include "Store.h"

#include <algorithm>

void Store::addPs(const int price, const int quality, const int generation)
{
	this->playStations.push_back(PlayStation(price, quality, generation));
	std::cout << "Adding: ";
	this->playStations.back().print();
}

void Store::addXbox(const int price, const int quality)
{
	this->xBoxs.push_back(Xbox(price, quality));
	std::cout << "Adding: ";
	this->xBoxs.back().print();
}

void Store::remove(const ConsoleType & consoleType)
{
	switch (consoleType)
	{
	case ConsoleType::PS:
		if (!this->playStations.empty())
		{
			std::cout << "Removing: ";
			this->playStations.back().print();
			this->playStations.pop_back();
		}
		break;

	case ConsoleType::XBOX:
		if (!this->xBoxs.empty())
		{
			std::cout << "Removing: ";
			this->xBoxs.back().print();
			this->xBoxs.pop_back();
		}
		break;

	default:
		break;
	}
}

void Store::sortByPrice(const ConsoleType & consoleType)
{
	switch (consoleType)
	{
	case ConsoleType::PS:
		std::sort(this->playStations.begin(), this->playStations.end(), [](const PlayStation a, const PlayStation b) {return b.getPrice() < a.getPrice(); });
		std::cout << "Sorting all PS by price\n";
		break;

	case ConsoleType::XBOX:
		std::sort(this->xBoxs.begin(), this->xBoxs.end(), [](const Xbox a, const Xbox b) {return b.getPrice() < a.getPrice(); });
		std::cout << "Sorting all Xbox by price\n";
		break;

	default:
		break;
	}
}

void Store::sortByQuality(const ConsoleType & consoleType)
{
	switch (consoleType)
	{
	case ConsoleType::PS:
		std::sort(this->playStations.begin(), this->playStations.end(), [](const PlayStation a, const PlayStation b) {return b.getQuality() < a.getQuality(); });
		std::cout << "Sorting all PS by quality\n";
		break;

	case ConsoleType::XBOX:
		std::sort(this->xBoxs.begin(), this->xBoxs.end(), [](const Xbox a, const Xbox b) {return b.getQuality() < a.getQuality(); });
		std::cout << "Sorting all Xbox by quality\n";
		break;

	default:
		break;
	}
}

void Store::print(const ConsoleType & consoleType)
{
	switch (consoleType)
	{
	case ConsoleType::XBOX:
		if (!this->xBoxs.empty())
		{
			std::cout << "Printing all Xbox data\n";
			for (size_t i = 0; i < this->xBoxs.size(); i++)
			{
				this->xBoxs[i].print();
			}
		}

		break;

	case ConsoleType::PS:
		if (!this->playStations.empty())
		{
			std::cout << "Printing all PS data\n";
			for (size_t i = 0; i < this->playStations.size(); i++)
			{
				this->playStations[i].print();
			}
		}
		break;

	default:
		break;
	}
}
