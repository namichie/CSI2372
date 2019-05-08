#ifndef EMERALD_H
#define EMERALD_H

#include "Card.h"

class Emerald : public Card
{
public:
	static constexpr const char* TYPE = "Emerald";
	int const MAX_CHAIN_SIZE = 3;

	Emerald();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !EMERALD_H
