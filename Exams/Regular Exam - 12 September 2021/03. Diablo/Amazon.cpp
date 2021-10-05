#include "Amazon.h"

Amazon::Amazon(const VitalData& vitalData) :
	attackTurns(1)
{
	this->_name = AMAZON_NAME;
	this->_vitalData = vitalData;
}

void Amazon::readSpellFromInput(SpellType spellType)
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

int Amazon::castSpell()
{
	int calculateMana = this->_vitalData.currMana - this->_spells[STRONGER_SPELL].manaCost;
	int damage = this->_spells[WEAKER_SPELL].damage;;

	std::string spellName = this->_spells[WEAKER_SPELL].name;
	int manaCost = this->_spells[WEAKER_SPELL].manaCost;
	int typeOfSpell = static_cast<int>(WEAKER_SPELL);

	if (calculateMana >= 0)
	{
		this->_vitalData.currMana -= this->_spells[STRONGER_SPELL].manaCost;
		damage = this->_spells[STRONGER_SPELL].damage;

		spellName = this->_spells[STRONGER_SPELL].name;
		manaCost = this->_spells[STRONGER_SPELL].manaCost;
		typeOfSpell = STRONGER_SPELL;
	}

	if (this->attackTurns == AMAZON_PASSIVE_ABILITY_COUNTER)
	{
		damage += damage*(AMAZON_DAMAGE_INCREASE_PERCENT / 100.0);
		this->attackTurns = 1;
	}
	else
	{
		this->attackTurns++;
	}

	std::cout << this->getName() << " casting " << spellName << " for " << manaCost << " mana " << std::endl;
	return damage;
}

void Amazon::takeDamage(int damage)
{
	this->_vitalData.health -= damage;
	std::cout << this->getName() << " took " << damage << " damage and is left with " << this->_vitalData.health << " health " << std::endl;
}

void Amazon::regenerate()
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

bool Amazon::isDead() const
{
	return this->_vitalData.health <= 0;
}
