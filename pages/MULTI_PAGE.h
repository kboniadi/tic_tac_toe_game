#ifndef MULTI_PAGE_H_
#define MULTI_PAGE_H_

#include <stdio.h>
#include "../LIMITS.h"
#include "../raygui.h"
#include "../GAME_DATA.h"

struct MULTI_PAGE {
	GAME_DATA	*data;
	bool		editModeMulti;
};

void Init_MULTI_PAGE(MULTI_PAGE *multi_page, GAME_DATA *data);

void Render_MULTI_PAGE(MULTI_PAGE *multi_page);

void Delete_MULTI_PAGE(MULTI_PAGE *multi_page);

#endif	/* MULTI_PAGE_H_ */