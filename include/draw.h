#ifndef DRAW_H
#define DRAW_H
#include <3ds.h>
#include "settings.h"
#include "main_data.h"
#include "level.h"
#include "lemming_data.h"
#include "control.h"

typedef enum
{
	TOP_SCREEN = 0,
	BOTTOM_SCREEN = 1,
	TOP_SCREEN_BACK = 2,
	BOTTOM_SCREEN_BACK = 3
} ScreenBuffer;

void init_drawing();

void begin_frame();
void end_frame();

// apply fading to palette (not its alpha value, since gfx seems to ignore alpha value)
void fade_palette(u32 palette[16], float fading);

// scale with linear interpolation
int draw_scaled(
		ScreenBuffer screen,
		s16 x,
		s16 y,
		const u8* img,
		u16 w,
		u16 h,
		u32 palette[16],
		float scaling);

int clear(ScreenBuffer screen);
int clear_rectangle(ScreenBuffer screen, u16 x, u16 y, u16 w, u16 h);
int color_rectangle(ScreenBuffer screen, u16 x, u16 y, u16 w, u16 h, u32 color);
void copy_from_backbuffer(ScreenBuffer screen);

// draw palette image into RGB image at specific position
int draw(ScreenBuffer screen, s16 x, s16 y, const u8* img, u16 w, u16 h, u32 palette[16]);

// draw menu background into im_bottom (tiled)
void tile_menu_background(ScreenBuffer screen, struct MainMenuData* menu_data);

// draw level view at top of RGB image while (without info text, toolbar, and lemmings)
int draw_level(
		ScreenBuffer screen,
		s16 x,
		s16 y,
		u16 w,
		u16 h,
		s16 x_offset,
		struct Level* level,
		struct MainInGameData* main_data,
		u32* palette);


// draw a string using highperf-font into an RGB image
void draw_highperf_text(
		ScreenBuffer screen,
		s16 x,
		s16 y,
		struct MainInGameData* data,
		const char* text,
		u32* highperf_palette);

// draw a string using menu-font into an RGB image
void draw_menu_text(
		ScreenBuffer screen,
		struct MainMenuData* data,
		s16 x_offset,
		s16 y_offset,
		const char* text,
		u32* palette,
		float scaling);

// draw toolbar at bottom of RGB image
int draw_toolbar(
		struct MainInGameData* data,
		struct Level* level,
		struct InputState* io_state,
		const char* text,
		u32* highperf_palette,
		u8 player);

// draw lemmings of all players (only 2 players supported)
void draw_lemmings(
		ScreenBuffer screen,
		s16 x,
		s16 y,
		struct Level* level,
		struct Image* lemmings_anim[337],
		struct Image* masks[23],
		u32 palette[16],
		s16 x_offset,
		s16 y_offset);

int update_topscreen(struct MainMenuData* menu);
#endif
