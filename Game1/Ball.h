#pragma once
#include "stdafx.h"

using namespace std;

// declaration of PLayer and Brick classes;
class Player;
class Brick;

// Ball class:

class Ball
{
public:
	// Default constructor for class Brick

	Ball::Ball() { this->x_pos = 0; this->y_pos = 0; this->diff_x = 5; this->diff_y = 5; this->ball_height = 32; this->ball_width = 32;}

	// Parametrized constructor for class Ball

		Ball::Ball(int x, int y, int dx, int dy, int bw, int bh)
	{
		this->x_pos = x; this->y_pos = y;
		this->diff_x = dx; this->diff_y = dy;
		this->ball_width = bw; this->ball_height = bh;
	}

	// Declaration of methods

	void set_x(int x);
	void set_y(int y);
	void set_dx(int dx);
	void set_dy(int dy);
	void set_bw(int bw);
	void set_bh(int bh);
	void change_position();
	void interaction_wall(int SW, int SH, Player* player);
	void interaction_player(Player* player);
	int interaction_brick(Brick* brick);

	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_bw();
	int get_bh();

private:

	// Private parameters

	int x_pos;
	int y_pos;
	int diff_x;
	int diff_y;
	int ball_width;
	int ball_height;
};
