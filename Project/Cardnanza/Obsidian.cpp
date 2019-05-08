#include "Obsidian.h"

Obsidian::Obsidian() : m_name(TYPE)
{
}

int Obsidian::getCardsPerCoin(int coins) const
{
	if (coins > 0)
	{
		switch (coins)
		{
		default:
			return 1;
		case 1:
			return 3;
		case 2:
			return 5;
		case 3:
			return 7;
		case 4:
			return 8;
		}
	}

	return 0;
}

int Obsidian::getCoinsPerCards(int numCards) const 
{
	if (numCards >= 0 && numCards <= 2)
	{
		return 0;
	}
	else if (numCards >= 3 && numCards <= 4)
	{
		return 1;
	}
	else if (numCards >= 5 && numCards <= 6)
	{
		return 2;
	}
	else if (numCards > 6)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int Obsidian::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}

string Obsidian::getName() const
{
	return m_name;
}

void Obsidian::print(ostream & out) const
{
	out << m_name[0];
}
