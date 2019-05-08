#include "Header.h"

void User_Input::get_Response(My_Character& Ch, My_Interface& I) {
	char c = _getch();
	switch (c)
	{
	case 'w': Ch.up_Response(I);
		break;
	case 'a': Ch.left_Response(I);
		break;
	case 'd': Ch.right_Response(I);
		break;
	case 's': Ch.down_Response(I);
		break;
	default:
		get_Response(Ch, I);
		//Call itself again
	}

	moves--;

}

void User_Input::start_Guide() {
	cout << "Press e to start!" << endl;
	cout << "Press q if you want help!" << endl;
	char c = _getch();
	switch (c)
	{
	case 'e':
		break;
	case 'q':
		cout << "/////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << " Press w a s d to move." << endl;
		cout << " Move in each direction would have a specific pattern" << endl;
		cout << " Up: * , left: &, right: +, down: O" << endl;
		cout << " You need to reach the enemy with the specific pattern" << endl;
		cout << " * against . ; $ against & ; + against -; O against X " << endl;
		cout << " In order to win the game, you need to:" << endl;
		cout << " *Low Level : Gain 5 points in 50 moves" << endl;
		cout << " *Mid Level : Gain 10 points in 80 moves" << endl;
		cout << " *High Level : Gain 15 points in 100 moves" << endl;
		cout << "/////////////////////////////////////////////////////////////////////////////////" << endl;
		start_Guide();
		break;
	default:
		start_Guide();

	}
}

int User_Input::level_Selection() {
	cout << "Press 1 for Low Level, 2 for Mid Level, 3 for High Level" << endl;
	char c = _getch();
	switch (c) {
	case '1':
		return 5;
	case '2':
		return 10;
	case '3':
		return 15;
	default:
		level_Selection();
	}
}