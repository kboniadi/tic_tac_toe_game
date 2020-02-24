//#define RAYGUI_IMPLEMENTATION
//#define RAYGUI_STATIC
#include "TIC_TAC_TOE.h"

void OutputInstruct(const int WIDTH)
{
	DrawText("This is a game of Tic Tac Toe!", 1, 0, 20, BLACK);
	DrawText("Each user will be given an option to pick either a X or O token", 1, 40, 20, BLACK);
	DrawText("Once you have picked a token, each player will alternate", 1, 60, 20, BLACK);
	DrawText("placing their token down until a row of three is", 1, 80, 20, BLACK);
	DrawText("achieved or else its a tie.", 1, 100, 20, BLACK);
}

bool MouseCollisionInstruct(int &page, int &button1, int &button2,
struct Vector2 mouse, struct Rectangle bounds1, struct Rectangle bounds2)
{
	bool exit;

	exit = false;

	if (CheckCollisionPointRec(mouse, bounds1)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button1 = 2;
		} else {
			button1 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			page = 1;
	} else {
		button1 = 0;
	}

	if (CheckCollisionPointRec(mouse, bounds2)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button2 = 2;
		} else {
			button2 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			exit = true;
	} else {
		button2 = 0;
	}

	return exit;
}

bool MouseCollisionMain(int &page, int &button2, int &button3, int &button4,
struct Vector2 mouse, struct Rectangle bounds2, struct Rectangle bounds3,
struct Rectangle bounds4)
{
	bool exit;

	exit = false;

	if (CheckCollisionPointRec(mouse, bounds3)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button3 = 2;
		} else {
			button3 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			page = 2;
	} else {
		button3 = 0;
	}

	if (CheckCollisionPointRec(mouse, bounds4)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button4 = 2;
		} else {
			button4 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			page = 3;
	} else {
		button4 = 0;
	}

	if (CheckCollisionPointRec(mouse, bounds2)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button2 = 2;
		} else {
			button2 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			exit = true;
	} else {
		button2 = 0;
	}

	return exit;
}

void MouseButtonCollision(int &page, int &button1, int &button2,
struct Vector2 mouse, struct Rectangle bounds1, struct Rectangle bounds2)
{
	if (CheckCollisionPointRec(mouse, bounds1)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button1 = 2;
		} else {
			button1 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			page = 4;
	} else {
		button1 = 0;
	}

	if (CheckCollisionPointRec(mouse, bounds2)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			button2 = 2;
		} else {
			button2 = 1;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			page = 1;
	} else {
		button2 = 0;
	}
}

void ResetData(int &char_counter, int &char_counter2, char array1[],
char array2[], const int ARRAY_SIZE, struct Vector2 mouse,
struct Rectangle bounds3, struct Rectangle bounds4)
{
	if (CheckCollisionPointRec(mouse, bounds3)) {
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			char_counter = 0;
			for (int i = 0; i < ARRAY_SIZE; i++) {
				array1[i] = '\0';
			}
		}
	} else if (CheckCollisionPointRec(mouse, bounds4)) {
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			char_counter = 0;
			char_counter2 = 0;
			for (int i = 0; i < ARRAY_SIZE; i++) {
				array1[i] = '\0';
				array2[i] = '\0';
			}
		}
	}
}

void TextBoxCollision(struct Rectangle txtBox, struct Vector2 mouse,
bool &mouseHover, bool &mouseClick, int &count, char array[],
const int ARRAY_SIZE, int &fcounter)
{
	if (CheckCollisionPointRec(mouse, txtBox)) {
		mouseHover = true;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			mouseClick = true;
		}
	} else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		mouseClick = false;
	} else {
		mouseHover = false;
	}

	if (mouseClick) {
		// Get pressed key (character) on the queue
		int key = GetKeyPressed();

		// Check if more characters have been pressed on the same frame
		while (key > 0) {
			// Only allow keys in range [32..125]
			if ((key >= 32) && (key <= 125) && (count < ARRAY_SIZE)) {
				array[count] = (char)key;
				count++;
			}

			key = GetKeyPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE)) {
			count--;
			array[count] = '\0';

			if (count < 0)
				count = 0;
		}
	}

	if (mouseClick)
		fcounter++;
	else
		fcounter = 0;
}

void TextBoxDraw(struct Rectangle txtBox, bool mouseHover, bool mouseClick,
int count, char array[], const int ARRAY_SIZE, int fcounter)
{
	DrawRectangleRec(txtBox, LIGHTGRAY);
	if (mouseHover || mouseClick)
		DrawRectangleLines(txtBox.x, txtBox.y, txtBox.width, txtBox.height, RED);
	else
		DrawRectangleLines(txtBox.x, txtBox.y, txtBox.width, txtBox.height, DARKGRAY);

	DrawText(array, txtBox.x + 5, txtBox.y + 8, 40, MAROON);

	DrawText(FormatText("INPUT CHARS: %i/%i", count, ARRAY_SIZE), txtBox.x, 150, 10, DARKGRAY);

	if (mouseClick) {
		if (count < ARRAY_SIZE) {
			// Draw blinking underscore char
			if (((fcounter/20)%2) == 0)
				DrawText("_", txtBox.x + 8 + MeasureText(array, 40), txtBox.y +
				12, 40, MAROON);
		} else {
			// DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
		}
	}
}

void TextBoxDraw2(struct Rectangle txtBox, bool mouseHover, bool mouseClick,
int count, char array[], const int ARRAY_SIZE, int fcounter)
{
	DrawRectangleRec(txtBox, LIGHTGRAY);
	if (mouseHover || mouseClick)
		DrawRectangleLines(txtBox.x, txtBox.y, txtBox.width, txtBox.height, RED);
	else
		DrawRectangleLines(txtBox.x, txtBox.y, txtBox.width, txtBox.height, DARKGRAY);

	DrawText(array, txtBox.x + 5, txtBox.y + 8, 40, MAROON);

	DrawText(FormatText("INPUT CHARS: %i/%i", count, ARRAY_SIZE), txtBox.x, 230, 10, DARKGRAY);

	if (mouseClick) {
		if (count < ARRAY_SIZE) {
			// Draw blinking underscore char
			if (((fcounter/20)%2) == 0)
				DrawText("_", txtBox.x + 8 + MeasureText(array, 40), txtBox.y + 12, 40, MAROON);
		} else {
			// DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
		}
	}
}