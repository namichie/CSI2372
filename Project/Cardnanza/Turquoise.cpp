#include "Turquoise.h"

Turquoise::Turquoise() : m_name(TYPE)
{
}

int Turquoise::getCardsPerCoin(int coins) const
{
	if (coins > 0)
	{
		switch (coins)
		{
		default:
			return 1;
		case 1:
			return 2;
		case 2:
			return 4;
		case 3:
			return 6;
		case 4:
			return 7;
		}
	}

	return 0;
}

int Turquoise::getCoinsPerCards(int numCards) const 
{
	if (numCards >= 0 && numCards <= 1)
	{
		return 0;
	}
	else if (numCards >= 2 && numCards <= 3)
	{
		return 1;
	}
	else if (numCards >= 4 && numCards <= 5)
	{
		return 2;
	}
	else if (numCards > 5)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int Turquoise::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}

string Turquoise::getName() const
{
	return m_name;
}

void Turquoise::print(ostream & out) const
{
	out << m_name[0];
}
