#ifndef QUARTZ_H
#define QUARTZ_H

#include "Card.h"

class Quartz : public Card
{
public:
	static constexpr const char* TYPE = "Quartz";
	int const MAX_CHAIN_SIZE = 10;

	Quartz();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !QUARTZ_H
