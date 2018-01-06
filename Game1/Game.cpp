#include "stdafx.h"
#include "Game.h" 

// Function for game initialization

void game_initialize(Ball *ball, Player *player, Brick brick[size_brick_height][size_brick_width], bool *playing, bool *title, bool *pause, int ballw, int ballh, int brickw, int brickh, int playerw, int playerh)
{
	// Initialize Ball object:

	ball->set_x(SCREEN_W / 2 - ballw / 2);
	ball->set_y(SCREEN_H / 2 - ballh);
	ball->set_dx(def_dx_dy);
	ball->set_dy(def_dx_dy);
	ball->set_bw(ballw);
	ball->set_bh(ballh);

	// Initialize Brick matrix:

	for (int i = 0; i < size_brick_height; i++) {
		for (int j = 0; j < size_brick_width; j++) {
			brick[i][j].set_x(j*brickw);
			brick[i][j].set_y(50 + i * brickh);
			brick[i][j].set_bh(brickh);
			brick[i][j].set_bw(brickw);
		}
	}

	// Initialize Player object:

	player->set_x(SCREEN_W / 2 - playerw / 2);
	player->set_y(SCREEN_H - playerh);
	player->set_pw(playerw);
	player->set_ph(playerh);
	player->set_dx(SCREEN_W / 100);
	player->set_life(def_life);

	// Setting parameters befor entering title

	*playing = true;
	*title = true;
	*pause = false;
}

// Function for easy game mode

void game_easy(Ball *ball, Player *player, bool *playing, bool *title, int *mode)
{
	*mode = 3;
	player->set_life(easy_life);
	ball->set_dx(easy_dx_dy);
	ball->set_dy(easy_dx_dy);
	*playing = true;
	*title = false;
}

// Function for default game mode

void game_default(Ball *ball, Player *player, bool *playing, bool *title, int *mode)
{
	*mode = 1;
	player->set_life(def_life);
	ball->set_dx(def_dx_dy);
	ball->set_dy(def_dx_dy);
	*playing = true;
	*title = false;
}

// Function for hard game mode

void game_hard(Ball *ball, Player *player, bool *playing, bool *title, int *mode)
{
	*mode = 2;
	player->set_life(hard_life);
	ball->set_dx(hard_dx_dy);
	ball->set_dy(hard_dx_dy);
	player->set_dx(SCREEN_W / 80);
	*playing = true;
	*title = false;
}

// Restart game when default mode is chosen:

void game_restart_def(bool key[3], bool *playing, Player *player, Ball *ball, Brick brick[size_brick_height][size_brick_width], int ballw, int ballh, int playerw, int playerh, int ignore_score[size_brick_height][size_brick_width])
{
	if (key[KEY_LEFT])
		key[KEY_LEFT] = false;

	if (key[KEY_RIGHT])
		key[KEY_RIGHT] = false;

	*playing = true;
	player->set_life(def_life);
	player->set_score(0);
	ball->set_dx(def_dx_dy);
	ball->set_dy(def_dx_dy);
	ball->set_x(SCREEN_W / 2 - ballw / 2);
	ball->set_y(SCREEN_H / 2 - ballh);
	player->set_x(SCREEN_W / 2 - playerw / 2);
	player->set_y(SCREEN_H - playerh);
	for (int i = 0; i < size_brick_height; i++) {
		for (int j = 0; j < size_brick_width; j++)
		{
			brick[i][j].set_bv(1);
			ignore_score[i][j] = 0;
		}
	}
}

// Function for game title

void game_title(Ball *ball, Player *player, bool *playing, bool *title, int *mode, ALLEGRO_EVENT *ev, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventqueue, ALLEGRO_FONT *font)
{
	while (*title) // Do while title is active
	{
		// Starting Allegro time and waiting for event:

	    al_start_timer(timer);
		al_wait_for_event(eventqueue, ev);
		if (ev->type == ALLEGRO_EVENT_TIMER)
		{
			// Showing the title:

			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 14 * 24, ALLEGRO_ALIGN_CENTRE, "(D)EFAULT GAME");
			al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 12 * 24, ALLEGRO_ALIGN_CENTRE, "(E)ASY GAME");
			al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 10 * 24, ALLEGRO_ALIGN_CENTRE, "(H)ARD GAME");
			al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 8 * 24, ALLEGRO_ALIGN_CENTRE, "(Q)UIT GAME");
			al_draw_textf(font, al_map_rgb(0, 120, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 6 * 24, ALLEGRO_ALIGN_CENTRE, "DURING GAME PRESS:");
			al_draw_textf(font, al_map_rgb(0, 120, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 4 * 24, ALLEGRO_ALIGN_CENTRE, "Q TO QUIT");
			al_draw_textf(font, al_map_rgb(0, 120, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 2 * 24, ALLEGRO_ALIGN_CENTRE, "R TO RESTART");
			al_draw_textf(font, al_map_rgb(0, 120, 255), SCREEN_W / 2, 3 * SCREEN_H / 4 - 0 * 24, ALLEGRO_ALIGN_CENTRE, "P TO PAUSE");
			al_flip_display();
		}
		else if (ev->type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev->keyboard.keycode) {
			case ALLEGRO_KEY_Q:
				// Quit choice:

				*playing = false;
				*title = false;
				break;
			case ALLEGRO_KEY_D:
			{
				// Default game mode:

				game_default(ball, player, playing, title, mode);
				break;
			}
			case ALLEGRO_KEY_H:
			{
				// Hard game mode:

				game_hard(ball, player, playing, title, mode);
				break;
			}
			case ALLEGRO_KEY_E:
			{
				// Easy game mode:

				game_easy(ball, player, playing, title, mode);
				break;
			}
			}
		}
	}
}

// Function for game playing

void game_play(Ball *ball, Player *player, Brick brick[size_brick_height][size_brick_width], bool *playing, int *mode, bool *pause, ALLEGRO_EVENT *ev, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventqueue, ALLEGRO_FONT *font, int ballw, int ballh, int brickw, int brickh, int playerw, int playerh, ALLEGRO_BITMAP *ball_fig, ALLEGRO_BITMAP *player_fig, ALLEGRO_BITMAP *brick_fig, ALLEGRO_DISPLAY *display)
{
	// If ball interacts with the brick, this brick should only once be added to players score

	int ignore_score[size_brick_height][size_brick_width] = { { 0 } };

	bool key[3] = { false, false, false }; // Check if keys are pressed 

	while (*playing) // When playing flag is true
	{
		if (!player->get_life()) // If player loses all lifes end screen appears 
		{
			al_start_timer(timer); 
			al_wait_for_event(eventqueue, ev);
			if (ev->type == ALLEGRO_EVENT_TIMER) // Everything is being drawn during the timer event
			{
				// At end screen, player can choose to quit or restart the game
				al_clear_to_color(al_map_rgb(255, 172, 78));
				al_draw_textf(font, al_map_rgb(0, 120, 255), SCREEN_W / 2, SCREEN_H / 2 - 48, ALLEGRO_ALIGN_CENTRE, "SORRY, YOU LOSE! SCORE WAS: %i", player->get_score());
				al_draw_textf(font, al_map_rgb(0, 0, 255), SCREEN_W / 2, SCREEN_H / 2 - 24, ALLEGRO_ALIGN_CENTRE, "(R)ESTART OR (Q)UIT");
				al_flip_display();
				if (key[KEY_R])
				{
					if (*mode == 1) // Restart game when default game mode was chosen 
					{
						game_restart_def(key, playing, player, ball, brick, ballw, ballh, playerw, playerh, ignore_score);
					}
					else if (*mode == 2)
					{
						if (key[KEY_LEFT])
							key[KEY_LEFT] = false;

						if (key[KEY_RIGHT])
							key[KEY_RIGHT] = false;

						*playing = true;
						player->set_life(hard_life);
						player->set_score(0);
						ball->set_dx(hard_dx_dy);
						ball->set_dy(hard_dx_dy);
						ball->set_x(SCREEN_W / 2 - ballw / 2);
						ball->set_y(SCREEN_H / 2 - ballh);
						player->set_x(SCREEN_W / 2 - playerw / 2);
						player->set_dx(SCREEN_W / 80);
						player->set_y(SCREEN_H - playerh);
						for (int i = 0; i < size_brick_height; i++) {
							for (int j = 0; j < size_brick_width; j++)
							{
								brick[i][j].set_bv(1);
								ignore_score[i][j] = 0;
							}
						}
					}
					else if (*mode == 3)
					{
						if (key[KEY_LEFT])
							key[KEY_LEFT] = false;

						if (key[KEY_RIGHT])
							key[KEY_RIGHT] = false;

						*playing = true;
						player->set_life(easy_life);
						player->set_score(0);
						ball->set_dx(easy_life);
						ball->set_dy(easy_dx_dy);
						ball->set_x(SCREEN_W / 2 - ballw / 2);
						ball->set_y(SCREEN_H / 2 - ballh);
						player->set_x(SCREEN_W / 2 - playerw / 2);
						player->set_y(SCREEN_H - playerh);
						for (int i = 0; i < size_brick_height; i++) {
							for (int j = 0; j < size_brick_width; j++)
							{
								brick[i][j].set_bv(1);
								ignore_score[i][j] = 0;
							}
						}
					}
				}
			}
			else if (ev->type == ALLEGRO_EVENT_KEY_DOWN) // Event when a key is pressed
			{
				switch (ev->keyboard.keycode) {
				case ALLEGRO_KEY_Q: // Q is used for quitting nad it sets playing flag to false
					*playing = false;
					break;
				case ALLEGRO_KEY_R: // Restart key
				{
					key[KEY_R] = true;
					break;
				}
				}

			}
			else if (ev->type == ALLEGRO_EVENT_KEY_DOWN) // Check if restart key is released 
			{
				switch (ev->keyboard.keycode) {
				case ALLEGRO_KEY_R:
					key[KEY_R] = false;
					break;
				}
			}
		}
		else // If not at end game screen, playing mode is on
		{
			al_clear_to_color(al_map_rgb(224, 224, 224)); // Setting allegro variables for drawing the playing mode 
			al_wait_for_event(eventqueue, ev);
			al_start_timer(timer);
			if (ev->type == ALLEGRO_EVENT_TIMER)
			{
				if (!*pause) // When pause is pressed, game stops until pause is pressed again
				{
					ball->change_position(); // Move the ball
					ball->interaction_wall(SCREEN_W, SCREEN_H, player); // Check if the ball interacts with walls
					ball->interaction_player(player); // Check if the ball interacts with player's paddle 

					// Check if ball has interacted with each brick 
					for (int i = 0; i < size_brick_height; i++) { 
						for (int j = 0; j < size_brick_width; j++) {
							if (brick[i][j].get_bv())
							{
								// If ball interacts with brick, this brick is then removed from play (brick_visible flag is false)
								brick[i][j].set_bv(!ball->interaction_brick(&brick[i][j]));
							}
						}
					}

					for (int i = 0; i < size_brick_height; i++) {
						for (int j = 0; j < size_brick_width; j++) {
							if (!brick[i][j].get_bv() && !ignore_score[i][j])
							{
								// If brick was hit by the ball this adds to player's score and this brick is ignored from further scoring
								player->inc_score(1);
								ignore_score[i][j] = 1;
							}
						}
					}

					if (key[KEY_LEFT]) // Move player left
					{
						player->change_position_left();
					}

					if (key[KEY_RIGHT]) // Move player right
					{
						player->change_position_right(SCREEN_W);
					}

					if (key[KEY_R]) // If R key is pressed during the game, game restarts
					{
						if (*pause)
							*pause = false;
						if (*mode == 1) // Restart game when default game mode was chosen
						{
							game_restart_def(key, playing, player, ball, brick, ballw, ballh, playerw, playerh, ignore_score);
						}
						else if (*mode == 2)
						{
							if (key[KEY_LEFT])
								key[KEY_LEFT] = false;

							if (key[KEY_RIGHT])
								key[KEY_RIGHT] = false;

							*playing = true;
							player->set_life(hard_life);
							player->set_score(0);
							ball->set_dx(hard_dx_dy);
							ball->set_dy(hard_dx_dy);
							ball->set_x(SCREEN_W / 2 - ballw / 2);
							ball->set_y(SCREEN_H / 2 - ballh);
							player->set_x(SCREEN_W / 2 - playerw / 2);
							player->set_dx(SCREEN_W / 80);
							player->set_y(SCREEN_H - playerh);
							for (int i = 0; i < size_brick_height; i++) {
								for (int j = 0; j < size_brick_width; j++)
								{
									brick[i][j].set_bv(1);
									ignore_score[i][j] = 0;
								}
							}
						}
						else if (*mode == 3)
						{
							if (key[KEY_LEFT])
								key[KEY_LEFT] = false;

							if (key[KEY_RIGHT])
								key[KEY_RIGHT] = false;

							*playing = true;
							player->set_life(easy_life);
							player->set_score(0);
							ball->set_dx(easy_life);
							ball->set_dy(easy_dx_dy);
							ball->set_x(SCREEN_W / 2 - ballw / 2);
							ball->set_y(SCREEN_H / 2 - ballh);
							player->set_x(SCREEN_W / 2 - playerw / 2);
							player->set_y(SCREEN_H - playerh);
							for (int i = 0; i < size_brick_height; i++) {
								for (int j = 0; j < size_brick_width; j++)
								{
									brick[i][j].set_bv(1);
									ignore_score[i][j] = 0;
								}
							}
						}
					}
				}
				else
				{
					al_draw_textf(font, al_map_rgb(0, 120, 255), SCREEN_W / 2, SCREEN_H / 2 - 48, ALLEGRO_ALIGN_CENTRE, "PAUSED. PRESS P AGAIN TO CONTINUE.");
				}

			}

			else if (ev->type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (ev->keyboard.keycode) {

				case ALLEGRO_KEY_LEFT:
					key[KEY_LEFT] = true;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					break;
				case ALLEGRO_KEY_Q:
					*playing = false;
					break;
				case ALLEGRO_KEY_P:
				{
					if (!*pause)
						*pause = true;
					else
						*pause = false;
					break;
				}
				case ALLEGRO_KEY_R:
				{
					key[KEY_R] = true;
					break;
				}
				}
			}
			else if (ev->type == ALLEGRO_EVENT_KEY_UP) {
				switch (ev->keyboard.keycode) {
				case ALLEGRO_KEY_LEFT:
					key[KEY_LEFT] = false;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = false;
					break;
				case ALLEGRO_KEY_R:
					key[KEY_R] = false;
					break;
				}
			}

			else if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
			}

			al_draw_bitmap(player_fig, player->get_x(), player->get_y(), 0);
			al_draw_bitmap(ball_fig, ball->get_x(), ball->get_y(), 0);
			al_draw_textf(font, al_map_rgb(0, 0, 0), SCREEN_W / 2, 24, ALLEGRO_ALIGN_CENTRE, "SCORE: %i ", player->get_score());
			al_draw_textf(font, al_map_rgb(0, 0, 0), SCREEN_W / 2, 0, ALLEGRO_ALIGN_CENTRE, "LIFE: %i ", player->get_life());

			for (int i = 0; i < size_brick_height; i++) {
				for (int j = 0; j < size_brick_width; j++)
				{
					if (brick[i][j].get_bv())
						al_draw_bitmap(brick_fig, brick[i][j].get_x(), brick[i][j].get_y(), 0);
				}
			}

			al_flip_display();
		}

	}

	al_flip_display();
	if (*playing)
		al_rest(0.1);
	else
		al_rest(0.8);

	al_destroy_display(display);
}
