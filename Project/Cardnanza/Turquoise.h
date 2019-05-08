#ifndef TURQUOISE_H
#define TURQUOISE_H

#include "Card.h"

class Turquoise : public Card
{
public:
	static constexpr const char* TYPE = "Turquoise";
	int const MAX_CHAIN_SIZE = 7;
	
	Turquoise();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !TURQUOISE_H
