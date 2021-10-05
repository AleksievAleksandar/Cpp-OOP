#include "Barbarian.h"

#include <iostream>
#include <sstream>
#include <string>

Barbarian::Barbarian(const VitalData& vitalData) : 
	defendsTurns(1)
{
	this->_name = BARBARIAN_NAME;
	this->_vitalData = vitalData;
}

void Barbarian::readSpellFromInput(SpellType spellType)
{
	switch (spellType)
	{
	case SpellType::Weak:
		std::cin >> this->_spells[WEAKER_SPELL].name >> this->_spells[WEAKER_SPELL].damage;
		break;

	case SpellType::Strong:
		std::cin >> this->_spells[STRONGER_SPELL].name >> this->_spells[STRONGER_SPELL].damage >> this->_spells[STRONGER_SPELL].manaCost;
		break;

	default:
		break;
	}
}

int Barbarian::castSpell()
{
	int calculateMana = this->_vitalData.currMana - this->_spells[STRONGER_SPELL].manaCost;

	std::string spellName = this->_spells[WEAKER_SPELL].name;
	int manaCost = this->_spells[WEAKER_SPELL].manaCost;
	int typeOfSpell = static_cast<int>(WEAKER_SPELL);

	if (calculateMana >= 0)
	{
		this->_vitalData.currMana -= this->_spells[STRONGER_SPELL].manaCost;

		spellName = this->_spells[STRONGER_SPELL].name;
		manaCost = this->_spells[STRONGER_SPELL].manaCost;
		typeOfSpell = STRONGER_SPELL;
	}

	std::cout << this->getName() << " casting " << spellName << " for " << manaCost << " mana " << std::endl;

	return this->_spells[typeOfSpell].damage;
}

void Barbarian::takeDamage(int damage)
{
	if (this->defendsTurns == BARBARIAN_PASSIVE_ABILITY_COUNTER)
	{
		damage *= (BARBARIAN_DAMAGE_BLOCK_PERCENT / 100.0);
		this->defendsTurns = 1;
	}
	else
	{
		this->defendsTurns++;
	}

	this->_vitalData.health -= damage;

	std::cout << this->getName() << " took " << damage << " damage and is left with " << this->_vitalData.health << " health " << std::endl;
}

void Barbarian::regenerate()
{
	int regenMana = 0;
	if (this->_vitalData.manaRegenRate + this->_vitalData.currMana <= this->_vitalData.maxMana)
	{
		this->_vitalData.currMana += this->_vitalData.manaRegenRate;
		regenMana = this->_vitalData.manaRegenRate;
	}
	else
	{
		regenMana = (this->_vitalData.manaRegenRate + this->_vitalData.currMana) - this->_vitalData.maxMana;
		this->_vitalData.currMana = this->_vitalData.maxMana;
	}
	std::cout << this->getName() << " regained " << regenMana << " mana for up to " << this->_vitalData.currMana << std::endl;
}

bool Barbarian::isDead() const
{
	return this->_vitalData.health <= 0;
}
