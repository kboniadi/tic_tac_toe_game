#include "TABLE_PAGE.h"

void Init_TABLE_PAGE(TABLE_PAGE *table_page, GAME_DATA *data)
{
	table_page->data	= data;

	table_page->o_token = LoadTexture("res/images/O.png");
	table_page->x_token = LoadTexture("res/images/X.png");

}

void Render_TABLE(TABLE_PAGE *table_page)
{
	DrawLineEx((Vector2){350, 75}, (Vector2){350, 375}, (float) 5, BLACK);
	DrawLineEx((Vector2){450, 75}, (Vector2){450, 375}, (float) 5, BLACK);
	DrawLineEx((Vector2){250, 175}, (Vector2){550, 175}, (float) 5, BLACK);
	DrawLineEx((Vector2){250, 275}, (Vector2){550, 275}, (float) 5, BLACK);

	if (table_page->data->playing_single_player) {
		playerinput(table_page);
		table_page->data->who_won = CheckWin(table_page);
		aiMove(table_page);
		table_page->data->who_won = CheckWin(table_page);
	} else {
		printWhosGoing(table_page);
		table_page->data->who_won = CheckWin(table_page);
		GetAndCheckInp(table_page);
		table_page->data->who_won = CheckWin(table_page);
	}

	DrawToken(table_page);

	OutputWinner(table_page);
}

char CheckWin(TABLE_PAGE *table_page)
{
	char winner;

	winner = ' ';
	// winning combinations
	for (int i = 0; i < BOARD_ROWS; i++) {
		if (table_page->data->board[i][0].marked && table_page->data->board[i][1].marked && table_page->data->board[i][1].marked && table_page->data->board[i][2].marked) {
			if (table_page->data->board[i][0].type == table_page->data->board[i][1].type && table_page->data->board[i][1].type == table_page->data->board[i][2].type) {
				table_page->data->gameOver = true;
				winner = table_page->data->board[i][0].type;
			}
		}
	}

	for (int j = 0; j < BOARD_COLUMNS; j++) {
		if (table_page->data->board[0][j].marked && table_page->data->board[1][j].marked && table_page->data->board[1][j].marked && table_page->data->board[2][j].marked) {
			if (table_page->data->board[0][j].type == table_page->data->board[1][j].type && table_page->data->board[1][j].type == table_page->data->board[2][j].type) {
				table_page->data->gameOver = true;
				winner = table_page->data->board[0][j].type;
			}
		}
	}

	if (table_page->data->board[0][0].marked && table_page->data->board[1][1].marked && table_page->data->board[2][2].marked) {
		if (table_page->data->board[0][0].type == table_page->data->board[1][1].type && table_page->data->board[1][1].type == table_page->data->board[2][2].type) {
			table_page->data->gameOver = true;
			winner = table_page->data->board[0][0].type;
		}
	}

	if (table_page->data->board[2][0].marked && table_page->data->board[1][1].marked && table_page->data->board[0][2].marked) {
		if (table_page->data->board[2][0].type == table_page->data->board[1][1].type && table_page->data->board[1][1].type == table_page->data->board[0][2].type) {
			table_page->data->gameOver = true;
			winner = table_page->data->board[2][0].type;
		}
	}

	// if all positions are occupied, then it is a draw
	if (table_page->data->positions > 8)
		table_page->data->draw = true;

	return winner;
}

void DrawToken(TABLE_PAGE *table_page)
{
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLUMNS; j++) {
			if (table_page->data->board[i][j].marked) {
				DrawTextureV(table_page->data->board[i][j].token,
				(Vector2){table_page->data->board[i][j].rect.x, table_page->data->board[i][j].rect.y},
				WHITE);
			}
		}
	}
}

void printWhosGoing(TABLE_PAGE *table_page)
{
	if (table_page->data->playerMove && !table_page->data->gameOver && !table_page->data->draw) {
		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		DrawTextEx(GuiGetFont(), table_page->data->player_1, (Vector2){(SCREEN_WIDTH) - (MeasureTextEx(GuiGetFont(), table_page->data->player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x) - (MeasureTextEx(GuiGetFont(), " 's turn! ", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 10 + (MeasureTextEx(GuiGetFont(), table_page->data->player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), BLACK);

		DrawTextEx(GuiGetFont(), "'s turn! ", (Vector2){(SCREEN_WIDTH) - (MeasureTextEx(GuiGetFont(), "'s turn! ", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 10 + (MeasureTextEx(GuiGetFont(), table_page->data->player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), BLACK);
	} else if (!table_page->data->playerMove && !table_page->data->gameOver && !table_page->data->draw) {
		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		DrawTextEx(GuiGetFont(), table_page->data->player_2, (Vector2){(SCREEN_WIDTH) - (MeasureTextEx(GuiGetFont(), table_page->data->player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x) - (MeasureTextEx(GuiGetFont(), " 's turn! ", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 10 + (MeasureTextEx(GuiGetFont(), table_page->data->player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), BLACK);

		DrawTextEx(GuiGetFont(), "'s turn! ", (Vector2){(SCREEN_WIDTH) - (MeasureTextEx(GuiGetFont(), "'s turn! ", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 10 + (MeasureTextEx(GuiGetFont(), table_page->data->player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), BLACK);
	}
}

void GetAndCheckInp(TABLE_PAGE *table_page)
{
	int		i;
	int		j;
	bool		found;

	if (!table_page->data->gameOver && !table_page->data->draw) {
		Vector2 mousePoint = GetMousePosition();
		i		= 0;
		found	= false;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			while (!found && i < BOARD_ROWS) {
				j = 0;
				while (!found && j < BOARD_COLUMNS) {
					if (mousePoint.x > table_page->data->board[i][j].rect.x &&
						mousePoint.y > table_page->data->board[i][j].rect.y &&
						mousePoint.x < table_page->data->board[i][j].rect.x + 100 &&
						mousePoint.y < table_page->data->board[i][j].rect.y + 100 &&
						!table_page->data->board[i][j].marked) {
							if (table_page->data->playerMove) {
								table_page->data->board[i][j].token = table_page->x_token;
								table_page->data->board[i][j].type = 'x';
							} else {
								table_page->data->board[i][j].token = table_page->o_token;
								table_page->data->board[i][j].type = 'o';
							}

							table_page->data->board[i][j].marked = true;
							table_page->data->playerMove = !table_page->data->playerMove;
							table_page->data->positions++;
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

void aiMove(TABLE_PAGE *table_page)
{
	int		random1;
	int		random2;

	random1 = rand() % 4;
	random2 = rand() % 8;

	if (!table_page->data->gameOver && !table_page->data->draw) {
		if (!table_page->data->playerMove && !table_page->data->whatMode) {
			for (int i = 0; i < BOARD_ROWS; i++) {
				for (int j = 0; j < BOARD_COLUMNS; j++) {
					if (!table_page->data->board[i][j].marked) {
						table_page->data->board[i][j].type = 'o';
						table_page->data->board[i][j].marked = true;
						if (CheckWin(table_page) == 'o') {
							table_page->data->board[i][j].token = table_page->o_token;
							table_page->data->playerMove = !table_page->data->playerMove;
							table_page->data->positions++;
							return;
						} else {
							table_page->data->board[i][j].type = ' ';
							table_page->data->board[i][j].marked = false;
						}
					}
				}
			}

			for (int k = 0; k < BOARD_ROWS; k++) {
				for (int l = 0; l < BOARD_COLUMNS; l++) {
					if (!table_page->data->board[k][l].marked) {
						table_page->data->board[k][l].type = 'x';
						table_page->data->board[k][l].marked = true;
						if (CheckWin(table_page) == 'x') {
							table_page->data->board[k][l].token = table_page->o_token;
							table_page->data->board[k][l].type = 'o';
							table_page->data->gameOver = false;
							table_page->data->playerMove = !table_page->data->playerMove;
							table_page->data->positions++;
							return;
						} else {
							table_page->data->board[k][l].type = ' ';
							table_page->data->board[k][l].marked = false;
						}
					}
				}
			}

			if (!table_page->data->board[1][1].marked) {
				table_page->data->board[1][1].token = table_page->o_token;
				table_page->data->board[1][1].type = 'o';
				table_page->data->board[1][1].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[0][0].marked && random1 == 0) {
				table_page->data->board[0][0].token = table_page->o_token;
				table_page->data->board[0][0].type = 'o';
				table_page->data->board[0][0].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[0][2].marked && random1 == 1) {
				table_page->data->board[0][2].token = table_page->o_token;
				table_page->data->board[0][2].type = 'o';
				table_page->data->board[0][2].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[2][0].marked && random1 == 2) {
				table_page->data->board[2][0].token = table_page->o_token;
				table_page->data->board[2][0].type = 'o';
				table_page->data->board[2][0].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[2][2].marked && random1 == 3) {
				table_page->data->board[2][2].token = table_page->o_token;
				table_page->data->board[2][2].type = 'o';
				table_page->data->board[2][2].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[0][1].marked && random1 == 0) {
				table_page->data->board[0][1].token = table_page->o_token;
				table_page->data->board[0][1].type = 'o';
				table_page->data->board[0][1].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[1][0].marked && random1 == 1) {
				table_page->data->board[1][0].token = table_page->o_token;
				table_page->data->board[1][0].type = 'o';
				table_page->data->board[1][0].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[1][2].marked && random1 == 2) {
				table_page->data->board[1][2].token = table_page->o_token;
				table_page->data->board[1][2].type = 'o';
				table_page->data->board[1][2].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (!table_page->data->board[2][1].marked && random1 == 3) {
				table_page->data->board[2][1].token = table_page->o_token;
				table_page->data->board[2][1].type = 'o';
				table_page->data->board[2][1].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			}
		} else if (!table_page->data->playerMove && table_page->data->whatMode) {
			if (random2 == 0 && !table_page->data->board[0][0].marked) {
				table_page->data->board[0][0].token = table_page->o_token;
				table_page->data->board[0][0].type = 'o';
				table_page->data->board[0][0].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 1 && !table_page->data->board[0][1].marked) {
				table_page->data->board[0][1].token = table_page->o_token;
				table_page->data->board[0][1].type = 'o';
				table_page->data->board[0][1].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 2 && !table_page->data->board[0][2].marked) {
				table_page->data->board[0][2].token = table_page->o_token;
				table_page->data->board[0][2].type = 'o';
				table_page->data->board[0][2].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 3 && !table_page->data->board[1][0].marked) {
				table_page->data->board[1][0].token = table_page->o_token;
				table_page->data->board[1][0].type = 'o';
				table_page->data->board[1][0].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 4 && !table_page->data->board[1][1].marked) {
				table_page->data->board[1][1].token = table_page->o_token;
				table_page->data->board[1][1].type = 'o';
				table_page->data->board[1][1].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 5 && !table_page->data->board[1][2].marked) {
				table_page->data->board[1][2].token = table_page->o_token;
				table_page->data->board[1][2].type = 'o';
				table_page->data->board[1][2].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 6 && !table_page->data->board[2][0].marked) {
				table_page->data->board[2][0].token = table_page->o_token;
				table_page->data->board[2][0].type = 'o';
				table_page->data->board[2][0].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 7 && !table_page->data->board[2][1].marked) {
				table_page->data->board[2][1].token = table_page->o_token;
				table_page->data->board[2][1].type = 'o';
				table_page->data->board[2][1].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			} else if (random2 == 8 && !table_page->data->board[2][2].marked) {
				table_page->data->board[2][2].token = table_page->o_token;
				table_page->data->board[2][2].type = 'o';
				table_page->data->board[2][2].marked = true;
				table_page->data->playerMove = !table_page->data->playerMove;
				table_page->data->positions++;
				return;
			}
		}
	}
}

void playerinput(TABLE_PAGE *table_page)
{
	int		i;
	int		j;
	bool	found;

	if (table_page->data->playerMove) {
		if (!table_page->data->gameOver && !table_page->data->draw) {
			Vector2 mousePoint = GetMousePosition();
			i		= 0;
			found	= false;
			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				while (!found && i < BOARD_ROWS) {
					j = 0;
					while (!found && j < BOARD_COLUMNS) {
						if (mousePoint.x > table_page->data->board[i][j].rect.x &&
							mousePoint.y > table_page->data->board[i][j].rect.y &&
							mousePoint.x < table_page->data->board[i][j].rect.x + 100 &&
							mousePoint.y < table_page->data->board[i][j].rect.y + 100 &&
							!table_page->data->board[i][j].marked) {
								table_page->data->board[i][j].token = table_page->x_token;
								table_page->data->board[i][j].type = 'x';
								table_page->data->board[i][j].marked = true;
								table_page->data->playerMove = !table_page->data->playerMove;
								table_page->data->positions++;
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

void OutputWinner(TABLE_PAGE *table_page)
{
	Rectangle endGameFade;

	endGameFade.x = endGameFade.y = 0;
	endGameFade.width = SCREEN_WIDTH;
	endGameFade.height = SCREEN_HEIGHT;

	if (table_page->data->gameOver && table_page->data->who_won == 'x') {
		DrawRectangleRec(endGameFade, (Color){0, 0, 0, 160});

		GuiSetStyle(DEFAULT, TEXT_SIZE, 80);

		DrawTextEx(GuiGetFont(), table_page->data->player_1, (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), table_page->data->player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2) - (MeasureTextEx(GuiGetFont(), table_page->data->player_1, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

		DrawTextEx(GuiGetFont(), "Won!", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Won!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		if (((table_page->data->framesCounter/30)%2 == 0)) {
			DrawTextEx(GuiGetFont(), "Press ENTER to return to main menu", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 1.3) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);
		}
	} else if (table_page->data->gameOver && table_page->data->who_won == 'o') {
		DrawRectangleRec(endGameFade, (Color){0, 0, 0, 160});

		GuiSetStyle(DEFAULT, TEXT_SIZE, 80);

		DrawTextEx(GuiGetFont(), table_page->data->player_2, (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), table_page->data->player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2) - (MeasureTextEx(GuiGetFont(), table_page->data->player_2, GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

		DrawTextEx(GuiGetFont(), "Won!", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Won!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		if (((table_page->data->framesCounter/30)%2 == 0)) {
			DrawTextEx(GuiGetFont(), "Press ENTER to return to main menu", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 1.3) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);
		}
	} else if (table_page->data->draw) {
		DrawRectangleRec(endGameFade, (Color){0, 0, 0, 160});

		GuiSetStyle(DEFAULT, TEXT_SIZE, 80);

		DrawTextEx(GuiGetFont(), "It's a draw!", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "It's a draw!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 2) - (MeasureTextEx(GuiGetFont(), "It's a draw!", GuiGetStyle(DEFAULT, TEXT_SIZE),
		GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);

		GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

		if (((table_page->data->framesCounter/30)%2 == 0)) {
			DrawTextEx(GuiGetFont(), "Press ENTER to return to main menu", (Vector2){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), (SCREEN_HEIGHT / 1.3) - (MeasureTextEx(GuiGetFont(), "Press ENTER to return to main menu", GuiGetStyle(DEFAULT, TEXT_SIZE),
			GuiGetStyle(DEFAULT, TEXT_SPACING)).y / 2)}, GuiGetStyle(DEFAULT, TEXT_SIZE), GuiGetStyle(DEFAULT, TEXT_SPACING), WHITE);
		}
	}

	if (IsKeyPressed(KEY_ENTER))
		table_page->data->state = MAIN_PAGE_ID;
}

void Delete_TABLE_PAGE(TABLE_PAGE *table_page)
{
	UnloadTexture(table_page->o_token);
	UnloadTexture(table_page->x_token);
}