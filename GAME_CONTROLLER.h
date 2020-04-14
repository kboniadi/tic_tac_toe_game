#ifndef GAME_CONTROLLER_H_
#define GAME_CONTROLLER_H_

#include "GAME_DATA.h"
#include "pages/INSTRUC_PAGE.h"
#include "pages/MAIN_PAGE.h"
#include "pages/SINGLE_PAGE.h"
#include "pages/MULTI_PAGE.h"
#include "pages/TABLE_PAGE.h"

struct GAME_CONTROLLER {
	Font 			font;
	INSTRUC_PAGE		instruc_page;
	MAIN_PAGE		main_page;
	SINGLE_PAGE		single_page;
	MULTI_PAGE		multi_page;
	TABLE_PAGE		table_page;
	GAME_DATA		data;
};

void Init_GAME_CONTROLLER(GAME_CONTROLLER *game_controller);

void Render_GAME_CONTROLLER(GAME_CONTROLLER *game_controller);

bool Run_Loop_GAME_CONTROLLER(GAME_CONTROLLER *game_controller);

void Delete_GAME_CONTROLLER(GAME_CONTROLLER *game_controller);

#endif