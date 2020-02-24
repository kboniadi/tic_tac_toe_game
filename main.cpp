#include "pages/INSTRUC_PAGE.h"
#include "pages/MAIN_PAGE.h"
#include "LIMITS.h"

int main() {
	int state;

	state = INSTRUC_PAGE;

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
		}

        EndDrawing();
    }

    CloseWindow();

    return 0;
}