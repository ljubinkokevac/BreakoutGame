#include "stdafx.h"
#include "Game.h"

int main()
{
	// Variables from allegro.h

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *ball_fig = NULL;
	ALLEGRO_BITMAP *brick_fig = NULL;
	ALLEGRO_BITMAP *player_fig = NULL;
	ALLEGRO_EVENT_QUEUE *eventqueue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT ev;

	// Allegro initialization:
	
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	al_init_primitives_addon();
	al_install_keyboard();
	eventqueue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	al_register_event_source(eventqueue, al_get_keyboard_event_source());
	al_register_event_source(eventqueue, al_get_display_event_source(display));
	al_register_event_source(eventqueue, al_get_timer_event_source(timer));

	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 24, 0);

	if (!font) {
		fprintf(stderr, "Could not load 'arial.ttf'.\n");
		return -1;
	}

	// End of Allegro initialization 

	// Loading images:
	
	ball_fig = al_load_bitmap("ball.png");

	if (!ball_fig) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load ball image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	int ballw = al_get_bitmap_width(ball_fig);
	int ballh = al_get_bitmap_height(ball_fig);

	brick_fig = al_load_bitmap("brick.png");

	if (!brick_fig) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load brick image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	int brickw = al_get_bitmap_width(brick_fig);
	int brickh = al_get_bitmap_height(brick_fig);
	
	player_fig = al_load_bitmap("paddle.png");

	if (!player_fig) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load player (paddle) image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	int playerw = al_get_bitmap_width(player_fig);
	int playerh = al_get_bitmap_height(player_fig);

	// End of images loading

	// Game initialization:

	Ball ball;
	Player player;
	Brick brick[size_brick_height][size_brick_width]; // Matrix of bricks

	// Game states:

	bool playing = false;
	bool title = false;
	bool pause = false;

	int mode = 0; // Three game modes (Default, Easy, hard)
	
	game_initialize(&ball, &player, brick, &playing, &title, &pause, ballw, ballh, brickw, brickh, playerw, playerh);

	// End of game initialization

	// Game title screen:

	game_title(&ball, &player, &playing, &title, &mode, &ev, timer, eventqueue, font);

	// Play game:

	game_play(&ball, &player, brick, &playing, &mode, &pause, &ev, timer, eventqueue, font, ballw, ballh, brickw, brickh, playerw, playerh, ball_fig, player_fig, brick_fig, display);	

	return 0;
}

