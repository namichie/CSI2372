#include "Ruby.h"

Ruby::Ruby() : m_name(TYPE)
{
}

int Ruby::getCardsPerCoin(int coins) const
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
			return 5;
		case 4:
			return 6;
		}
	}

	return 0;
}

int Ruby::getCoinsPerCards(int numCards) const 
{
	if (numCards >= 0 && numCards <= 1)
	{
		return 0;
	}
	else if (numCards >= 2 && numCards <= 3)
	{
		return 1;
	}
	else if (numCards == 4)
	{
		return 2;
	}
	else if (numCards > 4)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int Ruby::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}

string Ruby::getName() const
{
	return m_name;
}

void Ruby::print(ostream & out) const
{
	out << m_name[0];
}
