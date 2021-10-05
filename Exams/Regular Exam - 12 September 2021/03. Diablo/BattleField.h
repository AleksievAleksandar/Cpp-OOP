#ifndef BATTLE_FIELD_H
#define BATTLE_FIELD_H

#include <memory>
#include <vector>

#include "Hero.h"

class BattleField
{
private:
	std::vector<std::unique_ptr<Hero> > _heroes;
public:
	void createHeroes();
	void createSpells();
	void startBattle();
	void printWinner(const std::unique_ptr<Hero>& hero);
};

#endif // !BATTLE_FIELD_H
