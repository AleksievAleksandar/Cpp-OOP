#ifndef AMAZON_H
#define AMAZON_H

#include "Hero.h"

class Amazon : public Hero
{
private:
	int attackTurns;
public:
	Amazon(const VitalData& vitalData);

	virtual void readSpellFromInput(SpellType spellType) override;
	//returns the produced damage
	virtual int castSpell() override;
	virtual void takeDamage(int damage) override;
	virtual void regenerate() override;
	virtual bool isDead() const override;
};

#endif // !AMAZON_H
