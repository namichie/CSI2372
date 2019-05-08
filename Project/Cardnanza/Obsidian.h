#ifndef OBSIDIAN_H
#define OBSIDIAN_H

#include "Card.h"

class Obsidian : public Card
{
public:
	static constexpr const char* TYPE = "Obsidian";
	int const MAX_CHAIN_SIZE = 8;
	
	Obsidian();

	int getCardsPerCoin(int coins) const override;
	int getCoinsPerCards(int numCards) const override;
	int getMaxChainSize() const override;
	string getName() const override;
	void print(ostream & out) const override;

private:
	string m_name;
};

#endif // !OBSIDIAN_H
