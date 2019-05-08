#include "Amethyst.h"

Amethyst::Amethyst() : m_name(TYPE)
{
}

int Amethyst::getCardsPerCoin(int coins) const
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
			return 3;
		case 3:
			return 4;
		case 4:
			return 5;
		}
	}


	return 0;
}

int Amethyst::getCoinsPerCards(int numCards) const 
{
	if (numCards == 0 || numCards == 1)
	{
		return 0;
	}
	else if (numCards == 2)
	{
		return 1;
	}
	else if (numCards == 3)
	{
		return 2;
	}
	else if (numCards > 3)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int Amethyst::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}

string Amethyst::getName() const
{
	return m_name;
}

void Amethyst::print(ostream & out) const
{
	out << m_name[0];
}
