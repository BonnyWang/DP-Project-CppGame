#include "Header.h"

//print a lots of empty lines to clear the terminal
void My_Interface::clearScreen() {
	for (int i = 0; i < 100; i++) {
		cout << " " << endl;
	}
}

void My_Interface::initalize() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = "  ";
		}
	}

}

void My_Interface::print() {
	cout << "----------------------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "|";
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << "|" << endl;
	}
	cout << "----------------------" << endl;
}

void My_Interface::update() {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	clearScreen();
	print();

	sleep_for(nanoseconds(10));
	sleep_until(system_clock::now() + nanoseconds(150000000));

}

void My_Interface::win_Pattern() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = ":)";
		}
	}
	update();
}

