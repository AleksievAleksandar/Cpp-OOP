#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Hero.h"

class Barbarian : public Hero
{
private:
	int defendsTurns;
public:
	Barbarian(const VitalData& vitalData);

	virtual void readSpellFromInput(SpellType spellType) override;
	//returns the produced damage
	virtual int castSpell() override;
	virtual void takeDamage(int damage) override;
	virtual void regenerate() override;
	virtual bool isDead() const override;
};

#endif // !BARBARIAN_H
