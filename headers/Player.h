#ifndef PLAYER
#define PLAYER
#include "Body.h"

const int nameMax = 127;

class Player : public Body {
public:
	Player();
	Player(const char* name);
	Player(const Player& other);
	Player& operator=(const Player& other);

	void print() const;
	void read();

	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	friend std::istream& operator>>(std::istream& is, Player& player);
};
#endif

