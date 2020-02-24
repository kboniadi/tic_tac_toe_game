#define RAYGUI_IMPLEMENTATION
#include "INSTRUC_PAGE.h"

void Render_INSTRUC_PAGE(int &state)
{
	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

	GuiLabel((Rectangle){ 1, 10, 200, 20 }, "This is a game of Tic Tac Toe!");
	GuiLabel((Rectangle){ 1, 30, 200, 20 }, "Each user will be given an option to pick either a X or O token");
	GuiLabel((Rectangle){ 1, 50, 200, 20 }, "Once you have picked a token, each player will alternate");
	GuiLabel((Rectangle){ 1, 70, 200, 20 }, "placing their token down until a row of three is");
	GuiLabel((Rectangle){ 1, 90, 200, 20 }, "achieved or else its a tie.");

	if (GuiButton((Rectangle){ (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 200, BUTTON_WIDTH, BUTTON_HEIGHT}, "Load Game")) {
		state = MAIN_PAGE;
	}

	if (GuiButton((Rectangle){ (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2), 250, BUTTON_WIDTH, BUTTON_HEIGHT}, "Exit")) {
		state = EXIT_PAGE;
	}
}