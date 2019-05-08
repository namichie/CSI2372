#ifndef MALACHITE_H
#define MALACHITE_H

#include "Card.h"

class Malachite : public Card
{
public:
	static constexpr const char* TYPE = "Malachite";
	int const MAX_CHAIN_SIZE = 7;

	Malachite();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !MALACHITE_H
