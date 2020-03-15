#include "GAME_CONTROLLER.h"
#include <iostream>

int main() {
	GAME_CONTROLLER game_controller;

	Init_GAME_CONTROLLER(&game_controller);

	while (Run_Loop_GAME_CONTROLLER(&game_controller)) {
		Render_GAME_CONTROLLER(&game_controller);
	}

	Delete_GAME_CONTROLLER(&game_controller);

	return 0;
}