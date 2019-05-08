#include "Hand.h"

Hand::Hand(istream & in, const CardFactory * cardFactory)
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

Card * Hand::play()
{
	Card * card = top();

	if (card != nullptr)
	{
		m_cards.erase(m_cards.begin());
	}

	return card;
}

Card * Hand::top()
{
	if (m_cards.size() > 0)
	{
		return m_cards[0];
	}
	else
	{
		return nullptr;
	}
}

int Hand::size() const
{
	return m_cards.size();
}

Hand & Hand::operator+=(Card * card)
{
	m_cards.push_back(card);
	return *this;
}

Card * Hand::operator[](int i)
{
	if ( i >= 0 && i < m_cards.size())
	{
		Card * card = m_cards[i];
		m_cards.erase(m_cards.cbegin() + i);
		return card;
	}
	else
	{
		return nullptr;
	}
}

void Hand::print(ostream & out) const
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
}

ostream & operator<<(ostream & out, const Hand & hand)
{
	for (Card * card : hand.m_cards)
	{
		out << (*card) << " ";
	}

	out << endl;

	return out;
}
