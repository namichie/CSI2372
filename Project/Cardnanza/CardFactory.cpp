#include "CardFactory.h"

#include "Amethyst.h"
#include "Emerald.h"
#include "Hematite.h"
#include "Malachite.h"
#include "Obsidian.h"
#include "Quartz.h"
#include "Ruby.h"
#include "Turquoise.h"

CardFactory * CardFactory::m_cardFactory;

CardFactory::CardFactory()
{
	cards[Amethyst::TYPE] = new Amethyst();
	cards[Emerald::TYPE] = new Emerald();
	cards[Hematite::TYPE] = new Hematite();
	cards[Malachite::TYPE] = new Malachite();
	cards[Obsidian::TYPE] = new Obsidian();
	cards[Ruby::TYPE] = new Ruby();
	cards[Quartz::TYPE] = new Quartz();
	cards[Turquoise::TYPE] = new Turquoise();
}

CardFactory * CardFactory::getFactory()
{
	if (m_cardFactory == nullptr)
	{
		m_cardFactory = new CardFactory();
	}

	return m_cardFactory;
}

Deck CardFactory::getDeck()
{
	return Deck::randomizedDeck(this);
}

CardFactory::~CardFactory()
{
	delete cards[Amethyst::TYPE];
	delete cards[Emerald::TYPE];
	delete cards[Hematite::TYPE];
	delete cards[Malachite::TYPE];
	delete cards[Obsidian::TYPE];
	delete cards[Ruby::TYPE];
	delete cards[Quartz::TYPE];
	delete cards[Turquoise::TYPE] ;
}

Card * CardFactory::getCard(string type) const
{
	return (*cards.find(type)).second;
}

