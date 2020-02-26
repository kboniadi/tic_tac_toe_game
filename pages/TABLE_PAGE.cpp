#include "TABLE_PAGE.h"

void Render_TABLE_PAGE(bool game_type, char array[], char array2[], int random)
{

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	DrawLineEx((Vector2){350, 75}, (Vector2){350, 375}, (float) 5, BLACK);
	DrawLineEx((Vector2){450, 75}, (Vector2){450, 375}, (float) 5, BLACK);
	DrawLineEx((Vector2){250, 175}, (Vector2){550, 175}, (float) 5, BLACK);
	DrawLineEx((Vector2){250, 275}, (Vector2){550, 275}, (float) 5, BLACK);

	// GuiButton((Rectangle){250, 75, 100, 100}, " ");
	// GuiButton((Rectangle){350, 75, 100, 100}, " ");
	// GuiButton((Rectangle){450, 75, 100, 100}, " ");
	// GuiButton((Rectangle){250, 175, 100, 100}, " ");
	// GuiButton((Rectangle){350, 175, 100, 100}, " ");
	// GuiButton((Rectangle){450, 175, 100, 100}, " ");
	// GuiButton((Rectangle){250, 275, 100, 100}, " ");
	// GuiButton((Rectangle){350, 275, 100, 100}, " ");
	// GuiButton((Rectangle){450, 275, 100, 100}, " ");

// 	if (game_type) {
//
// 	} else {
// 		if (random == 0) {
//
// 			GuiLabel((Rectangle){(SCREEN_WIDTH - 10) - (MeasureTextEx(GuiGetFont(), " 's turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x) - (MeasureTextEx(GuiGetFont(), array, GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 50, MeasureTextEx(GuiGetFont(), array, GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x, MeasureTextEx(GuiGetFont(), array, GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).y}, array);
//
// 			GuiLabel((Rectangle){(SCREEN_WIDTH - 10) - MeasureTextEx(GuiGetFont(), "'s turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 50, MeasureTextEx(GuiGetFont(), "'s turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 40}, "'s turn!");
// 		} else {
// 			GuiLabel((Rectangle){(SCREEN_WIDTH - 10) - (MeasureTextEx(GuiGetFont(), " 's turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x) - (MeasureTextEx(GuiGetFont(), array2, GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x), 50, MeasureTextEx(GuiGetFont(), array2, GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x, MeasureTextEx(GuiGetFont(), array2, GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).y}, array2);
//
// 			GuiLabel((Rectangle){(SCREEN_WIDTH - 10) - MeasureTextEx(GuiGetFont(), "'s turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x, 50, MeasureTextEx(GuiGetFont(), "'s turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).x, MeasureTextEx(GuiGetFont(), "'s turn!", GuiGetStyle(DEFAULT, TEXT_SIZE),
// 			GuiGetStyle(DEFAULT, TEXT_SPACING)).y}, "'s turn!");
// 		}
// 	}
}

// void InitBoard(char boardAr[][3])
// {
// 	for (int i = 0; i < 3; i++) {
// 		for (int j = 0; j < 3; j++) {
// 			boardAr[i][j] = '\0';
// 		}
// 	}
// }
//
// void RefreshBoard(const char boardAr[][3])
// {
//
// }