#include "stdafx.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"
#include <stdlib.h>  

// BALL CLASS:

// Methods for setting the parameters:

void Ball::set_x(int x)
{
	this->x_pos = x;
}

void Ball::set_y(int y)
{
	this->y_pos = y;
}

void Ball::set_dx(int dx)
{
	this->diff_x = dx;
}

void Ball::set_dy(int dy)
{
	this->diff_y = dy;
}

void Ball::set_bw(int bw)
{
	this->ball_width = bw;
}

void Ball::set_bh(int bh)
{
	this->ball_height = bh;
}

// Method for moving the ball:

void Ball::change_position()
{
	// Change (x,y) of the ball:

	this->set_x(this->get_x() + this->get_dx());
	this->set_y(this->get_y() + this->get_dy());
}

// Method which checks if the ball interacts with any wall:

void Ball::interaction_wall(int SW, int SH, Player* player)
{
	// Check if the ball hits left side of the wall:

	if (this->get_x() + this->get_bw()>= SW)
	{
		this->set_dx(this->get_dx()*-1);
	}

	// Check if the ball hits right side of the wall:

	if (this->get_x()<=-1)
	{
		this->set_dx(this->get_dx()*-1);
	}

	// Check if the ball goes ot of the play (lower part of the field):

	if (this->get_y() + this->get_bw()>= SH)
	{
		// Reset the ball to starting position:

		this->set_x(SW / 2 - this->get_bw() / 2);
		this->set_y(SH / 2 - this->get_bh());
		player->dec_life(1);
	}

	// Check if the ball hits upper part of the wall:

	if (this->get_y() <= 0)
	{
		this->set_dy(this->get_dy()*-1);
	}
}

// Check if the ball has interacted with the player's paddle:

void Ball::interaction_player(Player* player){

	// Check if ball hits top of the paddle:

	if (this->get_x() <= player->get_x() + player->get_pw() && this->get_x() + this->get_bw() >= player->get_x() && this->get_y() + this->get_bh() <= player->get_y() + player->get_ph() && this->get_y() + this->get_bh() >= player->get_y())
	{
		this->set_dy(this->get_dy()*-1);
	}

	// Check if the ball hits left side of the paddle:

	if (this->get_x()  <= player->get_x() && this->get_x() + this->get_bw() >= player->get_x() && this->get_y() + this->get_bh() >= player->get_y() && this->get_y() + this->get_bh() <= player->get_y() + player->get_ph())
	{

		this->set_dx(abs(this->get_dx())*-1);
	}

	// Check if the ball hits right side of the paddle:

	if (this->get_x() <= player->get_x() + player->get_pw() && this->get_x() + this->get_bw() >= player->get_x() + player->get_pw() && this->get_y() + this->get_bh() >= player->get_y() && this->get_y() + this->get_bh() <= player->get_y() + player->get_ph())
	{

		this->set_dx(abs(this->get_dx()));
	}
}

// Check if the ball has hit the brick:

int Ball::interaction_brick(Brick* brick)
{

	// Varaibles which define if ball moves up or down:

	int dy_pos = 0;
	int dy_neg = 0;

	if (this->get_dy() < 0)
		dy_neg = 1;
	else
		dy_pos = 1;

	//First: we check if the ball has hit the upper side of the brick

	if (dy_pos && this->get_x() + this->get_bw() >= brick->get_x() && this->get_x() <= brick->get_x() && this->get_y() + this->get_bh() >= brick->get_y() && this->get_y() <= brick->get_y())
	{
		//this->set_dy(this->get_dy()*-1);
		this->set_dy(abs(this->get_dy())*-1);
		return 1;
	}
	else if (dy_pos && this->get_x() <= brick->get_x() + brick->get_bw() && this->get_x() + this->get_bw() >= brick->get_x() + brick->get_bw() && this->get_y() + this->get_bh() >= brick->get_y() && this->get_y() <= brick->get_y())
	{
		//this->set_dy(this->get_dy()*-1);
		this->set_dy(abs(this->get_dy())*-1);
		return 1;
	}

	//Second: we check if the ball has hit the bottom side of the brick

	else if (dy_neg && this->get_x() + this->get_bw() >= brick->get_x() && this->get_x() <= brick->get_x() && this->get_y() >= brick->get_y() && this->get_y() <= brick->get_y() + brick->get_bh())
	//else if (this->get_x() + this->get_bw() >= brick->get_x() && this->get_x() <= brick->get_x() && this->get_y() == brick->get_y() + brick->get_bh())
	{
		//this->set_dy(this->get_dy()*-1);
		this->set_dy(abs(this->get_dy()));
		return 1;
	}
	else if (dy_neg && this->get_x() <= brick->get_x() + brick->get_bw() && this->get_x() + this->get_bw() >= brick->get_x() + brick->get_bw() && this->get_y() >= brick->get_y() && this->get_y() <= brick->get_y() + brick->get_bh())
	//else if (this->get_x() <= brick->get_x() + brick->get_bw() && this->get_x() + this->get_bw() >= brick->get_x() + brick->get_bw() && this->get_y() == brick->get_y())
	{
		//this->set_dy(this->get_dy()*-1);
		this->set_dy(abs(this->get_dy()));
		return 1;
	}

	else return 0;

}

// Methods for getting the parameters:

int Ball::get_x()
{
	return this->x_pos;
}

int Ball::get_y()
{
	return this->y_pos;
}

int Ball::get_dx()
{
	return this->diff_x;
}

int Ball::get_dy()
{
	return this->diff_y;
}

int Ball::get_bw()
{
	return this->ball_width;
}

int Ball::get_bh()
{
	return this->ball_height;
}
