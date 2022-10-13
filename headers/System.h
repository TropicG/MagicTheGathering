#ifndef SYSTEM
#define SYSTEM
#include "Database.h"
#include <fstream>

class System {
private:
	void savePlayers(Database& database);
	void saveCards(Database& database);
	void saveDecks(Database& database);

	void loadPlayers(Database& database);
	void loadCards(Database& database);
	void loadDecks(Database& database);

public:
	void load(Database& database);
	void save(Database& database);

	void report(Database& database);
};
#endif 