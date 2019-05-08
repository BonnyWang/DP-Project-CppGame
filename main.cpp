
#include "Header.h"

int main()
{
	using namespace std::chrono;

	do {
		My_Interface interface;
		My_Character character;
		My_Enemy enemy;
		User_Input user1;
		interface.initalize();
		interface.print();
		character.print_Me(interface);
		user1.start_Guide();
		int level = user1.level_Selection();
		switch (level)
		{
			case 5:
				user1.moves = 50;
				break;
			case 10:
				user1.moves = 80;
				break;
			case 15:
				user1.moves = 100;
				break;
		}

		enemy.generate(interface);
		while (user1.moves > 0 && enemy.score < level) {
			user1.get_Response(character, interface);
			enemy.check(interface);
			cout << "Your Score is " << enemy.score << endl;
			cout << "Moves you left " << user1.moves << endl;
		}

		if (enemy.score == level) {
			interface.win_Pattern();
			cout << "You win!" << endl;
			cout << "Would you like to try again? Press e to play agian?" << endl;
		}
		else {
			cout << "You lose! Would you like to try again? Press e to play agian?" << endl;
		}
	} while (_getch() == 'e');
	
	cout << "Have a Nice Day!" << endl;

	return 0;
}