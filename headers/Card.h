#ifndef CARD
#define CARD
#include "Body.h"

const int cardNameMax = 65;

class Card : public Body {
private:
	std::string color;

private:
	bool valid(const std::string& color) const;
public:
	Card();
	Card(const char* name, const char* color);
	Card(const Card& other);
	Card& operator=(const Card& other);

	std::string getColor() const;

	void setColor(const char* color);

	void print() const; 
	void read();

	friend std::ostream& operator<<(std::ostream& os, const Card& card);
	friend std::istream& operator>>(std::istream& is, Card& card);
};
#endif

