#ifndef DECK
#define DECK
#include "Player.h"
#include "Card.h"
#include <vector>

const int deckSize = 60;

class Deck {
private:
	unsigned playerID = 0;
	std::string color;
	std::vector<Card*> cards;

private:
	void clearCards();
	int getMax(const int& red, const int& black, const int& white, const int& green, const int& blue) const;

public:
	Deck();
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();

	void addCard(const Card& card);

	Card getMostMetCard() const;
	void setDeckColor();

	Card& operator[](const unsigned& index) const;
	Card operator[](const unsigned& index);
	unsigned getPlayerId() const;
	std::string getColor() const;

	void setPlayerId(const unsigned& id);
	void setColor(const std::string& color);

	void print() const;

	friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
	friend std::istream& operator>>(std::istream& is, Deck& deck);
};
#endif
