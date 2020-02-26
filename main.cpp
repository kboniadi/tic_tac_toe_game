#include "pages/INSTRUC_PAGE.h"
#include "pages/MAIN_PAGE.h"
#include "pages/SINGLE_PAGE.h"
#include "pages/MULTI_PAGE.h"
#include "pages/TABLE_PAGE.h"
#include "LIMITS.h"
#include <iostream>
#include "raylib.h"

int main() {
	int state;
	bool editModeSingle;
	bool editModeMulti;
	bool normal_checked;
	bool hard_checked;
	bool playing_single_player;
	int random_num;
	int turn;

	turn = 0;
	state = INSTRUC_PAGE;
	char player_1[MAX_INPUT_CHARS + 1] = "\0";
	char player_2[MAX_INPUT_CHARS + 1] = "\0";
	editModeSingle = false;
	editModeMulti = false;
	normal_checked = true;
	hard_checked = false;

	srand(time(NULL));

	random_num = rand() % 2;

	struct Index {
		Rectangle rect;
		Texture2D token;
		char type = ' ';
		bool marked = false;
	};

	bool gameOver = false;
	bool draw = false;
	bool playerMove = false;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    SetTargetFPS(FPS);

	Texture2D x_token = LoadTexture("res/images/X.png");
	Texture2D o_token = LoadTexture("res/images/O.png");

	Index board[3][3];
	int positions = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j].rect.width = board[i][j].rect.height = 100;
			board[i][j].rect.x = (i * 100) + 250;
			board[i][j].rect.y = (j * 100) + 75;
		}
	}

	Rectangle rectMuteScreen;

	rectMuteScreen.x = rectMuteScreen.y = 0;
	rectMuteScreen.width = SCREEN_WIDTH;
	rectMuteScreen.height = SCREEN_HEIGHT;

	bool mouseButtonPressed = false;
    while (!(WindowShouldClose() || state == EXIT_PAGE)) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

		switch (state) {
		case INSTRUC_PAGE:
			Render_INSTRUC_PAGE(state);
			break;
		case MAIN_PAGE:
			Render_MAIN_PAGE(state, player_1, player_2, MAX_INPUT_CHARS);
			break;
		case SINGLE_PAGE:
			Render_SINGLE_PAGE(state, player_1, MAX_INPUT_CHARS, editModeSingle, normal_checked, hard_checked);
			playing_single_player = true;
			break;
		case MULTI_PAGE:
			Render_MULTI_PAGE(state, player_1, player_2, MAX_INPUT_CHARS, editModeSingle, editModeMulti);
			playing_single_player = false;
			break;
		case TABLE_PAGE:
			Render_TABLE_PAGE(playing_single_player, player_1, player_2, random_num);
			if (playing_single_player) {
				if (!gameOver && !draw) {
					Vector2 mousePoint = GetMousePosition();

					if (mouseButtonPressed) {
						for (int i = 0; i < 3; i++) {
							for (int j = 0; j < 3; j++) {
								if (mousePoint.x > board[i][j].rect.x &&
									mousePoint.y > board[i][j].rect.y &&
									mousePoint.x < board[i][j].rect.x + 100 &&
									mousePoint.y < board[i][j].rect.y + 100) {
										if (playerMove) {
											board[i][j].token = x_token;
											board[i][j].type = 'x';
										} else {
											board[i][j].token = o_token;
											board[i][j].type = 'o';
										}

										board[i][j].marked = true;
										playerMove = !playerMove;
										positions++;
										break;
									}
							}
						}

						mouseButtonPressed = false;
					}

					//	checking if game is over
					if(board[0][0].marked && board[0][1].marked && board[0][2].marked) {
						if(board[0][0].type == board[0][1].type && board[0][1].type == board[0][2].type) {
							gameOver = true;
						}
					}

					if(board[1][0].marked && board[1][1].marked && board[1][2].marked) {
						if(board[1][0].type == board[1][1].type && board[1][1].type == board[1][2].type) {
							gameOver = true;
						}
					}

					if(board[2][0].marked && board[2][1].marked && board[2][2].marked) {
						if(board[2][0].type == board[2][1].type && board[2][1].type == board[2][2].type) {
							gameOver = true;
						}
					}

					if(board[0][0].marked && board[1][0].marked && board[2][0].marked) {
						if(board[0][0].type == board[1][0].type && board[1][0].type == board[2][0].type) {
							gameOver = true;
						}
					}

					if(board[0][1].marked && board[1][1].marked && board[2][1].marked) {
						if(board[0][1].type == board[1][1].type && board[1][1].type == board[2][1].type) {
							gameOver = true;
						}
					}

					if(board[0][2].marked && board[1][2].marked && board[2][2].marked) {
						if(board[0][2].type == board[1][2].type && board[1][2].type == board[2][2].type) {
							gameOver = true;
						}
					}

					if(board[0][0].marked && board[1][1].marked && board[2][2].marked) {
						if(board[0][0].type == board[1][1].type && board[1][1].type == board[2][2].type) {
							gameOver = true;
						}
					}

					if(board[2][0].marked && board[1][1].marked && board[0][2].marked) {
						if(board[2][0].type == board[1][1].type && board[1][1].type == board[0][2].type) {
							gameOver = true;
						}
					}

					//	if all positions are occupied, then it is a draw
					if(positions >= 9) {
						draw = true;
					}
				}

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					mouseButtonPressed = true;
				}

				for (int i = 0; i < 3; i++) {
					for ( int j = 0; j < 3; j++) {
						if (board[i][j].marked) {
							DrawTextureRec(board[i][j].token, board[i][j].rect,
								(Vector2){board[i][j].rect.x, board[i][j].rect.y}, WHITE);
						}
					}
				}

				if (gameOver) {
					DrawRectangleRec(rectMuteScreen, (Color){0, 0, 0, 160});
					DrawText("You won!", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50, WHITE);
				} else if (draw) {
					DrawRectangleRec(rectMuteScreen, (Color){0, 0, 0, 160});
					DrawText("It's a draw!", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50, WHITE);
				}
			}
			break;
		}

        EndDrawing();
    }
	for (int i = 0; i < 3; i++) {
		for ( int j = 0; j < 3; j++) {
			// std::cout << board[i][j].rect.x << std::endl;
			// std::cout << board[i][j].rect.y << std::endl;
			std::cout << board[i][j].type << std::endl;

		}
	}
	UnloadTexture(x_token);
	UnloadTexture(o_token);

    CloseWindow();

    return 0;
}