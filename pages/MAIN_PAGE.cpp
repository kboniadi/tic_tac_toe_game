#include "MAIN_PAGE.h"

void Render_MAIN_PAGE(int &state)
{
	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "TIC TAC TOE", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "TIC TAC TOE", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "TIC TAC TOE");

	if (GuiButton((Rectangle){ (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 200, BUTTON_WIDTH, BUTTON_HEIGHT}, "Single Player"))
		state = SINGLE_PAGE;
	else if (GuiButton((Rectangle){ (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 250, BUTTON_WIDTH, BUTTON_HEIGHT}, "Multiplayer"))
		state = MULTI_PAGE;
	else if (GuiButton((Rectangle){ (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 300, BUTTON_WIDTH, BUTTON_HEIGHT}, "Exit"))
		state = EXIT_PAGE;
}