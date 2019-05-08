#include "DiscardPile.h"

#include "CardFactory.h"

ostream & operator<<(ostream & out, const Card & card);

ostream & operator<<(ostream & out, const DiscardPile & discardPile)
{
	if (discardPile.m_cards.size() > 0)
	{
		for (Card * card : discardPile.m_cards)
		{
			out << (*card) << " ";
		}
	}
	else
	{
		out << "No cards in discard pile." << endl;
	}

	return out;
}


DiscardPile::DiscardPile(istream & in, const CardFactory * cardFactory)
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

Card * DiscardPile::pickUp()
{
	Card * topCard = m_cards.back();
	m_cards.pop_back();
	return topCard;
}


Card * DiscardPile::top() const
{
	if (m_cards.size() > 0)
	{
		Card * topCard = m_cards.back();
		return topCard;
	}
	else
	{
		return nullptr;
	}

}

void DiscardPile::print(std::ostream & out) const
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

bool DiscardPile::isEmpty() const
{
	return m_cards.size() > 0;
}

DiscardPile & DiscardPile::operator+=(Card * card)
{
	if (card != nullptr)
	{
		m_cards.push_back(card);
	}
	return *this;
}


