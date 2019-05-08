#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>

#include"CardFactory.h"
#include "Card.h"

using namespace std;

class Hand
{
public:
	Hand() = default;
	Hand(istream & in, const CardFactory * cardFactory);

	Card * play();
	Card * top();
	
	int size() const;

	Hand & operator+=(Card* card); // Add to rear
	Card * operator[](int i); //Return AND REMOVE!!!! >:C

	void print(ostream & out) const;

	friend ostream & operator<<(ostream & out, const Hand & hand);

private:
	vector<Card *> m_cards;
};

#endif // !HAND_H
