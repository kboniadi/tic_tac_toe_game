#include "pages/INSTRUC_PAGE.h"
#include "pages/MAIN_PAGE.h"
#include "pages/SINGLE_PAGE.h"
#include "LIMITS.h"
#include <iostream>

int main() {
	int state;

	state = INSTRUC_PAGE;
	char name[MAX_INPUT_CHARS + 1] = "\0";


	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    SetTargetFPS(FPS);

    while (!(WindowShouldClose() || state == EXIT_PAGE)) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

		switch (state) {
		case INSTRUC_PAGE:
			Render_INSTRUC_PAGE(state);
			break;
		case MAIN_PAGE:
			Render_MAIN_PAGE(state);
			break;
		case SINGLE_PAGE:
			Render_SINGLE_PAGE(name, MAX_INPUT_CHARS);
			for (int i = 0; i < MAX_INPUT_CHARS + 1; i++) {
				std::cout << name[i];
			}
			std::cout << std::endl;
			break;
		}

        EndDrawing();
    }

    CloseWindow();

    return 0;
}