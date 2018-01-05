#pragma once
#include "stdafx.h"

using namespace std;

// Player class:

class Player
{
public:
	// Default Constructor of the class Player:

	Player::Player() { this->score = 0; this->life = 3; this->player_width = 64; this->player_height = 32; this->x_pos = 0; this->y_pos = 0; this->diff_x = 3; };

	// Parametrized Constructor of the class Player:

	Player::Player(int x, int y, int pw, int ph, int dx, int lif) { this->score = 0; this->life = lif; this->player_width = pw; this->player_height = ph; this->x_pos = x; this->y_pos = y; this->diff_x = dx; };

	// Declaration of methods

	void set_score(int inc);
	void dec_score(int lf_inc);
	void inc_score(int lf_inc);
	void set_life(int lf_inc);
	void dec_life(int lf_inc);
	void inc_life(int lf_inc);
	void set_x(int x);
	void set_y(int y);
	void set_dx(int dx);
	void set_pw(int bw);
	void set_ph(int bh);
	void change_position_left();
	void change_position_right(int SW);

	int get_score();
	int get_life();
	int get_x();
	int get_y();
	int get_dx();
	int get_pw();
	int get_ph();

private:

	// Private parameters

	int x_pos;
	int y_pos;
	int diff_x;
	int player_width;
	int player_height;
	int score;
	int life;
};
