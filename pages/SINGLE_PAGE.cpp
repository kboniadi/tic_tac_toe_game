#include "SINGLE_PAGE.h"

void Init_SINGLE_PAGE(SINGLE_PAGE *single_page, GAME_DATA *data)
{
	single_page->data			= data;
	single_page->normal_checked	 	= true;
	single_page->hard_checked		= false;
}

void Render_SINGLE_PAGE(SINGLE_PAGE *single_page)
{
	char		hard_mode[10] = "Hard Mode";
	char		normal_mode[12] = "Normal Mode";
	Vector2		mousePoint = GetMousePosition();

	strcpy(single_page->data->player_2, "The Computer");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Single Player Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "Single Player Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40 }, "Single Player Mode");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 75, 150, 150, 50}, single_page->data->player_1, MAX_INPUT_CHARS + 1, single_page->data->editModeSingle)) {
		single_page->data->editModeSingle = true;
	} else if (IsKeyPressed(KEY_ENTER) || (!CheckCollisionPointRec(mousePoint, (Rectangle){SCREEN_WIDTH / 2 - 100, 225, 200, 40}) && IsMouseButtonPressed(0))) {
		single_page->data->editModeSingle = false;
	}

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2 - 80) - (MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 165, MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "Player X");

	bool normal_mode_checked = GuiCheckBox((Rectangle){SCREEN_WIDTH / 2 + 90, 150, 20, 20}, normal_mode, single_page->normal_checked);
	bool hard_mode_checked = GuiCheckBox((Rectangle){SCREEN_WIDTH / 2 + 90, 180, 20, 20}, hard_mode, single_page->hard_checked);

	if (normal_mode_checked && single_page->hard_checked) {
		single_page->normal_checked = true;
		single_page->hard_checked = false;
	} else if (hard_mode_checked && single_page->normal_checked) {
		single_page->hard_checked = true;
		single_page->normal_checked = false;
	}

	if (normal_mode_checked) {
		single_page->data->whatMode = true;
	} else if (hard_mode_checked) {
		single_page->data->whatMode = false;
	}

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 230, BUTTON_WIDTH, BUTTON_HEIGHT}, "Start"))
		single_page->data->state = TABLE_PAGE_ID;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 290, BUTTON_WIDTH, BUTTON_HEIGHT}, "Back"))
		single_page->data->state = MAIN_PAGE_ID;

	single_page->data->playing_single_player = true;
}

void Delete_SINGLE_PAGE(SINGLE_PAGE *single_page)
{

}