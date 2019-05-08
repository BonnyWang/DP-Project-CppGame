
#include <iostream>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class My_Interface {
public:
	string board[10][10];//can use pointer
	void clearScreen();
	void initalize();
	void print();
	friend class My_Character;
	void update();
	void win_Pattern();
};

class My_Character {
	string appearance_N[3][3] = { {"  ", "* ", "  "},
								  {"* ", "* ", "* "},
								  {"  ", "  ", "  "} };
	string appearance_A[3][3] = { {"  ", " &", "  "},
								  {" &", "  ", "  "},
								  {"  ", " &", "  "} };
	string appearance_R[3][3] = { {"  ", " +", "  "},
								  {"  ", "  ", " +"},
								  {"  ", " +", "  "} };
	string appearance_F[3][3] = { {"  ", "  ", "  "},
								  {" O", "  ", " O"},
								  {"  ", " o", "  "} };
	string appearance_S[3][3] = { {"^^", "  ", "^^"},
								  {"8 ", "OO", " 8"},
								  {"  ", "ww", "  "} };
	string appearance_B[3][3] = { {"9 ", "  ", "9 "},
								  {"( ", "++", " )"},
								  {"  ", "--", "  "} };
	string appearance_C[3][3] = { {"! ", "  ", "! "},
								  {"} ", "**", " {"},
								  {"  ", "o ", "  "} };
	int coordinate[2] = { 4,4 };

public:
	void print_Me(My_Interface& I);
	void clear_Me(My_Interface& I);
	void up_Response(My_Interface& I);
	void left_Response(My_Interface& I);
	void right_Response(My_Interface& I);
	void down_Response(My_Interface& I);
	friend class My_Interface;

};


class User_Input {
public:
	void get_Response(My_Character& Ch, My_Interface& I);
	void start_Guide();
	int level_Selection();
	int moves = 0;
};

class My_Enemy {
	string appearance[4] = { "X ", "% ", "- ", ". " };
	int coord[2];


public:
	void generate(My_Interface& I);
	int check(My_Interface& I);
	int which;
	int score = 0;
};