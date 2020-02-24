#include "SINGLE_PAGE.h"

bool Render_SINGLE_PAGE(char array[], const int ARRAY_SIZE)
{
	bool editMode;

	editMode = true;
	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "SINGLE Player Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "SINGLE Player Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "SINGLE Player Mode");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
	return GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 100, 225, 200, 70}, array, ARRAY_SIZE + 1, editMode);
}