#include "stdafx.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"

// BRICK CLASS:

// Methods for setting the parameters:

void Brick::set_x(int x)
{
	this->x_pos = x;
}

void Brick::set_y(int y)
{
	this->y_pos = y;
}

void Brick::set_bw(int bw)
{
	this->brick_width = bw;
}

void Brick::set_bh(int bh)
{
	this->brick_height = bh;
}

void Brick::set_bv(int bv)
{
	this->brick_visible = bv;
}

// Methods for getting the parameters:

int Brick::get_x()
{
	return this->x_pos;
}

int Brick::get_y()
{
	return this->y_pos;
}

int Brick::get_bw()
{
	return this->brick_width;
}

int Brick::get_bh()
{
	return this->brick_height;
}

int Brick::get_bv()
{
	return this->brick_visible;
}

