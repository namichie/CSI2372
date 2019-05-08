#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <ostream>
#include <vector>

#include "Deck.h"
#include "Player.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class CardFactory;

using namespace std;

class Table
{
public:
	Table(string firstPlayerName, string secondPlayerName, CardFactory * cardFactory);
	Table(istream & in, CardFactory * cardFactory);

	bool win(string & winner);
	void print(ostream & out) const;

	friend ostream & operator<<(ostream & out, const Table & table);

	bool playOneRound(ostream & out, istream & in);

private:
	vector<Player> m_players;
	Deck m_deck;
	DiscardPile m_discardPile;
	TradeArea m_tradeArea;

	void distributeStartingCards();

	//Game flow functions
	void checkForThirdChain(ostream & out, istream & in, Player & player);
	void useTradeArea(ostream & out, Player & player);
	void drawCardForPlayer(ostream & out, Player & player);
	void playTopmostCard(ostream & out, istream & in, Player & player);
	void promptPlayerForDiscard(ostream & out, istream & in, Player & player);
	void askToPlayAgain(ostream & out, istream & in, Player & player);
	void drawThreeCardsForTradeArea(ostream & out);
	void drawFromDiscardUntilDifferent(ostream & out);

	void promptPlayerToSellIncompleteChain(ostream & out, istream & in, Player & player);

	bool promptPlayersToPause(ostream & out, istream & in);

	bool tryToSellCompleteChain(ostream & out, Player & player, int chainIndex);
	bool chainIsFull(Player & player, int chainIndex);
	int getMatchingChain(Card * card, Player & player);

};

#endif // !TABLE_H
