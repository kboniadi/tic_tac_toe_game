#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

#include "raylib.h"
#include <iostream>

using namespace std;

void OutputInstruct(const int WIDTH);

bool MouseCollisionInstruct(int &page, int &button1, int &button2,
struct Vector2 mouse, struct Rectangle bounds1, struct Rectangle bounds2);

bool MouseCollisionMain(int &page, int &button2, int &button3, int &button4,
struct Vector2 mouse, struct Rectangle bounds2, struct Rectangle bounds3,
struct Rectangle bounds4);

void MouseButtonCollision(int &page, int &button1, int &button2,
struct Vector2 mouse, struct Rectangle bounds1, struct Rectangle bounds2);

void ResetData(int &char_counter, int &char_counter2, char array1[],
char array2[], const int ARRAY_SIZE, struct Vector2 mouse,
struct Rectangle bounds3, struct Rectangle bounds4);

void TextBoxCollision(struct Rectangle txtBox, struct Vector2 mouse,
bool &mouseHover, bool &mouseClick, int &count, char array[],
const int ARRAY_SIZE, int &fcounter);

void TextBoxDraw(struct Rectangle txtBox, bool mouseHover, bool mouseClick,
int count, char array[], const int ARRAY_SIZE, int fcounter);

void TextBoxDraw2(struct Rectangle txtBox, bool mouseHover, bool mouseClick,
int count, char array[], const int ARRAY_SIZE, int fcounter);

#endif	/* TIC_TAC_TOE_H_ */