#include "Header.h"

void My_Character::print_Me(My_Interface& I) {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	//Starter Animation
	for (int k = 0; k < 2; k++) {
		for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
			for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
				I.board[i][j] = appearance_S[i - 4][j - 4];
			}
		}

		I.update();

		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + nanoseconds(200000000));

		for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
			for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
				I.board[i][j] = appearance_B[i - 4][j - 4];
			}
		}

		I.update();
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + nanoseconds(200000000));

		for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
			for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
				I.board[i][j] = appearance_C[i - 4][j - 4];
			}
		}

		I.update();
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + nanoseconds(200000000));
	}

	string welcome[] = { "We", "lc","om", "e!" };

	int j = 0;
	for (int i = 3; i < 7; i++) {
		I.board[7][i] = welcome[j];
		j++;
		I.update();
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + nanoseconds(200000000));
	}

	//clear welcome
	for (int i = 3; i < 7; i++) {
		I.board[7][i] = "  ";
		j++;
		I.update();
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + nanoseconds(200000000));
	}

}

void My_Character::up_Response(My_Interface & I) {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	clear_Me(I);
	if (coordinate[0] > 0 &&
		coordinate[0] <= 9 &&
		coordinate[1] >= 0 &&
		coordinate[1] <= 9) {

		coordinate[0]--;
	}

	int a = 0;
	int b = 0;

	for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
		for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
			I.board[i][j] = appearance_N[a][b];
			b++;
		}
		b = 0;
		a++;
	}

	I.update();
}

void My_Character::left_Response(My_Interface & I) {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	clear_Me(I);
	if (coordinate[0] >= 0 &&
		coordinate[0] <= 9 &&
		coordinate[1] > 0 &&
		coordinate[1] <= 9) {

		coordinate[1]--;
	}

	int a = 0;
	int b = 0;

	for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
		for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
			I.board[i][j] = appearance_A[a][b];
			b++;
		}
		b = 0;
		a++;
	}

	I.update();
}

void My_Character::right_Response(My_Interface & I) {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	clear_Me(I);

	if (coordinate[0] >= 0 &&
		coordinate[0] <= 9 &&
		coordinate[1] >= 0 &&
		coordinate[1] < 7) {

		coordinate[1]++;
	}

	int a = 0;
	int b = 0;

	for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
		for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
			I.board[i][j] = appearance_R[a][b];
			b++;
		}
		b = 0;
		a++;
	}

	I.update();
}

void My_Character::down_Response(My_Interface & I) {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	clear_Me(I);

	if (coordinate[0] >= 0 &&
		coordinate[0] < 7 &&
		coordinate[1] >= 0 &&
		coordinate[1] <= 9) {

		coordinate[0]++;
	}

	int a = 0;
	int b = 0;

	for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
		for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
			I.board[i][j] = appearance_F[a][b];
			b++;
		}
		b = 0;
		a++;
	}


	I.update();

}

void My_Character::clear_Me(My_Interface & I) {
	for (int i = coordinate[0]; i < (coordinate[0]) + 3; i++) {
		for (int j = coordinate[1]; j < (coordinate[1]) + 3; j++) {
			I.board[i][j] = "  ";
		}
	}

}