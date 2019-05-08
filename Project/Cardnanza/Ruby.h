#ifndef RUBY_H
#define RUBY_H

#include "Card.h"

class Ruby : public Card
{
public:
	static constexpr const char* TYPE = "Ruby";
	int const MAX_CHAIN_SIZE = 6;

	Ruby();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !RUBY_H
