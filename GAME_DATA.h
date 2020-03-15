#ifndef GAME_DATA_H_
#define GAME_DATA_H_

#include "raygui.h"
#include "LIMITS.h"
#include "INDEX.h"
#include <cstring>

struct GAME_DATA {
	int			state;
	bool		editModeSingle;
	bool		playing_single_player;
	bool		gameOver;
	bool		draw;
	bool		playerMove;
	bool		whatMode;
	int			framesCounter;
	char		who_won;
	char 		player_1[MAX_INPUT_CHARS + 1];
	char 		player_2[MAX_INPUT_CHARS + 1];
	Index 		board[BOARD_ROWS][BOARD_COLUMNS];
	int 		positions;
};

void Init_GAME_DATA(GAME_DATA *data);

void Delete_GAME_DATA(GAME_DATA *data);

#endif	/* GAME_DATA_H_ */