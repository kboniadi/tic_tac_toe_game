#ifndef TABLE_PAGE_H_
#define TABLE_PAGE_H_

#include "../LIMITS.h"
#include "../raygui.h"
#include "../GAME_DATA.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

struct TABLE_PAGE {
	GAME_DATA	*data;
	Texture2D	o_token;
	Texture2D	x_token;
};

void Init_TABLE_PAGE(TABLE_PAGE *table_page, GAME_DATA *data);

void Render_TABLE(TABLE_PAGE *table_page);

char CheckWin(TABLE_PAGE *table_page);

void DrawToken(TABLE_PAGE *table_page);

void printWhosGoing(TABLE_PAGE *table_page);

void GetAndCheckInp(TABLE_PAGE *table_page);

void aiMove(TABLE_PAGE *table_page);

void playerinput(TABLE_PAGE *table_page);

void OutputWinner(TABLE_PAGE *table_page);

void Delete_TABLE_PAGE(TABLE_PAGE *table_page);

#endif	/* TABLE_PAGE_H_ */