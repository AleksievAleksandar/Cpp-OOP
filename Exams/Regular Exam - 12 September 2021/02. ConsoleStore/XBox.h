#ifndef XBOX_H
#define XBOX_H

#include "Console.h"

class Xbox : public Console
{
public:
	Xbox(int price, int quality);
	void print();
};

#endif // !XBOX_H
