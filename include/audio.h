#ifndef AUDIO_H
#define AUDIO_H
#include <3ds.h>
#include "savegame.h"

void init_audio();
void read_audio_settings(struct SaveGame* savegame);
void write_audio_settings(struct SaveGame* savegame);
int toggle_audio();
int is_audio_enabled();
int is_audio_only_fx();
int import_audio(u8 game);
int is_custom_sound(u8 sound);
void next_music(u8 game);
void prepare_music(u8 game, u8 lvl);
void play_music();
void stop_audio();
void play_sound(u8 sound);
void update_audio();
void deinit_audio();
#endif
