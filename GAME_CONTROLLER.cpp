#include "GAME_CONTROLLER.h"

void Init_GAME_CONTROLLER(GAME_CONTROLLER *game_controller) {
	srand(time(NULL));

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	SetTargetFPS(FPS);

	Init_GAME_DATA(&game_controller->data);
	Init_INSTRUC_PAGE(&game_controller->instruc_page, &game_controller->data);
	Init_MAIN_PAGE(&game_controller->main_page, &game_controller->data);
	Init_SINGLE_PAGE(&game_controller->single_page, &game_controller->data);
	Init_MULTI_PAGE(&game_controller->multi_page, &game_controller->data);
	Init_TABLE_PAGE(&game_controller->table_page, &game_controller->data);

	game_controller->font = LoadFont("res/fonts/pixantiqua.png");

	GuiSetFont(game_controller->font);
}

void Render_GAME_CONTROLLER(GAME_CONTROLLER *game_controller) {
	BeginDrawing();

	ClearBackground(RAYWHITE);
	game_controller->data.framesCounter++;

	switch (game_controller->data.state) {
	case INSTRUC_PAGE_ID:
		Render_INSTRUC_PAGE(&game_controller->instruc_page);
		break;
	case MAIN_PAGE_ID:
		Render_MAIN_PAGE(&game_controller->main_page);
		break;
	case SINGLE_PAGE_ID:
		Render_SINGLE_PAGE(&game_controller->single_page);
		break;
	case MULTI_PAGE_ID:
		Render_MULTI_PAGE(&game_controller->multi_page);
		break;
	case TABLE_PAGE_ID:
		Render_TABLE(&game_controller->table_page);
		break;
	}

	EndDrawing();
}

bool Run_Loop_GAME_CONTROLLER(GAME_CONTROLLER *game_controller) {
	return !(WindowShouldClose() || game_controller->data.state == EXIT_PAGE_ID);
}

void Delete_GAME_CONTROLLER(GAME_CONTROLLER *game_controller) {
	Delete_GAME_DATA(&game_controller->data);
	Delete_INSTRUC_PAGE(&game_controller->instruc_page);
	Delete_MAIN_PAGE(&game_controller->main_page);
	Delete_SINGLE_PAGE(&game_controller->single_page);
	Delete_MULTI_PAGE(&game_controller->multi_page);
	Delete_TABLE_PAGE(&game_controller->table_page);

	UnloadFont(game_controller->font);

	CloseWindow();
}