#ifndef AMETHYST_H
#define AMETHYST_H

#include "Card.h"

class Amethyst : public Card
{
public:
	static constexpr const char* TYPE = "Amethyst";
	int const MAX_CHAIN_SIZE = 5;

	Amethyst();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !AMETHYST_H
