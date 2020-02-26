#include "MULTI_PAGE.h"

void Render_MULTI_PAGE(int &state, char array[], char array2[], const int ARRAY_SIZE, bool &mode1, bool &mode2)
{
	Vector2 mousePoint = GetMousePosition();

	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Multiplayer Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "Multiplayer Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40 }, "Multiplayer Mode");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 75, 150, 150, 50}, array, MAX_INPUT_CHARS + 1, mode1)) {
		mode1 = true;
	} else if (IsKeyPressed(KEY_ENTER) || (!CheckCollisionPointRec(mousePoint, (Rectangle){SCREEN_WIDTH / 2 - 75, 150, 150, 50}) && IsMouseButtonPressed(0))) {
		mode1 = false;
	}

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2 - 80) - (MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 165, MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "Player X");

	if (GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 75, 225, 150, 50}, array2, MAX_INPUT_CHARS + 1, mode2)) {
		mode2 = true;
	} else if (IsKeyPressed(KEY_ENTER) || (!CheckCollisionPointRec(mousePoint, (Rectangle){SCREEN_WIDTH / 2 - 75, 225, 150, 50}) && IsMouseButtonPressed(0))) {
		mode2 = false;
	}

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2 - 80) - (MeasureTextEx(GuiGetFont(), "Player O", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 240, MeasureTextEx(GuiGetFont(), "Player O", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "Player O");

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2),
	SCREEN_HEIGHT - (BUTTON_HEIGHT * 4), BUTTON_WIDTH, BUTTON_HEIGHT}, "Start"))
		state = TABLE_PAGE;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2),
	SCREEN_HEIGHT - ((BUTTON_HEIGHT * 3) - (BUTTON_HEIGHT / 2)), BUTTON_WIDTH,
	BUTTON_HEIGHT}, "Back"))
		state = MAIN_PAGE;
}