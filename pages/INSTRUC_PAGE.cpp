#define RAYGUI_IMPLEMENTATION
#include "INSTRUC_PAGE.h"

void Render_INSTRUC_PAGE(int &state)
{
	GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "This is a game of Tic Tac Toe!", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "This is a game of Tic Tac Toe!", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, GuiGetStyle(DEFAULT, TEXT_SIZE)}, "This is a game of Tic Tac Toe!");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "In this game you'll be able to play in single player or multiplayer mode.", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 60, MeasureTextEx(GuiGetFont(), "In this game you'll be able to play in single player or multiplayer mode.", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, GuiGetStyle(DEFAULT, TEXT_SIZE)}, "In this game you'll be able to play in single player or multiplayer mode.");

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Users will first have to enter their name(s) and in the case of the single", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 80, MeasureTextEx(GuiGetFont(), "Users will first have to enter their name(s) and in the case of the single", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, GuiGetStyle(DEFAULT, TEXT_SIZE)}, "Users will first have to enter their name(s) and in the case of the single");

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "player mode pick a difficulty. After, a player will then be picked at random", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 100, MeasureTextEx(GuiGetFont(), "player mode pick a difficulty. After, a player will then be picked at random", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, GuiGetStyle(DEFAULT, TEXT_SIZE)}, "player mode pick a difficulty. After, a player will then be picked at random");

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "to start and the goal will be to get three of your tokens in a row.", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 120, MeasureTextEx(GuiGetFont(), "to start and the goal will be to get three of your tokens in a row.", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, GuiGetStyle(DEFAULT, TEXT_SIZE)}, "to start and the goal will be to get three of your tokens in a row.");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Good Luck!", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 160, MeasureTextEx(GuiGetFont(), "Good Luck!", GuiGetStyle(DEFAULT, TEXT_SIZE),
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, GuiGetStyle(DEFAULT, TEXT_SIZE)}, "Good Luck!");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 250, BUTTON_WIDTH, BUTTON_HEIGHT}, "Load Game")) {
		state = MAIN_PAGE;
	} else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 300, BUTTON_WIDTH, BUTTON_HEIGHT}, "Exit")) {
		state = EXIT_PAGE;
	}
}