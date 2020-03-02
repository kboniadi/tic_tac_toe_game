#include "SINGLE_PAGE.h"

bool Render_SINGLE_PAGE(int &state, char array[], char array2[], const int ARRAY_SIZE, bool &mode, bool &n_checked, bool &h_checked)
{
	char hard_mode[10] = "Hard Mode";
	char normal_mode[12] = "Normal Mode";
	Vector2 mousePoint = GetMousePosition();
	bool gameMode;

	gameMode = false;

	strcpy(array2, "The Computer");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Single Player Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "Single Player Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40 }, "Single Player Mode");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 75, 150, 150, 50}, array, MAX_INPUT_CHARS + 1, mode)) {
		mode = true;
	} else if (IsKeyPressed(KEY_ENTER) || (!CheckCollisionPointRec(mousePoint, (Rectangle){SCREEN_WIDTH / 2 - 100, 225, 200, 40}) && IsMouseButtonPressed(0))) {
		mode = false;
	}

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2 - 80) - (MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 165, MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "Player X");

	bool normal_mode_checked = GuiCheckBox((Rectangle){SCREEN_WIDTH / 2 + 90, 150, 20, 20}, normal_mode, n_checked);
	bool hard_mode_checked = GuiCheckBox((Rectangle){SCREEN_WIDTH / 2 + 90, 180, 20, 20}, hard_mode, h_checked);

	if (normal_mode_checked && h_checked) {
		n_checked = true;
		h_checked = false;
	} else if (hard_mode_checked && n_checked) {
		h_checked = true;
		n_checked = false;
	}

	if (normal_mode_checked) {
		gameMode = true;
	} else if (hard_mode_checked) {
		gameMode = false;
	}

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 230, BUTTON_WIDTH, BUTTON_HEIGHT}, "Start"))
		state = TABLE_PAGE;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 290, BUTTON_WIDTH, BUTTON_HEIGHT}, "Back"))
		state = MAIN_PAGE;

	return gameMode;
}