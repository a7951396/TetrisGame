#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "resource.h"
#include <windows.h>
#include <vector>
#include <thread>
#include <sstream>
//#include <string>
//hi
using namespace sf;
using namespace std;


USHORT colorNum = 1 + rand() % 9; // цвет
USHORT colorNum2 = 1 + rand() % 9; // цвет
USHORT colorNumTemp = 1 + rand() % 9;
Image *LoadImageFromResource(const unsigned short& ID, const char* type);
Texture *LoadTextureFromResource(const unsigned short& ID, const char* type);
Font *LoadFontFromResource(const unsigned short& ID, const char* type);
void fill_tetramino();
void fill_tetramino2();
void draw_3buttons(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3);
void draw_3buttons2(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3);
void draw_3buttons3(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3);
void create_window_for_loading_screen();
//Animation/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Clock animation_1_line;
Clock animation_2_lines;
Clock animation_3_lines;
Clock animation_4_lines;
Clock animation_fast_falling_clock;

vector<USHORT> indexesOfIdLines;
vector<short> numberOfWide;
vector<short> numberOfNarrow;
bool check_space = false;


void animation_1_lineFn(RenderWindow& win, USHORT index, Sprite *spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22);

void animation_2_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5,
	Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11,
	Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17,
	Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22);

void animation_2_lines_with_voidFn(RenderWindow& win, vector<USHORT> &vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22);

void animation_3_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_3lines_1, Sprite* spriteAn_3lines_2, Sprite* spriteAn_3lines_3, Sprite* spriteAn_3lines_4, Sprite* spriteAn_3lines_5,
	Sprite* spriteAn_3lines_6, Sprite* spriteAn_3lines_7, Sprite* spriteAn_3lines_8, Sprite* spriteAn_3lines_9, Sprite* spriteAn_3lines_10, Sprite* spriteAn_3lines_11,
	Sprite* spriteAn_3lines_12, Sprite* spriteAn_3lines_13, Sprite* spriteAn_3lines_14, Sprite* spriteAn_3lines_15, Sprite* spriteAn_3lines_16, Sprite* spriteAn_3lines_17,
	Sprite* spriteAn_3lines_18, Sprite* spriteAn_3lines_19, Sprite* spriteAn_3lines_20, Sprite* spriteAn_3lines_21, Sprite* spriteAn_3lines_22);

void animation_3_lines_with_voidFn(RenderWindow& win, vector<USHORT> &vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5,
	Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11,
	Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17,
	Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22);

void animation_4_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_4lines_1, Sprite* spriteAn_4lines_2, Sprite* spriteAn_4lines_3, Sprite* spriteAn_4lines_4, Sprite* spriteAn_4lines_5,
	Sprite* spriteAn_4lines_6, Sprite* spriteAn_4lines_7, Sprite* spriteAn_4lines_8, Sprite* spriteAn_4lines_9, Sprite* spriteAn_4lines_10, Sprite* spriteAn_4lines_11,
	Sprite* spriteAn_4lines_12, Sprite* spriteAn_4lines_13, Sprite* spriteAn_4lines_14, Sprite* spriteAn_4lines_15, Sprite* spriteAn_4lines_16, Sprite* spriteAn_4lines_17,
	Sprite* spriteAn_4lines_18, Sprite* spriteAn_4lines_19, Sprite* spriteAn_4lines_20, Sprite* spriteAn_4lines_21, Sprite* spriteAn_4lines_22);

void animation_fast_falling_3InRow_16RowsFn(RenderWindow& win, Sprite* An_3_inRow_16Rows_1, Sprite* An_3_inRow_16Rows_2, Sprite* An_3_inRow_16Rows_3, Sprite* An_3_inRow_16Rows_4,
	Sprite* An_3_inRow_16Rows_5, Sprite* An_3_inRow_16Rows_6, Sprite* An_3_inRow_16Rows_7, Sprite* An_3_inRow_16Rows_8, Sprite* An_3_inRow_16Rows_9, Sprite* An_3_inRow_16Rows_10,
	Sprite* An_3_inRow_16Rows_11, Sprite* An_3_inRow_16Rows_12);

void animation_fast_falling_1InRow_1RowFn(RenderWindow& win, Sprite* An_1_inRow_1Row_1, Sprite* An_1_inRow_1Row_2);
void animation_fast_falling_1InRow_2RowsFn(RenderWindow& win, Sprite* An_1_inRow_2Rows_1, Sprite* An_1_inRow_2Rows_2);
void animation_fast_falling_1InRow_3RowsFn(RenderWindow& win, Sprite* An_1_inRow_3Rows_1, Sprite* An_1_inRow_3Rows_2);
void animation_fast_falling_1InRow_4RowsFn(RenderWindow& win, Sprite* An_1_inRow_4Rows_1, Sprite* An_1_inRow_4Rows_2, Sprite* An_1_inRow_4Rows_3, Sprite* An_1_inRow_4Rows_4);
void animation_fast_falling_1InRow_5RowsFn(RenderWindow& win, Sprite* An_1_inRow_5Rows_1, Sprite* An_1_inRow_5Rows_2, Sprite* An_1_inRow_5Rows_3, Sprite* An_1_inRow_5Rows_4);
void animation_fast_falling_1InRow_6RowsFn(RenderWindow& win, Sprite* An_1_inRow_6Rows_1, Sprite* An_1_inRow_6Rows_2, Sprite* An_1_inRow_6Rows_3, Sprite* An_1_inRow_6Rows_4);
void animation_fast_falling_1InRow_7RowsFn(RenderWindow& win, Sprite* An_1_inRow_7Rows_1, Sprite* An_1_inRow_7Rows_2, Sprite* An_1_inRow_7Rows_3, Sprite* An_1_inRow_7Rows_4,
	Sprite* An_1_inRow_7Rows_5, Sprite* An_1_inRow_7Rows_6);
void animation_fast_falling_1InRow_8RowsFn(RenderWindow& win, Sprite* An_1_inRow_8Rows_1, Sprite* An_1_inRow_8Rows_2, Sprite* An_1_inRow_8Rows_3, Sprite* An_1_inRow_8Rows_4,
	Sprite* An_1_inRow_8Rows_5, Sprite* An_1_inRow_8Rows_6);
void animation_fast_falling_1InRow_9RowsFn(RenderWindow& win, Sprite* An_1_inRow_9Rows_1, Sprite* An_1_inRow_9Rows_2, Sprite* An_1_inRow_9Rows_3, Sprite* An_1_inRow_9Rows_4,
	Sprite* An_1_inRow_9Rows_5, Sprite* An_1_inRow_9Rows_6);
void animation_fast_falling_1InRow_10RowsFn(RenderWindow& win, Sprite* An_1_inRow_10Rows_1, Sprite* An_1_inRow_10Rows_2, Sprite* An_1_inRow_10Rows_3, Sprite* An_1_inRow_10Rows_4,
	Sprite* An_1_inRow_10Rows_5, Sprite* An_1_inRow_10Rows_6, Sprite* An_1_inRow_10Rows_7, Sprite* An_1_inRow_10Rows_8);
void animation_fast_falling_1InRow_11RowsFn(RenderWindow& win, Sprite* An_1_inRow_11Rows_1, Sprite* An_1_inRow_11Rows_2, Sprite* An_1_inRow_11Rows_3, Sprite* An_1_inRow_11Rows_4,
	Sprite* An_1_inRow_11Rows_5, Sprite* An_1_inRow_11Rows_6, Sprite* An_1_inRow_11Rows_7, Sprite* An_1_inRow_11Rows_8);
void animation_fast_falling_1InRow_12RowsFn(RenderWindow& win, Sprite* An_1_inRow_12Rows_1, Sprite* An_1_inRow_12Rows_2, Sprite* An_1_inRow_12Rows_3, Sprite* An_1_inRow_12Rows_4,
	Sprite* An_1_inRow_12Rows_5, Sprite* An_1_inRow_12Rows_6, Sprite* An_1_inRow_12Rows_7, Sprite* An_1_inRow_12Rows_8);
void animation_fast_falling_1InRow_13RowsFn(RenderWindow& win, Sprite* An_1_inRow_13Rows_1, Sprite* An_1_inRow_13Rows_2, Sprite* An_1_inRow_13Rows_3, Sprite* An_1_inRow_13Rows_4,
	Sprite* An_1_inRow_13Rows_5, Sprite* An_1_inRow_13Rows_6, Sprite* An_1_inRow_13Rows_7, Sprite* An_1_inRow_13Rows_8, Sprite* An_1_inRow_13Rows_9, Sprite* An_1_inRow_13Rows_10);
void animation_fast_falling_1InRow_14RowsFn(RenderWindow& win, Sprite* An_1_inRow_14Rows_1, Sprite* An_1_inRow_14Rows_2, Sprite* An_1_inRow_14Rows_3, Sprite* An_1_inRow_14Rows_4,
	Sprite* An_1_inRow_14Rows_5, Sprite* An_1_inRow_14Rows_6, Sprite* An_1_inRow_14Rows_7, Sprite* An_1_inRow_14Rows_8, Sprite* An_1_inRow_14Rows_9, Sprite* An_1_inRow_14Rows_10);
void animation_fast_falling_1InRow_15RowsFn(RenderWindow& win, Sprite* An_1_inRow_15Rows_1, Sprite* An_1_inRow_15Rows_2, Sprite* An_1_inRow_15Rows_3, Sprite* An_1_inRow_15Rows_4,
	Sprite* An_1_inRow_15Rows_5, Sprite* An_1_inRow_15Rows_6, Sprite* An_1_inRow_15Rows_7, Sprite* An_1_inRow_15Rows_8, Sprite* An_1_inRow_15Rows_9, Sprite* An_1_inRow_15Rows_10);
void animation_fast_falling_1InRow_16RowsFn(RenderWindow& win, Sprite* An_1_inRow_16Rows_1, Sprite* An_1_inRow_16Rows_2, Sprite* An_1_inRow_16Rows_3, Sprite* An_1_inRow_16Rows_4,
	Sprite* An_1_inRow_16Rows_5, Sprite* An_1_inRow_16Rows_6, Sprite* An_1_inRow_16Rows_7, Sprite* An_1_inRow_16Rows_8, Sprite* An_1_inRow_16Rows_9, Sprite* An_1_inRow_16Rows_10,
	Sprite* An_1_inRow_16Rows_11, Sprite* An_1_inRow_16Rows_12);
void animation_fast_falling_1InRow_17RowsFn(RenderWindow& win, Sprite* An_1_inRow_17Rows_1, Sprite* An_1_inRow_17Rows_2, Sprite* An_1_inRow_17Rows_3, Sprite* An_1_inRow_17Rows_4,
	Sprite* An_1_inRow_17Rows_5, Sprite* An_1_inRow_17Rows_6, Sprite* An_1_inRow_17Rows_7, Sprite* An_1_inRow_17Rows_8, Sprite* An_1_inRow_17Rows_9, Sprite* An_1_inRow_17Rows_10,
	Sprite* An_1_inRow_17Rows_11, Sprite* An_1_inRow_17Rows_12);

void animation_fast_falling_2InRow_1RowFn(RenderWindow& win, Sprite* An_2_inRow_1Row_1, Sprite* An_2_inRow_1Row_2);
void animation_fast_falling_2InRow_2RowsFn(RenderWindow& win, Sprite* An_2_inRow_2Rows_1, Sprite* An_2_inRow_2Rows_2);
void animation_fast_falling_2InRow_3RowsFn(RenderWindow& win, Sprite* An_2_inRow_3Rows_1, Sprite* An_2_inRow_3Rows_2);
void animation_fast_falling_2InRow_4RowsFn(RenderWindow& win, Sprite* An_2_inRow_4Rows_1, Sprite* An_2_inRow_4Rows_2, Sprite* An_2_inRow_4Rows_3, Sprite* An_2_inRow_4Rows_4);
void animation_fast_falling_2InRow_5RowsFn(RenderWindow& win, Sprite* An_2_inRow_5Rows_1, Sprite* An_2_inRow_5Rows_2, Sprite* An_2_inRow_5Rows_3, Sprite* An_2_inRow_5Rows_4);
void animation_fast_falling_2InRow_6RowsFn(RenderWindow& win, Sprite* An_2_inRow_6Rows_1, Sprite* An_2_inRow_6Rows_2, Sprite* An_2_inRow_6Rows_3, Sprite* An_2_inRow_6Rows_4);
void animation_fast_falling_2InRow_7RowsFn(RenderWindow& win, Sprite* An_2_inRow_7Rows_1, Sprite* An_2_inRow_7Rows_2, Sprite* An_2_inRow_7Rows_3, Sprite* An_2_inRow_7Rows_4, Sprite* An_2_inRow_7Rows_5, Sprite* An_2_inRow_7Rows_6);
void animation_fast_falling_2InRow_8RowsFn(RenderWindow& win, Sprite* An_2_inRow_8Rows_1, Sprite* An_2_inRow_8Rows_2, Sprite* An_2_inRow_8Rows_3, Sprite* An_2_inRow_8Rows_4, Sprite* An_2_inRow_8Rows_5, Sprite* An_2_inRow_8Rows_6);
void animation_fast_falling_2InRow_9RowsFn(RenderWindow& win, Sprite* An_2_inRow_9Rows_1, Sprite* An_2_inRow_9Rows_2, Sprite* An_2_inRow_9Rows_3, Sprite* An_2_inRow_9Rows_4, Sprite* An_2_inRow_9Rows_5, Sprite* An_2_inRow_9Rows_6);
void animation_fast_falling_2InRow_10RowsFn(RenderWindow& win, Sprite* An_2_inRow_10Rows_1, Sprite* An_2_inRow_10Rows_2, Sprite* An_2_inRow_10Rows_3, Sprite* An_2_inRow_10Rows_4, Sprite* An_2_inRow_10Rows_5, Sprite* An_2_inRow_10Rows_6, Sprite* An_2_inRow_10Rows_7, Sprite* An_2_inRow_10Rows_8);
void animation_fast_falling_2InRow_11RowsFn(RenderWindow& win, Sprite* An_2_inRow_11Rows_1, Sprite* An_2_inRow_11Rows_2, Sprite* An_2_inRow_11Rows_3, Sprite* An_2_inRow_11Rows_4, Sprite* An_2_inRow_11Rows_5, Sprite* An_2_inRow_11Rows_6, Sprite* An_2_inRow_11Rows_7, Sprite* An_2_inRow_11Rows_8);
void animation_fast_falling_2InRow_12RowsFn(RenderWindow& win, Sprite* An_2_inRow_12Rows_1, Sprite* An_2_inRow_12Rows_2, Sprite* An_2_inRow_12Rows_3, Sprite* An_2_inRow_12Rows_4, Sprite* An_2_inRow_12Rows_5, Sprite* An_2_inRow_12Rows_6, Sprite* An_2_inRow_12Rows_7, Sprite* An_2_inRow_12Rows_8);
void animation_fast_falling_2InRow_13RowsFn(RenderWindow& win, Sprite* An_2_inRow_13Rows_1, Sprite* An_2_inRow_13Rows_2, Sprite* An_2_inRow_13Rows_3, Sprite* An_2_inRow_13Rows_4, Sprite* An_2_inRow_13Rows_5, Sprite* An_2_inRow_13Rows_6, Sprite* An_2_inRow_13Rows_7, Sprite* An_2_inRow_13Rows_8, Sprite* An_2_inRow_13Rows_9, Sprite* An_2_inRow_13Rows_10);
void animation_fast_falling_2InRow_14RowsFn(RenderWindow& win, Sprite* An_2_inRow_14Rows_1, Sprite* An_2_inRow_14Rows_2, Sprite* An_2_inRow_14Rows_3, Sprite* An_2_inRow_14Rows_4, Sprite* An_2_inRow_14Rows_5, Sprite* An_2_inRow_14Rows_6, Sprite* An_2_inRow_14Rows_7, Sprite* An_2_inRow_14Rows_8, Sprite* An_2_inRow_14Rows_9, Sprite* An_2_inRow_14Rows_10);
void animation_fast_falling_2InRow_15RowsFn(RenderWindow& win, Sprite* An_2_inRow_15Rows_1, Sprite* An_2_inRow_15Rows_2, Sprite* An_2_inRow_15Rows_3, Sprite* An_2_inRow_15Rows_4, Sprite* An_2_inRow_15Rows_5, Sprite* An_2_inRow_15Rows_6, Sprite* An_2_inRow_15Rows_7, Sprite* An_2_inRow_15Rows_8, Sprite* An_2_inRow_15Rows_9, Sprite* An_2_inRow_15Rows_10);
void animation_fast_falling_2InRow_16RowsFn(RenderWindow& win, Sprite* An_2_inRow_16Rows_1, Sprite* An_2_inRow_16Rows_2, Sprite* An_2_inRow_16Rows_3, Sprite* An_2_inRow_16Rows_4, Sprite* An_2_inRow_16Rows_5, Sprite* An_2_inRow_16Rows_6, Sprite* An_2_inRow_16Rows_7, Sprite* An_2_inRow_16Rows_8, Sprite* An_2_inRow_16Rows_9, Sprite* An_2_inRow_16Rows_10, Sprite* An_2_inRow_16Rows_11, Sprite* An_2_inRow_16Rows_12);
void animation_fast_falling_2InRow_17RowsFn(RenderWindow& win, Sprite* An_2_inRow_17Rows_1, Sprite* An_2_inRow_17Rows_2, Sprite* An_2_inRow_17Rows_3, Sprite* An_2_inRow_17Rows_4, Sprite* An_2_inRow_17Rows_5, Sprite* An_2_inRow_17Rows_6, Sprite* An_2_inRow_17Rows_7, Sprite* An_2_inRow_17Rows_8, Sprite* An_2_inRow_17Rows_9, Sprite* An_2_inRow_17Rows_10, Sprite* An_2_inRow_17Rows_11, Sprite* An_2_inRow_17Rows_12);

void animation_fast_falling_3InRow_1RowFn(RenderWindow& win, Sprite* An_3_inRow_1Row_1, Sprite* An_3_inRow_1Row_2);
void animation_fast_falling_3InRow_2RowsFn(RenderWindow& win, Sprite* An_3_inRow_2Rows_1, Sprite* An_3_inRow_2Rows_2);
void animation_fast_falling_3InRow_3RowsFn(RenderWindow& win, Sprite* An_3_inRow_3Rows_1, Sprite* An_3_inRow_3Rows_2);
void animation_fast_falling_3InRow_4RowsFn(RenderWindow& win, Sprite* An_3_inRow_4Rows_1, Sprite* An_3_inRow_4Rows_2, Sprite* An_3_inRow_4Rows_3, Sprite* An_3_inRow_4Rows_4);
void animation_fast_falling_3InRow_5RowsFn(RenderWindow& win, Sprite* An_3_inRow_5Rows_1, Sprite* An_3_inRow_5Rows_2, Sprite* An_3_inRow_5Rows_3, Sprite* An_3_inRow_5Rows_4);
void animation_fast_falling_3InRow_6RowsFn(RenderWindow& win, Sprite* An_3_inRow_6Rows_1, Sprite* An_3_inRow_6Rows_2, Sprite* An_3_inRow_6Rows_3, Sprite* An_3_inRow_6Rows_4);
void animation_fast_falling_3InRow_7RowsFn(RenderWindow& win, Sprite* An_3_inRow_7Rows_1, Sprite* An_3_inRow_7Rows_2, Sprite* An_3_inRow_7Rows_3, Sprite* An_3_inRow_7Rows_4, Sprite* An_3_inRow_7Rows_5, Sprite* An_3_inRow_7Rows_6);
void animation_fast_falling_3InRow_8RowsFn(RenderWindow& win, Sprite* An_3_inRow_8Rows_1, Sprite* An_3_inRow_8Rows_2, Sprite* An_3_inRow_8Rows_3, Sprite* An_3_inRow_8Rows_4, Sprite* An_3_inRow_8Rows_5, Sprite* An_3_inRow_8Rows_6);
void animation_fast_falling_3InRow_9RowsFn(RenderWindow& win, Sprite* An_3_inRow_9Rows_1, Sprite* An_3_inRow_9Rows_2, Sprite* An_3_inRow_9Rows_3, Sprite* An_3_inRow_9Rows_4, Sprite* An_3_inRow_9Rows_5, Sprite* An_3_inRow_9Rows_6);
void animation_fast_falling_3InRow_10RowsFn(RenderWindow& win, Sprite* An_3_inRow_10Rows_1, Sprite* An_3_inRow_10Rows_2, Sprite* An_3_inRow_10Rows_3, Sprite* An_3_inRow_10Rows_4, Sprite* An_3_inRow_10Rows_5, Sprite* An_3_inRow_10Rows_6, Sprite* An_3_inRow_10Rows_7, Sprite* An_3_inRow_10Rows_8);
void animation_fast_falling_3InRow_11RowsFn(RenderWindow& win, Sprite* An_3_inRow_11Rows_1, Sprite* An_3_inRow_11Rows_2, Sprite* An_3_inRow_11Rows_3, Sprite* An_3_inRow_11Rows_4, Sprite* An_3_inRow_11Rows_5, Sprite* An_3_inRow_11Rows_6, Sprite* An_3_inRow_11Rows_7, Sprite* An_3_inRow_11Rows_8);
void animation_fast_falling_3InRow_12RowsFn(RenderWindow& win, Sprite* An_3_inRow_12Rows_1, Sprite* An_3_inRow_12Rows_2, Sprite* An_3_inRow_12Rows_3, Sprite* An_3_inRow_12Rows_4, Sprite* An_3_inRow_12Rows_5, Sprite* An_3_inRow_12Rows_6, Sprite* An_3_inRow_12Rows_7, Sprite* An_3_inRow_12Rows_8);
void animation_fast_falling_3InRow_13RowsFn(RenderWindow& win, Sprite* An_3_inRow_13Rows_1, Sprite* An_3_inRow_13Rows_2, Sprite* An_3_inRow_13Rows_3, Sprite* An_3_inRow_13Rows_4, Sprite* An_3_inRow_13Rows_5, Sprite* An_3_inRow_13Rows_6, Sprite* An_3_inRow_13Rows_7, Sprite* An_3_inRow_13Rows_8, Sprite* An_3_inRow_13Rows_9, Sprite* An_3_inRow_13Rows_10);
void animation_fast_falling_3InRow_14RowsFn(RenderWindow& win, Sprite* An_3_inRow_14Rows_1, Sprite* An_3_inRow_14Rows_2, Sprite* An_3_inRow_14Rows_3, Sprite* An_3_inRow_14Rows_4, Sprite* An_3_inRow_14Rows_5, Sprite* An_3_inRow_14Rows_6, Sprite* An_3_inRow_14Rows_7, Sprite* An_3_inRow_14Rows_8, Sprite* An_3_inRow_14Rows_9, Sprite* An_3_inRow_14Rows_10);
void animation_fast_falling_3InRow_15RowsFn(RenderWindow& win, Sprite* An_3_inRow_15Rows_1, Sprite* An_3_inRow_15Rows_2, Sprite* An_3_inRow_15Rows_3, Sprite* An_3_inRow_15Rows_4, Sprite* An_3_inRow_15Rows_5, Sprite* An_3_inRow_15Rows_6, Sprite* An_3_inRow_15Rows_7, Sprite* An_3_inRow_15Rows_8, Sprite* An_3_inRow_15Rows_9, Sprite* An_3_inRow_15Rows_10);
void animation_fast_falling_3InRow_17RowsFn(RenderWindow& win, Sprite* An_3_inRow_17Rows_1, Sprite* An_3_inRow_17Rows_2, Sprite* An_3_inRow_17Rows_3, Sprite* An_3_inRow_17Rows_4, Sprite* An_3_inRow_17Rows_5, Sprite* An_3_inRow_17Rows_6, Sprite* An_3_inRow_17Rows_7, Sprite* An_3_inRow_17Rows_8, Sprite* An_3_inRow_17Rows_9, Sprite* An_3_inRow_17Rows_10, Sprite* An_3_inRow_17Rows_11, Sprite* An_3_inRow_17Rows_12);
void animation_fast_falling_3InRow_18RowsFn(RenderWindow& win, Sprite* An_3_inRow_18Rows_1, Sprite* An_3_inRow_18Rows_2, Sprite* An_3_inRow_18Rows_3, Sprite* An_3_inRow_18Rows_4, Sprite* An_3_inRow_18Rows_5, Sprite* An_3_inRow_18Rows_6, Sprite* An_3_inRow_18Rows_7, Sprite* An_3_inRow_18Rows_8, Sprite* An_3_inRow_18Rows_9, Sprite* An_3_inRow_18Rows_10, Sprite* An_3_inRow_18Rows_11, Sprite* An_3_inRow_18Rows_12);

void animation_fast_falling_4InRow_1RowFn(RenderWindow& win, Sprite* An_4_inRow_1Row_1, Sprite* An_4_inRow_1Row_2);
void animation_fast_falling_4InRow_2RowsFn(RenderWindow& win, Sprite* An_4_inRow_2Rows_1, Sprite* An_4_inRow_2Rows_2);
void animation_fast_falling_4InRow_3RowsFn(RenderWindow& win, Sprite* An_4_inRow_3Rows_1, Sprite* An_4_inRow_3Rows_2);
void animation_fast_falling_4InRow_4RowsFn(RenderWindow& win, Sprite* An_4_inRow_4Rows_1, Sprite* An_4_inRow_4Rows_2, Sprite* An_4_inRow_4Rows_3, Sprite* An_4_inRow_4Rows_4);
void animation_fast_falling_4InRow_5RowsFn(RenderWindow& win, Sprite* An_4_inRow_5Rows_1, Sprite* An_4_inRow_5Rows_2, Sprite* An_4_inRow_5Rows_3, Sprite* An_4_inRow_5Rows_4);
void animation_fast_falling_4InRow_6RowsFn(RenderWindow& win, Sprite* An_4_inRow_6Rows_1, Sprite* An_4_inRow_6Rows_2, Sprite* An_4_inRow_6Rows_3, Sprite* An_4_inRow_6Rows_4);
void animation_fast_falling_4InRow_7RowsFn(RenderWindow& win, Sprite* An_4_inRow_7Rows_1, Sprite* An_4_inRow_7Rows_2, Sprite* An_4_inRow_7Rows_3, Sprite* An_4_inRow_7Rows_4, Sprite* An_4_inRow_7Rows_5, Sprite* An_4_inRow_7Rows_6);
void animation_fast_falling_4InRow_8RowsFn(RenderWindow& win, Sprite* An_4_inRow_8Rows_1, Sprite* An_4_inRow_8Rows_2, Sprite* An_4_inRow_8Rows_3, Sprite* An_4_inRow_8Rows_4, Sprite* An_4_inRow_8Rows_5, Sprite* An_4_inRow_8Rows_6);
void animation_fast_falling_4InRow_9RowsFn(RenderWindow& win, Sprite* An_4_inRow_9Rows_1, Sprite* An_4_inRow_9Rows_2, Sprite* An_4_inRow_9Rows_3, Sprite* An_4_inRow_9Rows_4, Sprite* An_4_inRow_9Rows_5, Sprite* An_4_inRow_9Rows_6);
void animation_fast_falling_4InRow_10RowsFn(RenderWindow& win, Sprite* An_4_inRow_10Rows_1, Sprite* An_4_inRow_10Rows_2, Sprite* An_4_inRow_10Rows_3, Sprite* An_4_inRow_10Rows_4, Sprite* An_4_inRow_10Rows_5, Sprite* An_4_inRow_10Rows_6, Sprite* An_4_inRow_10Rows_7, Sprite* An_4_inRow_10Rows_8);
void animation_fast_falling_4InRow_11RowsFn(RenderWindow& win, Sprite* An_4_inRow_11Rows_1, Sprite* An_4_inRow_11Rows_2, Sprite* An_4_inRow_11Rows_3, Sprite* An_4_inRow_11Rows_4, Sprite* An_4_inRow_11Rows_5, Sprite* An_4_inRow_11Rows_6, Sprite* An_4_inRow_11Rows_7, Sprite* An_4_inRow_11Rows_8);
void animation_fast_falling_4InRow_12RowsFn(RenderWindow& win, Sprite* An_4_inRow_12Rows_1, Sprite* An_4_inRow_12Rows_2, Sprite* An_4_inRow_12Rows_3, Sprite* An_4_inRow_12Rows_4, Sprite* An_4_inRow_12Rows_5, Sprite* An_4_inRow_12Rows_6, Sprite* An_4_inRow_12Rows_7, Sprite* An_4_inRow_12Rows_8);
void animation_fast_falling_4InRow_13RowsFn(RenderWindow& win, Sprite* An_4_inRow_13Rows_1, Sprite* An_4_inRow_13Rows_2, Sprite* An_4_inRow_13Rows_3, Sprite* An_4_inRow_13Rows_4, Sprite* An_4_inRow_13Rows_5, Sprite* An_4_inRow_13Rows_6, Sprite* An_4_inRow_13Rows_7, Sprite* An_4_inRow_13Rows_8, Sprite* An_4_inRow_13Rows_9, Sprite* An_4_inRow_13Rows_10);
void animation_fast_falling_4InRow_14RowsFn(RenderWindow& win, Sprite* An_4_inRow_14Rows_1, Sprite* An_4_inRow_14Rows_2, Sprite* An_4_inRow_14Rows_3, Sprite* An_4_inRow_14Rows_4, Sprite* An_4_inRow_14Rows_5, Sprite* An_4_inRow_14Rows_6, Sprite* An_4_inRow_14Rows_7, Sprite* An_4_inRow_14Rows_8, Sprite* An_4_inRow_14Rows_9, Sprite* An_4_inRow_14Rows_10);
void animation_fast_falling_4InRow_15RowsFn(RenderWindow& win, Sprite* An_4_inRow_15Rows_1, Sprite* An_4_inRow_15Rows_2, Sprite* An_4_inRow_15Rows_3, Sprite* An_4_inRow_15Rows_4, Sprite* An_4_inRow_15Rows_5, Sprite* An_4_inRow_15Rows_6, Sprite* An_4_inRow_15Rows_7, Sprite* An_4_inRow_15Rows_8, Sprite* An_4_inRow_15Rows_9, Sprite* An_4_inRow_15Rows_10);
void animation_fast_falling_4InRow_16RowsFn(RenderWindow& win, Sprite* An_4_inRow_16Rows_1, Sprite* An_4_inRow_16Rows_2, Sprite* An_4_inRow_16Rows_3, Sprite* An_4_inRow_16Rows_4, Sprite* An_4_inRow_16Rows_5, Sprite* An_4_inRow_16Rows_6, Sprite* An_4_inRow_16Rows_7, Sprite* An_4_inRow_16Rows_8, Sprite* An_4_inRow_16Rows_9, Sprite* An_4_inRow_16Rows_10, Sprite* An_4_inRow_16Rows_11, Sprite* An_4_inRow_16Rows_12);
void animation_fast_falling_4InRow_17RowsFn(RenderWindow& win, Sprite* An_4_inRow_17Rows_1, Sprite* An_4_inRow_17Rows_2, Sprite* An_4_inRow_17Rows_3, Sprite* An_4_inRow_17Rows_4, Sprite* An_4_inRow_17Rows_5, Sprite* An_4_inRow_17Rows_6, Sprite* An_4_inRow_17Rows_7, Sprite* An_4_inRow_17Rows_8, Sprite* An_4_inRow_17Rows_9, Sprite* An_4_inRow_17Rows_10, Sprite* An_4_inRow_17Rows_11, Sprite* An_4_inRow_17Rows_12);
void animation_fast_falling_4InRow_18RowsFn(RenderWindow& win, Sprite* An_4_inRow_18Rows_1, Sprite* An_4_inRow_18Rows_2, Sprite* An_4_inRow_18Rows_3, Sprite* An_4_inRow_18Rows_4, Sprite* An_4_inRow_18Rows_5, Sprite* An_4_inRow_18Rows_6, Sprite* An_4_inRow_18Rows_7, Sprite* An_4_inRow_18Rows_8, Sprite* An_4_inRow_18Rows_9, Sprite* An_4_inRow_18Rows_10, Sprite* An_4_inRow_18Rows_11, Sprite* An_4_inRow_18Rows_12);


bool enableAnimation1line = false;
bool enableAnimation3lines_with_void = false;
bool enableAnimation2lines_with_void = false;
bool enableAnimation2lines = false;
bool enableAnimation3lines = false;
bool enableAnimation4lines = false;
bool enableAnimation_fast_falling_3InRow_16Rows = false;
bool enableAnimation_fast_falling_1InRow_1Row = false;
bool enableAnimation_fast_falling_1InRow_2Rows = false;
bool enableAnimation_fast_falling_1InRow_3Rows = false;
bool enableAnimation_fast_falling_1InRow_4Rows = false;
bool enableAnimation_fast_falling_1InRow_5Rows = false;
bool enableAnimation_fast_falling_1InRow_6Rows = false;
bool enableAnimation_fast_falling_1InRow_7Rows = false;
bool enableAnimation_fast_falling_1InRow_8Rows = false;
bool enableAnimation_fast_falling_1InRow_9Rows = false;
bool enableAnimation_fast_falling_1InRow_10Rows = false;
bool enableAnimation_fast_falling_1InRow_11Rows = false;
bool enableAnimation_fast_falling_1InRow_12Rows = false;
bool enableAnimation_fast_falling_1InRow_13Rows = false;
bool enableAnimation_fast_falling_1InRow_14Rows = false;
bool enableAnimation_fast_falling_1InRow_15Rows = false;
bool enableAnimation_fast_falling_1InRow_16Rows = false;
bool enableAnimation_fast_falling_1InRow_17Rows = false;
bool enableAnimation_fast_falling_2InRow_1Row = false;
bool enableAnimation_fast_falling_2InRow_2Rows = false;
bool enableAnimation_fast_falling_2InRow_3Rows = false;
bool enableAnimation_fast_falling_2InRow_4Rows = false;
bool enableAnimation_fast_falling_2InRow_5Rows = false;
bool enableAnimation_fast_falling_2InRow_6Rows = false;
bool enableAnimation_fast_falling_2InRow_7Rows = false;
bool enableAnimation_fast_falling_2InRow_8Rows = false;
bool enableAnimation_fast_falling_2InRow_9Rows = false;
bool enableAnimation_fast_falling_2InRow_10Rows = false;
bool enableAnimation_fast_falling_2InRow_11Rows = false;
bool enableAnimation_fast_falling_2InRow_12Rows = false;
bool enableAnimation_fast_falling_2InRow_13Rows = false;
bool enableAnimation_fast_falling_2InRow_14Rows = false;
bool enableAnimation_fast_falling_2InRow_15Rows = false;
bool enableAnimation_fast_falling_2InRow_16Rows = false;
bool enableAnimation_fast_falling_2InRow_17Rows = false;
bool enableAnimation_fast_falling_3InRow_1Row = false;
bool enableAnimation_fast_falling_3InRow_2Rows = false;
bool enableAnimation_fast_falling_3InRow_3Rows = false;
bool enableAnimation_fast_falling_3InRow_4Rows = false;
bool enableAnimation_fast_falling_3InRow_5Rows = false;
bool enableAnimation_fast_falling_3InRow_6Rows = false;
bool enableAnimation_fast_falling_3InRow_7Rows = false;
bool enableAnimation_fast_falling_3InRow_8Rows = false;
bool enableAnimation_fast_falling_3InRow_9Rows = false;
bool enableAnimation_fast_falling_3InRow_10Rows = false;
bool enableAnimation_fast_falling_3InRow_11Rows = false;
bool enableAnimation_fast_falling_3InRow_12Rows = false;
bool enableAnimation_fast_falling_3InRow_13Rows = false;
bool enableAnimation_fast_falling_3InRow_14Rows = false;
bool enableAnimation_fast_falling_3InRow_15Rows = false;
bool enableAnimation_fast_falling_3InRow_17Rows = false;
bool enableAnimation_fast_falling_3InRow_18Rows = false;
bool enableAnimation_fast_falling_4InRow_1Row = false;
bool enableAnimation_fast_falling_4InRow_2Rows = false;
bool enableAnimation_fast_falling_4InRow_3Rows = false;
bool enableAnimation_fast_falling_4InRow_4Rows = false;
bool enableAnimation_fast_falling_4InRow_5Rows = false;
bool enableAnimation_fast_falling_4InRow_6Rows = false;
bool enableAnimation_fast_falling_4InRow_7Rows = false;
bool enableAnimation_fast_falling_4InRow_8Rows = false;
bool enableAnimation_fast_falling_4InRow_9Rows = false;
bool enableAnimation_fast_falling_4InRow_10Rows = false;
bool enableAnimation_fast_falling_4InRow_11Rows = false;
bool enableAnimation_fast_falling_4InRow_12Rows = false;
bool enableAnimation_fast_falling_4InRow_13Rows = false;
bool enableAnimation_fast_falling_4InRow_14Rows = false;
bool enableAnimation_fast_falling_4InRow_15Rows = false;
bool enableAnimation_fast_falling_4InRow_16Rows = false;
bool enableAnimation_fast_falling_4InRow_17Rows = false;
bool enableAnimation_fast_falling_4InRow_18Rows = false;
bool afterAnimationLine = false;
bool afterAnimationFF = false;
bool progressOfAnimationLines = false;
bool progressOfAnimationFF = false;
bool forFigureBot = false;
//bool checkFoаrFigureBot = true; //чтобы не не вызывалась отрисовка фигуры снизу несколько раз
bool sameStructsAE = false;
USHORT numberOfIdenticalLines = 0; //число одинаковых линий
USHORT indexOfLastLine = 0;
//USHORT numberOfLanes{ 0 };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
string ToString(T tX);
bool check();
bool checkField();
bool checkForPrototype();
bool checkForPrototypeField();
bool checkForPrototypeHeight();
bool checkForPrototypeLeftSide();
bool checkForPrototypeRightSide();
bool checkForPrototypeTop();

//const USHORT H{ 20 }; // высота игрового поля
const USHORT H{ 20 }; // высота игрового поля
const USHORT W{ 10 }; // ширина игрового поля
USHORT n = rand() % 7; // тип тетрамино
USHORT typeOfTetramino1; //для нижнего поля - для поворота фигур, для фигуры квадрат
USHORT typeOfTetramino2;
USHORT nTemp1 = rand() % 7;
//USHORT countOfSameStruct = 0; //для подсчета одинаковых координат структур, чтобы не поворачивались прототипы//походу это не пригодилось
USHORT countOfSamePos = 0;
//short n = 0;
bool beginGame = true;
bool beginGame2 = true; // для прототипа фигур
bool beginGame3 = true; // для анимации FF
USHORT field[H][W] = { 0 }; // игровое поле

// Массив фигурок-тетрамино
USHORT figures[7][4] =
{
	1,3,5,7, // I
	2,4,5,7, // S
	3,5,4,6, // Z
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};


struct Point
{
	short x, y; //не менять тип
} a[4], b[4], c[4], d[4], e[4], f[4], j[4], h[4];

void falling_down(Point* j, Point* e);//прототип функции для падения вниз предварительной фигуры
void checkFullLineFn(USHORT field [H][W]);
void checkFullLineFn2(USHORT field[H][W]);
//СДЕЛАТЬ ПРОВЕРКУ НА ПУСТЫЕ СТРОКИ В ЦИКЛЕ!!! Уже не актуально

bool nOfSameStructsFn(Point* struct1, Point* struct2); // для подсчета на равенство структур a и e


int main()
//int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{

	//thread* thr1 = new thread(create_window_for_loading_screen);
	//cout << 4 % 4 << endl;
	bool startGame{ false };
	bool checkAus{ false };
	bool pauseBreak{ false };
	bool pause_resume_button{ false };
	bool start_newGame_button{ false };
	bool soundOn_sounOff_button{ true };
	bool musicOn_musicOff_button{ true };
	bool checkFullLine{ false };
	bool stopPrototypeRotate{ false };
	bool isLeftButton{ false };
	bool isRightButton{ false };
	bool isMiddleButton{ false };
	numberOfWide.push_back(0);
	numberOfNarrow.push_back(1);
	//if (CreateScalableFontResource(0, "scale.fot", "ERASBD.TTF", "E:\\CPP\\Projects on VS\\TetrisTheGame"))
	//	cout << "success" << endl;

	/*
	// Для получения разрешения экрана напишите следующий код:
	 HDC hDCScreen = GetDC(NULL);
	int Horres = GetDeviceCaps(hDCScreen, HORZRES);
	int Vertres = GetDeviceCaps(hDCScreen, VERTRES);
	ReleaseDC(NULL, hDCScreen);
	// в Horres содержится разрешение экрана по горизонтали,
	// в Vertres содержится разрешение экрана по вертикали.
	cout << Horres << endl << Vertres << endl;
	VideoMode mode;
	*/

	// Объект, который является главным окном приложения

	/*RenderWindow window(VideoMode(700, 800), "brick", Style::Close | Style::Titlebar | Style::Fullscreen);
	Image* icon = LoadImageFromResource(IDB_PNG1, "PNG");
	window.setIcon(38, 38, icon->getPixelsPtr());*/

	//RenderWindow window(VideoMode(1280, 1100), "Space Tetris", Style::Close | Style::Titlebar);
	//window.setVerticalSyncEnabled(true);
	
	//window.setFramerateLimit(350);
	//cout <<window.getSize().x<< endl;
	//window.setPosition(Vector2i(1200, 0));

	

	

	//Создание текстур
	Texture *sqtex = new Texture, *tex_table = new Texture;
	Texture* tex_background, * button_start_st1, * button_start_st2, * button_start_st3, * button_newgame_st1, * button_newgame_st2, * button_newgame_st3,
		* button_options_st1, * button_options_st2, * button_options_st3, * button_left_st1, * button_left_st2, * button_left_st3, * button_right_st1, * button_right_st2, * button_right_st3,
		* button_middle_restore_st1, * button_middle_restore_st2, * button_middle_restore_st3, * button_pause_st1, * button_pause_st2, * button_pause_st3, * button_pause_st4,
		* button_soundOff_st1, * button_soundOff_st2, * button_soundOff_st3, * left_frame, * right_frame, * right_frame_bottom, * ays_frame, * ays_question, * ays_yes1st, * ays_yes2st, * ays_no1st, * ays_no2st,
		* button_resume_st1, * button_resume_st2, * button_resume_st3, * button_musicOff_st1, * button_musicOff_st2, * button_musicOff_st3, * button_musicOn_st1, * button_musicOn_st2, * button_musicOn_st3, * button_musicOn_st4,
		* button_soundOn_st1, * button_soundOn_st2, * button_soundOn_st3, * button_soundOn_st4, * I_red, * S_red, * Z_red, * T_red, * L_red, * J_red, * O_red, * I_blue, * S_blue, * Z_blue, * T_blue, * L_blue,
		* J_blue, * O_blue, * I_black, * S_black, * Z_black, * T_black, * L_black, * J_black, * O_black, * I_brown, * S_brown, * Z_brown, * T_brown, * L_brown, * J_brown, * O_brown,
		* I_orange, * S_orange, * Z_orange, * T_orange, * L_orange, * J_orange, * O_orange, * I_green, * S_green, * Z_green, * T_green, * L_green, * J_green, * O_green,
		* I_purple, * S_purple, * Z_purple, * T_purple, * L_purple, * J_purple, * O_purple, * I_pink, * S_pink, * Z_pink, * T_pink, * L_pink, * J_pink, * O_pink,
		* I_yellow, * S_yellow, * Z_yellow, * T_yellow, * L_yellow, * J_yellow, * O_yellow, * myCursor,
		* An_1line_1, * An_1line_2, * An_1line_3, * An_1line_4, * An_1line_5, * An_1line_6, * An_1line_7, * An_1line_8, * An_1line_9, * An_1line_10, * An_1line_11,
		* An_1line_12, * An_1line_13, * An_1line_14, * An_1line_15, * An_1line_16, * An_1line_17, * An_1line_18, * An_1line_19, * An_1line_20, * An_1line_21, * An_1line_22,
		* An_2lines_1, * An_2lines_2, * An_2lines_3, * An_2lines_4, * An_2lines_5, * An_2lines_6, * An_2lines_7, * An_2lines_8, * An_2lines_9, * An_2lines_10,
		* An_2lines_11, * An_2lines_12, * An_2lines_13, * An_2lines_14, * An_2lines_15, * An_2lines_16, * An_2lines_17, * An_2lines_18, * An_2lines_19, * An_2lines_20,
		* An_2lines_21, * An_2lines_22,
		* An_3lines_1, * An_3lines_2, * An_3lines_3, * An_3lines_4, * An_3lines_5, * An_3lines_6, * An_3lines_7, * An_3lines_8, * An_3lines_9, * An_3lines_10,
		* An_3lines_11, * An_3lines_12, * An_3lines_13, * An_3lines_14, * An_3lines_15, * An_3lines_16, * An_3lines_17, * An_3lines_18, * An_3lines_19,
		* An_3lines_20, * An_3lines_21, * An_3lines_22,
		* An_4lines_1, * An_4lines_2, * An_4lines_3, * An_4lines_4, * An_4lines_5, * An_4lines_6, * An_4lines_7, * An_4lines_8, * An_4lines_9, * An_4lines_10,
		* An_4lines_11, * An_4lines_12, * An_4lines_13, * An_4lines_14, * An_4lines_15, * An_4lines_16, * An_4lines_17, * An_4lines_18, * An_4lines_19, * An_4lines_20,
		* An_4lines_21, * An_4lines_22,
		/** An_3_inRow_16Rows_1, * An_3_inRow_16Rows_2, * An_3_inRow_16Rows_3, * An_3_inRow_16Rows_4, * An_3_inRow_16Rows_5, * An_3_inRow_16Rows_6, * An_3_inRow_16Rows_7,
		* An_3_inRow_16Rows_8, * An_3_inRow_16Rows_9, * An_3_inRow_16Rows_10, * An_3_inRow_16Rows_11, * An_3_inRow_16Rows_12,*/
		* An_1_inRow_1Row_1, * An_1_inRow_1Row_2,
		* An_1_inRow_2Rows_1, * An_1_inRow_2Rows_2,
		* An_1_inRow_3Rows_1, * An_1_inRow_3Rows_2,
		* An_1_inRow_4Rows_1, * An_1_inRow_4Rows_2, * An_1_inRow_4Rows_3, * An_1_inRow_4Rows_4,
		* An_1_inRow_5Rows_1, * An_1_inRow_5Rows_2, * An_1_inRow_5Rows_3, * An_1_inRow_5Rows_4,
		* An_1_inRow_6Rows_1, * An_1_inRow_6Rows_2, * An_1_inRow_6Rows_3, * An_1_inRow_6Rows_4,
		* An_1_inRow_7Rows_1, * An_1_inRow_7Rows_2, * An_1_inRow_7Rows_3, * An_1_inRow_7Rows_4, * An_1_inRow_7Rows_5, * An_1_inRow_7Rows_6,
		* An_1_inRow_8Rows_1, * An_1_inRow_8Rows_2, * An_1_inRow_8Rows_3, * An_1_inRow_8Rows_4, * An_1_inRow_8Rows_5, * An_1_inRow_8Rows_6,
		* An_1_inRow_9Rows_1, * An_1_inRow_9Rows_2, * An_1_inRow_9Rows_3, * An_1_inRow_9Rows_4, * An_1_inRow_9Rows_5, * An_1_inRow_9Rows_6,
		* An_1_inRow_10Rows_1, * An_1_inRow_10Rows_2, * An_1_inRow_10Rows_3, * An_1_inRow_10Rows_4, * An_1_inRow_10Rows_5, * An_1_inRow_10Rows_6, * An_1_inRow_10Rows_7,
		* An_1_inRow_10Rows_8,
		* An_1_inRow_11Rows_1, * An_1_inRow_11Rows_2, * An_1_inRow_11Rows_3, * An_1_inRow_11Rows_4, * An_1_inRow_11Rows_5, * An_1_inRow_11Rows_6, * An_1_inRow_11Rows_7,
		* An_1_inRow_11Rows_8,
		* An_1_inRow_12Rows_1, * An_1_inRow_12Rows_2, * An_1_inRow_12Rows_3, * An_1_inRow_12Rows_4, * An_1_inRow_12Rows_5, * An_1_inRow_12Rows_6, * An_1_inRow_12Rows_7,
		* An_1_inRow_12Rows_8,
		* An_1_inRow_13Rows_1, * An_1_inRow_13Rows_2, * An_1_inRow_13Rows_3, * An_1_inRow_13Rows_4, * An_1_inRow_13Rows_5, * An_1_inRow_13Rows_6, * An_1_inRow_13Rows_7,
		* An_1_inRow_13Rows_8, * An_1_inRow_13Rows_9, * An_1_inRow_13Rows_10,
		* An_1_inRow_14Rows_1, * An_1_inRow_14Rows_2, * An_1_inRow_14Rows_3, * An_1_inRow_14Rows_4, * An_1_inRow_14Rows_5, * An_1_inRow_14Rows_6, * An_1_inRow_14Rows_7,
		* An_1_inRow_14Rows_8, * An_1_inRow_14Rows_9, * An_1_inRow_14Rows_10,
		* An_1_inRow_15Rows_1, * An_1_inRow_15Rows_2, * An_1_inRow_15Rows_3, * An_1_inRow_15Rows_4, * An_1_inRow_15Rows_5, * An_1_inRow_15Rows_6, * An_1_inRow_15Rows_7,
		* An_1_inRow_15Rows_8, * An_1_inRow_15Rows_9, * An_1_inRow_15Rows_10,
		* An_1_inRow_16Rows_1, * An_1_inRow_16Rows_2, * An_1_inRow_16Rows_3, * An_1_inRow_16Rows_4, * An_1_inRow_16Rows_5, * An_1_inRow_16Rows_6, * An_1_inRow_16Rows_7,
		* An_1_inRow_16Rows_8, * An_1_inRow_16Rows_9, * An_1_inRow_16Rows_10, * An_1_inRow_16Rows_11, * An_1_inRow_16Rows_12,
		* An_1_inRow_17Rows_1, * An_1_inRow_17Rows_2, * An_1_inRow_17Rows_3, * An_1_inRow_17Rows_4, * An_1_inRow_17Rows_5, * An_1_inRow_17Rows_6, * An_1_inRow_17Rows_7,
		* An_1_inRow_17Rows_8, * An_1_inRow_17Rows_9, * An_1_inRow_17Rows_10, * An_1_inRow_17Rows_11, * An_1_inRow_17Rows_12,
	*An_2_inRow_1Row_1, * An_2_inRow_1Row_2,
		* An_2_inRow_2Rows_1, * An_2_inRow_2Rows_2,
		* An_2_inRow_3Rows_1, * An_2_inRow_3Rows_2,
		* An_2_inRow_4Rows_1, * An_2_inRow_4Rows_2, * An_2_inRow_4Rows_3, * An_2_inRow_4Rows_4,
		* An_2_inRow_5Rows_1, * An_2_inRow_5Rows_2, * An_2_inRow_5Rows_3, * An_2_inRow_5Rows_4,
		* An_2_inRow_6Rows_1, * An_2_inRow_6Rows_2, * An_2_inRow_6Rows_3, * An_2_inRow_6Rows_4,
		* An_2_inRow_7Rows_1, * An_2_inRow_7Rows_2, * An_2_inRow_7Rows_3, * An_2_inRow_7Rows_4, * An_2_inRow_7Rows_5, * An_2_inRow_7Rows_6,
		* An_2_inRow_8Rows_1, * An_2_inRow_8Rows_2, * An_2_inRow_8Rows_3, * An_2_inRow_8Rows_4, * An_2_inRow_8Rows_5, * An_2_inRow_8Rows_6,
		* An_2_inRow_9Rows_1, * An_2_inRow_9Rows_2, * An_2_inRow_9Rows_3, * An_2_inRow_9Rows_4, * An_2_inRow_9Rows_5, * An_2_inRow_9Rows_6,
		* An_2_inRow_10Rows_1, * An_2_inRow_10Rows_2, * An_2_inRow_10Rows_3, * An_2_inRow_10Rows_4, * An_2_inRow_10Rows_5, * An_2_inRow_10Rows_6, * An_2_inRow_10Rows_7,
		* An_2_inRow_10Rows_8,
		* An_2_inRow_11Rows_1, * An_2_inRow_11Rows_2, * An_2_inRow_11Rows_3, * An_2_inRow_11Rows_4, * An_2_inRow_11Rows_5, * An_2_inRow_11Rows_6, * An_2_inRow_11Rows_7,
		* An_2_inRow_11Rows_8,
		* An_2_inRow_12Rows_1, * An_2_inRow_12Rows_2, * An_2_inRow_12Rows_3, * An_2_inRow_12Rows_4, * An_2_inRow_12Rows_5, * An_2_inRow_12Rows_6, * An_2_inRow_12Rows_7,
		* An_2_inRow_12Rows_8,
		* An_2_inRow_13Rows_1, * An_2_inRow_13Rows_2, * An_2_inRow_13Rows_3, * An_2_inRow_13Rows_4, * An_2_inRow_13Rows_5, * An_2_inRow_13Rows_6, * An_2_inRow_13Rows_7,
		* An_2_inRow_13Rows_8, * An_2_inRow_13Rows_9, * An_2_inRow_13Rows_10,
		* An_2_inRow_14Rows_1, * An_2_inRow_14Rows_2, * An_2_inRow_14Rows_3, * An_2_inRow_14Rows_4, * An_2_inRow_14Rows_5, * An_2_inRow_14Rows_6, * An_2_inRow_14Rows_7,
		* An_2_inRow_14Rows_8, * An_2_inRow_14Rows_9, * An_2_inRow_14Rows_10,
		* An_2_inRow_15Rows_1, * An_2_inRow_15Rows_2, * An_2_inRow_15Rows_3, * An_2_inRow_15Rows_4, * An_2_inRow_15Rows_5, * An_2_inRow_15Rows_6, * An_2_inRow_15Rows_7,
		* An_2_inRow_15Rows_8, * An_2_inRow_15Rows_9, * An_2_inRow_15Rows_10,
		* An_2_inRow_16Rows_1, * An_2_inRow_16Rows_2, * An_2_inRow_16Rows_3, * An_2_inRow_16Rows_4, * An_2_inRow_16Rows_5, * An_2_inRow_16Rows_6, * An_2_inRow_16Rows_7,
		* An_2_inRow_16Rows_8, * An_2_inRow_16Rows_9, * An_2_inRow_16Rows_10, * An_2_inRow_16Rows_11, * An_2_inRow_16Rows_12,
		* An_2_inRow_17Rows_1, * An_2_inRow_17Rows_2, * An_2_inRow_17Rows_3, * An_2_inRow_17Rows_4, * An_2_inRow_17Rows_5, * An_2_inRow_17Rows_6, * An_2_inRow_17Rows_7,
		* An_2_inRow_17Rows_8, * An_2_inRow_17Rows_9, * An_2_inRow_17Rows_10, * An_2_inRow_17Rows_11, * An_2_inRow_17Rows_12,
		*An_3_inRow_1Row_1, * An_3_inRow_1Row_2,
		*An_3_inRow_2Rows_1, * An_3_inRow_2Rows_2,
		* An_3_inRow_3Rows_1, * An_3_inRow_3Rows_2,
		* An_3_inRow_4Rows_1, * An_3_inRow_4Rows_2, * An_3_inRow_4Rows_3, * An_3_inRow_4Rows_4,
		* An_3_inRow_5Rows_1, * An_3_inRow_5Rows_2, * An_3_inRow_5Rows_3, * An_3_inRow_5Rows_4,
		* An_3_inRow_6Rows_1, * An_3_inRow_6Rows_2, * An_3_inRow_6Rows_3, * An_3_inRow_6Rows_4,
		* An_3_inRow_7Rows_1, * An_3_inRow_7Rows_2, * An_3_inRow_7Rows_3, * An_3_inRow_7Rows_4, * An_3_inRow_7Rows_5, * An_3_inRow_7Rows_6,
		* An_3_inRow_8Rows_1, * An_3_inRow_8Rows_2, * An_3_inRow_8Rows_3, * An_3_inRow_8Rows_4, * An_3_inRow_8Rows_5, * An_3_inRow_8Rows_6,
		* An_3_inRow_9Rows_1, * An_3_inRow_9Rows_2, * An_3_inRow_9Rows_3, * An_3_inRow_9Rows_4, * An_3_inRow_9Rows_5, * An_3_inRow_9Rows_6,
		* An_3_inRow_10Rows_1, * An_3_inRow_10Rows_2, * An_3_inRow_10Rows_3, * An_3_inRow_10Rows_4, * An_3_inRow_10Rows_5, * An_3_inRow_10Rows_6, * An_3_inRow_10Rows_7,
		* An_3_inRow_10Rows_8,
		* An_3_inRow_11Rows_1, * An_3_inRow_11Rows_2, * An_3_inRow_11Rows_3, * An_3_inRow_11Rows_4, * An_3_inRow_11Rows_5, * An_3_inRow_11Rows_6, * An_3_inRow_11Rows_7,
		* An_3_inRow_11Rows_8,
		* An_3_inRow_12Rows_1, * An_3_inRow_12Rows_2, * An_3_inRow_12Rows_3, * An_3_inRow_12Rows_4, * An_3_inRow_12Rows_5, * An_3_inRow_12Rows_6, * An_3_inRow_12Rows_7,
		* An_3_inRow_12Rows_8,
		* An_3_inRow_13Rows_1, * An_3_inRow_13Rows_2, * An_3_inRow_13Rows_3, * An_3_inRow_13Rows_4, * An_3_inRow_13Rows_5, * An_3_inRow_13Rows_6, * An_3_inRow_13Rows_7,
		* An_3_inRow_13Rows_8, * An_3_inRow_13Rows_9, * An_3_inRow_13Rows_10,
		* An_3_inRow_14Rows_1, * An_3_inRow_14Rows_2, * An_3_inRow_14Rows_3, * An_3_inRow_14Rows_4, * An_3_inRow_14Rows_5, * An_3_inRow_14Rows_6, * An_3_inRow_14Rows_7,
		* An_3_inRow_14Rows_8, * An_3_inRow_14Rows_9, * An_3_inRow_14Rows_10,
		* An_3_inRow_15Rows_1, * An_3_inRow_15Rows_2, * An_3_inRow_15Rows_3, * An_3_inRow_15Rows_4, * An_3_inRow_15Rows_5, * An_3_inRow_15Rows_6, * An_3_inRow_15Rows_7,
		* An_3_inRow_15Rows_8, * An_3_inRow_15Rows_9, * An_3_inRow_15Rows_10,
		* An_3_inRow_16Rows_1, * An_3_inRow_16Rows_2, * An_3_inRow_16Rows_3, * An_3_inRow_16Rows_4, * An_3_inRow_16Rows_5, * An_3_inRow_16Rows_6, * An_3_inRow_16Rows_7,
		* An_3_inRow_16Rows_8, * An_3_inRow_16Rows_9, * An_3_inRow_16Rows_10, * An_3_inRow_16Rows_11, * An_3_inRow_16Rows_12,
		* An_3_inRow_17Rows_1, * An_3_inRow_17Rows_2, * An_3_inRow_17Rows_3, * An_3_inRow_17Rows_4, * An_3_inRow_17Rows_5, * An_3_inRow_17Rows_6, * An_3_inRow_17Rows_7,
		* An_3_inRow_17Rows_8, * An_3_inRow_17Rows_9, * An_3_inRow_17Rows_10, * An_3_inRow_17Rows_11, * An_3_inRow_17Rows_12,
		* An_3_inRow_18Rows_1, * An_3_inRow_18Rows_2, * An_3_inRow_18Rows_3, * An_3_inRow_18Rows_4, * An_3_inRow_18Rows_5, * An_3_inRow_18Rows_6, * An_3_inRow_18Rows_7,
		* An_3_inRow_18Rows_8, * An_3_inRow_18Rows_9, * An_3_inRow_18Rows_10, * An_3_inRow_18Rows_11, * An_3_inRow_18Rows_12,
		* An_4_inRow_1Row_1, * An_4_inRow_1Row_2,
		* An_4_inRow_2Rows_1, * An_4_inRow_2Rows_2,
		* An_4_inRow_3Rows_1, * An_4_inRow_3Rows_2,
		* An_4_inRow_4Rows_1, * An_4_inRow_4Rows_2, * An_4_inRow_4Rows_3, * An_4_inRow_4Rows_4,
		* An_4_inRow_5Rows_1, * An_4_inRow_5Rows_2, * An_4_inRow_5Rows_3, * An_4_inRow_5Rows_4,
		* An_4_inRow_6Rows_1, * An_4_inRow_6Rows_2, * An_4_inRow_6Rows_3, * An_4_inRow_6Rows_4,
		* An_4_inRow_7Rows_1, * An_4_inRow_7Rows_2, * An_4_inRow_7Rows_3, * An_4_inRow_7Rows_4, * An_4_inRow_7Rows_5, * An_4_inRow_7Rows_6,
		* An_4_inRow_8Rows_1, * An_4_inRow_8Rows_2, * An_4_inRow_8Rows_3, * An_4_inRow_8Rows_4, * An_4_inRow_8Rows_5, * An_4_inRow_8Rows_6,
		* An_4_inRow_9Rows_1, * An_4_inRow_9Rows_2, * An_4_inRow_9Rows_3, * An_4_inRow_9Rows_4, * An_4_inRow_9Rows_5, * An_4_inRow_9Rows_6,
		* An_4_inRow_10Rows_1, * An_4_inRow_10Rows_2, * An_4_inRow_10Rows_3, * An_4_inRow_10Rows_4, * An_4_inRow_10Rows_5, * An_4_inRow_10Rows_6, * An_4_inRow_10Rows_7,
		* An_4_inRow_10Rows_8,
		* An_4_inRow_11Rows_1, * An_4_inRow_11Rows_2, * An_4_inRow_11Rows_3, * An_4_inRow_11Rows_4, * An_4_inRow_11Rows_5, * An_4_inRow_11Rows_6, * An_4_inRow_11Rows_7,
		* An_4_inRow_11Rows_8,
		* An_4_inRow_12Rows_1, * An_4_inRow_12Rows_2, * An_4_inRow_12Rows_3, * An_4_inRow_12Rows_4, * An_4_inRow_12Rows_5, * An_4_inRow_12Rows_6, * An_4_inRow_12Rows_7,
		* An_4_inRow_12Rows_8,
		* An_4_inRow_13Rows_1, * An_4_inRow_13Rows_2, * An_4_inRow_13Rows_3, * An_4_inRow_13Rows_4, * An_4_inRow_13Rows_5, * An_4_inRow_13Rows_6, * An_4_inRow_13Rows_7,
		* An_4_inRow_13Rows_8, * An_4_inRow_13Rows_9, * An_4_inRow_13Rows_10,
		* An_4_inRow_14Rows_1, * An_4_inRow_14Rows_2, * An_4_inRow_14Rows_3, * An_4_inRow_14Rows_4, * An_4_inRow_14Rows_5, * An_4_inRow_14Rows_6, * An_4_inRow_14Rows_7,
		* An_4_inRow_14Rows_8, * An_4_inRow_14Rows_9, * An_4_inRow_14Rows_10,
		* An_4_inRow_15Rows_1, * An_4_inRow_15Rows_2, * An_4_inRow_15Rows_3, * An_4_inRow_15Rows_4, * An_4_inRow_15Rows_5, * An_4_inRow_15Rows_6, * An_4_inRow_15Rows_7,
		* An_4_inRow_15Rows_8, * An_4_inRow_15Rows_9, * An_4_inRow_15Rows_10,
		* An_4_inRow_16Rows_1, * An_4_inRow_16Rows_2, * An_4_inRow_16Rows_3, * An_4_inRow_16Rows_4, * An_4_inRow_16Rows_5, * An_4_inRow_16Rows_6, * An_4_inRow_16Rows_7,
		* An_4_inRow_16Rows_8, * An_4_inRow_16Rows_9, * An_4_inRow_16Rows_10, * An_4_inRow_16Rows_11, * An_4_inRow_16Rows_12,
		* An_4_inRow_17Rows_1, * An_4_inRow_17Rows_2, * An_4_inRow_17Rows_3, * An_4_inRow_17Rows_4, * An_4_inRow_17Rows_5, * An_4_inRow_17Rows_6, * An_4_inRow_17Rows_7,
		* An_4_inRow_17Rows_8, * An_4_inRow_17Rows_9, * An_4_inRow_17Rows_10, * An_4_inRow_17Rows_11, * An_4_inRow_17Rows_12,
		* An_4_inRow_18Rows_1, * An_4_inRow_18Rows_2, * An_4_inRow_18Rows_3, * An_4_inRow_18Rows_4, * An_4_inRow_18Rows_5, * An_4_inRow_18Rows_6, * An_4_inRow_18Rows_7,
		* An_4_inRow_18Rows_8, * An_4_inRow_18Rows_9, * An_4_inRow_18Rows_10, * An_4_inRow_18Rows_11, * An_4_inRow_18Rows_12;
		

	
	//загрузка текстур из ресурсов
	myCursor = LoadTextureFromResource(IDB_PNG120, "PNG");
	myCursor->setSmooth(true);
	button_start_st1 = LoadTextureFromResource(IDB_PNG8, "PNG");
	button_start_st2 = LoadTextureFromResource(IDB_PNG56, "PNG");
	button_start_st3 = LoadTextureFromResource(IDB_PNG10, "PNG");

	button_newgame_st1 = LoadTextureFromResource(IDB_PNG9, "PNG");
	button_newgame_st2 = LoadTextureFromResource(IDB_PNG12, "PNG");
	button_newgame_st3 = LoadTextureFromResource(IDB_PNG13, "PNG");

	button_options_st1 = LoadTextureFromResource(IDB_PNG14, "PNG");
	button_options_st2 = LoadTextureFromResource(IDB_PNG15, "PNG");
	button_options_st3 = LoadTextureFromResource(IDB_PNG16, "PNG");

	button_left_st1 = LoadTextureFromResource(IDB_PNG17, "PNG");
	button_left_st2 = LoadTextureFromResource(IDB_PNG18, "PNG");
	button_left_st3 = LoadTextureFromResource(IDB_PNG19, "PNG");

	button_right_st1 = LoadTextureFromResource(IDB_PNG20, "PNG");
	button_right_st2 = LoadTextureFromResource(IDB_PNG21, "PNG");
	button_right_st3 = LoadTextureFromResource(IDB_PNG22, "PNG");

	button_middle_restore_st1 = LoadTextureFromResource(IDB_PNG23, "PNG");
	button_middle_restore_st2 = LoadTextureFromResource(IDB_PNG24, "PNG");
	button_middle_restore_st3 = LoadTextureFromResource(IDB_PNG25, "PNG");

	button_pause_st1 = LoadTextureFromResource(IDB_PNG26, "PNG");
	button_pause_st2 = LoadTextureFromResource(IDB_PNG27, "PNG");
	button_pause_st3 = LoadTextureFromResource(IDB_PNG28, "PNG");
	button_pause_st4 = LoadTextureFromResource(IDB_PNG53, "PNG");

	button_resume_st1 = LoadTextureFromResource(IDB_PNG41, "PNG");
	button_resume_st2 = LoadTextureFromResource(IDB_PNG42, "PNG");
	button_resume_st3 = LoadTextureFromResource(IDB_PNG43, "PNG");

	button_soundOff_st1 = LoadTextureFromResource(IDB_PNG29, "PNG");
	button_soundOff_st2 = LoadTextureFromResource(IDB_PNG30, "PNG");
	button_soundOff_st3 = LoadTextureFromResource(IDB_PNG31, "PNG");

	button_soundOn_st1 = LoadTextureFromResource(IDB_PNG44, "PNG");
	button_soundOn_st2 = LoadTextureFromResource(IDB_PNG45, "PNG");
	button_soundOn_st3 = LoadTextureFromResource(IDB_PNG46, "PNG");
	button_soundOn_st4 = LoadTextureFromResource(IDB_PNG54, "PNG");

	button_musicOn_st1 = LoadTextureFromResource(IDB_PNG47, "PNG");
	button_musicOn_st2 = LoadTextureFromResource(IDB_PNG48, "PNG");
	button_musicOn_st3 = LoadTextureFromResource(IDB_PNG49, "PNG");
	button_musicOn_st4 = LoadTextureFromResource(IDB_PNG55, "PNG");

	button_musicOff_st1 = LoadTextureFromResource(IDB_PNG50, "PNG");
	button_musicOff_st2 = LoadTextureFromResource(IDB_PNG51, "PNG");
	button_musicOff_st3 = LoadTextureFromResource(IDB_PNG52, "PNG");

	tex_background = LoadTextureFromResource(IDB_PNG4, "PNG");
	left_frame = LoadTextureFromResource(IDB_PNG32, "PNG");
	right_frame = LoadTextureFromResource(IDB_PNG33, "PNG");
	right_frame_bottom = LoadTextureFromResource(IDB_PNG34, "PNG");

	ays_frame = LoadTextureFromResource(IDB_PNG35, "PNG");
	ays_question = LoadTextureFromResource(IDB_PNG38, "PNG");
	ays_yes1st = LoadTextureFromResource(IDB_PNG39, "PNG");
	ays_yes2st = LoadTextureFromResource(IDB_PNG40, "PNG");
	ays_no1st = LoadTextureFromResource(IDB_PNG36, "PNG");
	ays_no2st = LoadTextureFromResource(IDB_PNG37, "PNG");
	
	I_red = LoadTextureFromResource(IDB_PNG57, "PNG");
	S_red = LoadTextureFromResource(IDB_PNG61, "PNG");
	Z_red = LoadTextureFromResource(IDB_PNG63, "PNG");
	T_red = LoadTextureFromResource(IDB_PNG62, "PNG");
	L_red = LoadTextureFromResource(IDB_PNG59, "PNG");
	J_red = LoadTextureFromResource(IDB_PNG58, "PNG");
	O_red = LoadTextureFromResource(IDB_PNG60, "PNG");

	I_blue = LoadTextureFromResource(IDB_PNG65, "PNG");
	S_blue = LoadTextureFromResource(IDB_PNG97, "PNG");
	Z_blue = LoadTextureFromResource(IDB_PNG113, "PNG");
	T_blue = LoadTextureFromResource(IDB_PNG105, "PNG");
	L_blue = LoadTextureFromResource(IDB_PNG81, "PNG");
	J_blue = LoadTextureFromResource(IDB_PNG73, "PNG");
	O_blue = LoadTextureFromResource(IDB_PNG89, "PNG");

	I_black = LoadTextureFromResource(IDB_PNG64, "PNG");
	S_black = LoadTextureFromResource(IDB_PNG96, "PNG");
	Z_black = LoadTextureFromResource(IDB_PNG112, "PNG");
	T_black = LoadTextureFromResource(IDB_PNG104, "PNG");
	L_black = LoadTextureFromResource(IDB_PNG80, "PNG");
	J_black = LoadTextureFromResource(IDB_PNG72, "PNG");
	O_black = LoadTextureFromResource(IDB_PNG88, "PNG");

	I_brown = LoadTextureFromResource(IDB_PNG66, "PNG");
	S_brown = LoadTextureFromResource(IDB_PNG98, "PNG");
	Z_brown = LoadTextureFromResource(IDB_PNG114, "PNG");
	T_brown = LoadTextureFromResource(IDB_PNG106, "PNG");
	L_brown = LoadTextureFromResource(IDB_PNG82, "PNG");
	J_brown = LoadTextureFromResource(IDB_PNG74, "PNG");
	O_brown = LoadTextureFromResource(IDB_PNG90, "PNG");

	I_orange = LoadTextureFromResource(IDB_PNG68, "PNG");
	S_orange = LoadTextureFromResource(IDB_PNG100, "PNG");
	Z_orange = LoadTextureFromResource(IDB_PNG116, "PNG");
	T_orange = LoadTextureFromResource(IDB_PNG108, "PNG");
	L_orange = LoadTextureFromResource(IDB_PNG84, "PNG");
	J_orange = LoadTextureFromResource(IDB_PNG76, "PNG");
	O_orange = LoadTextureFromResource(IDB_PNG92, "PNG");

	I_green = LoadTextureFromResource(IDB_PNG67, "PNG");
	S_green = LoadTextureFromResource(IDB_PNG99, "PNG");
	Z_green = LoadTextureFromResource(IDB_PNG115, "PNG");
	T_green = LoadTextureFromResource(IDB_PNG107, "PNG");
	L_green = LoadTextureFromResource(IDB_PNG83, "PNG");
	J_green = LoadTextureFromResource(IDB_PNG75, "PNG");
	O_green = LoadTextureFromResource(IDB_PNG91, "PNG");

	I_purple = LoadTextureFromResource(IDB_PNG70, "PNG");
	S_purple = LoadTextureFromResource(IDB_PNG102, "PNG");
	Z_purple = LoadTextureFromResource(IDB_PNG118, "PNG");
	T_purple = LoadTextureFromResource(IDB_PNG110, "PNG");
	L_purple = LoadTextureFromResource(IDB_PNG86, "PNG");
	J_purple = LoadTextureFromResource(IDB_PNG78, "PNG");
	O_purple = LoadTextureFromResource(IDB_PNG94, "PNG");

	I_pink = LoadTextureFromResource(IDB_PNG69, "PNG");
	S_pink = LoadTextureFromResource(IDB_PNG101, "PNG");
	Z_pink = LoadTextureFromResource(IDB_PNG117, "PNG");
	T_pink = LoadTextureFromResource(IDB_PNG109, "PNG");
	L_pink = LoadTextureFromResource(IDB_PNG85, "PNG");
	J_pink = LoadTextureFromResource(IDB_PNG77, "PNG");
	O_pink = LoadTextureFromResource(IDB_PNG93, "PNG");

	I_yellow = LoadTextureFromResource(IDB_PNG71, "PNG");
	S_yellow = LoadTextureFromResource(IDB_PNG103, "PNG");
	Z_yellow = LoadTextureFromResource(IDB_PNG119, "PNG");
	T_yellow = LoadTextureFromResource(IDB_PNG111, "PNG");
	L_yellow = LoadTextureFromResource(IDB_PNG87, "PNG");
	J_yellow = LoadTextureFromResource(IDB_PNG79, "PNG");
	O_yellow = LoadTextureFromResource(IDB_PNG95, "PNG");


	An_1line_1 = LoadTextureFromResource(IDB_PNG121, "PNG");
	An_1line_2 = LoadTextureFromResource(IDB_PNG122, "PNG");
	An_1line_3 = LoadTextureFromResource(IDB_PNG123, "PNG");
	An_1line_4 = LoadTextureFromResource(IDB_PNG124, "PNG");
	An_1line_5 = LoadTextureFromResource(IDB_PNG125, "PNG");
	An_1line_6 = LoadTextureFromResource(IDB_PNG126, "PNG");
	An_1line_7 = LoadTextureFromResource(IDB_PNG127, "PNG");
	An_1line_8 = LoadTextureFromResource(IDB_PNG128, "PNG");
	An_1line_9 = LoadTextureFromResource(IDB_PNG129, "PNG");
	An_1line_10 = LoadTextureFromResource(IDB_PNG130, "PNG");
	An_1line_11 = LoadTextureFromResource(IDB_PNG131, "PNG");
	An_1line_12 = LoadTextureFromResource(IDB_PNG132, "PNG");
	An_1line_13 = LoadTextureFromResource(IDB_PNG133, "PNG");
	An_1line_14 = LoadTextureFromResource(IDB_PNG134, "PNG");
	An_1line_15 = LoadTextureFromResource(IDB_PNG135, "PNG");
	An_1line_16 = LoadTextureFromResource(IDB_PNG136, "PNG");
	An_1line_17 = LoadTextureFromResource(IDB_PNG137, "PNG");
	An_1line_18 = LoadTextureFromResource(IDB_PNG138, "PNG");
	An_1line_19 = LoadTextureFromResource(IDB_PNG139, "PNG");
	An_1line_20 = LoadTextureFromResource(IDB_PNG140, "PNG");
	An_1line_21 = LoadTextureFromResource(IDB_PNG141, "PNG");
	An_1line_22 = LoadTextureFromResource(IDB_PNG142, "PNG");

	An_2lines_1 = LoadTextureFromResource(IDB_PNG143, "PNG");
	An_2lines_2 = LoadTextureFromResource(IDB_PNG144, "PNG");
	An_2lines_3 = LoadTextureFromResource(IDB_PNG145, "PNG");
	An_2lines_4 = LoadTextureFromResource(IDB_PNG146, "PNG");
	An_2lines_5 = LoadTextureFromResource(IDB_PNG147, "PNG");
	An_2lines_6 = LoadTextureFromResource(IDB_PNG148, "PNG");
	An_2lines_7 = LoadTextureFromResource(IDB_PNG149, "PNG");
	An_2lines_8 = LoadTextureFromResource(IDB_PNG150, "PNG");
	An_2lines_9 = LoadTextureFromResource(IDB_PNG151, "PNG");
	An_2lines_10 = LoadTextureFromResource(IDB_PNG152, "PNG");
	An_2lines_11 = LoadTextureFromResource(IDB_PNG153, "PNG");
	An_2lines_12 = LoadTextureFromResource(IDB_PNG154, "PNG");
	An_2lines_13 = LoadTextureFromResource(IDB_PNG155, "PNG");
	An_2lines_14 = LoadTextureFromResource(IDB_PNG156, "PNG");
	An_2lines_15 = LoadTextureFromResource(IDB_PNG157, "PNG");
	An_2lines_16 = LoadTextureFromResource(IDB_PNG158, "PNG");
	An_2lines_17 = LoadTextureFromResource(IDB_PNG159, "PNG");
	An_2lines_18 = LoadTextureFromResource(IDB_PNG160, "PNG");
	An_2lines_19 = LoadTextureFromResource(IDB_PNG161, "PNG");
	An_2lines_20 = LoadTextureFromResource(IDB_PNG162, "PNG");
	An_2lines_21 = LoadTextureFromResource(IDB_PNG163, "PNG");
	An_2lines_22 = LoadTextureFromResource(IDB_PNG164, "PNG");

	An_3lines_1 = LoadTextureFromResource(IDB_PNG165, "PNG");
	An_3lines_2 = LoadTextureFromResource(IDB_PNG166, "PNG");
	An_3lines_3 = LoadTextureFromResource(IDB_PNG167, "PNG");
	An_3lines_4 = LoadTextureFromResource(IDB_PNG168, "PNG");
	An_3lines_5 = LoadTextureFromResource(IDB_PNG169, "PNG");
	An_3lines_6 = LoadTextureFromResource(IDB_PNG170, "PNG");
	An_3lines_7 = LoadTextureFromResource(IDB_PNG171, "PNG");
	An_3lines_8 = LoadTextureFromResource(IDB_PNG172, "PNG");
	An_3lines_9 = LoadTextureFromResource(IDB_PNG173, "PNG");
	An_3lines_10 = LoadTextureFromResource(IDB_PNG174, "PNG");
	An_3lines_11 = LoadTextureFromResource(IDB_PNG175, "PNG");
	An_3lines_12 = LoadTextureFromResource(IDB_PNG176, "PNG");
	An_3lines_13 = LoadTextureFromResource(IDB_PNG177, "PNG");
	An_3lines_14 = LoadTextureFromResource(IDB_PNG178, "PNG");
	An_3lines_15 = LoadTextureFromResource(IDB_PNG179, "PNG");
	An_3lines_16 = LoadTextureFromResource(IDB_PNG180, "PNG");
	An_3lines_17 = LoadTextureFromResource(IDB_PNG181, "PNG");
	An_3lines_18 = LoadTextureFromResource(IDB_PNG182, "PNG");
	An_3lines_19 = LoadTextureFromResource(IDB_PNG183, "PNG");
	An_3lines_20 = LoadTextureFromResource(IDB_PNG184, "PNG");
	An_3lines_21 = LoadTextureFromResource(IDB_PNG185, "PNG");
	An_3lines_22 = LoadTextureFromResource(IDB_PNG186, "PNG");

	An_4lines_1 = LoadTextureFromResource(IDB_PNG187, "PNG");
	An_4lines_2 = LoadTextureFromResource(IDB_PNG188, "PNG");
	An_4lines_3 = LoadTextureFromResource(IDB_PNG189, "PNG");
	An_4lines_4 = LoadTextureFromResource(IDB_PNG190, "PNG");
	An_4lines_5 = LoadTextureFromResource(IDB_PNG191, "PNG");
	An_4lines_6 = LoadTextureFromResource(IDB_PNG192, "PNG");
	An_4lines_7 = LoadTextureFromResource(IDB_PNG193, "PNG");
	An_4lines_8 = LoadTextureFromResource(IDB_PNG194, "PNG");
	An_4lines_9 = LoadTextureFromResource(IDB_PNG195, "PNG");
	An_4lines_10 = LoadTextureFromResource(IDB_PNG196, "PNG");
	An_4lines_11 = LoadTextureFromResource(IDB_PNG197, "PNG");
	An_4lines_12 = LoadTextureFromResource(IDB_PNG198, "PNG");
	An_4lines_13 = LoadTextureFromResource(IDB_PNG199, "PNG");
	An_4lines_14 = LoadTextureFromResource(IDB_PNG200, "PNG");
	An_4lines_15 = LoadTextureFromResource(IDB_PNG201, "PNG");
	An_4lines_16 = LoadTextureFromResource(IDB_PNG202, "PNG");
	An_4lines_17 = LoadTextureFromResource(IDB_PNG203, "PNG");
	An_4lines_18 = LoadTextureFromResource(IDB_PNG204, "PNG");
	An_4lines_19 = LoadTextureFromResource(IDB_PNG205, "PNG");
	An_4lines_20 = LoadTextureFromResource(IDB_PNG206, "PNG");
	An_4lines_21 = LoadTextureFromResource(IDB_PNG207, "PNG");
	An_4lines_22 = LoadTextureFromResource(IDB_PNG208, "PNG");

	An_3_inRow_16Rows_1 = LoadTextureFromResource(IDB_PNG210, "PNG");
	An_3_inRow_16Rows_2 = LoadTextureFromResource(IDB_PNG211, "PNG");
	An_3_inRow_16Rows_3 = LoadTextureFromResource(IDB_PNG212, "PNG");
	An_3_inRow_16Rows_4 = LoadTextureFromResource(IDB_PNG213, "PNG");
	An_3_inRow_16Rows_5 = LoadTextureFromResource(IDB_PNG214, "PNG");
	An_3_inRow_16Rows_6 = LoadTextureFromResource(IDB_PNG215, "PNG");
	An_3_inRow_16Rows_7 = LoadTextureFromResource(IDB_PNG216, "PNG");
	An_3_inRow_16Rows_8 = LoadTextureFromResource(IDB_PNG217, "PNG");
	An_3_inRow_16Rows_9 = LoadTextureFromResource(IDB_PNG218, "PNG");
	An_3_inRow_16Rows_10 = LoadTextureFromResource(IDB_PNG219, "PNG");
	An_3_inRow_16Rows_11 = LoadTextureFromResource(IDB_PNG220, "PNG");
	An_3_inRow_16Rows_12 = LoadTextureFromResource(IDB_PNG221, "PNG");

	An_1_inRow_1Row_1 = LoadTextureFromResource(IDB_PNG222, "PNG");
	An_1_inRow_1Row_2 = LoadTextureFromResource(IDB_PNG223, "PNG");
	An_1_inRow_2Rows_1 = LoadTextureFromResource(IDB_PNG224, "PNG");
	An_1_inRow_2Rows_2 = LoadTextureFromResource(IDB_PNG225, "PNG");
	An_1_inRow_3Rows_1 = LoadTextureFromResource(IDB_PNG226, "PNG");
	An_1_inRow_3Rows_2 = LoadTextureFromResource(IDB_PNG227, "PNG");
	An_1_inRow_4Rows_1 = LoadTextureFromResource(IDB_PNG228, "PNG");
	An_1_inRow_4Rows_2 = LoadTextureFromResource(IDB_PNG229, "PNG");
	An_1_inRow_4Rows_3 = LoadTextureFromResource(IDB_PNG230, "PNG");
	An_1_inRow_4Rows_4 = LoadTextureFromResource(IDB_PNG231, "PNG");
	An_1_inRow_5Rows_1 = LoadTextureFromResource(IDB_PNG232, "PNG");
	An_1_inRow_5Rows_2 = LoadTextureFromResource(IDB_PNG233, "PNG");
	An_1_inRow_5Rows_3 = LoadTextureFromResource(IDB_PNG234, "PNG");
	An_1_inRow_5Rows_4 = LoadTextureFromResource(IDB_PNG235, "PNG");
	An_1_inRow_6Rows_1 = LoadTextureFromResource(IDB_PNG236, "PNG");
	An_1_inRow_6Rows_2 = LoadTextureFromResource(IDB_PNG237, "PNG");
	An_1_inRow_6Rows_3 = LoadTextureFromResource(IDB_PNG238, "PNG");
	An_1_inRow_6Rows_4 = LoadTextureFromResource(IDB_PNG239, "PNG");
	An_1_inRow_7Rows_1 = LoadTextureFromResource(IDB_PNG240, "PNG");
	An_1_inRow_7Rows_2 = LoadTextureFromResource(IDB_PNG241, "PNG");
	An_1_inRow_7Rows_3 = LoadTextureFromResource(IDB_PNG242, "PNG");
	An_1_inRow_7Rows_4 = LoadTextureFromResource(IDB_PNG243, "PNG");
	An_1_inRow_7Rows_5 = LoadTextureFromResource(IDB_PNG244, "PNG");
	An_1_inRow_7Rows_6 = LoadTextureFromResource(IDB_PNG245, "PNG");
	An_1_inRow_8Rows_1 = LoadTextureFromResource(IDB_PNG246, "PNG");
	An_1_inRow_8Rows_2 = LoadTextureFromResource(IDB_PNG247, "PNG");
	An_1_inRow_8Rows_3 = LoadTextureFromResource(IDB_PNG248, "PNG");
	An_1_inRow_8Rows_4 = LoadTextureFromResource(IDB_PNG249, "PNG");
	An_1_inRow_8Rows_5 = LoadTextureFromResource(IDB_PNG250, "PNG");
	An_1_inRow_8Rows_6 = LoadTextureFromResource(IDB_PNG251, "PNG");
	An_1_inRow_9Rows_1 = LoadTextureFromResource(IDB_PNG252, "PNG");
	An_1_inRow_9Rows_2 = LoadTextureFromResource(IDB_PNG253, "PNG");
	An_1_inRow_9Rows_3 = LoadTextureFromResource(IDB_PNG254, "PNG");
	An_1_inRow_9Rows_4 = LoadTextureFromResource(IDB_PNG255, "PNG");
	An_1_inRow_9Rows_5 = LoadTextureFromResource(IDB_PNG256, "PNG");
	An_1_inRow_9Rows_6 = LoadTextureFromResource(IDB_PNG257, "PNG");
	An_1_inRow_10Rows_1 = LoadTextureFromResource(IDB_PNG258, "PNG");
	An_1_inRow_10Rows_2 = LoadTextureFromResource(IDB_PNG259, "PNG");
	An_1_inRow_10Rows_3 = LoadTextureFromResource(IDB_PNG260, "PNG");
	An_1_inRow_10Rows_4 = LoadTextureFromResource(IDB_PNG261, "PNG");
	An_1_inRow_10Rows_5 = LoadTextureFromResource(IDB_PNG262, "PNG");
	An_1_inRow_10Rows_6 = LoadTextureFromResource(IDB_PNG263, "PNG");
	An_1_inRow_10Rows_7 = LoadTextureFromResource(IDB_PNG264, "PNG");
	An_1_inRow_10Rows_8 = LoadTextureFromResource(IDB_PNG265, "PNG");
	An_1_inRow_11Rows_1 = LoadTextureFromResource(IDB_PNG266, "PNG");
	An_1_inRow_11Rows_2 = LoadTextureFromResource(IDB_PNG267, "PNG");
	An_1_inRow_11Rows_3 = LoadTextureFromResource(IDB_PNG268, "PNG");
	An_1_inRow_11Rows_4 = LoadTextureFromResource(IDB_PNG269, "PNG");
	An_1_inRow_11Rows_5 = LoadTextureFromResource(IDB_PNG270, "PNG");
	An_1_inRow_11Rows_6 = LoadTextureFromResource(IDB_PNG271, "PNG");
	An_1_inRow_11Rows_7 = LoadTextureFromResource(IDB_PNG272, "PNG");
	An_1_inRow_11Rows_8 = LoadTextureFromResource(IDB_PNG273, "PNG");
	An_1_inRow_12Rows_1 = LoadTextureFromResource(IDB_PNG274, "PNG");
	An_1_inRow_12Rows_2 = LoadTextureFromResource(IDB_PNG275, "PNG");
	An_1_inRow_12Rows_3 = LoadTextureFromResource(IDB_PNG276, "PNG");
	An_1_inRow_12Rows_4 = LoadTextureFromResource(IDB_PNG277, "PNG");
	An_1_inRow_12Rows_5 = LoadTextureFromResource(IDB_PNG278, "PNG");
	An_1_inRow_12Rows_6 = LoadTextureFromResource(IDB_PNG279, "PNG");
	An_1_inRow_12Rows_7 = LoadTextureFromResource(IDB_PNG280, "PNG");
	An_1_inRow_12Rows_8 = LoadTextureFromResource(IDB_PNG281, "PNG");
	An_1_inRow_13Rows_1 = LoadTextureFromResource(IDB_PNG282, "PNG");
	An_1_inRow_13Rows_2 = LoadTextureFromResource(IDB_PNG283, "PNG");
	An_1_inRow_13Rows_3 = LoadTextureFromResource(IDB_PNG284, "PNG");
	An_1_inRow_13Rows_4 = LoadTextureFromResource(IDB_PNG285, "PNG");
	An_1_inRow_13Rows_5 = LoadTextureFromResource(IDB_PNG286, "PNG");
	An_1_inRow_13Rows_6 = LoadTextureFromResource(IDB_PNG287, "PNG");
	An_1_inRow_13Rows_7 = LoadTextureFromResource(IDB_PNG288, "PNG");
	An_1_inRow_13Rows_8 = LoadTextureFromResource(IDB_PNG289, "PNG");
	An_1_inRow_13Rows_9 = LoadTextureFromResource(IDB_PNG290, "PNG");
	An_1_inRow_13Rows_10 = LoadTextureFromResource(IDB_PNG291, "PNG");
	An_1_inRow_14Rows_1 = LoadTextureFromResource(IDB_PNG292, "PNG");
	An_1_inRow_14Rows_2 = LoadTextureFromResource(IDB_PNG293, "PNG");
	An_1_inRow_14Rows_3 = LoadTextureFromResource(IDB_PNG294, "PNG");
	An_1_inRow_14Rows_4 = LoadTextureFromResource(IDB_PNG295, "PNG");
	An_1_inRow_14Rows_5 = LoadTextureFromResource(IDB_PNG296, "PNG");
	An_1_inRow_14Rows_6 = LoadTextureFromResource(IDB_PNG297, "PNG");
	An_1_inRow_14Rows_7 = LoadTextureFromResource(IDB_PNG298, "PNG");
	An_1_inRow_14Rows_8 = LoadTextureFromResource(IDB_PNG299, "PNG");
	An_1_inRow_14Rows_9 = LoadTextureFromResource(IDB_PNG300, "PNG");
	An_1_inRow_14Rows_10 = LoadTextureFromResource(IDB_PNG301, "PNG");
	An_1_inRow_15Rows_1 = LoadTextureFromResource(IDB_PNG302, "PNG");
	An_1_inRow_15Rows_2 = LoadTextureFromResource(IDB_PNG303, "PNG");
	An_1_inRow_15Rows_3 = LoadTextureFromResource(IDB_PNG304, "PNG");
	An_1_inRow_15Rows_4 = LoadTextureFromResource(IDB_PNG305, "PNG");
	An_1_inRow_15Rows_5 = LoadTextureFromResource(IDB_PNG306, "PNG");
	An_1_inRow_15Rows_6 = LoadTextureFromResource(IDB_PNG307, "PNG");
	An_1_inRow_15Rows_7 = LoadTextureFromResource(IDB_PNG308, "PNG");
	An_1_inRow_15Rows_8 = LoadTextureFromResource(IDB_PNG309, "PNG");
	An_1_inRow_15Rows_9 = LoadTextureFromResource(IDB_PNG310, "PNG");
	An_1_inRow_15Rows_10 = LoadTextureFromResource(IDB_PNG311, "PNG");
	An_1_inRow_16Rows_1 = LoadTextureFromResource(IDB_PNG312, "PNG");
	An_1_inRow_16Rows_2 = LoadTextureFromResource(IDB_PNG313, "PNG");
	An_1_inRow_16Rows_3 = LoadTextureFromResource(IDB_PNG314, "PNG");
	An_1_inRow_16Rows_4 = LoadTextureFromResource(IDB_PNG315, "PNG");
	An_1_inRow_16Rows_5 = LoadTextureFromResource(IDB_PNG316, "PNG");
	An_1_inRow_16Rows_6 = LoadTextureFromResource(IDB_PNG317, "PNG");
	An_1_inRow_16Rows_7 = LoadTextureFromResource(IDB_PNG318, "PNG");
	An_1_inRow_16Rows_8 = LoadTextureFromResource(IDB_PNG319, "PNG");
	An_1_inRow_16Rows_9 = LoadTextureFromResource(IDB_PNG320, "PNG");
	An_1_inRow_16Rows_10 = LoadTextureFromResource(IDB_PNG321, "PNG");
	An_1_inRow_16Rows_11 = LoadTextureFromResource(IDB_PNG322, "PNG");
	An_1_inRow_16Rows_12 = LoadTextureFromResource(IDB_PNG323, "PNG");
	An_1_inRow_17Rows_1 = LoadTextureFromResource(IDB_PNG324, "PNG");
	An_1_inRow_17Rows_2 = LoadTextureFromResource(IDB_PNG325, "PNG");
	An_1_inRow_17Rows_3 = LoadTextureFromResource(IDB_PNG326, "PNG");
	An_1_inRow_17Rows_4 = LoadTextureFromResource(IDB_PNG327, "PNG");
	An_1_inRow_17Rows_5 = LoadTextureFromResource(IDB_PNG328, "PNG");
	An_1_inRow_17Rows_6 = LoadTextureFromResource(IDB_PNG329, "PNG");
	An_1_inRow_17Rows_7 = LoadTextureFromResource(IDB_PNG330, "PNG");
	An_1_inRow_17Rows_8 = LoadTextureFromResource(IDB_PNG331, "PNG");
	An_1_inRow_17Rows_9 = LoadTextureFromResource(IDB_PNG332, "PNG");
	An_1_inRow_17Rows_10 = LoadTextureFromResource(IDB_PNG333, "PNG");
	An_1_inRow_17Rows_11 = LoadTextureFromResource(IDB_PNG334, "PNG");
	An_1_inRow_17Rows_12 = LoadTextureFromResource(IDB_PNG335, "PNG");
	An_2_inRow_1Row_1 = LoadTextureFromResource(IDB_PNG336, "PNG");
	An_2_inRow_1Row_2 = LoadTextureFromResource(IDB_PNG337, "PNG");
	An_2_inRow_2Rows_1 = LoadTextureFromResource(IDB_PNG338, "PNG");
	An_2_inRow_2Rows_2 = LoadTextureFromResource(IDB_PNG339, "PNG");
	An_2_inRow_3Rows_1 = LoadTextureFromResource(IDB_PNG340, "PNG");
	An_2_inRow_3Rows_2 = LoadTextureFromResource(IDB_PNG341, "PNG");
	An_2_inRow_4Rows_1 = LoadTextureFromResource(IDB_PNG342, "PNG");
	An_2_inRow_4Rows_2 = LoadTextureFromResource(IDB_PNG343, "PNG");
	An_2_inRow_4Rows_3 = LoadTextureFromResource(IDB_PNG344, "PNG");
	An_2_inRow_4Rows_4 = LoadTextureFromResource(IDB_PNG345, "PNG");
	An_2_inRow_5Rows_1 = LoadTextureFromResource(IDB_PNG346, "PNG");
	An_2_inRow_5Rows_2 = LoadTextureFromResource(IDB_PNG347, "PNG");
	An_2_inRow_5Rows_3 = LoadTextureFromResource(IDB_PNG348, "PNG");
	An_2_inRow_5Rows_4 = LoadTextureFromResource(IDB_PNG349, "PNG");
	An_2_inRow_6Rows_1 = LoadTextureFromResource(IDB_PNG350, "PNG");
	An_2_inRow_6Rows_2 = LoadTextureFromResource(IDB_PNG351, "PNG");
	An_2_inRow_6Rows_3 = LoadTextureFromResource(IDB_PNG352, "PNG");
	An_2_inRow_6Rows_4 = LoadTextureFromResource(IDB_PNG353, "PNG");
	An_2_inRow_7Rows_1 = LoadTextureFromResource(IDB_PNG354, "PNG");
	An_2_inRow_7Rows_2 = LoadTextureFromResource(IDB_PNG355, "PNG");
	An_2_inRow_7Rows_3 = LoadTextureFromResource(IDB_PNG356, "PNG");
	An_2_inRow_7Rows_4 = LoadTextureFromResource(IDB_PNG357, "PNG");
	An_2_inRow_7Rows_5 = LoadTextureFromResource(IDB_PNG358, "PNG");
	An_2_inRow_7Rows_6 = LoadTextureFromResource(IDB_PNG359, "PNG");
	An_2_inRow_8Rows_1 = LoadTextureFromResource(IDB_PNG360, "PNG");
	An_2_inRow_8Rows_2 = LoadTextureFromResource(IDB_PNG361, "PNG");
	An_2_inRow_8Rows_3 = LoadTextureFromResource(IDB_PNG362, "PNG");
	An_2_inRow_8Rows_4 = LoadTextureFromResource(IDB_PNG363, "PNG");
	An_2_inRow_8Rows_5 = LoadTextureFromResource(IDB_PNG364, "PNG");
	An_2_inRow_8Rows_6 = LoadTextureFromResource(IDB_PNG365, "PNG");
	An_2_inRow_9Rows_1 = LoadTextureFromResource(IDB_PNG366, "PNG");
	An_2_inRow_9Rows_2 = LoadTextureFromResource(IDB_PNG367, "PNG");
	An_2_inRow_9Rows_3 = LoadTextureFromResource(IDB_PNG368, "PNG");
	An_2_inRow_9Rows_4 = LoadTextureFromResource(IDB_PNG369, "PNG");
	An_2_inRow_9Rows_5 = LoadTextureFromResource(IDB_PNG370, "PNG");
	An_2_inRow_9Rows_6 = LoadTextureFromResource(IDB_PNG371, "PNG");
	An_2_inRow_10Rows_1 = LoadTextureFromResource(IDB_PNG372, "PNG");
	An_2_inRow_10Rows_2 = LoadTextureFromResource(IDB_PNG373, "PNG");
	An_2_inRow_10Rows_3 = LoadTextureFromResource(IDB_PNG374, "PNG");
	An_2_inRow_10Rows_4 = LoadTextureFromResource(IDB_PNG375, "PNG");
	An_2_inRow_10Rows_5 = LoadTextureFromResource(IDB_PNG376, "PNG");
	An_2_inRow_10Rows_6 = LoadTextureFromResource(IDB_PNG377, "PNG");
	An_2_inRow_10Rows_7 = LoadTextureFromResource(IDB_PNG378, "PNG");
	An_2_inRow_10Rows_8 = LoadTextureFromResource(IDB_PNG379, "PNG");
	An_2_inRow_11Rows_1 = LoadTextureFromResource(IDB_PNG380, "PNG");
	An_2_inRow_11Rows_2 = LoadTextureFromResource(IDB_PNG381, "PNG");
	An_2_inRow_11Rows_3 = LoadTextureFromResource(IDB_PNG382, "PNG");
	An_2_inRow_11Rows_4 = LoadTextureFromResource(IDB_PNG383, "PNG");
	An_2_inRow_11Rows_5 = LoadTextureFromResource(IDB_PNG384, "PNG");
	An_2_inRow_11Rows_6 = LoadTextureFromResource(IDB_PNG385, "PNG");
	An_2_inRow_11Rows_7 = LoadTextureFromResource(IDB_PNG386, "PNG");
	An_2_inRow_11Rows_8 = LoadTextureFromResource(IDB_PNG387, "PNG");
	An_2_inRow_12Rows_1 = LoadTextureFromResource(IDB_PNG388, "PNG");
	An_2_inRow_12Rows_2 = LoadTextureFromResource(IDB_PNG389, "PNG");
	An_2_inRow_12Rows_3 = LoadTextureFromResource(IDB_PNG390, "PNG");
	An_2_inRow_12Rows_4 = LoadTextureFromResource(IDB_PNG391, "PNG");
	An_2_inRow_12Rows_5 = LoadTextureFromResource(IDB_PNG392, "PNG");
	An_2_inRow_12Rows_6 = LoadTextureFromResource(IDB_PNG393, "PNG");
	An_2_inRow_12Rows_7 = LoadTextureFromResource(IDB_PNG394, "PNG");
	An_2_inRow_12Rows_8 = LoadTextureFromResource(IDB_PNG395, "PNG");
	An_2_inRow_13Rows_1 = LoadTextureFromResource(IDB_PNG396, "PNG");
	An_2_inRow_13Rows_2 = LoadTextureFromResource(IDB_PNG397, "PNG");
	An_2_inRow_13Rows_3 = LoadTextureFromResource(IDB_PNG398, "PNG");
	An_2_inRow_13Rows_4 = LoadTextureFromResource(IDB_PNG399, "PNG");
	An_2_inRow_13Rows_5 = LoadTextureFromResource(IDB_PNG400, "PNG");
	An_2_inRow_13Rows_6 = LoadTextureFromResource(IDB_PNG401, "PNG");
	An_2_inRow_13Rows_7 = LoadTextureFromResource(IDB_PNG402, "PNG");
	An_2_inRow_13Rows_8 = LoadTextureFromResource(IDB_PNG403, "PNG");
	An_2_inRow_13Rows_9 = LoadTextureFromResource(IDB_PNG404, "PNG");
	An_2_inRow_13Rows_10 = LoadTextureFromResource(IDB_PNG405, "PNG");
	An_2_inRow_14Rows_1 = LoadTextureFromResource(IDB_PNG406, "PNG");
	An_2_inRow_14Rows_2 = LoadTextureFromResource(IDB_PNG407, "PNG");
	An_2_inRow_14Rows_3 = LoadTextureFromResource(IDB_PNG408, "PNG");
	An_2_inRow_14Rows_4 = LoadTextureFromResource(IDB_PNG409, "PNG");
	An_2_inRow_14Rows_5 = LoadTextureFromResource(IDB_PNG410, "PNG");
	An_2_inRow_14Rows_6 = LoadTextureFromResource(IDB_PNG411, "PNG");
	An_2_inRow_14Rows_7 = LoadTextureFromResource(IDB_PNG412, "PNG");
	An_2_inRow_14Rows_8 = LoadTextureFromResource(IDB_PNG413, "PNG");
	An_2_inRow_14Rows_9 = LoadTextureFromResource(IDB_PNG414, "PNG");
	An_2_inRow_14Rows_10 = LoadTextureFromResource(IDB_PNG415, "PNG");
	An_2_inRow_15Rows_1 = LoadTextureFromResource(IDB_PNG416, "PNG");
	An_2_inRow_15Rows_2 = LoadTextureFromResource(IDB_PNG417, "PNG");
	An_2_inRow_15Rows_3 = LoadTextureFromResource(IDB_PNG418, "PNG");
	An_2_inRow_15Rows_4 = LoadTextureFromResource(IDB_PNG419, "PNG");
	An_2_inRow_15Rows_5 = LoadTextureFromResource(IDB_PNG420, "PNG");
	An_2_inRow_15Rows_6 = LoadTextureFromResource(IDB_PNG421, "PNG");
	An_2_inRow_15Rows_7 = LoadTextureFromResource(IDB_PNG422, "PNG");
	An_2_inRow_15Rows_8 = LoadTextureFromResource(IDB_PNG423, "PNG");
	An_2_inRow_15Rows_9 = LoadTextureFromResource(IDB_PNG424, "PNG");
	An_2_inRow_15Rows_10 = LoadTextureFromResource(IDB_PNG425, "PNG");
	An_2_inRow_16Rows_1 = LoadTextureFromResource(IDB_PNG426, "PNG");
	An_2_inRow_16Rows_2 = LoadTextureFromResource(IDB_PNG427, "PNG");
	An_2_inRow_16Rows_3 = LoadTextureFromResource(IDB_PNG428, "PNG");
	An_2_inRow_16Rows_4 = LoadTextureFromResource(IDB_PNG429, "PNG");
	An_2_inRow_16Rows_5 = LoadTextureFromResource(IDB_PNG430, "PNG");
	An_2_inRow_16Rows_6 = LoadTextureFromResource(IDB_PNG431, "PNG");
	An_2_inRow_16Rows_7 = LoadTextureFromResource(IDB_PNG432, "PNG");
	An_2_inRow_16Rows_8 = LoadTextureFromResource(IDB_PNG433, "PNG");
	An_2_inRow_16Rows_9 = LoadTextureFromResource(IDB_PNG434, "PNG");
	An_2_inRow_16Rows_10 = LoadTextureFromResource(IDB_PNG435, "PNG");
	An_2_inRow_16Rows_11 = LoadTextureFromResource(IDB_PNG436, "PNG");
	An_2_inRow_16Rows_12 = LoadTextureFromResource(IDB_PNG437, "PNG");
	An_2_inRow_17Rows_1 = LoadTextureFromResource(IDB_PNG438, "PNG");
	An_2_inRow_17Rows_2 = LoadTextureFromResource(IDB_PNG439, "PNG");
	An_2_inRow_17Rows_3 = LoadTextureFromResource(IDB_PNG440, "PNG");
	An_2_inRow_17Rows_4 = LoadTextureFromResource(IDB_PNG441, "PNG");
	An_2_inRow_17Rows_5 = LoadTextureFromResource(IDB_PNG442, "PNG");
	An_2_inRow_17Rows_6 = LoadTextureFromResource(IDB_PNG443, "PNG");
	An_2_inRow_17Rows_7 = LoadTextureFromResource(IDB_PNG444, "PNG");
	An_2_inRow_17Rows_8 = LoadTextureFromResource(IDB_PNG445, "PNG");
	An_2_inRow_17Rows_9 = LoadTextureFromResource(IDB_PNG446, "PNG");
	An_2_inRow_17Rows_10 = LoadTextureFromResource(IDB_PNG447, "PNG");
	An_2_inRow_17Rows_11 = LoadTextureFromResource(IDB_PNG448, "PNG");
	An_2_inRow_17Rows_12 = LoadTextureFromResource(IDB_PNG449, "PNG");
	An_3_inRow_1Row_1 = LoadTextureFromResource(IDB_PNG450, "PNG");
	An_3_inRow_1Row_2 = LoadTextureFromResource(IDB_PNG451, "PNG");
	An_3_inRow_2Rows_1 = LoadTextureFromResource(IDB_PNG452, "PNG");
	An_3_inRow_2Rows_2 = LoadTextureFromResource(IDB_PNG453, "PNG");
	An_3_inRow_3Rows_1 = LoadTextureFromResource(IDB_PNG454, "PNG");
	An_3_inRow_3Rows_2 = LoadTextureFromResource(IDB_PNG455, "PNG");
	An_3_inRow_4Rows_1 = LoadTextureFromResource(IDB_PNG456, "PNG");
	An_3_inRow_4Rows_2 = LoadTextureFromResource(IDB_PNG457, "PNG");
	An_3_inRow_4Rows_3 = LoadTextureFromResource(IDB_PNG458, "PNG");
	An_3_inRow_4Rows_4 = LoadTextureFromResource(IDB_PNG459, "PNG");
	An_3_inRow_5Rows_1 = LoadTextureFromResource(IDB_PNG460, "PNG");
	An_3_inRow_5Rows_2 = LoadTextureFromResource(IDB_PNG461, "PNG");
	An_3_inRow_5Rows_3 = LoadTextureFromResource(IDB_PNG462, "PNG");
	An_3_inRow_5Rows_4 = LoadTextureFromResource(IDB_PNG463, "PNG");
	An_3_inRow_6Rows_1 = LoadTextureFromResource(IDB_PNG464, "PNG");
	An_3_inRow_6Rows_2 = LoadTextureFromResource(IDB_PNG465, "PNG");
	An_3_inRow_6Rows_3 = LoadTextureFromResource(IDB_PNG466, "PNG");
	An_3_inRow_6Rows_4 = LoadTextureFromResource(IDB_PNG467, "PNG");
	An_3_inRow_7Rows_1 = LoadTextureFromResource(IDB_PNG468, "PNG");
	An_3_inRow_7Rows_2 = LoadTextureFromResource(IDB_PNG469, "PNG");
	An_3_inRow_7Rows_3 = LoadTextureFromResource(IDB_PNG470, "PNG");
	An_3_inRow_7Rows_4 = LoadTextureFromResource(IDB_PNG471, "PNG");
	An_3_inRow_7Rows_5 = LoadTextureFromResource(IDB_PNG472, "PNG");
	An_3_inRow_7Rows_6 = LoadTextureFromResource(IDB_PNG473, "PNG");
	An_3_inRow_8Rows_1 = LoadTextureFromResource(IDB_PNG474, "PNG");
	An_3_inRow_8Rows_2 = LoadTextureFromResource(IDB_PNG475, "PNG");
	An_3_inRow_8Rows_3 = LoadTextureFromResource(IDB_PNG476, "PNG");
	An_3_inRow_8Rows_4 = LoadTextureFromResource(IDB_PNG477, "PNG");
	An_3_inRow_8Rows_5 = LoadTextureFromResource(IDB_PNG478, "PNG");
	An_3_inRow_8Rows_6 = LoadTextureFromResource(IDB_PNG479, "PNG");
	An_3_inRow_9Rows_1 = LoadTextureFromResource(IDB_PNG480, "PNG");
	An_3_inRow_9Rows_2 = LoadTextureFromResource(IDB_PNG481, "PNG");
	An_3_inRow_9Rows_3 = LoadTextureFromResource(IDB_PNG482, "PNG");
	An_3_inRow_9Rows_4 = LoadTextureFromResource(IDB_PNG483, "PNG");
	An_3_inRow_9Rows_5 = LoadTextureFromResource(IDB_PNG484, "PNG");
	An_3_inRow_9Rows_6 = LoadTextureFromResource(IDB_PNG485, "PNG");
	An_3_inRow_10Rows_1 = LoadTextureFromResource(IDB_PNG486, "PNG");
	An_3_inRow_10Rows_2 = LoadTextureFromResource(IDB_PNG487, "PNG");
	An_3_inRow_10Rows_3 = LoadTextureFromResource(IDB_PNG488, "PNG");
	An_3_inRow_10Rows_4 = LoadTextureFromResource(IDB_PNG489, "PNG");
	An_3_inRow_10Rows_5 = LoadTextureFromResource(IDB_PNG490, "PNG");
	An_3_inRow_10Rows_6 = LoadTextureFromResource(IDB_PNG491, "PNG");
	An_3_inRow_10Rows_7 = LoadTextureFromResource(IDB_PNG492, "PNG");
	An_3_inRow_10Rows_8 = LoadTextureFromResource(IDB_PNG493, "PNG");
	An_3_inRow_11Rows_1 = LoadTextureFromResource(IDB_PNG494, "PNG");
	An_3_inRow_11Rows_2 = LoadTextureFromResource(IDB_PNG495, "PNG");
	An_3_inRow_11Rows_3 = LoadTextureFromResource(IDB_PNG496, "PNG");
	An_3_inRow_11Rows_4 = LoadTextureFromResource(IDB_PNG497, "PNG");
	An_3_inRow_11Rows_5 = LoadTextureFromResource(IDB_PNG498, "PNG");
	An_3_inRow_11Rows_6 = LoadTextureFromResource(IDB_PNG499, "PNG");
	An_3_inRow_11Rows_7 = LoadTextureFromResource(IDB_PNG500, "PNG");
	An_3_inRow_11Rows_8 = LoadTextureFromResource(IDB_PNG501, "PNG");
	An_3_inRow_12Rows_1 = LoadTextureFromResource(IDB_PNG502, "PNG");
	An_3_inRow_12Rows_2 = LoadTextureFromResource(IDB_PNG503, "PNG");
	An_3_inRow_12Rows_3 = LoadTextureFromResource(IDB_PNG504, "PNG");
	An_3_inRow_12Rows_4 = LoadTextureFromResource(IDB_PNG505, "PNG");
	An_3_inRow_12Rows_5 = LoadTextureFromResource(IDB_PNG506, "PNG");
	An_3_inRow_12Rows_6 = LoadTextureFromResource(IDB_PNG507, "PNG");
	An_3_inRow_12Rows_7 = LoadTextureFromResource(IDB_PNG508, "PNG");
	An_3_inRow_12Rows_8 = LoadTextureFromResource(IDB_PNG509, "PNG");
	An_3_inRow_13Rows_1 = LoadTextureFromResource(IDB_PNG510, "PNG");
	An_3_inRow_13Rows_2 = LoadTextureFromResource(IDB_PNG511, "PNG");
	An_3_inRow_13Rows_3 = LoadTextureFromResource(IDB_PNG512, "PNG");
	An_3_inRow_13Rows_4 = LoadTextureFromResource(IDB_PNG513, "PNG");
	An_3_inRow_13Rows_5 = LoadTextureFromResource(IDB_PNG514, "PNG");
	An_3_inRow_13Rows_6 = LoadTextureFromResource(IDB_PNG515, "PNG");
	An_3_inRow_13Rows_7 = LoadTextureFromResource(IDB_PNG516, "PNG");
	An_3_inRow_13Rows_8 = LoadTextureFromResource(IDB_PNG517, "PNG");
	An_3_inRow_13Rows_9 = LoadTextureFromResource(IDB_PNG518, "PNG");
	An_3_inRow_13Rows_10 = LoadTextureFromResource(IDB_PNG519, "PNG");
	An_3_inRow_14Rows_1 = LoadTextureFromResource(IDB_PNG520, "PNG");
	An_3_inRow_14Rows_2 = LoadTextureFromResource(IDB_PNG521, "PNG");
	An_3_inRow_14Rows_3 = LoadTextureFromResource(IDB_PNG522, "PNG");
	An_3_inRow_14Rows_4 = LoadTextureFromResource(IDB_PNG523, "PNG");
	An_3_inRow_14Rows_5 = LoadTextureFromResource(IDB_PNG524, "PNG");
	An_3_inRow_14Rows_6 = LoadTextureFromResource(IDB_PNG525, "PNG");
	An_3_inRow_14Rows_7 = LoadTextureFromResource(IDB_PNG526, "PNG");
	An_3_inRow_14Rows_8 = LoadTextureFromResource(IDB_PNG527, "PNG");
	An_3_inRow_14Rows_9 = LoadTextureFromResource(IDB_PNG528, "PNG");
	An_3_inRow_14Rows_10 = LoadTextureFromResource(IDB_PNG529, "PNG");
	An_3_inRow_15Rows_1 = LoadTextureFromResource(IDB_PNG530, "PNG");
	An_3_inRow_15Rows_2 = LoadTextureFromResource(IDB_PNG531, "PNG");
	An_3_inRow_15Rows_3 = LoadTextureFromResource(IDB_PNG532, "PNG");
	An_3_inRow_15Rows_4 = LoadTextureFromResource(IDB_PNG533, "PNG");
	An_3_inRow_15Rows_5 = LoadTextureFromResource(IDB_PNG534, "PNG");
	An_3_inRow_15Rows_6 = LoadTextureFromResource(IDB_PNG535, "PNG");
	An_3_inRow_15Rows_7 = LoadTextureFromResource(IDB_PNG536, "PNG");
	An_3_inRow_15Rows_8 = LoadTextureFromResource(IDB_PNG537, "PNG");
	An_3_inRow_15Rows_9 = LoadTextureFromResource(IDB_PNG538, "PNG");
	An_3_inRow_15Rows_10 = LoadTextureFromResource(IDB_PNG539, "PNG");
	An_3_inRow_17Rows_1 = LoadTextureFromResource(IDB_PNG540, "PNG");
	An_3_inRow_17Rows_2 = LoadTextureFromResource(IDB_PNG541, "PNG");
	An_3_inRow_17Rows_3 = LoadTextureFromResource(IDB_PNG542, "PNG");
	An_3_inRow_17Rows_4 = LoadTextureFromResource(IDB_PNG543, "PNG");
	An_3_inRow_17Rows_5 = LoadTextureFromResource(IDB_PNG544, "PNG");
	An_3_inRow_17Rows_6 = LoadTextureFromResource(IDB_PNG545, "PNG");
	An_3_inRow_17Rows_7 = LoadTextureFromResource(IDB_PNG546, "PNG");
	An_3_inRow_17Rows_8 = LoadTextureFromResource(IDB_PNG547, "PNG");
	An_3_inRow_17Rows_9 = LoadTextureFromResource(IDB_PNG548, "PNG");
	An_3_inRow_17Rows_10 = LoadTextureFromResource(IDB_PNG549, "PNG");
	An_3_inRow_17Rows_11 = LoadTextureFromResource(IDB_PNG550, "PNG");
	An_3_inRow_17Rows_12 = LoadTextureFromResource(IDB_PNG551, "PNG");
	An_3_inRow_18Rows_1 = LoadTextureFromResource(IDB_PNG552, "PNG");
	An_3_inRow_18Rows_2 = LoadTextureFromResource(IDB_PNG553, "PNG");
	An_3_inRow_18Rows_3 = LoadTextureFromResource(IDB_PNG554, "PNG");
	An_3_inRow_18Rows_4 = LoadTextureFromResource(IDB_PNG555, "PNG");
	An_3_inRow_18Rows_5 = LoadTextureFromResource(IDB_PNG556, "PNG");
	An_3_inRow_18Rows_6 = LoadTextureFromResource(IDB_PNG557, "PNG");
	An_3_inRow_18Rows_7 = LoadTextureFromResource(IDB_PNG558, "PNG");
	An_3_inRow_18Rows_8 = LoadTextureFromResource(IDB_PNG559, "PNG");
	An_3_inRow_18Rows_9 = LoadTextureFromResource(IDB_PNG560, "PNG");
	An_3_inRow_18Rows_10 = LoadTextureFromResource(IDB_PNG561, "PNG");
	An_3_inRow_18Rows_11 = LoadTextureFromResource(IDB_PNG562, "PNG");
	An_3_inRow_18Rows_12 = LoadTextureFromResource(IDB_PNG563, "PNG");

	An_4_inRow_1Row_1 = LoadTextureFromResource(IDB_PNG564, "PNG");
	An_4_inRow_1Row_2 = LoadTextureFromResource(IDB_PNG565, "PNG");
	An_4_inRow_2Rows_1 = LoadTextureFromResource(IDB_PNG566, "PNG");
	An_4_inRow_2Rows_2 = LoadTextureFromResource(IDB_PNG567, "PNG");
	An_4_inRow_3Rows_1 = LoadTextureFromResource(IDB_PNG568, "PNG");
	An_4_inRow_3Rows_2 = LoadTextureFromResource(IDB_PNG569, "PNG");
	An_4_inRow_4Rows_1 = LoadTextureFromResource(IDB_PNG570, "PNG");
	An_4_inRow_4Rows_2 = LoadTextureFromResource(IDB_PNG571, "PNG");
	An_4_inRow_4Rows_3 = LoadTextureFromResource(IDB_PNG572, "PNG");
	An_4_inRow_4Rows_4 = LoadTextureFromResource(IDB_PNG573, "PNG");
	An_4_inRow_5Rows_1 = LoadTextureFromResource(IDB_PNG574, "PNG");
	An_4_inRow_5Rows_2 = LoadTextureFromResource(IDB_PNG575, "PNG");
	An_4_inRow_5Rows_3 = LoadTextureFromResource(IDB_PNG576, "PNG");
	An_4_inRow_5Rows_4 = LoadTextureFromResource(IDB_PNG577, "PNG");
	An_4_inRow_6Rows_1 = LoadTextureFromResource(IDB_PNG578, "PNG");
	An_4_inRow_6Rows_2 = LoadTextureFromResource(IDB_PNG579, "PNG");
	An_4_inRow_6Rows_3 = LoadTextureFromResource(IDB_PNG580, "PNG");
	An_4_inRow_6Rows_4 = LoadTextureFromResource(IDB_PNG581, "PNG");
	An_4_inRow_7Rows_1 = LoadTextureFromResource(IDB_PNG582, "PNG");
	An_4_inRow_7Rows_2 = LoadTextureFromResource(IDB_PNG583, "PNG");
	An_4_inRow_7Rows_3 = LoadTextureFromResource(IDB_PNG584, "PNG");
	An_4_inRow_7Rows_4 = LoadTextureFromResource(IDB_PNG585, "PNG");
	An_4_inRow_7Rows_5 = LoadTextureFromResource(IDB_PNG586, "PNG");
	An_4_inRow_7Rows_6 = LoadTextureFromResource(IDB_PNG587, "PNG");
	An_4_inRow_8Rows_1 = LoadTextureFromResource(IDB_PNG588, "PNG");
	An_4_inRow_8Rows_2 = LoadTextureFromResource(IDB_PNG589, "PNG");
	An_4_inRow_8Rows_3 = LoadTextureFromResource(IDB_PNG590, "PNG");
	An_4_inRow_8Rows_4 = LoadTextureFromResource(IDB_PNG591, "PNG");
	An_4_inRow_8Rows_5 = LoadTextureFromResource(IDB_PNG592, "PNG");
	An_4_inRow_8Rows_6 = LoadTextureFromResource(IDB_PNG593, "PNG");
	An_4_inRow_9Rows_1 = LoadTextureFromResource(IDB_PNG594, "PNG");
	An_4_inRow_9Rows_2 = LoadTextureFromResource(IDB_PNG595, "PNG");
	An_4_inRow_9Rows_3 = LoadTextureFromResource(IDB_PNG596, "PNG");
	An_4_inRow_9Rows_4 = LoadTextureFromResource(IDB_PNG597, "PNG");
	An_4_inRow_9Rows_5 = LoadTextureFromResource(IDB_PNG598, "PNG");
	An_4_inRow_9Rows_6 = LoadTextureFromResource(IDB_PNG599, "PNG");
	An_4_inRow_10Rows_1 = LoadTextureFromResource(IDB_PNG600, "PNG");
	An_4_inRow_10Rows_2 = LoadTextureFromResource(IDB_PNG601, "PNG");
	An_4_inRow_10Rows_3 = LoadTextureFromResource(IDB_PNG602, "PNG");
	An_4_inRow_10Rows_4 = LoadTextureFromResource(IDB_PNG603, "PNG");
	An_4_inRow_10Rows_5 = LoadTextureFromResource(IDB_PNG604, "PNG");
	An_4_inRow_10Rows_6 = LoadTextureFromResource(IDB_PNG605, "PNG");
	An_4_inRow_10Rows_7 = LoadTextureFromResource(IDB_PNG606, "PNG");
	An_4_inRow_10Rows_8 = LoadTextureFromResource(IDB_PNG607, "PNG");
	An_4_inRow_11Rows_1 = LoadTextureFromResource(IDB_PNG608, "PNG");
	An_4_inRow_11Rows_2 = LoadTextureFromResource(IDB_PNG609, "PNG");
	An_4_inRow_11Rows_3 = LoadTextureFromResource(IDB_PNG610, "PNG");
	An_4_inRow_11Rows_4 = LoadTextureFromResource(IDB_PNG611, "PNG");
	An_4_inRow_11Rows_5 = LoadTextureFromResource(IDB_PNG612, "PNG");
	An_4_inRow_11Rows_6 = LoadTextureFromResource(IDB_PNG613, "PNG");
	An_4_inRow_11Rows_7 = LoadTextureFromResource(IDB_PNG614, "PNG");
	An_4_inRow_11Rows_8 = LoadTextureFromResource(IDB_PNG615, "PNG");
	An_4_inRow_12Rows_1 = LoadTextureFromResource(IDB_PNG616, "PNG");
	An_4_inRow_12Rows_2 = LoadTextureFromResource(IDB_PNG617, "PNG");
	An_4_inRow_12Rows_3 = LoadTextureFromResource(IDB_PNG618, "PNG");
	An_4_inRow_12Rows_4 = LoadTextureFromResource(IDB_PNG619, "PNG");
	An_4_inRow_12Rows_5 = LoadTextureFromResource(IDB_PNG620, "PNG");
	An_4_inRow_12Rows_6 = LoadTextureFromResource(IDB_PNG621, "PNG");
	An_4_inRow_12Rows_7 = LoadTextureFromResource(IDB_PNG622, "PNG");
	An_4_inRow_12Rows_8 = LoadTextureFromResource(IDB_PNG623, "PNG");
	An_4_inRow_13Rows_1 = LoadTextureFromResource(IDB_PNG624, "PNG");
	An_4_inRow_13Rows_2 = LoadTextureFromResource(IDB_PNG625, "PNG");
	An_4_inRow_13Rows_3 = LoadTextureFromResource(IDB_PNG626, "PNG");
	An_4_inRow_13Rows_4 = LoadTextureFromResource(IDB_PNG627, "PNG");
	An_4_inRow_13Rows_5 = LoadTextureFromResource(IDB_PNG628, "PNG");
	An_4_inRow_13Rows_6 = LoadTextureFromResource(IDB_PNG629, "PNG");
	An_4_inRow_13Rows_7 = LoadTextureFromResource(IDB_PNG630, "PNG");
	An_4_inRow_13Rows_8 = LoadTextureFromResource(IDB_PNG631, "PNG");
	An_4_inRow_13Rows_9 = LoadTextureFromResource(IDB_PNG632, "PNG");
	An_4_inRow_13Rows_10 = LoadTextureFromResource(IDB_PNG633, "PNG");
	An_4_inRow_14Rows_1 = LoadTextureFromResource(IDB_PNG634, "PNG");
	An_4_inRow_14Rows_2 = LoadTextureFromResource(IDB_PNG635, "PNG");
	An_4_inRow_14Rows_3 = LoadTextureFromResource(IDB_PNG636, "PNG");
	An_4_inRow_14Rows_4 = LoadTextureFromResource(IDB_PNG637, "PNG");
	An_4_inRow_14Rows_5 = LoadTextureFromResource(IDB_PNG638, "PNG");
	An_4_inRow_14Rows_6 = LoadTextureFromResource(IDB_PNG639, "PNG");
	An_4_inRow_14Rows_7 = LoadTextureFromResource(IDB_PNG640, "PNG");
	An_4_inRow_14Rows_8 = LoadTextureFromResource(IDB_PNG641, "PNG");
	An_4_inRow_14Rows_9 = LoadTextureFromResource(IDB_PNG642, "PNG");
	An_4_inRow_14Rows_10 = LoadTextureFromResource(IDB_PNG643, "PNG");
	An_4_inRow_15Rows_1 = LoadTextureFromResource(IDB_PNG644, "PNG");
	An_4_inRow_15Rows_2 = LoadTextureFromResource(IDB_PNG645, "PNG");
	An_4_inRow_15Rows_3 = LoadTextureFromResource(IDB_PNG646, "PNG");
	An_4_inRow_15Rows_4 = LoadTextureFromResource(IDB_PNG647, "PNG");
	An_4_inRow_15Rows_5 = LoadTextureFromResource(IDB_PNG648, "PNG");
	An_4_inRow_15Rows_6 = LoadTextureFromResource(IDB_PNG649, "PNG");
	An_4_inRow_15Rows_7 = LoadTextureFromResource(IDB_PNG650, "PNG");
	An_4_inRow_15Rows_8 = LoadTextureFromResource(IDB_PNG651, "PNG");
	An_4_inRow_15Rows_9 = LoadTextureFromResource(IDB_PNG652, "PNG");
	An_4_inRow_15Rows_10 = LoadTextureFromResource(IDB_PNG653, "PNG");
	An_4_inRow_16Rows_1 = LoadTextureFromResource(IDB_PNG654, "PNG");
	An_4_inRow_16Rows_2 = LoadTextureFromResource(IDB_PNG655, "PNG");
	An_4_inRow_16Rows_3 = LoadTextureFromResource(IDB_PNG656, "PNG");
	An_4_inRow_16Rows_4 = LoadTextureFromResource(IDB_PNG657, "PNG");
	An_4_inRow_16Rows_5 = LoadTextureFromResource(IDB_PNG658, "PNG");
	An_4_inRow_16Rows_6 = LoadTextureFromResource(IDB_PNG659, "PNG");
	An_4_inRow_16Rows_7 = LoadTextureFromResource(IDB_PNG660, "PNG");
	An_4_inRow_16Rows_8 = LoadTextureFromResource(IDB_PNG661, "PNG");
	An_4_inRow_16Rows_9 = LoadTextureFromResource(IDB_PNG662, "PNG");
	An_4_inRow_16Rows_10 = LoadTextureFromResource(IDB_PNG663, "PNG");
	An_4_inRow_16Rows_11 = LoadTextureFromResource(IDB_PNG664, "PNG");
	An_4_inRow_16Rows_12 = LoadTextureFromResource(IDB_PNG665, "PNG");
	An_4_inRow_17Rows_1 = LoadTextureFromResource(IDB_PNG666, "PNG");
	An_4_inRow_17Rows_2 = LoadTextureFromResource(IDB_PNG667, "PNG");
	An_4_inRow_17Rows_3 = LoadTextureFromResource(IDB_PNG668, "PNG");
	An_4_inRow_17Rows_4 = LoadTextureFromResource(IDB_PNG669, "PNG");
	An_4_inRow_17Rows_5 = LoadTextureFromResource(IDB_PNG670, "PNG");
	An_4_inRow_17Rows_6 = LoadTextureFromResource(IDB_PNG671, "PNG");
	An_4_inRow_17Rows_7 = LoadTextureFromResource(IDB_PNG672, "PNG");
	An_4_inRow_17Rows_8 = LoadTextureFromResource(IDB_PNG673, "PNG");
	An_4_inRow_17Rows_9 = LoadTextureFromResource(IDB_PNG674, "PNG");
	An_4_inRow_17Rows_10 = LoadTextureFromResource(IDB_PNG675, "PNG");
	An_4_inRow_17Rows_11 = LoadTextureFromResource(IDB_PNG676, "PNG");
	An_4_inRow_17Rows_12 = LoadTextureFromResource(IDB_PNG677, "PNG");
	An_4_inRow_18Rows_1 = LoadTextureFromResource(IDB_PNG678, "PNG");
	An_4_inRow_18Rows_2 = LoadTextureFromResource(IDB_PNG679, "PNG");
	An_4_inRow_18Rows_3 = LoadTextureFromResource(IDB_PNG680, "PNG");
	An_4_inRow_18Rows_4 = LoadTextureFromResource(IDB_PNG681, "PNG");
	An_4_inRow_18Rows_5 = LoadTextureFromResource(IDB_PNG682, "PNG");
	An_4_inRow_18Rows_6 = LoadTextureFromResource(IDB_PNG683, "PNG");
	An_4_inRow_18Rows_7 = LoadTextureFromResource(IDB_PNG684, "PNG");
	An_4_inRow_18Rows_8 = LoadTextureFromResource(IDB_PNG685, "PNG");
	An_4_inRow_18Rows_9 = LoadTextureFromResource(IDB_PNG686, "PNG");
	An_4_inRow_18Rows_10 = LoadTextureFromResource(IDB_PNG687, "PNG");
	An_4_inRow_18Rows_11 = LoadTextureFromResource(IDB_PNG688, "PNG");
	An_4_inRow_18Rows_12 = LoadTextureFromResource(IDB_PNG689, "PNG");

	
	Image *img_table, *tetramino /*,*img_myCursor*/;
	img_table = LoadImageFromResource(IDB_PNG5, "PNG");
	tex_table->loadFromImage(*img_table);
	//img_myCursor = LoadImageFromResource(IDB_PNG120, "PNG");

	tetramino = LoadImageFromResource(IDB_PNG7, "PNG");
	/*tetramino->createMaskFromColor(Color(253, 253, 253));
	tetramino->createMaskFromColor(Color(254, 254, 254));
	tetramino->createMaskFromColor(Color(255, 255, 255));
	tetramino->createMaskFromColor(Color(199, 192, 243));
	tetramino->createMaskFromColor(Color(195, 188, 241));
	tetramino->createMaskFromColor(Color(168, 157, 237));*/
	
	sqtex->loadFromImage(*tetramino);//новые тетрамино
	sqtex->setSmooth(true);

	//Создание спрайтов
	Sprite* sprite = new Sprite(*sqtex), * sprite_background = new Sprite(*tex_background), * sprite_table = new Sprite(*tex_table),
		* sprite_button_start_st1 = new Sprite(*button_start_st1), * sprite_button_start_st2 = new Sprite(*button_start_st2), * sprite_button_start_st3 = new Sprite(*button_start_st3),
		* sprite_button_newgame_st1 = new Sprite(*button_newgame_st1), * sprite_button_newgame_st2 = new Sprite(*button_newgame_st2), * sprite_button_newgame_st3 = new Sprite(*button_newgame_st3),
		* sprite_button_options_st1 = new Sprite(*button_options_st1), * sprite_button_options_st2 = new Sprite(*button_options_st2), * sprite_button_options_st3 = new Sprite(*button_options_st3),
		* sprite_button_left_st1 = new Sprite(*button_left_st1), * sprite_button_left_st2 = new Sprite(*button_left_st2), * sprite_button_left_st3 = new Sprite(*button_left_st3),
		* sprite_button_right_st1 = new Sprite(*button_right_st1), * sprite_button_right_st2 = new Sprite(*button_right_st2), * sprite_button_right_st3 = new Sprite(*button_right_st3),
		* sprite_button_middle_restore_st1 = new Sprite(*button_middle_restore_st1), * sprite_button_middle_restore_st2 = new Sprite(*button_middle_restore_st2), * sprite_button_middle_restore_st3 = new Sprite(*button_middle_restore_st3),
		* sprite_button_pause_st1 = new Sprite(*button_pause_st1), * sprite_button_pause_st2 = new Sprite(*button_pause_st2), * sprite_button_pause_st3 = new Sprite(*button_pause_st3),
		* sprite_button_pause_st4 = new Sprite(*button_pause_st4),
		* sprite_button_soundOff_st1 = new Sprite(*button_soundOff_st1), * sprite_button_soundOff_st2 = new Sprite(*button_soundOff_st2), * sprite_button_soundOff_st3 = new Sprite(*button_soundOff_st3),
		* sprite_left_frame = new Sprite(*left_frame), * sprite_right_frame = new Sprite(*right_frame),
		* sprite_right_frame_bottom = new Sprite(*right_frame_bottom), * sprite_ays_frame = new Sprite(*ays_frame), * sprite_ays_question = new Sprite(*ays_question), * sprite_ays_yes1st = new Sprite(*ays_yes1st),
		* sprite_ays_yes2st = new Sprite(*ays_yes2st), * sprite_ays_no1st = new Sprite(*ays_no1st), * sprite_ays_no2st = new Sprite(*ays_no2st),
		* sprite_button_resume_st1 = new Sprite(*button_resume_st1), * sprite_button_resume_st2 = new Sprite(*button_resume_st2), * sprite_button_resume_st3 = new Sprite(*button_resume_st3),
		* sprite_button_soundOn_st1 = new Sprite(*button_soundOn_st1), * sprite_button_soundOn_st2 = new Sprite(*button_soundOn_st2), * sprite_button_soundOn_st3 = new Sprite(*button_soundOn_st3),
		* sprite_button_soundOn_st4 = new Sprite(*button_soundOn_st4),
		* sprite_button_musicOn_st1 = new Sprite(*button_musicOn_st1), * sprite_button_musicOn_st2 = new Sprite(*button_musicOn_st2), * sprite_button_musicOn_st3 = new Sprite(*button_musicOn_st3),
		* sprite_button_musicOn_st4 = new Sprite(*button_musicOn_st4),
		* sprite_button_musicOff_st1 = new Sprite(*button_musicOff_st1), * sprite_button_musicOff_st2 = new Sprite(*button_musicOff_st2), * sprite_button_musicOff_st3 = new Sprite(*button_musicOff_st3),

		* sprite_I_red = new Sprite(*I_red), * sprite_S_red = new Sprite(*S_red), * sprite_Z_red = new Sprite(*Z_red), * sprite_L_red = new Sprite(*L_red), * sprite_J_red = new Sprite(*J_red),
		* sprite_T_red = new Sprite(*T_red), * sprite_O_red = new Sprite(*O_red),

		* sprite_I_blue = new Sprite(*I_blue), * sprite_S_blue = new Sprite(*S_blue), * sprite_Z_blue = new Sprite(*Z_blue), * sprite_L_blue = new Sprite(*L_blue), * sprite_J_blue = new Sprite(*J_blue),
		* sprite_T_blue = new Sprite(*T_blue), * sprite_O_blue = new Sprite(*O_blue),

		* sprite_I_black = new Sprite(*I_black), * sprite_S_black = new Sprite(*S_black), * sprite_Z_black = new Sprite(*Z_black), * sprite_L_black = new Sprite(*L_black), * sprite_J_black = new Sprite(*J_black),
		* sprite_T_black = new Sprite(*T_black), * sprite_O_black = new Sprite(*O_black),

		* sprite_I_brown = new Sprite(*I_brown), * sprite_S_brown = new Sprite(*S_brown), * sprite_Z_brown = new Sprite(*Z_brown), * sprite_L_brown = new Sprite(*L_brown), * sprite_J_brown = new Sprite(*J_brown),
		* sprite_T_brown = new Sprite(*T_brown), * sprite_O_brown = new Sprite(*O_brown),

		* sprite_I_orange = new Sprite(*I_orange), * sprite_S_orange = new Sprite(*S_orange), * sprite_Z_orange = new Sprite(*Z_orange), * sprite_L_orange = new Sprite(*L_orange), * sprite_J_orange = new Sprite(*J_orange),
		* sprite_T_orange = new Sprite(*T_orange), * sprite_O_orange = new Sprite(*O_orange),

		* sprite_I_green = new Sprite(*I_green), * sprite_S_green = new Sprite(*S_green), * sprite_Z_green = new Sprite(*Z_green), * sprite_L_green = new Sprite(*L_green), * sprite_J_green = new Sprite(*J_green),
		* sprite_T_green = new Sprite(*T_green), * sprite_O_green = new Sprite(*O_green),

		* sprite_I_purple = new Sprite(*I_purple), * sprite_S_purple = new Sprite(*S_purple), * sprite_Z_purple = new Sprite(*Z_purple), * sprite_L_purple = new Sprite(*L_purple), * sprite_J_purple = new Sprite(*J_purple),
		* sprite_T_purple = new Sprite(*T_purple), * sprite_O_purple = new Sprite(*O_purple),

* sprite_I_pink = new Sprite(*I_pink), * sprite_S_pink = new Sprite(*S_pink), * sprite_Z_pink = new Sprite(*Z_pink), * sprite_L_pink = new Sprite(*L_pink), * sprite_J_pink = new Sprite(*J_pink),
* sprite_T_pink = new Sprite(*T_pink), * sprite_O_pink = new Sprite(*O_pink),

* sprite_I_yellow = new Sprite(*I_yellow), * sprite_S_yellow = new Sprite(*S_yellow), * sprite_Z_yellow = new Sprite(*Z_yellow), * sprite_L_yellow = new Sprite(*L_yellow), * sprite_J_yellow = new Sprite(*J_yellow),
* sprite_T_yellow = new Sprite(*T_yellow), * sprite_O_yellow = new Sprite(*O_yellow), * sprite_myCursor = new Sprite(*myCursor),

* spriteAn_1line_1 = new Sprite(*An_1line_1), * spriteAn_1line_2 = new Sprite(*An_1line_2), * spriteAn_1line_3 = new Sprite(*An_1line_3), * spriteAn_1line_4 = new Sprite(*An_1line_4),
* spriteAn_1line_5 = new Sprite(*An_1line_5), * spriteAn_1line_6 = new Sprite(*An_1line_6), * spriteAn_1line_7 = new Sprite(*An_1line_7), * spriteAn_1line_8 = new Sprite(*An_1line_8),
* spriteAn_1line_9 = new Sprite(*An_1line_9), * spriteAn_1line_10 = new Sprite(*An_1line_10), * spriteAn_1line_11 = new Sprite(*An_1line_11), * spriteAn_1line_12 = new Sprite(*An_1line_12),
* spriteAn_1line_13 = new Sprite(*An_1line_13), * spriteAn_1line_14 = new Sprite(*An_1line_14), * spriteAn_1line_15 = new Sprite(*An_1line_15), * spriteAn_1line_16 = new Sprite(*An_1line_16),
* spriteAn_1line_17 = new Sprite(*An_1line_17), * spriteAn_1line_18 = new Sprite(*An_1line_18), * spriteAn_1line_19 = new Sprite(*An_1line_19), * spriteAn_1line_20 = new Sprite(*An_1line_20),
* spriteAn_1line_21 = new Sprite(*An_1line_21), * spriteAn_1line_22 = new Sprite(*An_1line_22),

* spriteAn_2lines_1 = new Sprite(*An_2lines_1), * spriteAn_2lines_2 = new Sprite(*An_2lines_2), * spriteAn_2lines_3 = new Sprite(*An_2lines_3), * spriteAn_2lines_4 = new Sprite(*An_2lines_4),
* spriteAn_2lines_5 = new Sprite(*An_2lines_5), * spriteAn_2lines_6 = new Sprite(*An_2lines_6), * spriteAn_2lines_7 = new Sprite(*An_2lines_7), * spriteAn_2lines_8 = new Sprite(*An_2lines_8),
* spriteAn_2lines_9 = new Sprite(*An_2lines_9), * spriteAn_2lines_10 = new Sprite(*An_2lines_10), * spriteAn_2lines_11 = new Sprite(*An_2lines_11), * spriteAn_2lines_12 = new Sprite(*An_2lines_12),
* spriteAn_2lines_13 = new Sprite(*An_2lines_13), * spriteAn_2lines_14 = new Sprite(*An_2lines_14), * spriteAn_2lines_15 = new Sprite(*An_2lines_15), * spriteAn_2lines_16 = new Sprite(*An_2lines_16),
* spriteAn_2lines_17 = new Sprite(*An_2lines_17), * spriteAn_2lines_18 = new Sprite(*An_2lines_18), * spriteAn_2lines_19 = new Sprite(*An_2lines_19), * spriteAn_2lines_20 = new Sprite(*An_2lines_20),
* spriteAn_2lines_21 = new Sprite(*An_2lines_21), * spriteAn_2lines_22 = new Sprite(*An_2lines_22),

* spriteAn_3lines_1 = new Sprite(*An_3lines_1), * spriteAn_3lines_2 = new Sprite(*An_3lines_2), * spriteAn_3lines_3 = new Sprite(*An_3lines_3),
* spriteAn_3lines_4 = new Sprite(*An_3lines_4), * spriteAn_3lines_5 = new Sprite(*An_3lines_5), * spriteAn_3lines_6 = new Sprite(*An_3lines_6),
* spriteAn_3lines_7 = new Sprite(*An_3lines_7), * spriteAn_3lines_8 = new Sprite(*An_3lines_8), * spriteAn_3lines_9 = new Sprite(*An_3lines_9),
* spriteAn_3lines_10 = new Sprite(*An_3lines_10), * spriteAn_3lines_11 = new Sprite(*An_3lines_11), * spriteAn_3lines_12 = new Sprite(*An_3lines_12),
* spriteAn_3lines_13 = new Sprite(*An_3lines_13), * spriteAn_3lines_14 = new Sprite(*An_3lines_14), * spriteAn_3lines_15 = new Sprite(*An_3lines_15),
* spriteAn_3lines_16 = new Sprite(*An_3lines_16), * spriteAn_3lines_17 = new Sprite(*An_3lines_17), * spriteAn_3lines_18 = new Sprite(*An_3lines_18),
* spriteAn_3lines_19 = new Sprite(*An_3lines_19), * spriteAn_3lines_20 = new Sprite(*An_3lines_20), * spriteAn_3lines_21 = new Sprite(*An_3lines_21),
* spriteAn_3lines_22 = new Sprite(*An_3lines_22),

* spriteAn_4lines_1 = new Sprite(*An_4lines_1), * spriteAn_4lines_2 = new Sprite(*An_4lines_2), * spriteAn_4lines_3 = new Sprite(*An_4lines_3),
* spriteAn_4lines_4 = new Sprite(*An_4lines_4), * spriteAn_4lines_5 = new Sprite(*An_4lines_5), * spriteAn_4lines_6 = new Sprite(*An_4lines_6),
* spriteAn_4lines_7 = new Sprite(*An_4lines_7), * spriteAn_4lines_8 = new Sprite(*An_4lines_8), * spriteAn_4lines_9 = new Sprite(*An_4lines_9),
* spriteAn_4lines_10 = new Sprite(*An_4lines_10), * spriteAn_4lines_11 = new Sprite(*An_4lines_11), * spriteAn_4lines_12 = new Sprite(*An_4lines_12),
* spriteAn_4lines_13 = new Sprite(*An_4lines_13), * spriteAn_4lines_14 = new Sprite(*An_4lines_14), * spriteAn_4lines_15 = new Sprite(*An_4lines_15),
* spriteAn_4lines_16 = new Sprite(*An_4lines_16), * spriteAn_4lines_17 = new Sprite(*An_4lines_17), * spriteAn_4lines_18 = new Sprite(*An_4lines_18),
* spriteAn_4lines_19 = new Sprite(*An_4lines_19), * spriteAn_4lines_20 = new Sprite(*An_4lines_20), * spriteAn_4lines_21 = new Sprite(*An_4lines_21),
* spriteAn_4lines_22 = new Sprite(*An_4lines_22),

* spriteAn_3_inRow_16Rows_1 = new Sprite(*An_3_inRow_16Rows_1), * spriteAn_3_inRow_16Rows_2 = new Sprite(*An_3_inRow_16Rows_2), * spriteAn_3_inRow_16Rows_3 = new Sprite(*An_3_inRow_16Rows_3),
* spriteAn_3_inRow_16Rows_4 = new Sprite(*An_3_inRow_16Rows_4), * spriteAn_3_inRow_16Rows_5 = new Sprite(*An_3_inRow_16Rows_5), * spriteAn_3_inRow_16Rows_6 = new Sprite(*An_3_inRow_16Rows_6),
* spriteAn_3_inRow_16Rows_7 = new Sprite(*An_3_inRow_16Rows_7), * spriteAn_3_inRow_16Rows_8 = new Sprite(*An_3_inRow_16Rows_8), * spriteAn_3_inRow_16Rows_9 = new Sprite(*An_3_inRow_16Rows_9),
* spriteAn_3_inRow_16Rows_10 = new Sprite(*An_3_inRow_16Rows_10), * spriteAn_3_inRow_16Rows_11 = new Sprite(*An_3_inRow_16Rows_11), * spriteAn_3_inRow_16Rows_12 = new Sprite(*An_3_inRow_16Rows_12),

* spriteAn_1_inRow_1Row_1 = new Sprite(*An_1_inRow_1Row_1), * spriteAn_1_inRow_1Row_2 = new Sprite(*An_1_inRow_1Row_2),
* spriteAn_1_inRow_2Rows_1 = new Sprite(*An_1_inRow_2Rows_1), * spriteAn_1_inRow_2Rows_2 = new Sprite(*An_1_inRow_2Rows_2),
* spriteAn_1_inRow_3Rows_1 = new Sprite(*An_1_inRow_3Rows_1), * spriteAn_1_inRow_3Rows_2 = new Sprite(*An_1_inRow_3Rows_2),
* spriteAn_1_inRow_4Rows_1 = new Sprite(*An_1_inRow_4Rows_1), * spriteAn_1_inRow_4Rows_2 = new Sprite(*An_1_inRow_4Rows_2),
* spriteAn_1_inRow_4Rows_3 = new Sprite(*An_1_inRow_4Rows_3), * spriteAn_1_inRow_4Rows_4 = new Sprite(*An_1_inRow_4Rows_4),
* spriteAn_1_inRow_5Rows_1 = new Sprite(*An_1_inRow_5Rows_1), * spriteAn_1_inRow_5Rows_2 = new Sprite(*An_1_inRow_5Rows_2),
* spriteAn_1_inRow_5Rows_3 = new Sprite(*An_1_inRow_5Rows_3), * spriteAn_1_inRow_5Rows_4 = new Sprite(*An_1_inRow_5Rows_4),
* spriteAn_1_inRow_6Rows_1 = new Sprite(*An_1_inRow_6Rows_1), * spriteAn_1_inRow_6Rows_2 = new Sprite(*An_1_inRow_6Rows_2),
* spriteAn_1_inRow_6Rows_3 = new Sprite(*An_1_inRow_6Rows_3), * spriteAn_1_inRow_6Rows_4 = new Sprite(*An_1_inRow_6Rows_4),
* spriteAn_1_inRow_7Rows_1 = new Sprite(*An_1_inRow_7Rows_1), * spriteAn_1_inRow_7Rows_2 = new Sprite(*An_1_inRow_7Rows_2),
* spriteAn_1_inRow_7Rows_3 = new Sprite(*An_1_inRow_7Rows_3), * spriteAn_1_inRow_7Rows_4 = new Sprite(*An_1_inRow_7Rows_4),
* spriteAn_1_inRow_7Rows_5 = new Sprite(*An_1_inRow_7Rows_5), * spriteAn_1_inRow_7Rows_6 = new Sprite(*An_1_inRow_7Rows_6),
* spriteAn_1_inRow_8Rows_1 = new Sprite(*An_1_inRow_8Rows_1), * spriteAn_1_inRow_8Rows_2 = new Sprite(*An_1_inRow_8Rows_2),
* spriteAn_1_inRow_8Rows_3 = new Sprite(*An_1_inRow_8Rows_3), * spriteAn_1_inRow_8Rows_4 = new Sprite(*An_1_inRow_8Rows_4),
* spriteAn_1_inRow_8Rows_5 = new Sprite(*An_1_inRow_8Rows_5), * spriteAn_1_inRow_8Rows_6 = new Sprite(*An_1_inRow_8Rows_6),
* spriteAn_1_inRow_9Rows_1 = new Sprite(*An_1_inRow_9Rows_1), * spriteAn_1_inRow_9Rows_2 = new Sprite(*An_1_inRow_9Rows_2),
* spriteAn_1_inRow_9Rows_3 = new Sprite(*An_1_inRow_9Rows_3), * spriteAn_1_inRow_9Rows_4 = new Sprite(*An_1_inRow_9Rows_4),
* spriteAn_1_inRow_9Rows_5 = new Sprite(*An_1_inRow_9Rows_5), * spriteAn_1_inRow_9Rows_6 = new Sprite(*An_1_inRow_9Rows_6),
* spriteAn_1_inRow_10Rows_1 = new Sprite(*An_1_inRow_10Rows_1), * spriteAn_1_inRow_10Rows_2 = new Sprite(*An_1_inRow_10Rows_2),
* spriteAn_1_inRow_10Rows_3 = new Sprite(*An_1_inRow_10Rows_3), * spriteAn_1_inRow_10Rows_4 = new Sprite(*An_1_inRow_10Rows_4),
* spriteAn_1_inRow_10Rows_5 = new Sprite(*An_1_inRow_10Rows_5), * spriteAn_1_inRow_10Rows_6 = new Sprite(*An_1_inRow_10Rows_6),
* spriteAn_1_inRow_10Rows_7 = new Sprite(*An_1_inRow_10Rows_7), * spriteAn_1_inRow_10Rows_8 = new Sprite(*An_1_inRow_10Rows_8),
* spriteAn_1_inRow_11Rows_1 = new Sprite(*An_1_inRow_11Rows_1), * spriteAn_1_inRow_11Rows_2 = new Sprite(*An_1_inRow_11Rows_2),
* spriteAn_1_inRow_11Rows_3 = new Sprite(*An_1_inRow_11Rows_3), * spriteAn_1_inRow_11Rows_4 = new Sprite(*An_1_inRow_11Rows_4),
* spriteAn_1_inRow_11Rows_5 = new Sprite(*An_1_inRow_11Rows_5), * spriteAn_1_inRow_11Rows_6 = new Sprite(*An_1_inRow_11Rows_6),
* spriteAn_1_inRow_11Rows_7 = new Sprite(*An_1_inRow_11Rows_7), * spriteAn_1_inRow_11Rows_8 = new Sprite(*An_1_inRow_11Rows_8),
* spriteAn_1_inRow_12Rows_1 = new Sprite(*An_1_inRow_12Rows_1), * spriteAn_1_inRow_12Rows_2 = new Sprite(*An_1_inRow_12Rows_2),
* spriteAn_1_inRow_12Rows_3 = new Sprite(*An_1_inRow_12Rows_3), * spriteAn_1_inRow_12Rows_4 = new Sprite(*An_1_inRow_12Rows_4),
* spriteAn_1_inRow_12Rows_5 = new Sprite(*An_1_inRow_12Rows_5), * spriteAn_1_inRow_12Rows_6 = new Sprite(*An_1_inRow_12Rows_6),
* spriteAn_1_inRow_12Rows_7 = new Sprite(*An_1_inRow_12Rows_7), * spriteAn_1_inRow_12Rows_8 = new Sprite(*An_1_inRow_12Rows_8),
* spriteAn_1_inRow_13Rows_1 = new Sprite(*An_1_inRow_13Rows_1), * spriteAn_1_inRow_13Rows_2 = new Sprite(*An_1_inRow_13Rows_2),
* spriteAn_1_inRow_13Rows_3 = new Sprite(*An_1_inRow_13Rows_3), * spriteAn_1_inRow_13Rows_4 = new Sprite(*An_1_inRow_13Rows_4),
* spriteAn_1_inRow_13Rows_5 = new Sprite(*An_1_inRow_13Rows_5), * spriteAn_1_inRow_13Rows_6 = new Sprite(*An_1_inRow_13Rows_6),
* spriteAn_1_inRow_13Rows_7 = new Sprite(*An_1_inRow_13Rows_7), * spriteAn_1_inRow_13Rows_8 = new Sprite(*An_1_inRow_13Rows_8),
* spriteAn_1_inRow_13Rows_9 = new Sprite(*An_1_inRow_13Rows_9), * spriteAn_1_inRow_13Rows_10 = new Sprite(*An_1_inRow_13Rows_10),
* spriteAn_1_inRow_14Rows_1 = new Sprite(*An_1_inRow_14Rows_1), * spriteAn_1_inRow_14Rows_2 = new Sprite(*An_1_inRow_14Rows_2),
* spriteAn_1_inRow_14Rows_3 = new Sprite(*An_1_inRow_14Rows_3), * spriteAn_1_inRow_14Rows_4 = new Sprite(*An_1_inRow_14Rows_4),
* spriteAn_1_inRow_14Rows_5 = new Sprite(*An_1_inRow_14Rows_5), * spriteAn_1_inRow_14Rows_6 = new Sprite(*An_1_inRow_14Rows_6),
* spriteAn_1_inRow_14Rows_7 = new Sprite(*An_1_inRow_14Rows_7), * spriteAn_1_inRow_14Rows_8 = new Sprite(*An_1_inRow_14Rows_8),
* spriteAn_1_inRow_14Rows_9 = new Sprite(*An_1_inRow_14Rows_9), * spriteAn_1_inRow_14Rows_10 = new Sprite(*An_1_inRow_14Rows_10),
* spriteAn_1_inRow_15Rows_1 = new Sprite(*An_1_inRow_15Rows_1), * spriteAn_1_inRow_15Rows_2 = new Sprite(*An_1_inRow_15Rows_2),
* spriteAn_1_inRow_15Rows_3 = new Sprite(*An_1_inRow_15Rows_3), * spriteAn_1_inRow_15Rows_4 = new Sprite(*An_1_inRow_15Rows_4),
* spriteAn_1_inRow_15Rows_5 = new Sprite(*An_1_inRow_15Rows_5), * spriteAn_1_inRow_15Rows_6 = new Sprite(*An_1_inRow_15Rows_6),
* spriteAn_1_inRow_15Rows_7 = new Sprite(*An_1_inRow_15Rows_7), * spriteAn_1_inRow_15Rows_8 = new Sprite(*An_1_inRow_15Rows_8),
* spriteAn_1_inRow_15Rows_9 = new Sprite(*An_1_inRow_15Rows_9), * spriteAn_1_inRow_15Rows_10 = new Sprite(*An_1_inRow_15Rows_10),
* spriteAn_1_inRow_16Rows_1 = new Sprite(*An_1_inRow_16Rows_1), * spriteAn_1_inRow_16Rows_2 = new Sprite(*An_1_inRow_16Rows_2),
* spriteAn_1_inRow_16Rows_3 = new Sprite(*An_1_inRow_16Rows_3), * spriteAn_1_inRow_16Rows_4 = new Sprite(*An_1_inRow_16Rows_4),
* spriteAn_1_inRow_16Rows_5 = new Sprite(*An_1_inRow_16Rows_5), * spriteAn_1_inRow_16Rows_6 = new Sprite(*An_1_inRow_16Rows_6),
* spriteAn_1_inRow_16Rows_7 = new Sprite(*An_1_inRow_16Rows_7), * spriteAn_1_inRow_16Rows_8 = new Sprite(*An_1_inRow_16Rows_8),
* spriteAn_1_inRow_16Rows_9 = new Sprite(*An_1_inRow_16Rows_9), * spriteAn_1_inRow_16Rows_10 = new Sprite(*An_1_inRow_16Rows_10),
* spriteAn_1_inRow_16Rows_11 = new Sprite(*An_1_inRow_16Rows_11), * spriteAn_1_inRow_16Rows_12 = new Sprite(*An_1_inRow_16Rows_12),
* spriteAn_1_inRow_17Rows_1 = new Sprite(*An_1_inRow_17Rows_1), * spriteAn_1_inRow_17Rows_2 = new Sprite(*An_1_inRow_17Rows_2),
* spriteAn_1_inRow_17Rows_3 = new Sprite(*An_1_inRow_17Rows_3), * spriteAn_1_inRow_17Rows_4 = new Sprite(*An_1_inRow_17Rows_4),
* spriteAn_1_inRow_17Rows_5 = new Sprite(*An_1_inRow_17Rows_5), * spriteAn_1_inRow_17Rows_6 = new Sprite(*An_1_inRow_17Rows_6),
* spriteAn_1_inRow_17Rows_7 = new Sprite(*An_1_inRow_17Rows_7), * spriteAn_1_inRow_17Rows_8 = new Sprite(*An_1_inRow_17Rows_8),
* spriteAn_1_inRow_17Rows_9 = new Sprite(*An_1_inRow_17Rows_9), * spriteAn_1_inRow_17Rows_10 = new Sprite(*An_1_inRow_17Rows_10),
* spriteAn_1_inRow_17Rows_11 = new Sprite(*An_1_inRow_17Rows_11), * spriteAn_1_inRow_17Rows_12 = new Sprite(*An_1_inRow_17Rows_12),

* spriteAn_2_inRow_1Row_1 = new Sprite(*An_2_inRow_1Row_1), * spriteAn_2_inRow_1Row_2 = new Sprite(*An_2_inRow_1Row_2),
* spriteAn_2_inRow_2Rows_1 = new Sprite(*An_2_inRow_2Rows_1), * spriteAn_2_inRow_2Rows_2 = new Sprite(*An_2_inRow_2Rows_2),
* spriteAn_2_inRow_3Rows_1 = new Sprite(*An_2_inRow_3Rows_1), * spriteAn_2_inRow_3Rows_2 = new Sprite(*An_2_inRow_3Rows_2),
* spriteAn_2_inRow_4Rows_1 = new Sprite(*An_2_inRow_4Rows_1), * spriteAn_2_inRow_4Rows_2 = new Sprite(*An_2_inRow_4Rows_2),
* spriteAn_2_inRow_4Rows_3 = new Sprite(*An_2_inRow_4Rows_3), * spriteAn_2_inRow_4Rows_4 = new Sprite(*An_2_inRow_4Rows_4),
* spriteAn_2_inRow_5Rows_1 = new Sprite(*An_2_inRow_5Rows_1), * spriteAn_2_inRow_5Rows_2 = new Sprite(*An_2_inRow_5Rows_2),
* spriteAn_2_inRow_5Rows_3 = new Sprite(*An_2_inRow_5Rows_3), * spriteAn_2_inRow_5Rows_4 = new Sprite(*An_2_inRow_5Rows_4),
* spriteAn_2_inRow_6Rows_1 = new Sprite(*An_2_inRow_6Rows_1), * spriteAn_2_inRow_6Rows_2 = new Sprite(*An_2_inRow_6Rows_2),
* spriteAn_2_inRow_6Rows_3 = new Sprite(*An_2_inRow_6Rows_3), * spriteAn_2_inRow_6Rows_4 = new Sprite(*An_2_inRow_6Rows_4),
* spriteAn_2_inRow_7Rows_1 = new Sprite(*An_2_inRow_7Rows_1), * spriteAn_2_inRow_7Rows_2 = new Sprite(*An_2_inRow_7Rows_2),
* spriteAn_2_inRow_7Rows_3 = new Sprite(*An_2_inRow_7Rows_3), * spriteAn_2_inRow_7Rows_4 = new Sprite(*An_2_inRow_7Rows_4),
* spriteAn_2_inRow_7Rows_5 = new Sprite(*An_2_inRow_7Rows_5), * spriteAn_2_inRow_7Rows_6 = new Sprite(*An_2_inRow_7Rows_6),
* spriteAn_2_inRow_8Rows_1 = new Sprite(*An_2_inRow_8Rows_1), * spriteAn_2_inRow_8Rows_2 = new Sprite(*An_2_inRow_8Rows_2),
* spriteAn_2_inRow_8Rows_3 = new Sprite(*An_2_inRow_8Rows_3), * spriteAn_2_inRow_8Rows_4 = new Sprite(*An_2_inRow_8Rows_4),
* spriteAn_2_inRow_8Rows_5 = new Sprite(*An_2_inRow_8Rows_5), * spriteAn_2_inRow_8Rows_6 = new Sprite(*An_2_inRow_8Rows_6),
* spriteAn_2_inRow_9Rows_1 = new Sprite(*An_2_inRow_9Rows_1), * spriteAn_2_inRow_9Rows_2 = new Sprite(*An_2_inRow_9Rows_2),
* spriteAn_2_inRow_9Rows_3 = new Sprite(*An_2_inRow_9Rows_3), * spriteAn_2_inRow_9Rows_4 = new Sprite(*An_2_inRow_9Rows_4),
* spriteAn_2_inRow_9Rows_5 = new Sprite(*An_2_inRow_9Rows_5), * spriteAn_2_inRow_9Rows_6 = new Sprite(*An_2_inRow_9Rows_6),
* spriteAn_2_inRow_10Rows_1 = new Sprite(*An_2_inRow_10Rows_1), * spriteAn_2_inRow_10Rows_2 = new Sprite(*An_2_inRow_10Rows_2),
* spriteAn_2_inRow_10Rows_3 = new Sprite(*An_2_inRow_10Rows_3), * spriteAn_2_inRow_10Rows_4 = new Sprite(*An_2_inRow_10Rows_4),
* spriteAn_2_inRow_10Rows_5 = new Sprite(*An_2_inRow_10Rows_5), * spriteAn_2_inRow_10Rows_6 = new Sprite(*An_2_inRow_10Rows_6),
* spriteAn_2_inRow_10Rows_7 = new Sprite(*An_2_inRow_10Rows_7), * spriteAn_2_inRow_10Rows_8 = new Sprite(*An_2_inRow_10Rows_8),
* spriteAn_2_inRow_11Rows_1 = new Sprite(*An_2_inRow_11Rows_1), * spriteAn_2_inRow_11Rows_2 = new Sprite(*An_2_inRow_11Rows_2),
* spriteAn_2_inRow_11Rows_3 = new Sprite(*An_2_inRow_11Rows_3), * spriteAn_2_inRow_11Rows_4 = new Sprite(*An_2_inRow_11Rows_4),
* spriteAn_2_inRow_11Rows_5 = new Sprite(*An_2_inRow_11Rows_5), * spriteAn_2_inRow_11Rows_6 = new Sprite(*An_2_inRow_11Rows_6),
* spriteAn_2_inRow_11Rows_7 = new Sprite(*An_2_inRow_11Rows_7), * spriteAn_2_inRow_11Rows_8 = new Sprite(*An_2_inRow_11Rows_8),
* spriteAn_2_inRow_12Rows_1 = new Sprite(*An_2_inRow_12Rows_1), * spriteAn_2_inRow_12Rows_2 = new Sprite(*An_2_inRow_12Rows_2),
* spriteAn_2_inRow_12Rows_3 = new Sprite(*An_2_inRow_12Rows_3), * spriteAn_2_inRow_12Rows_4 = new Sprite(*An_2_inRow_12Rows_4),
* spriteAn_2_inRow_12Rows_5 = new Sprite(*An_2_inRow_12Rows_5), * spriteAn_2_inRow_12Rows_6 = new Sprite(*An_2_inRow_12Rows_6),
* spriteAn_2_inRow_12Rows_7 = new Sprite(*An_2_inRow_12Rows_7), * spriteAn_2_inRow_12Rows_8 = new Sprite(*An_2_inRow_12Rows_8),
* spriteAn_2_inRow_13Rows_1 = new Sprite(*An_2_inRow_13Rows_1), * spriteAn_2_inRow_13Rows_2 = new Sprite(*An_2_inRow_13Rows_2),
* spriteAn_2_inRow_13Rows_3 = new Sprite(*An_2_inRow_13Rows_3), * spriteAn_2_inRow_13Rows_4 = new Sprite(*An_2_inRow_13Rows_4),
* spriteAn_2_inRow_13Rows_5 = new Sprite(*An_2_inRow_13Rows_5), * spriteAn_2_inRow_13Rows_6 = new Sprite(*An_2_inRow_13Rows_6),
* spriteAn_2_inRow_13Rows_7 = new Sprite(*An_2_inRow_13Rows_7), * spriteAn_2_inRow_13Rows_8 = new Sprite(*An_2_inRow_13Rows_8),
* spriteAn_2_inRow_13Rows_9 = new Sprite(*An_2_inRow_13Rows_9), * spriteAn_2_inRow_13Rows_10 = new Sprite(*An_2_inRow_13Rows_10),
* spriteAn_2_inRow_14Rows_1 = new Sprite(*An_2_inRow_14Rows_1), * spriteAn_2_inRow_14Rows_2 = new Sprite(*An_2_inRow_14Rows_2),
* spriteAn_2_inRow_14Rows_3 = new Sprite(*An_2_inRow_14Rows_3), * spriteAn_2_inRow_14Rows_4 = new Sprite(*An_2_inRow_14Rows_4),
* spriteAn_2_inRow_14Rows_5 = new Sprite(*An_2_inRow_14Rows_5), * spriteAn_2_inRow_14Rows_6 = new Sprite(*An_2_inRow_14Rows_6),
* spriteAn_2_inRow_14Rows_7 = new Sprite(*An_2_inRow_14Rows_7), * spriteAn_2_inRow_14Rows_8 = new Sprite(*An_2_inRow_14Rows_8),
* spriteAn_2_inRow_14Rows_9 = new Sprite(*An_2_inRow_14Rows_9), * spriteAn_2_inRow_14Rows_10 = new Sprite(*An_2_inRow_14Rows_10),
* spriteAn_2_inRow_15Rows_1 = new Sprite(*An_2_inRow_15Rows_1), * spriteAn_2_inRow_15Rows_2 = new Sprite(*An_2_inRow_15Rows_2),
* spriteAn_2_inRow_15Rows_3 = new Sprite(*An_2_inRow_15Rows_3), * spriteAn_2_inRow_15Rows_4 = new Sprite(*An_2_inRow_15Rows_4),
* spriteAn_2_inRow_15Rows_5 = new Sprite(*An_2_inRow_15Rows_5), * spriteAn_2_inRow_15Rows_6 = new Sprite(*An_2_inRow_15Rows_6),
* spriteAn_2_inRow_15Rows_7 = new Sprite(*An_2_inRow_15Rows_7), * spriteAn_2_inRow_15Rows_8 = new Sprite(*An_2_inRow_15Rows_8),
* spriteAn_2_inRow_15Rows_9 = new Sprite(*An_2_inRow_15Rows_9), * spriteAn_2_inRow_15Rows_10 = new Sprite(*An_2_inRow_15Rows_10),
* spriteAn_2_inRow_16Rows_1 = new Sprite(*An_2_inRow_16Rows_1), * spriteAn_2_inRow_16Rows_2 = new Sprite(*An_2_inRow_16Rows_2),
* spriteAn_2_inRow_16Rows_3 = new Sprite(*An_2_inRow_16Rows_3), * spriteAn_2_inRow_16Rows_4 = new Sprite(*An_2_inRow_16Rows_4),
* spriteAn_2_inRow_16Rows_5 = new Sprite(*An_2_inRow_16Rows_5), * spriteAn_2_inRow_16Rows_6 = new Sprite(*An_2_inRow_16Rows_6),
* spriteAn_2_inRow_16Rows_7 = new Sprite(*An_2_inRow_16Rows_7), * spriteAn_2_inRow_16Rows_8 = new Sprite(*An_2_inRow_16Rows_8),
* spriteAn_2_inRow_16Rows_9 = new Sprite(*An_2_inRow_16Rows_9), * spriteAn_2_inRow_16Rows_10 = new Sprite(*An_2_inRow_16Rows_10),
* spriteAn_2_inRow_16Rows_11 = new Sprite(*An_2_inRow_16Rows_11), * spriteAn_2_inRow_16Rows_12 = new Sprite(*An_2_inRow_16Rows_12),
* spriteAn_2_inRow_17Rows_1 = new Sprite(*An_2_inRow_17Rows_1), * spriteAn_2_inRow_17Rows_2 = new Sprite(*An_2_inRow_17Rows_2),
* spriteAn_2_inRow_17Rows_3 = new Sprite(*An_2_inRow_17Rows_3), * spriteAn_2_inRow_17Rows_4 = new Sprite(*An_2_inRow_17Rows_4),
* spriteAn_2_inRow_17Rows_5 = new Sprite(*An_2_inRow_17Rows_5), * spriteAn_2_inRow_17Rows_6 = new Sprite(*An_2_inRow_17Rows_6),
* spriteAn_2_inRow_17Rows_7 = new Sprite(*An_2_inRow_17Rows_7), * spriteAn_2_inRow_17Rows_8 = new Sprite(*An_2_inRow_17Rows_8),
* spriteAn_2_inRow_17Rows_9 = new Sprite(*An_2_inRow_17Rows_9), * spriteAn_2_inRow_17Rows_10 = new Sprite(*An_2_inRow_17Rows_10),
* spriteAn_2_inRow_17Rows_11 = new Sprite(*An_2_inRow_17Rows_11), * spriteAn_2_inRow_17Rows_12 = new Sprite(*An_2_inRow_17Rows_12),

* spriteAn_3_inRow_1Row_1 = new Sprite(*An_3_inRow_1Row_1), * spriteAn_3_inRow_1Row_2 = new Sprite(*An_3_inRow_1Row_2),
* spriteAn_3_inRow_2Rows_1 = new Sprite(*An_3_inRow_2Rows_1), * spriteAn_3_inRow_2Rows_2 = new Sprite(*An_3_inRow_2Rows_2),
* spriteAn_3_inRow_3Rows_1 = new Sprite(*An_3_inRow_3Rows_1), * spriteAn_3_inRow_3Rows_2 = new Sprite(*An_3_inRow_3Rows_2),
* spriteAn_3_inRow_4Rows_1 = new Sprite(*An_3_inRow_4Rows_1), * spriteAn_3_inRow_4Rows_2 = new Sprite(*An_3_inRow_4Rows_2),
* spriteAn_3_inRow_4Rows_3 = new Sprite(*An_3_inRow_4Rows_3), * spriteAn_3_inRow_4Rows_4 = new Sprite(*An_3_inRow_4Rows_4),
* spriteAn_3_inRow_5Rows_1 = new Sprite(*An_3_inRow_5Rows_1), * spriteAn_3_inRow_5Rows_2 = new Sprite(*An_3_inRow_5Rows_2),
* spriteAn_3_inRow_5Rows_3 = new Sprite(*An_3_inRow_5Rows_3), * spriteAn_3_inRow_5Rows_4 = new Sprite(*An_3_inRow_5Rows_4),
* spriteAn_3_inRow_6Rows_1 = new Sprite(*An_3_inRow_6Rows_1), * spriteAn_3_inRow_6Rows_2 = new Sprite(*An_3_inRow_6Rows_2),
* spriteAn_3_inRow_6Rows_3 = new Sprite(*An_3_inRow_6Rows_3), * spriteAn_3_inRow_6Rows_4 = new Sprite(*An_3_inRow_6Rows_4),
* spriteAn_3_inRow_7Rows_1 = new Sprite(*An_3_inRow_7Rows_1), * spriteAn_3_inRow_7Rows_2 = new Sprite(*An_3_inRow_7Rows_2),
* spriteAn_3_inRow_7Rows_3 = new Sprite(*An_3_inRow_7Rows_3), * spriteAn_3_inRow_7Rows_4 = new Sprite(*An_3_inRow_7Rows_4),
* spriteAn_3_inRow_7Rows_5 = new Sprite(*An_3_inRow_7Rows_5), * spriteAn_3_inRow_7Rows_6 = new Sprite(*An_3_inRow_7Rows_6),
* spriteAn_3_inRow_8Rows_1 = new Sprite(*An_3_inRow_8Rows_1), * spriteAn_3_inRow_8Rows_2 = new Sprite(*An_3_inRow_8Rows_2),
* spriteAn_3_inRow_8Rows_3 = new Sprite(*An_3_inRow_8Rows_3), * spriteAn_3_inRow_8Rows_4 = new Sprite(*An_3_inRow_8Rows_4),
* spriteAn_3_inRow_8Rows_5 = new Sprite(*An_3_inRow_8Rows_5), * spriteAn_3_inRow_8Rows_6 = new Sprite(*An_3_inRow_8Rows_6),
* spriteAn_3_inRow_9Rows_1 = new Sprite(*An_3_inRow_9Rows_1), * spriteAn_3_inRow_9Rows_2 = new Sprite(*An_3_inRow_9Rows_2),
* spriteAn_3_inRow_9Rows_3 = new Sprite(*An_3_inRow_9Rows_3), * spriteAn_3_inRow_9Rows_4 = new Sprite(*An_3_inRow_9Rows_4),
* spriteAn_3_inRow_9Rows_5 = new Sprite(*An_3_inRow_9Rows_5), * spriteAn_3_inRow_9Rows_6 = new Sprite(*An_3_inRow_9Rows_6),
* spriteAn_3_inRow_10Rows_1 = new Sprite(*An_3_inRow_10Rows_1), * spriteAn_3_inRow_10Rows_2 = new Sprite(*An_3_inRow_10Rows_2),
* spriteAn_3_inRow_10Rows_3 = new Sprite(*An_3_inRow_10Rows_3), * spriteAn_3_inRow_10Rows_4 = new Sprite(*An_3_inRow_10Rows_4),
* spriteAn_3_inRow_10Rows_5 = new Sprite(*An_3_inRow_10Rows_5), * spriteAn_3_inRow_10Rows_6 = new Sprite(*An_3_inRow_10Rows_6),
* spriteAn_3_inRow_10Rows_7 = new Sprite(*An_3_inRow_10Rows_7), * spriteAn_3_inRow_10Rows_8 = new Sprite(*An_3_inRow_10Rows_8),
* spriteAn_3_inRow_11Rows_1 = new Sprite(*An_3_inRow_11Rows_1), * spriteAn_3_inRow_11Rows_2 = new Sprite(*An_3_inRow_11Rows_2),
* spriteAn_3_inRow_11Rows_3 = new Sprite(*An_3_inRow_11Rows_3), * spriteAn_3_inRow_11Rows_4 = new Sprite(*An_3_inRow_11Rows_4),
* spriteAn_3_inRow_11Rows_5 = new Sprite(*An_3_inRow_11Rows_5), * spriteAn_3_inRow_11Rows_6 = new Sprite(*An_3_inRow_11Rows_6),
* spriteAn_3_inRow_11Rows_7 = new Sprite(*An_3_inRow_11Rows_7), * spriteAn_3_inRow_11Rows_8 = new Sprite(*An_3_inRow_11Rows_8),
* spriteAn_3_inRow_12Rows_1 = new Sprite(*An_3_inRow_12Rows_1), * spriteAn_3_inRow_12Rows_2 = new Sprite(*An_3_inRow_12Rows_2),
* spriteAn_3_inRow_12Rows_3 = new Sprite(*An_3_inRow_12Rows_3), * spriteAn_3_inRow_12Rows_4 = new Sprite(*An_3_inRow_12Rows_4),
* spriteAn_3_inRow_12Rows_5 = new Sprite(*An_3_inRow_12Rows_5), * spriteAn_3_inRow_12Rows_6 = new Sprite(*An_3_inRow_12Rows_6),
* spriteAn_3_inRow_12Rows_7 = new Sprite(*An_3_inRow_12Rows_7), * spriteAn_3_inRow_12Rows_8 = new Sprite(*An_3_inRow_12Rows_8),
* spriteAn_3_inRow_13Rows_1 = new Sprite(*An_3_inRow_13Rows_1), * spriteAn_3_inRow_13Rows_2 = new Sprite(*An_3_inRow_13Rows_2),
* spriteAn_3_inRow_13Rows_3 = new Sprite(*An_3_inRow_13Rows_3), * spriteAn_3_inRow_13Rows_4 = new Sprite(*An_3_inRow_13Rows_4),
* spriteAn_3_inRow_13Rows_5 = new Sprite(*An_3_inRow_13Rows_5), * spriteAn_3_inRow_13Rows_6 = new Sprite(*An_3_inRow_13Rows_6),
* spriteAn_3_inRow_13Rows_7 = new Sprite(*An_3_inRow_13Rows_7), * spriteAn_3_inRow_13Rows_8 = new Sprite(*An_3_inRow_13Rows_8),
* spriteAn_3_inRow_13Rows_9 = new Sprite(*An_3_inRow_13Rows_9), * spriteAn_3_inRow_13Rows_10 = new Sprite(*An_3_inRow_13Rows_10),
* spriteAn_3_inRow_14Rows_1 = new Sprite(*An_3_inRow_14Rows_1), * spriteAn_3_inRow_14Rows_2 = new Sprite(*An_3_inRow_14Rows_2),
* spriteAn_3_inRow_14Rows_3 = new Sprite(*An_3_inRow_14Rows_3), * spriteAn_3_inRow_14Rows_4 = new Sprite(*An_3_inRow_14Rows_4),
* spriteAn_3_inRow_14Rows_5 = new Sprite(*An_3_inRow_14Rows_5), * spriteAn_3_inRow_14Rows_6 = new Sprite(*An_3_inRow_14Rows_6),
* spriteAn_3_inRow_14Rows_7 = new Sprite(*An_3_inRow_14Rows_7), * spriteAn_3_inRow_14Rows_8 = new Sprite(*An_3_inRow_14Rows_8),
* spriteAn_3_inRow_14Rows_9 = new Sprite(*An_3_inRow_14Rows_9), * spriteAn_3_inRow_14Rows_10 = new Sprite(*An_3_inRow_14Rows_10),
* spriteAn_3_inRow_15Rows_1 = new Sprite(*An_3_inRow_15Rows_1), * spriteAn_3_inRow_15Rows_2 = new Sprite(*An_3_inRow_15Rows_2),
* spriteAn_3_inRow_15Rows_3 = new Sprite(*An_3_inRow_15Rows_3), * spriteAn_3_inRow_15Rows_4 = new Sprite(*An_3_inRow_15Rows_4),
* spriteAn_3_inRow_15Rows_5 = new Sprite(*An_3_inRow_15Rows_5), * spriteAn_3_inRow_15Rows_6 = new Sprite(*An_3_inRow_15Rows_6),
* spriteAn_3_inRow_15Rows_7 = new Sprite(*An_3_inRow_15Rows_7), * spriteAn_3_inRow_15Rows_8 = new Sprite(*An_3_inRow_15Rows_8),
* spriteAn_3_inRow_15Rows_9 = new Sprite(*An_3_inRow_15Rows_9), * spriteAn_3_inRow_15Rows_10 = new Sprite(*An_3_inRow_15Rows_10),
* spriteAn_3_inRow_17Rows_1 = new Sprite(*An_3_inRow_17Rows_1), * spriteAn_3_inRow_17Rows_2 = new Sprite(*An_3_inRow_17Rows_2),
* spriteAn_3_inRow_17Rows_3 = new Sprite(*An_3_inRow_17Rows_3), * spriteAn_3_inRow_17Rows_4 = new Sprite(*An_3_inRow_17Rows_4),
* spriteAn_3_inRow_17Rows_5 = new Sprite(*An_3_inRow_17Rows_5), * spriteAn_3_inRow_17Rows_6 = new Sprite(*An_3_inRow_17Rows_6),
* spriteAn_3_inRow_17Rows_7 = new Sprite(*An_3_inRow_17Rows_7), * spriteAn_3_inRow_17Rows_8 = new Sprite(*An_3_inRow_17Rows_8),
* spriteAn_3_inRow_17Rows_9 = new Sprite(*An_3_inRow_17Rows_9), * spriteAn_3_inRow_17Rows_10 = new Sprite(*An_3_inRow_17Rows_10),
* spriteAn_3_inRow_17Rows_11 = new Sprite(*An_3_inRow_17Rows_11), * spriteAn_3_inRow_17Rows_12 = new Sprite(*An_3_inRow_17Rows_12),
* spriteAn_3_inRow_18Rows_1 = new Sprite(*An_3_inRow_18Rows_1), * spriteAn_3_inRow_18Rows_2 = new Sprite(*An_3_inRow_18Rows_2),
* spriteAn_3_inRow_18Rows_3 = new Sprite(*An_3_inRow_18Rows_3), * spriteAn_3_inRow_18Rows_4 = new Sprite(*An_3_inRow_18Rows_4),
* spriteAn_3_inRow_18Rows_5 = new Sprite(*An_3_inRow_18Rows_5), * spriteAn_3_inRow_18Rows_6 = new Sprite(*An_3_inRow_18Rows_6),
* spriteAn_3_inRow_18Rows_7 = new Sprite(*An_3_inRow_18Rows_7), * spriteAn_3_inRow_18Rows_8 = new Sprite(*An_3_inRow_18Rows_8),
* spriteAn_3_inRow_18Rows_9 = new Sprite(*An_3_inRow_18Rows_9), * spriteAn_3_inRow_18Rows_10 = new Sprite(*An_3_inRow_18Rows_10),
* spriteAn_3_inRow_18Rows_11 = new Sprite(*An_3_inRow_18Rows_11), * spriteAn_3_inRow_18Rows_12 = new Sprite(*An_3_inRow_18Rows_12),

* spriteAn_4_inRow_1Row_1 = new Sprite(*An_4_inRow_1Row_1), * spriteAn_4_inRow_1Row_2 = new Sprite(*An_4_inRow_1Row_2),
* spriteAn_4_inRow_2Rows_1 = new Sprite(*An_4_inRow_2Rows_1), * spriteAn_4_inRow_2Rows_2 = new Sprite(*An_4_inRow_2Rows_2),
* spriteAn_4_inRow_3Rows_1 = new Sprite(*An_4_inRow_3Rows_1), * spriteAn_4_inRow_3Rows_2 = new Sprite(*An_4_inRow_3Rows_2),
* spriteAn_4_inRow_4Rows_1 = new Sprite(*An_4_inRow_4Rows_1), * spriteAn_4_inRow_4Rows_2 = new Sprite(*An_4_inRow_4Rows_2),
* spriteAn_4_inRow_4Rows_3 = new Sprite(*An_4_inRow_4Rows_3), * spriteAn_4_inRow_4Rows_4 = new Sprite(*An_4_inRow_4Rows_4),
* spriteAn_4_inRow_5Rows_1 = new Sprite(*An_4_inRow_5Rows_1), * spriteAn_4_inRow_5Rows_2 = new Sprite(*An_4_inRow_5Rows_2),
* spriteAn_4_inRow_5Rows_3 = new Sprite(*An_4_inRow_5Rows_3), * spriteAn_4_inRow_5Rows_4 = new Sprite(*An_4_inRow_5Rows_4),
* spriteAn_4_inRow_6Rows_1 = new Sprite(*An_4_inRow_6Rows_1), * spriteAn_4_inRow_6Rows_2 = new Sprite(*An_4_inRow_6Rows_2),
* spriteAn_4_inRow_6Rows_3 = new Sprite(*An_4_inRow_6Rows_3), * spriteAn_4_inRow_6Rows_4 = new Sprite(*An_4_inRow_6Rows_4),
* spriteAn_4_inRow_7Rows_1 = new Sprite(*An_4_inRow_7Rows_1), * spriteAn_4_inRow_7Rows_2 = new Sprite(*An_4_inRow_7Rows_2),
* spriteAn_4_inRow_7Rows_3 = new Sprite(*An_4_inRow_7Rows_3), * spriteAn_4_inRow_7Rows_4 = new Sprite(*An_4_inRow_7Rows_4),
* spriteAn_4_inRow_7Rows_5 = new Sprite(*An_4_inRow_7Rows_5), * spriteAn_4_inRow_7Rows_6 = new Sprite(*An_4_inRow_7Rows_6),
* spriteAn_4_inRow_8Rows_1 = new Sprite(*An_4_inRow_8Rows_1), * spriteAn_4_inRow_8Rows_2 = new Sprite(*An_4_inRow_8Rows_2),
* spriteAn_4_inRow_8Rows_3 = new Sprite(*An_4_inRow_8Rows_3), * spriteAn_4_inRow_8Rows_4 = new Sprite(*An_4_inRow_8Rows_4),
* spriteAn_4_inRow_8Rows_5 = new Sprite(*An_4_inRow_8Rows_5), * spriteAn_4_inRow_8Rows_6 = new Sprite(*An_4_inRow_8Rows_6),
* spriteAn_4_inRow_9Rows_1 = new Sprite(*An_4_inRow_9Rows_1), * spriteAn_4_inRow_9Rows_2 = new Sprite(*An_4_inRow_9Rows_2),
* spriteAn_4_inRow_9Rows_3 = new Sprite(*An_4_inRow_9Rows_3), * spriteAn_4_inRow_9Rows_4 = new Sprite(*An_4_inRow_9Rows_4),
* spriteAn_4_inRow_9Rows_5 = new Sprite(*An_4_inRow_9Rows_5), * spriteAn_4_inRow_9Rows_6 = new Sprite(*An_4_inRow_9Rows_6),
* spriteAn_4_inRow_10Rows_1 = new Sprite(*An_4_inRow_10Rows_1), * spriteAn_4_inRow_10Rows_2 = new Sprite(*An_4_inRow_10Rows_2),
* spriteAn_4_inRow_10Rows_3 = new Sprite(*An_4_inRow_10Rows_3), * spriteAn_4_inRow_10Rows_4 = new Sprite(*An_4_inRow_10Rows_4),
* spriteAn_4_inRow_10Rows_5 = new Sprite(*An_4_inRow_10Rows_5), * spriteAn_4_inRow_10Rows_6 = new Sprite(*An_4_inRow_10Rows_6),
* spriteAn_4_inRow_10Rows_7 = new Sprite(*An_4_inRow_10Rows_7), * spriteAn_4_inRow_10Rows_8 = new Sprite(*An_4_inRow_10Rows_8),
* spriteAn_4_inRow_11Rows_1 = new Sprite(*An_4_inRow_11Rows_1), * spriteAn_4_inRow_11Rows_2 = new Sprite(*An_4_inRow_11Rows_2),
* spriteAn_4_inRow_11Rows_3 = new Sprite(*An_4_inRow_11Rows_3), * spriteAn_4_inRow_11Rows_4 = new Sprite(*An_4_inRow_11Rows_4),
* spriteAn_4_inRow_11Rows_5 = new Sprite(*An_4_inRow_11Rows_5), * spriteAn_4_inRow_11Rows_6 = new Sprite(*An_4_inRow_11Rows_6),
* spriteAn_4_inRow_11Rows_7 = new Sprite(*An_4_inRow_11Rows_7), * spriteAn_4_inRow_11Rows_8 = new Sprite(*An_4_inRow_11Rows_8),
* spriteAn_4_inRow_12Rows_1 = new Sprite(*An_4_inRow_12Rows_1), * spriteAn_4_inRow_12Rows_2 = new Sprite(*An_4_inRow_12Rows_2),
* spriteAn_4_inRow_12Rows_3 = new Sprite(*An_4_inRow_12Rows_3), * spriteAn_4_inRow_12Rows_4 = new Sprite(*An_4_inRow_12Rows_4),
* spriteAn_4_inRow_12Rows_5 = new Sprite(*An_4_inRow_12Rows_5), * spriteAn_4_inRow_12Rows_6 = new Sprite(*An_4_inRow_12Rows_6),
* spriteAn_4_inRow_12Rows_7 = new Sprite(*An_4_inRow_12Rows_7), * spriteAn_4_inRow_12Rows_8 = new Sprite(*An_4_inRow_12Rows_8),
* spriteAn_4_inRow_13Rows_1 = new Sprite(*An_4_inRow_13Rows_1), * spriteAn_4_inRow_13Rows_2 = new Sprite(*An_4_inRow_13Rows_2),
* spriteAn_4_inRow_13Rows_3 = new Sprite(*An_4_inRow_13Rows_3), * spriteAn_4_inRow_13Rows_4 = new Sprite(*An_4_inRow_13Rows_4),
* spriteAn_4_inRow_13Rows_5 = new Sprite(*An_4_inRow_13Rows_5), * spriteAn_4_inRow_13Rows_6 = new Sprite(*An_4_inRow_13Rows_6),
* spriteAn_4_inRow_13Rows_7 = new Sprite(*An_4_inRow_13Rows_7), * spriteAn_4_inRow_13Rows_8 = new Sprite(*An_4_inRow_13Rows_8),
* spriteAn_4_inRow_13Rows_9 = new Sprite(*An_4_inRow_13Rows_9), * spriteAn_4_inRow_13Rows_10 = new Sprite(*An_4_inRow_13Rows_10),
* spriteAn_4_inRow_14Rows_1 = new Sprite(*An_4_inRow_14Rows_1), * spriteAn_4_inRow_14Rows_2 = new Sprite(*An_4_inRow_14Rows_2),
* spriteAn_4_inRow_14Rows_3 = new Sprite(*An_4_inRow_14Rows_3), * spriteAn_4_inRow_14Rows_4 = new Sprite(*An_4_inRow_14Rows_4),
* spriteAn_4_inRow_14Rows_5 = new Sprite(*An_4_inRow_14Rows_5), * spriteAn_4_inRow_14Rows_6 = new Sprite(*An_4_inRow_14Rows_6),
* spriteAn_4_inRow_14Rows_7 = new Sprite(*An_4_inRow_14Rows_7), * spriteAn_4_inRow_14Rows_8 = new Sprite(*An_4_inRow_14Rows_8),
* spriteAn_4_inRow_14Rows_9 = new Sprite(*An_4_inRow_14Rows_9), * spriteAn_4_inRow_14Rows_10 = new Sprite(*An_4_inRow_14Rows_10),
* spriteAn_4_inRow_15Rows_1 = new Sprite(*An_4_inRow_15Rows_1), * spriteAn_4_inRow_15Rows_2 = new Sprite(*An_4_inRow_15Rows_2),
* spriteAn_4_inRow_15Rows_3 = new Sprite(*An_4_inRow_15Rows_3), * spriteAn_4_inRow_15Rows_4 = new Sprite(*An_4_inRow_15Rows_4),
* spriteAn_4_inRow_15Rows_5 = new Sprite(*An_4_inRow_15Rows_5), * spriteAn_4_inRow_15Rows_6 = new Sprite(*An_4_inRow_15Rows_6),
* spriteAn_4_inRow_15Rows_7 = new Sprite(*An_4_inRow_15Rows_7), * spriteAn_4_inRow_15Rows_8 = new Sprite(*An_4_inRow_15Rows_8),
* spriteAn_4_inRow_15Rows_9 = new Sprite(*An_4_inRow_15Rows_9), * spriteAn_4_inRow_15Rows_10 = new Sprite(*An_4_inRow_15Rows_10),
* spriteAn_4_inRow_16Rows_1 = new Sprite(*An_4_inRow_16Rows_1), * spriteAn_4_inRow_16Rows_2 = new Sprite(*An_4_inRow_16Rows_2),
* spriteAn_4_inRow_16Rows_3 = new Sprite(*An_4_inRow_16Rows_3), * spriteAn_4_inRow_16Rows_4 = new Sprite(*An_4_inRow_16Rows_4),
* spriteAn_4_inRow_16Rows_5 = new Sprite(*An_4_inRow_16Rows_5), * spriteAn_4_inRow_16Rows_6 = new Sprite(*An_4_inRow_16Rows_6),
* spriteAn_4_inRow_16Rows_7 = new Sprite(*An_4_inRow_16Rows_7), * spriteAn_4_inRow_16Rows_8 = new Sprite(*An_4_inRow_16Rows_8),
* spriteAn_4_inRow_16Rows_9 = new Sprite(*An_4_inRow_16Rows_9), * spriteAn_4_inRow_16Rows_10 = new Sprite(*An_4_inRow_16Rows_10),
* spriteAn_4_inRow_16Rows_11 = new Sprite(*An_4_inRow_16Rows_11), * spriteAn_4_inRow_16Rows_12 = new Sprite(*An_4_inRow_16Rows_12),
* spriteAn_4_inRow_17Rows_1 = new Sprite(*An_4_inRow_17Rows_1), * spriteAn_4_inRow_17Rows_2 = new Sprite(*An_4_inRow_17Rows_2),
* spriteAn_4_inRow_17Rows_3 = new Sprite(*An_4_inRow_17Rows_3), * spriteAn_4_inRow_17Rows_4 = new Sprite(*An_4_inRow_17Rows_4),
* spriteAn_4_inRow_17Rows_5 = new Sprite(*An_4_inRow_17Rows_5), * spriteAn_4_inRow_17Rows_6 = new Sprite(*An_4_inRow_17Rows_6),
* spriteAn_4_inRow_17Rows_7 = new Sprite(*An_4_inRow_17Rows_7), * spriteAn_4_inRow_17Rows_8 = new Sprite(*An_4_inRow_17Rows_8),
* spriteAn_4_inRow_17Rows_9 = new Sprite(*An_4_inRow_17Rows_9), * spriteAn_4_inRow_17Rows_10 = new Sprite(*An_4_inRow_17Rows_10),
* spriteAn_4_inRow_17Rows_11 = new Sprite(*An_4_inRow_17Rows_11), * spriteAn_4_inRow_17Rows_12 = new Sprite(*An_4_inRow_17Rows_12),
* spriteAn_4_inRow_18Rows_1 = new Sprite(*An_4_inRow_18Rows_1), * spriteAn_4_inRow_18Rows_2 = new Sprite(*An_4_inRow_18Rows_2),
* spriteAn_4_inRow_18Rows_3 = new Sprite(*An_4_inRow_18Rows_3), * spriteAn_4_inRow_18Rows_4 = new Sprite(*An_4_inRow_18Rows_4),
* spriteAn_4_inRow_18Rows_5 = new Sprite(*An_4_inRow_18Rows_5), * spriteAn_4_inRow_18Rows_6 = new Sprite(*An_4_inRow_18Rows_6),
* spriteAn_4_inRow_18Rows_7 = new Sprite(*An_4_inRow_18Rows_7), * spriteAn_4_inRow_18Rows_8 = new Sprite(*An_4_inRow_18Rows_8),
* spriteAn_4_inRow_18Rows_9 = new Sprite(*An_4_inRow_18Rows_9), * spriteAn_4_inRow_18Rows_10 = new Sprite(*An_4_inRow_18Rows_10),
* spriteAn_4_inRow_18Rows_11 = new Sprite(*An_4_inRow_18Rows_11), * spriteAn_4_inRow_18Rows_12 = new Sprite(*An_4_inRow_18Rows_12);

	//sprite->setColor(Color(255, 255, 255, 255));//непрозрачность
	sprite->scale(0.5, 0.5);
	sprite_myCursor->scale(0.7, 0.7);
	//Text
	Font *font = LoadFontFromResource(IDR_JPEG2, "JPEG");
	USHORT fontSize{ 37 };
	Text *lefttext{ new Text("Score:\nBest score:\nLevel:\nLines:\nSpeed:", *font, fontSize) };
	Text *shOfLefttext{ new Text("Score:\nBest score: \nLevel: \nLines: \nSpeed: ", *font, fontSize) };

	lefttext->setFillColor(Color(118, 36, 182));
	lefttext->setLineSpacing(2.f);

	lefttext->setPosition(155.61f, 350.44f);
	//lefttext->setOutlineColor(Color(29, 17, 55));
	//lefttext->setOutlineThickness(2.f);

	shOfLefttext->setFillColor(Color(3, 6, 18));
	shOfLefttext->setLineSpacing(2.f);
	shOfLefttext->setPosition(158.61f, 353.44f);//+3px

	UINT scoreInt{ 0 };
	//Text *score{ new Text("100500", *font, fontSize) };
	Text *score{ new Text("100500", *font, fontSize) };
	Text *shOfScore{ new Text("100500", *font, fontSize) };
	score->setFillColor(Color(219, 217, 44));
	score->setPosition(((408.8f / 2) - score->getLocalBounds().width) + 360.01f, 350.44f);
	shOfScore->setFillColor(Color(3, 6, 18));
	shOfScore->setPosition(((408.8f / 2) - score->getLocalBounds().width) + 363.01f, 353.44f);//+3px
	//cout << numeric_limits<unsigned int>::max() << endl;
	//cout << thread::hardware_concurrency();

	UINT best_scoreInt{ 0 };
	Text *best_score{ new Text("999999", *font, fontSize) };
	Text *shOfBest_score{ new Text("999999", *font, fontSize) };
	best_score->setFillColor(Color(219, 217, 44));
	best_score->setPosition(((408.8f / 2) - best_score->getLocalBounds().width) + 360.01f, 86 + 350.44f);
	shOfBest_score->setFillColor(Color(3, 6, 18));
	shOfBest_score->setPosition(((408.8f / 2) - best_score->getLocalBounds().width) + 363.01f, 86 + 353.44f);//+3px

	USHORT levelInt{ 0 };
	Text *level{ new Text( "350", *font, fontSize )};
	Text *shOfLevel{ new Text( "350", *font, fontSize )};
	level->setFillColor(Color(219, 217, 44));
	level->setPosition(((408.8f / 2) - level->getLocalBounds().width) + 360.01f, 172 + 350.44f);
	shOfLevel->setFillColor(Color(3, 6, 18));
	shOfLevel->setPosition(((408.8f / 2) - level->getLocalBounds().width) + 363.01f, 172 + 353.44f);//+3px

	UINT linesInt{ 0 };
	Text *lines{ new Text( "1600", *font, fontSize )};
	Text *shOfLines{ new Text( "1600", *font, fontSize )};
	lines->setFillColor(Color(219, 217, 44));
	lines->setPosition(((408.8f / 2) - lines->getLocalBounds().width) + 360.01f, 258 + 350.44f);
	shOfLines->setFillColor(Color(3, 6, 18));
	shOfLines->setPosition(((408.8f / 2) - lines->getLocalBounds().width) + 363.01f, 258 + 353.44f);//+3px

	USHORT speedInt{ 0 };
	Text *speed{ new Text( "10X", *font, fontSize )};
	Text *shOfSpeed{ new Text( "10X", *font, fontSize )};
	speed->setFillColor(Color(219, 217, 44));
	speed->setPosition(((408.8f / 2) - speed->getLocalBounds().width) + 360.01f, 344 + 350.44f);
	shOfSpeed->setFillColor(Color(3, 6, 18));
	shOfSpeed->setPosition(((408.8f / 2) - speed->getLocalBounds().width) + 363.01f, 344 + 353.44f);//+3px

	Text *player{ new Text( "Player:", *font, fontSize - 3 )}; // Уменьшил шрифт на 3 чтобы влезало имя
	Text *shOfPlayer{ new Text( "Player:", *font, fontSize - 3 )};
	player->setFillColor(Color(118, 36, 182));
	player->setPosition(1353, 338 + 3);
	shOfPlayer->setFillColor(Color(3, 6, 18));
	shOfPlayer->setPosition(1356, 341 + 3);//+3px

	string namestr{ "Andrew" };//17 символов максимум делать
	Text *name{ new Text( namestr, *font, fontSize )};
	Text *shOfName{ new Text( namestr, *font, fontSize )};
	name->setFillColor(Color(219, 217, 44));
	//USHORT x1 = 1353 + player->getLocalBounds().width;
	//name->setPosition(408 - player->getLocalBounds().width-name->getLocalBounds().width + x1, 338);
	name->setPosition(1761  - name->getLocalBounds().width, 338);
	shOfName->setFillColor(Color(3, 6, 18));
	//shOfName->setPosition(408 - player->getLocalBounds().width - name->getLocalBounds().width + x1 + 3, 341);//+3px
	shOfName->setPosition(1761 - name->getLocalBounds().width + 3, 341);

	USHORT nameX = 1761 - name->getLocalBounds().width;
	USHORT nameY = 338;
	USHORT shOfNameX = 1761 - name->getLocalBounds().width + 3;
	USHORT shOfNameY = 341;

	if (namestr.size() > 12)
	{
		for (USHORT i = 13; i < 18; i++)
		{
			if (namestr.size() == i)
			{
				name->setCharacterSize(fontSize - (i - 12) * 3);
				shOfName->setCharacterSize(fontSize - (i - 12) * 3);
				name->setPosition(1761 - name->getLocalBounds().width, 338 + (i - 12) * 3);
				shOfName->setPosition(1761 - name->getLocalBounds().width + 3, 341 + (i - 12) * 3);
			}
		}
	}

	Text *time2{ new Text( "Time:", *font, fontSize )};
	Text *shOfTime{ new Text( "Time:", *font, fontSize )};
	time2->setFillColor(Color(118, 36, 182));
	time2->setPosition(1353, 535);
	shOfTime->setFillColor(Color(3, 6, 18));
	shOfTime->setPosition(1356, 538);//+3px

	
	Clock clockForTimer;
	USHORT hours{ 0 };
	USHORT minutes{ 0 };
	USHORT seconds{ 0 };
	FLOAT secondsTemp{ 0.f };
	FLOAT secondsTemp2{ 0.f };
	const USHORT secondsMax{ 60 };
	const USHORT minutesMax{ 60 };
	const USHORT hoursMax{ 99 };
	
	string numOfTime{ "00 : 00 : 00"};
	//string numOfTime;
	Text *clockTime{ new Text( numOfTime, *font, fontSize )};
	Text *shOfClockTime{ new Text( numOfTime, *font, fontSize )};
	clockTime->setFillColor(Color(219, 217, 44));
	clockTime->setPosition(1761 - clockTime->getLocalBounds().width, 535);
	shOfClockTime->setFillColor(Color(3, 6, 18));
	shOfClockTime->setPosition(1761 - clockTime->getLocalBounds().width + 3, 538);

	

	bool check_bottom = false;//для поворота фигуры перед началом падения
	bool check_bottom2 = true;//для отключения ускорения падения
	bool check_bottomForSpace = true;//для отключения ускорения падения space
	bool check_rotate = true;
	bool check_rotate2 = true;//для предварительной фигуры
	
	bool stopSpace = false;//чтобы анимация FF не продолжалась когда проиграл
	USHORT dx = 0;
	bool rotateRight = 0;
	bool rotateLeft = 0;
	bool turnRight = false;
	bool turnLeft = false;
	bool rotateBack90 = false;
	bool rotateForward90 = false;
	bool set_grid = true; //установка сетки
	bool set_prototype = true; //установка прототипа фигур
	//USHORT colorNum = 1 + rand() % 9; // цвет
	//USHORT colorNum2 = 1 + rand() % 9; // цвет
	//USHORT colorNumTemp = 1 + rand() % 9;
	// Переменные для таймера и задержки
	float timer = 0, delay = 0.6f, delay_2 = 0.08f;
	//USHORT step = 1;

	
	//thr1->detach();
	// Объект, который является главным окном приложения
	RenderWindow window(VideoMode(1920, 1080), "brick", /*Style::Close | Style::Titlebar |*/ Style::Fullscreen);
	Image* icon = LoadImageFromResource(IDB_PNG1, "PNG");
	window.setIcon(38, 38, icon->getPixelsPtr());


	//Курсор
	//SetClassLong(window.getSystemHandle(), NULL, IDC_CURSOR1);
	//SetCursor(LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR2)));
	window.setMouseCursorVisible(false);
	// Часы (таймер)
	Clock clock;
	srand(time(0));
	//fill_tetramino();
	// Главный цикл приложения. Выполняется, пока открыто окно
	//animation_1_line.restart();
	while (window.isOpen())
	{
		/*cout << "Wide: " << numberOfWide[0] << endl;
		cout << "Narrow: " << numberOfNarrow[0] << endl << endl << endl;*/
		/*int time_1_line = animation_1_line.getElapsedTime().asMilliseconds();
		cout << time_1_line << endl;*/
		//SetCursor(LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1)));
		Vector2i mousePos = Mouse::getPosition(window);
		Vector2f mousePosf;
		mousePosf.x = Mouse::getPosition(window).x;
		mousePosf.y = Mouse::getPosition(window).y;
		//sprite_myCursor->setPosition(mousePosf.x - 1317, mousePosf.y - 836); //default size
		sprite_myCursor->setPosition(mousePosf.x - 921.9f, mousePosf.y - 585.2f);

		//cout << timer << "     " << delay << endl << endl;
		float time = clock.getElapsedTime().asSeconds();
		//cout << clockForTimer.getElapsedTime().asSeconds() << endl;
		clock.restart();
		timer += time;

		// Обрабатываем очередь событий в цикле
		Event event;

		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			switch (event.type)
			{
			case Event::Closed:
				// Тогда закрываем его
				window.close();
				break;
				/*case Event::MouseButtonPressed:
					if (event.key.code == Mouse::Left)
						if (IntRect(1584, 953, 300, 100).contains(mousePos.x, mousePos.y))
							window.draw(sprite_button_start_st3);
					break;*/
					/*case Event::MouseButtonReleased:
						if (event.key.code == Mouse::Left)
							if (IntRect(1584, 953, 300, 100).contains(mousePos.x, mousePos.y))
								window.draw(sprite_button_start_st2);
						break;*/
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Enter && checkAus)
				{
					pauseBreak = false;
					pause_resume_button = false;
					checkAus = false;
					for (USHORT i = 0; i < H; i++)
						for (USHORT j = 0; j < W; j++)
							field[i][j] = 0;
					startGame = true;
					colorNum = 1 + rand() % 9;
					colorNum2 = 1 + rand() % 9;
					beginGame = true;
					beginGame2 = true;
					beginGame3 = true;
					hours = 0;
					minutes = 0;
					seconds = 0;
					secondsTemp = 0;
					clockForTimer.restart();
					sprite_I_red->setRotation(0);
					sprite_S_red->setRotation(0);
					sprite_Z_red->setRotation(0);
					sprite_T_red->setRotation(0);
					sprite_L_red->setRotation(0);
					sprite_J_red->setRotation(0);
					sprite_O_red->setRotation(0);
					sprite_I_black->setRotation(0);
					sprite_S_black->setRotation(0);
					sprite_Z_black->setRotation(0);
					sprite_T_black->setRotation(0);
					sprite_L_black->setRotation(0);
					sprite_J_black->setRotation(0);
					sprite_O_black->setRotation(0);
					sprite_I_blue->setRotation(0);
					sprite_S_blue->setRotation(0);
					sprite_Z_blue->setRotation(0);
					sprite_T_blue->setRotation(0);
					sprite_L_blue->setRotation(0);
					sprite_J_blue->setRotation(0);
					sprite_O_blue->setRotation(0);
					sprite_I_brown->setRotation(0);
					sprite_S_brown->setRotation(0);
					sprite_Z_brown->setRotation(0);
					sprite_T_brown->setRotation(0);
					sprite_L_brown->setRotation(0);
					sprite_J_brown->setRotation(0);
					sprite_O_brown->setRotation(0);
					sprite_I_orange->setRotation(0);
					sprite_S_orange->setRotation(0);
					sprite_Z_orange->setRotation(0);
					sprite_T_orange->setRotation(0);
					sprite_L_orange->setRotation(0);
					sprite_J_orange->setRotation(0);
					sprite_O_orange->setRotation(0);
					sprite_I_green->setRotation(0);
					sprite_S_green->setRotation(0);
					sprite_Z_green->setRotation(0);
					sprite_T_green->setRotation(0);
					sprite_L_green->setRotation(0);
					sprite_J_green->setRotation(0);
					sprite_O_green->setRotation(0);
					sprite_I_purple->setRotation(0);
					sprite_S_purple->setRotation(0);
					sprite_Z_purple->setRotation(0);
					sprite_T_purple->setRotation(0);
					sprite_L_purple->setRotation(0);
					sprite_J_purple->setRotation(0);
					sprite_O_purple->setRotation(0);
					sprite_I_pink->setRotation(0);
					sprite_S_pink->setRotation(0);
					sprite_Z_pink->setRotation(0);
					sprite_T_pink->setRotation(0);
					sprite_L_pink->setRotation(0);
					sprite_J_pink->setRotation(0);
					sprite_O_pink->setRotation(0);
					sprite_I_yellow->setRotation(0);
					sprite_S_yellow->setRotation(0);
					sprite_Z_yellow->setRotation(0);
					sprite_T_yellow->setRotation(0);
					sprite_L_yellow->setRotation(0);
					sprite_J_yellow->setRotation(0);
					sprite_O_yellow->setRotation(0);
					numberOfWide.clear();
					numberOfWide.push_back(0);
					numberOfNarrow.clear();
					numberOfNarrow.push_back(1);
				}
				//Эта кнопка – стрелка вверх
				if (event.key.code == Keyboard::Up && typeOfTetramino1 != 6 && !progressOfAnimationLines && !progressOfAnimationFF)
				{
					rotateRight = true;
					turnRight = true;
				}
				else if (event.key.code == Keyboard::RControl && typeOfTetramino1 != 6 && !progressOfAnimationLines && !progressOfAnimationFF)
				{
					rotateLeft = true;
					turnLeft = true;
				}
				//Или может стрелка влево?
				else if (event.key.code == Keyboard::Left && !pauseBreak && !progressOfAnimationFF) dx = -1;
				// Или стрелка вправо?
				else if (event.key.code == Keyboard::Right && !pauseBreak && !progressOfAnimationFF) dx = 1;
				else if (event.key.code == Keyboard::Pause && !checkAus)
				{
					if (pauseBreak)
					{
						clockForTimer.restart();
						pauseBreak = false;
						pause_resume_button = false;
					}
					else {
						secondsTemp = secondsTemp2;
						pauseBreak = true;
						pause_resume_button = true;
					}
				}
				//else if (event.key.code == Keyboard::Down) delay = 0.001;
				else if (event.key.code == Keyboard::Escape)window.close();
				else if (event.key.code == Keyboard::V)window.setVerticalSyncEnabled(true);//пофиксить потом
				else if (event.key.code == Keyboard::G)
					if (!set_grid) set_grid = true;
					else set_grid = false;
				else if (event.key.code == Keyboard::P)
					if (!set_prototype) set_prototype = true;
					else set_prototype = false;
				else if (event.key.code == Keyboard::F9)hours++;
				else if (event.key.code == Keyboard::F10)minutes++;
				else if (event.key.code == Keyboard::F11)seconds++;
				else if (event.key.code == Keyboard::F6)hours--;
				else if (event.key.code == Keyboard::F7)minutes--;
				else if (event.key.code == Keyboard::F8)seconds--;
				else if (event.key.code == Keyboard::F1)
				{
				/*	enableAnimation4lines = true;
					animation_4_lines.restart();*/
					for (USHORT i = H - 1; i > 0; i--)//очистка поля
					{
						for (USHORT j = 0; j < W; j++)
						{
							field[i][j] = 0;
						}
					}

					for (USHORT i = H - 1; i > 2; i--)
					{
						for (USHORT j = 0; j < W; j++)
						{
							
							field[i][j] = 1;
							if(i < 7)
							field[i][4] = 0;
							//if (i == 18) field[i][3] = 0;
							//if (i == 17) field[i][3] = 0;
							if (i == 4) field[i][3] = 0;
							if (i == 7) field[i][8] = 0;
							if (i == 8) field[i][9] = 0;
							if (i == 9) field[i][0] = 0;
							if (i == 10) field[i][1] = 0;
							if (i == 11) field[i][2] = 0;
							if (i == 12) field[i][3] = 0;
							if (i == 13) field[i][4] = 0;
							if (i == 14) field[i][5] = 0;
							if (i == 15) field[i][6] = 0;
							if (i == 16) field[i][7] = 0;
							if (i == 17) field[i][8] = 0;
							if (i == 18) field[i][9] = 0;
							if (i == 19) field[i][8] = 0;

						}
					}
				}
				else if (event.key.code == Keyboard::F2)
				{
					enableAnimation_fast_falling_4InRow_1Row = true;
				}
				else if (event.key.code == Keyboard::F3)
				{
					
				}
				else if (event.key.code == Keyboard::Space && check_bottomForSpace && !progressOfAnimationFF && !progressOfAnimationLines && !checkAus && !stopSpace && !pauseBreak)
				{
					if (!nOfSameStructsFn(a, e))
					{
						check_space = true;
						if((e[1].y - a[0].y == 16 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 17 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//для 16 полос тетрамино №4 L
						{
							enableAnimation_fast_falling_3InRow_16Rows = true;
						}
						
						else if ((e[1].y - a[0].y == 17 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 17 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//для 16 полос тетрамино №5 Г
						{
							enableAnimation_fast_falling_3InRow_16Rows = true;
						}

						else if ((e[1].y - a[0].y == 17 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 17 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//для 16 полос тетрамино №3 Т
						{
							enableAnimation_fast_falling_3InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[0].y - a[0].y == 16 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//для 16 полос тетрамино №1 S
						{
							enableAnimation_fast_falling_3InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[0].y - a[0].y == 16 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//для 16 полос тетрамино №2 Z
						{
							enableAnimation_fast_falling_3InRow_16Rows = true;
						}
						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */||
							(e[3].y - a[3].y == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_1Row = true;
						}
						
						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 6 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 7 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 8 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 9 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 10 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 11 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 12 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_1InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 13 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_1InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 14 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_1InRow_13Rows = true;
						}

						else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 15 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_1InRow_14Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 16 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_1InRow_15Rows = true;
						}

						else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 17 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_1InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 0 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 18 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_1InRow_17Rows = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}


						//

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_2Rows = true; 
						}
						//

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_1Row = true;
						}
						
						//

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_2Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_3Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 6 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 6 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 6 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 6 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 6 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_4Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 7 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 7 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 7 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 7 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 7 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_5Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 8 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 8 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 8 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 8 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 8 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_6Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 9 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 9 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 9 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 9 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 9 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_7Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 10 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 10 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 10 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 10 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 10 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_8Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 11 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 11 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 11 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 11 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 11 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_9Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 12 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 12 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 12 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 12 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 12 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_10Rows = true;
						}
					}
					//

					if (!nOfSameStructsFn(a, e))//Создал еще один, чтобы не было ошибки "ограничение компилятора недопустимая степень вложения блоков"
					{

						if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 13 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 13 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 13 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 13 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 13 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 13) && typeOfTetramino1 == 6)
						{
							enableAnimation_fast_falling_2InRow_11Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 14 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_13Rows = true;
						}

						else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 14 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_13Rows = true;
						}

						else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 14 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_13Rows = true;
						}

						else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 14 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_13Rows = true;
						}

						else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 14 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_13Rows = true;
						}

						else if ((e[3].y - a[3].y == 14) && typeOfTetramino1 == 6)
						{
							enableAnimation_fast_falling_2InRow_12Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 15 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_14Rows = true;
						}

						else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 15 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_14Rows = true;
						}

						else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 15 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_14Rows = true;
						}

						else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 15 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_14Rows = true;
						}

						else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
							(e[3].y - a[3].y == 15 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
							enableAnimation_fast_falling_2InRow_14Rows = true;
						}

						else if ((e[3].y - a[3].y == 15) && typeOfTetramino1 == 6)
						{
							enableAnimation_fast_falling_2InRow_13Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 16 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_15Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 16 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_15Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 16 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_15Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 16 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_15Rows = true;
						}

						else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 16 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_15Rows = true;
						}

						else if ((e[3].y - a[3].y == 16) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_14Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 1 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 17 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 2 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 17 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 17 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 17 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 17 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_16Rows = true;
						}

						else if ((e[3].y - a[3].y == 17) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_15Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 3 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 18 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_17Rows = true;
						}

						else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 4 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 18 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_17Rows = true;
						}

						else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 5 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2)) /* */ ||
						(e[3].y - a[3].y == 18 && (numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0))
						{
						enableAnimation_fast_falling_2InRow_17Rows = true;
						}

						else if ((e[3].y - a[3].y == 18) && typeOfTetramino1 == 6)
						{
						enableAnimation_fast_falling_2InRow_16Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 1 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
							enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 1 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
							enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 1 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
							enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 1 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
							enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 1 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
							enableAnimation_fast_falling_3InRow_1Row = true;
						}

						//

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 2 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 2 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 2 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_1Row = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 2 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 2 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_2Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 3 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 3 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 3 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_2Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 3 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 3 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_3Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 4 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 4 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 4 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_3Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 4 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 4 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_4Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 5 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 5 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 5 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_4Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 5 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 5 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_5Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 6 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 6 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 6 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_5Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 6 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 6 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_6Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 7 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 7 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 7 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_6Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 7 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 7 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_7Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 8 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 8 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 8 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_7Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 8 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 8 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_8Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 9 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 9 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 9 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_8Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 9 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 9 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_9Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 10 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 10 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 10 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_9Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 10 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 10 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_10Rows = true;
						}

						//

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 11 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 11 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 11 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_10Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 11 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 11 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_11Rows = true;
						}

						//
						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 12 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
						{
						enableAnimation_fast_falling_3InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 12 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
						{
						enableAnimation_fast_falling_3InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 12 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
						{
						enableAnimation_fast_falling_3InRow_11Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 12 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
						{
						enableAnimation_fast_falling_3InRow_12Rows = true;
						}

						else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 12 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
						{
						enableAnimation_fast_falling_3InRow_12Rows = true;
						}

					}

					if (!nOfSameStructsFn(a, e))//Создал еще один, чтобы не было ошибки "ограничение компилятора недопустимая степень вложения блоков"
					{
						//

					if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 13 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
					{
						enableAnimation_fast_falling_3InRow_12Rows = true;
					}

					else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 13 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
					{
						enableAnimation_fast_falling_3InRow_12Rows = true;
					}

					else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 13 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
					{
						enableAnimation_fast_falling_3InRow_12Rows = true;
					}

					else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 13 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					{
						enableAnimation_fast_falling_3InRow_13Rows = true;
					}

					else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 13 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
					{
						enableAnimation_fast_falling_3InRow_13Rows = true;
					}

					//

					else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 14 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
					{
						enableAnimation_fast_falling_3InRow_13Rows = true;
					}

					else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 14 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
					{
						enableAnimation_fast_falling_3InRow_13Rows = true;
					}

					else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 14 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
					{
						enableAnimation_fast_falling_3InRow_13Rows = true;
					}

					else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 14 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					{
						enableAnimation_fast_falling_3InRow_14Rows = true;
					}

					else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 14 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
					{
						enableAnimation_fast_falling_3InRow_14Rows = true;
					}

					//

					else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 15 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
					{
						enableAnimation_fast_falling_3InRow_14Rows = true;
					}

					else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 15 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
					{
						enableAnimation_fast_falling_3InRow_14Rows = true;
					}

					else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 15 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
					{
						enableAnimation_fast_falling_3InRow_14Rows = true;
					}

					else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 15 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					{
						enableAnimation_fast_falling_3InRow_15Rows = true;
					}

					else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 15 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
					{
						enableAnimation_fast_falling_3InRow_15Rows = true;
					}

				//
					else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 16 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
					{
						enableAnimation_fast_falling_3InRow_15Rows = true;
					}

					else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 16 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
					{
						enableAnimation_fast_falling_3InRow_15Rows = true;
					}

					else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 16 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
					{
						enableAnimation_fast_falling_3InRow_15Rows = true;
					}

					//else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 16 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					//{
					//	enableAnimation_fast_falling_3InRow_16Rows = true;
					//}

					//else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 16 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
					//{
					//	enableAnimation_fast_falling_3InRow_16Rows = true;
					//}

					//

					else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 18 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
					{
					enableAnimation_fast_falling_3InRow_17Rows = true;
					}

					else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 18 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
					{
					enableAnimation_fast_falling_3InRow_17Rows = true;
					}

					else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 18 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
					{
					enableAnimation_fast_falling_3InRow_17Rows = true;
					}

					else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 17 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					{
						enableAnimation_fast_falling_3InRow_17Rows = true;
					}

					else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 17 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
					{
						enableAnimation_fast_falling_3InRow_17Rows = true;
					}

					//

					else if ((e[3].y - a[3].y == 19 && typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 19 && typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// L
					{
					enableAnimation_fast_falling_3InRow_18Rows = true;
					}

					else if ((e[3].y - a[3].y == 19 && typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 19 && typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Г
					{
					enableAnimation_fast_falling_3InRow_18Rows = true;
					}

					else if ((e[3].y - a[3].y == 19 && typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 19 && typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//Т
					{
					enableAnimation_fast_falling_3InRow_18Rows = true;
					}

					else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 18 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					{
					enableAnimation_fast_falling_3InRow_18Rows = true;
					}

					//else if ((a[3].y == 1 && typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0) || ( a[3].y == 1 && typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//S
					//{
					//enableAnimation_fast_falling_3InRow_18Rows = true;
					//}

					else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 18 && typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))// Z
					{
					enableAnimation_fast_falling_3InRow_18Rows = true;
					}

					//

					else if ((e[3].y - a[3].y == 1 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 1 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_1Row = true;
					}

					else if ((e[3].y - a[3].y == 2 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 2 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_1Row = true;
					}

					else if ((e[3].y - a[3].y == 3 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 3 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_2Rows = true;
					}

					else if ((e[3].y - a[3].y == 4 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 4 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_3Rows = true;
					}

					else if ((e[3].y - a[3].y == 5 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 5 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_4Rows = true;
					}

					else if ((e[3].y - a[3].y == 6 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 6 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_5Rows = true;
					}

					else if ((e[3].y - a[3].y == 7 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 7 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_6Rows = true;
					}

					else if ((e[3].y - a[3].y == 8 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 8 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_7Rows = true;
					}

					else if ((e[3].y - a[3].y == 9 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 9 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_8Rows = true;
					}

					else if ((e[3].y - a[3].y == 10 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 10 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_9Rows = true;
					}

					else if ((e[3].y - a[3].y == 11 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 11 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_10Rows = true;
					}

					else if ((e[3].y - a[3].y == 12 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 12 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_11Rows = true;
					}

					else if ((e[3].y - a[3].y == 13 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 13 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_12Rows = true;
					}

					else if ((e[3].y - a[3].y == 14 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 14 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_13Rows = true;
					}

					else if ((e[3].y - a[3].y == 15 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 15 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_14Rows = true;
					}

					else if ((e[3].y - a[3].y == 16 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 16 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_15Rows = true;
					}

					else if ((e[3].y - a[3].y == 17 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 17 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_16Rows = true;
					}

					else if ((e[3].y - a[3].y == 18 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 18 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_17Rows = true;
					}
					else if ((e[3].y - a[3].y == 19 && typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0) || (e[3].y - a[3].y == 19 && typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2)))//I
					{
					enableAnimation_fast_falling_4InRow_18Rows = true;
					}
					}
					check_bottomForSpace = false;
				}
				break;
			case Event::Resized:
				/*cout << "Resized" << endl;
				cout << window.getSize().x << '\t' << window.getSize().y << endl << endl;
				cout << event.size.width << '\t' << event.size.height << endl << endl << endl;*/
				break;
			case Event::KeyReleased:
				check_bottomForSpace = true;
				check_bottom2 = true;
				check_rotate = true;
				check_rotate2 = true;
				//check_space = false;
				//step = 1;

				//if (IntRect(1584, 953, 300, 100).contains(mousePos.x, mousePos.y))	sf::sleep(sf::milliseconds(1000));
				break;
			case Event::MouseButtonReleased:
				//pause/resume
				if (IntRect(216, 963, 80, 80).contains(mousePos.x, mousePos.y) && !checkAus)
				{
					if (!pauseBreak && !pause_resume_button)\
					{
						secondsTemp = secondsTemp2;
						pauseBreak = true;
						pause_resume_button = true;
					}
					else
					{
						clockForTimer.restart();
						pauseBreak = false;
						pause_resume_button = false;
					}
				}
				//Start/New game
				else if (IntRect(1584, 953, 300, 100).contains(mousePos.x, mousePos.y))
				{
					if (beginGame && !start_newGame_button)
					{
						startGame = true;
						clockForTimer.restart();
						start_newGame_button = true;
						numberOfWide.clear();
						numberOfWide.push_back(0);
						numberOfNarrow.clear();
						numberOfNarrow.push_back(1);
					}
					else if (start_newGame_button)
					{
						pauseBreak = true;
						pause_resume_button = true;
						checkAus = true;
					}
				}

				//SoundOn/SoundOff
				else if (IntRect(36, 963, 80, 80).contains(mousePos.x, mousePos.y))
				{
					if (!soundOn_sounOff_button) soundOn_sounOff_button = true;
					else soundOn_sounOff_button = false;
				}

				//MusicOn/MusicOff
				else if (IntRect(126, 963, 80, 80).contains(mousePos.x, mousePos.y))
				{
					if (!musicOn_musicOff_button) musicOn_musicOff_button = true;
					else musicOn_musicOff_button = false;
				}
				//Left minimize
				else if (IntRect(1629, 32, 85, 62).contains(mousePos.x, mousePos.y)) SendNotifyMessage(window.getSystemHandle(), WM_SYSCOMMAND, SC_MINIMIZE, 0); //МИНИМИЗАЦИЯ ОКНА

				//Right close
				else if (IntRect(1799, 32, 85, 62).contains(mousePos.x, mousePos.y)) window.close();

				//Middle restore
				else if (IntRect(1714, 32, 85, 62).contains(mousePos.x, mousePos.y)) window.setSize(Vector2u(700, 800));
				break;
			case Event::MouseButtonPressed:
				//if (IntRect(1694, 858, 80, 80).contains(mousePos.x, mousePos.y))
				//is_mouse_released = false;
				break;
			}
		}
		//cout << secondsTemp << endl;

		// Нажали на кнопку "Вниз"? Ускоряем падение тетрамино
		if (Keyboard::isKeyPressed(Keyboard::Down))//Не убирать наверх, будет задержка
			if (check_bottom2)
				delay = 0.02f;//0.001;



		if (startGame)
			if (beginGame)
			{
				stopSpace = false;
				fill_tetramino();
				fill_tetramino2();
				// Вращение фигуры сверху
				Point p = c[1]; // указываем центр вращения
				for (int i = 0; i < 4; i++)
				{
					if (typeOfTetramino2 == 3 || typeOfTetramino2 == 4 || typeOfTetramino2 == 5)
					{
						USHORT x = p.y - c[i].y;
						USHORT y = p.x - c[i].x;//270
						c[i].x = p.x - x;
						c[i].y = p.y + y;
					}
					else
					{
						USHORT x = c[i].y - p.y; // y - y0
						USHORT y = c[i].x - p.x; // x - x0 
						c[i].x = p.x - x; //90
						c[i].y = p.y + y;
					}
				}

				//поворот фигуры на 90 градусов если начало падения и начало игры
				//поворот для А
				p = a[1]; // указываем центр вращения
				if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = a[2];
				for (int i = 0; i < 4; i++)
				{
					//b[i] = a[i];
					if (typeOfTetramino1 == 3 || typeOfTetramino1 == 4 || typeOfTetramino1 == 5)
					{
						USHORT x = p.y - a[i].y;
						USHORT y = p.x - a[i].x;
						a[i].x = p.x - x;
						a[i].y = p.y + y;
					}
					else
					{
						USHORT x = a[i].y - p.y; // y - y0
						USHORT y = a[i].x - p.x; // x - x0
						a[i].x = p.x - x;
						a[i].y = p.y + y;
					}
				}
				//поворот для Е
				p = e[1]; // указываем центр вращения
				if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = e[2];
				for (int i = 0; i < 4; i++)
				{
					//b[i] = e[i];
					if (typeOfTetramino1 == 3 || typeOfTetramino1 == 4 || typeOfTetramino1 == 5)
					{
						USHORT x = p.y - e[i].y;
						USHORT y = p.x - e[i].x;
						e[i].x = p.x - x;
						e[i].y = p.y + y;
					}
					else
					{
						USHORT x = e[i].y - p.y; // y - y0
						USHORT y = e[i].x - p.x; // x - x0
						e[i].x = p.x - x;
						e[i].y = p.y + y;
					}
				}

				//Сдвиг по оси Y для А и для E
				switch (typeOfTetramino1)
				{
				case 0:
				case 1:
				case 2:
					for (USHORT i = 0; i < 4; i++)
					{
						a[i].y = a[i].y - 2;
						//e[i].y = e[i].y - 2;
					}

					break;
				case 3:
				case 4:
				case 5:
					for (USHORT i = 0; i < 4; i++)
					{
						a[i].y = a[i].y - 3;
						//e[i].y = e[i].y - 3;
					}

					break;
				case 6:
					for (USHORT i = 0; i < 4; i++)
					{
						a[i].y = a[i].y - 1;
						//e[i].y = e[i].y - 1;
					}

				}
				//cout << "===============================Beginning=================================" << endl;
				////cout << "Before" << endl;
				//for (int i = 0; i < 4; i++)
				//{
				//	cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
				//	cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				//}
				//cout << "===============================End=======================================" << endl;
				//cout << endl << endl;
			}

		

		// Горизонтальное перемещение
		for (USHORT i = 0; i < 4; i++)
		{
			b[i] = a[i];
			a[i].x += dx;
			e[i].x += dx;
		}
		
		if ((!check() || !checkField()) && dx!=0) {//пока работает, если что исправить
			for (USHORT i = 0; i < 4; i++)
			{
				a[i] = b[i];
				e[i] = b[i];
			}
			//cout << "here" << endl;
		}

				// Вращение по часовой стрелке вправо
		if (rotateRight && !pauseBreak && check_rotate)
		{
			numberOfWide[0]++;
			numberOfNarrow[0]++;
			Point p = a[1]; // указываем центр вращения
			if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = a[2];
			for (int i = 0; i < 4; i++)
			{
				b[i] = a[i];
				USHORT x = a[i].y - p.y; // y - y0
				USHORT y = a[i].x - p.x; // x - x0
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
			p = e[1];
			if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = e[2];
			for (int i = 0; i < 4; i++)
			{
				f[i] = e[i];
				USHORT x = e[i].y - p.y; // y - y0
				USHORT y = e[i].x - p.x; // x - x0
				e[i].x = p.x - x;
				e[i].y = p.y + y;
			}

			if (!checkForPrototypeHeight())
			{
			one:
				for (int i = 0; i < 4; i++)
				{
					e[i].y--;
				}
				if (!checkForPrototypeHeight())goto one;
			}

			if (!checkForPrototypeRightSide())
			{
				for (int i = 0; i < 4; i++)
					e[i] = f[i];
				rotateBack90 = true;
			}

			if (!checkForPrototypeLeftSide())
			{
				for (int i = 0; i < 4; i++)
					e[i] = f[i];
				rotateBack90 = true;
			}
			
			if(!checkField())
			{
				for (int i = 0; i < 4; i++)
					e[i] = f[i];
				rotateBack90 = true;
			}
		/*	while (!checkForPrototypeTop())
				for (USHORT i = 0; i < 4; i++)
				{
					e[i].y--;
				}
			falling_down(j, e);*/
			countOfSamePos = 0;
			while (true)
			{
				for (USHORT i = 0; i < 4; i++)
				{
					e[i].y--;
					if (e[i].y == a[i].y) countOfSamePos++;
				}
				if (countOfSamePos == 4) break;
			}
			falling_down(j, e);
			check_rotate = false;
			//cout << "===============================Beginning=================================" << endl;
			////cout << "Before" << endl;
			//for (int i = 0; i < 4; i++)
			//{
			//	cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
			//	cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

			//}
			//cout << "===============================End=======================================" << endl;
			//cout << endl << endl;
			// 
				//Если вышли за пределы поля после поворота, то возвращаем старые координаты 

			if (!check() || !checkField()) // если ненулевое значение
			{
				for (int i = 0; i < 4; i++) a[i] = b[i];
				//cout << "here" << endl;
			}
		}

		//falling_down(j, e);//пока закомментил, пока это не нужно

		// Вращение против часовой стрелки влево
		if (rotateLeft && !pauseBreak && check_rotate)
		{
			numberOfWide[0]--;
			numberOfNarrow[0]--;
			Point p = a[1]; // указываем центр вращения
			if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = a[2];
			for (int i = 0; i < 4; i++)
			{
				b[i] = a[i];
				USHORT x = p.y - a[i].y;
				USHORT y = p.x - a[i].x;
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}

			p = e[1];
			if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = e[2];
			for (int i = 0; i < 4; i++)
			{
				f[i] = a[i];
				USHORT x = p.y - e[i].y;
				USHORT y = p.x - e[i].x;
				e[i].x = p.x - x;
				e[i].y = p.y + y;
			}
			

			if (!checkForPrototypeHeight())
			{
			four:
				for (int i = 0; i < 4; i++)
				{
					e[i].y--;
				}
				if (!checkForPrototypeHeight())goto four;
			}
			if (!checkForPrototypeRightSide())
			{
				for (int i = 0; i < 4; i++)
					e[i] = j[i];
				rotateForward90 = true;
			}

			if (!checkForPrototypeLeftSide())
			{
				for (int i = 0; i < 4; i++)
					e[i] = j[i];
				rotateForward90 = true;
			}
			
			if (!checkField())
			{
				for (int i = 0; i < 4; i++)
					e[i] = j[i];
				rotateForward90 = true;
			}
		/*	while (!checkForPrototypeTop())
				for (USHORT i = 0; i < 4; i++)
				{
					e[i].y--;
				}
			falling_down(j, e);*/
			countOfSamePos = 0;
			while (true)
			{
				for (USHORT i = 0; i < 4; i++)
				{
					e[i].y--;
					if (e[i].y == a[i].y) countOfSamePos++;
				}
				if (countOfSamePos == 4) break;
			}
			falling_down(j, e);
			check_rotate = false;
			//cout << "===============================Beginning=================================" << endl;
			////cout << "Before" << endl;
			//for (int i = 0; i < 4; i++)
			//{
			//	cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
			//	cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

			//}
			//cout << "===============================End=======================================" << endl;
			//cout << endl << endl;

				//Если вышли за пределы поля после поворота, то возвращаем старые координаты 
			if (!check() || !checkField()) // если ненулевое значение
			{
				for (int i = 0; i < 4; i++) a[i] = b[i];
				//cout << "here" << endl;
			}
		}

		////Если вышли за пределы поля после поворота, то возвращаем старые координаты 
		//if (!check() || !checkField()) // если ненулевое значение
		//{
		//	for (int i = 0; i < 4; i++) a[i] = b[i];
		//	//cout << "here" << endl;
		//}


		//Копирование структуры a в d, для Паузы
		if (pauseBreak)
		{
			for (USHORT i = 0; i < 4; i++)
				d[i] = a[i];
		}

		//if (check_space && check_bottomForSpace && startGame && !pauseBreak) // для моментального падения фигур вниз// это пока не надо
		//{
		//	for (USHORT i = 0; i < 4; i++)// для отрисовки анимации от координат h
		//	{
		//		h[i] = a[i];
		//	}
		//}
		//после анимации FF

		if (afterAnimationFF)
		{
			afterAnimationFF = false;
			goto here;
		}

	
		//Движение тетрамино вниз («тик» таймера)
		if (!pauseBreak && startGame && !enableAnimation_fast_falling_3InRow_16Rows)
			if (timer > delay)
			{
				for (USHORT i = 0; i < 4; i++)
				{
					b[i] = a[i]; a[i].y++;
					//b[i].y = b[i].y + 1;
				}
				//cout << "numberOfWide :" << numberOfWide[0] << endl;
				//cout << "numberOfNarrow :" << numberOfNarrow[0] << endl;
				//cout << "===============================Beginning=================================" << endl;
				////cout << "Before" << endl;
				for (int i = 0; i < 4; i++)
				{
					cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
					//cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				}
				cout << endl;
				for (int i = 0; i < 4; i++)
				{
					//cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
					cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				}
				cout << "===============================End=======================================" << endl;
				cout << endl << endl;
				

				if (!check() || !checkField())
				{
					for (USHORT i = 0; i < 4; i++)
					field[b[i].y][(b[i].x + 4)] = colorNum; ///тут править
				here:
					numberOfWide.clear();
					numberOfWide.push_back(0);
					numberOfNarrow.clear();
					numberOfNarrow.push_back(1);
					//checkForFigureBot = true;

					beginGame3 = false;
					check_bottom = true;
					check_bottom2 = false;
					sprite_I_red->setRotation(0);
					sprite_S_red->setRotation(0);
					sprite_Z_red->setRotation(0);
					sprite_T_red->setRotation(0);
					sprite_L_red->setRotation(0);
					sprite_J_red->setRotation(0);
					sprite_O_red->setRotation(0);
					sprite_I_black->setRotation(0);
					sprite_S_black->setRotation(0);
					sprite_Z_black->setRotation(0);
					sprite_T_black->setRotation(0);
					sprite_L_black->setRotation(0);
					sprite_J_black->setRotation(0);
					sprite_O_black->setRotation(0);
					sprite_I_blue->setRotation(0);
					sprite_S_blue->setRotation(0);
					sprite_Z_blue->setRotation(0);
					sprite_T_blue->setRotation(0);
					sprite_L_blue->setRotation(0);
					sprite_J_blue->setRotation(0);
					sprite_O_blue->setRotation(0);
					sprite_I_brown->setRotation(0);
					sprite_S_brown->setRotation(0);
					sprite_Z_brown->setRotation(0);
					sprite_T_brown->setRotation(0);
					sprite_L_brown->setRotation(0);
					sprite_J_brown->setRotation(0);
					sprite_O_brown->setRotation(0);
					sprite_I_orange->setRotation(0);
					sprite_S_orange->setRotation(0);
					sprite_Z_orange->setRotation(0);
					sprite_T_orange->setRotation(0);
					sprite_L_orange->setRotation(0);
					sprite_J_orange->setRotation(0);
					sprite_O_orange->setRotation(0);
					sprite_I_green->setRotation(0);
					sprite_S_green->setRotation(0);
					sprite_Z_green->setRotation(0);
					sprite_T_green->setRotation(0);
					sprite_L_green->setRotation(0);
					sprite_J_green->setRotation(0);
					sprite_O_green->setRotation(0);
					sprite_I_purple->setRotation(0);
					sprite_S_purple->setRotation(0);
					sprite_Z_purple->setRotation(0);
					sprite_T_purple->setRotation(0);
					sprite_L_purple->setRotation(0);
					sprite_J_purple->setRotation(0);
					sprite_O_purple->setRotation(0);
					sprite_I_pink->setRotation(0);
					sprite_S_pink->setRotation(0);
					sprite_Z_pink->setRotation(0);
					sprite_T_pink->setRotation(0);
					sprite_L_pink->setRotation(0);
					sprite_J_pink->setRotation(0);
					sprite_O_pink->setRotation(0);
					sprite_I_yellow->setRotation(0);
					sprite_S_yellow->setRotation(0);
					sprite_Z_yellow->setRotation(0);
					sprite_T_yellow->setRotation(0);
					sprite_L_yellow->setRotation(0);
					sprite_J_yellow->setRotation(0);
					sprite_O_yellow->setRotation(0);
					
					//countOfSameStruct = 0;
					colorNum = colorNum2;
					colorNum2 = 1 + rand() % 9;
					if (colorNum2 == colorNumTemp)// для рандома цвета фигур
					{
						while (colorNum2 == colorNumTemp)
							colorNum2 = 1 + rand() % 9;
					}

					n = rand() % 7;
					if (n == nTemp1)// для рандома фигур
					{
						while (n == nTemp1)
						n = rand() % 7;
					}
					//----ПРОВЕРКА ЛИНИИ на заполненность снизу----//
					checkFullLineFn(field);

					for (USHORT i = 0; i < 4; i++)
					{
						c[i].x = figures[n][i] % 2;
						c[i].y = figures[n][i] / 2;
					}
					
					for (USHORT i = 0; i < 4; i++)
					{
						a[i].x = figures[typeOfTetramino2][i] % 2;
						a[i].y = figures[typeOfTetramino2][i] / 2;
						e[i].x = figures[typeOfTetramino2][i] % 2;
						e[i].y = figures[typeOfTetramino2][i] / 2;
					}

				/*	cout << "===============================Beginning=================================" << endl;
					cout << "Before" << endl;
					for (int i = 0; i < 4; i++)
					{
						cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
						cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

					}
					cout << "===============================End=======================================" << endl;
					cout << endl << endl;*/

					
			/*		cout << "===============================Beginning=================================" << endl;
					cout << "After" << endl;
					for (int i = 0; i < 4; i++)
					{
						cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
						cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

					}
					cout << "===============================End=======================================" << endl;
					cout << endl << endl;*/
					typeOfTetramino1 = typeOfTetramino2;//для проверки на поворот фигуры квадрат
					typeOfTetramino2 = n;
				
					Point p = c[1]; // указываем центр вращения
					for (int i = 0; i < 4; i++)
					{
						if (n == 3 || n == 4 || n == 5)
						{
							USHORT x = p.y - c[i].y;
							USHORT y = p.x - c[i].x;
							c[i].x = p.x - x;
							c[i].y = p.y + y;
						}
						else
						{
							USHORT x = c[i].y - p.y; // y - y0
							USHORT y = c[i].x - p.x; // x - x0
							c[i].x = p.x - x;
							c[i].y = p.y + y;
						}
					}

					//Сдвиг координат по оси Y
					switch (typeOfTetramino1)
					{
						case 0:
						case 1:
						case 2:
							for (USHORT i = 0; i < 4; i++)
							{
								a[i].y = a[i].y - 1;
								//e[i].y = e[i].y--;
							}
							break;
						case 3:
						case 4:
						case 5:
							for (USHORT i = 0; i < 4; i++)
							{
								a[i].y = a[i].y - 2;
								//e[i].y = e[i].y - 2;
							}
					}

					//поворот фигуры на 90 градусов если начало падения
					if (check_bottom)
					{
						Point p = a[1]; // указываем центр вращения
						if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = a[2];
						for (int i = 0; i < 4; i++)
						{
							b[i] = a[i];
							if (typeOfTetramino1 == 3 || typeOfTetramino1 == 4 || typeOfTetramino1 == 5)
							{
								USHORT x = p.y - a[i].y;
								USHORT y = p.x - a[i].x;
								a[i].x = p.x - x;
								a[i].y = p.y + y;
							}
							else
							{
								USHORT x = a[i].y - p.y; // y - y0
								USHORT y = a[i].x - p.x; // x - x0
								a[i].x = p.x - x;
								a[i].y = p.y + y;
							}
						}

						p = e[1];
						if (typeOfTetramino1 == 1 || typeOfTetramino1 == 4) p = e[2];
						for (int i = 0; i < 4; i++)
						{
							f[i] = e[i];
							if (typeOfTetramino1 == 3 || typeOfTetramino1 == 4 || typeOfTetramino1 == 5)
							{
								USHORT x = p.y - e[i].y;
								USHORT y = p.x - e[i].x;
								e[i].x = p.x - x;
								e[i].y = p.y + y;
							}
							else
							{
								USHORT x = e[i].y - p.y; // y - y0
								USHORT y = e[i].x - p.x; // x - x0
								e[i].x = p.x - x;
								e[i].y = p.y + y;
							}
						}
						check_bottom = false;
					}
					falling_down(j, e);
					nTemp1 = n;
					colorNumTemp = colorNum2;
				}
				timer = 0;
				
				//----ПРОВЕРКА НА ЗАПОЛНЕННОСТЬ СВЕРХУ----//
				if (!check() || !checkField())
				{
					checkAus = true;
					pauseBreak = true;
					stopSpace = true;
					//cout << "here" << endl;
				}
			
				//for (size_t i = 0; i < H; i++)
				//{
				//	for (size_t j = 0; j < W; j++)
				//	{
				//		cout << field[i][j] << " ";
				//	}
				//	cout << endl;
				//}
			}
			
		
			if (dx != 0)
			{
				//while (!checkForPrototypeTop())
				//	for (USHORT i = 0; i < 4; i++)
				//	{
				//		//e[i].y = figures[typeOfTetramino1][i] / 2;
				//		e[i].y--;
				//	}
				countOfSamePos = 0;
				while (true)
				{
					for (USHORT i = 0; i < 4; i++)
					{
						e[i].y--;
						if (e[i].y == a[i].y) countOfSamePos++;
					}
					if (countOfSamePos == 4) break;
				}
				falling_down(j, e);
			}
			
			//----ПРОВЕРКА НА ЗАПОЛНЕННОСТЬ СВЕРХУ----//это тут пока не нужно
			//if (!check() || !checkField())
			//{
			//	checkAus = true;
			//	pauseBreak = true;
			//	stopSpace = true;
			//	//cout << "here" << endl;
			//}

				//для отрисовки фигуры на поле после моментального падения во время анимации
			if (forFigureBot)
			{
				for (USHORT i = 0; i < 4; i++)
					field[e[i].y][e[i].x + 4] = colorNum; ///тут править
				forFigureBot = false;
				//checkForFigureBot = false;
				//cout << "blablabla" << endl;
				//cout << "===============================Beginning=================================" << endl;
				////cout << "Before" << endl;
				//for (int i = 0; i < 4; i++)
				//{
				//	cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
				//	//cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				//}
				//cout << endl;
				//for (int i = 0; i < 4; i++)
				//{
				//	//cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
				//	cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				//}
				//cout << "===============================End=======================================" << endl;
				//cout << endl << endl;

			}

			// для предварительной отрисовки фигур снизу
		if (startGame && beginGame2 && !pauseBreak)
		{
			falling_down(j, e);
			beginGame2 = false;
		}
		
	

		dx = 0;
		rotateRight = 0;
		rotateLeft = 0;
		delay = 0.6f;

		//----ОТРИСОВКА----//
		window.clear(Color::White);
		window.draw(*sprite_background);
		window.draw(*sprite_left_frame);
		window.draw(*sprite_right_frame);
		window.draw(*sprite_right_frame_bottom);
		if (set_grid)
			window.draw(*sprite_table);


		window.draw(*shOfLefttext);
		window.draw(*lefttext);
		window.draw(*shOfScore);
		window.draw(*score);
		window.draw(*shOfBest_score);
		window.draw(*best_score);
		window.draw(*shOfLevel);
		window.draw(*level);
		window.draw(*shOfLines);
		window.draw(*lines);
		window.draw(*shOfSpeed);
		window.draw(*speed);
		window.draw(*shOfPlayer);
		window.draw(*player);
		window.draw(*shOfName);
		window.draw(*name);
		window.draw(*shOfTime);
		window.draw(*time2);
		

		// Отрисовка таймера
		if (startGame && !pauseBreak && !checkAus) secondsTemp2 = secondsTemp + clockForTimer.getElapsedTime().asSeconds();

		seconds = secondsTemp2;

		if (seconds == secondsMax)
		{
			seconds = 0;
			clockForTimer.restart();
			minutes++;
			secondsTemp = 0;
			secondsTemp2 = 0;
		}
		if (minutes == minutesMax)
		{
			minutes = 0;
			hours++;
		}
		if (hours == hoursMax)window.close();//temporarely

		if(seconds < 10 && minutes < 10 && hours < 10) numOfTime = "0" + ToString(hours) + " : " + "0" + ToString(minutes) + " : " + "0" + ToString(seconds);
		else if(seconds > 9 && minutes > 9 && hours < 10) numOfTime = "0" + ToString(hours) + " : " + ToString(minutes) + " : " + ToString(seconds);
		else if(seconds > 9 && minutes < 10 && hours < 10) numOfTime = "0" + ToString(hours) + " : " + "0" + ToString(minutes) + " : " + ToString(seconds);
		else if(seconds < 10 && minutes > 9 && hours < 10) numOfTime = "0" + ToString(hours) + " : " +  ToString(minutes) + " : " + "0" + ToString(seconds);

		else if (seconds < 10 && minutes < 10 && hours > 9) numOfTime = ToString(hours) + " : " + "0" + ToString(minutes) + " : " + "0" + ToString(seconds);
		else if (seconds > 9 && minutes > 9 && hours > 9) numOfTime = ToString(hours) + " : " + ToString(minutes) + " : " + ToString(seconds);
		else if (seconds > 9 && minutes < 10 && hours > 9) numOfTime = ToString(hours) + " : " + "0" + ToString(minutes) + " : " + ToString(seconds);
		else if (seconds < 10 && minutes > 9 && hours > 9) numOfTime = ToString(hours) + " : " + ToString(minutes) + " : " + "0" + ToString(seconds);
		clockTime->setString(numOfTime);
		shOfClockTime->setString(numOfTime);
		window.draw(*shOfClockTime);
		window.draw(*clockTime);

		/*cout << clockForTimer.getElapsedTime().asSeconds() << endl << endl << endl;
		cout << secondsTemp << endl;*/
		//Отрисовка кнопки Start
		if (!start_newGame_button)
			if (IntRect(1584, 953, 300, 100).contains(mousePos.x, mousePos.y))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_start_st3);
				else window.draw(*sprite_button_start_st2);
			}
			else window.draw(*sprite_button_start_st1);

		//Отрисовка кнопки New game
		else if (start_newGame_button)
			if (IntRect(1584, 953, 300, 100).contains(mousePos.x, mousePos.y))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_newgame_st3);
				else window.draw(*sprite_button_newgame_st2);
			}
			else window.draw(*sprite_button_newgame_st1);

		//Отрисовка кнопки Options

		if (IntRect(36, 32, 256, 62).contains(mousePos.x, mousePos.y))

		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				window.draw(*sprite_button_options_st3);
			}
			else window.draw(*sprite_button_options_st2);
		}
		else window.draw(*sprite_button_options_st1);

		//проверка для трех кнопок
		if (IntRect(1629, 32, 85, 62).contains(mousePos.x, mousePos.y)) isLeftButton = true;
		else isLeftButton = false;

		if (IntRect(1799, 32, 85, 62).contains(mousePos.x, mousePos.y)) isRightButton = true;
		else isRightButton = false;

		if (IntRect(1714, 32, 85, 62).contains(mousePos.x, mousePos.y)) isMiddleButton = true;
		else isMiddleButton = false;

		//Отрисовка трех кнопок сверху справа
		if(isLeftButton) draw_3buttons(window, mousePos, *sprite_button_left_st1, *sprite_button_left_st2, *sprite_button_left_st3, *sprite_button_right_st1, *sprite_button_right_st2, *sprite_button_right_st3,
			*sprite_button_middle_restore_st1, *sprite_button_middle_restore_st2, *sprite_button_middle_restore_st3);
		else if(isRightButton) draw_3buttons2(window, mousePos, *sprite_button_left_st1, *sprite_button_left_st2, *sprite_button_left_st3, *sprite_button_right_st1, *sprite_button_right_st2, *sprite_button_right_st3,
			*sprite_button_middle_restore_st1, *sprite_button_middle_restore_st2, *sprite_button_middle_restore_st3);
		else draw_3buttons3(window, mousePos, *sprite_button_left_st1, *sprite_button_left_st2, *sprite_button_left_st3, *sprite_button_right_st1, *sprite_button_right_st2, *sprite_button_right_st3,
			*sprite_button_middle_restore_st1, *sprite_button_middle_restore_st2, *sprite_button_middle_restore_st3);

		
		//Отрисовка кнопки pause
		if (!pause_resume_button)
		{
			if (IntRect(216, 963, 80, 80).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_pause_st3);
				//else window.draw(*sprite_button_pause_st2);
				else window.draw(*sprite_button_pause_st4);
			else window.draw(*sprite_button_pause_st1);
		}


		//Отрисовка кнопки resume
	/*	if(pause_resume_button)
		{ 
			if (IntRect(216, 963, 80, 80).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_resume_st3);
				else window.draw(*sprite_button_resume_st2);
			else window.draw(*sprite_button_resume_st1);
		}*/

		if (pause_resume_button)
		{
			if (IntRect(216, 963, 80, 80).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left) && !checkAus)
					window.draw(*sprite_button_pause_st3);
				else window.draw(*sprite_button_pause_st4);
			else window.draw(*sprite_button_pause_st4);
		}
		
		//Отрисовка кнопки soundOn
		if(soundOn_sounOff_button)
		if (IntRect(36, 963, 80, 80).contains(mousePos.x, mousePos.y))
			if (Mouse::isButtonPressed(Mouse::Left))
				window.draw(*sprite_button_soundOn_st3);
			//else window.draw(*sprite_button_soundOn_st2);
			else window.draw(*sprite_button_soundOn_st4);
		else window.draw(*sprite_button_soundOn_st4);

		//Отрисовка кнопки soundOff
		/*else if(!soundOn_sounOff_button)
		if (IntRect(36, 963, 80, 80).contains(mousePos.x, mousePos.y))
			if (Mouse::isButtonPressed(Mouse::Left))
				window.draw(*sprite_button_soundOff_st3);
			else window.draw(*sprite_button_soundOff_st2);
		else window.draw(*sprite_button_soundOff_st1);*/

		else if (!soundOn_sounOff_button)
			if (IntRect(36, 963, 80, 80).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_soundOn_st3);
				else window.draw(*sprite_button_soundOn_st4);
			else window.draw(*sprite_button_soundOn_st1);

		//Отрисовка кнопки musicOff
		/*if(!musicOn_musicOff_button)
		if (IntRect(126, 963, 80, 80).contains(mousePos.x, mousePos.y))
			if (Mouse::isButtonPressed(Mouse::Left))
				window.draw(*sprite_button_musicOff_st3);
			else window.draw(*sprite_button_musicOff_st2);
		else window.draw(*sprite_button_musicOff_st1);*/

		if (!musicOn_musicOff_button)
			if (IntRect(126, 963, 80, 80).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_musicOn_st3);
				else window.draw(*sprite_button_musicOn_st4);
			else window.draw(*sprite_button_musicOn_st1);

		//Отрисовка кнопки musicOn
		else if (musicOn_musicOff_button)
			if (IntRect(126, 963, 80, 80).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_musicOn_st3);
				else window.draw(*sprite_button_musicOn_st4);
			else window.draw(*sprite_button_musicOn_st4);

	//sdfssfs

			//cout << "===============================Beginning=================================" << endl;
			//	for (int i = 0; i < 4; i++)
			//	{
			//		//cout << "a[i].x : " << a[i].x << '\t' << "a[i].y :" << a[i].y << endl;
			//		cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;
			//	}
			//	cout << "===============================End=======================================" << endl;
			//	cout << endl << endl;

			//Отрисовка предварительного тетрамино снизу
			if (startGame && !enableAnimation1line && !enableAnimation2lines && !enableAnimation2lines_with_void && !enableAnimation3lines
				&& !enableAnimation3lines_with_void && !enableAnimation4lines)
			{
				switch (typeOfTetramino1)
				{
				case 0:
					switch (colorNum)
					{
					case 1:
						sprite_I_red->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_red->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_red->rotate(90);
							if (rotateBack90)sprite_I_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_red->rotate(270);
							if (rotateForward90)sprite_I_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_red);
						break;
					case 2:
						sprite_I_blue->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_blue->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_blue->rotate(90);
							if (rotateBack90)sprite_I_blue->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_blue->rotate(270);
							if (rotateForward90)sprite_I_blue->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_blue);
						break;
					case 3:
						sprite_I_green->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_green->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_green->rotate(90);
							if (rotateBack90)sprite_I_green->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_green->rotate(270);
							if (rotateForward90)sprite_I_green->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_green);
						break;
					case 4:
						sprite_I_yellow->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_yellow->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_yellow->rotate(90);
							if (rotateBack90)sprite_I_yellow->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_yellow->rotate(270);
							if (rotateForward90)sprite_I_yellow->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_yellow);
						break;
					case 5:
						sprite_I_purple->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_purple->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_purple->rotate(90);
							if (rotateBack90)sprite_I_purple->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_purple->rotate(270);
							if (rotateForward90)sprite_I_purple->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_purple);
						break;
					case 6:
						sprite_I_orange->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_orange->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_orange->rotate(90);
							if (rotateBack90)sprite_I_orange->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_orange->rotate(270);
							if (rotateForward90)sprite_I_orange->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_orange);
						break;
					case 7:
						sprite_I_brown->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_brown->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_brown->rotate(90);
							if (rotateBack90)sprite_I_brown->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_brown->rotate(270);
							if (rotateForward90)sprite_I_brown->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_brown);
						break;
					case 8:
						sprite_I_pink->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_pink->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_pink->rotate(90);
							if (rotateBack90)sprite_I_pink->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_pink->rotate(270);
							if (rotateForward90)sprite_I_pink->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_pink);
						break;
					case 9:
						sprite_I_black->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_black->setPosition(e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[0].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_I_black->rotate(90);
							if (rotateBack90)sprite_I_black->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_black->rotate(270);
							if (rotateForward90)sprite_I_black->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_black);
						break;
					}
					break;

				case 1:
					switch (colorNum)
					{
					case 1:
						sprite_S_red->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_red->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_red->rotate(90);
							if (rotateBack90)sprite_S_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_red->rotate(270);
							if (rotateForward90)sprite_S_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_red);
						break;
					case 2:
						sprite_S_blue->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_blue->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_blue->rotate(90);
							if (rotateBack90)sprite_S_blue->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_blue->rotate(270);
							if (rotateForward90)sprite_S_blue->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_blue);
						break;
					case 3:
						sprite_S_green->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_green->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_green->rotate(90);
							if (rotateBack90)sprite_S_green->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_green->rotate(270);
							if (rotateForward90)sprite_S_green->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_green);
						break;
					case 4:
						sprite_S_yellow->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_yellow->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_yellow->rotate(90);
							if (rotateBack90)sprite_S_yellow->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_yellow->rotate(270);
							if (rotateForward90)sprite_S_yellow->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_yellow);
						break;
					case 5:
						sprite_S_purple->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_purple->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_purple->rotate(90);
							if (rotateBack90)sprite_S_purple->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_purple->rotate(270);
							if (rotateForward90)sprite_S_purple->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_purple);
						break;
					case 6:
						sprite_S_orange->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_orange->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_orange->rotate(90);
							if (rotateBack90)sprite_S_orange->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_orange->rotate(270);
							if (rotateForward90)sprite_S_orange->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_orange);
						break;
					case 7:
						sprite_S_brown->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_brown->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_brown->rotate(90);
							if (rotateBack90)sprite_S_brown->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_brown->rotate(270);
							if (rotateForward90)sprite_S_brown->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_brown);
						break;
					case 8:
						sprite_S_pink->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_pink->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_pink->rotate(90);
							if (rotateBack90)sprite_S_pink->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_pink->rotate(270);
							if (rotateForward90)sprite_S_pink->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_pink);
						break;
					case 9:
						sprite_S_black->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_S_black->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_S_black->rotate(90);
							if (rotateBack90)sprite_S_black->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_S_black->rotate(270);
							if (rotateForward90)sprite_S_black->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_S_black);
						break;
					}
					break;

				case 2:
					switch (colorNum)
					{
					case 1:
						sprite_Z_red->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_red->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_red->rotate(90);
							if (rotateBack90)sprite_Z_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_red->rotate(270);
							if (rotateForward90)sprite_Z_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_red);
						break;
					case 2:
						sprite_Z_blue->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_blue->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_blue->rotate(90);
							if (rotateBack90)sprite_Z_blue->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_blue->rotate(270);
							if (rotateForward90)sprite_Z_blue->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_blue);
						break;
					case 3:
						sprite_Z_green->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_green->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_green->rotate(90);
							if (rotateBack90)sprite_Z_green->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_green->rotate(270);
							if (rotateForward90)sprite_Z_green->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_green);
						break;
					case 4:
						sprite_Z_yellow->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_yellow->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_yellow->rotate(90);
							if (rotateBack90)sprite_Z_yellow->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_yellow->rotate(270);
							if (rotateForward90)sprite_Z_yellow->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_yellow);
						break;
					case 5:
						sprite_Z_purple->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_purple->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_purple->rotate(90);
							if (rotateBack90)sprite_Z_purple->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_purple->rotate(270);
							if (rotateForward90)sprite_Z_purple->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_purple);
						break;
					case 6:
						sprite_Z_orange->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_orange->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_orange->rotate(90);
							if (rotateBack90)sprite_Z_orange->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_orange->rotate(270);
							if (rotateForward90)sprite_Z_orange->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_orange);
						break;
					case 7:
						sprite_Z_brown->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_brown->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_brown->rotate(90);
							if (rotateBack90)sprite_Z_brown->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_brown->rotate(270);
							if (rotateForward90)sprite_Z_brown->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_brown);
						break;
					case 8:
						sprite_Z_pink->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_pink->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_pink->rotate(90);
							if (rotateBack90)sprite_Z_pink->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_pink->rotate(270);
							if (rotateForward90)sprite_Z_pink->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_pink);
						break;
					case 9:
						sprite_Z_black->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_Z_black->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_Z_black->rotate(90);
							if (rotateBack90)sprite_Z_black->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_Z_black->rotate(270);
							if (rotateForward90)sprite_Z_black->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_Z_black);
						break;
					}
					break;

				case 3:
					switch (colorNum)
					{
					case 1:
						sprite_T_red->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_red->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_red->rotate(90);
							if (rotateBack90)sprite_T_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_red->rotate(270);
							if (rotateForward90)sprite_T_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_red);
						break;
					case 2:
						sprite_T_blue->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_blue->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_blue->rotate(90);
							if (rotateBack90)sprite_T_blue->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_blue->rotate(270);
							if (rotateForward90)sprite_T_blue->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_blue);
						break;
					case 3:
						sprite_T_green->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_green->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_green->rotate(90);
							if (rotateBack90)sprite_T_green->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_green->rotate(270);
							if (rotateForward90)sprite_T_green->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_green);
						break;
					case 4:
						sprite_T_yellow->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_yellow->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_yellow->rotate(90);
							if (rotateBack90)sprite_T_yellow->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_yellow->rotate(270);
							if (rotateForward90)sprite_T_yellow->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_yellow);
						break;
					case 5:
						sprite_T_purple->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_purple->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_purple->rotate(90);
							if (rotateBack90)sprite_T_purple->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_purple->rotate(270);
							if (rotateForward90)sprite_T_purple->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_purple);
						break;
					case 6:
						sprite_T_orange->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_orange->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_orange->rotate(90);
							if (rotateBack90)sprite_T_orange->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_orange->rotate(270);
							if (rotateForward90)sprite_T_orange->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_orange);
						break;
					case 7:
						sprite_T_brown->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_brown->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_brown->rotate(90);
							if (rotateBack90)sprite_T_brown->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_brown->rotate(270);
							if (rotateForward90)sprite_T_brown->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_brown);
						break;
					case 8:
						sprite_T_pink->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_pink->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_pink->rotate(90);
							if (rotateBack90)sprite_T_pink->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_pink->rotate(270);
							if (rotateForward90)sprite_T_pink->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_pink);
						break;
					case 9:
						sprite_T_black->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_T_black->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_T_black->rotate(90);
							if (rotateBack90)sprite_T_black->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_T_black->rotate(270);
							if (rotateForward90)sprite_T_black->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_T_black);
						break;
					}
				
					break;

				case 4:
					switch (colorNum)
					{
					case 1:
						sprite_L_red->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_red->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_red->rotate(90);
							if (rotateBack90)sprite_L_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_red->rotate(270);
							if (rotateForward90)sprite_L_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_red);
						break;
					case 2:
						sprite_L_blue->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_blue->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_blue->rotate(90);
							if (rotateBack90)sprite_L_blue->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_blue->rotate(270);
							if (rotateForward90)sprite_L_blue->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_blue);
						break;
					case 3:
						sprite_L_green->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_green->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_green->rotate(90);
							if (rotateBack90)sprite_L_green->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_green->rotate(270);
							if (rotateForward90)sprite_L_green->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_green);
						break;
					case 4:
						sprite_L_yellow->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_yellow->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_yellow->rotate(90);
							if (rotateBack90)sprite_L_yellow->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_yellow->rotate(270);
							if (rotateForward90)sprite_L_yellow->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_yellow);
						break;
					case 5:
						sprite_L_purple->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_purple->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_purple->rotate(90);
							if (rotateBack90)sprite_L_purple->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_purple->rotate(270);
							if (rotateForward90)sprite_L_purple->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_purple);
						break;
					case 6:
						sprite_L_orange->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_orange->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_orange->rotate(90);
							if (rotateBack90)sprite_L_orange->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_orange->rotate(270);
							if (rotateForward90)sprite_L_orange->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_orange);
						break;
					case 7:
						sprite_L_brown->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_brown->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_brown->rotate(90);
							if (rotateBack90)sprite_L_brown->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_brown->rotate(270);
							if (rotateForward90)sprite_L_brown->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_brown);
						break;
					case 8:
						sprite_L_pink->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_pink->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_pink->rotate(90);
							if (rotateBack90)sprite_L_pink->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_pink->rotate(270);
							if (rotateForward90)sprite_L_pink->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_pink);
						break;
					case 9:
						sprite_L_black->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_L_black->setPosition(e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[2].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_L_black->rotate(90);
							if (rotateBack90)sprite_L_black->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_L_black->rotate(270);
							if (rotateForward90)sprite_L_black->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_L_black);
						break;
					}
					
					break;
				case 5:
					switch (colorNum)
					{
					case 1:
						sprite_J_red->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_red->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_red->rotate(90);
							if (rotateBack90)sprite_J_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_red->rotate(270);
							if (rotateForward90)sprite_J_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_red);
						break;
					case 2:
						sprite_J_blue->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_blue->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_blue->rotate(90);
							if (rotateBack90)sprite_J_blue->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_blue->rotate(270);
							if (rotateForward90)sprite_J_blue->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_blue);
						break;
					case 3:
						sprite_J_green->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_green->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_green->rotate(90);
							if (rotateBack90)sprite_J_green->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_green->rotate(270);
							if (rotateForward90)sprite_J_green->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_green);
						break;
					case 4:
						sprite_J_yellow->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_yellow->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_yellow->rotate(90);
							if (rotateBack90)sprite_J_yellow->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_yellow->rotate(270);
							if (rotateForward90)sprite_J_yellow->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_yellow);
						break;
					case 5:
						sprite_J_purple->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_purple->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_purple->rotate(90);
							if (rotateBack90)sprite_J_purple->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_purple->rotate(270);
							if (rotateForward90)sprite_J_purple->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_purple);
						break;
					case 6:
						sprite_J_orange->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_orange->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_orange->rotate(90);
							if (rotateBack90)sprite_J_orange->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_orange->rotate(270);
							if (rotateForward90)sprite_J_orange->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_orange);
						break;
					case 7:
						sprite_J_brown->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_brown->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_brown->rotate(90);
							if (rotateBack90)sprite_J_brown->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_brown->rotate(270);
							if (rotateForward90)sprite_J_brown->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_brown);
						break;
					case 8:
						sprite_J_pink->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_pink->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_pink->rotate(90);
							if (rotateBack90)sprite_J_pink->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_pink->rotate(270);
							if (rotateForward90)sprite_J_pink->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_pink);
						break;
					case 9:
						sprite_J_black->setOrigin(40 + 38 + 19, 40 + 19);
						sprite_J_black->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19, e[1].y * 38 + 219 - 38 - 2 + 40 + 19);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							sprite_J_black->rotate(90);
							if (rotateBack90)sprite_J_black->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_J_black->rotate(270);
							if (rotateForward90)sprite_J_black->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_J_black);
						break;
					}
					break;

				case 6:
					switch (colorNum)
					{
					case 1:
						sprite_O_red->setOrigin(40 + 38, 40 + 38);
						sprite_O_red->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_red);
						break;
					case 2:
						sprite_O_blue->setOrigin(40 + 38, 40 + 38);
						sprite_O_blue->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_blue);
						break;
					case 3:
						sprite_O_green->setOrigin(40 + 38, 40 + 38);
						sprite_O_green->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_green);
						break;
					case 4:
						sprite_O_yellow->setOrigin(40 + 38, 40 + 38);
						sprite_O_yellow->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_yellow);
						break;
					case 5:
						sprite_O_purple->setOrigin(40 + 38, 40 + 38);
						sprite_O_purple->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_purple);
						break;
					case 6:
						sprite_O_orange->setOrigin(40 + 38, 40 + 38);
						sprite_O_orange->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_orange);
						break;
					case 7:
						sprite_O_brown->setOrigin(40 + 38, 40 + 38);
						sprite_O_brown->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_brown);
						break;
					case 8:
						sprite_O_pink->setOrigin(40 + 38, 40 + 38);
						sprite_O_pink->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_pink);
						break;
					case 9:
						sprite_O_black->setOrigin(40 + 38, 40 + 38);
						sprite_O_black->setPosition(e[1].x * 38 + 922 - 154 + 40 + 38 * 3, e[1].y * 38 + 219 - 38 - 2 + 40);
						if (set_prototype)window.draw(*sprite_O_black);
						break;
					}
					break;
				}
			
				
				turnRight = false;
				turnLeft = false;
				rotateBack90 = false;
				rotateForward90 = false;
			}

		

		//ОТРИСОВКА ТЕТРАМИНО
		if (startGame) {//Если кнопка старт или новая игра были нажаты
			if (pauseBreak)
			{
				for (int i = 0; i < 4; i++)
				{
					// Разукрашиваем тетрамино
					sprite->setTextureRect(IntRect(colorNum * 76, 0, 76, 76));
					sprite->setScale(0.5, 0.5);

					// Устанавливаем позицию каждого кусочка тетрамино
					sprite->setPosition(d[i].x * 38 + 922, d[i].y * 38 + 219);//тут править

					// Отрисовка спрайта
					if (a[i].y > -1)
					window.draw(*sprite);
				}
			}
			else if (!enableAnimation1line && !enableAnimation2lines && !enableAnimation2lines_with_void && !enableAnimation3lines
				&& !enableAnimation3lines_with_void && !enableAnimation4lines && !enableAnimation_fast_falling_3InRow_16Rows && !enableAnimation_fast_falling_1InRow_1Row &&
				!enableAnimation_fast_falling_1InRow_2Rows && !enableAnimation_fast_falling_1InRow_3Rows && !enableAnimation_fast_falling_1InRow_4Rows && 
				!enableAnimation_fast_falling_1InRow_5Rows && !enableAnimation_fast_falling_1InRow_6Rows && !enableAnimation_fast_falling_1InRow_7Rows &&
				!enableAnimation_fast_falling_1InRow_8Rows && !enableAnimation_fast_falling_1InRow_9Rows && !enableAnimation_fast_falling_1InRow_10Rows &&
				!enableAnimation_fast_falling_1InRow_11Rows && !enableAnimation_fast_falling_1InRow_12Rows && !enableAnimation_fast_falling_1InRow_13Rows &&
				!enableAnimation_fast_falling_1InRow_14Rows && !enableAnimation_fast_falling_1InRow_15Rows && !enableAnimation_fast_falling_1InRow_16Rows &&
				!enableAnimation_fast_falling_1InRow_17Rows && !enableAnimation_fast_falling_2InRow_1Row &&
				!enableAnimation_fast_falling_2InRow_2Rows && !enableAnimation_fast_falling_2InRow_3Rows && !enableAnimation_fast_falling_2InRow_4Rows &&
				!enableAnimation_fast_falling_2InRow_5Rows && !enableAnimation_fast_falling_2InRow_6Rows && !enableAnimation_fast_falling_2InRow_7Rows &&
				!enableAnimation_fast_falling_2InRow_8Rows && !enableAnimation_fast_falling_2InRow_9Rows && !enableAnimation_fast_falling_2InRow_10Rows &&
				!enableAnimation_fast_falling_2InRow_11Rows && !enableAnimation_fast_falling_2InRow_12Rows && !enableAnimation_fast_falling_2InRow_13Rows &&
				!enableAnimation_fast_falling_2InRow_14Rows && !enableAnimation_fast_falling_2InRow_15Rows && !enableAnimation_fast_falling_2InRow_16Rows &&
				!enableAnimation_fast_falling_2InRow_17Rows && !enableAnimation_fast_falling_3InRow_1Row &&
				!enableAnimation_fast_falling_3InRow_2Rows && !enableAnimation_fast_falling_3InRow_3Rows && !enableAnimation_fast_falling_3InRow_4Rows &&
				!enableAnimation_fast_falling_3InRow_5Rows && !enableAnimation_fast_falling_3InRow_6Rows && !enableAnimation_fast_falling_3InRow_7Rows &&
				!enableAnimation_fast_falling_3InRow_8Rows && !enableAnimation_fast_falling_3InRow_9Rows && !enableAnimation_fast_falling_3InRow_10Rows &&
				!enableAnimation_fast_falling_3InRow_11Rows && !enableAnimation_fast_falling_3InRow_12Rows && !enableAnimation_fast_falling_3InRow_13Rows &&
				!enableAnimation_fast_falling_3InRow_14Rows && !enableAnimation_fast_falling_3InRow_15Rows && !enableAnimation_fast_falling_3InRow_16Rows &&
				!enableAnimation_fast_falling_3InRow_17Rows && !enableAnimation_fast_falling_3InRow_18Rows &&
				!enableAnimation_fast_falling_4InRow_1Row &&
				!enableAnimation_fast_falling_4InRow_2Rows && !enableAnimation_fast_falling_4InRow_3Rows && !enableAnimation_fast_falling_4InRow_4Rows &&
				!enableAnimation_fast_falling_4InRow_5Rows && !enableAnimation_fast_falling_4InRow_6Rows && !enableAnimation_fast_falling_4InRow_7Rows &&
				!enableAnimation_fast_falling_4InRow_8Rows && !enableAnimation_fast_falling_4InRow_9Rows && !enableAnimation_fast_falling_4InRow_10Rows &&
				!enableAnimation_fast_falling_4InRow_11Rows && !enableAnimation_fast_falling_4InRow_12Rows && !enableAnimation_fast_falling_4InRow_13Rows &&
				!enableAnimation_fast_falling_4InRow_14Rows && !enableAnimation_fast_falling_4InRow_15Rows && !enableAnimation_fast_falling_4InRow_16Rows &&
				!enableAnimation_fast_falling_4InRow_17Rows && !enableAnimation_fast_falling_4InRow_18Rows
				)
				for (int i = 0; i < 4; i++)
				{
					// Разукрашиваем тетрамино
					sprite->setTextureRect(IntRect(colorNum * 76, 0, 76, 76));
					sprite->setScale(0.5, 0.5);

					// Устанавливаем позицию каждого кусочка тетрамино
					sprite->setPosition(a[i].x * 38 + 922, a[i].y * 38 + 219);//тут править

					// Отрисовка спрайта
						if (a[i].y > -1)
						window.draw(*sprite);
				}
			
			//отрисовка тетрамино в верхнем поле
			for (int i = 0; i < 4; i++)
			{
				// Разукрашиваем тетрамино
				sprite->setTextureRect(IntRect(colorNum2 * 76, 0, 76, 76));
				sprite->setScale(0.5, 0.5);

				// Устанавливаем позицию каждого кусочка тетрамино

				sprite->setPosition(c[i].x * 38 + 922, c[i].y * 38 + 14);//тут править

				//Смещение спрайтов верхних фигур
				switch (typeOfTetramino2)
				{
				case 0: sprite->move(0, 38);
					break;
				case 1: sprite->move(19, -19);
					break;
				case 2: sprite->move(-19, 19);
					break;
				case 3: sprite->move(-19, -19);
					break;
				case 4: sprite->move(-57, 19);
					break;
				case 5: sprite->move(-19, -19);
					break;
				case 6: sprite->move(0, 57);
					break;
				}

				// Отрисовка спрайта
				window.draw(*sprite);
			}

			////----ПРОВЕРКА ЛИНИИ на заполненность снизу----//
			//USHORT k = H - 1;
			//for (USHORT i = H - 1; i > 0; i--)
			//{
			//	USHORT count = 0;
			//	for (USHORT j = 0; j < W; j++)
			//	{
			//		if (field[i][j]) count++;
			//		field[k][j] = field[i][j];
			//	}
			//	if (count < W) k--;
			//	else checkFullLine = true;//для обновления падения прототипов фигур
			//}

			//ОТРИСОВКА ТЕТРАМИНО СНИЗУ
			for (USHORT i = 0; i < H; i++)
				for (USHORT j = 0; j < W; j++)
				{
					if (field[i][j] == 0) continue;
					sprite->setTextureRect(IntRect(field[i][j] * 76, 0, 76, 76));
					sprite->setScale(0.5, 0.5);
					sprite->setPosition(j * 38 + 770, i * 38 + 219);//тут править
					window.draw(*sprite);
				}

		

		}
		/*if (checkFullLine) falling_down(j, e);
		checkFullLine = false;*/

		//Отрисовка поля Are you sure?
		if (checkAus)
		{
			secondsTemp = secondsTemp2;
			window.draw(*sprite_ays_frame);
			window.draw(*sprite_ays_question);
			
			//кнопка yes
			if (IntRect(735, 547, 85, 37).contains(mousePos.x, mousePos.y))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					pauseBreak = false;
					pause_resume_button = false;
					checkAus = false;
					for (USHORT i = 0; i < H; i++)
						for (USHORT j = 0; j < W; j++)
							field[i][j] = 0;
					startGame = true;
					colorNum = 1 + rand() % 9;
					colorNum2 = 1 + rand() % 9;
					beginGame = true;
					beginGame2 = true;
					beginGame3 = true;
					hours = 0;
					minutes = 0;
					seconds = 0;
					secondsTemp = 0;
					clockForTimer.restart();
					sprite_I_red->setRotation(0);
					sprite_S_red->setRotation(0);
					sprite_Z_red->setRotation(0);
					sprite_T_red->setRotation(0);
					sprite_L_red->setRotation(0);
					sprite_J_red->setRotation(0);
					sprite_O_red->setRotation(0);
					numberOfWide.clear();
					numberOfWide.push_back(0);
					numberOfNarrow.clear();
					numberOfNarrow.push_back(1);
				}
				else window.draw(*sprite_ays_yes2st);
			}
			else window.draw(*sprite_ays_yes1st);
			//кнопка no
			if (IntRect(1113, 547, 71, 37).contains(mousePos.x, mousePos.y))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					clockForTimer.restart();
					checkAus = false;
					pauseBreak = false;
					pause_resume_button = false;
				}
				else window.draw(*sprite_ays_no2st);
			}
			else window.draw(*sprite_ays_no1st);
			
		}
		/*cout << spriteAn_1line_1->getPosition().x << endl;
		cout << spriteAn_1line_1->getPosition().y << endl;*/
		
		if(enableAnimation1line)
		animation_1_lineFn(window, indexOfLastLine, spriteAn_1line_1, spriteAn_1line_2, spriteAn_1line_3, spriteAn_1line_4, spriteAn_1line_5, spriteAn_1line_6, spriteAn_1line_7,
			spriteAn_1line_8, spriteAn_1line_9, spriteAn_1line_10, spriteAn_1line_11, spriteAn_1line_12, spriteAn_1line_13, spriteAn_1line_14, spriteAn_1line_15,
			spriteAn_1line_16, spriteAn_1line_17, spriteAn_1line_18, spriteAn_1line_19, spriteAn_1line_20, spriteAn_1line_21, spriteAn_1line_22);
		if(enableAnimation2lines)
			animation_2_linesFn(window, indexOfLastLine, spriteAn_2lines_1, spriteAn_2lines_2, spriteAn_2lines_3, spriteAn_2lines_4, spriteAn_2lines_5, spriteAn_2lines_6, spriteAn_2lines_7,
				spriteAn_2lines_8, spriteAn_2lines_9, spriteAn_2lines_10, spriteAn_2lines_11, spriteAn_2lines_12, spriteAn_2lines_13, spriteAn_2lines_14, spriteAn_2lines_15,
				spriteAn_2lines_16, spriteAn_2lines_17, spriteAn_2lines_18, spriteAn_2lines_19, spriteAn_2lines_20, spriteAn_2lines_21, spriteAn_2lines_22);
		if(enableAnimation3lines)
			animation_3_linesFn(window, indexOfLastLine, spriteAn_3lines_1, spriteAn_3lines_2, spriteAn_3lines_3, spriteAn_3lines_4, spriteAn_3lines_5, spriteAn_3lines_6, spriteAn_3lines_7,
				spriteAn_3lines_8, spriteAn_3lines_9, spriteAn_3lines_10, spriteAn_3lines_11, spriteAn_3lines_12, spriteAn_3lines_13, spriteAn_3lines_14, spriteAn_3lines_15,
				spriteAn_3lines_16, spriteAn_3lines_17, spriteAn_3lines_18, spriteAn_3lines_19, spriteAn_3lines_20, spriteAn_3lines_21, spriteAn_3lines_22);
		if(enableAnimation4lines)
			animation_4_linesFn(window, indexOfLastLine, spriteAn_4lines_1, spriteAn_4lines_2, spriteAn_4lines_3, spriteAn_4lines_4, spriteAn_4lines_5, spriteAn_4lines_6, spriteAn_4lines_7,
				spriteAn_4lines_8, spriteAn_4lines_9, spriteAn_4lines_10, spriteAn_4lines_11, spriteAn_4lines_12, spriteAn_4lines_13, spriteAn_4lines_14, spriteAn_4lines_15,
				spriteAn_4lines_16, spriteAn_4lines_17, spriteAn_4lines_18, spriteAn_4lines_19, spriteAn_4lines_20, spriteAn_4lines_21, spriteAn_4lines_22);
		if(enableAnimation2lines_with_void)
			animation_2_lines_with_voidFn(window, indexesOfIdLines, spriteAn_1line_1, spriteAn_1line_2, spriteAn_1line_3, spriteAn_1line_4, spriteAn_1line_5, spriteAn_1line_6, spriteAn_1line_7,
				spriteAn_1line_8, spriteAn_1line_9, spriteAn_1line_10, spriteAn_1line_11, spriteAn_1line_12, spriteAn_1line_13, spriteAn_1line_14, spriteAn_1line_15,
				spriteAn_1line_16, spriteAn_1line_17, spriteAn_1line_18, spriteAn_1line_19, spriteAn_1line_20, spriteAn_1line_21, spriteAn_1line_22);
		if (enableAnimation3lines_with_void)
			animation_3_lines_with_voidFn(window, indexesOfIdLines, spriteAn_1line_1, spriteAn_1line_2, spriteAn_1line_3, spriteAn_1line_4, spriteAn_1line_5, spriteAn_1line_6, spriteAn_1line_7,
				spriteAn_1line_8, spriteAn_1line_9, spriteAn_1line_10, spriteAn_1line_11, spriteAn_1line_12, spriteAn_1line_13, spriteAn_1line_14, spriteAn_1line_15,
				spriteAn_1line_16, spriteAn_1line_17, spriteAn_1line_18, spriteAn_1line_19, spriteAn_1line_20, spriteAn_1line_21, spriteAn_1line_22, spriteAn_2lines_1, spriteAn_2lines_2, spriteAn_2lines_3, spriteAn_2lines_4, spriteAn_2lines_5, spriteAn_2lines_6, spriteAn_2lines_7,
				spriteAn_2lines_8, spriteAn_2lines_9, spriteAn_2lines_10, spriteAn_2lines_11, spriteAn_2lines_12, spriteAn_2lines_13, spriteAn_2lines_14, spriteAn_2lines_15,
				spriteAn_2lines_16, spriteAn_2lines_17, spriteAn_2lines_18, spriteAn_2lines_19, spriteAn_2lines_20, spriteAn_2lines_21, spriteAn_2lines_22);
		if (enableAnimation_fast_falling_3InRow_16Rows)
			animation_fast_falling_3InRow_16RowsFn(window, spriteAn_3_inRow_16Rows_1, spriteAn_3_inRow_16Rows_2, spriteAn_3_inRow_16Rows_3, spriteAn_3_inRow_16Rows_4,
				spriteAn_3_inRow_16Rows_5, spriteAn_3_inRow_16Rows_6, spriteAn_3_inRow_16Rows_7, spriteAn_3_inRow_16Rows_8, spriteAn_3_inRow_16Rows_9,
				spriteAn_3_inRow_16Rows_10, spriteAn_3_inRow_16Rows_11, spriteAn_3_inRow_16Rows_12);
		if (enableAnimation_fast_falling_1InRow_1Row)
			animation_fast_falling_1InRow_1RowFn(window, spriteAn_1_inRow_1Row_1, spriteAn_1_inRow_1Row_2);
		if (enableAnimation_fast_falling_1InRow_2Rows)
			animation_fast_falling_1InRow_2RowsFn(window, spriteAn_1_inRow_2Rows_1, spriteAn_1_inRow_2Rows_2);
		if (enableAnimation_fast_falling_1InRow_3Rows)
			animation_fast_falling_1InRow_3RowsFn(window, spriteAn_1_inRow_3Rows_1, spriteAn_1_inRow_3Rows_2);
		if (enableAnimation_fast_falling_1InRow_4Rows)
			animation_fast_falling_1InRow_4RowsFn(window, spriteAn_1_inRow_4Rows_1, spriteAn_1_inRow_4Rows_2, spriteAn_1_inRow_4Rows_3, spriteAn_1_inRow_4Rows_4);
		if (enableAnimation_fast_falling_1InRow_5Rows)
			animation_fast_falling_1InRow_5RowsFn(window, spriteAn_1_inRow_5Rows_1, spriteAn_1_inRow_5Rows_2, spriteAn_1_inRow_5Rows_3, spriteAn_1_inRow_5Rows_4);
		if (enableAnimation_fast_falling_1InRow_6Rows)
			animation_fast_falling_1InRow_6RowsFn(window, spriteAn_1_inRow_6Rows_1, spriteAn_1_inRow_6Rows_2, spriteAn_1_inRow_6Rows_3, spriteAn_1_inRow_6Rows_4);
		if (enableAnimation_fast_falling_1InRow_7Rows)
			animation_fast_falling_1InRow_7RowsFn(window, spriteAn_1_inRow_7Rows_1, spriteAn_1_inRow_7Rows_2, spriteAn_1_inRow_7Rows_3, spriteAn_1_inRow_7Rows_4,
				spriteAn_1_inRow_7Rows_5, spriteAn_1_inRow_7Rows_6);
		if (enableAnimation_fast_falling_1InRow_8Rows)
			animation_fast_falling_1InRow_8RowsFn(window, spriteAn_1_inRow_8Rows_1, spriteAn_1_inRow_8Rows_2, spriteAn_1_inRow_8Rows_3, spriteAn_1_inRow_8Rows_4,
				spriteAn_1_inRow_8Rows_5, spriteAn_1_inRow_8Rows_6);
		if (enableAnimation_fast_falling_1InRow_9Rows)
			animation_fast_falling_1InRow_9RowsFn(window, spriteAn_1_inRow_9Rows_1, spriteAn_1_inRow_9Rows_2, spriteAn_1_inRow_9Rows_3, spriteAn_1_inRow_9Rows_4,
				spriteAn_1_inRow_9Rows_5, spriteAn_1_inRow_9Rows_6);
		if (enableAnimation_fast_falling_1InRow_10Rows)
		animation_fast_falling_1InRow_10RowsFn(window, spriteAn_1_inRow_10Rows_1, spriteAn_1_inRow_10Rows_2, spriteAn_1_inRow_10Rows_3, spriteAn_1_inRow_10Rows_4,
			spriteAn_1_inRow_10Rows_5, spriteAn_1_inRow_10Rows_6, spriteAn_1_inRow_10Rows_7, spriteAn_1_inRow_10Rows_8);
		if (enableAnimation_fast_falling_1InRow_11Rows)
		animation_fast_falling_1InRow_11RowsFn(window, spriteAn_1_inRow_11Rows_1, spriteAn_1_inRow_11Rows_2, spriteAn_1_inRow_11Rows_3, spriteAn_1_inRow_11Rows_4,
			spriteAn_1_inRow_11Rows_5, spriteAn_1_inRow_11Rows_6, spriteAn_1_inRow_11Rows_7, spriteAn_1_inRow_11Rows_8);
		if (enableAnimation_fast_falling_1InRow_12Rows)
			animation_fast_falling_1InRow_12RowsFn(window, spriteAn_1_inRow_12Rows_1, spriteAn_1_inRow_12Rows_2, spriteAn_1_inRow_12Rows_3, spriteAn_1_inRow_12Rows_4,
				spriteAn_1_inRow_12Rows_5, spriteAn_1_inRow_12Rows_6, spriteAn_1_inRow_12Rows_7, spriteAn_1_inRow_12Rows_8);
		if (enableAnimation_fast_falling_1InRow_13Rows)
			animation_fast_falling_1InRow_13RowsFn(window, spriteAn_1_inRow_13Rows_1, spriteAn_1_inRow_13Rows_2, spriteAn_1_inRow_13Rows_3, spriteAn_1_inRow_13Rows_4,
				spriteAn_1_inRow_13Rows_5, spriteAn_1_inRow_13Rows_6, spriteAn_1_inRow_13Rows_7, spriteAn_1_inRow_13Rows_8, spriteAn_1_inRow_13Rows_9, spriteAn_1_inRow_13Rows_10);
		if (enableAnimation_fast_falling_1InRow_14Rows)
			animation_fast_falling_1InRow_14RowsFn(window, spriteAn_1_inRow_14Rows_1, spriteAn_1_inRow_14Rows_2, spriteAn_1_inRow_14Rows_3, spriteAn_1_inRow_14Rows_4,
				spriteAn_1_inRow_14Rows_5, spriteAn_1_inRow_14Rows_6, spriteAn_1_inRow_14Rows_7, spriteAn_1_inRow_14Rows_8, spriteAn_1_inRow_14Rows_9, spriteAn_1_inRow_14Rows_10);
		if (enableAnimation_fast_falling_1InRow_15Rows)
			animation_fast_falling_1InRow_15RowsFn(window, spriteAn_1_inRow_15Rows_1, spriteAn_1_inRow_15Rows_2, spriteAn_1_inRow_15Rows_3, spriteAn_1_inRow_15Rows_4,
				spriteAn_1_inRow_15Rows_5, spriteAn_1_inRow_15Rows_6, spriteAn_1_inRow_15Rows_7, spriteAn_1_inRow_15Rows_8, spriteAn_1_inRow_15Rows_9, spriteAn_1_inRow_15Rows_10);
		if (enableAnimation_fast_falling_1InRow_16Rows)
			animation_fast_falling_1InRow_16RowsFn(window, spriteAn_1_inRow_16Rows_1, spriteAn_1_inRow_16Rows_2, spriteAn_1_inRow_16Rows_3, spriteAn_1_inRow_16Rows_4,
				spriteAn_1_inRow_16Rows_5, spriteAn_1_inRow_16Rows_6, spriteAn_1_inRow_16Rows_7, spriteAn_1_inRow_16Rows_8, spriteAn_1_inRow_16Rows_9, spriteAn_1_inRow_16Rows_10,
				spriteAn_1_inRow_16Rows_11, spriteAn_1_inRow_16Rows_12);
		if (enableAnimation_fast_falling_1InRow_17Rows)
			animation_fast_falling_1InRow_17RowsFn(window, spriteAn_1_inRow_17Rows_1, spriteAn_1_inRow_17Rows_2, spriteAn_1_inRow_17Rows_3, spriteAn_1_inRow_17Rows_4,
				spriteAn_1_inRow_17Rows_5, spriteAn_1_inRow_17Rows_6, spriteAn_1_inRow_17Rows_7, spriteAn_1_inRow_17Rows_8, spriteAn_1_inRow_17Rows_9, spriteAn_1_inRow_17Rows_10,
				spriteAn_1_inRow_17Rows_11, spriteAn_1_inRow_17Rows_12);

		if (enableAnimation_fast_falling_2InRow_1Row)
			animation_fast_falling_2InRow_1RowFn(window, spriteAn_2_inRow_1Row_1, spriteAn_2_inRow_1Row_2);
		if (enableAnimation_fast_falling_2InRow_2Rows)
			animation_fast_falling_2InRow_2RowsFn(window, spriteAn_2_inRow_2Rows_1, spriteAn_2_inRow_2Rows_2);
		if (enableAnimation_fast_falling_2InRow_3Rows)
			animation_fast_falling_2InRow_3RowsFn(window, spriteAn_2_inRow_3Rows_1, spriteAn_2_inRow_3Rows_2);
		if (enableAnimation_fast_falling_2InRow_4Rows)
			animation_fast_falling_2InRow_4RowsFn(window, spriteAn_2_inRow_4Rows_1, spriteAn_2_inRow_4Rows_2, spriteAn_2_inRow_4Rows_3, spriteAn_2_inRow_4Rows_4);
		if (enableAnimation_fast_falling_2InRow_5Rows)
			animation_fast_falling_2InRow_5RowsFn(window, spriteAn_2_inRow_5Rows_1, spriteAn_2_inRow_5Rows_2, spriteAn_2_inRow_5Rows_3, spriteAn_2_inRow_5Rows_4);
		if (enableAnimation_fast_falling_2InRow_6Rows)
			animation_fast_falling_2InRow_6RowsFn(window, spriteAn_2_inRow_6Rows_1, spriteAn_2_inRow_6Rows_2, spriteAn_2_inRow_6Rows_3, spriteAn_2_inRow_6Rows_4);
		if (enableAnimation_fast_falling_2InRow_7Rows)
			animation_fast_falling_2InRow_7RowsFn(window, spriteAn_2_inRow_7Rows_1, spriteAn_2_inRow_7Rows_2, spriteAn_2_inRow_7Rows_3, spriteAn_2_inRow_7Rows_4, spriteAn_2_inRow_7Rows_5, spriteAn_2_inRow_7Rows_6);
		if (enableAnimation_fast_falling_2InRow_8Rows)
			animation_fast_falling_2InRow_8RowsFn(window, spriteAn_2_inRow_8Rows_1, spriteAn_2_inRow_8Rows_2, spriteAn_2_inRow_8Rows_3, spriteAn_2_inRow_8Rows_4, spriteAn_2_inRow_8Rows_5, spriteAn_2_inRow_8Rows_6);
		if (enableAnimation_fast_falling_2InRow_9Rows)
			animation_fast_falling_2InRow_9RowsFn(window, spriteAn_2_inRow_9Rows_1, spriteAn_2_inRow_9Rows_2, spriteAn_2_inRow_9Rows_3, spriteAn_2_inRow_9Rows_4, spriteAn_2_inRow_9Rows_5, spriteAn_2_inRow_9Rows_6);
		if (enableAnimation_fast_falling_2InRow_10Rows)
			animation_fast_falling_2InRow_10RowsFn(window, spriteAn_2_inRow_10Rows_1, spriteAn_2_inRow_10Rows_2, spriteAn_2_inRow_10Rows_3, spriteAn_2_inRow_10Rows_4, spriteAn_2_inRow_10Rows_5, spriteAn_2_inRow_10Rows_6, spriteAn_2_inRow_10Rows_7, spriteAn_2_inRow_10Rows_8);
		if (enableAnimation_fast_falling_2InRow_11Rows)
			animation_fast_falling_2InRow_11RowsFn(window, spriteAn_2_inRow_11Rows_1, spriteAn_2_inRow_11Rows_2, spriteAn_2_inRow_11Rows_3, spriteAn_2_inRow_11Rows_4, spriteAn_2_inRow_11Rows_5, spriteAn_2_inRow_11Rows_6, spriteAn_2_inRow_11Rows_7, spriteAn_2_inRow_11Rows_8);
		if (enableAnimation_fast_falling_2InRow_12Rows)
			animation_fast_falling_2InRow_12RowsFn(window, spriteAn_2_inRow_12Rows_1, spriteAn_2_inRow_12Rows_2, spriteAn_2_inRow_12Rows_3, spriteAn_2_inRow_12Rows_4, spriteAn_2_inRow_12Rows_5, spriteAn_2_inRow_12Rows_6, spriteAn_2_inRow_12Rows_7, spriteAn_2_inRow_12Rows_8);
		if (enableAnimation_fast_falling_2InRow_13Rows)
			animation_fast_falling_2InRow_13RowsFn(window, spriteAn_2_inRow_13Rows_1, spriteAn_2_inRow_13Rows_2, spriteAn_2_inRow_13Rows_3, spriteAn_2_inRow_13Rows_4, spriteAn_2_inRow_13Rows_5, spriteAn_2_inRow_13Rows_6, spriteAn_2_inRow_13Rows_7, spriteAn_2_inRow_13Rows_8, spriteAn_2_inRow_13Rows_9, spriteAn_2_inRow_13Rows_10);
		if (enableAnimation_fast_falling_2InRow_14Rows)
			animation_fast_falling_2InRow_14RowsFn(window, spriteAn_2_inRow_14Rows_1, spriteAn_2_inRow_14Rows_2, spriteAn_2_inRow_14Rows_3, spriteAn_2_inRow_14Rows_4, spriteAn_2_inRow_14Rows_5, spriteAn_2_inRow_14Rows_6, spriteAn_2_inRow_14Rows_7, spriteAn_2_inRow_14Rows_8, spriteAn_2_inRow_14Rows_9, spriteAn_2_inRow_14Rows_10);
		if (enableAnimation_fast_falling_2InRow_15Rows)
			animation_fast_falling_2InRow_15RowsFn(window, spriteAn_2_inRow_15Rows_1, spriteAn_2_inRow_15Rows_2, spriteAn_2_inRow_15Rows_3, spriteAn_2_inRow_15Rows_4, spriteAn_2_inRow_15Rows_5, spriteAn_2_inRow_15Rows_6, spriteAn_2_inRow_15Rows_7, spriteAn_2_inRow_15Rows_8, spriteAn_2_inRow_15Rows_9, spriteAn_2_inRow_15Rows_10);
		if (enableAnimation_fast_falling_2InRow_16Rows)
			animation_fast_falling_2InRow_16RowsFn(window, spriteAn_2_inRow_16Rows_1, spriteAn_2_inRow_16Rows_2, spriteAn_2_inRow_16Rows_3, spriteAn_2_inRow_16Rows_4, spriteAn_2_inRow_16Rows_5, spriteAn_2_inRow_16Rows_6, spriteAn_2_inRow_16Rows_7, spriteAn_2_inRow_16Rows_8, spriteAn_2_inRow_16Rows_9, spriteAn_2_inRow_16Rows_10, spriteAn_2_inRow_16Rows_11, spriteAn_2_inRow_16Rows_12);
		if (enableAnimation_fast_falling_2InRow_17Rows)
			animation_fast_falling_2InRow_17RowsFn(window, spriteAn_2_inRow_17Rows_1, spriteAn_2_inRow_17Rows_2, spriteAn_2_inRow_17Rows_3, spriteAn_2_inRow_17Rows_4, spriteAn_2_inRow_17Rows_5, spriteAn_2_inRow_17Rows_6, spriteAn_2_inRow_17Rows_7, spriteAn_2_inRow_17Rows_8, spriteAn_2_inRow_17Rows_9, spriteAn_2_inRow_17Rows_10, spriteAn_2_inRow_17Rows_11, spriteAn_2_inRow_17Rows_12);
		
		if (enableAnimation_fast_falling_3InRow_1Row)
			animation_fast_falling_3InRow_1RowFn(window, spriteAn_3_inRow_1Row_1, spriteAn_3_inRow_1Row_2);
		if (enableAnimation_fast_falling_3InRow_2Rows)
			animation_fast_falling_3InRow_2RowsFn(window, spriteAn_3_inRow_2Rows_1, spriteAn_3_inRow_2Rows_2);
		if (enableAnimation_fast_falling_3InRow_3Rows)
			animation_fast_falling_3InRow_3RowsFn(window, spriteAn_3_inRow_3Rows_1, spriteAn_3_inRow_3Rows_2);
		if (enableAnimation_fast_falling_3InRow_4Rows)
			animation_fast_falling_3InRow_4RowsFn(window, spriteAn_3_inRow_4Rows_1, spriteAn_3_inRow_4Rows_2, spriteAn_3_inRow_4Rows_3, spriteAn_3_inRow_4Rows_4);
		if (enableAnimation_fast_falling_3InRow_5Rows)
			animation_fast_falling_3InRow_5RowsFn(window, spriteAn_3_inRow_5Rows_1, spriteAn_3_inRow_5Rows_2, spriteAn_3_inRow_5Rows_3, spriteAn_3_inRow_5Rows_4);
		if (enableAnimation_fast_falling_3InRow_6Rows)
			animation_fast_falling_3InRow_6RowsFn(window, spriteAn_3_inRow_6Rows_1, spriteAn_3_inRow_6Rows_2, spriteAn_3_inRow_6Rows_3, spriteAn_3_inRow_6Rows_4);
		if (enableAnimation_fast_falling_3InRow_7Rows)
			animation_fast_falling_3InRow_7RowsFn(window, spriteAn_3_inRow_7Rows_1, spriteAn_3_inRow_7Rows_2, spriteAn_3_inRow_7Rows_3, spriteAn_3_inRow_7Rows_4, spriteAn_3_inRow_7Rows_5, spriteAn_3_inRow_7Rows_6);
		if (enableAnimation_fast_falling_3InRow_8Rows)
			animation_fast_falling_3InRow_8RowsFn(window, spriteAn_3_inRow_8Rows_1, spriteAn_3_inRow_8Rows_2, spriteAn_3_inRow_8Rows_3, spriteAn_3_inRow_8Rows_4, spriteAn_3_inRow_8Rows_5, spriteAn_3_inRow_8Rows_6);
		if (enableAnimation_fast_falling_3InRow_9Rows)
			animation_fast_falling_3InRow_9RowsFn(window, spriteAn_3_inRow_9Rows_1, spriteAn_3_inRow_9Rows_2, spriteAn_3_inRow_9Rows_3, spriteAn_3_inRow_9Rows_4, spriteAn_3_inRow_9Rows_5, spriteAn_3_inRow_9Rows_6);
		if (enableAnimation_fast_falling_3InRow_10Rows)
			animation_fast_falling_3InRow_10RowsFn(window, spriteAn_3_inRow_10Rows_1, spriteAn_3_inRow_10Rows_2, spriteAn_3_inRow_10Rows_3, spriteAn_3_inRow_10Rows_4, spriteAn_3_inRow_10Rows_5, spriteAn_3_inRow_10Rows_6, spriteAn_3_inRow_10Rows_7, spriteAn_3_inRow_10Rows_8);
		if (enableAnimation_fast_falling_3InRow_11Rows)
			animation_fast_falling_3InRow_11RowsFn(window, spriteAn_3_inRow_11Rows_1, spriteAn_3_inRow_11Rows_2, spriteAn_3_inRow_11Rows_3, spriteAn_3_inRow_11Rows_4, spriteAn_3_inRow_11Rows_5, spriteAn_3_inRow_11Rows_6, spriteAn_3_inRow_11Rows_7, spriteAn_3_inRow_11Rows_8);
		if (enableAnimation_fast_falling_3InRow_12Rows)
			animation_fast_falling_3InRow_12RowsFn(window, spriteAn_3_inRow_12Rows_1, spriteAn_3_inRow_12Rows_2, spriteAn_3_inRow_12Rows_3, spriteAn_3_inRow_12Rows_4, spriteAn_3_inRow_12Rows_5, spriteAn_3_inRow_12Rows_6, spriteAn_3_inRow_12Rows_7, spriteAn_3_inRow_12Rows_8);
		if (enableAnimation_fast_falling_3InRow_13Rows)
			animation_fast_falling_3InRow_13RowsFn(window, spriteAn_3_inRow_13Rows_1, spriteAn_3_inRow_13Rows_2, spriteAn_3_inRow_13Rows_3, spriteAn_3_inRow_13Rows_4, spriteAn_3_inRow_13Rows_5, spriteAn_3_inRow_13Rows_6, spriteAn_3_inRow_13Rows_7, spriteAn_3_inRow_13Rows_8, spriteAn_3_inRow_13Rows_9, spriteAn_3_inRow_13Rows_10);
		if (enableAnimation_fast_falling_3InRow_14Rows)
			animation_fast_falling_3InRow_14RowsFn(window, spriteAn_3_inRow_14Rows_1, spriteAn_3_inRow_14Rows_2, spriteAn_3_inRow_14Rows_3, spriteAn_3_inRow_14Rows_4, spriteAn_3_inRow_14Rows_5, spriteAn_3_inRow_14Rows_6, spriteAn_3_inRow_14Rows_7, spriteAn_3_inRow_14Rows_8, spriteAn_3_inRow_14Rows_9, spriteAn_3_inRow_14Rows_10);
		if (enableAnimation_fast_falling_3InRow_15Rows)
			animation_fast_falling_3InRow_15RowsFn(window, spriteAn_3_inRow_15Rows_1, spriteAn_3_inRow_15Rows_2, spriteAn_3_inRow_15Rows_3, spriteAn_3_inRow_15Rows_4, spriteAn_3_inRow_15Rows_5, spriteAn_3_inRow_15Rows_6, spriteAn_3_inRow_15Rows_7, spriteAn_3_inRow_15Rows_8, spriteAn_3_inRow_15Rows_9, spriteAn_3_inRow_15Rows_10);
		if (enableAnimation_fast_falling_3InRow_17Rows)
			animation_fast_falling_3InRow_17RowsFn(window, spriteAn_3_inRow_17Rows_1, spriteAn_3_inRow_17Rows_2, spriteAn_3_inRow_17Rows_3, spriteAn_3_inRow_17Rows_4, spriteAn_3_inRow_17Rows_5, spriteAn_3_inRow_17Rows_6, spriteAn_3_inRow_17Rows_7, spriteAn_3_inRow_17Rows_8, spriteAn_3_inRow_17Rows_9, spriteAn_3_inRow_17Rows_10, spriteAn_3_inRow_17Rows_11, spriteAn_3_inRow_17Rows_12);
		if (enableAnimation_fast_falling_3InRow_18Rows)
			animation_fast_falling_3InRow_18RowsFn(window, spriteAn_3_inRow_18Rows_1, spriteAn_3_inRow_18Rows_2, spriteAn_3_inRow_18Rows_3, spriteAn_3_inRow_18Rows_4, spriteAn_3_inRow_18Rows_5, spriteAn_3_inRow_18Rows_6, spriteAn_3_inRow_18Rows_7, spriteAn_3_inRow_18Rows_8, spriteAn_3_inRow_18Rows_9, spriteAn_3_inRow_18Rows_10, spriteAn_3_inRow_18Rows_11, spriteAn_3_inRow_18Rows_12);
		checkFullLineFn2(field);

		if (enableAnimation_fast_falling_4InRow_1Row)
			animation_fast_falling_4InRow_1RowFn(window, spriteAn_4_inRow_1Row_1, spriteAn_4_inRow_1Row_2);
		if (enableAnimation_fast_falling_4InRow_2Rows)
			animation_fast_falling_4InRow_2RowsFn(window, spriteAn_4_inRow_2Rows_1, spriteAn_4_inRow_2Rows_2);
		if (enableAnimation_fast_falling_4InRow_3Rows)
			animation_fast_falling_4InRow_3RowsFn(window, spriteAn_4_inRow_3Rows_1, spriteAn_4_inRow_3Rows_2);
		if (enableAnimation_fast_falling_4InRow_4Rows)
			animation_fast_falling_4InRow_4RowsFn(window, spriteAn_4_inRow_4Rows_1, spriteAn_4_inRow_4Rows_2, spriteAn_4_inRow_4Rows_3, spriteAn_4_inRow_4Rows_4);
		if (enableAnimation_fast_falling_4InRow_5Rows)
			animation_fast_falling_4InRow_5RowsFn(window, spriteAn_4_inRow_5Rows_1, spriteAn_4_inRow_5Rows_2, spriteAn_4_inRow_5Rows_3, spriteAn_4_inRow_5Rows_4);
		if (enableAnimation_fast_falling_4InRow_6Rows)
			animation_fast_falling_4InRow_6RowsFn(window, spriteAn_4_inRow_6Rows_1, spriteAn_4_inRow_6Rows_2, spriteAn_4_inRow_6Rows_3, spriteAn_4_inRow_6Rows_4);
		if (enableAnimation_fast_falling_4InRow_7Rows)
			animation_fast_falling_4InRow_7RowsFn(window, spriteAn_4_inRow_7Rows_1, spriteAn_4_inRow_7Rows_2, spriteAn_4_inRow_7Rows_3, spriteAn_4_inRow_7Rows_4, spriteAn_4_inRow_7Rows_5, spriteAn_4_inRow_7Rows_6);
		if (enableAnimation_fast_falling_4InRow_8Rows)
			animation_fast_falling_4InRow_8RowsFn(window, spriteAn_4_inRow_8Rows_1, spriteAn_4_inRow_8Rows_2, spriteAn_4_inRow_8Rows_3, spriteAn_4_inRow_8Rows_4, spriteAn_4_inRow_8Rows_5, spriteAn_4_inRow_8Rows_6);
		if (enableAnimation_fast_falling_4InRow_9Rows)
			animation_fast_falling_4InRow_9RowsFn(window, spriteAn_4_inRow_9Rows_1, spriteAn_4_inRow_9Rows_2, spriteAn_4_inRow_9Rows_3, spriteAn_4_inRow_9Rows_4, spriteAn_4_inRow_9Rows_5, spriteAn_4_inRow_9Rows_6);
		if (enableAnimation_fast_falling_4InRow_10Rows)
			animation_fast_falling_4InRow_10RowsFn(window, spriteAn_4_inRow_10Rows_1, spriteAn_4_inRow_10Rows_2, spriteAn_4_inRow_10Rows_3, spriteAn_4_inRow_10Rows_4, spriteAn_4_inRow_10Rows_5, spriteAn_4_inRow_10Rows_6, spriteAn_4_inRow_10Rows_7, spriteAn_4_inRow_10Rows_8);
		if (enableAnimation_fast_falling_4InRow_11Rows)
			animation_fast_falling_4InRow_11RowsFn(window, spriteAn_4_inRow_11Rows_1, spriteAn_4_inRow_11Rows_2, spriteAn_4_inRow_11Rows_3, spriteAn_4_inRow_11Rows_4, spriteAn_4_inRow_11Rows_5, spriteAn_4_inRow_11Rows_6, spriteAn_4_inRow_11Rows_7, spriteAn_4_inRow_11Rows_8);
		if (enableAnimation_fast_falling_4InRow_12Rows)
			animation_fast_falling_4InRow_12RowsFn(window, spriteAn_4_inRow_12Rows_1, spriteAn_4_inRow_12Rows_2, spriteAn_4_inRow_12Rows_3, spriteAn_4_inRow_12Rows_4, spriteAn_4_inRow_12Rows_5, spriteAn_4_inRow_12Rows_6, spriteAn_4_inRow_12Rows_7, spriteAn_4_inRow_12Rows_8);
		if (enableAnimation_fast_falling_4InRow_13Rows)
			animation_fast_falling_4InRow_13RowsFn(window, spriteAn_4_inRow_13Rows_1, spriteAn_4_inRow_13Rows_2, spriteAn_4_inRow_13Rows_3, spriteAn_4_inRow_13Rows_4, spriteAn_4_inRow_13Rows_5, spriteAn_4_inRow_13Rows_6, spriteAn_4_inRow_13Rows_7, spriteAn_4_inRow_13Rows_8, spriteAn_4_inRow_13Rows_9, spriteAn_4_inRow_13Rows_10);
		if (enableAnimation_fast_falling_4InRow_14Rows)
			animation_fast_falling_4InRow_14RowsFn(window, spriteAn_4_inRow_14Rows_1, spriteAn_4_inRow_14Rows_2, spriteAn_4_inRow_14Rows_3, spriteAn_4_inRow_14Rows_4, spriteAn_4_inRow_14Rows_5, spriteAn_4_inRow_14Rows_6, spriteAn_4_inRow_14Rows_7, spriteAn_4_inRow_14Rows_8, spriteAn_4_inRow_14Rows_9, spriteAn_4_inRow_14Rows_10);
		if (enableAnimation_fast_falling_4InRow_15Rows)
			animation_fast_falling_4InRow_15RowsFn(window, spriteAn_4_inRow_15Rows_1, spriteAn_4_inRow_15Rows_2, spriteAn_4_inRow_15Rows_3, spriteAn_4_inRow_15Rows_4, spriteAn_4_inRow_15Rows_5, spriteAn_4_inRow_15Rows_6, spriteAn_4_inRow_15Rows_7, spriteAn_4_inRow_15Rows_8, spriteAn_4_inRow_15Rows_9, spriteAn_4_inRow_15Rows_10);
		if (enableAnimation_fast_falling_4InRow_16Rows)
			animation_fast_falling_4InRow_16RowsFn(window, spriteAn_4_inRow_16Rows_1, spriteAn_4_inRow_16Rows_2, spriteAn_4_inRow_16Rows_3, spriteAn_4_inRow_16Rows_4, spriteAn_4_inRow_16Rows_5, spriteAn_4_inRow_16Rows_6, spriteAn_4_inRow_16Rows_7, spriteAn_4_inRow_16Rows_8, spriteAn_4_inRow_16Rows_9, spriteAn_4_inRow_16Rows_10, spriteAn_4_inRow_16Rows_11, spriteAn_4_inRow_16Rows_12);
		if (enableAnimation_fast_falling_4InRow_17Rows)
			animation_fast_falling_4InRow_17RowsFn(window, spriteAn_4_inRow_17Rows_1, spriteAn_4_inRow_17Rows_2, spriteAn_4_inRow_17Rows_3, spriteAn_4_inRow_17Rows_4, spriteAn_4_inRow_17Rows_5, spriteAn_4_inRow_17Rows_6, spriteAn_4_inRow_17Rows_7, spriteAn_4_inRow_17Rows_8, spriteAn_4_inRow_17Rows_9, spriteAn_4_inRow_17Rows_10, spriteAn_4_inRow_17Rows_11, spriteAn_4_inRow_17Rows_12);
		if (enableAnimation_fast_falling_4InRow_18Rows)
			animation_fast_falling_4InRow_18RowsFn(window, spriteAn_4_inRow_18Rows_1, spriteAn_4_inRow_18Rows_2, spriteAn_4_inRow_18Rows_3, spriteAn_4_inRow_18Rows_4, spriteAn_4_inRow_18Rows_5, spriteAn_4_inRow_18Rows_6, spriteAn_4_inRow_18Rows_7, spriteAn_4_inRow_18Rows_8, spriteAn_4_inRow_18Rows_9, spriteAn_4_inRow_18Rows_10, spriteAn_4_inRow_18Rows_11, spriteAn_4_inRow_18Rows_12);
		
		checkFullLineFn2(field);

		//cursor
		window.draw(*sprite_myCursor);
		//here was checking for bottom
		// Отрисовка окна	
		window.display();
		//cout << indexesOfIdLines.size() << endl;
		
	}
	return 0;
}

Image *LoadImageFromResource(const unsigned short& ID, const char* type)
{
	HRSRC rsrcData = FindResource(NULL, MAKEINTRESOURCE(ID), type);
	
	if (!rsrcData)
	throw std::runtime_error("Failed to find resource.");
	
	DWORD rsrcDataSize = SizeofResource(NULL, rsrcData);
	if (rsrcDataSize <= 0)
		throw std::runtime_error("Size of resource is 0.");

	HGLOBAL grsrcData = LoadResource(NULL, rsrcData);
	if (!grsrcData)
		throw std::runtime_error("Failed to load resource.");

	LPVOID firstByte = LockResource(grsrcData);
	if (!firstByte)
		throw std::runtime_error("Failed to lock resource.");

	Image* image{ new Image };

	if (!image->loadFromMemory(firstByte, rsrcDataSize))
	throw std::runtime_error("Failed to load image from memory.");
	
	//return Image();
	return image;
}


Texture* LoadTextureFromResource(const unsigned short& ID, const char* type)
{
	HRSRC rsrcData = FindResource(NULL, MAKEINTRESOURCE(ID), type);
	if (!rsrcData)
		throw std::runtime_error("Failed to find resource.");

	DWORD rsrcDataSize = SizeofResource(NULL, rsrcData);
	if (rsrcDataSize <= 0)
		throw std::runtime_error("Size of resource is 0.");

	HGLOBAL grsrcData = LoadResource(NULL, rsrcData);
	if (!grsrcData)
		throw std::runtime_error("Failed to load resource.");

	LPVOID firstByte = LockResource(grsrcData);
	if (!firstByte)
		throw std::runtime_error("Failed to lock resource.");

	Texture *texture = new Texture;
	if (!texture->loadFromMemory(firstByte, rsrcDataSize))
		throw std::runtime_error("Failed to load image from memory.");

	//return Texture();
	return texture;
}

Font *LoadFontFromResource(const unsigned short& ID, const char* type)
	{
		HRSRC rsrcData = FindResource(NULL, MAKEINTRESOURCE(ID), type);
		if (!rsrcData)
			throw std::runtime_error("Failed to find resource.");

		DWORD rsrcDataSize = SizeofResource(NULL, rsrcData);
		if (rsrcDataSize <= 0)
			throw std::runtime_error("Size of resource is 0.");

		HGLOBAL grsrcData = LoadResource(NULL, rsrcData);
		if (!grsrcData)
			throw std::runtime_error("Failed to load resource.");

		LPVOID firstByte = LockResource(grsrcData);
		if (!firstByte)
			throw std::runtime_error("Failed to lock resource.");

		Font *font{ new Font };
		if (!font->loadFromMemory(firstByte, rsrcDataSize))
			throw std::runtime_error("Failed to load image from memory.");

		return font;
}

void fill_tetramino()
{
	 // задаём тип тетрамино
	beginGame = false;
	typeOfTetramino1 = rand() % 7;
	//typeOfTetramino1 = 1;
	//typeOfTetramino2 = 1;
	typeOfTetramino2 = rand() % 7;
	for (int i = 0; i < 4; i++)
	{
		a[i].x = figures[typeOfTetramino1][i] % 2;
		a[i].y = figures[typeOfTetramino1][i] / 2;
		e[i].x = figures[typeOfTetramino1][i] % 2;
		e[i].y = figures[typeOfTetramino1][i] / 2;
	}
}

void fill_tetramino2()
{
	for (int i = 0; i < 4; i++)
	{
		c[i].x = figures[typeOfTetramino2][i] % 2;
		c[i].y = figures[typeOfTetramino2][i] / 2;
	}
}


bool check()
{
	for (int i = 0; i < 4; i++)
	if (a[i].x < -4 || a[i].x >= W - 4 || a[i].y >= H) return 0;//тут править
	//else if (field[a[i].y][a[i].x + 4]) return 0;//тут править
	return 1;
}

bool checkForPrototypeHeight()
{
	for (int i = 0; i < 4; i++)
		if (e[i].y >= H) return 0;//тут править
	return 1;
}

bool checkForPrototypeLeftSide()
{
	for (int i = 0; i < 4; i++)
		if (e[i].x < -4) return 0;//тут править
	return 1;
}

bool checkForPrototypeRightSide()
{
	for (int i = 0; i < 4; i++)
		if (e[i].x >= W - 4) return 0;//тут править
	return 1;
}

bool checkForPrototypeField()
{
	for (size_t i = 0; i < 4; i++)
		if (e[i].y < 0)return 1;// если фигуры выходят за край сверху
	for (int i = 0; i < 4; i++)
		if (field[e[i].y][e[i].x + 4]) return 0;//тут править
	return 1;
}
bool checkForPrototype()
{
	for (int i = 0; i < 4; i++)
		if (e[i].x < -4 || e[i].x >= W - 4 || e[i].y >= H) return 0;//тут править
		else if (field[e[i].y][e[i].x + 4]) return 0;//тут править
	return 1;
}

bool checkForPrototypeTop()
{
	for (USHORT i = 0; i < 4; i++)
		if (e[i].y < 0)return 1;// если фигуры выходят за край сверху
	return 0;
}
bool checkField()
{
	for (size_t i = 0; i < 4; i++)
		if (a[i].y < 0)return 1;// если фигуры выходят за край сверху

	for (int i = 0; i < 4; i++)
		if (field[a[i].y][a[i].x + 4]) return 0;//тут править

	return 1;
}

void draw_3buttons(RenderWindow &win, Vector2i &mpos, Sprite &splst1, Sprite &splst2, Sprite &splst3, Sprite &sprst1, Sprite &sprst2, Sprite &sprst3, Sprite &spmst1, Sprite &spmst2, Sprite &spmst3)
{

	//Отрисовка кнопки right Close

	if (IntRect(1799, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(sprst3);
		else win.draw(sprst2);
	}
	else win.draw(sprst1);

	//Отрисовка кнопки middle restore

	if (IntRect(1714, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(spmst3);
		else win.draw(spmst2);
	}
	else win.draw(spmst1);

	//Отрисовка кнопки left Minimize

	if (IntRect(1629, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(splst3);
		else win.draw(splst2);
	}
	else win.draw(splst1);
}

void draw_3buttons2(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3)
{
	//Отрисовка кнопки middle restore

	if (IntRect(1714, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(spmst3);
		else win.draw(spmst2);
	}
	else win.draw(spmst1);

	//Отрисовка кнопки left Minimize

	if (IntRect(1629, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(splst3);
		else win.draw(splst2);
	}
	else win.draw(splst1);

	//Отрисовка кнопки right Close

	if (IntRect(1799, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(sprst3);
		else win.draw(sprst2);
	}
	else win.draw(sprst1);
}

void draw_3buttons3(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3)
{
	//Отрисовка кнопки right Close

	if (IntRect(1799, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(sprst3);
		else win.draw(sprst2);
	}
	else win.draw(sprst1);

	//Отрисовка кнопки left Minimize

	if (IntRect(1629, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(splst3);
		else win.draw(splst2);
	}
	else win.draw(splst1);

	//Отрисовка кнопки middle restore

	if (IntRect(1714, 32, 85, 62).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(spmst3);
		else win.draw(spmst2);
	}
	else win.draw(spmst1);
}

void create_window_for_loading_screen()
{
	RenderWindow* loading_screen = new RenderWindow(VideoMode(500, 500), "Tetris", Style::Close | Style::Titlebar | Style::Fullscreen);

}

void animation_1_lineFn(RenderWindow& win, USHORT index, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22)
{
	progressOfAnimationLines = true;
	spriteAn_1line_1->setPosition(0, (index - 9) * 38);
	spriteAn_1line_2->setPosition(0, (index - 9) * 38);
	spriteAn_1line_3->setPosition(0, (index - 9) * 38);
	spriteAn_1line_4->setPosition(0, (index - 9) * 38);
	spriteAn_1line_5->setPosition(0, (index - 9) * 38);
	spriteAn_1line_6->setPosition(0, (index - 9) * 38);
	spriteAn_1line_7->setPosition(0, (index - 9) * 38);
	spriteAn_1line_8->setPosition(0, (index - 9) * 38);
	spriteAn_1line_9->setPosition(0, (index - 9) * 38);
	spriteAn_1line_10->setPosition(0, (index - 9) * 38);
	spriteAn_1line_11->setPosition(0, (index - 9) * 38);
	spriteAn_1line_12->setPosition(0, (index - 9) * 38);
	spriteAn_1line_13->setPosition(0, (index - 9) * 38);
	spriteAn_1line_14->setPosition(0, (index - 9) * 38);
	spriteAn_1line_15->setPosition(0, (index - 9) * 38);
	spriteAn_1line_16->setPosition(0, (index - 9) * 38);
	spriteAn_1line_17->setPosition(0, (index - 9) * 38);
	spriteAn_1line_18->setPosition(0, (index - 9) * 38);
	spriteAn_1line_19->setPosition(0, (index - 9) * 38);
	spriteAn_1line_20->setPosition(0, (index - 9) * 38);
	spriteAn_1line_21->setPosition(0, (index - 9) * 38);
	spriteAn_1line_22->setPosition(0, (index - 9) * 38);
	
	int time_1_line = animation_1_line.getElapsedTime().asMilliseconds();
	if ((time_1_line >= 0) && (time_1_line < 16)) win.draw(*spriteAn_1line_1);
	else if ((time_1_line >= 16) && (time_1_line < 32)) win.draw(*spriteAn_1line_2);
	else if ((time_1_line >= 32) && (time_1_line < 48)) win.draw(*spriteAn_1line_3);
	else if ((time_1_line >= 48) && (time_1_line < 64)) win.draw(*spriteAn_1line_4);
	else if ((time_1_line >= 64) && (time_1_line < 80)) win.draw(*spriteAn_1line_5);
	else if ((time_1_line >= 80) && (time_1_line < 96)) win.draw(*spriteAn_1line_6);
	else if ((time_1_line >= 96) && (time_1_line < 112)) win.draw(*spriteAn_1line_7);
	else if ((time_1_line >= 112) && (time_1_line < 128)) win.draw(*spriteAn_1line_8);
	else if ((time_1_line >= 128) && (time_1_line < 144)) win.draw(*spriteAn_1line_9);
	else if ((time_1_line >= 144) && (time_1_line < 160)) win.draw(*spriteAn_1line_10);
	else if ((time_1_line >= 160) && (time_1_line < 176)) win.draw(*spriteAn_1line_11);
	else if ((time_1_line >= 176) && (time_1_line < 192)) win.draw(*spriteAn_1line_12);
	else if ((time_1_line >= 192) && (time_1_line < 208)) win.draw(*spriteAn_1line_13);
	else if ((time_1_line >= 208) && (time_1_line < 224)) win.draw(*spriteAn_1line_14);
	else if ((time_1_line >= 224) && (time_1_line < 240)) win.draw(*spriteAn_1line_15);
	else if ((time_1_line >= 240) && (time_1_line < 256)) win.draw(*spriteAn_1line_16);
	else if ((time_1_line >= 256) && (time_1_line < 272)) win.draw(*spriteAn_1line_17);
	else if ((time_1_line >= 272) && (time_1_line < 288)) win.draw(*spriteAn_1line_18);
	else if ((time_1_line >= 288) && (time_1_line < 304)) win.draw(*spriteAn_1line_19);
	else if ((time_1_line >= 304) && (time_1_line < 320)) win.draw(*spriteAn_1line_20);
	else if ((time_1_line >= 320) && (time_1_line < 336)) win.draw(*spriteAn_1line_21);
	else if ((time_1_line >= 336) && (time_1_line < 352)) win.draw(*spriteAn_1line_22);
	else
	{
		afterAnimationLine = true;
		enableAnimation1line = false;
		progressOfAnimationLines = false;
	}
}

void animation_2_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5, Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11, Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17, Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22)
{
	progressOfAnimationLines = true;
	spriteAn_2lines_1->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_2->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_3->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_4->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_5->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_6->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_7->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_8->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_9->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_10->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_11->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_12->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_13->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_14->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_15->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_16->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_17->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_18->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_19->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_20->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_21->setPosition(0, (index - 9) * 38);
	spriteAn_2lines_22->setPosition(0, (index - 9) * 38);

	int time_2_lines = animation_2_lines.getElapsedTime().asMilliseconds();
	if ((time_2_lines >= 0) && (time_2_lines < 16)) win.draw(*spriteAn_2lines_1);
	else if ((time_2_lines >= 16) && (time_2_lines < 32)) win.draw(*spriteAn_2lines_2);
	else if ((time_2_lines >= 32) && (time_2_lines < 48)) win.draw(*spriteAn_2lines_3);
	else if ((time_2_lines >= 48) && (time_2_lines < 64)) win.draw(*spriteAn_2lines_4);
	else if ((time_2_lines >= 64) && (time_2_lines < 80)) win.draw(*spriteAn_2lines_5);
	else if ((time_2_lines >= 80) && (time_2_lines < 96)) win.draw(*spriteAn_2lines_6);
	else if ((time_2_lines >= 96) && (time_2_lines < 112)) win.draw(*spriteAn_2lines_7);
	else if ((time_2_lines >= 112) && (time_2_lines < 128)) win.draw(*spriteAn_2lines_8);
	else if ((time_2_lines >= 128) && (time_2_lines < 144)) win.draw(*spriteAn_2lines_9);
	else if ((time_2_lines >= 144) && (time_2_lines < 160)) win.draw(*spriteAn_2lines_10);
	else if ((time_2_lines >= 160) && (time_2_lines < 176)) win.draw(*spriteAn_2lines_11);
	else if ((time_2_lines >= 176) && (time_2_lines < 192)) win.draw(*spriteAn_2lines_12);
	else if ((time_2_lines >= 192) && (time_2_lines < 208)) win.draw(*spriteAn_2lines_13);
	else if ((time_2_lines >= 208) && (time_2_lines < 224)) win.draw(*spriteAn_2lines_14);
	else if ((time_2_lines >= 224) && (time_2_lines < 240)) win.draw(*spriteAn_2lines_15);
	else if ((time_2_lines >= 240) && (time_2_lines < 256)) win.draw(*spriteAn_2lines_16);
	else if ((time_2_lines >= 256) && (time_2_lines < 272)) win.draw(*spriteAn_2lines_17);
	else if ((time_2_lines >= 272) && (time_2_lines < 288)) win.draw(*spriteAn_2lines_18);
	else if ((time_2_lines >= 288) && (time_2_lines < 304)) win.draw(*spriteAn_2lines_19);
	else if ((time_2_lines >= 304) && (time_2_lines < 320)) win.draw(*spriteAn_2lines_20);
	else if ((time_2_lines >= 320) && (time_2_lines < 336)) win.draw(*spriteAn_2lines_21);
	else if ((time_2_lines >= 336) && (time_2_lines < 352)) win.draw(*spriteAn_2lines_22);
	else
	{
		afterAnimationLine = true;
		enableAnimation2lines = false;
		progressOfAnimationLines = false;
	}
	
}

void animation_3_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_3lines_1, Sprite* spriteAn_3lines_2, Sprite* spriteAn_3lines_3, Sprite* spriteAn_3lines_4, Sprite* spriteAn_3lines_5, Sprite* spriteAn_3lines_6, Sprite* spriteAn_3lines_7, Sprite* spriteAn_3lines_8, Sprite* spriteAn_3lines_9, Sprite* spriteAn_3lines_10, Sprite* spriteAn_3lines_11, Sprite* spriteAn_3lines_12, Sprite* spriteAn_3lines_13, Sprite* spriteAn_3lines_14, Sprite* spriteAn_3lines_15, Sprite* spriteAn_3lines_16, Sprite* spriteAn_3lines_17, Sprite* spriteAn_3lines_18, Sprite* spriteAn_3lines_19, Sprite* spriteAn_3lines_20, Sprite* spriteAn_3lines_21, Sprite* spriteAn_3lines_22)
{
	progressOfAnimationLines = true;
	spriteAn_3lines_1->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_2->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_3->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_4->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_5->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_6->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_7->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_8->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_9->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_10->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_11->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_12->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_13->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_14->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_15->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_16->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_17->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_18->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_19->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_20->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_21->setPosition(0, (index - 9) * 38);
	spriteAn_3lines_22->setPosition(0, (index - 9) * 38);

	int time_3_lines = animation_3_lines.getElapsedTime().asMilliseconds();
	if ((time_3_lines >= 0) && (time_3_lines < 16)) win.draw(*spriteAn_3lines_1);
	else if ((time_3_lines >= 16) && (time_3_lines < 32)) win.draw(*spriteAn_3lines_2);
	else if ((time_3_lines >= 32) && (time_3_lines < 48)) win.draw(*spriteAn_3lines_3);
	else if ((time_3_lines >= 48) && (time_3_lines < 64)) win.draw(*spriteAn_3lines_4);
	else if ((time_3_lines >= 64) && (time_3_lines < 80)) win.draw(*spriteAn_3lines_5);
	else if ((time_3_lines >= 80) && (time_3_lines < 96)) win.draw(*spriteAn_3lines_6);
	else if ((time_3_lines >= 96) && (time_3_lines < 112)) win.draw(*spriteAn_3lines_7);
	else if ((time_3_lines >= 112) && (time_3_lines < 128)) win.draw(*spriteAn_3lines_8);
	else if ((time_3_lines >= 128) && (time_3_lines < 144)) win.draw(*spriteAn_3lines_9);
	else if ((time_3_lines >= 144) && (time_3_lines < 160)) win.draw(*spriteAn_3lines_10);
	else if ((time_3_lines >= 160) && (time_3_lines < 176)) win.draw(*spriteAn_3lines_11);
	else if ((time_3_lines >= 176) && (time_3_lines < 192)) win.draw(*spriteAn_3lines_12);
	else if ((time_3_lines >= 192) && (time_3_lines < 208)) win.draw(*spriteAn_3lines_13);
	else if ((time_3_lines >= 208) && (time_3_lines < 224)) win.draw(*spriteAn_3lines_14);
	else if ((time_3_lines >= 224) && (time_3_lines < 240)) win.draw(*spriteAn_3lines_15);
	else if ((time_3_lines >= 240) && (time_3_lines < 256)) win.draw(*spriteAn_3lines_16);
	else if ((time_3_lines >= 256) && (time_3_lines < 272)) win.draw(*spriteAn_3lines_17);
	else if ((time_3_lines >= 272) && (time_3_lines < 288)) win.draw(*spriteAn_3lines_18);
	else if ((time_3_lines >= 288) && (time_3_lines < 304)) win.draw(*spriteAn_3lines_19);
	else if ((time_3_lines >= 304) && (time_3_lines < 320)) win.draw(*spriteAn_3lines_20);
	else if ((time_3_lines >= 320) && (time_3_lines < 336)) win.draw(*spriteAn_3lines_21);
	else if ((time_3_lines >= 336) && (time_3_lines < 352)) win.draw(*spriteAn_3lines_22);
	else
	{
		afterAnimationLine = true;
		enableAnimation3lines = false;
		progressOfAnimationLines = false;
	}

}

void animation_4_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_4lines_1, Sprite* spriteAn_4lines_2, Sprite* spriteAn_4lines_3, Sprite* spriteAn_4lines_4, Sprite* spriteAn_4lines_5, Sprite* spriteAn_4lines_6, Sprite* spriteAn_4lines_7, Sprite* spriteAn_4lines_8, Sprite* spriteAn_4lines_9, Sprite* spriteAn_4lines_10, Sprite* spriteAn_4lines_11, Sprite* spriteAn_4lines_12, Sprite* spriteAn_4lines_13, Sprite* spriteAn_4lines_14, Sprite* spriteAn_4lines_15, Sprite* spriteAn_4lines_16, Sprite* spriteAn_4lines_17, Sprite* spriteAn_4lines_18, Sprite* spriteAn_4lines_19, Sprite* spriteAn_4lines_20, Sprite* spriteAn_4lines_21, Sprite* spriteAn_4lines_22)
{
	progressOfAnimationLines = true;
	spriteAn_4lines_1->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_2->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_3->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_4->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_5->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_6->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_7->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_8->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_9->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_10->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_11->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_12->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_13->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_14->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_15->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_16->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_17->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_18->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_19->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_20->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_21->setPosition(0, (index - 9) * 38);
	spriteAn_4lines_22->setPosition(0, (index - 9) * 38);

	int time_4_lines = animation_4_lines.getElapsedTime().asMilliseconds();
	if ((time_4_lines >= 0) && (time_4_lines < 16)) win.draw(*spriteAn_4lines_1);
	else if ((time_4_lines >= 16) && (time_4_lines < 32)) win.draw(*spriteAn_4lines_2);
	else if ((time_4_lines >= 32) && (time_4_lines < 48)) win.draw(*spriteAn_4lines_3);
	else if ((time_4_lines >= 48) && (time_4_lines < 64)) win.draw(*spriteAn_4lines_4);
	else if ((time_4_lines >= 64) && (time_4_lines < 80)) win.draw(*spriteAn_4lines_5);
	else if ((time_4_lines >= 80) && (time_4_lines < 96)) win.draw(*spriteAn_4lines_6);
	else if ((time_4_lines >= 96) && (time_4_lines < 112)) win.draw(*spriteAn_4lines_7);
	else if ((time_4_lines >= 112) && (time_4_lines < 128)) win.draw(*spriteAn_4lines_8);
	else if ((time_4_lines >= 128) && (time_4_lines < 144)) win.draw(*spriteAn_4lines_9);
	else if ((time_4_lines >= 144) && (time_4_lines < 160)) win.draw(*spriteAn_4lines_10);
	else if ((time_4_lines >= 160) && (time_4_lines < 176)) win.draw(*spriteAn_4lines_11);
	else if ((time_4_lines >= 176) && (time_4_lines < 192)) win.draw(*spriteAn_4lines_12);
	else if ((time_4_lines >= 192) && (time_4_lines < 208)) win.draw(*spriteAn_4lines_13);
	else if ((time_4_lines >= 208) && (time_4_lines < 224)) win.draw(*spriteAn_4lines_14);
	else if ((time_4_lines >= 224) && (time_4_lines < 240)) win.draw(*spriteAn_4lines_15);
	else if ((time_4_lines >= 240) && (time_4_lines < 256)) win.draw(*spriteAn_4lines_16);
	else if ((time_4_lines >= 256) && (time_4_lines < 272)) win.draw(*spriteAn_4lines_17);
	else if ((time_4_lines >= 272) && (time_4_lines < 288)) win.draw(*spriteAn_4lines_18);
	else if ((time_4_lines >= 288) && (time_4_lines < 304)) win.draw(*spriteAn_4lines_19);
	else if ((time_4_lines >= 304) && (time_4_lines < 320)) win.draw(*spriteAn_4lines_20);
	else if ((time_4_lines >= 320) && (time_4_lines < 336)) win.draw(*spriteAn_4lines_21);
	else if ((time_4_lines >= 336) && (time_4_lines < 352)) win.draw(*spriteAn_4lines_22);

	else
	{
		afterAnimationLine = true;
		enableAnimation4lines = false;
		progressOfAnimationLines = false;
	}
}

void animation_2_lines_with_voidFn(RenderWindow& win, vector<USHORT>& vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5, Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11, Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17, Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22)
{
	progressOfAnimationLines = true;
	spriteAn_1line_1->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_2->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_3->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_4->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_5->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_6->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_7->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_8->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_9->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_10->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_11->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_12->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_13->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_14->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_15->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_16->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_17->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_18->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_19->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_20->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_21->setPosition(0, (vec[0] - 9) * 38);
	spriteAn_1line_22->setPosition(0, (vec[0] - 9) * 38);

	int time_1_line = animation_1_line.getElapsedTime().asMilliseconds();

	if ((time_1_line >= 0) && (time_1_line < 16)) win.draw(*spriteAn_1line_1);
	else if ((time_1_line >= 16) && (time_1_line < 32)) win.draw(*spriteAn_1line_2);
	else if ((time_1_line >= 32) && (time_1_line < 48)) win.draw(*spriteAn_1line_3);
	else if ((time_1_line >= 48) && (time_1_line < 64)) win.draw(*spriteAn_1line_4);
	else if ((time_1_line >= 64) && (time_1_line < 80)) win.draw(*spriteAn_1line_5);
	else if ((time_1_line >= 80) && (time_1_line < 96)) win.draw(*spriteAn_1line_6);
	else if ((time_1_line >= 96) && (time_1_line < 112)) win.draw(*spriteAn_1line_7);
	else if ((time_1_line >= 112) && (time_1_line < 128)) win.draw(*spriteAn_1line_8);
	else if ((time_1_line >= 128) && (time_1_line < 144)) win.draw(*spriteAn_1line_9);
	else if ((time_1_line >= 144) && (time_1_line < 160)) win.draw(*spriteAn_1line_10);
	else if ((time_1_line >= 160) && (time_1_line < 176)) win.draw(*spriteAn_1line_11);
	else if ((time_1_line >= 176) && (time_1_line < 192)) win.draw(*spriteAn_1line_12);
	else if ((time_1_line >= 192) && (time_1_line < 208)) win.draw(*spriteAn_1line_13);
	else if ((time_1_line >= 208) && (time_1_line < 224)) win.draw(*spriteAn_1line_14);
	else if ((time_1_line >= 224) && (time_1_line < 240)) win.draw(*spriteAn_1line_15);
	else if ((time_1_line >= 240) && (time_1_line < 256)) win.draw(*spriteAn_1line_16);
	else if ((time_1_line >= 256) && (time_1_line < 272)) win.draw(*spriteAn_1line_17);
	else if ((time_1_line >= 272) && (time_1_line < 288)) win.draw(*spriteAn_1line_18);
	else if ((time_1_line >= 288) && (time_1_line < 304)) win.draw(*spriteAn_1line_19);
	else if ((time_1_line >= 304) && (time_1_line < 320)) win.draw(*spriteAn_1line_20);
	else if ((time_1_line >= 320) && (time_1_line < 336)) win.draw(*spriteAn_1line_21);
	else if ((time_1_line >= 336) && (time_1_line < 352)) win.draw(*spriteAn_1line_22);
	
	spriteAn_1line_1->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_2->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_3->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_4->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_5->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_6->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_7->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_8->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_9->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_10->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_11->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_12->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_13->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_14->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_15->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_16->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_17->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_18->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_19->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_20->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_21->setPosition(0, (vec[1] - 9) * 38);
	spriteAn_1line_22->setPosition(0, (vec[1] - 9) * 38);

	if ((time_1_line >= 0) && (time_1_line < 16)) win.draw(*spriteAn_1line_1);
	else if ((time_1_line >= 16) && (time_1_line < 32)) win.draw(*spriteAn_1line_2);
	else if ((time_1_line >= 32) && (time_1_line < 48)) win.draw(*spriteAn_1line_3);
	else if ((time_1_line >= 48) && (time_1_line < 64)) win.draw(*spriteAn_1line_4);
	else if ((time_1_line >= 64) && (time_1_line < 80)) win.draw(*spriteAn_1line_5);
	else if ((time_1_line >= 80) && (time_1_line < 96)) win.draw(*spriteAn_1line_6);
	else if ((time_1_line >= 96) && (time_1_line < 112)) win.draw(*spriteAn_1line_7);
	else if ((time_1_line >= 112) && (time_1_line < 128)) win.draw(*spriteAn_1line_8);
	else if ((time_1_line >= 128) && (time_1_line < 144)) win.draw(*spriteAn_1line_9);
	else if ((time_1_line >= 144) && (time_1_line < 160)) win.draw(*spriteAn_1line_10);
	else if ((time_1_line >= 160) && (time_1_line < 176)) win.draw(*spriteAn_1line_11);
	else if ((time_1_line >= 176) && (time_1_line < 192)) win.draw(*spriteAn_1line_12);
	else if ((time_1_line >= 192) && (time_1_line < 208)) win.draw(*spriteAn_1line_13);
	else if ((time_1_line >= 208) && (time_1_line < 224)) win.draw(*spriteAn_1line_14);
	else if ((time_1_line >= 224) && (time_1_line < 240)) win.draw(*spriteAn_1line_15);
	else if ((time_1_line >= 240) && (time_1_line < 256)) win.draw(*spriteAn_1line_16);
	else if ((time_1_line >= 256) && (time_1_line < 272)) win.draw(*spriteAn_1line_17);
	else if ((time_1_line >= 272) && (time_1_line < 288)) win.draw(*spriteAn_1line_18);
	else if ((time_1_line >= 288) && (time_1_line < 304)) win.draw(*spriteAn_1line_19);
	else if ((time_1_line >= 304) && (time_1_line < 320)) win.draw(*spriteAn_1line_20);
	else if ((time_1_line >= 320) && (time_1_line < 336)) win.draw(*spriteAn_1line_21);
	else if ((time_1_line >= 336) && (time_1_line < 352)) win.draw(*spriteAn_1line_22);
	else
	{
		afterAnimationLine = true;
		enableAnimation2lines_with_void = false;
		progressOfAnimationLines = false;
	}
}

void animation_3_lines_with_voidFn(RenderWindow& win, vector<USHORT>& vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5, Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11, Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17, Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5, Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11, Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17, Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22)
{
	progressOfAnimationLines = true;
	if (indexesOfIdLines[0] - indexesOfIdLines[1] == 1)
	{
		spriteAn_1line_1->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_2->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_3->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_4->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_5->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_6->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_7->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_8->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_9->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_10->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_11->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_12->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_13->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_14->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_15->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_16->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_17->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_18->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_19->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_20->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_21->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_1line_22->setPosition(0, (vec[2] - 9) * 38);

		int time_1_line = animation_1_line.getElapsedTime().asMilliseconds();

		if ((time_1_line >= 0) && (time_1_line < 16)) win.draw(*spriteAn_1line_1);
		else if ((time_1_line >= 16) && (time_1_line < 32)) win.draw(*spriteAn_1line_2);
		else if ((time_1_line >= 32) && (time_1_line < 48)) win.draw(*spriteAn_1line_3);
		else if ((time_1_line >= 48) && (time_1_line < 64)) win.draw(*spriteAn_1line_4);
		else if ((time_1_line >= 64) && (time_1_line < 80)) win.draw(*spriteAn_1line_5);
		else if ((time_1_line >= 80) && (time_1_line < 96)) win.draw(*spriteAn_1line_6);
		else if ((time_1_line >= 96) && (time_1_line < 112)) win.draw(*spriteAn_1line_7);
		else if ((time_1_line >= 112) && (time_1_line < 128)) win.draw(*spriteAn_1line_8);
		else if ((time_1_line >= 128) && (time_1_line < 144)) win.draw(*spriteAn_1line_9);
		else if ((time_1_line >= 144) && (time_1_line < 160)) win.draw(*spriteAn_1line_10);
		else if ((time_1_line >= 160) && (time_1_line < 176)) win.draw(*spriteAn_1line_11);
		else if ((time_1_line >= 176) && (time_1_line < 192)) win.draw(*spriteAn_1line_12);
		else if ((time_1_line >= 192) && (time_1_line < 208)) win.draw(*spriteAn_1line_13);
		else if ((time_1_line >= 208) && (time_1_line < 224)) win.draw(*spriteAn_1line_14);
		else if ((time_1_line >= 224) && (time_1_line < 240)) win.draw(*spriteAn_1line_15);
		else if ((time_1_line >= 240) && (time_1_line < 256)) win.draw(*spriteAn_1line_16);
		else if ((time_1_line >= 256) && (time_1_line < 272)) win.draw(*spriteAn_1line_17);
		else if ((time_1_line >= 272) && (time_1_line < 288)) win.draw(*spriteAn_1line_18);
		else if ((time_1_line >= 288) && (time_1_line < 304)) win.draw(*spriteAn_1line_19);
		else if ((time_1_line >= 304) && (time_1_line < 320)) win.draw(*spriteAn_1line_20);
		else if ((time_1_line >= 320) && (time_1_line < 336)) win.draw(*spriteAn_1line_21);
		else if ((time_1_line >= 336) && (time_1_line < 352)) win.draw(*spriteAn_1line_22);

		spriteAn_2lines_1->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_2->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_3->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_4->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_5->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_6->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_7->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_8->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_9->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_10->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_11->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_12->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_13->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_14->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_15->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_16->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_17->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_18->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_19->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_20->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_21->setPosition(0, (vec[1] - 9) * 38);
		spriteAn_2lines_22->setPosition(0, (vec[1] - 9) * 38);

		int time_2_lines = animation_2_lines.getElapsedTime().asMilliseconds();

		if ((time_2_lines >= 0) && (time_2_lines < 16)) win.draw(*spriteAn_2lines_1);
		else if ((time_2_lines >= 16) && (time_2_lines < 32)) win.draw(*spriteAn_2lines_2);
		else if ((time_2_lines >= 32) && (time_2_lines < 48)) win.draw(*spriteAn_2lines_3);
		else if ((time_2_lines >= 48) && (time_2_lines < 64)) win.draw(*spriteAn_2lines_4);
		else if ((time_2_lines >= 64) && (time_2_lines < 80)) win.draw(*spriteAn_2lines_5);
		else if ((time_2_lines >= 80) && (time_2_lines < 96)) win.draw(*spriteAn_2lines_6);
		else if ((time_2_lines >= 96) && (time_2_lines < 112)) win.draw(*spriteAn_2lines_7);
		else if ((time_2_lines >= 112) && (time_2_lines < 128)) win.draw(*spriteAn_2lines_8);
		else if ((time_2_lines >= 128) && (time_2_lines < 144)) win.draw(*spriteAn_2lines_9);
		else if ((time_2_lines >= 144) && (time_2_lines < 160)) win.draw(*spriteAn_2lines_10);
		else if ((time_2_lines >= 160) && (time_2_lines < 176)) win.draw(*spriteAn_2lines_11);
		else if ((time_2_lines >= 176) && (time_2_lines < 192)) win.draw(*spriteAn_2lines_12);
		else if ((time_2_lines >= 192) && (time_2_lines < 208)) win.draw(*spriteAn_2lines_13);
		else if ((time_2_lines >= 208) && (time_2_lines < 224)) win.draw(*spriteAn_2lines_14);
		else if ((time_2_lines >= 224) && (time_2_lines < 240)) win.draw(*spriteAn_2lines_15);
		else if ((time_2_lines >= 240) && (time_2_lines < 256)) win.draw(*spriteAn_2lines_16);
		else if ((time_2_lines >= 256) && (time_2_lines < 272)) win.draw(*spriteAn_2lines_17);
		else if ((time_2_lines >= 272) && (time_2_lines < 288)) win.draw(*spriteAn_2lines_18);
		else if ((time_2_lines >= 288) && (time_2_lines < 304)) win.draw(*spriteAn_2lines_19);
		else if ((time_2_lines >= 304) && (time_2_lines < 320)) win.draw(*spriteAn_2lines_20);
		else if ((time_2_lines >= 320) && (time_2_lines < 336)) win.draw(*spriteAn_2lines_21);
		else if ((time_2_lines >= 336) && (time_2_lines < 352)) win.draw(*spriteAn_2lines_22);
		else
		{
			afterAnimationLine = true;
			enableAnimation3lines_with_void = false;
			progressOfAnimationLines = false;
		}

	}
	else if (indexesOfIdLines[0] - indexesOfIdLines[1] == 2)
	{
		spriteAn_2lines_1->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_2->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_3->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_4->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_5->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_6->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_7->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_8->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_9->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_10->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_11->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_12->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_13->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_14->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_15->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_16->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_17->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_18->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_19->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_20->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_21->setPosition(0, (vec[2] - 9) * 38);
		spriteAn_2lines_22->setPosition(0, (vec[2] - 9) * 38);

		int time_2_lines = animation_2_lines.getElapsedTime().asMilliseconds();

		if ((time_2_lines >= 0) && (time_2_lines < 16)) win.draw(*spriteAn_2lines_1);
		else if ((time_2_lines >= 16) && (time_2_lines < 32)) win.draw(*spriteAn_2lines_2);
		else if ((time_2_lines >= 32) && (time_2_lines < 48)) win.draw(*spriteAn_2lines_3);
		else if ((time_2_lines >= 48) && (time_2_lines < 64)) win.draw(*spriteAn_2lines_4);
		else if ((time_2_lines >= 64) && (time_2_lines < 80)) win.draw(*spriteAn_2lines_5);
		else if ((time_2_lines >= 80) && (time_2_lines < 96)) win.draw(*spriteAn_2lines_6);
		else if ((time_2_lines >= 96) && (time_2_lines < 112)) win.draw(*spriteAn_2lines_7);
		else if ((time_2_lines >= 112) && (time_2_lines < 128)) win.draw(*spriteAn_2lines_8);
		else if ((time_2_lines >= 128) && (time_2_lines < 144)) win.draw(*spriteAn_2lines_9);
		else if ((time_2_lines >= 144) && (time_2_lines < 160)) win.draw(*spriteAn_2lines_10);
		else if ((time_2_lines >= 160) && (time_2_lines < 176)) win.draw(*spriteAn_2lines_11);
		else if ((time_2_lines >= 176) && (time_2_lines < 192)) win.draw(*spriteAn_2lines_12);
		else if ((time_2_lines >= 192) && (time_2_lines < 208)) win.draw(*spriteAn_2lines_13);
		else if ((time_2_lines >= 208) && (time_2_lines < 224)) win.draw(*spriteAn_2lines_14);
		else if ((time_2_lines >= 224) && (time_2_lines < 240)) win.draw(*spriteAn_2lines_15);
		else if ((time_2_lines >= 240) && (time_2_lines < 256)) win.draw(*spriteAn_2lines_16);
		else if ((time_2_lines >= 256) && (time_2_lines < 272)) win.draw(*spriteAn_2lines_17);
		else if ((time_2_lines >= 272) && (time_2_lines < 288)) win.draw(*spriteAn_2lines_18);
		else if ((time_2_lines >= 288) && (time_2_lines < 304)) win.draw(*spriteAn_2lines_19);
		else if ((time_2_lines >= 304) && (time_2_lines < 320)) win.draw(*spriteAn_2lines_20);
		else if ((time_2_lines >= 320) && (time_2_lines < 336)) win.draw(*spriteAn_2lines_21);
		else if ((time_2_lines >= 336) && (time_2_lines < 352)) win.draw(*spriteAn_2lines_22);

		spriteAn_1line_1->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_2->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_3->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_4->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_5->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_6->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_7->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_8->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_9->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_10->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_11->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_12->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_13->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_14->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_15->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_16->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_17->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_18->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_19->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_20->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_21->setPosition(0, (vec[0] - 9) * 38);
		spriteAn_1line_22->setPosition(0, (vec[0] - 9) * 38);

		int time_1_line = animation_1_line.getElapsedTime().asMilliseconds();

		if ((time_1_line >= 0) && (time_1_line < 16)) win.draw(*spriteAn_1line_1);
		else if ((time_1_line >= 16) && (time_1_line < 32)) win.draw(*spriteAn_1line_2);
		else if ((time_1_line >= 32) && (time_1_line < 48)) win.draw(*spriteAn_1line_3);
		else if ((time_1_line >= 48) && (time_1_line < 64)) win.draw(*spriteAn_1line_4);
		else if ((time_1_line >= 64) && (time_1_line < 80)) win.draw(*spriteAn_1line_5);
		else if ((time_1_line >= 80) && (time_1_line < 96)) win.draw(*spriteAn_1line_6);
		else if ((time_1_line >= 96) && (time_1_line < 112)) win.draw(*spriteAn_1line_7);
		else if ((time_1_line >= 112) && (time_1_line < 128)) win.draw(*spriteAn_1line_8);
		else if ((time_1_line >= 128) && (time_1_line < 144)) win.draw(*spriteAn_1line_9);
		else if ((time_1_line >= 144) && (time_1_line < 160)) win.draw(*spriteAn_1line_10);
		else if ((time_1_line >= 160) && (time_1_line < 176)) win.draw(*spriteAn_1line_11);
		else if ((time_1_line >= 176) && (time_1_line < 192)) win.draw(*spriteAn_1line_12);
		else if ((time_1_line >= 192) && (time_1_line < 208)) win.draw(*spriteAn_1line_13);
		else if ((time_1_line >= 208) && (time_1_line < 224)) win.draw(*spriteAn_1line_14);
		else if ((time_1_line >= 224) && (time_1_line < 240)) win.draw(*spriteAn_1line_15);
		else if ((time_1_line >= 240) && (time_1_line < 256)) win.draw(*spriteAn_1line_16);
		else if ((time_1_line >= 256) && (time_1_line < 272)) win.draw(*spriteAn_1line_17);
		else if ((time_1_line >= 272) && (time_1_line < 288)) win.draw(*spriteAn_1line_18);
		else if ((time_1_line >= 288) && (time_1_line < 304)) win.draw(*spriteAn_1line_19);
		else if ((time_1_line >= 304) && (time_1_line < 320)) win.draw(*spriteAn_1line_20);
		else if ((time_1_line >= 320) && (time_1_line < 336)) win.draw(*spriteAn_1line_21);
		else if ((time_1_line >= 336) && (time_1_line < 352)) win.draw(*spriteAn_1line_22);
		else
		{
			afterAnimationLine = true;
			enableAnimation3lines_with_void = false;
			progressOfAnimationLines = false;
		}
	}
}

void animation_fast_falling_3InRow_16RowsFn(RenderWindow& win, Sprite* An_3_inRow_16Rows_1, Sprite* An_3_inRow_16Rows_2, Sprite* An_3_inRow_16Rows_3, Sprite* An_3_inRow_16Rows_4, Sprite* An_3_inRow_16Rows_5, Sprite* An_3_inRow_16Rows_6, Sprite* An_3_inRow_16Rows_7, Sprite* An_3_inRow_16Rows_8, Sprite* An_3_inRow_16Rows_9, Sprite* An_3_inRow_16Rows_10, Sprite* An_3_inRow_16Rows_11, Sprite* An_3_inRow_16Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	/*cout << "type1: " << typeOfTetramino1 << endl;
	cout << "type2: " << typeOfTetramino2 << endl << endl;*/
	//if (beginGame3)cout << "yes" << endl;
	//else cout << "no" << endl;
	
		if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		}

		else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2) )
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 76);
		}

		else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		}


		else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
		}

		else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		}


		else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
		}

		else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
		{
			An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
			An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295 + 38);
		}


		else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
		{
		An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295);
		}

		else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
		{
		An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 76, a[0].y * 38 + 219 - 295);
		}


		else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
		{
		An_3_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		An_3_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 295 + 38);
		}
	
	int time_ff_3InRow_16Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();
	
	if (time_ff_3InRow_16Rows >= 0 && time_ff_3InRow_16Rows < 16) win.draw(*An_3_inRow_16Rows_1);
	else if (time_ff_3InRow_16Rows >= 16 && time_ff_3InRow_16Rows < 32) win.draw(*An_3_inRow_16Rows_2);
	else if (time_ff_3InRow_16Rows >= 32 && time_ff_3InRow_16Rows < 48) win.draw(*An_3_inRow_16Rows_3);
	else if (time_ff_3InRow_16Rows >= 48 && time_ff_3InRow_16Rows < 64) win.draw(*An_3_inRow_16Rows_4);
	else if (time_ff_3InRow_16Rows >= 64 && time_ff_3InRow_16Rows < 80) win.draw(*An_3_inRow_16Rows_5);
	else if (time_ff_3InRow_16Rows >= 80 && time_ff_3InRow_16Rows < 96) win.draw(*An_3_inRow_16Rows_6);
	else if (time_ff_3InRow_16Rows >= 96 && time_ff_3InRow_16Rows < 112) win.draw(*An_3_inRow_16Rows_7);
	else if (time_ff_3InRow_16Rows >= 112 && time_ff_3InRow_16Rows < 128) win.draw(*An_3_inRow_16Rows_8);
	else if (time_ff_3InRow_16Rows >= 128 && time_ff_3InRow_16Rows < 144) win.draw(*An_3_inRow_16Rows_9);
	else if (time_ff_3InRow_16Rows >= 144 && time_ff_3InRow_16Rows < 160)
	{
		win.draw(*An_3_inRow_16Rows_10);
		//if(checkForFigureBot)
		forFigureBot = true;
	}
	else if (time_ff_3InRow_16Rows >= 160 && time_ff_3InRow_16Rows < 176) win.draw(*An_3_inRow_16Rows_11);
	else if (time_ff_3InRow_16Rows >= 176 && time_ff_3InRow_16Rows < 192) win.draw(*An_3_inRow_16Rows_12);
	else 
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_16Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_1InRow_1RowFn(RenderWindow& win, Sprite* An_1_inRow_1Row_1, Sprite* An_1_inRow_1Row_2)
{
	if(!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38);
		An_1_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38*4);
		An_1_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38*4);
	}

	int time_ff_1InRow_1Row = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_1Row >= 0 && time_ff_1InRow_1Row < 16) win.draw(*An_1_inRow_1Row_1);
	else if (time_ff_1InRow_1Row >= 16 && time_ff_1InRow_1Row < 32) win.draw(*An_1_inRow_1Row_2);
	else if (time_ff_1InRow_1Row >= 32 && time_ff_1InRow_1Row < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_1Row = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_2RowsFn(RenderWindow& win, Sprite* An_1_inRow_2Rows_1, Sprite* An_1_inRow_2Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 76);
		An_1_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 76);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_1_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	int time_ff_1InRow_2Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_2Rows >= 0 && time_ff_1InRow_2Rows < 16) win.draw(*An_1_inRow_2Rows_1);
	else if (time_ff_1InRow_2Rows >= 16 && time_ff_1InRow_2Rows < 32) win.draw(*An_1_inRow_2Rows_2);
	else if (time_ff_1InRow_2Rows >= 32 && time_ff_1InRow_2Rows < 48)/* if (checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_2Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_3RowsFn(RenderWindow& win, Sprite* An_1_inRow_3Rows_1, Sprite* An_1_inRow_3Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 114);
		An_1_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 114);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_1_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	int time_ff_1InRow_3Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_3Rows >= 0 && time_ff_1InRow_3Rows < 16) win.draw(*An_1_inRow_3Rows_1);
	else if (time_ff_1InRow_3Rows >= 16 && time_ff_1InRow_3Rows < 32) win.draw(*An_1_inRow_3Rows_2);
	else if (time_ff_1InRow_3Rows >= 32 && time_ff_1InRow_3Rows < 48) /*if (checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_3Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_4RowsFn(RenderWindow& win, Sprite* An_1_inRow_4Rows_1, Sprite* An_1_inRow_4Rows_2, Sprite* An_1_inRow_4Rows_3, Sprite* An_1_inRow_4Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 190);
		An_1_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 190);
		An_1_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 190);
		An_1_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 190);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_1_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_1_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_1_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	int time_ff_1InRow_4Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_4Rows >= 0 && time_ff_1InRow_4Rows < 16) win.draw(*An_1_inRow_4Rows_1);
	else if (time_ff_1InRow_4Rows >= 16 && time_ff_1InRow_4Rows < 32) win.draw(*An_1_inRow_4Rows_2);
	else if (time_ff_1InRow_4Rows >= 32 && time_ff_1InRow_4Rows < 48) win.draw(*An_1_inRow_4Rows_3);
	else if (time_ff_1InRow_4Rows >= 48 && time_ff_1InRow_4Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_4Rows_4);
	}
	//else if (time_ff_1InRow_4Rows >= 64 && time_ff_1InRow_4Rows < 80) win.draw(*An_3_inRow_4Rows_4);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_4Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_5RowsFn(RenderWindow& win, Sprite* An_1_inRow_5Rows_1, Sprite* An_1_inRow_5Rows_2, Sprite* An_1_inRow_5Rows_3, Sprite* An_1_inRow_5Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 228);
		An_1_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 228);
		An_1_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 228);
		An_1_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 228);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_1_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_1_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_1_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	int time_ff_1InRow_5Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_5Rows >= 0 && time_ff_1InRow_5Rows < 16) win.draw(*An_1_inRow_5Rows_1);
	else if (time_ff_1InRow_5Rows >= 16 && time_ff_1InRow_5Rows < 32) win.draw(*An_1_inRow_5Rows_2);
	else if (time_ff_1InRow_5Rows >= 32 && time_ff_1InRow_5Rows < 48) win.draw(*An_1_inRow_5Rows_3);
	else if (time_ff_1InRow_5Rows >= 48 && time_ff_1InRow_5Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_5Rows_4);
	}
	//else if (time_ff_1InRow_5Rows >= 64 && time_ff_1InRow_5Rows < 80) win.draw(*An_3_inRow_4Rows_4);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_5Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_6RowsFn(RenderWindow& win, Sprite* An_1_inRow_6Rows_1, Sprite* An_1_inRow_6Rows_2, Sprite* An_1_inRow_6Rows_3, Sprite* An_1_inRow_6Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 266);
		An_1_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 266);
		An_1_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 266);
		An_1_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 266);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_1_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_1_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_1_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	int time_ff_1InRow_6Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_6Rows >= 0 && time_ff_1InRow_6Rows < 16) win.draw(*An_1_inRow_6Rows_1);
	else if (time_ff_1InRow_6Rows >= 16 && time_ff_1InRow_6Rows < 32) win.draw(*An_1_inRow_6Rows_2);
	else if (time_ff_1InRow_6Rows >= 32 && time_ff_1InRow_6Rows < 48) win.draw(*An_1_inRow_6Rows_3);
	else if (time_ff_1InRow_6Rows >= 48 && time_ff_1InRow_6Rows < 64)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_1_inRow_6Rows_4);
	}
	//else if (time_ff_1InRow_6Rows >= 64 && time_ff_1InRow_6Rows < 80) win.draw(*An_3_inRow_4Rows_4);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_6Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_7RowsFn(RenderWindow& win, Sprite* An_1_inRow_7Rows_1, Sprite* An_1_inRow_7Rows_2, Sprite* An_1_inRow_7Rows_3, Sprite* An_1_inRow_7Rows_4, Sprite* An_1_inRow_7Rows_5, Sprite* An_1_inRow_7Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 304);
		An_1_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 304);
		An_1_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 304);
		An_1_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 304);
		An_1_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 304);
		An_1_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 304);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_1_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_1_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_1_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_1_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_1_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	int time_ff_1InRow_7Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_7Rows >= 0 && time_ff_1InRow_7Rows < 16) win.draw(*An_1_inRow_7Rows_1);
	else if (time_ff_1InRow_7Rows >= 16 && time_ff_1InRow_7Rows < 32) win.draw(*An_1_inRow_7Rows_2);
	else if (time_ff_1InRow_7Rows >= 32 && time_ff_1InRow_7Rows < 48) win.draw(*An_1_inRow_7Rows_3);
	else if (time_ff_1InRow_7Rows >= 48 && time_ff_1InRow_7Rows < 64) win.draw(*An_1_inRow_7Rows_4);
	else if (time_ff_1InRow_7Rows >= 64 && time_ff_1InRow_7Rows < 80) 
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_7Rows_5);
	}
	else if (time_ff_1InRow_7Rows >= 80 && time_ff_1InRow_7Rows < 96) win.draw(*An_1_inRow_7Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_7Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_8RowsFn(RenderWindow& win, Sprite* An_1_inRow_8Rows_1, Sprite* An_1_inRow_8Rows_2, Sprite* An_1_inRow_8Rows_3, Sprite* An_1_inRow_8Rows_4, Sprite* An_1_inRow_8Rows_5, Sprite* An_1_inRow_8Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 342);
		An_1_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 342);
		An_1_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 342);
		An_1_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 342);
		An_1_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 342);
		An_1_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 342);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_1_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_1_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_1_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_1_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_1_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	int time_ff_1InRow_8Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_8Rows >= 0 && time_ff_1InRow_8Rows < 16) win.draw(*An_1_inRow_8Rows_1);
	else if (time_ff_1InRow_8Rows >= 16 && time_ff_1InRow_8Rows < 32) win.draw(*An_1_inRow_8Rows_2);
	else if (time_ff_1InRow_8Rows >= 32 && time_ff_1InRow_8Rows < 48) win.draw(*An_1_inRow_8Rows_3);
	else if (time_ff_1InRow_8Rows >= 48 && time_ff_1InRow_8Rows < 64) win.draw(*An_1_inRow_8Rows_4);
	else if (time_ff_1InRow_8Rows >= 64 && time_ff_1InRow_8Rows < 80)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_1_inRow_8Rows_5);
	}
	else if (time_ff_1InRow_8Rows >= 80 && time_ff_1InRow_8Rows < 96) win.draw(*An_1_inRow_8Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_8Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_9RowsFn(RenderWindow& win, Sprite* An_1_inRow_9Rows_1, Sprite* An_1_inRow_9Rows_2, Sprite* An_1_inRow_9Rows_3, Sprite* An_1_inRow_9Rows_4, Sprite* An_1_inRow_9Rows_5, Sprite* An_1_inRow_9Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 380);
		An_1_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 380);
		An_1_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 380);
		An_1_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 380);
		An_1_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 380);
		An_1_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 380);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_1_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_1_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_1_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_1_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_1_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	int time_ff_1InRow_9Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_9Rows >= 0 && time_ff_1InRow_9Rows < 16) win.draw(*An_1_inRow_9Rows_1);
	else if (time_ff_1InRow_9Rows >= 16 && time_ff_1InRow_9Rows < 32) win.draw(*An_1_inRow_9Rows_2);
	else if (time_ff_1InRow_9Rows >= 32 && time_ff_1InRow_9Rows < 48) win.draw(*An_1_inRow_9Rows_3);
	else if (time_ff_1InRow_9Rows >= 48 && time_ff_1InRow_9Rows < 64) win.draw(*An_1_inRow_9Rows_4);
	else if (time_ff_1InRow_9Rows >= 64 && time_ff_1InRow_9Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_9Rows_5);
	}
	else if (time_ff_1InRow_9Rows >= 80 && time_ff_1InRow_9Rows < 96) win.draw(*An_1_inRow_9Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_9Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_10RowsFn(RenderWindow& win, Sprite* An_1_inRow_10Rows_1, Sprite* An_1_inRow_10Rows_2, Sprite* An_1_inRow_10Rows_3, Sprite* An_1_inRow_10Rows_4, Sprite* An_1_inRow_10Rows_5, Sprite* An_1_inRow_10Rows_6, Sprite* An_1_inRow_10Rows_7, Sprite* An_1_inRow_10Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
		An_1_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 418);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_1_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	int time_ff_1InRow_10Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_10Rows >= 0 && time_ff_1InRow_10Rows < 16) win.draw(*An_1_inRow_10Rows_1);
	else if (time_ff_1InRow_10Rows >= 16 && time_ff_1InRow_10Rows < 32) win.draw(*An_1_inRow_10Rows_2);
	else if (time_ff_1InRow_10Rows >= 32 && time_ff_1InRow_10Rows < 48) win.draw(*An_1_inRow_10Rows_3);
	else if (time_ff_1InRow_10Rows >= 48 && time_ff_1InRow_10Rows < 64) win.draw(*An_1_inRow_10Rows_4);
	else if (time_ff_1InRow_10Rows >= 64 && time_ff_1InRow_10Rows < 80) win.draw(*An_1_inRow_10Rows_5);
	else if (time_ff_1InRow_10Rows >= 80 && time_ff_1InRow_10Rows < 96) win.draw(*An_1_inRow_10Rows_6);
	else if (time_ff_1InRow_10Rows >= 96 && time_ff_1InRow_10Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_10Rows_7);
	}
	else if (time_ff_1InRow_10Rows >= 112 && time_ff_1InRow_10Rows < 128) win.draw(*An_1_inRow_10Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_10Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_11RowsFn(RenderWindow& win, Sprite* An_1_inRow_11Rows_1, Sprite* An_1_inRow_11Rows_2, Sprite* An_1_inRow_11Rows_3, Sprite* An_1_inRow_11Rows_4, Sprite* An_1_inRow_11Rows_5, Sprite* An_1_inRow_11Rows_6, Sprite* An_1_inRow_11Rows_7, Sprite* An_1_inRow_11Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
		An_1_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 456);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_1_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	int time_ff_1InRow_11Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_11Rows >= 0 && time_ff_1InRow_11Rows < 16) win.draw(*An_1_inRow_11Rows_1);
	else if (time_ff_1InRow_11Rows >= 16 && time_ff_1InRow_11Rows < 32) win.draw(*An_1_inRow_11Rows_2);
	else if (time_ff_1InRow_11Rows >= 32 && time_ff_1InRow_11Rows < 48) win.draw(*An_1_inRow_11Rows_3);
	else if (time_ff_1InRow_11Rows >= 48 && time_ff_1InRow_11Rows < 64) win.draw(*An_1_inRow_11Rows_4);
	else if (time_ff_1InRow_11Rows >= 64 && time_ff_1InRow_11Rows < 80) win.draw(*An_1_inRow_11Rows_5);
	else if (time_ff_1InRow_11Rows >= 80 && time_ff_1InRow_11Rows < 96) win.draw(*An_1_inRow_11Rows_6);
	else if (time_ff_1InRow_11Rows >= 96 && time_ff_1InRow_11Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_11Rows_7);
	}
	else if (time_ff_1InRow_11Rows >= 112 && time_ff_1InRow_11Rows < 128) win.draw(*An_1_inRow_11Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_11Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_12RowsFn(RenderWindow& win, Sprite* An_1_inRow_12Rows_1, Sprite* An_1_inRow_12Rows_2, Sprite* An_1_inRow_12Rows_3, Sprite* An_1_inRow_12Rows_4, Sprite* An_1_inRow_12Rows_5, Sprite* An_1_inRow_12Rows_6, Sprite* An_1_inRow_12Rows_7, Sprite* An_1_inRow_12Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
		An_1_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 494);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_1_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	int time_ff_1InRow_12Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_12Rows >= 0 && time_ff_1InRow_12Rows < 16) win.draw(*An_1_inRow_12Rows_1);
	else if (time_ff_1InRow_12Rows >= 16 && time_ff_1InRow_12Rows < 32) win.draw(*An_1_inRow_12Rows_2);
	else if (time_ff_1InRow_12Rows >= 32 && time_ff_1InRow_12Rows < 48) win.draw(*An_1_inRow_12Rows_3);
	else if (time_ff_1InRow_12Rows >= 48 && time_ff_1InRow_12Rows < 64) win.draw(*An_1_inRow_12Rows_4);
	else if (time_ff_1InRow_12Rows >= 64 && time_ff_1InRow_12Rows < 80) win.draw(*An_1_inRow_12Rows_5);
	else if (time_ff_1InRow_12Rows >= 80 && time_ff_1InRow_12Rows < 96) win.draw(*An_1_inRow_12Rows_6);
	else if (time_ff_1InRow_12Rows >= 96 && time_ff_1InRow_12Rows < 112)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_1_inRow_12Rows_7);
	}
	else if (time_ff_1InRow_12Rows >= 112 && time_ff_1InRow_12Rows < 128) win.draw(*An_1_inRow_12Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_12Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_13RowsFn(RenderWindow& win, Sprite* An_1_inRow_13Rows_1, Sprite* An_1_inRow_13Rows_2, Sprite* An_1_inRow_13Rows_3, Sprite* An_1_inRow_13Rows_4, Sprite* An_1_inRow_13Rows_5, Sprite* An_1_inRow_13Rows_6, Sprite* An_1_inRow_13Rows_7, Sprite* An_1_inRow_13Rows_8, Sprite* An_1_inRow_13Rows_9, Sprite* An_1_inRow_13Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
		An_1_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 532);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_1_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	int time_ff_1InRow_13Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_13Rows >= 0 && time_ff_1InRow_13Rows < 16) win.draw(*An_1_inRow_13Rows_1);
	else if (time_ff_1InRow_13Rows >= 16 && time_ff_1InRow_13Rows < 32) win.draw(*An_1_inRow_13Rows_2);
	else if (time_ff_1InRow_13Rows >= 32 && time_ff_1InRow_13Rows < 48) win.draw(*An_1_inRow_13Rows_3);
	else if (time_ff_1InRow_13Rows >= 48 && time_ff_1InRow_13Rows < 64) win.draw(*An_1_inRow_13Rows_4);
	else if (time_ff_1InRow_13Rows >= 64 && time_ff_1InRow_13Rows < 80) win.draw(*An_1_inRow_13Rows_5);
	else if (time_ff_1InRow_13Rows >= 80 && time_ff_1InRow_13Rows < 96) win.draw(*An_1_inRow_13Rows_6);
	else if (time_ff_1InRow_13Rows >= 96 && time_ff_1InRow_13Rows < 112) win.draw(*An_1_inRow_13Rows_7);
	else if (time_ff_1InRow_13Rows >= 112 && time_ff_1InRow_13Rows < 128) win.draw(*An_1_inRow_13Rows_8);
	else if (time_ff_1InRow_13Rows >= 128 && time_ff_1InRow_13Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_1_inRow_13Rows_9);
	}
	else if (time_ff_1InRow_13Rows >= 144 && time_ff_1InRow_13Rows < 160) win.draw(*An_1_inRow_13Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_13Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_14RowsFn(RenderWindow& win, Sprite* An_1_inRow_14Rows_1, Sprite* An_1_inRow_14Rows_2, Sprite* An_1_inRow_14Rows_3, Sprite* An_1_inRow_14Rows_4, Sprite* An_1_inRow_14Rows_5, Sprite* An_1_inRow_14Rows_6, Sprite* An_1_inRow_14Rows_7, Sprite* An_1_inRow_14Rows_8, Sprite* An_1_inRow_14Rows_9, Sprite* An_1_inRow_14Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
		An_1_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 570);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_1_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
	}

	int time_ff_1InRow_14Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_14Rows >= 0 && time_ff_1InRow_14Rows < 16) win.draw(*An_1_inRow_14Rows_1);
	else if (time_ff_1InRow_14Rows >= 16 && time_ff_1InRow_14Rows < 32) win.draw(*An_1_inRow_14Rows_2);
	else if (time_ff_1InRow_14Rows >= 32 && time_ff_1InRow_14Rows < 48) win.draw(*An_1_inRow_14Rows_3);
	else if (time_ff_1InRow_14Rows >= 48 && time_ff_1InRow_14Rows < 64) win.draw(*An_1_inRow_14Rows_4);
	else if (time_ff_1InRow_14Rows >= 64 && time_ff_1InRow_14Rows < 80) win.draw(*An_1_inRow_14Rows_5);
	else if (time_ff_1InRow_14Rows >= 80 && time_ff_1InRow_14Rows < 96) win.draw(*An_1_inRow_14Rows_6);
	else if (time_ff_1InRow_14Rows >= 96 && time_ff_1InRow_14Rows < 112) win.draw(*An_1_inRow_14Rows_7);
	else if (time_ff_1InRow_14Rows >= 112 && time_ff_1InRow_14Rows < 128) win.draw(*An_1_inRow_14Rows_8);
	else if (time_ff_1InRow_14Rows >= 128 && time_ff_1InRow_14Rows < 144)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_14Rows_9);
	}
	else if (time_ff_1InRow_14Rows >= 144 && time_ff_1InRow_14Rows < 160) win.draw(*An_1_inRow_14Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_14Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_15RowsFn(RenderWindow& win, Sprite* An_1_inRow_15Rows_1, Sprite* An_1_inRow_15Rows_2, Sprite* An_1_inRow_15Rows_3, Sprite* An_1_inRow_15Rows_4, Sprite* An_1_inRow_15Rows_5, Sprite* An_1_inRow_15Rows_6, Sprite* An_1_inRow_15Rows_7, Sprite* An_1_inRow_15Rows_8, Sprite* An_1_inRow_15Rows_9, Sprite* An_1_inRow_15Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
		An_1_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 608);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_1_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
	}

	int time_ff_1InRow_15Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_15Rows >= 0 && time_ff_1InRow_15Rows < 16) win.draw(*An_1_inRow_15Rows_1);
	else if (time_ff_1InRow_15Rows >= 16 && time_ff_1InRow_15Rows < 32) win.draw(*An_1_inRow_15Rows_2);
	else if (time_ff_1InRow_15Rows >= 32 && time_ff_1InRow_15Rows < 48) win.draw(*An_1_inRow_15Rows_3);
	else if (time_ff_1InRow_15Rows >= 48 && time_ff_1InRow_15Rows < 64) win.draw(*An_1_inRow_15Rows_4);
	else if (time_ff_1InRow_15Rows >= 64 && time_ff_1InRow_15Rows < 80) win.draw(*An_1_inRow_15Rows_5);
	else if (time_ff_1InRow_15Rows >= 80 && time_ff_1InRow_15Rows < 96) win.draw(*An_1_inRow_15Rows_6);
	else if (time_ff_1InRow_15Rows >= 96 && time_ff_1InRow_15Rows < 112) win.draw(*An_1_inRow_15Rows_7);
	else if (time_ff_1InRow_15Rows >= 112 && time_ff_1InRow_15Rows < 128) win.draw(*An_1_inRow_15Rows_8);
	else if (time_ff_1InRow_15Rows >= 128 && time_ff_1InRow_15Rows < 144)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_15Rows_9);
	}
	else if (time_ff_1InRow_15Rows >= 144 && time_ff_1InRow_15Rows < 160) win.draw(*An_1_inRow_15Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_15Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_16RowsFn(RenderWindow& win, Sprite* An_1_inRow_16Rows_1, Sprite* An_1_inRow_16Rows_2, Sprite* An_1_inRow_16Rows_3, Sprite* An_1_inRow_16Rows_4, Sprite* An_1_inRow_16Rows_5, Sprite* An_1_inRow_16Rows_6, Sprite* An_1_inRow_16Rows_7, Sprite* An_1_inRow_16Rows_8, Sprite* An_1_inRow_16Rows_9, Sprite* An_1_inRow_16Rows_10, Sprite* An_1_inRow_16Rows_11, Sprite* An_1_inRow_16Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
		An_1_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 646);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_1_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 20);
	}

	int time_ff_1InRow_16Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_16Rows >= 0 && time_ff_1InRow_16Rows < 16) win.draw(*An_1_inRow_16Rows_1);
	else if (time_ff_1InRow_16Rows >= 16 && time_ff_1InRow_16Rows < 32) win.draw(*An_1_inRow_16Rows_2);
	else if (time_ff_1InRow_16Rows >= 32 && time_ff_1InRow_16Rows < 48) win.draw(*An_1_inRow_16Rows_3);
	else if (time_ff_1InRow_16Rows >= 48 && time_ff_1InRow_16Rows < 64) win.draw(*An_1_inRow_16Rows_4);
	else if (time_ff_1InRow_16Rows >= 64 && time_ff_1InRow_16Rows < 80) win.draw(*An_1_inRow_16Rows_5);
	else if (time_ff_1InRow_16Rows >= 80 && time_ff_1InRow_16Rows < 96) win.draw(*An_1_inRow_16Rows_6);
	else if (time_ff_1InRow_16Rows >= 96 && time_ff_1InRow_16Rows < 112) win.draw(*An_1_inRow_16Rows_7);
	else if (time_ff_1InRow_16Rows >= 112 && time_ff_1InRow_16Rows < 128) win.draw(*An_1_inRow_16Rows_8);
	else if (time_ff_1InRow_16Rows >= 128 && time_ff_1InRow_16Rows < 144) win.draw(*An_1_inRow_16Rows_9);
	else if (time_ff_1InRow_16Rows >= 144 && time_ff_1InRow_16Rows < 160)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_16Rows_10);
	}
	else if (time_ff_1InRow_16Rows >= 160 && time_ff_1InRow_16Rows < 176) win.draw(*An_1_inRow_16Rows_11);
	else if (time_ff_1InRow_16Rows >= 176 && time_ff_1InRow_16Rows < 192) win.draw(*An_1_inRow_16Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_16Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_1InRow_17RowsFn(RenderWindow& win, Sprite* An_1_inRow_17Rows_1, Sprite* An_1_inRow_17Rows_2, Sprite* An_1_inRow_17Rows_3, Sprite* An_1_inRow_17Rows_4, Sprite* An_1_inRow_17Rows_5, Sprite* An_1_inRow_17Rows_6, Sprite* An_1_inRow_17Rows_7, Sprite* An_1_inRow_17Rows_8, Sprite* An_1_inRow_17Rows_9, Sprite* An_1_inRow_17Rows_10, Sprite* An_1_inRow_17Rows_11, Sprite* An_1_inRow_17Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
		An_1_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 684);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_1_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 21);
	}

	int time_ff_1InRow_17Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_1InRow_17Rows >= 0 && time_ff_1InRow_17Rows < 16) win.draw(*An_1_inRow_17Rows_1);
	else if (time_ff_1InRow_17Rows >= 16 && time_ff_1InRow_17Rows < 32) win.draw(*An_1_inRow_17Rows_2);
	else if (time_ff_1InRow_17Rows >= 32 && time_ff_1InRow_17Rows < 48) win.draw(*An_1_inRow_17Rows_3);
	else if (time_ff_1InRow_17Rows >= 48 && time_ff_1InRow_17Rows < 64) win.draw(*An_1_inRow_17Rows_4);
	else if (time_ff_1InRow_17Rows >= 64 && time_ff_1InRow_17Rows < 80) win.draw(*An_1_inRow_17Rows_5);
	else if (time_ff_1InRow_17Rows >= 80 && time_ff_1InRow_17Rows < 96) win.draw(*An_1_inRow_17Rows_6);
	else if (time_ff_1InRow_17Rows >= 96 && time_ff_1InRow_17Rows < 112) win.draw(*An_1_inRow_17Rows_7);
	else if (time_ff_1InRow_17Rows >= 112 && time_ff_1InRow_17Rows < 128) win.draw(*An_1_inRow_17Rows_8);
	else if (time_ff_1InRow_17Rows >= 128 && time_ff_1InRow_17Rows < 144) win.draw(*An_1_inRow_17Rows_9);
	else if (time_ff_1InRow_17Rows >= 144 && time_ff_1InRow_17Rows < 160)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_1_inRow_17Rows_10);
		
	}
	else if (time_ff_1InRow_17Rows >= 160 && time_ff_1InRow_17Rows < 176) win.draw(*An_1_inRow_17Rows_11);
	else if (time_ff_1InRow_17Rows >= 176 && time_ff_1InRow_17Rows < 192) win.draw(*An_1_inRow_17Rows_12);
	else  
	{ 
		afterAnimationFF = true;
 		check_space = false;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_1InRow_17Rows = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_1RowFn(RenderWindow& win, Sprite* An_2_inRow_1Row_1, Sprite* An_2_inRow_1Row_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 2);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 2);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 , a[0].y * 38 + 219 - 940 + 38 * 2);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 , a[0].y * 38 + 219 - 940 + 38 * 2);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38*4);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38*4);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 2);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 2);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 3);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 3);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
	An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 1);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 1);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
	}

	int time_ff_2InRow_1Row = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2InRow_1Row >= 0 && time_ff_2InRow_1Row < 16) win.draw(*An_2_inRow_1Row_1);
	else if (time_ff_2InRow_1Row >= 16 && time_ff_2InRow_1Row < 32) win.draw(*An_2_inRow_1Row_2);
	else if (time_ff_2InRow_1Row >= 32 && time_ff_2InRow_1Row < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_1Row = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_2RowsFn(RenderWindow& win, Sprite* An_2_inRow_2Rows_1, Sprite* An_2_inRow_2Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 3);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 3);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 2);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 2);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	int time_ff_2_inRow_2Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_2Rows >= 0 && time_ff_2_inRow_2Rows < 16) win.draw(*An_2_inRow_2Rows_1);
	else if (time_ff_2_inRow_2Rows >= 16 && time_ff_2_inRow_2Rows < 32) win.draw(*An_2_inRow_2Rows_2);
	else if (time_ff_2_inRow_2Rows >= 32 && time_ff_2_inRow_2Rows < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_2Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_3RowsFn(RenderWindow& win, Sprite* An_2_inRow_3Rows_1, Sprite* An_2_inRow_3Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 4);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 3);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	int time_ff_2_inRow_3Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_3Rows >= 0 && time_ff_2_inRow_3Rows < 16) win.draw(*An_2_inRow_3Rows_1);
	else if (time_ff_2_inRow_3Rows >= 16 && time_ff_2_inRow_3Rows < 32) win.draw(*An_2_inRow_3Rows_2);
	else if (time_ff_2_inRow_3Rows >= 32 && time_ff_2_inRow_3Rows < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_3Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_4RowsFn(RenderWindow& win, Sprite* An_2_inRow_4Rows_1, Sprite* An_2_inRow_4Rows_2, Sprite* An_2_inRow_4Rows_3, Sprite* An_2_inRow_4Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 5);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 4);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
	}

	int time_ff_2_inRow_4Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_4Rows >= 0 && time_ff_2_inRow_4Rows < 16) win.draw(*An_2_inRow_4Rows_1);
	else if (time_ff_2_inRow_4Rows >= 16 && time_ff_2_inRow_4Rows < 32) win.draw(*An_2_inRow_4Rows_2);
	else if (time_ff_2_inRow_4Rows >= 32 && time_ff_2_inRow_4Rows < 48) win.draw(*An_2_inRow_4Rows_3);
	else if (time_ff_2_inRow_4Rows >= 48 && time_ff_2_inRow_4Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_4Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_4Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_5RowsFn(RenderWindow& win, Sprite* An_2_inRow_5Rows_1, Sprite* An_2_inRow_5Rows_2, Sprite* An_2_inRow_5Rows_3, Sprite* An_2_inRow_5Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 6);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 5);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	int time_ff_2_inRow_5Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_5Rows >= 0 && time_ff_2_inRow_5Rows < 16) win.draw(*An_2_inRow_5Rows_1);
	else if (time_ff_2_inRow_5Rows >= 16 && time_ff_2_inRow_5Rows < 32) win.draw(*An_2_inRow_5Rows_2);
	else if (time_ff_2_inRow_5Rows >= 32 && time_ff_2_inRow_5Rows < 48) win.draw(*An_2_inRow_5Rows_3);
	else if (time_ff_2_inRow_5Rows >= 48 && time_ff_2_inRow_5Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_5Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_5Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_6RowsFn(RenderWindow& win, Sprite* An_2_inRow_6Rows_1, Sprite* An_2_inRow_6Rows_2, Sprite* An_2_inRow_6Rows_3, Sprite* An_2_inRow_6Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 7);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 6);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	int time_ff_2_inRow_6Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_6Rows >= 0 && time_ff_2_inRow_6Rows < 16) win.draw(*An_2_inRow_6Rows_1);
	else if (time_ff_2_inRow_6Rows >= 16 && time_ff_2_inRow_6Rows < 32) win.draw(*An_2_inRow_6Rows_2);
	else if (time_ff_2_inRow_6Rows >= 32 && time_ff_2_inRow_6Rows < 48) win.draw(*An_2_inRow_6Rows_3);
	else if (time_ff_2_inRow_6Rows >= 48 && time_ff_2_inRow_6Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_6Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_6Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_7RowsFn(RenderWindow& win, Sprite* An_2_inRow_7Rows_1, Sprite* An_2_inRow_7Rows_2, Sprite* An_2_inRow_7Rows_3, Sprite* An_2_inRow_7Rows_4, Sprite* An_2_inRow_7Rows_5, Sprite* An_2_inRow_7Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 8);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 7);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	int time_ff_2_inRow_7Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_7Rows >= 0 && time_ff_2_inRow_7Rows < 16) win.draw(*An_2_inRow_7Rows_1);
	else if (time_ff_2_inRow_7Rows >= 16 && time_ff_2_inRow_7Rows < 32) win.draw(*An_2_inRow_7Rows_2);
	else if (time_ff_2_inRow_7Rows >= 32 && time_ff_2_inRow_7Rows < 48) win.draw(*An_2_inRow_7Rows_3);
	else if (time_ff_2_inRow_7Rows >= 48 && time_ff_2_inRow_7Rows < 64) win.draw(*An_2_inRow_7Rows_4);
	else if (time_ff_2_inRow_7Rows >= 64 && time_ff_2_inRow_7Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_7Rows_5);
	}
	else if (time_ff_2_inRow_7Rows >= 80 && time_ff_2_inRow_7Rows < 96) win.draw(*An_2_inRow_7Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_7Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_8RowsFn(RenderWindow& win, Sprite* An_2_inRow_8Rows_1, Sprite* An_2_inRow_8Rows_2, Sprite* An_2_inRow_8Rows_3, Sprite* An_2_inRow_8Rows_4, Sprite* An_2_inRow_8Rows_5, Sprite* An_2_inRow_8Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 9);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 8);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	int time_ff_2_inRow_8Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_8Rows >= 0 && time_ff_2_inRow_8Rows < 16) win.draw(*An_2_inRow_8Rows_1);
	else if (time_ff_2_inRow_8Rows >= 16 && time_ff_2_inRow_8Rows < 32) win.draw(*An_2_inRow_8Rows_2);
	else if (time_ff_2_inRow_8Rows >= 32 && time_ff_2_inRow_8Rows < 48) win.draw(*An_2_inRow_8Rows_3);
	else if (time_ff_2_inRow_8Rows >= 48 && time_ff_2_inRow_8Rows < 64) win.draw(*An_2_inRow_8Rows_4);
	else if (time_ff_2_inRow_8Rows >= 64 && time_ff_2_inRow_8Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_8Rows_5);
	}
	else if (time_ff_2_inRow_8Rows >= 80 && time_ff_2_inRow_8Rows < 96) win.draw(*An_2_inRow_8Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_8Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_9RowsFn(RenderWindow& win, Sprite* An_2_inRow_9Rows_1, Sprite* An_2_inRow_9Rows_2, Sprite* An_2_inRow_9Rows_3, Sprite* An_2_inRow_9Rows_4, Sprite* An_2_inRow_9Rows_5, Sprite* An_2_inRow_9Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 10);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 9);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	int time_ff_2_inRow_9Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_9Rows >= 0 && time_ff_2_inRow_9Rows < 16) win.draw(*An_2_inRow_9Rows_1);
	else if (time_ff_2_inRow_9Rows >= 16 && time_ff_2_inRow_9Rows < 32) win.draw(*An_2_inRow_9Rows_2);
	else if (time_ff_2_inRow_9Rows >= 32 && time_ff_2_inRow_9Rows < 48) win.draw(*An_2_inRow_9Rows_3);
	else if (time_ff_2_inRow_9Rows >= 48 && time_ff_2_inRow_9Rows < 64) win.draw(*An_2_inRow_9Rows_4);
	else if (time_ff_2_inRow_9Rows >= 64 && time_ff_2_inRow_9Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_9Rows_5);
	}
	else if (time_ff_2_inRow_9Rows >= 80 && time_ff_2_inRow_9Rows < 96) win.draw(*An_2_inRow_9Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_9Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_10RowsFn(RenderWindow& win, Sprite* An_2_inRow_10Rows_1, Sprite* An_2_inRow_10Rows_2, Sprite* An_2_inRow_10Rows_3, Sprite* An_2_inRow_10Rows_4, Sprite* An_2_inRow_10Rows_5, Sprite* An_2_inRow_10Rows_6, Sprite* An_2_inRow_10Rows_7, Sprite* An_2_inRow_10Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 11);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 10);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	int time_ff_2_inRow_10Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_10Rows >= 0 && time_ff_2_inRow_10Rows < 16) win.draw(*An_2_inRow_10Rows_1);
	else if (time_ff_2_inRow_10Rows >= 16 && time_ff_2_inRow_10Rows < 32) win.draw(*An_2_inRow_10Rows_2);
	else if (time_ff_2_inRow_10Rows >= 32 && time_ff_2_inRow_10Rows < 48) win.draw(*An_2_inRow_10Rows_3);
	else if (time_ff_2_inRow_10Rows >= 48 && time_ff_2_inRow_10Rows < 64) win.draw(*An_2_inRow_10Rows_4);
	else if (time_ff_2_inRow_10Rows >= 64 && time_ff_2_inRow_10Rows < 80) win.draw(*An_2_inRow_10Rows_5);
	else if (time_ff_2_inRow_10Rows >= 80 && time_ff_2_inRow_10Rows < 96) win.draw(*An_2_inRow_10Rows_6);
	else if (time_ff_2_inRow_10Rows >= 96 && time_ff_2_inRow_10Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_10Rows_7);
	}
	else if (time_ff_2_inRow_10Rows >= 112 && time_ff_2_inRow_10Rows < 128) win.draw(*An_2_inRow_10Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_10Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_11RowsFn(RenderWindow& win, Sprite* An_2_inRow_11Rows_1, Sprite* An_2_inRow_11Rows_2, Sprite* An_2_inRow_11Rows_3, Sprite* An_2_inRow_11Rows_4, Sprite* An_2_inRow_11Rows_5, Sprite* An_2_inRow_11Rows_6, Sprite* An_2_inRow_11Rows_7, Sprite* An_2_inRow_11Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 12);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 11);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	int time_ff_2_inRow_11Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_11Rows >= 0 && time_ff_2_inRow_11Rows < 16) win.draw(*An_2_inRow_11Rows_1);
	else if (time_ff_2_inRow_11Rows >= 16 && time_ff_2_inRow_11Rows < 32) win.draw(*An_2_inRow_11Rows_2);
	else if (time_ff_2_inRow_11Rows >= 32 && time_ff_2_inRow_11Rows < 48) win.draw(*An_2_inRow_11Rows_3);
	else if (time_ff_2_inRow_11Rows >= 48 && time_ff_2_inRow_11Rows < 64) win.draw(*An_2_inRow_11Rows_4);
	else if (time_ff_2_inRow_11Rows >= 64 && time_ff_2_inRow_11Rows < 80) win.draw(*An_2_inRow_11Rows_5);
	else if (time_ff_2_inRow_11Rows >= 80 && time_ff_2_inRow_11Rows < 96) win.draw(*An_2_inRow_11Rows_6);
	else if (time_ff_2_inRow_11Rows >= 96 && time_ff_2_inRow_11Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_11Rows_7);
	}
	else if (time_ff_2_inRow_11Rows >= 112 && time_ff_2_inRow_11Rows < 128) win.draw(*An_2_inRow_11Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_11Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_12RowsFn(RenderWindow& win, Sprite* An_2_inRow_12Rows_1, Sprite* An_2_inRow_12Rows_2, Sprite* An_2_inRow_12Rows_3, Sprite* An_2_inRow_12Rows_4, Sprite* An_2_inRow_12Rows_5, Sprite* An_2_inRow_12Rows_6, Sprite* An_2_inRow_12Rows_7, Sprite* An_2_inRow_12Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 13);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 12);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	int time_ff_2_inRow_12Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_12Rows >= 0 && time_ff_2_inRow_12Rows < 16) win.draw(*An_2_inRow_12Rows_1);
	else if (time_ff_2_inRow_12Rows >= 16 && time_ff_2_inRow_12Rows < 32) win.draw(*An_2_inRow_12Rows_2);
	else if (time_ff_2_inRow_12Rows >= 32 && time_ff_2_inRow_12Rows < 48) win.draw(*An_2_inRow_12Rows_3);
	else if (time_ff_2_inRow_12Rows >= 48 && time_ff_2_inRow_12Rows < 64) win.draw(*An_2_inRow_12Rows_4);
	else if (time_ff_2_inRow_12Rows >= 64 && time_ff_2_inRow_12Rows < 80) win.draw(*An_2_inRow_12Rows_5);
	else if (time_ff_2_inRow_12Rows >= 80 && time_ff_2_inRow_12Rows < 96) win.draw(*An_2_inRow_12Rows_6);
	else if (time_ff_2_inRow_12Rows >= 96 && time_ff_2_inRow_12Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_12Rows_7);
	}
	else if (time_ff_2_inRow_12Rows >= 112 && time_ff_2_inRow_12Rows < 128) win.draw(*An_2_inRow_12Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_12Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_13RowsFn(RenderWindow& win, Sprite* An_2_inRow_13Rows_1, Sprite* An_2_inRow_13Rows_2, Sprite* An_2_inRow_13Rows_3, Sprite* An_2_inRow_13Rows_4, Sprite* An_2_inRow_13Rows_5, Sprite* An_2_inRow_13Rows_6, Sprite* An_2_inRow_13Rows_7, Sprite* An_2_inRow_13Rows_8, Sprite* An_2_inRow_13Rows_9, Sprite* An_2_inRow_13Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 14);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 13);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	int time_ff_2_inRow_13Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_13Rows >= 0 && time_ff_2_inRow_13Rows < 16) win.draw(*An_2_inRow_13Rows_1);
	else if (time_ff_2_inRow_13Rows >= 16 && time_ff_2_inRow_13Rows < 32) win.draw(*An_2_inRow_13Rows_2);
	else if (time_ff_2_inRow_13Rows >= 32 && time_ff_2_inRow_13Rows < 48) win.draw(*An_2_inRow_13Rows_3);
	else if (time_ff_2_inRow_13Rows >= 48 && time_ff_2_inRow_13Rows < 64) win.draw(*An_2_inRow_13Rows_4);
	else if (time_ff_2_inRow_13Rows >= 64 && time_ff_2_inRow_13Rows < 80) win.draw(*An_2_inRow_13Rows_5);
	else if (time_ff_2_inRow_13Rows >= 80 && time_ff_2_inRow_13Rows < 96) win.draw(*An_2_inRow_13Rows_6);
	else if (time_ff_2_inRow_13Rows >= 96 && time_ff_2_inRow_13Rows < 112) win.draw(*An_2_inRow_13Rows_7);
	else if (time_ff_2_inRow_13Rows >= 112 && time_ff_2_inRow_13Rows < 128) win.draw(*An_2_inRow_13Rows_8);
	else if (time_ff_2_inRow_13Rows >= 128 && time_ff_2_inRow_13Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_2_inRow_13Rows_9);
	}
	else if (time_ff_2_inRow_13Rows >= 144 && time_ff_2_inRow_13Rows < 160) win.draw(*An_2_inRow_13Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_13Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_14RowsFn(RenderWindow& win, Sprite* An_2_inRow_14Rows_1, Sprite* An_2_inRow_14Rows_2, Sprite* An_2_inRow_14Rows_3, Sprite* An_2_inRow_14Rows_4, Sprite* An_2_inRow_14Rows_5, Sprite* An_2_inRow_14Rows_6, Sprite* An_2_inRow_14Rows_7, Sprite* An_2_inRow_14Rows_8, Sprite* An_2_inRow_14Rows_9, Sprite* An_2_inRow_14Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 15);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 14);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	int time_ff_2_inRow_14Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_14Rows >= 0 && time_ff_2_inRow_14Rows < 16) win.draw(*An_2_inRow_14Rows_1);
	else if (time_ff_2_inRow_14Rows >= 16 && time_ff_2_inRow_14Rows < 32) win.draw(*An_2_inRow_14Rows_2);
	else if (time_ff_2_inRow_14Rows >= 32 && time_ff_2_inRow_14Rows < 48) win.draw(*An_2_inRow_14Rows_3);
	else if (time_ff_2_inRow_14Rows >= 48 && time_ff_2_inRow_14Rows < 64) win.draw(*An_2_inRow_14Rows_4);
	else if (time_ff_2_inRow_14Rows >= 64 && time_ff_2_inRow_14Rows < 80) win.draw(*An_2_inRow_14Rows_5);
	else if (time_ff_2_inRow_14Rows >= 80 && time_ff_2_inRow_14Rows < 96) win.draw(*An_2_inRow_14Rows_6);
	else if (time_ff_2_inRow_14Rows >= 96 && time_ff_2_inRow_14Rows < 112) win.draw(*An_2_inRow_14Rows_7);
	else if (time_ff_2_inRow_14Rows >= 112 && time_ff_2_inRow_14Rows < 128) win.draw(*An_2_inRow_14Rows_8);
	else if (time_ff_2_inRow_14Rows >= 128 && time_ff_2_inRow_14Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_2_inRow_14Rows_9);
	}
	else if (time_ff_2_inRow_14Rows >= 144 && time_ff_2_inRow_14Rows < 160) win.draw(*An_2_inRow_14Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_14Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_15RowsFn(RenderWindow& win, Sprite* An_2_inRow_15Rows_1, Sprite* An_2_inRow_15Rows_2, Sprite* An_2_inRow_15Rows_3, Sprite* An_2_inRow_15Rows_4, Sprite* An_2_inRow_15Rows_5, Sprite* An_2_inRow_15Rows_6, Sprite* An_2_inRow_15Rows_7, Sprite* An_2_inRow_15Rows_8, Sprite* An_2_inRow_15Rows_9, Sprite* An_2_inRow_15Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 16);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 15);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
	}

	int time_ff_2_inRow_15Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_15Rows >= 0 && time_ff_2_inRow_15Rows < 16) win.draw(*An_2_inRow_15Rows_1);
	else if (time_ff_2_inRow_15Rows >= 16 && time_ff_2_inRow_15Rows < 32) win.draw(*An_2_inRow_15Rows_2);
	else if (time_ff_2_inRow_15Rows >= 32 && time_ff_2_inRow_15Rows < 48) win.draw(*An_2_inRow_15Rows_3);
	else if (time_ff_2_inRow_15Rows >= 48 && time_ff_2_inRow_15Rows < 64) win.draw(*An_2_inRow_15Rows_4);
	else if (time_ff_2_inRow_15Rows >= 64 && time_ff_2_inRow_15Rows < 80) win.draw(*An_2_inRow_15Rows_5);
	else if (time_ff_2_inRow_15Rows >= 80 && time_ff_2_inRow_15Rows < 96) win.draw(*An_2_inRow_15Rows_6);
	else if (time_ff_2_inRow_15Rows >= 96 && time_ff_2_inRow_15Rows < 112) win.draw(*An_2_inRow_15Rows_7);
	else if (time_ff_2_inRow_15Rows >= 112 && time_ff_2_inRow_15Rows < 128) win.draw(*An_2_inRow_15Rows_8);
	else if (time_ff_2_inRow_15Rows >= 128 && time_ff_2_inRow_15Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_2_inRow_15Rows_9);
	}
	else if (time_ff_2_inRow_15Rows >= 144 && time_ff_2_inRow_15Rows < 160) win.draw(*An_2_inRow_15Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_15Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_16RowsFn(RenderWindow& win, Sprite* An_2_inRow_16Rows_1, Sprite* An_2_inRow_16Rows_2, Sprite* An_2_inRow_16Rows_3, Sprite* An_2_inRow_16Rows_4, Sprite* An_2_inRow_16Rows_5, Sprite* An_2_inRow_16Rows_6, Sprite* An_2_inRow_16Rows_7, Sprite* An_2_inRow_16Rows_8, Sprite* An_2_inRow_16Rows_9, Sprite* An_2_inRow_16Rows_10, Sprite* An_2_inRow_16Rows_11, Sprite* An_2_inRow_16Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 17);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 18);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 16);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
	}

	int time_ff_2_inRow_16Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_16Rows >= 0 && time_ff_2_inRow_16Rows < 16) win.draw(*An_2_inRow_16Rows_1);
	else if (time_ff_2_inRow_16Rows >= 16 && time_ff_2_inRow_16Rows < 32) win.draw(*An_2_inRow_16Rows_2);
	else if (time_ff_2_inRow_16Rows >= 32 && time_ff_2_inRow_16Rows < 48) win.draw(*An_2_inRow_16Rows_3);
	else if (time_ff_2_inRow_16Rows >= 48 && time_ff_2_inRow_16Rows < 64) win.draw(*An_2_inRow_16Rows_4);
	else if (time_ff_2_inRow_16Rows >= 64 && time_ff_2_inRow_16Rows < 80) win.draw(*An_2_inRow_16Rows_5);
	else if (time_ff_2_inRow_16Rows >= 80 && time_ff_2_inRow_16Rows < 96) win.draw(*An_2_inRow_16Rows_6);
	else if (time_ff_2_inRow_16Rows >= 96 && time_ff_2_inRow_16Rows < 112) win.draw(*An_2_inRow_16Rows_7);
	else if (time_ff_2_inRow_16Rows >= 112 && time_ff_2_inRow_16Rows < 128) win.draw(*An_2_inRow_16Rows_8);
	else if (time_ff_2_inRow_16Rows >= 128 && time_ff_2_inRow_16Rows < 144) win.draw(*An_2_inRow_16Rows_9);
	else if (time_ff_2_inRow_16Rows >= 144 && time_ff_2_inRow_16Rows < 160)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_16Rows_10);
	}
	else if (time_ff_2_inRow_16Rows >= 160 && time_ff_2_inRow_16Rows < 176) win.draw(*An_2_inRow_16Rows_11);
	else if (time_ff_2_inRow_16Rows >= 176 && time_ff_2_inRow_16Rows < 192) win.draw(*An_2_inRow_16Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_16Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_2InRow_17RowsFn(RenderWindow& win, Sprite* An_2_inRow_17Rows_1, Sprite* An_2_inRow_17Rows_2, Sprite* An_2_inRow_17Rows_3, Sprite* An_2_inRow_17Rows_4, Sprite* An_2_inRow_17Rows_5, Sprite* An_2_inRow_17Rows_6, Sprite* An_2_inRow_17Rows_7, Sprite* An_2_inRow_17Rows_8, Sprite* An_2_inRow_17Rows_9, Sprite* An_2_inRow_17Rows_10, Sprite* An_2_inRow_17Rows_11, Sprite* An_2_inRow_17Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
		An_2_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 20);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
		An_2_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 18);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 19);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
		An_2_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 19);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
		An_2_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922 - 38, a[0].y * 38 + 219 - 940 + 38 * 21);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
		An_2_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 922, a[0].y * 38 + 219 - 940 + 38 * 17);
	}

	int time_ff_2_inRow_17Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_2_inRow_17Rows >= 0 && time_ff_2_inRow_17Rows < 16) win.draw(*An_2_inRow_17Rows_1);
	else if (time_ff_2_inRow_17Rows >= 16 && time_ff_2_inRow_17Rows < 32) win.draw(*An_2_inRow_17Rows_2);
	else if (time_ff_2_inRow_17Rows >= 32 && time_ff_2_inRow_17Rows < 48) win.draw(*An_2_inRow_17Rows_3);
	else if (time_ff_2_inRow_17Rows >= 48 && time_ff_2_inRow_17Rows < 64) win.draw(*An_2_inRow_17Rows_4);
	else if (time_ff_2_inRow_17Rows >= 64 && time_ff_2_inRow_17Rows < 80) win.draw(*An_2_inRow_17Rows_5);
	else if (time_ff_2_inRow_17Rows >= 80 && time_ff_2_inRow_17Rows < 96) win.draw(*An_2_inRow_17Rows_6);
	else if (time_ff_2_inRow_17Rows >= 96 && time_ff_2_inRow_17Rows < 112) win.draw(*An_2_inRow_17Rows_7);
	else if (time_ff_2_inRow_17Rows >= 112 && time_ff_2_inRow_17Rows < 128) win.draw(*An_2_inRow_17Rows_8);
	else if (time_ff_2_inRow_17Rows >= 128 && time_ff_2_inRow_17Rows < 144) win.draw(*An_2_inRow_17Rows_9);
	else if (time_ff_2_inRow_17Rows >= 144 && time_ff_2_inRow_17Rows < 160)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_2_inRow_17Rows_10);
	}
	else if (time_ff_2_inRow_17Rows >= 160 && time_ff_2_inRow_17Rows < 176) win.draw(*An_2_inRow_17Rows_11);
	else if (time_ff_2_inRow_17Rows >= 176 && time_ff_2_inRow_17Rows < 192) win.draw(*An_2_inRow_17Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_2InRow_17Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_1RowFn(RenderWindow& win, Sprite* An_3_inRow_1Row_1, Sprite* An_3_inRow_1Row_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38*2);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);	
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38*1);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38*1);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864 + 38);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884 , a[0].y * 38 + 219 - 864);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884 , a[0].y * 38 + 219 - 864);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884 - 38*2, a[0].y * 38 + 219 - 864);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
	}

	int time_ff_3InRow_1Row = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_1Row >= 0 && time_ff_3InRow_1Row < 16) win.draw(*An_3_inRow_1Row_1);
	else if (time_ff_3InRow_1Row >= 16 && time_ff_3InRow_1Row < 32) win.draw(*An_3_inRow_1Row_2);
	else if (time_ff_3InRow_1Row >= 32 && time_ff_3InRow_1Row < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_1Row = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_2RowsFn(RenderWindow& win, Sprite* An_3_inRow_2Rows_1, Sprite* An_3_inRow_2Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 2);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 2);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38*2);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38*2);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38);
		An_3_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38);
	}

	int time_ff_3InRow_2Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_2Rows >= 0 && time_ff_3InRow_2Rows < 16) win.draw(*An_3_inRow_2Rows_1);
	else if (time_ff_3InRow_2Rows >= 16 && time_ff_3InRow_2Rows < 32) win.draw(*An_3_inRow_2Rows_2);
	else if (time_ff_3InRow_2Rows >= 32 && time_ff_3InRow_2Rows < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_2Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_3RowsFn(RenderWindow& win, Sprite* An_3_inRow_3Rows_1, Sprite* An_3_inRow_3Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38*2);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38*2);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38*2);
		An_3_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38*2);
	}

	int time_ff_3InRow_3Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_3Rows >= 0 && time_ff_3InRow_3Rows < 16) win.draw(*An_3_inRow_3Rows_1);
	else if (time_ff_3InRow_3Rows >= 16 && time_ff_3InRow_3Rows < 32) win.draw(*An_3_inRow_3Rows_2);
	else if (time_ff_3InRow_3Rows >= 32 && time_ff_3InRow_3Rows < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_3Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_4RowsFn(RenderWindow& win, Sprite* An_3_inRow_4Rows_1, Sprite* An_3_inRow_4Rows_2, Sprite* An_3_inRow_4Rows_3, Sprite* An_3_inRow_4Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 3);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 3);
		An_3_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 3);
		An_3_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 3);
		An_3_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 3);
	}

	int time_ff_3InRow_4Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_4Rows >= 0 && time_ff_3InRow_4Rows < 16) win.draw(*An_3_inRow_4Rows_1);
	else if (time_ff_3InRow_4Rows >= 16 && time_ff_3InRow_4Rows < 32) win.draw(*An_3_inRow_4Rows_2);
	else if (time_ff_3InRow_4Rows >= 32 && time_ff_3InRow_4Rows < 48) win.draw(*An_3_inRow_4Rows_3);
	else if (time_ff_3InRow_4Rows >= 48 && time_ff_3InRow_4Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_4Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_4Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_5RowsFn(RenderWindow& win, Sprite* An_3_inRow_5Rows_1, Sprite* An_3_inRow_5Rows_2, Sprite* An_3_inRow_5Rows_3, Sprite* An_3_inRow_5Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 4);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 4);
		An_3_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 4);
		An_3_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 4);
		An_3_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 4);
	}

	int time_ff_3InRow_5Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_5Rows >= 0 && time_ff_3InRow_5Rows < 16) win.draw(*An_3_inRow_5Rows_1);
	else if (time_ff_3InRow_5Rows >= 16 && time_ff_3InRow_5Rows < 32) win.draw(*An_3_inRow_5Rows_2);
	else if (time_ff_3InRow_5Rows >= 32 && time_ff_3InRow_5Rows < 48) win.draw(*An_3_inRow_5Rows_3);
	else if (time_ff_3InRow_5Rows >= 48 && time_ff_3InRow_5Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_5Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_5Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_6RowsFn(RenderWindow& win, Sprite* An_3_inRow_6Rows_1, Sprite* An_3_inRow_6Rows_2, Sprite* An_3_inRow_6Rows_3, Sprite* An_3_inRow_6Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 5);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 5);
		An_3_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 5);
		An_3_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 5);
		An_3_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 5);
	}

	int time_ff_3InRow_6Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_6Rows >= 0 && time_ff_3InRow_6Rows < 16) win.draw(*An_3_inRow_6Rows_1);
	else if (time_ff_3InRow_6Rows >= 16 && time_ff_3InRow_6Rows < 32) win.draw(*An_3_inRow_6Rows_2);
	else if (time_ff_3InRow_6Rows >= 32 && time_ff_3InRow_6Rows < 48) win.draw(*An_3_inRow_6Rows_3);
	else if (time_ff_3InRow_6Rows >= 48 && time_ff_3InRow_6Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_6Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_6Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_7RowsFn(RenderWindow& win, Sprite* An_3_inRow_7Rows_1, Sprite* An_3_inRow_7Rows_2, Sprite* An_3_inRow_7Rows_3, Sprite* An_3_inRow_7Rows_4, Sprite* An_3_inRow_7Rows_5, Sprite* An_3_inRow_7Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 6);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 6);
		An_3_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 6);
		An_3_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 6);
		An_3_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 6);
		An_3_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 6);
		An_3_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 6);
	}

	int time_ff_3InRow_7Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_7Rows >= 0 && time_ff_3InRow_7Rows < 16) win.draw(*An_3_inRow_7Rows_1);
	else if (time_ff_3InRow_7Rows >= 16 && time_ff_3InRow_7Rows < 32) win.draw(*An_3_inRow_7Rows_2);
	else if (time_ff_3InRow_7Rows >= 32 && time_ff_3InRow_7Rows < 48) win.draw(*An_3_inRow_7Rows_3);
	else if (time_ff_3InRow_7Rows >= 48 && time_ff_3InRow_7Rows < 64) win.draw(*An_3_inRow_7Rows_4);
	else if (time_ff_3InRow_7Rows >= 64 && time_ff_3InRow_7Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_7Rows_5);
	}
	else if (time_ff_3InRow_7Rows >= 80 && time_ff_3InRow_7Rows < 96) win.draw(*An_3_inRow_7Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_7Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_8RowsFn(RenderWindow& win, Sprite* An_3_inRow_8Rows_1, Sprite* An_3_inRow_8Rows_2, Sprite* An_3_inRow_8Rows_3, Sprite* An_3_inRow_8Rows_4, Sprite* An_3_inRow_8Rows_5, Sprite* An_3_inRow_8Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 7);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 7);
		An_3_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 7);
		An_3_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 7);
		An_3_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 7);
		An_3_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 7);
		An_3_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 7);
	}

	int time_ff_3InRow_8Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_8Rows >= 0 && time_ff_3InRow_8Rows < 16) win.draw(*An_3_inRow_8Rows_1);
	else if (time_ff_3InRow_8Rows >= 16 && time_ff_3InRow_8Rows < 32) win.draw(*An_3_inRow_8Rows_2);
	else if (time_ff_3InRow_8Rows >= 32 && time_ff_3InRow_8Rows < 48) win.draw(*An_3_inRow_8Rows_3);
	else if (time_ff_3InRow_8Rows >= 48 && time_ff_3InRow_8Rows < 64) win.draw(*An_3_inRow_8Rows_4);
	else if (time_ff_3InRow_8Rows >= 64 && time_ff_3InRow_8Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_8Rows_5);
	}
	else if (time_ff_3InRow_8Rows >= 80 && time_ff_3InRow_8Rows < 96) win.draw(*An_3_inRow_8Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_8Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_9RowsFn(RenderWindow& win, Sprite* An_3_inRow_9Rows_1, Sprite* An_3_inRow_9Rows_2, Sprite* An_3_inRow_9Rows_3, Sprite* An_3_inRow_9Rows_4, Sprite* An_3_inRow_9Rows_5, Sprite* An_3_inRow_9Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 8);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 8);
		An_3_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 8);
		An_3_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 8);
		An_3_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 8);
		An_3_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 8);
		An_3_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 8);
	}

	int time_ff_3InRow_9Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_9Rows >= 0 && time_ff_3InRow_9Rows < 16) win.draw(*An_3_inRow_9Rows_1);
	else if (time_ff_3InRow_9Rows >= 16 && time_ff_3InRow_9Rows < 32) win.draw(*An_3_inRow_9Rows_2);
	else if (time_ff_3InRow_9Rows >= 32 && time_ff_3InRow_9Rows < 48) win.draw(*An_3_inRow_9Rows_3);
	else if (time_ff_3InRow_9Rows >= 48 && time_ff_3InRow_9Rows < 64) win.draw(*An_3_inRow_9Rows_4);
	else if (time_ff_3InRow_9Rows >= 64 && time_ff_3InRow_9Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_9Rows_5);
	}
	else if (time_ff_3InRow_9Rows >= 80 && time_ff_3InRow_9Rows < 96) win.draw(*An_3_inRow_9Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_9Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_10RowsFn(RenderWindow& win, Sprite* An_3_inRow_10Rows_1, Sprite* An_3_inRow_10Rows_2, Sprite* An_3_inRow_10Rows_3, Sprite* An_3_inRow_10Rows_4, Sprite* An_3_inRow_10Rows_5, Sprite* An_3_inRow_10Rows_6, Sprite* An_3_inRow_10Rows_7, Sprite* An_3_inRow_10Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 9);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
		An_3_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 9);
	}

	int time_ff_3InRow_10Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_10Rows >= 0 && time_ff_3InRow_10Rows < 16) win.draw(*An_3_inRow_10Rows_1);
	else if (time_ff_3InRow_10Rows >= 16 && time_ff_3InRow_10Rows < 32) win.draw(*An_3_inRow_10Rows_2);
	else if (time_ff_3InRow_10Rows >= 32 && time_ff_3InRow_10Rows < 48) win.draw(*An_3_inRow_10Rows_3);
	else if (time_ff_3InRow_10Rows >= 48 && time_ff_3InRow_10Rows < 64) win.draw(*An_3_inRow_10Rows_4);
	else if (time_ff_3InRow_10Rows >= 64 && time_ff_3InRow_10Rows < 80) win.draw(*An_3_inRow_10Rows_5);
	else if (time_ff_3InRow_10Rows >= 80 && time_ff_3InRow_10Rows < 96) win.draw(*An_3_inRow_10Rows_6);
	else if (time_ff_3InRow_10Rows >= 96 && time_ff_3InRow_10Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_10Rows_7);
	}
	else if (time_ff_3InRow_10Rows >= 112 && time_ff_3InRow_10Rows < 128) win.draw(*An_3_inRow_10Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_10Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_11RowsFn(RenderWindow& win, Sprite* An_3_inRow_11Rows_1, Sprite* An_3_inRow_11Rows_2, Sprite* An_3_inRow_11Rows_3, Sprite* An_3_inRow_11Rows_4, Sprite* An_3_inRow_11Rows_5, Sprite* An_3_inRow_11Rows_6, Sprite* An_3_inRow_11Rows_7, Sprite* An_3_inRow_11Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 10);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
		An_3_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 10);
	}

	int time_ff_3InRow_11Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_11Rows >= 0 && time_ff_3InRow_11Rows < 16) win.draw(*An_3_inRow_11Rows_1);
	else if (time_ff_3InRow_11Rows >= 16 && time_ff_3InRow_11Rows < 32) win.draw(*An_3_inRow_11Rows_2);
	else if (time_ff_3InRow_11Rows >= 32 && time_ff_3InRow_11Rows < 48) win.draw(*An_3_inRow_11Rows_3);
	else if (time_ff_3InRow_11Rows >= 48 && time_ff_3InRow_11Rows < 64) win.draw(*An_3_inRow_11Rows_4);
	else if (time_ff_3InRow_11Rows >= 64 && time_ff_3InRow_11Rows < 80) win.draw(*An_3_inRow_11Rows_5);
	else if (time_ff_3InRow_11Rows >= 80 && time_ff_3InRow_11Rows < 96) win.draw(*An_3_inRow_11Rows_6);
	else if (time_ff_3InRow_11Rows >= 96 && time_ff_3InRow_11Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_11Rows_7);
	}
	else if (time_ff_3InRow_11Rows >= 112 && time_ff_3InRow_11Rows < 128) win.draw(*An_3_inRow_11Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_11Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_12RowsFn(RenderWindow& win, Sprite* An_3_inRow_12Rows_1, Sprite* An_3_inRow_12Rows_2, Sprite* An_3_inRow_12Rows_3, Sprite* An_3_inRow_12Rows_4, Sprite* An_3_inRow_12Rows_5, Sprite* An_3_inRow_12Rows_6, Sprite* An_3_inRow_12Rows_7, Sprite* An_3_inRow_12Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 11);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
		An_3_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 11);
	}

	int time_ff_3InRow_12Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_12Rows >= 0 && time_ff_3InRow_12Rows < 16) win.draw(*An_3_inRow_12Rows_1);
	else if (time_ff_3InRow_12Rows >= 16 && time_ff_3InRow_12Rows < 32) win.draw(*An_3_inRow_12Rows_2);
	else if (time_ff_3InRow_12Rows >= 32 && time_ff_3InRow_12Rows < 48) win.draw(*An_3_inRow_12Rows_3);
	else if (time_ff_3InRow_12Rows >= 48 && time_ff_3InRow_12Rows < 64) win.draw(*An_3_inRow_12Rows_4);
	else if (time_ff_3InRow_12Rows >= 64 && time_ff_3InRow_12Rows < 80) win.draw(*An_3_inRow_12Rows_5);
	else if (time_ff_3InRow_12Rows >= 80 && time_ff_3InRow_12Rows < 96) win.draw(*An_3_inRow_12Rows_6);
	else if (time_ff_3InRow_12Rows >= 96 && time_ff_3InRow_12Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_3_inRow_12Rows_7);
	}
	else if (time_ff_3InRow_12Rows >= 112 && time_ff_3InRow_12Rows < 128) win.draw(*An_3_inRow_12Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_12Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_13RowsFn(RenderWindow& win, Sprite* An_3_inRow_13Rows_1, Sprite* An_3_inRow_13Rows_2, Sprite* An_3_inRow_13Rows_3, Sprite* An_3_inRow_13Rows_4, Sprite* An_3_inRow_13Rows_5, Sprite* An_3_inRow_13Rows_6, Sprite* An_3_inRow_13Rows_7, Sprite* An_3_inRow_13Rows_8, Sprite* An_3_inRow_13Rows_9, Sprite* An_3_inRow_13Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 12);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
		An_3_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 12);
	}

	int time_ff_3InRow_13Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_13Rows >= 0 && time_ff_3InRow_13Rows < 16) win.draw(*An_3_inRow_13Rows_1);
	else if (time_ff_3InRow_13Rows >= 16 && time_ff_3InRow_13Rows < 32) win.draw(*An_3_inRow_13Rows_2);
	else if (time_ff_3InRow_13Rows >= 32 && time_ff_3InRow_13Rows < 48) win.draw(*An_3_inRow_13Rows_3);
	else if (time_ff_3InRow_13Rows >= 48 && time_ff_3InRow_13Rows < 64) win.draw(*An_3_inRow_13Rows_4);
	else if (time_ff_3InRow_13Rows >= 64 && time_ff_3InRow_13Rows < 80) win.draw(*An_3_inRow_13Rows_5);
	else if (time_ff_3InRow_13Rows >= 80 && time_ff_3InRow_13Rows < 96) win.draw(*An_3_inRow_13Rows_6);
	else if (time_ff_3InRow_13Rows >= 96 && time_ff_3InRow_13Rows < 112) win.draw(*An_3_inRow_13Rows_7);
	else if (time_ff_3InRow_13Rows >= 112 && time_ff_3InRow_13Rows < 128) win.draw(*An_3_inRow_13Rows_8);
	else if (time_ff_3InRow_13Rows >= 128 && time_ff_3InRow_13Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_3_inRow_13Rows_9);
	}
	else if (time_ff_3InRow_13Rows >= 144 && time_ff_3InRow_13Rows < 160) win.draw(*An_3_inRow_13Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_13Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_14RowsFn(RenderWindow& win, Sprite* An_3_inRow_14Rows_1, Sprite* An_3_inRow_14Rows_2, Sprite* An_3_inRow_14Rows_3, Sprite* An_3_inRow_14Rows_4, Sprite* An_3_inRow_14Rows_5, Sprite* An_3_inRow_14Rows_6, Sprite* An_3_inRow_14Rows_7, Sprite* An_3_inRow_14Rows_8, Sprite* An_3_inRow_14Rows_9, Sprite* An_3_inRow_14Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 13);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
		An_3_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 13);
	}

	int time_ff_3InRow_14Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_14Rows >= 0 && time_ff_3InRow_14Rows < 16) win.draw(*An_3_inRow_14Rows_1);
	else if (time_ff_3InRow_14Rows >= 16 && time_ff_3InRow_14Rows < 32) win.draw(*An_3_inRow_14Rows_2);
	else if (time_ff_3InRow_14Rows >= 32 && time_ff_3InRow_14Rows < 48) win.draw(*An_3_inRow_14Rows_3);
	else if (time_ff_3InRow_14Rows >= 48 && time_ff_3InRow_14Rows < 64) win.draw(*An_3_inRow_14Rows_4);
	else if (time_ff_3InRow_14Rows >= 64 && time_ff_3InRow_14Rows < 80) win.draw(*An_3_inRow_14Rows_5);
	else if (time_ff_3InRow_14Rows >= 80 && time_ff_3InRow_14Rows < 96) win.draw(*An_3_inRow_14Rows_6);
	else if (time_ff_3InRow_14Rows >= 96 && time_ff_3InRow_14Rows < 112) win.draw(*An_3_inRow_14Rows_7);
	else if (time_ff_3InRow_14Rows >= 112 && time_ff_3InRow_14Rows < 128) win.draw(*An_3_inRow_14Rows_8);
	else if (time_ff_3InRow_14Rows >= 128 && time_ff_3InRow_14Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_3_inRow_14Rows_9);
	}
	else if (time_ff_3InRow_14Rows >= 144 && time_ff_3InRow_14Rows < 160) win.draw(*An_3_inRow_14Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_14Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_15RowsFn(RenderWindow& win, Sprite* An_3_inRow_15Rows_1, Sprite* An_3_inRow_15Rows_2, Sprite* An_3_inRow_15Rows_3, Sprite* An_3_inRow_15Rows_4, Sprite* An_3_inRow_15Rows_5, Sprite* An_3_inRow_15Rows_6, Sprite* An_3_inRow_15Rows_7, Sprite* An_3_inRow_15Rows_8, Sprite* An_3_inRow_15Rows_9, Sprite* An_3_inRow_15Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 15);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 14);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
		An_3_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 14);
	}

	int time_ff_3InRow_15Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_15Rows >= 0 && time_ff_3InRow_15Rows < 16) win.draw(*An_3_inRow_15Rows_1);
	else if (time_ff_3InRow_15Rows >= 16 && time_ff_3InRow_15Rows < 32) win.draw(*An_3_inRow_15Rows_2);
	else if (time_ff_3InRow_15Rows >= 32 && time_ff_3InRow_15Rows < 48) win.draw(*An_3_inRow_15Rows_3);
	else if (time_ff_3InRow_15Rows >= 48 && time_ff_3InRow_15Rows < 64) win.draw(*An_3_inRow_15Rows_4);
	else if (time_ff_3InRow_15Rows >= 64 && time_ff_3InRow_15Rows < 80) win.draw(*An_3_inRow_15Rows_5);
	else if (time_ff_3InRow_15Rows >= 80 && time_ff_3InRow_15Rows < 96) win.draw(*An_3_inRow_15Rows_6);
	else if (time_ff_3InRow_15Rows >= 96 && time_ff_3InRow_15Rows < 112) win.draw(*An_3_inRow_15Rows_7);
	else if (time_ff_3InRow_15Rows >= 112 && time_ff_3InRow_15Rows < 128) win.draw(*An_3_inRow_15Rows_8);
	else if (time_ff_3InRow_15Rows >= 128 && time_ff_3InRow_15Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_3_inRow_15Rows_9);
	}
	else if (time_ff_3InRow_15Rows >= 144 && time_ff_3InRow_15Rows < 160) win.draw(*An_3_inRow_15Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_15Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_3InRow_17RowsFn(RenderWindow& win, Sprite* An_3_inRow_17Rows_1, Sprite* An_3_inRow_17Rows_2, Sprite* An_3_inRow_17Rows_3, Sprite* An_3_inRow_17Rows_4, Sprite* An_3_inRow_17Rows_5, Sprite* An_3_inRow_17Rows_6, Sprite* An_3_inRow_17Rows_7, Sprite* An_3_inRow_17Rows_8, Sprite* An_3_inRow_17Rows_9, Sprite* An_3_inRow_17Rows_10, Sprite* An_3_inRow_17Rows_11, Sprite* An_3_inRow_17Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	
	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
		An_3_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 16);
	}

	int time_ff_3InRow_17Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_17Rows >= 0 && time_ff_3InRow_17Rows < 16) win.draw(*An_3_inRow_17Rows_1);
	else if (time_ff_3InRow_17Rows >= 16 && time_ff_3InRow_17Rows < 32) win.draw(*An_3_inRow_17Rows_2);
	else if (time_ff_3InRow_17Rows >= 32 && time_ff_3InRow_17Rows < 48) win.draw(*An_3_inRow_17Rows_3);
	else if (time_ff_3InRow_17Rows >= 48 && time_ff_3InRow_17Rows < 64) win.draw(*An_3_inRow_17Rows_4);
	else if (time_ff_3InRow_17Rows >= 64 && time_ff_3InRow_17Rows < 80) win.draw(*An_3_inRow_17Rows_5);
	else if (time_ff_3InRow_17Rows >= 80 && time_ff_3InRow_17Rows < 96) win.draw(*An_3_inRow_17Rows_6);
	else if (time_ff_3InRow_17Rows >= 96 && time_ff_3InRow_17Rows < 112) win.draw(*An_3_inRow_17Rows_7);
	else if (time_ff_3InRow_17Rows >= 112 && time_ff_3InRow_17Rows < 128) win.draw(*An_3_inRow_17Rows_8);
	else if (time_ff_3InRow_17Rows >= 128 && time_ff_3InRow_17Rows < 144) win.draw(*An_3_inRow_17Rows_9);
	else if (time_ff_3InRow_17Rows >= 144 && time_ff_3InRow_17Rows < 160)
	{
		win.draw(*An_3_inRow_17Rows_10);
		//if(checkForFigureBot)
		forFigureBot = true;
	}
	else if (time_ff_3InRow_17Rows >= 160 && time_ff_3InRow_17Rows < 176) win.draw(*An_3_inRow_17Rows_11);
	else if (time_ff_3InRow_17Rows >= 176 && time_ff_3InRow_17Rows < 192) win.draw(*An_3_inRow_17Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_17Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}
void animation_fast_falling_3InRow_18RowsFn(RenderWindow& win, Sprite* An_3_inRow_18Rows_1, Sprite* An_3_inRow_18Rows_2, Sprite* An_3_inRow_18Rows_3, Sprite* An_3_inRow_18Rows_4, Sprite* An_3_inRow_18Rows_5, Sprite* An_3_inRow_18Rows_6, Sprite* An_3_inRow_18Rows_7, Sprite* An_3_inRow_18Rows_8, Sprite* An_3_inRow_18Rows_9, Sprite* An_3_inRow_18Rows_10, Sprite* An_3_inRow_18Rows_11, Sprite* An_3_inRow_18Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 18);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
	}


	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 18);
	}


	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 17);
	}


	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)

	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884 - 38 * 2, a[0].y * 38 + 219 - 864 + 38 * 16);
	}


	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
		An_3_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 + 38 * 17);
	}

	int time_ff_3InRow_18Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_3InRow_18Rows >= 0 && time_ff_3InRow_18Rows < 16) win.draw(*An_3_inRow_18Rows_1);
	else if (time_ff_3InRow_18Rows >= 16 && time_ff_3InRow_18Rows < 32) win.draw(*An_3_inRow_18Rows_2);
	else if (time_ff_3InRow_18Rows >= 32 && time_ff_3InRow_18Rows < 48) win.draw(*An_3_inRow_18Rows_3);
	else if (time_ff_3InRow_18Rows >= 48 && time_ff_3InRow_18Rows < 64) win.draw(*An_3_inRow_18Rows_4);
	else if (time_ff_3InRow_18Rows >= 64 && time_ff_3InRow_18Rows < 80) win.draw(*An_3_inRow_18Rows_5);
	else if (time_ff_3InRow_18Rows >= 80 && time_ff_3InRow_18Rows < 96) win.draw(*An_3_inRow_18Rows_6);
	else if (time_ff_3InRow_18Rows >= 96 && time_ff_3InRow_18Rows < 112) win.draw(*An_3_inRow_18Rows_7);
	else if (time_ff_3InRow_18Rows >= 112 && time_ff_3InRow_18Rows < 128) win.draw(*An_3_inRow_18Rows_8);
	else if (time_ff_3InRow_18Rows >= 128 && time_ff_3InRow_18Rows < 144) win.draw(*An_3_inRow_18Rows_9);
	else if (time_ff_3InRow_18Rows >= 144 && time_ff_3InRow_18Rows < 160)
	{
		win.draw(*An_3_inRow_18Rows_10);
		//if(checkForFigureBot)
		forFigureBot = true;
	}
	else if (time_ff_3InRow_18Rows >= 160 && time_ff_3InRow_18Rows < 176) win.draw(*An_3_inRow_18Rows_11);
	else if (time_ff_3InRow_18Rows >= 176 && time_ff_3InRow_18Rows < 192) win.draw(*An_3_inRow_18Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_3InRow_18Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_1RowFn(RenderWindow& win, Sprite* An_4_inRow_1Row_1, Sprite* An_4_inRow_1Row_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
		An_4_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_1Row_1->setPosition(a[0].x * 38 + 922 - 844 - 38*4, a[0].y * 38 + 219 - 864 + 38);
		An_4_inRow_1Row_2->setPosition(a[0].x * 38 + 922 - 844 - 38*4, a[0].y * 38 + 219 - 864 + 38);
	}

	int time_ff_4InRow_1Row = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_1Row >= 0 && time_ff_4InRow_1Row < 16) win.draw(*An_4_inRow_1Row_1);
	else if (time_ff_4InRow_1Row >= 16 && time_ff_4InRow_1Row < 32) win.draw(*An_4_inRow_1Row_2);
	else if (time_ff_4InRow_1Row >= 32 && time_ff_4InRow_1Row < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_1Row = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_2RowsFn(RenderWindow& win, Sprite* An_4_inRow_2Rows_1, Sprite* An_4_inRow_2Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
		An_4_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38*2);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_2Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38*2);
		An_4_inRow_2Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38*2);
	}

	int time_ff_4InRow_2Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_2Rows >= 0 && time_ff_4InRow_2Rows < 16) win.draw(*An_4_inRow_2Rows_1);
	else if (time_ff_4InRow_2Rows >= 16 && time_ff_4InRow_2Rows < 32) win.draw(*An_4_inRow_2Rows_2);
	else if (time_ff_4InRow_2Rows >= 32 && time_ff_4InRow_2Rows < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_2Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_3RowsFn(RenderWindow& win, Sprite* An_4_inRow_3Rows_1, Sprite* An_4_inRow_3Rows_2)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_4_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 3);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_3Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 3);
		An_4_inRow_3Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 3);
	}

	int time_ff_4InRow_3Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_3Rows >= 0 && time_ff_4InRow_3Rows < 16) win.draw(*An_4_inRow_3Rows_1);
	else if (time_ff_4InRow_3Rows >= 16 && time_ff_4InRow_3Rows < 32) win.draw(*An_4_inRow_3Rows_2);
	else if (time_ff_4InRow_3Rows >= 32 && time_ff_4InRow_3Rows < 48) /*if(checkForFigureBot)*/ forFigureBot = true;
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_3Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_4RowsFn(RenderWindow& win, Sprite* An_4_inRow_4Rows_1, Sprite* An_4_inRow_4Rows_2, Sprite* An_4_inRow_4Rows_3, Sprite* An_4_inRow_4Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_4_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_4_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_4_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 4);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_4Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_4_inRow_4Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_4_inRow_4Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 4);
		An_4_inRow_4Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 4);
	}

	int time_ff_4InRow_4Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_4Rows >= 0 && time_ff_4InRow_4Rows < 16) win.draw(*An_4_inRow_4Rows_1);
	else if (time_ff_4InRow_4Rows >= 16 && time_ff_4InRow_4Rows < 32) win.draw(*An_4_inRow_4Rows_2);
	else if (time_ff_4InRow_4Rows >= 32 && time_ff_4InRow_4Rows < 48) win.draw(*An_4_inRow_4Rows_3);
	else if (time_ff_4InRow_4Rows >= 48 && time_ff_4InRow_4Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_4Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_4Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_5RowsFn(RenderWindow& win, Sprite* An_4_inRow_5Rows_1, Sprite* An_4_inRow_5Rows_2, Sprite* An_4_inRow_5Rows_3, Sprite* An_4_inRow_5Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_4_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_4_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_4_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 5);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_5Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_4_inRow_5Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_4_inRow_5Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 5);
		An_4_inRow_5Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 5);
	}

	int time_ff_4InRow_5Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_5Rows >= 0 && time_ff_4InRow_5Rows < 16) win.draw(*An_4_inRow_5Rows_1);
	else if (time_ff_4InRow_5Rows >= 16 && time_ff_4InRow_5Rows < 32) win.draw(*An_4_inRow_5Rows_2);
	else if (time_ff_4InRow_5Rows >= 32 && time_ff_4InRow_5Rows < 48) win.draw(*An_4_inRow_5Rows_3);
	else if (time_ff_4InRow_5Rows >= 48 && time_ff_4InRow_5Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_5Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_5Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_6RowsFn(RenderWindow& win, Sprite* An_4_inRow_6Rows_1, Sprite* An_4_inRow_6Rows_2, Sprite* An_4_inRow_6Rows_3, Sprite* An_4_inRow_6Rows_4)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_4_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_4_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_4_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 6);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_6Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_4_inRow_6Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_4_inRow_6Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 6);
		An_4_inRow_6Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 6);
	}

	int time_ff_4InRow_6Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_6Rows >= 0 && time_ff_4InRow_6Rows < 16) win.draw(*An_4_inRow_6Rows_1);
	else if (time_ff_4InRow_6Rows >= 16 && time_ff_4InRow_6Rows < 32) win.draw(*An_4_inRow_6Rows_2);
	else if (time_ff_4InRow_6Rows >= 32 && time_ff_4InRow_6Rows < 48) win.draw(*An_4_inRow_6Rows_3);
	else if (time_ff_4InRow_6Rows >= 48 && time_ff_4InRow_6Rows < 64)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_6Rows_4);
	}
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_6Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_7RowsFn(RenderWindow& win, Sprite* An_4_inRow_7Rows_1, Sprite* An_4_inRow_7Rows_2, Sprite* An_4_inRow_7Rows_3, Sprite* An_4_inRow_7Rows_4, Sprite* An_4_inRow_7Rows_5, Sprite* An_4_inRow_7Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 7);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_7Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 7);
		An_4_inRow_7Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 7);
	}

	int time_ff_4InRow_7Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_7Rows >= 0 && time_ff_4InRow_7Rows < 16) win.draw(*An_4_inRow_7Rows_1);
	else if (time_ff_4InRow_7Rows >= 16 && time_ff_4InRow_7Rows < 32) win.draw(*An_4_inRow_7Rows_2);
	else if (time_ff_4InRow_7Rows >= 32 && time_ff_4InRow_7Rows < 48) win.draw(*An_4_inRow_7Rows_3);
	else if (time_ff_4InRow_7Rows >= 48 && time_ff_4InRow_7Rows < 64) win.draw(*An_4_inRow_7Rows_4);
	else if (time_ff_4InRow_7Rows >= 64 && time_ff_4InRow_7Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_7Rows_5);
	}
	else if (time_ff_4InRow_7Rows >= 80 && time_ff_4InRow_7Rows < 96) win.draw(*An_4_inRow_7Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_7Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_8RowsFn(RenderWindow& win, Sprite* An_4_inRow_8Rows_1, Sprite* An_4_inRow_8Rows_2, Sprite* An_4_inRow_8Rows_3, Sprite* An_4_inRow_8Rows_4, Sprite* An_4_inRow_8Rows_5, Sprite* An_4_inRow_8Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 8);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_8Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 8);
		An_4_inRow_8Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 8);
	}

	int time_ff_4InRow_8Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_8Rows >= 0 && time_ff_4InRow_8Rows < 16) win.draw(*An_4_inRow_8Rows_1);
	else if (time_ff_4InRow_8Rows >= 16 && time_ff_4InRow_8Rows < 32) win.draw(*An_4_inRow_8Rows_2);
	else if (time_ff_4InRow_8Rows >= 32 && time_ff_4InRow_8Rows < 48) win.draw(*An_4_inRow_8Rows_3);
	else if (time_ff_4InRow_8Rows >= 48 && time_ff_4InRow_8Rows < 64) win.draw(*An_4_inRow_8Rows_4);
	else if (time_ff_4InRow_8Rows >= 64 && time_ff_4InRow_8Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_8Rows_5);
	}
	else if (time_ff_4InRow_8Rows >= 80 && time_ff_4InRow_8Rows < 96) win.draw(*An_4_inRow_8Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_8Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_9RowsFn(RenderWindow& win, Sprite* An_4_inRow_9Rows_1, Sprite* An_4_inRow_9Rows_2, Sprite* An_4_inRow_9Rows_3, Sprite* An_4_inRow_9Rows_4, Sprite* An_4_inRow_9Rows_5, Sprite* An_4_inRow_9Rows_6)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 9);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_9Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 9);
		An_4_inRow_9Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 9);
	}

	int time_ff_4InRow_9Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_9Rows >= 0 && time_ff_4InRow_9Rows < 16) win.draw(*An_4_inRow_9Rows_1);
	else if (time_ff_4InRow_9Rows >= 16 && time_ff_4InRow_9Rows < 32) win.draw(*An_4_inRow_9Rows_2);
	else if (time_ff_4InRow_9Rows >= 32 && time_ff_4InRow_9Rows < 48) win.draw(*An_4_inRow_9Rows_3);
	else if (time_ff_4InRow_9Rows >= 48 && time_ff_4InRow_9Rows < 64) win.draw(*An_4_inRow_9Rows_4);
	else if (time_ff_4InRow_9Rows >= 64 && time_ff_4InRow_9Rows < 80)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_9Rows_5);
	}
	else if (time_ff_4InRow_9Rows >= 80 && time_ff_4InRow_9Rows < 96) win.draw(*An_4_inRow_9Rows_6);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_9Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_10RowsFn(RenderWindow& win, Sprite* An_4_inRow_10Rows_1, Sprite* An_4_inRow_10Rows_2, Sprite* An_4_inRow_10Rows_3, Sprite* An_4_inRow_10Rows_4, Sprite* An_4_inRow_10Rows_5, Sprite* An_4_inRow_10Rows_6, Sprite* An_4_inRow_10Rows_7, Sprite* An_4_inRow_10Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 10);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_10Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
		An_4_inRow_10Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 10);
	}

	int time_ff_4InRow_10Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_10Rows >= 0 && time_ff_4InRow_10Rows < 16) win.draw(*An_4_inRow_10Rows_1);
	else if (time_ff_4InRow_10Rows >= 16 && time_ff_4InRow_10Rows < 32) win.draw(*An_4_inRow_10Rows_2);
	else if (time_ff_4InRow_10Rows >= 32 && time_ff_4InRow_10Rows < 48) win.draw(*An_4_inRow_10Rows_3);
	else if (time_ff_4InRow_10Rows >= 48 && time_ff_4InRow_10Rows < 64) win.draw(*An_4_inRow_10Rows_4);
	else if (time_ff_4InRow_10Rows >= 64 && time_ff_4InRow_10Rows < 80) win.draw(*An_4_inRow_10Rows_5);
	else if (time_ff_4InRow_10Rows >= 80 && time_ff_4InRow_10Rows < 96) win.draw(*An_4_inRow_10Rows_6);
	else if (time_ff_4InRow_10Rows >= 96 && time_ff_4InRow_10Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_10Rows_7);
	}
	else if (time_ff_4InRow_10Rows >= 112 && time_ff_4InRow_10Rows < 128) win.draw(*An_4_inRow_10Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_10Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_11RowsFn(RenderWindow& win, Sprite* An_4_inRow_11Rows_1, Sprite* An_4_inRow_11Rows_2, Sprite* An_4_inRow_11Rows_3, Sprite* An_4_inRow_11Rows_4, Sprite* An_4_inRow_11Rows_5, Sprite* An_4_inRow_11Rows_6, Sprite* An_4_inRow_11Rows_7, Sprite* An_4_inRow_11Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 11);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_11Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
		An_4_inRow_11Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 11);
	}

	int time_ff_4InRow_11Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_11Rows >= 0 && time_ff_4InRow_11Rows < 16) win.draw(*An_4_inRow_11Rows_1);
	else if (time_ff_4InRow_11Rows >= 16 && time_ff_4InRow_11Rows < 32) win.draw(*An_4_inRow_11Rows_2);
	else if (time_ff_4InRow_11Rows >= 32 && time_ff_4InRow_11Rows < 48) win.draw(*An_4_inRow_11Rows_3);
	else if (time_ff_4InRow_11Rows >= 48 && time_ff_4InRow_11Rows < 64) win.draw(*An_4_inRow_11Rows_4);
	else if (time_ff_4InRow_11Rows >= 64 && time_ff_4InRow_11Rows < 80) win.draw(*An_4_inRow_11Rows_5);
	else if (time_ff_4InRow_11Rows >= 80 && time_ff_4InRow_11Rows < 96) win.draw(*An_4_inRow_11Rows_6);
	else if (time_ff_4InRow_11Rows >= 96 && time_ff_4InRow_11Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_11Rows_7);
	}
	else if (time_ff_4InRow_11Rows >= 112 && time_ff_4InRow_11Rows < 128) win.draw(*An_4_inRow_11Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_11Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_12RowsFn(RenderWindow& win, Sprite* An_4_inRow_12Rows_1, Sprite* An_4_inRow_12Rows_2, Sprite* An_4_inRow_12Rows_3, Sprite* An_4_inRow_12Rows_4, Sprite* An_4_inRow_12Rows_5, Sprite* An_4_inRow_12Rows_6, Sprite* An_4_inRow_12Rows_7, Sprite* An_4_inRow_12Rows_8)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 12);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_12Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
		An_4_inRow_12Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 12);
	}

	int time_ff_4InRow_12Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_12Rows >= 0 && time_ff_4InRow_12Rows < 16) win.draw(*An_4_inRow_12Rows_1);
	else if (time_ff_4InRow_12Rows >= 16 && time_ff_4InRow_12Rows < 32) win.draw(*An_4_inRow_12Rows_2);
	else if (time_ff_4InRow_12Rows >= 32 && time_ff_4InRow_12Rows < 48) win.draw(*An_4_inRow_12Rows_3);
	else if (time_ff_4InRow_12Rows >= 48 && time_ff_4InRow_12Rows < 64) win.draw(*An_4_inRow_12Rows_4);
	else if (time_ff_4InRow_12Rows >= 64 && time_ff_4InRow_12Rows < 80) win.draw(*An_4_inRow_12Rows_5);
	else if (time_ff_4InRow_12Rows >= 80 && time_ff_4InRow_12Rows < 96) win.draw(*An_4_inRow_12Rows_6);
	else if (time_ff_4InRow_12Rows >= 96 && time_ff_4InRow_12Rows < 112)
	{
		/*if (checkForFigureBot)*/ forFigureBot = true;
		win.draw(*An_4_inRow_12Rows_7);
	}
	else if (time_ff_4InRow_12Rows >= 112 && time_ff_4InRow_12Rows < 128) win.draw(*An_4_inRow_12Rows_8);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_12Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_13RowsFn(RenderWindow& win, Sprite* An_4_inRow_13Rows_1, Sprite* An_4_inRow_13Rows_2, Sprite* An_4_inRow_13Rows_3, Sprite* An_4_inRow_13Rows_4, Sprite* An_4_inRow_13Rows_5, Sprite* An_4_inRow_13Rows_6, Sprite* An_4_inRow_13Rows_7, Sprite* An_4_inRow_13Rows_8, Sprite* An_4_inRow_13Rows_9, Sprite* An_4_inRow_13Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 13);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_13Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_9->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
		An_4_inRow_13Rows_10->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 13);
	}

	int time_ff_4InRow_13Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_13Rows >= 0 && time_ff_4InRow_13Rows < 16) win.draw(*An_4_inRow_13Rows_1);
	else if (time_ff_4InRow_13Rows >= 16 && time_ff_4InRow_13Rows < 32) win.draw(*An_4_inRow_13Rows_2);
	else if (time_ff_4InRow_13Rows >= 32 && time_ff_4InRow_13Rows < 48) win.draw(*An_4_inRow_13Rows_3);
	else if (time_ff_4InRow_13Rows >= 48 && time_ff_4InRow_13Rows < 64) win.draw(*An_4_inRow_13Rows_4);
	else if (time_ff_4InRow_13Rows >= 64 && time_ff_4InRow_13Rows < 80) win.draw(*An_4_inRow_13Rows_5);
	else if (time_ff_4InRow_13Rows >= 80 && time_ff_4InRow_13Rows < 96) win.draw(*An_4_inRow_13Rows_6);
	else if (time_ff_4InRow_13Rows >= 96 && time_ff_4InRow_13Rows < 112) win.draw(*An_4_inRow_13Rows_7);
	else if (time_ff_4InRow_13Rows >= 112 && time_ff_4InRow_13Rows < 128) win.draw(*An_4_inRow_13Rows_8);
	else if (time_ff_4InRow_13Rows >= 128 && time_ff_4InRow_13Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_4_inRow_13Rows_9);
	}
	else if (time_ff_4InRow_13Rows >= 144 && time_ff_4InRow_13Rows < 160) win.draw(*An_4_inRow_13Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_13Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_14RowsFn(RenderWindow& win, Sprite* An_4_inRow_14Rows_1, Sprite* An_4_inRow_14Rows_2, Sprite* An_4_inRow_14Rows_3, Sprite* An_4_inRow_14Rows_4, Sprite* An_4_inRow_14Rows_5, Sprite* An_4_inRow_14Rows_6, Sprite* An_4_inRow_14Rows_7, Sprite* An_4_inRow_14Rows_8, Sprite* An_4_inRow_14Rows_9, Sprite* An_4_inRow_14Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 14);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_14Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_9->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
		An_4_inRow_14Rows_10->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 14);
	}

	int time_ff_4InRow_14Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_14Rows >= 0 && time_ff_4InRow_14Rows < 16) win.draw(*An_4_inRow_14Rows_1);
	else if (time_ff_4InRow_14Rows >= 16 && time_ff_4InRow_14Rows < 32) win.draw(*An_4_inRow_14Rows_2);
	else if (time_ff_4InRow_14Rows >= 32 && time_ff_4InRow_14Rows < 48) win.draw(*An_4_inRow_14Rows_3);
	else if (time_ff_4InRow_14Rows >= 48 && time_ff_4InRow_14Rows < 64) win.draw(*An_4_inRow_14Rows_4);
	else if (time_ff_4InRow_14Rows >= 64 && time_ff_4InRow_14Rows < 80) win.draw(*An_4_inRow_14Rows_5);
	else if (time_ff_4InRow_14Rows >= 80 && time_ff_4InRow_14Rows < 96) win.draw(*An_4_inRow_14Rows_6);
	else if (time_ff_4InRow_14Rows >= 96 && time_ff_4InRow_14Rows < 112) win.draw(*An_4_inRow_14Rows_7);
	else if (time_ff_4InRow_14Rows >= 112 && time_ff_4InRow_14Rows < 128) win.draw(*An_4_inRow_14Rows_8);
	else if (time_ff_4InRow_14Rows >= 128 && time_ff_4InRow_14Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_4_inRow_14Rows_9);
	}
	else if (time_ff_4InRow_14Rows >= 144 && time_ff_4InRow_14Rows < 160) win.draw(*An_4_inRow_14Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_14Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_15RowsFn(RenderWindow& win, Sprite* An_4_inRow_15Rows_1, Sprite* An_4_inRow_15Rows_2, Sprite* An_4_inRow_15Rows_3, Sprite* An_4_inRow_15Rows_4, Sprite* An_4_inRow_15Rows_5, Sprite* An_4_inRow_15Rows_6, Sprite* An_4_inRow_15Rows_7, Sprite* An_4_inRow_15Rows_8, Sprite* An_4_inRow_15Rows_9, Sprite* An_4_inRow_15Rows_10)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 15);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_15Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_9->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
		An_4_inRow_15Rows_10->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 15);
	}

	int time_ff_4InRow_15Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_15Rows >= 0 && time_ff_4InRow_15Rows < 16) win.draw(*An_4_inRow_15Rows_1);
	else if (time_ff_4InRow_15Rows >= 16 && time_ff_4InRow_15Rows < 32) win.draw(*An_4_inRow_15Rows_2);
	else if (time_ff_4InRow_15Rows >= 32 && time_ff_4InRow_15Rows < 48) win.draw(*An_4_inRow_15Rows_3);
	else if (time_ff_4InRow_15Rows >= 48 && time_ff_4InRow_15Rows < 64) win.draw(*An_4_inRow_15Rows_4);
	else if (time_ff_4InRow_15Rows >= 64 && time_ff_4InRow_15Rows < 80) win.draw(*An_4_inRow_15Rows_5);
	else if (time_ff_4InRow_15Rows >= 80 && time_ff_4InRow_15Rows < 96) win.draw(*An_4_inRow_15Rows_6);
	else if (time_ff_4InRow_15Rows >= 96 && time_ff_4InRow_15Rows < 112) win.draw(*An_4_inRow_15Rows_7);
	else if (time_ff_4InRow_15Rows >= 112 && time_ff_4InRow_15Rows < 128) win.draw(*An_4_inRow_15Rows_8);
	else if (time_ff_4InRow_15Rows >= 128 && time_ff_4InRow_15Rows < 144)
	{
		/*if (checkForFigureBot) */forFigureBot = true;
		win.draw(*An_4_inRow_15Rows_9);
	}
	else if (time_ff_4InRow_15Rows >= 144 && time_ff_4InRow_15Rows < 160) win.draw(*An_4_inRow_15Rows_10);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_15Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_16RowsFn(RenderWindow& win, Sprite* An_4_inRow_16Rows_1, Sprite* An_4_inRow_16Rows_2, Sprite* An_4_inRow_16Rows_3, Sprite* An_4_inRow_16Rows_4, Sprite* An_4_inRow_16Rows_5, Sprite* An_4_inRow_16Rows_6, Sprite* An_4_inRow_16Rows_7, Sprite* An_4_inRow_16Rows_8, Sprite* An_4_inRow_16Rows_9, Sprite* An_4_inRow_16Rows_10, Sprite* An_4_inRow_16Rows_11, Sprite* An_4_inRow_16Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 16);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_16Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_9->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_10->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_11->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
		An_4_inRow_16Rows_12->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 16);
	}

	int time_ff_4InRow_16Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_16Rows >= 0 && time_ff_4InRow_16Rows < 16) win.draw(*An_4_inRow_16Rows_1);
	else if (time_ff_4InRow_16Rows >= 16 && time_ff_4InRow_16Rows < 32) win.draw(*An_4_inRow_16Rows_2);
	else if (time_ff_4InRow_16Rows >= 32 && time_ff_4InRow_16Rows < 48) win.draw(*An_4_inRow_16Rows_3);
	else if (time_ff_4InRow_16Rows >= 48 && time_ff_4InRow_16Rows < 64) win.draw(*An_4_inRow_16Rows_4);
	else if (time_ff_4InRow_16Rows >= 64 && time_ff_4InRow_16Rows < 80) win.draw(*An_4_inRow_16Rows_5);
	else if (time_ff_4InRow_16Rows >= 80 && time_ff_4InRow_16Rows < 96) win.draw(*An_4_inRow_16Rows_6);
	else if (time_ff_4InRow_16Rows >= 96 && time_ff_4InRow_16Rows < 112) win.draw(*An_4_inRow_16Rows_7);
	else if (time_ff_4InRow_16Rows >= 112 && time_ff_4InRow_16Rows < 128) win.draw(*An_4_inRow_16Rows_8);
	else if (time_ff_4InRow_16Rows >= 128 && time_ff_4InRow_16Rows < 144) win.draw(*An_4_inRow_16Rows_9);
	else if (time_ff_4InRow_16Rows >= 144 && time_ff_4InRow_16Rows < 160)
	{
		win.draw(*An_4_inRow_16Rows_10);
		//if(checkForFigureBot)
		forFigureBot = true;
	}
	else if (time_ff_4InRow_16Rows >= 160 && time_ff_4InRow_16Rows < 176) win.draw(*An_4_inRow_16Rows_11);
	else if (time_ff_4InRow_16Rows >= 176 && time_ff_4InRow_16Rows < 192) win.draw(*An_4_inRow_16Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_16Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_17RowsFn(RenderWindow& win, Sprite* An_4_inRow_17Rows_1, Sprite* An_4_inRow_17Rows_2, Sprite* An_4_inRow_17Rows_3, Sprite* An_4_inRow_17Rows_4, Sprite* An_4_inRow_17Rows_5, Sprite* An_4_inRow_17Rows_6, Sprite* An_4_inRow_17Rows_7, Sprite* An_4_inRow_17Rows_8, Sprite* An_4_inRow_17Rows_9, Sprite* An_4_inRow_17Rows_10, Sprite* An_4_inRow_17Rows_11, Sprite* An_4_inRow_17Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_17Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_9->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_10->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_11->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_17Rows_12->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	int time_ff_4InRow_17Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_17Rows >= 0 && time_ff_4InRow_17Rows < 16) win.draw(*An_4_inRow_17Rows_1);
	else if (time_ff_4InRow_17Rows >= 16 && time_ff_4InRow_17Rows < 32) win.draw(*An_4_inRow_17Rows_2);
	else if (time_ff_4InRow_17Rows >= 32 && time_ff_4InRow_17Rows < 48) win.draw(*An_4_inRow_17Rows_3);
	else if (time_ff_4InRow_17Rows >= 48 && time_ff_4InRow_17Rows < 64) win.draw(*An_4_inRow_17Rows_4);
	else if (time_ff_4InRow_17Rows >= 64 && time_ff_4InRow_17Rows < 80) win.draw(*An_4_inRow_17Rows_5);
	else if (time_ff_4InRow_17Rows >= 80 && time_ff_4InRow_17Rows < 96) win.draw(*An_4_inRow_17Rows_6);
	else if (time_ff_4InRow_17Rows >= 96 && time_ff_4InRow_17Rows < 112) win.draw(*An_4_inRow_17Rows_7);
	else if (time_ff_4InRow_17Rows >= 112 && time_ff_4InRow_17Rows < 128) win.draw(*An_4_inRow_17Rows_8);
	else if (time_ff_4InRow_17Rows >= 128 && time_ff_4InRow_17Rows < 144) win.draw(*An_4_inRow_17Rows_9);
	else if (time_ff_4InRow_17Rows >= 144 && time_ff_4InRow_17Rows < 160)
	{
		win.draw(*An_4_inRow_17Rows_10);
		//if(checkForFigureBot)
		forFigureBot = true;
	}
	else if (time_ff_4InRow_17Rows >= 160 && time_ff_4InRow_17Rows < 176) win.draw(*An_4_inRow_17Rows_11);
	else if (time_ff_4InRow_17Rows >= 176 && time_ff_4InRow_17Rows < 192) win.draw(*An_4_inRow_17Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_17Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void animation_fast_falling_4InRow_18RowsFn(RenderWindow& win, Sprite* An_4_inRow_18Rows_1, Sprite* An_4_inRow_18Rows_2, Sprite* An_4_inRow_18Rows_3, Sprite* An_4_inRow_18Rows_4, Sprite* An_4_inRow_18Rows_5, Sprite* An_4_inRow_18Rows_6, Sprite* An_4_inRow_18Rows_7, Sprite* An_4_inRow_18Rows_8, Sprite* An_4_inRow_18Rows_9, Sprite* An_4_inRow_18Rows_10, Sprite* An_4_inRow_18Rows_11, Sprite* An_4_inRow_18Rows_12)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 884, a[0].y * 38 + 219 - 864 + 38 * 17);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_18Rows_1->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_2->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_3->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_4->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_5->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_6->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_7->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_8->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_9->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_10->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_11->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
		An_4_inRow_18Rows_12->setPosition(a[0].x * 38 + 922 - 844 - 38 * 4, a[0].y * 38 + 219 - 864 + 38 * 17);
	}

	int time_ff_4InRow_18Rows = animation_fast_falling_clock.getElapsedTime().asMilliseconds();

	if (time_ff_4InRow_18Rows >= 0 && time_ff_4InRow_18Rows < 16) win.draw(*An_4_inRow_18Rows_1);
	else if (time_ff_4InRow_18Rows >= 16 && time_ff_4InRow_18Rows < 32) win.draw(*An_4_inRow_18Rows_2);
	else if (time_ff_4InRow_18Rows >= 32 && time_ff_4InRow_18Rows < 48) win.draw(*An_4_inRow_18Rows_3);
	else if (time_ff_4InRow_18Rows >= 48 && time_ff_4InRow_18Rows < 64) win.draw(*An_4_inRow_18Rows_4);
	else if (time_ff_4InRow_18Rows >= 64 && time_ff_4InRow_18Rows < 80) win.draw(*An_4_inRow_18Rows_5);
	else if (time_ff_4InRow_18Rows >= 80 && time_ff_4InRow_18Rows < 96) win.draw(*An_4_inRow_18Rows_6);
	else if (time_ff_4InRow_18Rows >= 96 && time_ff_4InRow_18Rows < 112) win.draw(*An_4_inRow_18Rows_7);
	else if (time_ff_4InRow_18Rows >= 112 && time_ff_4InRow_18Rows < 128) win.draw(*An_4_inRow_18Rows_8);
	else if (time_ff_4InRow_18Rows >= 128 && time_ff_4InRow_18Rows < 144) win.draw(*An_4_inRow_18Rows_9);
	else if (time_ff_4InRow_18Rows >= 144 && time_ff_4InRow_18Rows < 160)
	{
		win.draw(*An_4_inRow_18Rows_10);
		//if(checkForFigureBot)
		forFigureBot = true;
	}
	else if (time_ff_4InRow_18Rows >= 160 && time_ff_4InRow_18Rows < 176) win.draw(*An_4_inRow_18Rows_11);
	else if (time_ff_4InRow_18Rows >= 176 && time_ff_4InRow_18Rows < 192) win.draw(*An_4_inRow_18Rows_12);
	else
	{
		afterAnimationFF = true;
		progressOfAnimationFF = false;
		enableAnimation_fast_falling_4InRow_18Rows = false;
		check_space = false;
		for (USHORT i = 0; i < 4; i++)
			field[e[i].y][e[i].x + 4] = colorNum; ///тут править
	}
}

void falling_down(Point* j, Point* e)
{
	while (true)
	{
		for (USHORT i = 0; i < 4; i++)
		{
			j[i] = e[i]; e[i].y++;
		}
		if (!checkForPrototypeField() || !checkForPrototypeHeight())
		{
			for (USHORT i = 0; i < 4; i++)
			{
				e[i] = j[i];
			}
			break;
		}
	}
				//cout << "===============================Beginning=================================" << endl;
				//for (int i = 0; i < 4; i++)
				//{
				//	//cout << "a[i].x : " << a[i].x << '\t' << "a[i].y :" << a[i].y << endl;
				//	cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;
				//	cout << "j[" << i << "].x : " << j[i].x << '\t' << "j[" << i << "].y :" << j[i].y << endl;
				//}
				//cout << "===============================End=======================================" << endl;
				//cout << endl << endl;
}

void checkFullLineFn(USHORT field [H][W])
{
		for (USHORT i = H - 1; i > 0; i--)
		{
			USHORT count = 0;
			for (USHORT j = 0; j < W; j++)
			{
				if (field[i][j]) count++;
			}
			if (count == W)
			{
				indexesOfIdLines.push_back(i);
				numberOfIdenticalLines++;
				indexOfLastLine = i;
			}
		}
		//cout << numberOfIdenticalLines << endl;
		//cout << indexOfLastLine << endl;
		//обнуление линий перед анимацией
		for (USHORT i = indexOfLastLine; ; i++)
		{
			
			for (USHORT k = 0; k < indexesOfIdLines.size(); k++)
			{
				if(indexesOfIdLines[k] == i)// если индекс из вектора совпадает с индексом i, обнулить
					for (USHORT j = 0; j < W; j++)
					{
						field[i][j] = 0;
					}
			}
			if (i == (19 - indexOfLastLine + indexOfLastLine))break;
		}
	
		if (numberOfIdenticalLines == 1)
		{
			enableAnimation1line = true;
			animation_1_line.restart();
		}
		
		if (numberOfIdenticalLines == 2 && indexesOfIdLines[0] - indexesOfIdLines[1] == 2)
		{
			enableAnimation2lines_with_void = true;
			animation_1_line.restart();
		}

		if (numberOfIdenticalLines == 2 && indexesOfIdLines[0] - indexesOfIdLines[1] == 3)
		{
			enableAnimation2lines_with_void = true;
			animation_1_line.restart();
		}

		if (numberOfIdenticalLines == 2 && indexesOfIdLines[0] - indexesOfIdLines[1] == 1)
		{
			enableAnimation2lines = true;
			animation_2_lines.restart();
		}

		if (numberOfIdenticalLines == 3 && indexesOfIdLines[0] - indexesOfIdLines[1] == 1 && indexesOfIdLines[1] - indexesOfIdLines[2] == 1)
		{
			enableAnimation3lines = true;
			animation_3_lines.restart();
		}

		if (numberOfIdenticalLines == 3 && indexesOfIdLines[0] - indexesOfIdLines[1] == 1 && indexesOfIdLines[1] - indexesOfIdLines[2] == 2)
		{
			enableAnimation3lines_with_void = true;
			animation_1_line.restart();
			animation_2_lines.restart();
		}

		if (numberOfIdenticalLines == 3 && indexesOfIdLines[0] - indexesOfIdLines[1] == 2 && indexesOfIdLines[1] - indexesOfIdLines[2] == 1)
		{
			enableAnimation3lines_with_void = true;
			animation_1_line.restart();
			animation_2_lines.restart();
		}

		if (numberOfIdenticalLines == 4)
		{
			enableAnimation4lines = true;
			animation_4_lines.restart();
		}

}

void checkFullLineFn2(USHORT field[H][W])
{
	if (afterAnimationLine)
	{
		USHORT k = H - 1;
		//заполнение линии после анимации
		for (USHORT i = indexOfLastLine; ; i++)
		{

			for (USHORT k = 0; k < indexesOfIdLines.size(); k++)
			{
				if (indexesOfIdLines[k] == i)// если индекс из вектора совпадает с индексом i, заполнить единицами
					for (USHORT j = 0; j < W; j++)
					{
						field[i][j] = 1;
					}
			}
			if (i == (19 - indexOfLastLine + indexOfLastLine))break;
		}

		//сжигание линий
		for (USHORT i = H - 1; i > 0; i--)
		{
			USHORT count = 0;
			for (USHORT j = 0; j < W; j++)
			{
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
				if (k != i) field[i][j] = 0;
			}
			if (count < W) k--;
		}
		afterAnimationLine = false;
		numberOfIdenticalLines = 0;
		indexOfLastLine = 0;
		indexesOfIdLines.clear();
		falling_down(j, e);
	}

}

bool nOfSameStructsFn(Point *struct1, Point *struct2)
{
	USHORT nOfSameStructs = 0;// для подсчета на равенство структур a и e
	for (USHORT i = 0; i < 4; i++)
	{
		if (struct1[i].x == struct2[i].x && struct1[i].y == struct2[i].y)nOfSameStructs++;
	}
	if (nOfSameStructs == 4)return true;
	return false;
}


template <typename T>
string ToString(T tX)//для конвертации чисел в строки
{
	std::ostringstream oStream;
	oStream << tX;
	return oStream.str();
}