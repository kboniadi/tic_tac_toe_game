#ifndef SINGLE_PAGE_H_
#define SINGLE_PAGE_H_

#include <stdio.h>
#include "../LIMITS.h"
#include "../raygui.h"
#include "../GAME_DATA.h"
#include <cstring>

struct SINGLE_PAGE {
	GAME_DATA	*data;
	bool		normal_checked;
	bool		hard_checked;
};

void Init_SINGLE_PAGE(SINGLE_PAGE *single_page, GAME_DATA *data);

void Render_SINGLE_PAGE(SINGLE_PAGE *single_page);

void Delete_SINGLE_PAGE(SINGLE_PAGE *single_page);

#endif	/* SINGLE_PAGE_H_ */