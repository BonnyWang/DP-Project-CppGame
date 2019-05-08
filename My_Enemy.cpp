
#include "Header.h"

void My_Enemy::generate(My_Interface& I) {


	while (1) {
		coord[0] = 1 + (std::rand() % (7 - 0 + 1));
		coord[1] = 1 + (std::rand() % (7 - 0 + 1));
		which = 0 + (std::rand() % (3 - 0 + 1));
		if (I.board[coord[0]][coord[1]] == "  ") {
			I.board[coord[0]][coord[1]] = appearance[which];
			break;
		}
	}

	I.update();

}

int My_Enemy::check(My_Interface& I) {
	if (which == 0 && (I.board[coord[0]][coord[1]] == " O" || I.board[coord[0]][coord[1]] == " o")) {
		score++;
		generate(I);
	}
	if (which == 1 && (I.board[coord[0]][coord[1]] == " &")) {
		score++;
		generate(I);
	}
	else if (which == 2 && (I.board[coord[0]][coord[1]] == " +")) {
		score++;
		generate(I);
	}
	else if (which == 3 && (I.board[coord[0]][coord[1]] == "* ")) {
		score++;
		generate(I);
	}
	else if (I.board[coord[0]][coord[1]] == "  ") {
		I.board[coord[0]][coord[1]] = appearance[which];
		I.update();

	}
	else if (I.board[coord[0]][coord[1]] == appearance[which]) {
	}
	else {
		generate(I);
	}
	return 1;
}