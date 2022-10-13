#include "Deck.h"

void Deck::clearCards()
{
}

int Deck::getMax(const int& red, const int& black, const int& white, const int& green, const int& blue) const
{
	return 0;
}

Deck::Deck()
{
}

Deck::Deck(const Deck& other)
{
	this->setColor(other.getColor().c_str());
	this->setPlayerId(other.getPlayerId());
	for (int i = 0; i < deckSize; ++i) {
		this->cards.push_back(new Card(other[i]));
	}
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other) {

		this->clearCards();

		this->setColor(other.getColor().c_str());
		this->setPlayerId(other.getPlayerId());
		for (int i = 0; i < deckSize; ++i) {
			this->cards.push_back(new Card(other[i]));
		}
	}

	return *this;
}

Deck::~Deck()
{
	this->clearCards();
}

void Deck::addCard(const Card& card)
{
	this->cards.push_back(new Card(card));
}

Card Deck::getMostMetCard() const
{
	int maxCount = 0, currentCount = 0, size = this->cards.size();
	Card maxCard, currentCard;
	for (int i = 0; i < size; ++i) {

		currentCard = *this->cards[i];
		for (int j = 0; j < size; ++j) {

			if (this->cards[i]->getName() == this->cards[j]->getName()) {
				currentCount++;
			}
		}

		if (currentCount > maxCount) {
			maxCount = currentCount;
			maxCard = currentCard;
		}

		currentCount = 0;
	}

	return maxCard;
}

void Deck::setDeckColor()
{
	int red = 0, black = 0, green = 0, blue = 0, white = 0;
	for (int i = 0; i < deckSize; ++i) {
		if (this->cards[i]->getColor() == "Red") {
			red++;
		}
		else if (this->cards[i]->getColor() == "Black") {
			black++;
		}
		else if (this->cards[i]->getColor() == "Green") {
			green++;
		}
		else if (this->cards[i]->getColor() == "Blue") {
			blue++;
		}
		else {
			white++;
		}
	}

	if (getMax(red, black, white, green, blue) == red) {
		this->setColor("Red");
	}
	else if (getMax(red, black, white, green, blue) == black) {
		this->setColor("Black");
	}
	else if (getMax(red, black, white, green, blue) == white) {
		this->setColor("White");
	}
	else if (getMax(red, black, white, green, blue) == green) {
		this->setColor("Green");
	}
	else {
		this->setColor("Blue");
	}
}

Card& Deck::operator[](const unsigned& index) const
{
	return *this->cards[index];
}

Card Deck::operator[](const unsigned& index)
{
	return *this->cards[index];
}

unsigned Deck::getPlayerId() const
{
	return this->playerID;
}

std::string Deck::getColor() const
{
	return this->color;
}

void Deck::setPlayerId(const unsigned& id)
{
	this->playerID = id;
}

void Deck::setColor(const std::string& color)
{
	this->color = color;
}

void Deck::print() const
{
	std::cout << "Player's id: " << this->playerID << ", Color: " << this->color << std::endl;
	for (int i = 0; i < deckSize; ++i) {
		this->cards[i]->print();
	}
}

std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	os << deck.playerID << " " << deck.color << std::endl;
	for (int i = 0; i < deckSize; ++i) {
		os << deck[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, Deck& deck)
{
	is >> deck.playerID >> deck.color;
	for (int i = 0; i < deckSize; ++i) {
		Card temp;
		is >> temp;
		deck.cards.push_back(new Card(temp));
	}

	return is;
}
