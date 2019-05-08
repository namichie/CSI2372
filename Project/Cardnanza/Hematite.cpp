#include "Hematite.h"

Hematite::Hematite() : m_name(TYPE)
{
}

int Hematite::getCardsPerCoin(int coins) const
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
			return 6;
		case 3:
			return 8;
		case 4:
			return 9;
		}
	}

	return 0;
}

int Hematite::getCoinsPerCards(int numCards) const 
{
	if (numCards >= 0 && numCards <= 2)
	{
		return 0;
	}
	else if (numCards >= 3 && numCards <= 5)
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


int Hematite::getMaxChainSize() const {
	return MAX_CHAIN_SIZE;
}



string Hematite::getName() const
{
	return m_name;
}




void Hematite::print(ostream & out) const
{
	out << m_name[0];
}






