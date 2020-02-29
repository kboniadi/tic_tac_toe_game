#include "TABLE_PAGE.h"

void Render_TABLE()
{
	DrawLineEx((Vector2){350, 75}, (Vector2){350, 375}, (float) 5, BLACK);
	DrawLineEx((Vector2){450, 75}, (Vector2){450, 375}, (float) 5, BLACK);
	DrawLineEx((Vector2){250, 175}, (Vector2){550, 175}, (float) 5, BLACK);
	DrawLineEx((Vector2){250, 275}, (Vector2){550, 275}, (float) 5, BLACK);
}

char CheckWin(Index table[][BOARD_ROWS], int turns,  bool &endGame, bool &tie)
{
	char winner;

	winner = ' ';

	// winning combinations
	for (int i = 0; i < BOARD_ROWS; i++) {
		if (table[i][0].marked && table[i][1].marked && table[i][1].marked && table[i][2].marked) {
			if (table[i][0].type == table[i][1].type && table[i][1].type == table[i][2].type) {
				endGame = true;
				winner = table[i][0].type;
			}
		}
	}

	for (int j = 0; j < BOARD_COLUMNS; j++) {
		if (table[0][j].marked && table[1][j].marked && table[1][j].marked && table[2][j].marked) {
			if (table[0][j].type == table[1][j].type && table[1][j].type == table[2][j].type) {
				endGame = true;
				winner = table[0][j].type;
			}
		}
	}

	if(table[0][0].marked && table[1][1].marked && table[2][2].marked) {
		if(table[0][0].type == table[1][1].type && table[1][1].type == table[2][2].type) {
			endGame = true;
			winner = table[0][0].type;
		}
	}

	if(table[2][0].marked && table[1][1].marked && table[0][2].marked) {
		if(table[2][0].type == table[1][1].type && table[1][1].type == table[0][2].type) {
			endGame = true;
			winner = table[2][0].type;
		}
	}

	// if all positions are occupied, then it is a draw
	if(turns > 8) {
		tie = true;
	}

	return winner;
}

void DrawToken(Index table[][BOARD_ROWS])
{
	for (int i = 0; i < BOARD_ROWS; i++) {
		for ( int j = 0; j < BOARD_COLUMNS; j++) {
			if (table[i][j].marked) {
				DrawTextureV(table[i][j].token,
				(Vector2){table[i][j].rect.x, table[i][j].rect.y},
				WHITE);
			}
		}
	}
}

void GetAndCheckInp(Index table[][BOARD_ROWS], bool endGame, bool tie,
bool &whosGoing, int &turns, Texture2D x_chip, Texture2D o_chip)
{
	int i;
	int j;
	bool found;

	if (!endGame && !tie) {
		Vector2 mousePoint = GetMousePosition();
		i = 0;
		found = false;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			while (!found && i < BOARD_ROWS) {
				j = 0;
				while (!found && j < BOARD_COLUMNS) {
					if (mousePoint.x > table[i][j].rect.x &&
						mousePoint.y > table[i][j].rect.y &&
						mousePoint.x < table[i][j].rect.x + 100 &&
						mousePoint.y < table[i][j].rect.y + 100 &&
						!table[i][j].marked) {
							if (whosGoing) {
								table[i][j].token = x_chip;
								table[i][j].type = 'x';
							} else {
								table[i][j].token = o_chip;
								table[i][j].type = 'o';
							}

							table[i][j].marked = true;
							whosGoing = !whosGoing;
							turns++;
							found = true;
					} else {
						j++;
					}
				}
				i++;
			}
		}
	}
}

void aiMove(Index table[][BOARD_ROWS], bool endGame, bool tie, bool &whosGoing,
int &turns, Texture2D x_chip, Texture2D o_chip)
{
	int i;
	int j;
	int k;
	int l;
	bool found;
	bool found2;

	if (!endGame && !tie) {
		i = 0;
		found = false;
		if (!whosGoing) {
			while (!found && i < BOARD_ROWS) {
				j = 0;
				while (!found && j < BOARD_COLUMNS) {
					if (!table[i][j].marked) {
						table[i][j].type = 'o';
						table[i][j].marked = true;
						if (CheckWin(table, turns, endGame, tie) == 'o') {
							table[i][j].token = o_chip;
							whosGoing = !whosGoing;
							turns++;
							found = true;
							return;
						} else {
							table[i][j].type = ' ';
							table[i][j].marked = false;
						}
					}
					j++;
				}
				i++;
			}

			k = 0;
			found2 = false;
			while (!found2 && k < BOARD_ROWS) {
				l = 0;
				while (!found2 && l < BOARD_COLUMNS) {
					if (!table[k][l].marked) {
						table[k][l].type = 'x';
						table[k][l].marked = true;
						if (CheckWin(table, turns, endGame, tie) == 'x') {
							table[k][l].token = o_chip;
							table[k][l].type = 'o';
							whosGoing = !whosGoing;
							turns++;
							found2 = true;
							return;
						} else {
							table[k][l].type = ' ';
							table[k][l].marked = false;
						}
					}
					l++;
				}
				k++;
			}

			if (!table[1][1].marked) {
				table[1][1].token = o_chip;
				table[1][1].type = 'o';
				table[1][1].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[0][0].marked) {
				table[0][0].token = o_chip;
				table[0][0].type = 'o';
				table[0][0].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[0][2].marked) {
				table[0][2].token = o_chip;
				table[0][2].type = 'o';
				table[0][2].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[2][0].marked) {
				table[2][0].token = o_chip;
				table[2][0].type = 'o';
				table[2][0].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[2][2].marked) {
				table[2][2].token = o_chip;
				table[2][2].type = 'o';
				table[2][2].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[0][1].marked) {
				table[0][1].token = o_chip;
				table[0][1].type = 'o';
				table[0][1].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[1][0].marked) {
				table[1][0].token = o_chip;
				table[1][0].type = 'o';
				table[1][0].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[1][2].marked) {
				table[1][2].token = o_chip;
				table[1][2].type = 'o';
				table[1][2].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			} else if (!table[2][1].marked) {
				table[2][1].token = o_chip;
				table[2][1].type = 'o';
				table[2][1].marked = true;
				whosGoing = !whosGoing;
				turns++;
				return;
			}
		}
	}
}

void playerinput(Index table[][BOARD_ROWS], bool endGame, bool tie,
bool &whosGoing, int &turns, Texture2D x_chip, Texture2D o_chip)
{
	int i;
	int j;
	bool found;
	if (whosGoing) {
		if (!endGame && !tie) {
			Vector2 mousePoint = GetMousePosition();
			i = 0;
			found = false;
			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				while (!found && i < BOARD_ROWS) {
					j = 0;
					while (!found && j < BOARD_COLUMNS) {
						if (mousePoint.x > table[i][j].rect.x &&
							mousePoint.y > table[i][j].rect.y &&
							mousePoint.x < table[i][j].rect.x + 100 &&
							mousePoint.y < table[i][j].rect.y + 100 &&
							!table[i][j].marked) {
								table[i][j].token = x_chip;
								table[i][j].type = 'x';
								table[i][j].marked = true;
								whosGoing = !whosGoing;
								turns++;
								found = true;
						} else {
							j++;
						}
					}
					i++;
				}
			}
		}
	}
}

void OutputWinner(char *player_1, char *player_2, char winner, bool endGame,
bool tie, int &state, int framesCounter)
{
	Rectangle endGameFade;

	endGameFade.x = endGameFade.y = 0;
	endGameFade.width = SCREEN_WIDTH;
	endGameFade.height = SCREEN_HEIGHT;

	if (endGame && winner == 'x') {
		DrawRectangleRec(endGameFade, (Color){0, 0, 0, 160});

		GuiSetStyle(DEFAULT, TEXT_SIZE, 80);

		DrawTextEx(GuiGetFont(), player_1, (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2) - (MeasureTextEx(GuiGetFont(), player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

		DrawTextEx(GuiGetFont(), "Won!", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Won!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		if (((framesCounter/30)%2 == 0)) {
			DrawTextEx(GuiGetFont(), "Press ENTER to return to main menu", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 1.3) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);
		}

		if (IsKeyPressed(KEY_ENTER))
			state = MAIN_PAGE;
	} else if (tie) {
		DrawRectangleRec(endGameFade, (Color){0, 0, 0, 160});

		GuiSetStyle(DEFAULT, TEXT_SIZE, 60);

		DrawTextEx(GuiGetFont(), "It's a draw!", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "It's a draw!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2) - (MeasureTextEx(GuiGetFont(), "It's a draw!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		if (((framesCounter/30)%2 == 0)) {
			DrawTextEx(GuiGetFont(), "Press ENTER to return to main menu", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 1.3) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);
		}

		if (IsKeyPressed(KEY_ENTER))
			state = MAIN_PAGE;
	} else if (endGame && winner == 'o') {
		DrawRectangleRec(endGameFade, (Color){0, 0, 0, 160});

		GuiSetStyle(DEFAULT, TEXT_SIZE, 80);

		DrawTextEx(GuiGetFont(), player_2, (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2) - (MeasureTextEx(GuiGetFont(), player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

		DrawTextEx(GuiGetFont(), "Won!", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Won!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		if (((framesCounter/30)%2 == 0)) {
			DrawTextEx(GuiGetFont(), "Press ENTER to return to main menu", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 1.3) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);
		}

		if (IsKeyPressed(KEY_ENTER))
			state = MAIN_PAGE;
	}
}