#include "Emerald.h"

Emerald::Emerald() : m_name(TYPE)
{
}

int Emerald::getCardsPerCoin(int coins) const
{
	if (coins > 0)
	{
		switch (coins)
		{
		default:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		}
	}


	return 0;
}

int Emerald::getCoinsPerCards(int numCards) const 
{
	if (numCards == 0 || numCards == 1)
	{
		return 0;
	}
	else if (numCards == 2)
	{
		return 2;
	}
	else if (numCards > 2)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int Emerald::getMaxChainSize() const {

	return MAX_CHAIN_SIZE;

}

string Emerald::getName() const
{
	return m_name;
}

void Emerald::print(ostream & out) const
{
	out << m_name[0];
}
