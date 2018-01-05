#pragma once
#include "stdafx.h"

using namespace std;

// Brick class:
class Brick
{
public:
	// Default constructor for class Brick

	Brick::Brick() { this->x_pos = 0; this->y_pos = 0; this->brick_width = 0; this->brick_height = 0; this->brick_visible = 1; } 

	// Parametrized constructor for class Brick

	Brick::Brick(int x, int y, int bw, int bh) { this->x_pos = x; this->y_pos = y; this->brick_width = bw; this->brick_height = bh; this->brick_visible = 1; } 

	// Declaration of methods:

	void set_x(int x);
	void set_y(int y);
	void set_bw(int bw);
	void set_bh(int bh);
	void set_bv(int bv);

	int get_x();
	int get_y();
	int get_bw();
	int get_bh();
	int get_bv();

private:

	// Private parameters

	int x_pos;
	int y_pos;
	int brick_width;
	int brick_height;
	int brick_visible;
};

