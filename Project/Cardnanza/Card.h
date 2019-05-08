#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>

using namespace std;

class Card
{
public:
	virtual int getCardsPerCoin(int coins) const = 0;
	virtual int getCoinsPerCards(int numCards) const = 0;
	virtual string getName() const = 0;
	virtual int getMaxChainSize() const = 0;
	virtual void print(ostream & out) const = 0;
	
	friend ostream & operator<<(ostream & out, const Card & card)
	{
		out << card.getName()[0];

		return out;
	}
};
#endif // !CARD_H
