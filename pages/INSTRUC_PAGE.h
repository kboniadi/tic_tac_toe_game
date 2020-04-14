#ifndef INSTRUC_PAGE_H_
#define INSTRUC_PAGE_H_

#include "../GAME_DATA.h"

struct INSTRUC_PAGE {
	GAME_DATA *data;
};

void Init_INSTRUC_PAGE(INSTRUC_PAGE *instruc_page, GAME_DATA *data);

void Render_INSTRUC_PAGE(INSTRUC_PAGE *instruc_page);

void Delete_INSTRUC_PAGE(INSTRUC_PAGE *instruc_page);

#endif	/* INSTRUC_PAGE_H_ */