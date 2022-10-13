#include "System.h"
#include "inputFunctions.h"
using namespace std;

int main() {

	System system;
	Database database;

	system.load(database);

	string command;

	printMenu();
	while (true) {

		inputCommand(command);

		if (command == "cc") {

			Card temp;
			temp.read();
			while (database.dublicateCardId(temp)) {
				temp.generateId();
			}
			database.addCard(temp);
			cout << "Succsesfully added card" << endl << endl;
		}
		else if (command == "cp") {

			Player temp;
			temp.read();
			while (database.dublicatePlayerId(temp)) {
				temp.generateId();
			}
			database.addPlayer(temp);
			cout << "Succsesfully added player" << endl << endl;
		}
		else if (command == "cd") {

			Deck deck;

			char name[nameMax];
			inputPlayerName(name);
			while (!database.insidePlayer(name)) {
				std::cout << "There is no such name in our database, try again: ";
				inputPlayerName(name);
			}

			Player player = database.getPlayerByName(name);
			deck.setPlayerId(player.getId());

			for (int i = 0; i < deckSize; ++i) {

				Card temp;
				temp.read();
				while (!database.insideCard(temp.getName())) {
					std::cout << "There is no such name in our database, try again ";
					temp.read();
				}
				deck.addCard(temp);
			}

			deck.setDeckColor();
			database.addDeck(deck);
			cout << "Succsesfully added deck" << endl << endl;
		}
		else if (command == "report") {
			system.report(database);
			system.save(database);
			break;
		}
		else{
			system.save(database);
			break;
		}

	}
	
	return 0;
}