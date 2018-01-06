#pragma once
#include "stdafx.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro5.h>
#include <allegro5/color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include <math.h> 
#include <iostream>
#include <conio.h>
// Defintion of needed constants:

const int SCREEN_W = 800;
const int SCREEN_H = 700;
const float FPS = 60.0;
const int size_brick_width = 25;
const int size_brick_height = 8;
const int def_life = 5;
const int def_dx_dy = 5;
const int hard_life = 3;
const int hard_dx_dy = 10;
const int easy_life = 7;
const int easy_dx_dy = 3;

// Keys for moving player's paddle:

enum MYKEYS {
	KEY_LEFT, KEY_RIGHT, KEY_R
};

// Function for game initialization

void game_initialize(Ball *ball, Player *player, Brick brick[size_brick_height][size_brick_width], bool *playing, bool *title, bool *pause, int ballw, int ballh, int brickw, int brickh, int playerw, int playerh);

// Function for easy game mode

void game_easy(Ball *ball, Player *player, bool *playing, bool *title, int *mode);

// Function for default game mode

void game_default(Ball *ball, Player *player, bool *playing, bool *title, int *mode);

// Function for hard game mode

void game_hard(Ball *ball, Player *player, bool *playing, bool *title, int *mode);

// Function for game title

void game_title(Ball *ball, Player *player, bool *playing, bool *title, int *mode, ALLEGRO_EVENT *ev, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventqueue, ALLEGRO_FONT *font);

// Restart game when default mode is chosen:

void game_restart_def(bool key[3], bool *playing, Player *player, Ball *ball, Brick brick[size_brick_height][size_brick_width], int ballw, int ballh, int playerw, int playerh, int ignore_score[size_brick_height][size_brick_width]);

// Restart game when hard mode is chosen:

void game_restart_hard(bool key[3], bool *playing, Player *player, Ball *ball, Brick brick[size_brick_height][size_brick_width], int ballw, int ballh, int playerw, int playerh, int ignore_score[size_brick_height][size_brick_width]);

// Restart game when easy mode is chosen:

void game_restart_easy(bool key[3], bool *playing, Player *player, Ball *ball, Brick brick[size_brick_height][size_brick_width], int ballw, int ballh, int playerw, int playerh, int ignore_score[size_brick_height][size_brick_width]);

// Function for game playing:

void game_play(Ball *ball, Player *player, Brick brick[size_brick_height][size_brick_width], bool *playing, int *mode, bool *pause, ALLEGRO_EVENT *ev, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventqueue, ALLEGRO_FONT *font, int ballw, int ballh, int brickw, int brickh, int playerw, int playerh, ALLEGRO_BITMAP *ball_fig, ALLEGRO_BITMAP *player_fig, ALLEGRO_BITMAP *brick_fig, ALLEGRO_DISPLAY *display);



