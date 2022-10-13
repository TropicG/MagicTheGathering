#ifndef DATABASE
#define DATABASE
#include "Player.h"
#include "Card.h"
#include "Deck.h"

class Database {
private:
	std::vector<Player*> players;
	std::vector<Card*> cards;
	std::vector<Deck*> decks;

private:
	void clearPlayers();
	void clearCards();
	void clearDecks();

public:
	Database();
	~Database();

	void addPlayer(const Player& player);
	void addCard(const Card& card);
	void addDeck(const Deck& deck);

	Player& getPlayerByName(const std::string& name) const;
	Player& getPlayerById(const unsigned id) const;

	Player& getPlayer(const unsigned& index) const;
	Card& getCard(const unsigned& index) const;
	Deck& getDeck(const unsigned& index) const;

	bool dublicatePlayerId(const Player& player) const;
	bool dublicateCardId(const Card& card) const;

	bool insidePlayer(const std::string& name) const;
	bool insideCard(const std::string& name) const;

	int getRedDeckCount() const;
	int getBlackDeckCount() const;
	int getWhiteDeckCount() const;
	int getGreenDeckCount() const;
	int getBlueDeckCount() const;

	int getPlayerSize() const;
	int getCardSize() const;
	int getDeckSize() const;
};
#endif