#ifndef DECK_H
#define DECK_H

#include <istream>
#include <vector>
#include "Card.h"

using namespace std;

class CardFactory;

class Deck
{
public:
	Deck() = default;
	Deck(istream & in, const CardFactory * cardFactory);

	static Deck randomizedDeck(CardFactory * cardFactory);

	bool isEmpty();
	Card * draw();

	void print(ostream & out) const;

	friend ostream & operator<<(ostream & out, const Deck & deck);

private:
	vector<Card *> m_cards;

};
#endif // !DECK_H
