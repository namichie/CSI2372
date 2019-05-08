#ifndef TRADE_AREA_H
#define TRADE_AREA_H

#include <list>
#include <iostream>

#include "Card.h"

class CardFactory;

using namespace std;

class TradeArea
{
public:
	TradeArea() = default;
	TradeArea(istream & in, const CardFactory * cardFactory);

	int getNumCards() const;
	bool legal(Card * card) const;
	Card* trade(string cardType);

	void print(ostream & out) const;

	TradeArea & operator+=(Card* card);
	friend ostream & operator<<(ostream & out, const TradeArea & tradeArea);

private:
	list<Card *> m_cards;

};

#endif // !TRADE_AREA_H
