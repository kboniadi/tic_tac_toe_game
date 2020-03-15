#include "MAIN_PAGE.h"

void Init_MAIN_PAGE(MAIN_PAGE *main_page, GAME_DATA *data) {
	main_page->data			= data;
	main_page->random_num	= 0;
}

void Render_MAIN_PAGE(MAIN_PAGE *main_page)
{
	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "TIC TAC TOE", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "TIC TAC TOE", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40 }, "TIC TAC TOE");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 200, BUTTON_WIDTH, BUTTON_HEIGHT}, "Single Player"))
		main_page->data->state = SINGLE_PAGE_ID;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 250, BUTTON_WIDTH, BUTTON_HEIGHT}, "Multiplayer"))
		main_page->data->state = MULTI_PAGE_ID;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 300, BUTTON_WIDTH, BUTTON_HEIGHT}, "Exit"))
		main_page->data->state = EXIT_PAGE_ID;

	for (int i = 0; i < MAX_INPUT_CHARS; i++) {
		main_page->data->player_1[i] = '\0';
		main_page->data->player_2[i] = '\0';
	}

	main_page->data->gameOver = false;
	main_page->data->draw = false;
	main_page->random_num = rand() % 2;

	main_page->data->playerMove = (main_page->random_num == 0);

	main_page->data->positions = 0;

	InitBoard(main_page);

}

void InitBoard(MAIN_PAGE *main_page)
{
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLUMNS; j++) {
			main_page->data->board[i][j].rect.width = main_page->data->board[i][j].rect.height = 100;
			main_page->data->board[i][j].rect.x = (j * 100) + 250;
			main_page->data->board[i][j].rect.y = (i * 100) + 75;
			main_page->data->board[i][j].type = ' ';
			main_page->data->board[i][j].marked = false;
		}
	}
}

void Delete_MAIN_PAGE(MAIN_PAGE *main_page)
{

}