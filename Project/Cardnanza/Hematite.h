#ifndef HEMATITE_H
#define HEMATITE_H

#include "Card.h"

class Hematite : public Card
{
public:
	static constexpr const char* TYPE = "Hematite";
	int const MAX_CHAIN_SIZE = 9;

	Hematite();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !HEMATITE_H
