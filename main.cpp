#include "pages/INSTRUC_PAGE.h"
#include "pages/MAIN_PAGE.h"
#include "pages/SINGLE_PAGE.h"
#include "pages/MULTI_PAGE.h"
#include "pages/TABLE_PAGE.h"
#include "LIMITS.h"
#include "INDEX.h"
#include <iostream>

int main() {
	int state;
	bool editModeSingle;
	bool editModeMulti;
	bool normal_checked;
	bool hard_checked;
	bool playing_single_player;
	bool gameOver;
	bool draw;
	bool playerMove;
	int framesCounter;
	char who_won;
	int random_num;

	playing_single_player = true;
	state = INSTRUC_PAGE;
	char player_1[MAX_INPUT_CHARS + 1] = "\0";
	char player_2[MAX_INPUT_CHARS + 1] = "\0";
	editModeSingle = false;
	editModeMulti = false;
	normal_checked = true;
	hard_checked = false;
	who_won = ' ';
	random_num = 0;

	srand(time(NULL));

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    SetTargetFPS(FPS);

	Texture2D x_token = LoadTexture("res/images/X.png");
	Texture2D o_token = LoadTexture("res/images/O.png");

	Index board[BOARD_ROWS][BOARD_COLUMNS];
	int positions;

	gameOver = false;
	draw = false;
	playerMove = false;
	positions = 0;
	framesCounter = 0;

    while (!(WindowShouldClose() || state == EXIT_PAGE)) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
		framesCounter++;

		switch (state) {
		case INSTRUC_PAGE:
			Render_INSTRUC_PAGE(state);
			break;
		case MAIN_PAGE:
			Render_MAIN_PAGE(state, player_1, player_2, MAX_INPUT_CHARS);

			InitBoard(board);

			gameOver = false;
			draw = false;
			random_num = rand() % 2;

			if (random_num == 0)
				playerMove = false;
			else if (random_num == 1)
				playerMove = true;

			positions = 0;
			break;
		case SINGLE_PAGE:
			Render_SINGLE_PAGE(state, player_1, player_2, MAX_INPUT_CHARS, editModeSingle, normal_checked, hard_checked);
			playing_single_player = true;
			break;
		case MULTI_PAGE:
			Render_MULTI_PAGE(state, player_1, player_2, MAX_INPUT_CHARS, editModeSingle, editModeMulti);
			playing_single_player = false;
			break;
		case TABLE_PAGE:
			Render_TABLE();

			if (playing_single_player) {
				playerinput(board, gameOver, draw, playerMove, positions, x_token, o_token);
				aiMove(board, gameOver, draw, playerMove, positions, x_token, o_token);
				who_won = CheckWin(board, positions, gameOver, draw);
			} else {
				GetAndCheckInp(board, gameOver, draw, playerMove, positions, x_token, o_token);
				who_won = CheckWin(board, positions, gameOver, draw);
			}

			DrawToken(board);

			OutputWinner(player_1, player_2, who_won, gameOver, draw, state, framesCounter);
			break;
		}

        EndDrawing();
    }
	UnloadTexture(x_token);
	UnloadTexture(o_token);

    CloseWindow();

    return 0;
}