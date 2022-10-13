#include "Player.h"

Player::Player() : Body()
{
}

Player::Player(const char* name) : Body(name)
{
}

Player::Player(const Player& other) : Body(other)
{
}

Player& Player::operator=(const Player& other)
{
	if (this != &other) {

		Body::operator=(other);
	}

	return *this;
}

void Player::print() const
{
	Body::print();
	std::cout << std::endl;
}

void Player::read()
{
	char name[nameMax];
	std::cout << "Enter the name of the player: ";
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::cin.getline(name, nameMax, '\n');
	bool failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->setName(name);

	this->generateId();
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	os << player.name << "|" << player.id << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Player& player)
{
	char name[nameMax];
	if (is.peek() == '\n') is.ignore();
	is.getline(name, nameMax, '|');
	player.setName(name);

	is >> player.id;

	return is;
}
