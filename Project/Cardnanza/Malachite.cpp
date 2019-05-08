#include "Malachite.h"

Malachite::Malachite() : m_name(TYPE)
{
}

int Malachite::getCardsPerCoin(int coins) const
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
			return 6;
		case 4:
			return 7;
		}
	}

	return 0;
}

int Malachite::getCoinsPerCards(int numCards) const 
{
	if (numCards >= 0 && numCards <= 2)
	{
		return 0;
	}
	else if (numCards >= 3 && numCards <= 4)
	{
		return 1;
	}
	else if (numCards == 5)
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

int Malachite::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}

string Malachite::getName() const
{
	return m_name;
}

void Malachite::print(ostream & out) const
{
	out << m_name[0];
}
