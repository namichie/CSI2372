#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <vector>
#include <exception>
#include "Card.h"

#include "CardFactory.h"


using namespace std;

class CardFactory;

template <class T> class Chain { //: public Chain_Base {

public:
	//typedef T value_type;s

	Chain() = default;
	Chain(T firstElem);
	Chain(istream & in, const CardFactory * cardFactory);

	bool isEmpty();
	T getFirst();
	int getChainSize();

	int sell();
	Chain<T> & operator+=(T elem);

	void print(ostream & out) const;

	template <class T>
	friend ostream & operator<<(ostream & out, const Chain<T> & chain)
	{
		
		if (chain.m_chain.size() > 0)
		{
			const T elem = chain.m_chain[0];
			Card * card = dynamic_cast<Card *>(elem);

			if (card != nullptr)
			{
				out << card->getName() << ": ";

				for (size_t i = 0; i < chain.m_chain.size(); ++i)
				{
					card->print(out);

					out << " ";
				}
			}

			out << endl;
		}

		return out;
	} 

private:
	vector<T> m_chain;
};
#endif // ! CHAIN_H

template<class T>
Chain<T>::Chain(T firstElem)
{
	m_chain.push_back(firstElem);
}

template <class T>
Chain<T>::Chain(istream & in, const CardFactory * cardFactory)
{
	int numCards = 0;
	//1. Num cards
	in >> numCards;
	//2. Cards
	for (int i = 0; i < numCards; ++i)
	{
		string cardType;
		in >> cardType;
		m_chain.push_back(cardFactory->getCard(cardType));
	}
}

template <class T>
int Chain<T>::sell() {
	int numOfCards = m_chain.size();
	return m_chain[0]->getCoinsPerCards(numOfCards);
}

template<class T>
T Chain<T>::getFirst() {
	return m_chain[0];
}

template<class T>
int Chain<T>::getChainSize() {
	return m_chain.size();
}

template<class T>
bool Chain<T>::isEmpty() 
{
	return m_chain.empty();
}

template <class T>
Chain<T> & Chain<T>::operator+=(T elem)
{
	if (m_chain.size() > 0)
	{
		Card * card = dynamic_cast<Card *>(elem);
		T frontElem = getFirst();
		Card * firstCard = dynamic_cast<Card *>(frontElem);

		if (card->getName().compare(firstCard->getName()) != 0)
		{
			throw new IllegalType();
		}

	}

	m_chain.push_back(elem);
	return *this;
}

template<class T>
void Chain<T>::print(ostream & out) const
{
	//1. Num cards
	out << m_chain.size();
	out << " ";
	//2. Cards
	for (Card * card : m_chain)
	{
		out << card->getName();
		out << " ";
	}
}

// Exception class
class IllegalType : public exception {
	const char * what() const throw() {
		return "Cards don't match.";
	}
};


