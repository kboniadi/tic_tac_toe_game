#define RAYGUI_IMPLEMENTATION

#include "GAME_DATA.h"
#include <iostream>

void Init_GAME_DATA(GAME_DATA *data)
{
	data->playing_single_player 	= true;
	data->state 					= INSTRUC_PAGE_ID;
	strcpy(data->player_1, "\0");
	strcpy(data->player_2, "\0");
	data->editModeSingle 			= false;
	// data->editModeMulti 			= false;
	// data->normal_checked 			= true;
	// data->hard_checked 				= false;
	data->who_won 					= ' ';
	// data->random_num 				= 0;
	data->whatMode 					= false;
	data->positions 				= 0;
	data->gameOver 					= false;
	data->draw 						= false;
	data->playerMove 				= false;
	data->framesCounter 			= 0;
}

void Delete_GAME_DATA(GAME_DATA *data)
{

}

