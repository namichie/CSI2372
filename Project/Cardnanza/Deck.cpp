#include "Deck.h"

#include <algorithm>
#include <random>
#include "time.h"

#include "CardFactory.h"

#include "Amethyst.h"
#include "Emerald.h"
#include "Hematite.h"
#include "Malachite.h"
#include "Obsidian.h"
#include "Quartz.h"
#include "Ruby.h"
#include "Turquoise.h"

Deck::Deck(istream & in, const CardFactory * cardFactory)
{
	int numCards = 0;
	//1. Num cards
	in >> numCards;
	//2. Cards
	for (int i = 0; i < numCards; ++i)
	{
		string cardType;
		in >> cardType;
		m_cards.push_back(cardFactory->getCard(cardType));
	}

}

Deck Deck::randomizedDeck(CardFactory * cardFactory)
{
	Deck deck;
	srand(time(NULL));

	const int numCardTypes = 8;

	int cardCounts[numCardTypes] =
	{
		8,	/* 0: Amethyst  */
		6,	/* 1: Emerald   */
		18, /* 2: Hematite  */
		14, /* 3: Malachite */
		16, /* 4: Obsidian  */
		20, /* 5: Quartz    */
		12, /* 6: Turquoise */
		10	/* 7: Ruby      */
	};

	int numCards = 0;

	for (int i = 0; i < numCardTypes; ++i)
	{
		numCards += cardCounts[i];
	}

	for (int i = 0; i < numCards; ++i)
	{
		int index = 0;

		while (!(cardCounts[index] > 0))
		{
			index = (index + 1) % numCardTypes; //Linear probing to find non-zero card count;
		}

		switch (index)
		{
		case 0: /* 0: Amethyst  */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Amethyst::TYPE));
			break;
		case 1: /* 1: Emerald   */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Emerald::TYPE));
			break;
		case 2: /* 2: Hematite  */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Hematite::TYPE));
			break;
		case 3: /* 3: Malachite */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Malachite::TYPE));
			break;
		case 4: /* 4: Obsidian  */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Obsidian::TYPE));
			break;
		case 5: /* 5: Quartz    */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Quartz::TYPE));
			break;
		case 6: /* 6: Turquoise */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Turquoise::TYPE));
			break;
		case 7: /* 7: Ruby      */
			deck.m_cards.insert(deck.m_cards.end(), cardFactory->getCard(Ruby::TYPE));
			break;
		}

		--cardCounts[index];
	}

	std::shuffle(deck.m_cards.begin(), deck.m_cards.end(), std::default_random_engine(time(NULL)));

	return deck;
}

bool Deck::isEmpty()
{
	return m_cards.size() == 0;
}

Card * Deck::draw()
{
	//Review this.
	Card * card = m_cards.back();
	m_cards.pop_back();
	return card;
}

void Deck::print(ostream & out) const
{
	//1. Num cards
	out << m_cards.size();
	out << " ";
	//2. Cards
	for (Card * card : m_cards)
	{
		out << card->getName();
		out << " ";
	}

	out << endl;
}

ostream & operator<<(ostream & out, const Deck & deck)
{
	for (auto card : deck.m_cards)
	{
		out << (*card) << " ";
	}

	return out;
}
