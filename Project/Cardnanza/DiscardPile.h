#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

#include <vector>
#include <iostream>

class Card;
class CardFactory;

using namespace std;

class DiscardPile
{
public:
	DiscardPile() = default;
	DiscardPile(istream & in, const CardFactory * cardFactory);

	Card * pickUp();
	Card * top() const;
	void print(ostream & out) const;

	bool isEmpty()const ;

	DiscardPile & operator+=(Card * card);
	friend ostream & operator<<(ostream & out, const DiscardPile & discardPile);

private:
	std::vector<Card *> m_cards;
};

#endif // !DISCARD_PILE_H