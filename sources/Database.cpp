#include "Database.h"

void Database::clearPlayers()
{
	int size = this->players.size();
	for (int i = 0; i < size; ++i) {
		delete this->players[i];
	}
}

void Database::clearCards()
{
	int size = this->cards.size();
	for (int i = 0; i < size; ++i) {
		delete this->cards[i];
	}
}

void Database::clearDecks()
{
	int size = this->decks.size();
	for (int i = 0; i < size; ++i) {
		delete this->decks[i];
	}
}

Database::Database()
{
}

Database::~Database()
{
	this->clearPlayers();
	this->clearCards();
	this->clearDecks();
}

void Database::addPlayer(const Player& player)
{
	this->players.push_back(new Player(player));
}

bool Database::dublicatePlayerId(const Player& player) const
{
	int size = this->players.size();
	for (int i = 0; i < size; ++i) {
		if (this->getPlayer(i).getId() == player.getId()) {
			return true;
		}
	}

	return false;
}

bool Database::insidePlayer(const std::string& name) const
{
	int size = this->players.size();
	for (int i = 0; i < size; ++i) {
		if (this->players[i]->getName() == name) {
			return true;
		}
	}
	
	return false;
}

int Database::getPlayerSize() const
{
	return this->players.size();
}

Player& Database::getPlayer(const unsigned& index) const
{
	return *this->players[index];
}

Player& Database::getPlayerByName(const std::string& name) const
{
	int size = this->players.size();
	for (int i = 0; i < size; ++i) {
		if (this->players[i]->getName() == name) {
			return *this->players[i];
		}
	}
}

Player& Database::getPlayerById(const unsigned id) const
{
	int size = this->getPlayerSize();
	for (int i = 0; i < size; ++i) {
		if (this->getPlayer(i).getId() == id) {
			return this->getPlayer(i);
		}
	}
}

void Database::addCard(const Card& card)
{
	this->cards.push_back(new Card(card));
}

bool Database::dublicateCardId(const Card& card) const
{
	int size = this->cards.size();
	for (int i = 0; i < size; ++i) {
		if (this->getCard(i).getId() == card.getId()) {
			return true;
		}
	}

	return false;
}

bool Database::insideCard(const std::string& name) const
{
	int size = this->cards.size();
	for (int i = 0; i < size; ++i) {
		if (this->cards[i]->getName() == name) {
			return true;
		}
	}

	return false;
}

int Database::getRedDeckCount() const
{
	int count = 0, size = this->decks.size();
	for (int i = 0; i < size; ++i) {
		if (this->getDeck(i).getColor() == "Red") {
			count++;
		}
	}

	return count;
}

int Database::getBlackDeckCount() const
{
	int count = 0, size = this->decks.size();
	for (int i = 0; i < size; ++i) {
		if (this->getDeck(i).getColor() == "Black") {
			count++;
		}
	}

	return count;
}

int Database::getWhiteDeckCount() const
{
	int count = 0, size = this->decks.size();
	for (int i = 0; i < size; ++i) {
		if (this->getDeck(i).getColor() == "White") {
			count++;
		}
	}

	return count;
}

int Database::getGreenDeckCount() const
{
	int count = 0, size = this->decks.size();
	for (int i = 0; i < size; ++i) {
		if (this->getDeck(i).getColor() == "Green") {
			count++;
		}
	}

	return count;
}

int Database::getBlueDeckCount() const
{
	int count = 0, size = this->decks.size();
	for (int i = 0; i < size; ++i) {
		if (this->getDeck(i).getColor() == "Blue") {
			count++;
		}
	}

	return count;
}

int Database::getCardSize() const
{
	return this->cards.size();
}

Card& Database::getCard(const unsigned& index) const
{
	return *this->cards[index];
}

void Database::addDeck(const Deck& deck)
{
	this->decks.push_back(new Deck(deck));
}

int Database::getDeckSize() const
{
	return this->decks.size();
}

Deck& Database::getDeck(const unsigned& index) const
{
	return *this->decks[index];
}
