#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include "Deck.h"

#include <map>

using namespace std;

class CardFactory
{
public:
	static CardFactory * getFactory();
	~CardFactory();

	Card * getCard(string type) const;
	Deck getDeck();

private:
	static CardFactory * m_cardFactory;
	map<string, Card *> cards;

	CardFactory();
};
#endif // !CARD_FACTORY_H
