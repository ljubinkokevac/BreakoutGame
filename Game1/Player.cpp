#include "stdafx.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"

// PLAYER CLASS:

// Definition of methods for setting parameters:

void Player::set_score(int inc)
{
	this->score = inc;
}

void Player::dec_score(int lf_inc)
{
	this->score -= lf_inc;
}

void Player::inc_score(int lf_inc)
{
	this->score += lf_inc;
}

void Player::set_life(int lf_inc)
{
	this->life = lf_inc;
}

void Player::dec_life(int lf_inc)
{
	this->life -= lf_inc;
}

void Player::inc_life(int lf_inc)
{
	this->life += lf_inc;
}

void Player::set_x(int x)
{
	this->x_pos = x;
}

void Player::set_y(int y)
{
	this->y_pos = y;
}

void Player::set_dx(int dx)
{
	this->diff_x = dx;
}

void Player::set_pw(int pw)
{
	this->player_width = pw;
}

void Player::set_ph(int ph)
{
	this->player_height = ph;
}

// Method fo changing position of player's paddle to the left:

void Player::change_position_left()
{
	this->set_x(this->get_x() - this->get_dx());
	if (this->get_x() < 0) { this->set_x(0); };
}

// Method fo changing position of player's paddle to the left:

void Player::change_position_right(int SW)
{
	this->set_x(this->get_x() + this->get_dx());
	if (this->get_x() + this->get_pw() > SW) { this->set_x(SW - this->get_pw()); };
}

// Methods for getting parameters:

int Player::get_score()
{
	return this->score;
}

int Player::get_life()
{
	return this->life;
}

int Player::get_x()
{
	return this->x_pos;
}

int Player::get_y()
{
	return this->y_pos;
}

int Player::get_dx()
{
	return this->diff_x;
}


int Player::get_pw()
{
	return this->player_width;
}

int Player::get_ph()
{
	return this->player_height;
}