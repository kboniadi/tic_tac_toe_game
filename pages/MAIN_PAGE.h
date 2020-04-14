#ifndef MAIN_PAGE_H_
#define MAIN_PAGE_H_

#include <stdio.h>
#include "../raygui.h"
#include "../LIMITS.h"
#include "../GAME_DATA.h"
#include <iostream>

struct MAIN_PAGE {
	GAME_DATA	*data;
	int		random_num;
};

void Init_MAIN_PAGE(MAIN_PAGE *main_page, GAME_DATA *data);

void Render_MAIN_PAGE(MAIN_PAGE *main_page);

void Delete_MAIN_PAGE(MAIN_PAGE *main_page);

void InitBoard(MAIN_PAGE *main_page);

#endif	/* MAIN_PAGE_H_ */