#include "Quartz.h"

Quartz::Quartz() : m_name(TYPE)
{
}

int Quartz::getCardsPerCoin(int coins) const
{
	if (coins > 0)
	{
		switch (coins)
		{
		default:
			return 1;
		case 1:
			return 4;
		case 2:
			return 6;
		case 3:
			return 8;
		case 4:
			return 10;
		}
	}

	return 0;
}

int Quartz::getCoinsPerCards(int numCards) const 
{
	if (numCards >= 0 && numCards <= 3)
	{
		return 0;
	}
	else if (numCards >= 4 && numCards <= 5)
	{
		return 1;
	}
	else if (numCards >= 6 && numCards <= 7)
	{
		return 2;
	}
	else if (numCards > 7)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int Quartz::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}


string Quartz::getName() const
{
	return m_name;
}

void Quartz::print(ostream & out) const
{
	out << m_name[0];
}
