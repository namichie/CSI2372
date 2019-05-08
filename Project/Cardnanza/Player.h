#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Chain.h"
#include "Hand.h"

using namespace std;

class CardFactory;

class Player
{
public:
	const int CHAIN_COST = 2;
	const int STARTING_CHAINS = 2;
	const int MAX_CHAINS = 3;


	Player(const string & name);
	Player(istream & in, const CardFactory * cardFactory);

	string getName() const;
	int getNumCoins() const;
	int getMaxNumChains() const;
	int getNumChains() const;
	int getNumCards() const;
	void buyThirdChain();
	bool canBuyExtraChain() const;

	Card * showTopCard();
	Card * playTopCard();

	Card * discardCardAtPosition(int index);

	Chain<Card *> * createChain(Card * card);
	int sellChain(int chainIndex);

	void printHand(ostream & out, bool showAllCards = false) const;
	void print(ostream & out) const;

	Chain<Card *> & operator[](int i);
	Player & operator+=(int numCoins);
	Player & operator+=(Card * card);
	friend ostream & operator<<(ostream & out, const Player & player);

private:
	string m_name;
	int m_coins;
	int m_maxChains = 2;
	Hand m_hand;
	vector<Chain<Card *>> m_chains;
};


#endif // !PLAYER_H

