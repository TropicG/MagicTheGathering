#ifndef INPUTFUNCTIONS
#define INPUTFUNCTIONS
#include <string>
#include <iostream>
using namespace std;

void printMenu() {

	cout << "cc - create card" << endl;
	cout << "cp - create player" << endl;
	cout << "cd - create deck" << endl;
	cout << "report - and program and see txt file report" << endl;
	cout << "end - save file end exit program" << endl;
	cout << endl;
}

bool validCommand(std::string& command) {
	return command == "cc" || command == "cd" || command == "cp" || command == "report" || command == "end";
}

void inputCommand(std::string& command) {

	cout << "Enter your command: ";
	if (cin.peek() == '\n') cin.ignore();
	cin >> command;
	while (!validCommand(command)) {
		cout << "Invalid command try again: ";
		command.clear();
		cin >> command;
	}
}

void inputPlayerName(char* name) {

	cout << "Enter the player's name: ";
	if (cin.peek() == '\n') cin.ignore();
	cin.getline(name, nameMax, '\n');
	bool failed = cin.fail();
	if (failed) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
#endif
