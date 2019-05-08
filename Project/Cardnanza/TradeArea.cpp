#include "TradeArea.h"

#include "CardFactory.h"

//TODO
TradeArea::TradeArea(istream & in, const CardFactory * cardFactory)
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


TradeArea & TradeArea::operator+=(Card * card)
{
	if (card != nullptr)
	{
		m_cards.push_back(card);
	}

	return *this;
}


bool TradeArea::legal(Card * card) const
{
	if (card != nullptr)
	{
		for (const Card * m_card : m_cards)
		{
			if (card->getName().compare(m_card->getName()) == 0)
			{
				return true;
			}
		}
	}

	return false;
}


Card * TradeArea::trade(string cardType)
{
	for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter) 
	{
		if ((*iter)->getName() == cardType) 
		{
			Card * card = *iter;
			m_cards.erase(iter);
			return card;
		}
	}

	return 0;
}

void TradeArea::print(ostream & out) const
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


int TradeArea::getNumCards() const
{
	return m_cards.size();
}


ostream & operator<<(ostream & out, const TradeArea & tradeArea)
{

	for (auto card : tradeArea.m_cards) {
		out << *card << " ";
	}

	return out;
}


