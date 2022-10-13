#include "System.h"

void System::savePlayers(Database& database)
{
	std::ofstream file;
	file.open("players.txt");
	if (!file) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	int size = database.getPlayerSize();
	for (int i = 0; i < size; ++i) {
		file << database.getPlayer(i);
	}
}

void System::saveCards(Database& database)
{
	std::ofstream file;
	file.open("cards.txt");
	if (!file) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	int size = database.getCardSize();
	for (int i = 0; i < size; ++i) {
		file << database.getCard(i);
	}
}

void System::saveDecks(Database& database)
{
	std::ofstream file;
	file.open("decks.txt");
	if (!file) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	int size = database.getDeckSize();
	for (int i = 0; i < size; ++i) {
		file << database.getDeck(i);
	}
}

void System::loadPlayers(Database& database)
{
	std::ifstream file;
	file.open("players.txt");
	if (!file) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	int size = database.getPlayerSize();
	for (int i = 0; i < size; ++i) {
		Player temp;
		file >> temp;
		database.addPlayer(temp);
	}
}

void System::loadCards(Database& database)
{
	std::ifstream file;
	file.open("cards.txt");
	if (!file) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	int size = database.getCardSize();
	for (int i = 0; i < size; ++i) {
		Card temp;
		file >> temp;
		database.addCard(temp);
	}
}

void System::loadDecks(Database& database)
{
	std::ifstream file;
	file.open("decks.txt");
	if (!file) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	int size = database.getDeckSize();
	for (int i = 0; i < size; ++i) {
		Deck temp;
		file >> temp;
		database.addDeck(temp);
	}
}

void System::load(Database& database)
{
	this->loadPlayers(database);
	this->loadCards(database);
	this->loadDecks(database);
}

void System::save(Database& database)
{
	this->savePlayers(database);
	this->saveCards(database);
	this->saveDecks(database);
}

void System::report(Database& database)
{
	std::ofstream file;
	file.open("report.txt");
	//if !file

	file << "Black" << std::endl;
	int deckSize = database.getDeckSize();
	for (int i = 0; i < deckSize; ++i) {
		if (database.getDeck(i).getColor() == "Black") {
			Player tempPlayer;
			tempPlayer = database.getPlayerById(database.getDeck(i).getPlayerId());
			Card tempCard = database.getDeck(i).getMostMetCard();
			file << "Owner: " << tempPlayer.getName() << " Card: " << tempCard.getName() << " Color: " << tempCard.getColor() << std::endl;
		}
	}

	file << "Red" << std::endl;
	for (int i = 0; i < deckSize; ++i) {
		if (database.getDeck(i).getColor() == "Red") {
			Player tempPlayer;
			tempPlayer = database.getPlayerById(database.getDeck(i).getPlayerId());
			Card tempCard = database.getDeck(i).getMostMetCard();
			file << "Owner: " << tempPlayer.getName() << " Card: " << tempCard.getName() << " Color: " << tempCard.getColor() << std::endl;
		}
	}

	file << "Blue" << std::endl;
	for (int i = 0; i < deckSize; ++i) {
		if (database.getDeck(i).getColor() == "Blue") {
			Player tempPlayer;
			tempPlayer = database.getPlayerById(database.getDeck(i).getPlayerId());
			Card tempCard = database.getDeck(i).getMostMetCard();
			file << "Owner: " << tempPlayer.getName() << " Card: " << tempCard.getName() << " Color: " << tempCard.getColor() << std::endl;
		}
	}

	file << "White" << std::endl;
	for (int i = 0; i < deckSize; ++i) {
		if (database.getDeck(i).getColor() == "White") {
			Player tempPlayer;
			tempPlayer = database.getPlayerById(database.getDeck(i).getPlayerId());
			Card tempCard = database.getDeck(i).getMostMetCard();
			file << "Owner: " << tempPlayer.getName() << " Card: " << tempCard.getName() << " Color: " << tempCard.getColor() << std::endl;
		}
	}

	file << "Green" << std::endl;
	for (int i = 0; i < deckSize; ++i) {
		if (database.getDeck(i).getColor() == "Green") {
			Player tempPlayer;
			tempPlayer = database.getPlayerById(database.getDeck(i).getPlayerId());
			Card tempCard = database.getDeck(i).getMostMetCard();
			file << "Owner: " << tempPlayer.getName() << " Card: " << tempCard.getName() << " Color: " << tempCard.getColor() << std::endl;
		}
	}
}
