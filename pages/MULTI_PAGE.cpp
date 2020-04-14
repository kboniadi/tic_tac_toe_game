#include "MULTI_PAGE.h"

void Init_MULTI_PAGE(MULTI_PAGE *multi_page, GAME_DATA *data)
{
	multi_page->data		= data;
	multi_page->editModeMulti	= false;
}

void Render_MULTI_PAGE(MULTI_PAGE *multi_page)
{
	Vector2 mousePoint = GetMousePosition();

	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2) - (MeasureTextEx(GuiGetFont(), "Multiplayer Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x / 2), 10, MeasureTextEx(GuiGetFont(), "Multiplayer Mode", 40,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40}, "Multiplayer Mode");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	if (GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 75, 150, 150, 50}, multi_page->data->player_1, MAX_INPUT_CHARS + 1, multi_page->data->editModeSingle)) {
		multi_page->data->editModeSingle = true;
	} else if (IsKeyPressed(KEY_ENTER) || (!CheckCollisionPointRec(mousePoint, (Rectangle){SCREEN_WIDTH / 2 - 75, 150, 150, 50}) && IsMouseButtonPressed(0))) {
		multi_page->data->editModeSingle = false;
	}

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2 - 80) - (MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 165, MeasureTextEx(GuiGetFont(), "Player X", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "Player X");

	if (GuiTextBox((Rectangle){SCREEN_WIDTH / 2 - 75, 225, 150, 50}, multi_page->data->player_2, MAX_INPUT_CHARS + 1, multi_page->editModeMulti)) {
		multi_page->editModeMulti = true;
	} else if (IsKeyPressed(KEY_ENTER) || (!CheckCollisionPointRec(mousePoint, (Rectangle){SCREEN_WIDTH / 2 - 75, 225, 150, 50}) && IsMouseButtonPressed(0))) {
		multi_page->editModeMulti = false;
	}

	GuiLabel((Rectangle){(SCREEN_WIDTH / 2 - 80) - (MeasureTextEx(GuiGetFont(), "Player O", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 240, MeasureTextEx(GuiGetFont(), "Player O", 20,
	GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 20 }, "Player O");

	if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2),
	SCREEN_HEIGHT - (BUTTON_HEIGHT * 4), BUTTON_WIDTH, BUTTON_HEIGHT}, "Start"))
		multi_page->data->state = TABLE_PAGE_ID;
	else if (GuiButton((Rectangle){(SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2),
	SCREEN_HEIGHT - ((BUTTON_HEIGHT * 3) - (BUTTON_HEIGHT / 2)), BUTTON_WIDTH,
	BUTTON_HEIGHT}, "Back"))
		multi_page->data->state = MAIN_PAGE_ID;

	multi_page->data->playing_single_player = false;
}

void Delete_MULTI_PAGE(MULTI_PAGE *multi_page)
{

}