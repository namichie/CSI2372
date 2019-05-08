#include "Table.h"

#include "CardFactory.h"

Table::Table(string firstPlayerName, string secondPlayerName, CardFactory * cardFactory) : m_discardPile(), m_tradeArea()
{
	Player first(firstPlayerName);
	Player second(secondPlayerName);

	m_players.push_back(first);
	m_players.push_back(second);

	if (cardFactory != nullptr)
	{
		m_deck = cardFactory->getDeck();
	}


	distributeStartingCards();
}

Table::Table(istream & in, CardFactory * cardFactory)
{
	Player first(in, cardFactory);
	Player second(in, cardFactory);

	m_players.push_back(first);
	m_players.push_back(second);

	//Deck
	m_deck = Deck(in, cardFactory);

	//Trade Area
	m_tradeArea = TradeArea(in, cardFactory);

	//Discard Pile
	m_discardPile = DiscardPile(in, cardFactory);
}

bool Table::win(string & winner)
{
	if (m_deck.isEmpty())
	{
		Player * richestPlayer;
		int highestCoins = INT_MIN;

		for (Player & player : m_players)
		{
			if (player.getNumCoins() > highestCoins)
			{
				highestCoins = player.getNumCoins();
				richestPlayer = &player;
			}
		}

		if (richestPlayer != nullptr)
		{
			winner = richestPlayer->getName();
			return true;
		}
	}

	return false;
}

void Table::print(ostream & out) const
{
	//Players
	for (const Player & player : m_players)
	{
		player.print(out);
	}

	//Deck
	m_deck.print(out);

	//Trade Area
	m_tradeArea.print(out);

	//Discard Pile
	m_discardPile.print(out);
}

void Table::distributeStartingCards()
{
	int numStartingCards = 5;

	for (int i = 0; i < numStartingCards; ++i)
	{
		for (Player & player : m_players)
		{
			player += m_deck.draw();
		}
	}

	m_deck;
}

ostream & operator<<(ostream & out, const Table & table)
{
	int i = 0;
	for (const Player & player : table.m_players)
	{
		out << ++i << ": " << player;
	}

	out << endl;

	out << "Trade Area: " << table.m_tradeArea << endl;

	out << "Discard Pile: " << table.m_discardPile << endl;

	return out;
}

//Game flow functions =============================================================================

bool Table::playOneRound(ostream & out, istream & in)
{
	for (Player & player : m_players)
	{
		out << "===================================" << endl;
		out << player.getName() << "'s turn" << endl;

		out << (*this);

		checkForThirdChain(out, in, player);

		useTradeArea(out, player);

		playTopmostCard(out, in, player);

		askToPlayAgain(out, in, player);

		promptPlayerForDiscard(out, in, player);

		drawThreeCardsForTradeArea(out);

		drawFromDiscardUntilDifferent(out);

		useTradeArea(out, player);

		drawCardForPlayer(out, player);

		out << "enter any character to continue";
		char c_continue;
		in >> c_continue;
	}

	return promptPlayersToPause(out, in);
}

void Table::checkForThirdChain(ostream & out, istream & in, Player & player)
{
	if (player.canBuyExtraChain())
	{
		out << player.getName() << ", do you want to buy another chain? (type \"Y\")" << endl;
		
		char response;
		in >> response;

		if (response == 'y' || response == 'Y')
		{
			player.buyThirdChain();
		}
	}
}

void Table::useTradeArea(ostream & out, Player & player)
{
	out << player.getName() << " uses the Trade Area: " << m_tradeArea << endl;

	int numberCardsDrawn = 0;

	if (m_tradeArea.getNumCards() > 0)
	{
		for (int i = 0; i < player.getNumChains(); ++i)
		{
			string chainType = player[i].getFirst()->getName();

			Card * card = m_tradeArea.trade(chainType);

			while (card != nullptr)
			{
				if (numberCardsDrawn == 0)
				{
					out << player.getName() << " drew: ";
				}

				out << (*card) << " ";
				
				++numberCardsDrawn;
				player[i] += card;

				if (tryToSellCompleteChain(out, player, i))
				{
					card = nullptr;
				}
				else
				{
					card = m_tradeArea.trade(player[i].getFirst()->getName());
				}
			}
		}
	}

	if (numberCardsDrawn > 0)
	{
		out << endl;
	}
	else
	{
		out << "Found nothing of use." << endl;
	}
}

void Table::playTopmostCard(ostream & out, istream & in, Player & player)
{
	Card * card = player.showTopCard();

	int chainIndex = getMatchingChain(card, player);

	if (chainIndex != -1)
	{
		player[chainIndex] += player.playTopCard();
		out << player.getName() << " played " << (*card) << " in the chain:" << endl;
		out << player[chainIndex];
	}
	else
	{
		if (player.getNumChains() >= player.getMaxNumChains())
		{
			promptPlayerToSellIncompleteChain(out, in, player);
		}

		player.createChain(player.playTopCard());
		out << player.getName() << " created a new chain of " << (*card) << endl;
	}
}

void Table::promptPlayerForDiscard(ostream & out, istream & in, Player & player)
{
	if (player.getNumCards() > 0)
	{
		out << player.getName() << ", you must discard a card." << endl;
		out << "Write the position of the card you want to discard (1.." << player.getNumCards() << ")" << endl;
		player.printHand(out, true);

		int index = -1;
		do
		{
			in >> index;

			if (!(index >= 1 && index <= player.getNumCards()))
			{
				out << "Valid indices: (1.." << player.getNumCards() << ")" << endl;;
			}
		} while (!(index >= 1 && index <= player.getNumCards()));

		Card * discardedCard = player.discardCardAtPosition(index - 1);
		m_discardPile += discardedCard;

		out << player.getName() << " discarded " << (*discardedCard) << endl;
	}
}

void Table::promptPlayerToSellIncompleteChain(ostream & out, istream & in, Player & player)
{
	out << "No valid placement for " << player.getName() << "'s first card." << endl;
	out << "You must sell an old chain. Which chain ? (1.." << player.getNumChains() << ")" << endl;

	for (int i = 0; i < player.getNumChains(); ++i)
	{
		out << player[i];
	}

	int index = -1;
	do
	{
		in >> index;

		if (!(index >= 1 || index <= player.getNumChains()))
		{
			out << "Valid indices: (1.." << player.getNumChains() << ")" << endl;
		}
	} while (!(index >= 1 && index <= player.getNumChains()));

	string type = player[index-1].getFirst()->getName();
	int coins = player.sellChain(index-1);
	out << player.getName() << " sold a chain of " << type << " for " << coins << " coins." << endl;
}

bool Table::promptPlayersToPause(ostream & out, istream & in)
{
	out << "Type 'p' to pause (save and quit), otherwise, any key to continue." << endl;

	char response;
	in >> response;

	if(response == 'p' || response == 'P')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Table::askToPlayAgain(ostream & out, istream & in, Player & player)
{
	bool done = false;
	while (!done && (getMatchingChain(player.showTopCard(), player) != -1 || player.getNumChains() < player.getMaxNumChains()))
	{
		out << player.getName() << ", do you want to play your next card?" << endl;
		out << "Next card: ";
		player.printHand(out);

		char response;
		in >> response;

		if (response == 'y' || response == 'Y')
		{
			playTopmostCard(out, in, player);

			if (player.getNumCards() == 0)
			{
				done = true;
			}
		}
		else
		{
			done = true;
		}
	}
}

void Table::drawThreeCardsForTradeArea(ostream & out)
{
	out << "Drawing cards from deck for Trade Area: ";
	for (int i = 0; i < 3; ++i)
	{
		if (!m_deck.isEmpty())
		{
			Card * card = m_deck.draw();
			m_tradeArea += card;
			out << (*card) << " ";
		}
	}

	out << endl;
}

void Table::drawFromDiscardUntilDifferent(ostream & out)
{
	out << "Drawing cards from discard pile for Trade Area: ";

	bool legal = m_tradeArea.legal(m_discardPile.top());
	
	while (legal)
	{
		if (m_discardPile.top() != nullptr)
		{
			Card * card = m_discardPile.pickUp();
			m_tradeArea += card;
			out << (*card) << " ";
			legal = m_tradeArea.legal(m_discardPile.top());
		}
		else
		{
			legal = false;
		}
	}
	out << endl;
}

bool Table::tryToSellCompleteChain(ostream & out, Player & player, int chainIndex)
{
	if (chainIsFull(player, chainIndex))
	{
		string type = player[chainIndex].getFirst()->getName();

		int coins = player.sellChain(chainIndex);
		out << player.getName() << " sold a chain of " << type << " for " << coins << " coins." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Table::chainIsFull(Player & player, int chainIndex) 
{
	Card * card = player[chainIndex].getFirst();
	return player[chainIndex].getChainSize() == card->getMaxChainSize();
}

int Table::getMatchingChain(Card * card, Player & player)
{
	for (int i = 0; i < player.getNumChains(); ++i)
	{
		if (!player[i].isEmpty())
		{
			Card * cardType = player[i].getFirst();
			if (card->getName().compare(cardType->getName()) == 0)
			{
				return i;
			}
		}
	}
	return -1;
}

void Table::drawCardForPlayer(ostream & out, Player & player)
{
	out << player.getName() << " has drawn ";
	for (int i = 0; i < 2; ++i)
	{
		if (!m_deck.isEmpty())
		{
			Card * card = m_deck.draw();
			out << (*card) << " ";
			player += card;
		}
		else
		{
			out << endl << "Deck is empty.";
		}
	}
	out << endl;
}