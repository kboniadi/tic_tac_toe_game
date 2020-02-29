#ifndef TABLE_PAGE_H_
#define TABLE_PAGE_H_

#include "../LIMITS.h"
#include "../raygui.h"
#include "../INDEX.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
// #include <stdio.h>
#include <string.h>

void Render_TABLE();

char CheckWin(Index table[][BOARD_ROWS], int turns,  bool &endGame, bool &tie);

void DrawToken(Index table[][BOARD_ROWS]);

void GetAndCheckInp(Index table[][BOARD_ROWS], bool endGame, bool tie, bool &whosGoing, int &turns, Texture2D x_chip, Texture2D o_chip);

void aiMove(Index table[][BOARD_ROWS], bool endGame, bool tie, bool &whosGoing, int &turns, Texture2D x_chip, Texture2D o_chip);

void playerinput(Index table[][BOARD_ROWS], bool endGame, bool tie, bool &whosGoing, int &turns, Texture2D x_chip, Texture2D o_chip);

void OutputWinner(char *player_1, char *player_2, char winner, bool endGame, bool tie, int &state, int framesCounter);

#endif	/* TABLE_PAGE_H_ */