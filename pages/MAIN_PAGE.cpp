#include "MAIN_PAGE.h"

void Render_MAIN_PAGE(int &state, char array[], char array2[], const int ARRAY_SIZE)
{
	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "TIC TAC TOE", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "TIC TAC TOE", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40 }, "TIC TAC TOE");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 200, BUTTON_WIDTH, BUTTON_HEIGHT}, "Single Player"))
		state = SINGLE_PAGE;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 250, BUTTON_WIDTH, BUTTON_HEIGHT}, "Multiplayer"))
		state = MULTI_PAGE;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 300, BUTTON_WIDTH, BUTTON_HEIGHT}, "Exit"))
		state = EXIT_PAGE;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = '\0';
		array2[i] = '\0';
	}

}

void InitBoard(Index table[][BOARD_ROWS])
{
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLUMNS; j++) {
			table[i][j].rect.width = table[i][j].rect.height = 100;
			table[i][j].rect.x = (j * 100) + 250;
			table[i][j].rect.y = (i * 100) + 75;
			table[i][j].type = ' ';
			table[i][j].marked = false;
		}
	}
}