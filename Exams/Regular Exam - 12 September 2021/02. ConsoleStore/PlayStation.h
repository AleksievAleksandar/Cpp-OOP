#ifndef PLAY_STATION_H
#define PLAY_STATION_H

#include "Console.h"

class PlayStation : public Console
{
private:
	int generation;
public:
	PlayStation(const int price, const int quality, const int generation);
	void print() const;
};

#endif // !PLAY_STATION_H
