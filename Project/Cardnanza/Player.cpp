#include "Player.h"

Player::Player(const string & name) : m_name{ name }, m_coins{ 0 }, m_maxChains{ STARTING_CHAINS }, m_chains{}, m_hand{}
{
}

Player::Player(istream & in, const CardFactory * cardFactory)
{
	int numChains = 0;

	//1. Name
	in >> m_name;
	//2. Coins
	in >> m_coins;
	//3. Hand
	m_hand = Hand(in, cardFactory);
	//4. Num max chains
	in >> m_maxChains;
	//5. Num chains
	in >> numChains;
	//6. Chains
	for (int i = 0; i < numChains; ++i)
	{
		m_chains.emplace_back(in, cardFactory);
	}
}

string Player::getName() const
{
	return m_name;
}

int Player::getNumCoins() const
{
	return m_coins;
}

int Player::getMaxNumChains() const
{
	return m_maxChains;
}

int Player::getNumChains() const
{
	return m_chains.size();
}

int Player::getNumCards() const
{
	return m_hand.size();
}

void Player::buyThirdChain()
{
	if (m_maxChains < MAX_CHAINS)
	{
		if (m_coins >= CHAIN_COST)
		{
			m_coins -= CHAIN_COST;
			++m_maxChains;
		}
		else
		{
			throw "NotEnoughCoins";
		}
	}
}

bool Player::canBuyExtraChain() const
{
	return m_maxChains < MAX_CHAINS && getNumCoins() >= CHAIN_COST;
}

Card * Player::showTopCard()
{
	return m_hand.top();
}

Card * Player::playTopCard()
{
	return m_hand.play();
}

Card * Player::discardCardAtPosition(int index)
{
	if (index >= 0 || index < m_hand.size())
	{
		return m_hand[index];
	}
	else
	{
		return nullptr;
	}
}

Chain<Card*> * Player::createChain(Card * card)
{
	if (m_chains.size() < m_maxChains)
	{
		m_chains.emplace_back(card);
		return &m_chains[m_chains.size() - 1];
	}
	else
	{
		return nullptr;
	}
}

int Player::sellChain(int chainIndex)
{
	int coins = m_chains[chainIndex].sell();
	m_coins += coins;
	m_chains.erase(m_chains.begin() + chainIndex);
	return coins;
}

void Player::printHand(ostream & out, bool showAllCards) const
{
	out << m_hand;
}

void Player::print(ostream & out) const
{
	//1. Name
	out << m_name;
	out << " ";
	//2. Coins
	out << m_coins;
	out << " ";
	//3. Hand
	m_hand.print(out);
	//4. Num max chains
	out << m_maxChains;
	out << " ";
	//5. Num chains
	out << m_chains.size();
	out << " ";
	//6. Chains
	for (Chain<Card *> chain : m_chains)
	{
		chain.print(out);
	}

	out << endl;
}

Chain<Card *> & Player::operator[](int i)
{
	return m_chains[i];
}

Player & Player::operator+=(int numCoins)
{
	if (numCoins > 0)
	{
		m_coins += numCoins;
	}

	return *this;
}

Player & Player::operator+=(Card * card)
{
	m_hand += card;
	return *this;
}

ostream & operator<<(ostream & out, const Player & player)
{
	out << player.m_name << "\t";
	out << player.m_coins << " coins" << endl;

	for (const Chain<Card*> & chain : player.m_chains)
	{
		out << chain;
	}

	return out;
}
