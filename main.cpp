#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "resource.h"
#include <windows.h>
#include <vector>
#include <thread>
#include <sstream>
//#include <string>
//#include < iomanip >
using namespace sf;
using namespace std;

//#define  LOGGER(v)  std::cout << #v << " = " << (v) << "\n";
Vector2u sizeOfWin;
USHORT colorNum = 1 + rand() % 9; // цвет
USHORT colorNum2 = 1 + rand() % 9; // цвет
USHORT colorNumTemp = 1 + rand() % 9;
Image *LoadImageFromResource(const unsigned short& ID, const char* type);
Texture *LoadTextureFromResource(const unsigned short& ID, const char* type);
Font *LoadFontFromResource(const unsigned short& ID, const char* type);
void fill_tetramino();
void fill_tetramino2();
void draw_3buttons(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3, Vector2f fsc);
void draw_3buttons2(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3, Vector2f fsc);
void draw_3buttons3(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3, Vector2f fsc);

void create_window_for_loading_screen(Sprite * scr, Sprite *Load);
Vector2f factorOfScaleFn(RenderWindow& win);
//Vector2i winPos;
//Vector2u winSizePrev;
bool enableResize = false;

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
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Vector2f scale);

void animation_2_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5,
	Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11,
	Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17,
	Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22, Vector2f scale);

void animation_2_lines_with_voidFn(RenderWindow& win, vector<USHORT> &vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Vector2f scale);

void animation_3_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_3lines_1, Sprite* spriteAn_3lines_2, Sprite* spriteAn_3lines_3, Sprite* spriteAn_3lines_4, Sprite* spriteAn_3lines_5,
	Sprite* spriteAn_3lines_6, Sprite* spriteAn_3lines_7, Sprite* spriteAn_3lines_8, Sprite* spriteAn_3lines_9, Sprite* spriteAn_3lines_10, Sprite* spriteAn_3lines_11,
	Sprite* spriteAn_3lines_12, Sprite* spriteAn_3lines_13, Sprite* spriteAn_3lines_14, Sprite* spriteAn_3lines_15, Sprite* spriteAn_3lines_16, Sprite* spriteAn_3lines_17,
	Sprite* spriteAn_3lines_18, Sprite* spriteAn_3lines_19, Sprite* spriteAn_3lines_20, Sprite* spriteAn_3lines_21, Sprite* spriteAn_3lines_22, Vector2f scale);

void animation_3_lines_with_voidFn(RenderWindow& win, vector<USHORT> &vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5,
	Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11,
	Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17,
	Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22, Vector2f scale);

void animation_4_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_4lines_1, Sprite* spriteAn_4lines_2, Sprite* spriteAn_4lines_3, Sprite* spriteAn_4lines_4, Sprite* spriteAn_4lines_5,
	Sprite* spriteAn_4lines_6, Sprite* spriteAn_4lines_7, Sprite* spriteAn_4lines_8, Sprite* spriteAn_4lines_9, Sprite* spriteAn_4lines_10, Sprite* spriteAn_4lines_11,
	Sprite* spriteAn_4lines_12, Sprite* spriteAn_4lines_13, Sprite* spriteAn_4lines_14, Sprite* spriteAn_4lines_15, Sprite* spriteAn_4lines_16, Sprite* spriteAn_4lines_17,
	Sprite* spriteAn_4lines_18, Sprite* spriteAn_4lines_19, Sprite* spriteAn_4lines_20, Sprite* spriteAn_4lines_21, Sprite* spriteAn_4lines_22, Vector2f scale);


void animation_fast_falling_1InRow_1RowFn(RenderWindow& win, Sprite* An_1_inRow_1Row_1, Sprite* An_1_inRow_1Row_2, Vector2f scale);
void animation_fast_falling_1InRow_2RowsFn(RenderWindow& win, Sprite* An_1_inRow_2Rows_1, Sprite* An_1_inRow_2Rows_2, Vector2f scale);
void animation_fast_falling_1InRow_3RowsFn(RenderWindow& win, Sprite* An_1_inRow_3Rows_1, Sprite* An_1_inRow_3Rows_2, Vector2f scale);
void animation_fast_falling_1InRow_4RowsFn(RenderWindow& win, Sprite* An_1_inRow_4Rows_1, Sprite* An_1_inRow_4Rows_2, Sprite* An_1_inRow_4Rows_3, Sprite* An_1_inRow_4Rows_4, Vector2f scale);
void animation_fast_falling_1InRow_5RowsFn(RenderWindow& win, Sprite* An_1_inRow_5Rows_1, Sprite* An_1_inRow_5Rows_2, Sprite* An_1_inRow_5Rows_3, Sprite* An_1_inRow_5Rows_4, Vector2f scale);
void animation_fast_falling_1InRow_6RowsFn(RenderWindow& win, Sprite* An_1_inRow_6Rows_1, Sprite* An_1_inRow_6Rows_2, Sprite* An_1_inRow_6Rows_3, Sprite* An_1_inRow_6Rows_4, Vector2f scale);
void animation_fast_falling_1InRow_7RowsFn(RenderWindow& win, Sprite* An_1_inRow_7Rows_1, Sprite* An_1_inRow_7Rows_2, Sprite* An_1_inRow_7Rows_3, Sprite* An_1_inRow_7Rows_4,
	Sprite* An_1_inRow_7Rows_5, Sprite* An_1_inRow_7Rows_6, Vector2f scale);
void animation_fast_falling_1InRow_8RowsFn(RenderWindow& win, Sprite* An_1_inRow_8Rows_1, Sprite* An_1_inRow_8Rows_2, Sprite* An_1_inRow_8Rows_3, Sprite* An_1_inRow_8Rows_4,
	Sprite* An_1_inRow_8Rows_5, Sprite* An_1_inRow_8Rows_6, Vector2f scale);
void animation_fast_falling_1InRow_9RowsFn(RenderWindow& win, Sprite* An_1_inRow_9Rows_1, Sprite* An_1_inRow_9Rows_2, Sprite* An_1_inRow_9Rows_3, Sprite* An_1_inRow_9Rows_4,
	Sprite* An_1_inRow_9Rows_5, Sprite* An_1_inRow_9Rows_6, Vector2f scale);
void animation_fast_falling_1InRow_10RowsFn(RenderWindow& win, Sprite* An_1_inRow_10Rows_1, Sprite* An_1_inRow_10Rows_2, Sprite* An_1_inRow_10Rows_3, Sprite* An_1_inRow_10Rows_4,
	Sprite* An_1_inRow_10Rows_5, Sprite* An_1_inRow_10Rows_6, Sprite* An_1_inRow_10Rows_7, Sprite* An_1_inRow_10Rows_8, Vector2f scale);
void animation_fast_falling_1InRow_11RowsFn(RenderWindow& win, Sprite* An_1_inRow_11Rows_1, Sprite* An_1_inRow_11Rows_2, Sprite* An_1_inRow_11Rows_3, Sprite* An_1_inRow_11Rows_4,
	Sprite* An_1_inRow_11Rows_5, Sprite* An_1_inRow_11Rows_6, Sprite* An_1_inRow_11Rows_7, Sprite* An_1_inRow_11Rows_8, Vector2f scale);
void animation_fast_falling_1InRow_12RowsFn(RenderWindow& win, Sprite* An_1_inRow_12Rows_1, Sprite* An_1_inRow_12Rows_2, Sprite* An_1_inRow_12Rows_3, Sprite* An_1_inRow_12Rows_4,
	Sprite* An_1_inRow_12Rows_5, Sprite* An_1_inRow_12Rows_6, Sprite* An_1_inRow_12Rows_7, Sprite* An_1_inRow_12Rows_8, Vector2f scale);
void animation_fast_falling_1InRow_13RowsFn(RenderWindow& win, Sprite* An_1_inRow_13Rows_1, Sprite* An_1_inRow_13Rows_2, Sprite* An_1_inRow_13Rows_3, Sprite* An_1_inRow_13Rows_4,
	Sprite* An_1_inRow_13Rows_5, Sprite* An_1_inRow_13Rows_6, Sprite* An_1_inRow_13Rows_7, Sprite* An_1_inRow_13Rows_8, Sprite* An_1_inRow_13Rows_9, Sprite* An_1_inRow_13Rows_10, Vector2f scale);
void animation_fast_falling_1InRow_14RowsFn(RenderWindow& win, Sprite* An_1_inRow_14Rows_1, Sprite* An_1_inRow_14Rows_2, Sprite* An_1_inRow_14Rows_3, Sprite* An_1_inRow_14Rows_4,
	Sprite* An_1_inRow_14Rows_5, Sprite* An_1_inRow_14Rows_6, Sprite* An_1_inRow_14Rows_7, Sprite* An_1_inRow_14Rows_8, Sprite* An_1_inRow_14Rows_9, Sprite* An_1_inRow_14Rows_10, Vector2f scale);
void animation_fast_falling_1InRow_15RowsFn(RenderWindow& win, Sprite* An_1_inRow_15Rows_1, Sprite* An_1_inRow_15Rows_2, Sprite* An_1_inRow_15Rows_3, Sprite* An_1_inRow_15Rows_4,
	Sprite* An_1_inRow_15Rows_5, Sprite* An_1_inRow_15Rows_6, Sprite* An_1_inRow_15Rows_7, Sprite* An_1_inRow_15Rows_8, Sprite* An_1_inRow_15Rows_9, Sprite* An_1_inRow_15Rows_10, Vector2f scale);
void animation_fast_falling_1InRow_16RowsFn(RenderWindow& win, Sprite* An_1_inRow_16Rows_1, Sprite* An_1_inRow_16Rows_2, Sprite* An_1_inRow_16Rows_3, Sprite* An_1_inRow_16Rows_4,
	Sprite* An_1_inRow_16Rows_5, Sprite* An_1_inRow_16Rows_6, Sprite* An_1_inRow_16Rows_7, Sprite* An_1_inRow_16Rows_8, Sprite* An_1_inRow_16Rows_9, Sprite* An_1_inRow_16Rows_10,
	Sprite* An_1_inRow_16Rows_11, Sprite* An_1_inRow_16Rows_12, Vector2f scale);
void animation_fast_falling_1InRow_17RowsFn(RenderWindow& win, Sprite* An_1_inRow_17Rows_1, Sprite* An_1_inRow_17Rows_2, Sprite* An_1_inRow_17Rows_3, Sprite* An_1_inRow_17Rows_4,
	Sprite* An_1_inRow_17Rows_5, Sprite* An_1_inRow_17Rows_6, Sprite* An_1_inRow_17Rows_7, Sprite* An_1_inRow_17Rows_8, Sprite* An_1_inRow_17Rows_9, Sprite* An_1_inRow_17Rows_10,
	Sprite* An_1_inRow_17Rows_11, Sprite* An_1_inRow_17Rows_12, Vector2f scale);

void animation_fast_falling_2InRow_1RowFn(RenderWindow& win, Sprite* An_2_inRow_1Row_1, Sprite* An_2_inRow_1Row_2, Vector2f scale);
void animation_fast_falling_2InRow_2RowsFn(RenderWindow& win, Sprite* An_2_inRow_2Rows_1, Sprite* An_2_inRow_2Rows_2, Vector2f scale);
void animation_fast_falling_2InRow_3RowsFn(RenderWindow& win, Sprite* An_2_inRow_3Rows_1, Sprite* An_2_inRow_3Rows_2, Vector2f scale);
void animation_fast_falling_2InRow_4RowsFn(RenderWindow& win, Sprite* An_2_inRow_4Rows_1, Sprite* An_2_inRow_4Rows_2, Sprite* An_2_inRow_4Rows_3, Sprite* An_2_inRow_4Rows_4, Vector2f scale);
void animation_fast_falling_2InRow_5RowsFn(RenderWindow& win, Sprite* An_2_inRow_5Rows_1, Sprite* An_2_inRow_5Rows_2, Sprite* An_2_inRow_5Rows_3, Sprite* An_2_inRow_5Rows_4, Vector2f scale);
void animation_fast_falling_2InRow_6RowsFn(RenderWindow& win, Sprite* An_2_inRow_6Rows_1, Sprite* An_2_inRow_6Rows_2, Sprite* An_2_inRow_6Rows_3, Sprite* An_2_inRow_6Rows_4, Vector2f scale);
void animation_fast_falling_2InRow_7RowsFn(RenderWindow& win, Sprite* An_2_inRow_7Rows_1, Sprite* An_2_inRow_7Rows_2, Sprite* An_2_inRow_7Rows_3, Sprite* An_2_inRow_7Rows_4, Sprite* An_2_inRow_7Rows_5, Sprite* An_2_inRow_7Rows_6, Vector2f scale);
void animation_fast_falling_2InRow_8RowsFn(RenderWindow& win, Sprite* An_2_inRow_8Rows_1, Sprite* An_2_inRow_8Rows_2, Sprite* An_2_inRow_8Rows_3, Sprite* An_2_inRow_8Rows_4, Sprite* An_2_inRow_8Rows_5, Sprite* An_2_inRow_8Rows_6, Vector2f scale);
void animation_fast_falling_2InRow_9RowsFn(RenderWindow& win, Sprite* An_2_inRow_9Rows_1, Sprite* An_2_inRow_9Rows_2, Sprite* An_2_inRow_9Rows_3, Sprite* An_2_inRow_9Rows_4, Sprite* An_2_inRow_9Rows_5, Sprite* An_2_inRow_9Rows_6, Vector2f scale);
void animation_fast_falling_2InRow_10RowsFn(RenderWindow& win, Sprite* An_2_inRow_10Rows_1, Sprite* An_2_inRow_10Rows_2, Sprite* An_2_inRow_10Rows_3, Sprite* An_2_inRow_10Rows_4, Sprite* An_2_inRow_10Rows_5, Sprite* An_2_inRow_10Rows_6, Sprite* An_2_inRow_10Rows_7, Sprite* An_2_inRow_10Rows_8, Vector2f scale);
void animation_fast_falling_2InRow_11RowsFn(RenderWindow& win, Sprite* An_2_inRow_11Rows_1, Sprite* An_2_inRow_11Rows_2, Sprite* An_2_inRow_11Rows_3, Sprite* An_2_inRow_11Rows_4, Sprite* An_2_inRow_11Rows_5, Sprite* An_2_inRow_11Rows_6, Sprite* An_2_inRow_11Rows_7, Sprite* An_2_inRow_11Rows_8, Vector2f scale);
void animation_fast_falling_2InRow_12RowsFn(RenderWindow& win, Sprite* An_2_inRow_12Rows_1, Sprite* An_2_inRow_12Rows_2, Sprite* An_2_inRow_12Rows_3, Sprite* An_2_inRow_12Rows_4, Sprite* An_2_inRow_12Rows_5, Sprite* An_2_inRow_12Rows_6, Sprite* An_2_inRow_12Rows_7, Sprite* An_2_inRow_12Rows_8, Vector2f scale);
void animation_fast_falling_2InRow_13RowsFn(RenderWindow& win, Sprite* An_2_inRow_13Rows_1, Sprite* An_2_inRow_13Rows_2, Sprite* An_2_inRow_13Rows_3, Sprite* An_2_inRow_13Rows_4, Sprite* An_2_inRow_13Rows_5, Sprite* An_2_inRow_13Rows_6, Sprite* An_2_inRow_13Rows_7, Sprite* An_2_inRow_13Rows_8, Sprite* An_2_inRow_13Rows_9, Sprite* An_2_inRow_13Rows_10, Vector2f scale);
void animation_fast_falling_2InRow_14RowsFn(RenderWindow& win, Sprite* An_2_inRow_14Rows_1, Sprite* An_2_inRow_14Rows_2, Sprite* An_2_inRow_14Rows_3, Sprite* An_2_inRow_14Rows_4, Sprite* An_2_inRow_14Rows_5, Sprite* An_2_inRow_14Rows_6, Sprite* An_2_inRow_14Rows_7, Sprite* An_2_inRow_14Rows_8, Sprite* An_2_inRow_14Rows_9, Sprite* An_2_inRow_14Rows_10, Vector2f scale);
void animation_fast_falling_2InRow_15RowsFn(RenderWindow& win, Sprite* An_2_inRow_15Rows_1, Sprite* An_2_inRow_15Rows_2, Sprite* An_2_inRow_15Rows_3, Sprite* An_2_inRow_15Rows_4, Sprite* An_2_inRow_15Rows_5, Sprite* An_2_inRow_15Rows_6, Sprite* An_2_inRow_15Rows_7, Sprite* An_2_inRow_15Rows_8, Sprite* An_2_inRow_15Rows_9, Sprite* An_2_inRow_15Rows_10, Vector2f scale);
void animation_fast_falling_2InRow_16RowsFn(RenderWindow& win, Sprite* An_2_inRow_16Rows_1, Sprite* An_2_inRow_16Rows_2, Sprite* An_2_inRow_16Rows_3, Sprite* An_2_inRow_16Rows_4, Sprite* An_2_inRow_16Rows_5, Sprite* An_2_inRow_16Rows_6, Sprite* An_2_inRow_16Rows_7, Sprite* An_2_inRow_16Rows_8, Sprite* An_2_inRow_16Rows_9, Sprite* An_2_inRow_16Rows_10, Sprite* An_2_inRow_16Rows_11, Sprite* An_2_inRow_16Rows_12, Vector2f scale);
void animation_fast_falling_2InRow_17RowsFn(RenderWindow& win, Sprite* An_2_inRow_17Rows_1, Sprite* An_2_inRow_17Rows_2, Sprite* An_2_inRow_17Rows_3, Sprite* An_2_inRow_17Rows_4, Sprite* An_2_inRow_17Rows_5, Sprite* An_2_inRow_17Rows_6, Sprite* An_2_inRow_17Rows_7, Sprite* An_2_inRow_17Rows_8, Sprite* An_2_inRow_17Rows_9, Sprite* An_2_inRow_17Rows_10, Sprite* An_2_inRow_17Rows_11, Sprite* An_2_inRow_17Rows_12, Vector2f scale);
void animation_fast_falling_3InRow_1RowFn(RenderWindow& win, Sprite* An_3_inRow_1Row_1, Sprite* An_3_inRow_1Row_2, Vector2f scale);
void animation_fast_falling_3InRow_2RowsFn(RenderWindow& win, Sprite* An_3_inRow_2Rows_1, Sprite* An_3_inRow_2Rows_2, Vector2f scale);
void animation_fast_falling_3InRow_3RowsFn(RenderWindow& win, Sprite* An_3_inRow_3Rows_1, Sprite* An_3_inRow_3Rows_2, Vector2f scale);
void animation_fast_falling_3InRow_4RowsFn(RenderWindow& win, Sprite* An_3_inRow_4Rows_1, Sprite* An_3_inRow_4Rows_2, Sprite* An_3_inRow_4Rows_3, Sprite* An_3_inRow_4Rows_4, Vector2f scale);
void animation_fast_falling_3InRow_5RowsFn(RenderWindow& win, Sprite* An_3_inRow_5Rows_1, Sprite* An_3_inRow_5Rows_2, Sprite* An_3_inRow_5Rows_3, Sprite* An_3_inRow_5Rows_4, Vector2f scale);
void animation_fast_falling_3InRow_6RowsFn(RenderWindow& win, Sprite* An_3_inRow_6Rows_1, Sprite* An_3_inRow_6Rows_2, Sprite* An_3_inRow_6Rows_3, Sprite* An_3_inRow_6Rows_4, Vector2f scale);
void animation_fast_falling_3InRow_7RowsFn(RenderWindow& win, Sprite* An_3_inRow_7Rows_1, Sprite* An_3_inRow_7Rows_2, Sprite* An_3_inRow_7Rows_3, Sprite* An_3_inRow_7Rows_4, Sprite* An_3_inRow_7Rows_5, Sprite* An_3_inRow_7Rows_6, Vector2f scale);
void animation_fast_falling_3InRow_8RowsFn(RenderWindow& win, Sprite* An_3_inRow_8Rows_1, Sprite* An_3_inRow_8Rows_2, Sprite* An_3_inRow_8Rows_3, Sprite* An_3_inRow_8Rows_4, Sprite* An_3_inRow_8Rows_5, Sprite* An_3_inRow_8Rows_6, Vector2f scale);
void animation_fast_falling_3InRow_9RowsFn(RenderWindow& win, Sprite* An_3_inRow_9Rows_1, Sprite* An_3_inRow_9Rows_2, Sprite* An_3_inRow_9Rows_3, Sprite* An_3_inRow_9Rows_4, Sprite* An_3_inRow_9Rows_5, Sprite* An_3_inRow_9Rows_6, Vector2f scale);
void animation_fast_falling_3InRow_10RowsFn(RenderWindow& win, Sprite* An_3_inRow_10Rows_1, Sprite* An_3_inRow_10Rows_2, Sprite* An_3_inRow_10Rows_3, Sprite* An_3_inRow_10Rows_4, Sprite* An_3_inRow_10Rows_5, Sprite* An_3_inRow_10Rows_6, Sprite* An_3_inRow_10Rows_7, Sprite* An_3_inRow_10Rows_8, Vector2f scale);
void animation_fast_falling_3InRow_11RowsFn(RenderWindow& win, Sprite* An_3_inRow_11Rows_1, Sprite* An_3_inRow_11Rows_2, Sprite* An_3_inRow_11Rows_3, Sprite* An_3_inRow_11Rows_4, Sprite* An_3_inRow_11Rows_5, Sprite* An_3_inRow_11Rows_6, Sprite* An_3_inRow_11Rows_7, Sprite* An_3_inRow_11Rows_8, Vector2f scale);
void animation_fast_falling_3InRow_12RowsFn(RenderWindow& win, Sprite* An_3_inRow_12Rows_1, Sprite* An_3_inRow_12Rows_2, Sprite* An_3_inRow_12Rows_3, Sprite* An_3_inRow_12Rows_4, Sprite* An_3_inRow_12Rows_5, Sprite* An_3_inRow_12Rows_6, Sprite* An_3_inRow_12Rows_7, Sprite* An_3_inRow_12Rows_8, Vector2f scale);
void animation_fast_falling_3InRow_13RowsFn(RenderWindow& win, Sprite* An_3_inRow_13Rows_1, Sprite* An_3_inRow_13Rows_2, Sprite* An_3_inRow_13Rows_3, Sprite* An_3_inRow_13Rows_4, Sprite* An_3_inRow_13Rows_5, Sprite* An_3_inRow_13Rows_6, Sprite* An_3_inRow_13Rows_7, Sprite* An_3_inRow_13Rows_8, Sprite* An_3_inRow_13Rows_9, Sprite* An_3_inRow_13Rows_10, Vector2f scale);
void animation_fast_falling_3InRow_14RowsFn(RenderWindow& win, Sprite* An_3_inRow_14Rows_1, Sprite* An_3_inRow_14Rows_2, Sprite* An_3_inRow_14Rows_3, Sprite* An_3_inRow_14Rows_4, Sprite* An_3_inRow_14Rows_5, Sprite* An_3_inRow_14Rows_6, Sprite* An_3_inRow_14Rows_7, Sprite* An_3_inRow_14Rows_8, Sprite* An_3_inRow_14Rows_9, Sprite* An_3_inRow_14Rows_10, Vector2f scale);
void animation_fast_falling_3InRow_15RowsFn(RenderWindow& win, Sprite* An_3_inRow_15Rows_1, Sprite* An_3_inRow_15Rows_2, Sprite* An_3_inRow_15Rows_3, Sprite* An_3_inRow_15Rows_4, Sprite* An_3_inRow_15Rows_5, Sprite* An_3_inRow_15Rows_6, Sprite* An_3_inRow_15Rows_7, Sprite* An_3_inRow_15Rows_8, Sprite* An_3_inRow_15Rows_9, Sprite* An_3_inRow_15Rows_10, Vector2f scale);
void animation_fast_falling_3InRow_16RowsFn(RenderWindow& win, Sprite* An_3_inRow_16Rows_1, Sprite* An_3_inRow_16Rows_2, Sprite* An_3_inRow_16Rows_3, Sprite* An_3_inRow_16Rows_4,
	Sprite* An_3_inRow_16Rows_5, Sprite* An_3_inRow_16Rows_6, Sprite* An_3_inRow_16Rows_7, Sprite* An_3_inRow_16Rows_8, Sprite* An_3_inRow_16Rows_9, Sprite* An_3_inRow_16Rows_10,
	Sprite* An_3_inRow_16Rows_11, Sprite* An_3_inRow_16Rows_12, Vector2f scale);
void animation_fast_falling_3InRow_17RowsFn(RenderWindow& win, Sprite* An_3_inRow_17Rows_1, Sprite* An_3_inRow_17Rows_2, Sprite* An_3_inRow_17Rows_3, Sprite* An_3_inRow_17Rows_4, Sprite* An_3_inRow_17Rows_5, Sprite* An_3_inRow_17Rows_6, Sprite* An_3_inRow_17Rows_7, Sprite* An_3_inRow_17Rows_8, Sprite* An_3_inRow_17Rows_9, Sprite* An_3_inRow_17Rows_10, Sprite* An_3_inRow_17Rows_11, Sprite* An_3_inRow_17Rows_12, Vector2f scale);
void animation_fast_falling_3InRow_18RowsFn(RenderWindow& win, Sprite* An_3_inRow_18Rows_1, Sprite* An_3_inRow_18Rows_2, Sprite* An_3_inRow_18Rows_3, Sprite* An_3_inRow_18Rows_4, Sprite* An_3_inRow_18Rows_5, Sprite* An_3_inRow_18Rows_6, Sprite* An_3_inRow_18Rows_7, Sprite* An_3_inRow_18Rows_8, Sprite* An_3_inRow_18Rows_9, Sprite* An_3_inRow_18Rows_10, Sprite* An_3_inRow_18Rows_11, Sprite* An_3_inRow_18Rows_12, Vector2f scale);
void animation_fast_falling_4InRow_1RowFn(RenderWindow& win, Sprite* An_4_inRow_1Row_1, Sprite* An_4_inRow_1Row_2, Vector2f scale);
void animation_fast_falling_4InRow_2RowsFn(RenderWindow& win, Sprite* An_4_inRow_2Rows_1, Sprite* An_4_inRow_2Rows_2, Vector2f scale);
void animation_fast_falling_4InRow_3RowsFn(RenderWindow& win, Sprite* An_4_inRow_3Rows_1, Sprite* An_4_inRow_3Rows_2, Vector2f scale);
void animation_fast_falling_4InRow_4RowsFn(RenderWindow& win, Sprite* An_4_inRow_4Rows_1, Sprite* An_4_inRow_4Rows_2, Sprite* An_4_inRow_4Rows_3, Sprite* An_4_inRow_4Rows_4, Vector2f scale);
void animation_fast_falling_4InRow_5RowsFn(RenderWindow& win, Sprite* An_4_inRow_5Rows_1, Sprite* An_4_inRow_5Rows_2, Sprite* An_4_inRow_5Rows_3, Sprite* An_4_inRow_5Rows_4, Vector2f scale);
void animation_fast_falling_4InRow_6RowsFn(RenderWindow& win, Sprite* An_4_inRow_6Rows_1, Sprite* An_4_inRow_6Rows_2, Sprite* An_4_inRow_6Rows_3, Sprite* An_4_inRow_6Rows_4, Vector2f scale);
void animation_fast_falling_4InRow_7RowsFn(RenderWindow& win, Sprite* An_4_inRow_7Rows_1, Sprite* An_4_inRow_7Rows_2, Sprite* An_4_inRow_7Rows_3, Sprite* An_4_inRow_7Rows_4, Sprite* An_4_inRow_7Rows_5, Sprite* An_4_inRow_7Rows_6, Vector2f scale);
void animation_fast_falling_4InRow_8RowsFn(RenderWindow& win, Sprite* An_4_inRow_8Rows_1, Sprite* An_4_inRow_8Rows_2, Sprite* An_4_inRow_8Rows_3, Sprite* An_4_inRow_8Rows_4, Sprite* An_4_inRow_8Rows_5, Sprite* An_4_inRow_8Rows_6, Vector2f scale);
void animation_fast_falling_4InRow_9RowsFn(RenderWindow& win, Sprite* An_4_inRow_9Rows_1, Sprite* An_4_inRow_9Rows_2, Sprite* An_4_inRow_9Rows_3, Sprite* An_4_inRow_9Rows_4, Sprite* An_4_inRow_9Rows_5, Sprite* An_4_inRow_9Rows_6, Vector2f scale);
void animation_fast_falling_4InRow_10RowsFn(RenderWindow& win, Sprite* An_4_inRow_10Rows_1, Sprite* An_4_inRow_10Rows_2, Sprite* An_4_inRow_10Rows_3, Sprite* An_4_inRow_10Rows_4, Sprite* An_4_inRow_10Rows_5, Sprite* An_4_inRow_10Rows_6, Sprite* An_4_inRow_10Rows_7, Sprite* An_4_inRow_10Rows_8, Vector2f scale);
void animation_fast_falling_4InRow_11RowsFn(RenderWindow& win, Sprite* An_4_inRow_11Rows_1, Sprite* An_4_inRow_11Rows_2, Sprite* An_4_inRow_11Rows_3, Sprite* An_4_inRow_11Rows_4, Sprite* An_4_inRow_11Rows_5, Sprite* An_4_inRow_11Rows_6, Sprite* An_4_inRow_11Rows_7, Sprite* An_4_inRow_11Rows_8, Vector2f scale);
void animation_fast_falling_4InRow_12RowsFn(RenderWindow& win, Sprite* An_4_inRow_12Rows_1, Sprite* An_4_inRow_12Rows_2, Sprite* An_4_inRow_12Rows_3, Sprite* An_4_inRow_12Rows_4, Sprite* An_4_inRow_12Rows_5, Sprite* An_4_inRow_12Rows_6, Sprite* An_4_inRow_12Rows_7, Sprite* An_4_inRow_12Rows_8, Vector2f scale);
void animation_fast_falling_4InRow_13RowsFn(RenderWindow& win, Sprite* An_4_inRow_13Rows_1, Sprite* An_4_inRow_13Rows_2, Sprite* An_4_inRow_13Rows_3, Sprite* An_4_inRow_13Rows_4, Sprite* An_4_inRow_13Rows_5, Sprite* An_4_inRow_13Rows_6, Sprite* An_4_inRow_13Rows_7, Sprite* An_4_inRow_13Rows_8, Sprite* An_4_inRow_13Rows_9, Sprite* An_4_inRow_13Rows_10, Vector2f scale);
void animation_fast_falling_4InRow_14RowsFn(RenderWindow& win, Sprite* An_4_inRow_14Rows_1, Sprite* An_4_inRow_14Rows_2, Sprite* An_4_inRow_14Rows_3, Sprite* An_4_inRow_14Rows_4, Sprite* An_4_inRow_14Rows_5, Sprite* An_4_inRow_14Rows_6, Sprite* An_4_inRow_14Rows_7, Sprite* An_4_inRow_14Rows_8, Sprite* An_4_inRow_14Rows_9, Sprite* An_4_inRow_14Rows_10, Vector2f scale);
void animation_fast_falling_4InRow_15RowsFn(RenderWindow& win, Sprite* An_4_inRow_15Rows_1, Sprite* An_4_inRow_15Rows_2, Sprite* An_4_inRow_15Rows_3, Sprite* An_4_inRow_15Rows_4, Sprite* An_4_inRow_15Rows_5, Sprite* An_4_inRow_15Rows_6, Sprite* An_4_inRow_15Rows_7, Sprite* An_4_inRow_15Rows_8, Sprite* An_4_inRow_15Rows_9, Sprite* An_4_inRow_15Rows_10, Vector2f scale);
void animation_fast_falling_4InRow_16RowsFn(RenderWindow& win, Sprite* An_4_inRow_16Rows_1, Sprite* An_4_inRow_16Rows_2, Sprite* An_4_inRow_16Rows_3, Sprite* An_4_inRow_16Rows_4, Sprite* An_4_inRow_16Rows_5, Sprite* An_4_inRow_16Rows_6, Sprite* An_4_inRow_16Rows_7, Sprite* An_4_inRow_16Rows_8, Sprite* An_4_inRow_16Rows_9, Sprite* An_4_inRow_16Rows_10, Sprite* An_4_inRow_16Rows_11, Sprite* An_4_inRow_16Rows_12, Vector2f scale);
void animation_fast_falling_4InRow_17RowsFn(RenderWindow& win, Sprite* An_4_inRow_17Rows_1, Sprite* An_4_inRow_17Rows_2, Sprite* An_4_inRow_17Rows_3, Sprite* An_4_inRow_17Rows_4, Sprite* An_4_inRow_17Rows_5, Sprite* An_4_inRow_17Rows_6, Sprite* An_4_inRow_17Rows_7, Sprite* An_4_inRow_17Rows_8, Sprite* An_4_inRow_17Rows_9, Sprite* An_4_inRow_17Rows_10, Sprite* An_4_inRow_17Rows_11, Sprite* An_4_inRow_17Rows_12, Vector2f scale);
void animation_fast_falling_4InRow_18RowsFn(RenderWindow& win, Sprite* An_4_inRow_18Rows_1, Sprite* An_4_inRow_18Rows_2, Sprite* An_4_inRow_18Rows_3, Sprite* An_4_inRow_18Rows_4, Sprite* An_4_inRow_18Rows_5, Sprite* An_4_inRow_18Rows_6, Sprite* An_4_inRow_18Rows_7, Sprite* An_4_inRow_18Rows_8, Sprite* An_4_inRow_18Rows_9, Sprite* An_4_inRow_18Rows_10, Sprite* An_4_inRow_18Rows_11, Sprite* An_4_inRow_18Rows_12, Vector2f scale);

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

bool for_loading_scr = true;
Clock* loading_clock = new Clock();

int main()
//int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	Texture *loading_screen_tex = LoadTextureFromResource(IDB_PNG690, "PNG");
	//loading_screen_tex->setSmooth(true);
	Sprite *sprite_loading_screen = new Sprite(*loading_screen_tex);
	Texture *LOADING = LoadTextureFromResource(IDB_PNG210, "PNG");
	Sprite* sprite_LOADING = new Sprite(*LOADING);
	thread* thr1 = new thread(create_window_for_loading_screen, sprite_loading_screen, sprite_LOADING);
	
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
	Texture *sqtex = new Texture, /**tex_table = new Texture,*/ *tex_table2 = new Texture;
	Texture* tex_background, * button_start_st1, * button_start_st2, * button_start_st3, * button_newgame_st1, * button_newgame_st2, * button_newgame_st3,
		* button_options_st1, * button_options_st2, * button_options_st3, * button_left_st1, * button_left_st2, * button_left_st3, * button_right_st1, * button_right_st2, * button_right_st3,
		* button_middle_restore_st1, * button_middle_restore_st2, * button_middle_restore_st3, * button_pause_st1, /** button_pause_st2,*/ * button_pause_st3, * button_pause_st4,
		/** button_soundOff_st1, * button_soundOff_st2, * button_soundOff_st3,*/ * left_frame, * right_frame, * right_frame_bottom, * ays_frame, * ays_question, * ays_yes1st, * ays_yes2st, * ays_no1st, * ays_no2st,
		/** button_resume_st1, * button_resume_st2, * button_resume_st3, * button_musicOff_st1, * button_musicOff_st2, * button_musicOff_st3,*/ * button_musicOn_st1, /** button_musicOn_st2,*/ * button_musicOn_st3, * button_musicOn_st4,
		* button_soundOn_st1, /** button_soundOn_st2,*/ * button_soundOn_st3, * button_soundOn_st4, * I_red, * S_red, * Z_red, * T_red, * L_red, * J_red, * O_red, * I_blue, * S_blue, * Z_blue, * T_blue, * L_blue,
		* J_blue, * O_blue, * I_black, * S_black, * Z_black, * T_black, * L_black, * J_black, * O_black, * I_brown, * S_brown, * Z_brown, * T_brown, * L_brown, * J_brown, * O_brown,
		* I_orange, * S_orange, * Z_orange, * T_orange, * L_orange, * J_orange, * O_orange, * I_green, * S_green, * Z_green, * T_green, * L_green, * J_green, * O_green,
		* I_purple, * S_purple, * Z_purple, * T_purple, * L_purple, * J_purple, * O_purple, * I_pink, * S_pink, * Z_pink, * T_pink, * L_pink, * J_pink, * O_pink,
		* I_yellow, * S_yellow, * Z_yellow, * T_yellow, * L_yellow, * J_yellow, * O_yellow, * myCursor,
		/** An_1line_1, * An_1line_2, * An_1line_3, * An_1line_4, * An_1line_5, * An_1line_6, * An_1line_7, * An_1line_8, * An_1line_9, * An_1line_10, * An_1line_11,
		* An_1line_12, * An_1line_13, * An_1line_14, * An_1line_15, * An_1line_16, * An_1line_17, * An_1line_18, * An_1line_19, * An_1line_20, * An_1line_21, * An_1line_22,*/
		* An_2lines_1, * An_2lines_2, * An_2lines_3, * An_2lines_4, * An_2lines_5, * An_2lines_6, * An_2lines_7, * An_2lines_8, * An_2lines_9, * An_2lines_10,
		* An_2lines_11, * An_2lines_12, * An_2lines_13, * An_2lines_14, * An_2lines_15, * An_2lines_16, * An_2lines_17, * An_2lines_18, * An_2lines_19, * An_2lines_20,
		* An_2lines_21, * An_2lines_22,
		* An_3lines_1, * An_3lines_2, * An_3lines_3, * An_3lines_4, * An_3lines_5, * An_3lines_6, * An_3lines_7, * An_3lines_8, * An_3lines_9, * An_3lines_10,
		* An_3lines_11, * An_3lines_12, * An_3lines_13, * An_3lines_14, * An_3lines_15, * An_3lines_16, * An_3lines_17, * An_3lines_18, * An_3lines_19,
		* An_3lines_20, * An_3lines_21, * An_3lines_22,
		* An_4lines_1, * An_4lines_2, * An_4lines_3, * An_4lines_4, * An_4lines_5, * An_4lines_6, * An_4lines_7, * An_4lines_8, * An_4lines_9, * An_4lines_10,
		* An_4lines_11, * An_4lines_12, * An_4lines_13, * An_4lines_14, * An_4lines_15, * An_4lines_16, * An_4lines_17, * An_4lines_18, * An_4lines_19, * An_4lines_20,
		* An_4lines_21, * An_4lines_22, * AnFF1inRow1To4Rows, * AnFF1inRow5To8Rows, * AnFF1inRow9To12Rows, * AnFF1inRow13To15Rows, * AnFF1inRow16To17Rows,
		* AnFF2inRow1To6Rows, *AnFF2inRow7To10Rows, *AnFF2inRow11To13Rows, *AnFF2inRow14To15Rows, *AnFF2inRow16To17Rows, *AnFF3inRow1To4Rows, *AnFF3inRow5To8Rows, 
		*AnFF3inRow9To11Rows, *AnFF3inRow12To13Rows, *AnFF3inRow14To15Rows, *AnFF3inRow16Rows, *AnFF3inRow17Rows, *AnFF3inRow18Rows, *AnFF4inRow1To4Rows, *AnFF4inRow5To8Rows,
		*AnFF4inRow9To11Rows, *AnFF4inRow12To13Rows, *AnFF4inRow14Rows, *AnFF4inRow15Rows, *AnFF4inRow16Rows, *AnFF4inRow17Rows, *AnFF4inRow18Rows, *AnBurning1Row,
		*AnBurning2Rows, *AnBurning3Rows, *AnBurning4Rows;
		


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
	//button_pause_st2 = LoadTextureFromResource(IDB_PNG27, "PNG");
	button_pause_st3 = LoadTextureFromResource(IDB_PNG28, "PNG");
	button_pause_st4 = LoadTextureFromResource(IDB_PNG53, "PNG");

	//button_resume_st1 = LoadTextureFromResource(IDB_PNG41, "PNG");
	//button_resume_st2 = LoadTextureFromResource(IDB_PNG42, "PNG");
	//button_resume_st3 = LoadTextureFromResource(IDB_PNG43, "PNG");

	//button_soundOff_st1 = LoadTextureFromResource(IDB_PNG29, "PNG");
	//button_soundOff_st2 = LoadTextureFromResource(IDB_PNG30, "PNG");
	//button_soundOff_st3 = LoadTextureFromResource(IDB_PNG31, "PNG");

	button_soundOn_st1 = LoadTextureFromResource(IDB_PNG44, "PNG");
	//button_soundOn_st2 = LoadTextureFromResource(IDB_PNG45, "PNG");
	button_soundOn_st3 = LoadTextureFromResource(IDB_PNG46, "PNG");
	button_soundOn_st4 = LoadTextureFromResource(IDB_PNG54, "PNG");

	button_musicOn_st1 = LoadTextureFromResource(IDB_PNG47, "PNG");
	//button_musicOn_st2 = LoadTextureFromResource(IDB_PNG48, "PNG");
	button_musicOn_st3 = LoadTextureFromResource(IDB_PNG49, "PNG");
	button_musicOn_st4 = LoadTextureFromResource(IDB_PNG55, "PNG");

	//button_musicOff_st1 = LoadTextureFromResource(IDB_PNG50, "PNG");
	//button_musicOff_st2 = LoadTextureFromResource(IDB_PNG51, "PNG");
	//button_musicOff_st3 = LoadTextureFromResource(IDB_PNG52, "PNG");

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

	AnFF1inRow1To4Rows = LoadTextureFromResource(IDB_PNG209, "PNG");
	AnFF1inRow5To8Rows = LoadTextureFromResource(IDB_PNG211, "PNG");
	AnFF1inRow9To12Rows = LoadTextureFromResource(IDB_PNG212, "PNG");
	AnFF1inRow13To15Rows = LoadTextureFromResource(IDB_PNG213, "PNG");
	AnFF1inRow16To17Rows = LoadTextureFromResource(IDB_PNG214, "PNG");
	AnFF2inRow1To6Rows = LoadTextureFromResource(IDB_PNG215, "PNG");
	AnFF2inRow7To10Rows = LoadTextureFromResource(IDB_PNG216, "PNG");
	AnFF2inRow11To13Rows = LoadTextureFromResource(IDB_PNG217, "PNG");
	AnFF2inRow14To15Rows = LoadTextureFromResource(IDB_PNG218, "PNG");
	AnFF2inRow16To17Rows = LoadTextureFromResource(IDB_PNG219, "PNG");
	AnFF3inRow1To4Rows = LoadTextureFromResource(IDB_PNG220, "PNG");
	AnFF3inRow5To8Rows = LoadTextureFromResource(IDB_PNG221, "PNG");
	AnFF3inRow9To11Rows = LoadTextureFromResource(IDB_PNG222, "PNG");
	AnFF3inRow12To13Rows = LoadTextureFromResource(IDB_PNG223, "PNG");
	AnFF3inRow14To15Rows = LoadTextureFromResource(IDB_PNG224, "PNG");
	AnFF3inRow16Rows = LoadTextureFromResource(IDB_PNG225, "PNG");
	AnFF3inRow17Rows = LoadTextureFromResource(IDB_PNG226, "PNG");
	AnFF3inRow18Rows = LoadTextureFromResource(IDB_PNG227, "PNG");
	AnFF4inRow1To4Rows = LoadTextureFromResource(IDB_PNG228, "PNG");
	AnFF4inRow5To8Rows = LoadTextureFromResource(IDB_PNG230, "PNG");
	AnFF4inRow9To11Rows = LoadTextureFromResource(IDB_PNG231, "PNG");
	AnFF4inRow12To13Rows = LoadTextureFromResource(IDB_PNG232, "PNG");
	AnFF4inRow14Rows = LoadTextureFromResource(IDB_PNG233, "PNG");
	AnFF4inRow15Rows = LoadTextureFromResource(IDB_PNG234, "PNG");
	AnFF4inRow16Rows = LoadTextureFromResource(IDB_PNG235, "PNG");
	AnFF4inRow17Rows = LoadTextureFromResource(IDB_PNG236, "PNG");
	AnFF4inRow18Rows = LoadTextureFromResource(IDB_PNG693, "PNG");

	AnBurning1Row = LoadTextureFromResource(IDB_PNG229, "PNG");
	AnBurning2Rows = LoadTextureFromResource(IDB_PNG237, "PNG");
	AnBurning3Rows = LoadTextureFromResource(IDB_PNG238, "PNG");
	AnBurning4Rows = LoadTextureFromResource(IDB_PNG239, "PNG");
	//loading_screen_tex = LoadTextureFromResource(IDB_PNG690, "PNG");
	
	Image /**img_table,*/ *tetramino /*,*img_myCursor*/;
	//img_table = LoadImageFromResource(IDB_PNG5, "PNG");

	//tex_table->loadFromImage(*img_table);
	tex_table2 = LoadTextureFromResource(IDB_PNG5, "PNG");
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
	Sprite* sprite = new Sprite(*sqtex), * sprite_background = new Sprite(*tex_background), /** sprite_table = new Sprite(*tex_table),*/ * sprite_table2 = new Sprite(*tex_table2),
		* sprite_button_start_st1 = new Sprite(*button_start_st1), * sprite_button_start_st2 = new Sprite(*button_start_st2), * sprite_button_start_st3 = new Sprite(*button_start_st3),
		* sprite_button_newgame_st1 = new Sprite(*button_newgame_st1), * sprite_button_newgame_st2 = new Sprite(*button_newgame_st2), * sprite_button_newgame_st3 = new Sprite(*button_newgame_st3),
		* sprite_button_options_st1 = new Sprite(*button_options_st1), * sprite_button_options_st2 = new Sprite(*button_options_st2), * sprite_button_options_st3 = new Sprite(*button_options_st3),
		* sprite_button_left_st1 = new Sprite(*button_left_st1), * sprite_button_left_st2 = new Sprite(*button_left_st2), * sprite_button_left_st3 = new Sprite(*button_left_st3),
		* sprite_button_right_st1 = new Sprite(*button_right_st1), * sprite_button_right_st2 = new Sprite(*button_right_st2), * sprite_button_right_st3 = new Sprite(*button_right_st3),
		* sprite_button_middle_restore_st1 = new Sprite(*button_middle_restore_st1), * sprite_button_middle_restore_st2 = new Sprite(*button_middle_restore_st2), * sprite_button_middle_restore_st3 = new Sprite(*button_middle_restore_st3),
		* sprite_button_pause_st1 = new Sprite(*button_pause_st1), /** sprite_button_pause_st2 = new Sprite(*button_pause_st2),*/ * sprite_button_pause_st3 = new Sprite(*button_pause_st3),
		* sprite_button_pause_st4 = new Sprite(*button_pause_st4),
		/** sprite_button_soundOff_st1 = new Sprite(*button_soundOff_st1), * sprite_button_soundOff_st2 = new Sprite(*button_soundOff_st2), * sprite_button_soundOff_st3 = new Sprite(*button_soundOff_st3),*/
		* sprite_left_frame = new Sprite(*left_frame), * sprite_right_frame = new Sprite(*right_frame),
		* sprite_right_frame_bottom = new Sprite(*right_frame_bottom), * sprite_ays_frame = new Sprite(*ays_frame), * sprite_ays_question = new Sprite(*ays_question), * sprite_ays_yes1st = new Sprite(*ays_yes1st),
		* sprite_ays_yes2st = new Sprite(*ays_yes2st), * sprite_ays_no1st = new Sprite(*ays_no1st), * sprite_ays_no2st = new Sprite(*ays_no2st),
		/** sprite_button_resume_st1 = new Sprite(*button_resume_st1), * sprite_button_resume_st2 = new Sprite(*button_resume_st2), * sprite_button_resume_st3 = new Sprite(*button_resume_st3),*/
		* sprite_button_soundOn_st1 = new Sprite(*button_soundOn_st1), /** sprite_button_soundOn_st2 = new Sprite(*button_soundOn_st2),*/ * sprite_button_soundOn_st3 = new Sprite(*button_soundOn_st3),
		* sprite_button_soundOn_st4 = new Sprite(*button_soundOn_st4),
		* sprite_button_musicOn_st1 = new Sprite(*button_musicOn_st1),/* * sprite_button_musicOn_st2 = new Sprite(*button_musicOn_st2),*/ * sprite_button_musicOn_st3 = new Sprite(*button_musicOn_st3),
		* sprite_button_musicOn_st4 = new Sprite(*button_musicOn_st4),
		/** sprite_button_musicOff_st1 = new Sprite(*button_musicOff_st1), * sprite_button_musicOff_st2 = new Sprite(*button_musicOff_st2), * sprite_button_musicOff_st3 = new Sprite(*button_musicOff_st3),*/

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

* spriteAn_1line_1 = new Sprite(*AnBurning1Row, IntRect(0, 0, 480, 137)), * spriteAn_1line_2 = new Sprite(*AnBurning1Row, IntRect(0, 137, 480, 132)), * spriteAn_1line_3 = new Sprite(*AnBurning1Row, IntRect(0, 269, 480, 127)), * spriteAn_1line_4 = new Sprite(*AnBurning1Row, IntRect(0, 396, 480, 123)),
* spriteAn_1line_5 = new Sprite(*AnBurning1Row, IntRect(0, 519, 479, 118)), * spriteAn_1line_6 = new Sprite(*AnBurning1Row, IntRect(0, 637, 478, 114)), * spriteAn_1line_7 = new Sprite(*AnBurning1Row, IntRect(0, 751, 477, 109)), * spriteAn_1line_8 = new Sprite(*AnBurning1Row, IntRect(0, 965, 476, 105)),
* spriteAn_1line_9 = new Sprite(*AnBurning1Row, IntRect(0, 860, 477, 105)), * spriteAn_1line_10 = new Sprite(*AnBurning1Row, IntRect(0, 1070, 449, 105)), * spriteAn_1line_11 = new Sprite(*AnBurning1Row, IntRect(0, 1175, 423, 105)), * spriteAn_1line_12 = new Sprite(*AnBurning1Row, IntRect(0, 1280, 395, 105)),
* spriteAn_1line_13 = new Sprite(*AnBurning1Row, IntRect(0, 1385, 369, 105)), * spriteAn_1line_14 = new Sprite(*AnBurning1Row, IntRect(0, 1490, 341, 105)), * spriteAn_1line_15 = new Sprite(*AnBurning1Row, IntRect(0, 1595, 314, 105)), * spriteAn_1line_16 = new Sprite(*AnBurning1Row, IntRect(0, 1700, 287, 105)),
* spriteAn_1line_17 = new Sprite(*AnBurning1Row, IntRect(0, 1805, 258, 103)), * spriteAn_1line_18 = new Sprite(*AnBurning1Row, IntRect(258, 1805, 231, 103)), * spriteAn_1line_19 = new Sprite(*AnBurning1Row, IntRect(287, 1700, 204, 103)), * spriteAn_1line_20 = new Sprite(*AnBurning1Row, IntRect(314, 1595, 173, 101)),
* spriteAn_1line_21 = new Sprite(*AnBurning1Row, IntRect(341, 1490, 144, 97)), * spriteAn_1line_22 = new Sprite(*AnBurning1Row, IntRect(369, 1385, 110, 89)),

* spriteAn_2lines_1 = new Sprite(*AnBurning2Rows, IntRect(0, 0, 482, 169)), * spriteAn_2lines_2 = new Sprite(*AnBurning2Rows, IntRect(0, 169, 482, 161)), * spriteAn_2lines_3 = new Sprite(*AnBurning2Rows, IntRect(0, 330, 481, 151)), * spriteAn_2lines_4 = new Sprite(*AnBurning2Rows, IntRect(0, 481, 481, 142)),
* spriteAn_2lines_5 = new Sprite(*AnBurning2Rows, IntRect(0, 623, 480, 132)), * spriteAn_2lines_6 = new Sprite(*AnBurning2Rows, IntRect(0, 755, 480, 123)), * spriteAn_2lines_7 = new Sprite(*AnBurning2Rows, IntRect(0, 878, 478, 114)), * spriteAn_2lines_8 = new Sprite(*AnBurning2Rows, IntRect(0, 992, 476, 105)),
* spriteAn_2lines_9 = new Sprite(*AnBurning2Rows, IntRect(0, 1097, 476, 105)), * spriteAn_2lines_10 = new Sprite(*AnBurning2Rows, IntRect(0, 1202, 448, 105)), * spriteAn_2lines_11 = new Sprite(*AnBurning2Rows, IntRect(0, 1307, 422, 105)), * spriteAn_2lines_12 = new Sprite(*AnBurning2Rows, IntRect(0, 1412, 394, 105)),
* spriteAn_2lines_13 = new Sprite(*AnBurning2Rows, IntRect(0, 1517, 368, 105)), * spriteAn_2lines_14 = new Sprite(*AnBurning2Rows, IntRect(0, 1622, 340, 105)), * spriteAn_2lines_15 = new Sprite(*AnBurning2Rows, IntRect(0, 1727, 314, 105)), * spriteAn_2lines_16 = new Sprite(*AnBurning2Rows, IntRect(0, 1832, 286, 105)),
* spriteAn_2lines_17 = new Sprite(*AnBurning2Rows, IntRect(0, 1937, 258, 103)), * spriteAn_2lines_18 = new Sprite(*AnBurning2Rows, IntRect(258, 1937, 230, 103)), * spriteAn_2lines_19 = new Sprite(*AnBurning2Rows, IntRect(286, 1832, 203, 103)), * spriteAn_2lines_20 = new Sprite(*AnBurning2Rows, IntRect(314, 1727, 173, 101)),
* spriteAn_2lines_21 = new Sprite(*AnBurning2Rows, IntRect(340, 1622, 143, 97)), * spriteAn_2lines_22 = new Sprite(*AnBurning2Rows, IntRect(368, 1517, 110, 89)),

* spriteAn_3lines_1 = new Sprite(*AnBurning3Rows, IntRect(0, 0, 482, 203)), * spriteAn_3lines_2 = new Sprite(*AnBurning3Rows, IntRect(482, 0, 482, 189)), * spriteAn_3lines_3 = new Sprite(*AnBurning3Rows, IntRect(964, 0, 482, 175)),
* spriteAn_3lines_4 = new Sprite(*AnBurning3Rows, IntRect(1446, 0, 482, 161)), * spriteAn_3lines_5 = new Sprite(*AnBurning3Rows, IntRect(1446, 161, 481, 147)), * spriteAn_3lines_6 = new Sprite(*AnBurning3Rows, IntRect(964, 175, 480, 133)),
* spriteAn_3lines_7 = new Sprite(*AnBurning3Rows, IntRect(482, 189, 479, 119)), * spriteAn_3lines_8 = new Sprite(*AnBurning3Rows, IntRect(0, 203, 476, 105)), * spriteAn_3lines_9 = new Sprite(*AnBurning3Rows, IntRect(0, 308, 476, 105)),
* spriteAn_3lines_10 = new Sprite(*AnBurning3Rows, IntRect(476, 308, 448, 105)), * spriteAn_3lines_11 = new Sprite(*AnBurning3Rows, IntRect(924, 308, 422,	105)), * spriteAn_3lines_12 = new Sprite(*AnBurning3Rows, IntRect(1346, 308, 394, 105)),
* spriteAn_3lines_13 = new Sprite(*AnBurning3Rows, IntRect(0, 413, 368, 105)), * spriteAn_3lines_14 = new Sprite(*AnBurning3Rows, IntRect(368, 413, 340, 105)), * spriteAn_3lines_15 = new Sprite(*AnBurning3Rows, IntRect(708, 413, 314, 105)),
* spriteAn_3lines_16 = new Sprite(*AnBurning3Rows, IntRect(1740, 308, 286, 105)), * spriteAn_3lines_17 = new Sprite(*AnBurning3Rows, IntRect(1022, 413, 258, 103)), * spriteAn_3lines_18 = new Sprite(*AnBurning3Rows, IntRect(1280, 413, 230, 103)),
* spriteAn_3lines_19 = new Sprite(*AnBurning3Rows, IntRect(1510, 413, 204, 103)), * spriteAn_3lines_20 = new Sprite(*AnBurning3Rows, IntRect(1714, 413, 173, 101)), * spriteAn_3lines_21 = new Sprite(*AnBurning3Rows, IntRect(1887, 413, 143, 97)),
* spriteAn_3lines_22 = new Sprite(*AnBurning3Rows, IntRect(1927, 161, 110, 89)),

* spriteAn_4lines_1 = new Sprite(*AnBurning4Rows, IntRect(0, 0, 482, 237)), * spriteAn_4lines_2 = new Sprite(*AnBurning4Rows, IntRect(482, 0, 482, 217)), * spriteAn_4lines_3 = new Sprite(*AnBurning4Rows, IntRect(482, 217, 482,198)),
* spriteAn_4lines_4 = new Sprite(*AnBurning4Rows, IntRect(0, 237, 482, 180)), * spriteAn_4lines_5 = new Sprite(*AnBurning4Rows, IntRect(482, 415, 482, 161)), * spriteAn_4lines_6 = new Sprite(*AnBurning4Rows, IntRect(0, 417, 481, 142)),
* spriteAn_4lines_7 = new Sprite(*AnBurning4Rows, IntRect(0, 559, 480, 123)), * spriteAn_4lines_8 = new Sprite(*AnBurning4Rows, IntRect(480, 576, 476, 105)), * spriteAn_4lines_9 = new Sprite(*AnBurning4Rows, IntRect(480, 681, 476, 105)),
* spriteAn_4lines_10 = new Sprite(*AnBurning4Rows, IntRect(0, 682, 448, 105)), * spriteAn_4lines_11 = new Sprite(*AnBurning4Rows, IntRect(448, 786, 422, 105)), * spriteAn_4lines_12 = new Sprite(*AnBurning4Rows, IntRect(0, 787, 394, 105)),
* spriteAn_4lines_13 = new Sprite(*AnBurning4Rows, IntRect(0, 892, 368, 105)), * spriteAn_4lines_14 = new Sprite(*AnBurning4Rows, IntRect(0, 997, 340, 105)), * spriteAn_4lines_15 = new Sprite(*AnBurning4Rows, IntRect(340, 997, 314, 105)),
* spriteAn_4lines_16 = new Sprite(*AnBurning4Rows, IntRect(368, 892, 286, 105)), * spriteAn_4lines_17 = new Sprite(*AnBurning4Rows, IntRect(654, 891, 258, 103)), * spriteAn_4lines_18 = new Sprite(*AnBurning4Rows, IntRect(654, 994, 231, 103)),
* spriteAn_4lines_19 = new Sprite(*AnBurning4Rows, IntRect(654, 1097, 204, 103)), * spriteAn_4lines_20 = new Sprite(*AnBurning4Rows, IntRect(0, 1102, 173, 101)), * spriteAn_4lines_21 = new Sprite(*AnBurning4Rows, IntRect(173, 1102, 144, 97)),
* spriteAn_4lines_22 = new Sprite(*AnBurning4Rows, IntRect(317, 1102, 110, 89)),

* spriteAn_1_inRow_1Row_1 = new Sprite(*AnFF1inRow1To4Rows,IntRect(251, 1182, 248, 232)), * spriteAn_1_inRow_1Row_2 = new Sprite(*AnFF1inRow1To4Rows, IntRect(0, 1175, 251, 247)),
* spriteAn_1_inRow_2Rows_1 = new Sprite(*AnFF1inRow1To4Rows, IntRect(0, 924, 251, 251)), * spriteAn_1_inRow_2Rows_2 = new Sprite(*AnFF1inRow1To4Rows, IntRect(253, 637, 253, 285)),
* spriteAn_1_inRow_3Rows_1 = new Sprite(*AnFF1inRow1To4Rows, IntRect(0, 654, 252, 270)), * spriteAn_1_inRow_3Rows_2 = new Sprite(*AnFF1inRow1To4Rows, IntRect(254, 0, 253, 323)),
* spriteAn_1_inRow_4Rows_1 = new Sprite(*AnFF1inRow1To4Rows, IntRect(252, 922, 249, 260)), * spriteAn_1_inRow_4Rows_2 = new Sprite(*AnFF1inRow1To4Rows, IntRect(254, 323, 253, 314)),
* spriteAn_1_inRow_4Rows_3 = new Sprite(*AnFF1inRow1To4Rows, IntRect(0, 0, 254, 365)), * spriteAn_1_inRow_4Rows_4 = new Sprite(*AnFF1inRow1To4Rows, IntRect(0, 365, 253, 289)),
* spriteAn_1_inRow_5Rows_1 = new Sprite(*AnFF1inRow5To8Rows, IntRect(750, 1542, 249, 272)), * spriteAn_1_inRow_5Rows_2 = new Sprite(*AnFF1inRow5To8Rows, IntRect(254, 892, 253, 340)),
* spriteAn_1_inRow_5Rows_3 = new Sprite(*AnFF1inRow5To8Rows, IntRect(0, 517, 254, 403)), * spriteAn_1_inRow_5Rows_4 = new Sprite(*AnFF1inRow5To8Rows, IntRect(507, 1222, 253, 308)),
* spriteAn_1_inRow_6Rows_1 = new Sprite(*AnFF1inRow5To8Rows, IntRect(250, 1543, 250, 284)), * spriteAn_1_inRow_6Rows_2 = new Sprite(*AnFF1inRow5To8Rows, IntRect(762, 831, 254, 365)),
* spriteAn_1_inRow_6Rows_3 = new Sprite(*AnFF1inRow5To8Rows, IntRect(508, 0, 254, 441)), * spriteAn_1_inRow_6Rows_4 = new Sprite(*AnFF1inRow5To8Rows, IntRect(0, 920, 253, 327)),
* spriteAn_1_inRow_7Rows_1 = new Sprite(*AnFF1inRow5To8Rows, IntRect(0, 1247, 249, 276)), * spriteAn_1_inRow_7Rows_2 = new Sprite(*AnFF1inRow5To8Rows, IntRect(762, 1196, 253, 346)),
* spriteAn_1_inRow_7Rows_3 = new Sprite(*AnFF1inRow5To8Rows, IntRect(254, 479, 254, 413)), * spriteAn_1_inRow_7Rows_4 = new Sprite(*AnFF1inRow5To8Rows, IntRect(254, 0, 254, 479)),
* spriteAn_1_inRow_7Rows_5 = new Sprite(*AnFF1inRow5To8Rows, IntRect(762, 441, 254, 390)), * spriteAn_1_inRow_7Rows_6 = new Sprite(*AnFF1inRow5To8Rows, IntRect(0, 1530, 250, 298)),
* spriteAn_1_inRow_8Rows_1 = new Sprite(*AnFF1inRow5To8Rows, IntRect(500, 1543, 250, 285)), * spriteAn_1_inRow_8Rows_2 = new Sprite(*AnFF1inRow5To8Rows, IntRect(508, 857, 254, 365)),
* spriteAn_1_inRow_8Rows_3 = new Sprite(*AnFF1inRow5To8Rows, IntRect(762, 0, 254, 441)), * spriteAn_1_inRow_8Rows_4 = new Sprite(*AnFF1inRow5To8Rows, IntRect(0, 0, 254, 517)),
* spriteAn_1_inRow_8Rows_5 = new Sprite(*AnFF1inRow5To8Rows, IntRect(508, 441, 254, 416)), * spriteAn_1_inRow_8Rows_6 = new Sprite(*AnFF1inRow5To8Rows, IntRect(253, 1232, 251, 311)),
* spriteAn_1_inRow_9Rows_1 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1772, 600, 250, 295)), * spriteAn_1_inRow_9Rows_2 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1016, 1346, 254, 384)),
* spriteAn_1_inRow_9Rows_3 = new Sprite(*AnFF1inRow9To12Rows, IntRect(762, 1133, 254, 470)), * spriteAn_1_inRow_9Rows_4 = new Sprite(*AnFF1inRow9To12Rows, IntRect(0, 669, 254, 555)),
* spriteAn_1_inRow_9Rows_5 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1016, 905, 254, 441)), * spriteAn_1_inRow_9Rows_6 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1521, 1060, 251, 323)),
* spriteAn_1_inRow_10Rows_1 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1772, 1184, 245, 281)), * spriteAn_1_inRow_10Rows_2 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1521, 376, 251, 361)),
* spriteAn_1_inRow_10Rows_3 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1016, 464, 254, 441)), * spriteAn_1_inRow_10Rows_4 = new Sprite(*AnFF1inRow9To12Rows, IntRect(508, 1120, 254,517)),
* spriteAn_1_inRow_10Rows_5 = new Sprite(*AnFF1inRow9To12Rows, IntRect(508, 0, 254, 593)), * spriteAn_1_inRow_10Rows_6 = new Sprite(*AnFF1inRow9To12Rows, IntRect(254, 1178, 254, 498)),
* spriteAn_1_inRow_10Rows_7 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1270, 855, 251, 399)), * spriteAn_1_inRow_10Rows_8 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1772, 0, 251, 304)),
* spriteAn_1_inRow_11Rows_1 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1772, 895, 246, 289)), * spriteAn_1_inRow_11Rows_2 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1521, 0, 251, 376)),
* spriteAn_1_inRow_11Rows_3 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1016, 0, 254, 464)), * spriteAn_1_inRow_11Rows_4 = new Sprite(*AnFF1inRow9To12Rows, IntRect(254, 631, 254, 547)),
* spriteAn_1_inRow_11Rows_5 = new Sprite(*AnFF1inRow9To12Rows, IntRect(254, 0, 254, 631)), * spriteAn_1_inRow_11Rows_6 = new Sprite(*AnFF1inRow9To12Rows, IntRect(508, 593, 254, 527)),
* spriteAn_1_inRow_11Rows_7 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1270, 437, 251, 418)), * spriteAn_1_inRow_11Rows_8 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1521, 1383, 251, 314)),
* spriteAn_1_inRow_12Rows_1 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1772, 304, 246, 296)), * spriteAn_1_inRow_12Rows_2 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1270, 1254, 251, 391)),
* spriteAn_1_inRow_12Rows_3 = new Sprite(*AnFF1inRow9To12Rows, IntRect(0, 1224, 254, 486)), * spriteAn_1_inRow_12Rows_4 = new Sprite(*AnFF1inRow9To12Rows, IntRect(762, 0, 254, 578)),
* spriteAn_1_inRow_12Rows_5 = new Sprite(*AnFF1inRow9To12Rows, IntRect(0, 0, 254, 669)), * spriteAn_1_inRow_12Rows_6 = new Sprite(*AnFF1inRow9To12Rows, IntRect(762, 578, 254, 555)),
* spriteAn_1_inRow_12Rows_7 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1270, 0, 251, 437)), * spriteAn_1_inRow_12Rows_8 = new Sprite(*AnFF1inRow9To12Rows, IntRect(1521, 737, 251, 323)),
* spriteAn_1_inRow_13Rows_1 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1775, 897, 245, 287)), * spriteAn_1_inRow_13Rows_2 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1760, 1614, 251, 373)),
* spriteAn_1_inRow_13Rows_3 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1270, 976, 254, 460)), * spriteAn_1_inRow_13Rows_4 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1016, 593, 254, 542)),
* spriteAn_1_inRow_13Rows_5 = new Sprite(*AnFF1inRow13To15Rows, IntRect(762, 639, 254, 625)), * spriteAn_1_inRow_13Rows_6 = new Sprite(*AnFF1inRow13To15Rows, IntRect(508, 0, 254, 707)),
* spriteAn_1_inRow_13Rows_7 = new Sprite(*AnFF1inRow13To15Rows, IntRect(762, 1264, 254, 608)), * spriteAn_1_inRow_13Rows_8 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1016, 1135, 254, 510)),
* spriteAn_1_inRow_13Rows_9 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1524, 422, 251, 407)), * spriteAn_1_inRow_13Rows_10 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1775, 0, 246, 304)),
* spriteAn_1_inRow_14Rows_1 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1775, 604, 246, 293)), * spriteAn_1_inRow_14Rows_2 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1760, 1228, 251, 386)),
* spriteAn_1_inRow_14Rows_3 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1270, 498, 254, 478)), * spriteAn_1_inRow_14Rows_4 = new Sprite(*AnFF1inRow13To15Rows, IntRect(508, 1395, 254, 567)),
* spriteAn_1_inRow_14Rows_5 = new Sprite(*AnFF1inRow13To15Rows, IntRect(254, 745, 254, 656)), * spriteAn_1_inRow_14Rows_6 = new Sprite(*AnFF1inRow13To15Rows, IntRect(254, 0, 254, 745)),
* spriteAn_1_inRow_14Rows_7 = new Sprite(*AnFF1inRow13To15Rows, IntRect(762, 0, 254, 639)), * spriteAn_1_inRow_14Rows_8 = new Sprite(*AnFF1inRow13To15Rows, IntRect(0, 1452, 254, 532)),
* spriteAn_1_inRow_14Rows_9 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1524, 0, 251, 422)), * spriteAn_1_inRow_14Rows_10 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1263, 1645, 246, 311)),
* spriteAn_1_inRow_15Rows_1 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1775, 304, 246, 300)), * spriteAn_1_inRow_15Rows_2 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1524, 829, 251, 399)),
* spriteAn_1_inRow_15Rows_3 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1270, 0, 254, 498)), * spriteAn_1_inRow_15Rows_4 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1016, 0, 254, 593)),
* spriteAn_1_inRow_15Rows_5 = new Sprite(*AnFF1inRow13To15Rows, IntRect(508, 707, 254, 688)), * spriteAn_1_inRow_15Rows_6 = new Sprite(*AnFF1inRow13To15Rows, IntRect(0, 0, 254, 783)),
* spriteAn_1_inRow_15Rows_7 = new Sprite(*AnFF1inRow13To15Rows, IntRect(0, 783, 254, 669)), * spriteAn_1_inRow_15Rows_8 = new Sprite(*AnFF1inRow13To15Rows, IntRect(254, 1401, 254, 555)),
* spriteAn_1_inRow_15Rows_9 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1509, 1436, 251, 437)), * spriteAn_1_inRow_15Rows_10 = new Sprite(*AnFF1inRow13To15Rows, IntRect(1016, 1645, 247, 319)),
* spriteAn_1_inRow_16Rows_1 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1517, 1405, 246, 306)), * spriteAn_1_inRow_16Rows_2 = new Sprite(*AnFF1inRow16To17Rows, IntRect(762, 1322, 251, 412)),
* spriteAn_1_inRow_16Rows_3 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1778, 0, 254, 517)), * spriteAn_1_inRow_16Rows_4 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1016, 644, 254, 618)),
* spriteAn_1_inRow_16Rows_5 = new Sprite(*AnFF1inRow16To17Rows, IntRect(508, 734, 254, 720)), * spriteAn_1_inRow_16Rows_6 = new Sprite(*AnFF1inRow16To17Rows, IntRect(0, 859, 254, 821)),
* spriteAn_1_inRow_16Rows_7 = new Sprite(*AnFF1inRow16To17Rows, IntRect(508, 0, 254, 734)), * spriteAn_1_inRow_16Rows_8 = new Sprite(*AnFF1inRow16To17Rows, IntRect(762, 675, 254, 647)),
* spriteAn_1_inRow_16Rows_9 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1270, 582, 254, 561)), * spriteAn_1_inRow_16Rows_10 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1775, 536, 251, 470)),
* spriteAn_1_inRow_16Rows_11 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1524, 1022, 251, 383)), * spriteAn_1_inRow_16Rows_12 = new Sprite(*AnFF1inRow16To17Rows, IntRect(508, 1454, 242, 288)),
* spriteAn_1_inRow_17Rows_1 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1270, 1143, 247, 313)), * spriteAn_1_inRow_17Rows_2 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1775, 1006, 251, 424)),
* spriteAn_1_inRow_17Rows_3 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1524, 0, 254, 536)), * spriteAn_1_inRow_17Rows_4 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1016, 0, 254, 644)),
* spriteAn_1_inRow_17Rows_5 = new Sprite(*AnFF1inRow16To17Rows, IntRect(254, 767, 254, 751)), * spriteAn_1_inRow_17Rows_6 = new Sprite(*AnFF1inRow16To17Rows, IntRect(0, 0, 254, 859)),
* spriteAn_1_inRow_17Rows_7 = new Sprite(*AnFF1inRow16To17Rows, IntRect(254, 0, 254, 767)), * spriteAn_1_inRow_17Rows_8 = new Sprite(*AnFF1inRow16To17Rows, IntRect(762, 0, 254, 675)),
* spriteAn_1_inRow_17Rows_9 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1270, 0, 254, 582)), * spriteAn_1_inRow_17Rows_10 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1524, 536, 251, 486)),
* spriteAn_1_inRow_17Rows_11 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1013, 1322, 251, 394)), * spriteAn_1_inRow_17Rows_12 = new Sprite(*AnFF1inRow16To17Rows, IntRect(1763, 1430, 243, 294)),

* spriteAn_2_inRow_1Row_1 = new Sprite(*AnFF2inRow1To6Rows, IntRect(0, 1636, 285, 234)), * spriteAn_2_inRow_1Row_2 = new Sprite(*AnFF2inRow1To6Rows, IntRect(287, 1626, 289, 253)),
* spriteAn_2_inRow_2Rows_1 = new Sprite(*AnFF2inRow1To6Rows, IntRect(576, 1626, 289, 253)), * spriteAn_2_inRow_2Rows_2 = new Sprite(*AnFF2inRow1To6Rows, IntRect(291, 1063, 291, 291)),
* spriteAn_2_inRow_3Rows_1 = new Sprite(*AnFF2inRow1To6Rows, IntRect(291, 1354, 290, 272)), * spriteAn_2_inRow_3Rows_2 = new Sprite(*AnFF2inRow1To6Rows, IntRect(0, 443, 291, 329)),
* spriteAn_2_inRow_4Rows_1 = new Sprite(*AnFF2inRow1To6Rows, IntRect(0, 1373, 287, 263)), * spriteAn_2_inRow_4Rows_2 = new Sprite(*AnFF2inRow1To6Rows, IntRect(291, 747, 291, 316)),
* spriteAn_2_inRow_4Rows_3 = new Sprite(*AnFF2inRow1To6Rows, IntRect(584, 0, 292, 367)), * spriteAn_2_inRow_4Rows_4 = new Sprite(*AnFF2inRow1To6Rows, IntRect(0, 1082, 291, 291)),
* spriteAn_2_inRow_5Rows_1 = new Sprite(*AnFF2inRow1To6Rows, IntRect(582, 1351, 287, 275)), * spriteAn_2_inRow_5Rows_2 = new Sprite(*AnFF2inRow1To6Rows, IntRect(292, 405, 291, 342)),
* spriteAn_2_inRow_5Rows_3 = new Sprite(*AnFF2inRow1To6Rows, IntRect(292, 0, 292, 405)), * spriteAn_2_inRow_5Rows_4 = new Sprite(*AnFF2inRow1To6Rows, IntRect(0, 772, 291, 310)),
* spriteAn_2_inRow_6Rows_1 = new Sprite(*AnFF2inRow1To6Rows, IntRect(582, 1063, 288, 288)), * spriteAn_2_inRow_6Rows_2 = new Sprite(*AnFF2inRow1To6Rows, IntRect(584, 367, 292, 367)),
* spriteAn_2_inRow_6Rows_3 = new Sprite(*AnFF2inRow1To6Rows, IntRect(0, 0, 292, 443)), * spriteAn_2_inRow_6Rows_4 = new Sprite(*AnFF2inRow1To6Rows, IntRect(583, 734, 291, 329)),
* spriteAn_2_inRow_7Rows_1 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1454, 1171, 287, 279)), * spriteAn_2_inRow_7Rows_2 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1168, 804, 291, 348)),
* spriteAn_2_inRow_7Rows_3 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1460, 0, 292, 415)), * spriteAn_2_inRow_7Rows_4 = new Sprite(*AnFF2inRow7To10Rows, IntRect(584,0, 292, 481)),
* spriteAn_2_inRow_7Rows_5 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1460, 415, 292, 392)), * spriteAn_2_inRow_7Rows_6 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1752, 0, 288, 301)),
* spriteAn_2_inRow_8Rows_1 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1752, 599, 288, 288)), * spriteAn_2_inRow_8Rows_2 = new Sprite(*AnFF2inRow7To10Rows, IntRect(876, 443, 292, 367)),
* spriteAn_2_inRow_8Rows_3 = new Sprite(*AnFF2inRow7To10Rows, IntRect(584, 953, 292, 443)), * spriteAn_2_inRow_8Rows_4 = new Sprite(*AnFF2inRow7To10Rows, IntRect(292, 519, 292, 519)),
* spriteAn_2_inRow_8Rows_5 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1168, 0, 292, 418)), * spriteAn_2_inRow_8Rows_6 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1165, 1152, 289, 314)),
* spriteAn_2_inRow_9Rows_1 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1752, 301, 288, 298)), * spriteAn_2_inRow_9Rows_2 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1168, 418, 292, 386)),
* spriteAn_2_inRow_9Rows_3 = new Sprite(*AnFF2inRow7To10Rows, IntRect(584, 481, 292, 472)), * spriteAn_2_inRow_9Rows_4 = new Sprite(*AnFF2inRow7To10Rows, IntRect(0, 595, 292, 557)),
* spriteAn_2_inRow_9Rows_5 = new Sprite(*AnFF2inRow7To10Rows, IntRect(876, 0, 292, 443)), * spriteAn_2_inRow_9Rows_6 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1748, 887, 289, 326)),
* spriteAn_2_inRow_10Rows_1 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1741, 1213, 283, 283)), * spriteAn_2_inRow_10Rows_2 = new Sprite(*AnFF2inRow7To10Rows, IntRect(1459, 807, 289, 364)),
* spriteAn_2_inRow_10Rows_3 = new Sprite(*AnFF2inRow7To10Rows, IntRect(0, 1152, 292, 443)), * spriteAn_2_inRow_10Rows_4 = new Sprite(*AnFF2inRow7To10Rows, IntRect(292, 0, 292, 519)),
* spriteAn_2_inRow_10Rows_5 = new Sprite(*AnFF2inRow7To10Rows, IntRect(0, 0, 292, 595)), * spriteAn_2_inRow_10Rows_6 = new Sprite(*AnFF2inRow7To10Rows, IntRect(292, 1038, 292, 500)),
* spriteAn_2_inRow_10Rows_7 = new Sprite(*AnFF2inRow7To10Rows, IntRect(876, 810, 289, 402)), * spriteAn_2_inRow_10Rows_8 = new Sprite(*AnFF2inRow7To10Rows, IntRect(876, 1212, 289, 307)),
* spriteAn_2_inRow_11Rows_1 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1752, 604, 284, 291)), * spriteAn_2_inRow_11Rows_2 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1743, 1184, 289, 379)),
* spriteAn_2_inRow_11Rows_3 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1168, 529, 292, 466)), * spriteAn_2_inRow_11Rows_4 = new Sprite(*AnFF2inRow11To13Rows, IntRect(584, 1167, 292, 549)),
* spriteAn_2_inRow_11Rows_5 = new Sprite(*AnFF2inRow11To13Rows, IntRect(292, 0, 292, 633)), * spriteAn_2_inRow_11Rows_6 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1168, 0, 292, 529)),
* spriteAn_2_inRow_11Rows_7 = new Sprite(*AnFF2inRow11To13Rows, IntRect(876, 984, 289, 421)), * spriteAn_2_inRow_11Rows_8 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1165, 1405, 289, 317)),
* spriteAn_2_inRow_12Rows_1 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1752, 306, 284, 298)), * spriteAn_2_inRow_12Rows_2 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1454, 1001, 289, 394)),
* spriteAn_2_inRow_12Rows_3 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1460, 512, 292, 489)), * spriteAn_2_inRow_12Rows_4 = new Sprite(*AnFF2inRow11To13Rows, IntRect(292, 1260, 292, 580)),
* spriteAn_2_inRow_12Rows_5 = new Sprite(*AnFF2inRow11To13Rows, IntRect(0, 709, 292, 671)), * spriteAn_2_inRow_12Rows_6 = new Sprite(*AnFF2inRow11To13Rows, IntRect(584, 610, 292, 557)),
* spriteAn_2_inRow_12Rows_7 = new Sprite(*AnFF2inRow11To13Rows, IntRect(876, 544, 289, 440)), * spriteAn_2_inRow_12Rows_8 = new Sprite(*AnFF2inRow11To13Rows, IntRect(876, 1405, 289, 326)),
* spriteAn_2_inRow_13Rows_1 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1752, 895, 283, 289)), * spriteAn_2_inRow_13Rows_2 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1454, 1395, 289, 377)),
* spriteAn_2_inRow_13Rows_3 = new Sprite(*AnFF2inRow11To13Rows, IntRect(0, 1380, 292, 462)), * spriteAn_2_inRow_13Rows_4 = new Sprite(*AnFF2inRow11To13Rows, IntRect(876, 0, 292, 544)),
* spriteAn_2_inRow_13Rows_5 = new Sprite(*AnFF2inRow11To13Rows, IntRect(292, 633, 292, 627)), * spriteAn_2_inRow_13Rows_6 = new Sprite(*AnFF2inRow11To13Rows, IntRect(0, 0, 292, 709)),
* spriteAn_2_inRow_13Rows_7 = new Sprite(*AnFF2inRow11To13Rows, IntRect(584, 0, 292, 610)), * spriteAn_2_inRow_13Rows_8 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1460, 0, 292, 512)),
* spriteAn_2_inRow_13Rows_9 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1165, 995, 289, 410)), * spriteAn_2_inRow_13Rows_10 = new Sprite(*AnFF2inRow11To13Rows, IntRect(1752, 0, 284, 306)),
* spriteAn_2_inRow_14Rows_1 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1452, 1267, 284, 296)), * spriteAn_2_inRow_14Rows_2 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1445, 1569, 289, 389)),
* spriteAn_2_inRow_14Rows_3 = new Sprite(*AnFF2inRow14To15Rows, IntRect(876, 1127, 292, 481)), * spriteAn_2_inRow_14Rows_4 = new Sprite(*AnFF2inRow14To15Rows, IntRect(876, 0, 292, 570)),
* spriteAn_2_inRow_14Rows_5 = new Sprite(*AnFF2inRow14To15Rows, IntRect(584, 0, 292, 658)), * spriteAn_2_inRow_14Rows_6 = new Sprite(*AnFF2inRow14To15Rows, IntRect(292, 0, 292, 747)),
* spriteAn_2_inRow_14Rows_7 = new Sprite(*AnFF2inRow14To15Rows, IntRect(584, 658, 292, 641)), * spriteAn_2_inRow_14Rows_8 = new Sprite(*AnFF2inRow14To15Rows, IntRect(292, 1437, 292, 534)),
* spriteAn_2_inRow_14Rows_9 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1168, 440, 289, 425)), * spriteAn_2_inRow_14Rows_10 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1161, 1608, 284, 314)),
* spriteAn_2_inRow_15Rows_1 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1168, 1267, 284, 302)), * spriteAn_2_inRow_15Rows_2 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1168, 865, 289, 402)),
* spriteAn_2_inRow_15Rows_3 = new Sprite(*AnFF2inRow14To15Rows, IntRect(0, 1456, 292, 500)), * spriteAn_2_inRow_15Rows_4 = new Sprite(*AnFF2inRow14To15Rows, IntRect(584, 1299, 292, 595)),
* spriteAn_2_inRow_15Rows_5 = new Sprite(*AnFF2inRow14To15Rows, IntRect(292, 747, 292, 690)), * spriteAn_2_inRow_15Rows_6 = new Sprite(*AnFF2inRow14To15Rows, IntRect(0, 0, 292, 785)),
* spriteAn_2_inRow_15Rows_7 = new Sprite(*AnFF2inRow14To15Rows, IntRect(0, 785, 292, 671)), * spriteAn_2_inRow_15Rows_8 = new Sprite(*AnFF2inRow14To15Rows, IntRect(876, 570, 292, 557)),
* spriteAn_2_inRow_15Rows_9 = new Sprite(*AnFF2inRow14To15Rows, IntRect(1168, 0, 289, 440)), * spriteAn_2_inRow_15Rows_10 = new Sprite(*AnFF2inRow14To15Rows, IntRect(876, 1608, 285, 321)),
* spriteAn_2_inRow_16Rows_1 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1752, 1058, 284, 309)), * spriteAn_2_inRow_16Rows_2 = new Sprite(*AnFF2inRow16To17Rows, IntRect(292, 1522, 289, 415)),
* spriteAn_2_inRow_16Rows_3 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1752, 538, 292, 520)), * spriteAn_2_inRow_16Rows_4 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1168, 646, 292, 621)),
* spriteAn_2_inRow_16Rows_5 = new Sprite(*AnFF2inRow16To17Rows, IntRect(584, 736, 292, 722)), * spriteAn_2_inRow_16Rows_6 = new Sprite(*AnFF2inRow16To17Rows, IntRect(0, 861, 292, 823)),
* spriteAn_2_inRow_16Rows_7 = new Sprite(*AnFF2inRow16To17Rows, IntRect(584, 0, 292, 736)), * spriteAn_2_inRow_16Rows_8 = new Sprite(*AnFF2inRow16To17Rows, IntRect(876, 677, 292, 649)),
* spriteAn_2_inRow_16Rows_9 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1460, 584, 292, 562)), * spriteAn_2_inRow_16Rows_10 = new Sprite(*AnFF2inRow16To17Rows, IntRect(876, 1326, 289, 472)),
* spriteAn_2_inRow_16Rows_11 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1460, 1146, 289, 385)), * spriteAn_2_inRow_16Rows_12 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1743, 1664, 280, 290)),
* spriteAn_2_inRow_17Rows_1 = new Sprite(*AnFF2inRow16To17Rows, IntRect(0, 1684, 285, 315)), * spriteAn_2_inRow_17Rows_2 = new Sprite(*AnFF2inRow16To17Rows, IntRect(581, 1522, 289, 427)),
* spriteAn_2_inRow_17Rows_3 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1752, 0, 292, 538)), * spriteAn_2_inRow_17Rows_4 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1168, 0, 292, 646)),
* spriteAn_2_inRow_17Rows_5 = new Sprite(*AnFF2inRow16To17Rows, IntRect(292, 769, 292, 753)), * spriteAn_2_inRow_17Rows_6 = new Sprite(*AnFF2inRow16To17Rows, IntRect(0, 0, 292, 861)),
* spriteAn_2_inRow_17Rows_7 = new Sprite(*AnFF2inRow16To17Rows, IntRect(292, 0, 292, 769)), * spriteAn_2_inRow_17Rows_8 = new Sprite(*AnFF2inRow16To17Rows, IntRect(876, 0, 292, 677)),
* spriteAn_2_inRow_17Rows_9 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1460, 0, 292, 584)), * spriteAn_2_inRow_17Rows_10 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1165, 1326, 289, 489)),
* spriteAn_2_inRow_17Rows_11 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1454, 1531, 289, 397)), * spriteAn_2_inRow_17Rows_12 = new Sprite(*AnFF2inRow16To17Rows, IntRect(1749, 1367, 281, 297)),

* spriteAn_3_inRow_1Row_1 = new Sprite(*AnFF3inRow1To4Rows, IntRect(658, 770, 324, 234)), * spriteAn_3_inRow_1Row_2 = new Sprite(*AnFF3inRow1To4Rows, IntRect(658, 0, 327, 253)),
* spriteAn_3_inRow_2Rows_1 = new Sprite(*AnFF3inRow1To4Rows, IntRect(658, 253, 327, 253)), * spriteAn_3_inRow_2Rows_2 = new Sprite(*AnFF3inRow1To4Rows, IntRect(0, 696, 329, 291)),
* spriteAn_3_inRow_3Rows_1 = new Sprite(*AnFF3inRow1To4Rows, IntRect(330, 0, 328, 272)), * spriteAn_3_inRow_3Rows_2 = new Sprite(*AnFF3inRow1To4Rows, IntRect(0, 367, 329, 329)),
* spriteAn_3_inRow_4Rows_1 = new Sprite(*AnFF3inRow1To4Rows, IntRect(658, 506, 325, 264)), * spriteAn_3_inRow_4Rows_2 = new Sprite(*AnFF3inRow1To4Rows, IntRect(329, 367, 329, 316)),
* spriteAn_3_inRow_4Rows_3 = new Sprite(*AnFF3inRow1To4Rows, IntRect(0, 0, 330, 367)), * spriteAn_3_inRow_4Rows_4 = new Sprite(*AnFF3inRow1To4Rows, IntRect(329, 683, 329, 291)),
* spriteAn_3_inRow_5Rows_1 = new Sprite(*AnFF3inRow5To8Rows, IntRect(659, 1176, 325, 276)), * spriteAn_3_inRow_5Rows_2 = new Sprite(*AnFF3inRow5To8Rows, IntRect(330, 1158, 329, 342)),
* spriteAn_3_inRow_5Rows_3 = new Sprite(*AnFF3inRow5To8Rows, IntRect(990, 415, 330, 405)), * spriteAn_3_inRow_5Rows_4 = new Sprite(*AnFF3inRow5To8Rows, IntRect(990, 1149, 329, 310)),
* spriteAn_3_inRow_6Rows_1 = new Sprite(*AnFF3inRow5To8Rows, IntRect(1320, 616, 326, 289)), * spriteAn_3_inRow_6Rows_2 = new Sprite(*AnFF3inRow5To8Rows, IntRect(330, 443, 330, 367)),
* spriteAn_3_inRow_6Rows_3 = new Sprite(*AnFF3inRow5To8Rows, IntRect(0, 1000, 330, 443)), * spriteAn_3_inRow_6Rows_4 = new Sprite(*AnFF3inRow5To8Rows, IntRect(990, 820, 329, 329)),
* spriteAn_3_inRow_7Rows_1 = new Sprite(*AnFF3inRow5To8Rows, IntRect(1319, 1194, 325, 280)), * spriteAn_3_inRow_7Rows_2 = new Sprite(*AnFF3inRow5To8Rows, IntRect(330, 810, 329, 348)),
* spriteAn_3_inRow_7Rows_3 = new Sprite(*AnFF3inRow5To8Rows, IntRect(990, 0, 330, 415)), * spriteAn_3_inRow_7Rows_4 = new Sprite(*AnFF3inRow5To8Rows, IntRect(0, 519, 330, 481)),
* spriteAn_3_inRow_7Rows_5 = new Sprite(*AnFF3inRow5To8Rows, IntRect(660, 417, 330, 392)), * spriteAn_3_inRow_7Rows_6 = new Sprite(*AnFF3inRow5To8Rows, IntRect(1320, 314, 326, 302)),
* spriteAn_3_inRow_8Rows_1 = new Sprite(*AnFF3inRow5To8Rows, IntRect(1319, 905, 326, 289)), * spriteAn_3_inRow_8Rows_2 = new Sprite(*AnFF3inRow5To8Rows, IntRect(660, 809, 330, 367)),
* spriteAn_3_inRow_8Rows_3 = new Sprite(*AnFF3inRow5To8Rows, IntRect(330, 0, 330, 443)), * spriteAn_3_inRow_8Rows_4 = new Sprite(*AnFF3inRow5To8Rows, IntRect(0, 0, 330, 519)),
* spriteAn_3_inRow_8Rows_5 = new Sprite(*AnFF3inRow5To8Rows, IntRect(660, 0, 330, 417)), * spriteAn_3_inRow_8Rows_6 = new Sprite(*AnFF3inRow5To8Rows, IntRect(1320, 0, 327, 314)),
* spriteAn_3_inRow_9Rows_1 = new Sprite(*AnFF3inRow9To11Rows, IntRect(660, 1588, 326, 299)), * spriteAn_3_inRow_9Rows_2 = new Sprite(*AnFF3inRow9To11Rows, IntRect(330, 1598, 330, 387)),
* spriteAn_3_inRow_9Rows_3 = new Sprite(*AnFF3inRow9To11Rows, IntRect(990, 0, 330, 472)), * spriteAn_3_inRow_9Rows_4 = new Sprite(*AnFF3inRow9To11Rows, IntRect(0, 1228, 330, 557)),
* spriteAn_3_inRow_9Rows_5 = new Sprite(*AnFF3inRow9To11Rows, IntRect(990, 938, 330, 443)), * spriteAn_3_inRow_9Rows_6 = new Sprite(*AnFF3inRow9To11Rows, IntRect(660, 943, 327, 327)),
* spriteAn_3_inRow_10Rows_1 = new Sprite(*AnFF3inRow9To11Rows, IntRect(986, 1689, 321, 285)), * spriteAn_3_inRow_10Rows_2 = new Sprite(*AnFF3inRow9To11Rows, IntRect(1320, 1206, 327, 365)),
* spriteAn_3_inRow_10Rows_3 = new Sprite(*AnFF3inRow9To11Rows, IntRect(660, 500, 330, 443)), * spriteAn_3_inRow_10Rows_4 = new Sprite(*AnFF3inRow9To11Rows, IntRect(330, 1079, 330, 519)),
* spriteAn_3_inRow_10Rows_5 = new Sprite(*AnFF3inRow9To11Rows, IntRect(0, 633, 330, 595)), * spriteAn_3_inRow_10Rows_6 = new Sprite(*AnFF3inRow9To11Rows, IntRect(660, 0, 330, 500)),
* spriteAn_3_inRow_10Rows_7 = new Sprite(*AnFF3inRow9To11Rows, IntRect(1320, 422, 327, 403)), * spriteAn_3_inRow_10Rows_8 = new Sprite(*AnFF3inRow9To11Rows, IntRect(987, 1381, 327, 308)),
* spriteAn_3_inRow_11Rows_1 = new Sprite(*AnFF3inRow9To11Rows, IntRect(1314, 1571, 322, 293)), * spriteAn_3_inRow_11Rows_2 = new Sprite(*AnFF3inRow9To11Rows, IntRect(1320, 825, 327, 381)),
* spriteAn_3_inRow_11Rows_3 = new Sprite(*AnFF3inRow9To11Rows, IntRect(990, 472, 330, 466)), * spriteAn_3_inRow_11Rows_4 = new Sprite(*AnFF3inRow9To11Rows, IntRect(330, 0, 330, 550)),
* spriteAn_3_inRow_11Rows_5 = new Sprite(*AnFF3inRow9To11Rows, IntRect(0, 0, 330, 633)), * spriteAn_3_inRow_11Rows_6 = new Sprite(*AnFF3inRow9To11Rows, IntRect(330, 550, 330, 529)),
* spriteAn_3_inRow_11Rows_7 = new Sprite(*AnFF3inRow9To11Rows, IntRect(1320, 0, 327, 422)), * spriteAn_3_inRow_11Rows_8 = new Sprite(*AnFF3inRow9To11Rows, IntRect(660, 1270, 327, 318)),
* spriteAn_3_inRow_12Rows_1 = new Sprite(*AnFF3inRow12To13Rows, IntRect(1314, 1190, 322, 300)), * spriteAn_3_inRow_12Rows_2 = new Sprite(*AnFF3inRow12To13Rows, IntRect(660, 1139, 327, 395)),
* spriteAn_3_inRow_12Rows_3 = new Sprite(*AnFF3inRow12To13Rows, IntRect(1320, 0, 330, 489)), * spriteAn_3_inRow_12Rows_4 = new Sprite(*AnFF3inRow12To13Rows, IntRect(990, 610, 330,580)),
* spriteAn_3_inRow_12Rows_5 = new Sprite(*AnFF3inRow12To13Rows, IntRect(330, 0, 330, 671)), * spriteAn_3_inRow_12Rows_6 = new Sprite(*AnFF3inRow12To13Rows, IntRect(330, 671, 330, 557)),
* spriteAn_3_inRow_12Rows_7 = new Sprite(*AnFF3inRow12To13Rows, IntRect(1636, 952, 327, 441)), * spriteAn_3_inRow_12Rows_8 = new Sprite(*AnFF3inRow12To13Rows, IntRect(987, 1190, 327, 327)),
* spriteAn_3_inRow_13Rows_1 = new Sprite(*AnFF3inRow12To13Rows, IntRect(0, 1254, 321, 292)), * spriteAn_3_inRow_13Rows_2 = new Sprite(*AnFF3inRow12To13Rows, IntRect(1650, 411, 327, 378)),
* spriteAn_3_inRow_13Rows_3 = new Sprite(*AnFF3inRow12To13Rows, IntRect(1320, 489, 330, 463)), * spriteAn_3_inRow_13Rows_4 = new Sprite(*AnFF3inRow12To13Rows, IntRect(0, 709, 330, 545)),
* spriteAn_3_inRow_13Rows_5 = new Sprite(*AnFF3inRow12To13Rows, IntRect(660, 0, 330, 627)), * spriteAn_3_inRow_13Rows_6 = new Sprite(*AnFF3inRow12To13Rows, IntRect(0, 0, 330, 709)),
* spriteAn_3_inRow_13Rows_7 = new Sprite(*AnFF3inRow12To13Rows, IntRect(990, 0, 330, 610)), * spriteAn_3_inRow_13Rows_8 = new Sprite(*AnFF3inRow12To13Rows, IntRect(660, 627, 330, 512)),
* spriteAn_3_inRow_13Rows_9 = new Sprite(*AnFF3inRow12To13Rows, IntRect(1650, 0, 327, 411)), * spriteAn_3_inRow_13Rows_10 = new Sprite(*AnFF3inRow12To13Rows, IntRect(330, 1228, 322, 308)),
* spriteAn_3_inRow_14Rows_1 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1643, 867, 322, 298)), * spriteAn_3_inRow_14Rows_2 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1317, 1572, 327, 390)),
* spriteAn_3_inRow_14Rows_3 = new Sprite(*AnFF3inRow14To15Rows, IntRect(990, 1091, 330, 481)), * spriteAn_3_inRow_14Rows_4 = new Sprite(*AnFF3inRow14To15Rows, IntRect(330, 1388, 330, 570)),
* spriteAn_3_inRow_14Rows_5 = new Sprite(*AnFF3inRow14To15Rows, IntRect(0, 785, 330, 658)), * spriteAn_3_inRow_14Rows_6 = new Sprite(*AnFF3inRow14To15Rows, IntRect(330, 0, 330, 747)),
* spriteAn_3_inRow_14Rows_7 = new Sprite(*AnFF3inRow14To15Rows, IntRect(330, 747, 330, 641)), * spriteAn_3_inRow_14Rows_8 = new Sprite(*AnFF3inRow14To15Rows, IntRect(990, 557, 330, 534)),
* spriteAn_3_inRow_14Rows_9 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1320, 441, 327, 426)), * spriteAn_3_inRow_14Rows_10 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1320, 1190, 322, 316)),
* spriteAn_3_inRow_15Rows_1 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1642, 1190, 322, 304)), * spriteAn_3_inRow_15Rows_2 = new Sprite(*AnFF3inRow14To15Rows, IntRect(990, 1572, 327, 403)),
* spriteAn_3_inRow_15Rows_3 = new Sprite(*AnFF3inRow14To15Rows, IntRect(0, 1443, 330, 500)), * spriteAn_3_inRow_15Rows_4 = new Sprite(*AnFF3inRow14To15Rows, IntRect(660, 1361, 330, 595)),
* spriteAn_3_inRow_15Rows_5 = new Sprite(*AnFF3inRow14To15Rows, IntRect(660, 0, 330, 690)), * spriteAn_3_inRow_15Rows_6 = new Sprite(*AnFF3inRow14To15Rows, IntRect(0, 0, 330, 785)),
* spriteAn_3_inRow_15Rows_7 = new Sprite(*AnFF3inRow14To15Rows, IntRect(660, 690, 330, 671)), * spriteAn_3_inRow_15Rows_8 = new Sprite(*AnFF3inRow14To15Rows, IntRect(990, 0, 330, 557)),
* spriteAn_3_inRow_15Rows_9 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1320, 0, 327, 441)), * spriteAn_3_inRow_15Rows_10 = new Sprite(*AnFF3inRow14To15Rows, IntRect(1320, 867, 323, 323)),
* spriteAn_3_inRow_16Rows_1 = new Sprite(*AnFF3inRow16Rows, IntRect(990, 0, 319, 324)), * spriteAn_3_inRow_16Rows_2 = new Sprite(*AnFF3inRow16Rows, IntRect(987, 1380, 327, 414)),
* spriteAn_3_inRow_16Rows_3 = new Sprite(*AnFF3inRow16Rows, IntRect(0, 1442, 327, 495)), * spriteAn_3_inRow_16Rows_4 = new Sprite(*AnFF3inRow16Rows, IntRect(330, 741, 330, 578)), 
* spriteAn_3_inRow_16Rows_5 = new Sprite(*AnFF3inRow16Rows, IntRect(660, 721, 330, 659)), * spriteAn_3_inRow_16Rows_6 = new Sprite(*AnFF3inRow16Rows, IntRect(330, 0, 330, 741)),
* spriteAn_3_inRow_16Rows_7 = new Sprite(*AnFF3inRow16Rows, IntRect(0, 0, 330, 822)), * spriteAn_3_inRow_16Rows_8 = new Sprite(*AnFF3inRow16Rows, IntRect(660, 0, 330, 721)), 
* spriteAn_3_inRow_16Rows_9 = new Sprite(*AnFF3inRow16Rows, IntRect(0, 822, 330, 620)), * spriteAn_3_inRow_16Rows_10 = new Sprite(*AnFF3inRow16Rows, IntRect(330, 1319, 330, 519)), 
* spriteAn_3_inRow_16Rows_11 = new Sprite(*AnFF3inRow16Rows, IntRect(660, 1380, 327, 416)), * spriteAn_3_inRow_16Rows_12 = new Sprite(*AnFF3inRow16Rows, IntRect(990, 324, 322, 311)),
* spriteAn_3_inRow_17Rows_1 = new Sprite(*AnFF3inRow17Rows, IntRect(990, 0, 322, 317)), * spriteAn_3_inRow_17Rows_2 = new Sprite(*AnFF3inRow17Rows, IntRect(660, 1430, 327, 428)),
* spriteAn_3_inRow_17Rows_3 = new Sprite(*AnFF3inRow17Rows, IntRect(330, 1353, 330, 538)), * spriteAn_3_inRow_17Rows_4 = new Sprite(*AnFF3inRow17Rows, IntRect(0, 861, 330, 646)),
* spriteAn_3_inRow_17Rows_5 = new Sprite(*AnFF3inRow17Rows, IntRect(660, 0, 330, 753)), * spriteAn_3_inRow_17Rows_6 = new Sprite(*AnFF3inRow17Rows, IntRect(0, 0, 330, 861)),
* spriteAn_3_inRow_17Rows_7 = new Sprite(*AnFF3inRow17Rows, IntRect(330, 0, 330, 769)), * spriteAn_3_inRow_17Rows_8 = new Sprite(*AnFF3inRow17Rows, IntRect(660, 753, 330, 677)),
* spriteAn_3_inRow_17Rows_9 = new Sprite(*AnFF3inRow17Rows, IntRect(330, 769, 330, 584)), * spriteAn_3_inRow_17Rows_10 = new Sprite(*AnFF3inRow17Rows, IntRect(0, 1507, 327, 490)),
* spriteAn_3_inRow_17Rows_11 = new Sprite(*AnFF3inRow17Rows, IntRect(987, 1430, 327, 398)), * spriteAn_3_inRow_17Rows_12 = new Sprite(*AnFF3inRow17Rows, IntRect(990, 317, 319, 298)),
* spriteAn_3_inRow_18Rows_1 = new Sprite(*AnFF3inRow18Rows, IntRect(990, 0, 323, 323)), * spriteAn_3_inRow_18Rows_2 = new Sprite(*AnFF3inRow18Rows, IntRect(0, 1570, 327, 441)),
* spriteAn_3_inRow_18Rows_3 = new Sprite(*AnFF3inRow18Rows, IntRect(330, 1407, 330, 557)), * spriteAn_3_inRow_18Rows_4 = new Sprite(*AnFF3inRow18Rows, IntRect(0, 899, 330, 671)),
* spriteAn_3_inRow_18Rows_5 = new Sprite(*AnFF3inRow18Rows, IntRect(660, 0, 330, 785)), * spriteAn_3_inRow_18Rows_6 = new Sprite(*AnFF3inRow18Rows, IntRect(0, 0, 330, 899)),
* spriteAn_3_inRow_18Rows_7 = new Sprite(*AnFF3inRow18Rows, IntRect(330, 0, 330, 801)), * spriteAn_3_inRow_18Rows_8 = new Sprite(*AnFF3inRow18Rows, IntRect(660, 785, 330, 704)),
* spriteAn_3_inRow_18Rows_9 = new Sprite(*AnFF3inRow18Rows, IntRect(330, 801, 330, 606)), * spriteAn_3_inRow_18Rows_10 = new Sprite(*AnFF3inRow18Rows, IntRect(660, 1489, 327, 506)),
* spriteAn_3_inRow_18Rows_11 = new Sprite(*AnFF3inRow18Rows, IntRect(987, 1489, 327, 409)), * spriteAn_3_inRow_18Rows_12 = new Sprite(*AnFF3inRow18Rows, IntRect(990, 323, 319, 303)),

* spriteAn_4_inRow_1Row_1 = new Sprite(*AnFF4inRow1To4Rows, IntRect(365, 1203, 362, 235)), * spriteAn_4_inRow_1Row_2 = new Sprite(*AnFF4inRow1To4Rows, IntRect(0, 933, 365, 254)),
* spriteAn_4_inRow_2Rows_1 = new Sprite(*AnFF4inRow1To4Rows, IntRect(0, 1187, 365, 254)), * spriteAn_4_inRow_2Rows_2 = new Sprite(*AnFF4inRow1To4Rows, IntRect(0, 368, 367, 292)),
* spriteAn_4_inRow_3Rows_1 = new Sprite(*AnFF4inRow1To4Rows, IntRect(0, 660, 366, 273)), * spriteAn_4_inRow_3Rows_2 = new Sprite(*AnFF4inRow1To4Rows, IntRect(368, 0, 367, 330)),
* spriteAn_4_inRow_4Rows_1 = new Sprite(*AnFF4inRow1To4Rows, IntRect(365, 939, 363, 264)), * spriteAn_4_inRow_4Rows_2 = new Sprite(*AnFF4inRow1To4Rows, IntRect(368, 330, 367, 317)),
* spriteAn_4_inRow_4Rows_3 = new Sprite(*AnFF4inRow1To4Rows, IntRect(0, 0, 368, 368)), * spriteAn_4_inRow_4Rows_4 = new Sprite(*AnFF4inRow1To4Rows, IntRect(367, 647, 367, 292)),
* spriteAn_4_inRow_5Rows_1 = new Sprite(*AnFF4inRow5To8Rows, IntRect(368, 1269, 363, 276)), * spriteAn_4_inRow_5Rows_2 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1104, 717, 368, 343)),
* spriteAn_4_inRow_5Rows_3 = new Sprite(*AnFF4inRow5To8Rows, IntRect(368, 863, 368, 406)), * spriteAn_4_inRow_5Rows_4 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1104, 1060, 367, 311)),
* spriteAn_4_inRow_6Rows_1 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1472, 617, 364, 290)), * spriteAn_4_inRow_6Rows_2 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1104, 0, 368, 368)),
* spriteAn_4_inRow_6Rows_3 = new Sprite(*AnFF4inRow5To8Rows, IntRect(368, 0, 368, 444)), * spriteAn_4_inRow_6Rows_4 = new Sprite(*AnFF4inRow5To8Rows, IntRect(736, 1177, 367, 330)),
* spriteAn_4_inRow_7Rows_1 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1471, 1196, 363, 280)), * spriteAn_4_inRow_7Rows_2 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1104, 368, 368, 349)),
* spriteAn_4_inRow_7Rows_3 = new Sprite(*AnFF4inRow5To8Rows, IntRect(736, 0, 368, 416)), * spriteAn_4_inRow_7Rows_4 = new Sprite(*AnFF4inRow5To8Rows, IntRect(0, 520, 368, 482)),
* spriteAn_4_inRow_7Rows_5 = new Sprite(*AnFF4inRow5To8Rows, IntRect(736, 416, 368, 393)), * spriteAn_4_inRow_7Rows_6 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1472, 315, 365, 302)),
* spriteAn_4_inRow_8Rows_1 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1472, 907, 364, 289)), * spriteAn_4_inRow_8Rows_2 = new Sprite(*AnFF4inRow5To8Rows, IntRect(736, 809, 368, 368)),
* spriteAn_4_inRow_8Rows_3 = new Sprite(*AnFF4inRow5To8Rows, IntRect(0, 1002, 368, 444)), * spriteAn_4_inRow_8Rows_4 = new Sprite(*AnFF4inRow5To8Rows, IntRect(0, 0, 368, 520)),
* spriteAn_4_inRow_8Rows_5 = new Sprite(*AnFF4inRow5To8Rows, IntRect(368, 444, 368, 419)), * spriteAn_4_inRow_8Rows_6 = new Sprite(*AnFF4inRow5To8Rows, IntRect(1472, 0, 365, 315)),
* spriteAn_4_inRow_9Rows_1 = new Sprite(*AnFF4inRow9To11Rows, IntRect(736, 1590, 364, 299)), * spriteAn_4_inRow_9Rows_2 = new Sprite(*AnFF4inRow9To11Rows, IntRect(368, 1600, 368, 387)),
* spriteAn_4_inRow_9Rows_3 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1104, 0, 368, 473)), * spriteAn_4_inRow_9Rows_4 = new Sprite(*AnFF4inRow9To11Rows, IntRect(0, 1230, 368, 558)),
* spriteAn_4_inRow_9Rows_5 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1104, 940, 368, 444)), * spriteAn_4_inRow_9Rows_6 = new Sprite(*AnFF4inRow9To11Rows, IntRect(736, 945, 365, 327)),
* spriteAn_4_inRow_10Rows_1 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1100, 1692, 359, 285)), * spriteAn_4_inRow_10Rows_2 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1472, 1205, 365, 365)),
* spriteAn_4_inRow_10Rows_3 = new Sprite(*AnFF4inRow9To11Rows, IntRect(736, 501, 368, 444)), * spriteAn_4_inRow_10Rows_4 = new Sprite(*AnFF4inRow9To11Rows, IntRect(368, 1080, 368, 520)),
* spriteAn_4_inRow_10Rows_5 = new Sprite(*AnFF4inRow9To11Rows, IntRect(0, 634, 368, 596)), * spriteAn_4_inRow_10Rows_6 = new Sprite(*AnFF4inRow9To11Rows, IntRect(736, 0, 368, 501)),
* spriteAn_4_inRow_10Rows_7 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1472, 422, 365, 403)), * spriteAn_4_inRow_10Rows_8 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1101, 1384, 365, 308)),
* spriteAn_4_inRow_11Rows_1 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1466, 1570, 360, 293)), * spriteAn_4_inRow_11Rows_2 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1472, 825, 365, 380)),
* spriteAn_4_inRow_11Rows_3 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1104, 473, 368, 467)), * spriteAn_4_inRow_11Rows_4 = new Sprite(*AnFF4inRow9To11Rows, IntRect(368, 0, 368, 550)),
* spriteAn_4_inRow_11Rows_5 = new Sprite(*AnFF4inRow9To11Rows, IntRect(0, 0, 368, 634)), * spriteAn_4_inRow_11Rows_6 = new Sprite(*AnFF4inRow9To11Rows, IntRect(368, 550, 368, 530)),
* spriteAn_4_inRow_11Rows_7 = new Sprite(*AnFF4inRow9To11Rows, IntRect(1472, 0, 365, 422)), * spriteAn_4_inRow_11Rows_8 = new Sprite(*AnFF4inRow9To11Rows, IntRect(736, 1272, 365, 318)),
* spriteAn_4_inRow_12Rows_1 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1469, 308, 360, 301)), * spriteAn_4_inRow_12Rows_2 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1104, 852, 365, 396)),
* spriteAn_4_inRow_12Rows_3 = new Sprite(*AnFF4inRow12To13Rows, IntRect(736, 1058, 368, 490)), * spriteAn_4_inRow_12Rows_4 = new Sprite(*AnFF4inRow12To13Rows, IntRect(368, 1300, 368, 581)),
* spriteAn_4_inRow_12Rows_5 = new Sprite(*AnFF4inRow12To13Rows, IntRect(368, 0, 368, 672)), * spriteAn_4_inRow_12Rows_6 = new Sprite(*AnFF4inRow12To13Rows, IntRect(0, 1321, 368, 558)),
* spriteAn_4_inRow_12Rows_7 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1104, 0, 365, 441)), * spriteAn_4_inRow_12Rows_8 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1104, 1626, 365, 327)),
* spriteAn_4_inRow_13Rows_1 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1469, 609, 360, 291)), * spriteAn_4_inRow_13Rows_2 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1104, 1248, 365, 378)),
* spriteAn_4_inRow_13Rows_3 = new Sprite(*AnFF4inRow12To13Rows, IntRect(736, 1548, 368, 463)), * spriteAn_4_inRow_13Rows_4 = new Sprite(*AnFF4inRow12To13Rows, IntRect(736, 0, 368, 545)),
* spriteAn_4_inRow_13Rows_5 = new Sprite(*AnFF4inRow12To13Rows, IntRect(368, 672, 368, 628)), * spriteAn_4_inRow_13Rows_6 = new Sprite(*AnFF4inRow12To13Rows, IntRect(0, 0, 368, 710)),
* spriteAn_4_inRow_13Rows_7 = new Sprite(*AnFF4inRow12To13Rows, IntRect(0, 710, 368, 611)), * spriteAn_4_inRow_13Rows_8 = new Sprite(*AnFF4inRow12To13Rows, IntRect(736, 545, 368, 513)),
* spriteAn_4_inRow_13Rows_9 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1104, 441, 365, 411 )), * spriteAn_4_inRow_13Rows_10 = new Sprite(*AnFF4inRow12To13Rows, IntRect(1469, 0, 360, 308)),
* spriteAn_4_inRow_14Rows_1 = new Sprite(*AnFF4inRow14Rows, IntRect(0, 748, 360, 298)), * spriteAn_4_inRow_14Rows_2 = new Sprite(*AnFF4inRow14Rows, IntRect(736, 642, 365, 390)),
* spriteAn_4_inRow_14Rows_3 = new Sprite(*AnFF4inRow14Rows, IntRect(1472, 535, 368, 482)), * spriteAn_4_inRow_14Rows_4 = new Sprite(*AnFF4inRow14Rows, IntRect(1104, 0, 368, 571)),
* spriteAn_4_inRow_14Rows_5 = new Sprite(*AnFF4inRow14Rows, IntRect(368, 0, 368, 659)), * spriteAn_4_inRow_14Rows_6 = new Sprite(*AnFF4inRow14Rows, IntRect(0, 0, 368, 748)),
* spriteAn_4_inRow_14Rows_7 = new Sprite(*AnFF4inRow14Rows, IntRect(736, 0, 368, 642)), * spriteAn_4_inRow_14Rows_8 = new Sprite(*AnFF4inRow14Rows, IntRect(1472, 0, 368, 535)),
* spriteAn_4_inRow_14Rows_9 = new Sprite(*AnFF4inRow14Rows, IntRect(1104, 571, 365, 426)), * spriteAn_4_inRow_14Rows_10 = new Sprite(*AnFF4inRow14Rows, IntRect(368, 659, 361, 316)),
* spriteAn_4_inRow_15Rows_1 = new Sprite(*AnFF4inRow15Rows, IntRect(0, 786, 360, 304)), * spriteAn_4_inRow_15Rows_2 = new Sprite(*AnFF4inRow15Rows, IntRect(736, 672, 365, 403)),
* spriteAn_4_inRow_15Rows_3 = new Sprite(*AnFF4inRow15Rows, IntRect(1472, 558, 368, 501)), * spriteAn_4_inRow_15Rows_4 = new Sprite(*AnFF4inRow15Rows, IntRect(1104, 0, 368, 596)),
* spriteAn_4_inRow_15Rows_5 = new Sprite(*AnFF4inRow15Rows, IntRect(368, 0, 368, 691)), * spriteAn_4_inRow_15Rows_6 = new Sprite(*AnFF4inRow15Rows, IntRect(0, 0, 368, 786)),
* spriteAn_4_inRow_15Rows_7 = new Sprite(*AnFF4inRow15Rows, IntRect(736, 0, 368, 672)), * spriteAn_4_inRow_15Rows_8 = new Sprite(*AnFF4inRow15Rows, IntRect(1472, 0, 368, 558)),
* spriteAn_4_inRow_15Rows_9 = new Sprite(*AnFF4inRow15Rows, IntRect(1104, 596, 365, 441)), * spriteAn_4_inRow_15Rows_10 = new Sprite(*AnFF4inRow15Rows, IntRect(368, 691, 361, 323)),
* spriteAn_4_inRow_16Rows_1 = new Sprite(*AnFF4inRow16Rows, IntRect(1101, 622, 360, 311)), * spriteAn_4_inRow_16Rows_2 = new Sprite(*AnFF4inRow16Rows, IntRect(736, 1096, 365, 416)),
* spriteAn_4_inRow_16Rows_3 = new Sprite(*AnFF4inRow16Rows, IntRect(0, 1474, 368, 521)), * spriteAn_4_inRow_16Rows_4 = new Sprite(*AnFF4inRow16Rows, IntRect(736, 0, 368, 622)),
* spriteAn_4_inRow_16Rows_5 = new Sprite(*AnFF4inRow16Rows, IntRect(368, 737, 368, 723)), * spriteAn_4_inRow_16Rows_6 = new Sprite(*AnFF4inRow16Rows, IntRect(0, 0, 368, 824)),
* spriteAn_4_inRow_16Rows_7 = new Sprite(*AnFF4inRow16Rows, IntRect(368, 0, 368, 737)), * spriteAn_4_inRow_16Rows_8 = new Sprite(*AnFF4inRow16Rows, IntRect(0, 824, 368, 650)),
* spriteAn_4_inRow_16Rows_9 = new Sprite(*AnFF4inRow16Rows, IntRect(368, 1460, 368, 564)), * spriteAn_4_inRow_16Rows_10 = new Sprite(*AnFF4inRow16Rows, IntRect(736, 622, 365, 474)),
* spriteAn_4_inRow_16Rows_11 = new Sprite(*AnFF4inRow16Rows, IntRect(736, 1512, 365, 387)), * spriteAn_4_inRow_16Rows_12 = new Sprite(*AnFF4inRow16Rows, IntRect(1104, 0, 357, 292)),
* spriteAn_4_inRow_17Rows_1 = new Sprite(*AnFF4inRow17Rows, IntRect(1104, 0, 361, 317)), * spriteAn_4_inRow_17Rows_2 = new Sprite(*AnFF4inRow17Rows, IntRect(736, 1432, 365, 428)),
* spriteAn_4_inRow_17Rows_3 = new Sprite(*AnFF4inRow17Rows, IntRect(368, 1356, 368, 539)), * spriteAn_4_inRow_17Rows_4 = new Sprite(*AnFF4inRow17Rows, IntRect(0, 862, 368, 647)),
* spriteAn_4_inRow_17Rows_5 = new Sprite(*AnFF4inRow17Rows, IntRect(736, 0, 368, 754)), * spriteAn_4_inRow_17Rows_6 = new Sprite(*AnFF4inRow17Rows, IntRect(0, 0, 368, 862)),
* spriteAn_4_inRow_17Rows_7 = new Sprite(*AnFF4inRow17Rows, IntRect(368, 0, 368, 770)), * spriteAn_4_inRow_17Rows_8 = new Sprite(*AnFF4inRow17Rows, IntRect(736, 754, 368, 678)),
* spriteAn_4_inRow_17Rows_9 = new Sprite(*AnFF4inRow17Rows, IntRect(368, 770, 368, 586)), * spriteAn_4_inRow_17Rows_10 = new Sprite(*AnFF4inRow17Rows, IntRect(0, 1509, 365, 490)),
* spriteAn_4_inRow_17Rows_11 = new Sprite(*AnFF4inRow17Rows, IntRect(1101, 1432, 365, 398)), * spriteAn_4_inRow_17Rows_12 = new Sprite(*AnFF4inRow17Rows, IntRect(1104, 317, 357, 298)),
* spriteAn_4_inRow_18Rows_1 = new Sprite(*AnFF4inRow18Rows, IntRect(1104, 0, 361, 323)), * spriteAn_4_inRow_18Rows_2 = new Sprite(*AnFF4inRow18Rows, IntRect(0, 1572, 365, 441)),
* spriteAn_4_inRow_18Rows_3 = new Sprite(*AnFF4inRow18Rows, IntRect(368, 1409, 368, 558)), * spriteAn_4_inRow_18Rows_4 = new Sprite(*AnFF4inRow18Rows, IntRect(0, 900, 368, 672)),
* spriteAn_4_inRow_18Rows_5 = new Sprite(*AnFF4inRow18Rows, IntRect(736, 0, 368, 786)), * spriteAn_4_inRow_18Rows_6 = new Sprite(*AnFF4inRow18Rows, IntRect(0, 0, 368, 900)),
* spriteAn_4_inRow_18Rows_7 = new Sprite(*AnFF4inRow18Rows, IntRect(368, 0, 368, 802)), * spriteAn_4_inRow_18Rows_8 = new Sprite(*AnFF4inRow18Rows, IntRect(736, 786, 368, 705)),
* spriteAn_4_inRow_18Rows_9 = new Sprite(*AnFF4inRow18Rows, IntRect(368, 802, 368, 607)), * spriteAn_4_inRow_18Rows_10 = new Sprite(*AnFF4inRow18Rows, IntRect(735, 1491, 365, 506)),
* spriteAn_4_inRow_18Rows_11 = new Sprite(*AnFF4inRow18Rows, IntRect(1101, 1491, 365, 409)), * spriteAn_4_inRow_18Rows_12 = new Sprite(*AnFF4inRow18Rows, IntRect(1104, 323, 357, 303));

//* sprite_loading_screen = new Sprite(*loading_screen_tex);

	//sprite->setColor(Color(255, 255, 255, 255));//непрозрачность

	

	//Text
	Font *font = LoadFontFromResource(IDR_JPEG2, "JPEG");
	USHORT fontSize{ 37 };
	Text *lefttext{ new Text("Score:\nBest score:\nLevel:\nLines:\nSpeed:", *font, fontSize) };
	Text *shOfLefttext{ new Text("Score:\nBest score: \nLevel: \nLines: \nSpeed: ", *font, fontSize) };

	lefttext->setFillColor(Color(118, 36, 182));
	//lefttext->setLineSpacing(2.f);
	//lefttext->setOutlineColor(Color(29, 17, 55));
	//lefttext->setOutlineThickness(2.f);

	shOfLefttext->setFillColor(Color(3, 6, 18));
	//shOfLefttext->setLineSpacing(2.f);
	

	UINT scoreInt{ 0 };
	//Text *score{ new Text("100500", *font, fontSize) };
	Text *score{ new Text("100500", *font, fontSize) };
	Text *shOfScore{ new Text("100500", *font, fontSize) };
	score->setFillColor(Color(219, 217, 44));
	
	shOfScore->setFillColor(Color(3, 6, 18));
	
	//cout << numeric_limits<unsigned int>::max() << endl;
	//cout << thread::hardware_concurrency();

	UINT best_scoreInt{ 0 };
	Text *best_score{ new Text("999999", *font, fontSize) };
	Text *shOfBest_score{ new Text("999999", *font, fontSize) };
	best_score->setFillColor(Color(219, 217, 44));
	
	shOfBest_score->setFillColor(Color(3, 6, 18));

	USHORT levelInt{ 0 };
	Text *level{ new Text( "350", *font, fontSize )};
	Text *shOfLevel{ new Text( "350", *font, fontSize )};
	level->setFillColor(Color(219, 217, 44));
	
	shOfLevel->setFillColor(Color(3, 6, 18));
	

	UINT linesInt{ 0 };
	Text *lines{ new Text( "1600", *font, fontSize )};
	Text *shOfLines{ new Text( "1600", *font, fontSize )};
	lines->setFillColor(Color(219, 217, 44));
	
	shOfLines->setFillColor(Color(3, 6, 18));
	

	USHORT speedInt{ 0 };
	Text *speed{ new Text( "10X", *font, fontSize )};
	Text *shOfSpeed{ new Text( "10X", *font, fontSize )};
	speed->setFillColor(Color(219, 217, 44));
	
	shOfSpeed->setFillColor(Color(3, 6, 18));
	

	Text *player{ new Text( "Player:", *font, fontSize - 3 )}; // Уменьшил шрифт на 3 чтобы влезало имя
	Text *shOfPlayer{ new Text( "Player:", *font, fontSize - 3 )};
	player->setFillColor(Color(118, 36, 182));
	
	shOfPlayer->setFillColor(Color(3, 6, 18));
	

	string namestr{ "Your name is bad" };//17 символов максимум делать
	Text *name{ new Text( namestr, *font, fontSize )};
	Text *shOfName{ new Text( namestr, *font, fontSize )};
	name->setFillColor(Color(219, 217, 44));
	//USHORT x1 = 1353 + player->getLocalBounds().width;
	//name->setPosition(408 - player->getLocalBounds().width-name->getLocalBounds().width + x1, 338);
	
	shOfName->setFillColor(Color(3, 6, 18));
	//shOfName->setPosition(408 - player->getLocalBounds().width - name->getLocalBounds().width + x1 + 3, 341);//+3px
	

	USHORT nameX = 1761 - name->getLocalBounds().width;
	USHORT nameY = 338;
	USHORT shOfNameX = 1761 - name->getLocalBounds().width + 3;
	USHORT shOfNameY = 341;



	Text *time2{ new Text( "Time:", *font, fontSize )};
	Text *shOfTime{ new Text( "Time:", *font, fontSize )};
	time2->setFillColor(Color(118, 36, 182));
	
	shOfTime->setFillColor(Color(3, 6, 18));
	

	
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
	
	shOfClockTime->setFillColor(Color(3, 6, 18));
	

	

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

	/*for_loading_scr = false;*/
	

	// Объект, который является главным окном приложения
	// 
	ContextSettings* context = new ContextSettings(0, 0, 2);//antialliasing
	for_loading_scr = false;
	
	//RenderWindow window(VideoMode(1920, 1080), "brick", /*Style::Close | Style::Titlebar |*/ Style::Fullscreen);
	RenderWindow window(VideoMode().getFullscreenModes()[0], "Tetris", Style::None, *context);
	//RenderWindow window(VideoMode(1280, 1024), "Tetris", Style::None, *context);
	//RenderWindow window(VideoMode().getDesktopMode(), "Tetris", Style::None, *context);
	//RenderWindow window(VideoMode(800, 600), "Tetris", Style::Titlebar, *context);

	//View * vi = new View();
	//vi->setCenter(1920 / 2, 1080 / 2);
	//vi->setSize(3840, 2160);
	//window.setView(*vi);
	
	SetForegroundWindow(window.getSystemHandle());//чтобы сделать окно активным
	//window.requestFocus();

	Image* icon = LoadImageFromResource(IDB_PNG1, "PNG");
	window.setIcon(38, 38, icon->getPixelsPtr());

	//МАСШТАБИРОВАНИЕ
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	scalemark:
	Vector2f fscale = factorOfScaleFn(window);
	sprite_background->setScale(fscale);
	//sprite_table->setScale(fscale);
	sprite_table2->setScale(fscale);
	
	
	sprite->setScale(fscale);
	sprite_myCursor->setScale(fscale);
	sprite->scale(0.5, 0.5);//стандартное масштабирование
	sprite_myCursor->scale(0.7f, 0.7f);//стандартное масштабирование

	sprite_button_start_st1->setScale(fscale);
	sprite_button_start_st2->setScale(fscale);
	sprite_button_start_st3->setScale(fscale);

	sprite_button_newgame_st1->setScale(fscale);
	sprite_button_newgame_st2->setScale(fscale);
	sprite_button_newgame_st3->setScale(fscale);

	sprite_left_frame->setScale(fscale);
	sprite_right_frame->setScale(fscale);
	sprite_right_frame_bottom->setScale(fscale);

	sprite_button_left_st1->setScale(fscale);
	sprite_button_left_st2->setScale(fscale);
	sprite_button_left_st3->setScale(fscale);

	sprite_button_middle_restore_st1->setScale(fscale);
	sprite_button_middle_restore_st2->setScale(fscale);
	sprite_button_middle_restore_st3->setScale(fscale);

	sprite_button_right_st1->setScale(fscale);
	sprite_button_right_st2->setScale(fscale);
	sprite_button_right_st3->setScale(fscale);

	sprite_button_options_st1->setScale(fscale);
	sprite_button_options_st2->setScale(fscale);
	sprite_button_options_st3->setScale(fscale);

	sprite_button_pause_st1->setScale(fscale);
	//sprite_button_pause_st2->setScale(fscale);
	sprite_button_pause_st3->setScale(fscale);
	sprite_button_pause_st4->setScale(fscale);

	//sprite_button_musicOff_st1->setScale(fscale);
	//sprite_button_musicOff_st2->setScale(fscale);
	//sprite_button_musicOff_st3->setScale(fscale);
	
	//sprite_button_soundOff_st1->setScale(fscale);
	//sprite_button_soundOff_st2->setScale(fscale);
	//sprite_button_soundOff_st3->setScale(fscale);

	sprite_button_soundOn_st1->setScale(fscale);
	//sprite_button_soundOn_st2->setScale(fscale);
	sprite_button_soundOn_st3->setScale(fscale);
	sprite_button_soundOn_st4->setScale(fscale);

	sprite_button_musicOn_st1->setScale(fscale);
	//sprite_button_musicOn_st2->setScale(fscale);
	sprite_button_musicOn_st3->setScale(fscale);
	sprite_button_musicOn_st4->setScale(fscale);

	sprite_ays_frame->setScale(fscale);
	sprite_ays_yes1st->setScale(fscale);
	sprite_ays_yes2st->setScale(fscale);
	sprite_ays_no1st->setScale(fscale);
	sprite_ays_no2st->setScale(fscale);
	sprite_ays_question->setScale(fscale);

	sprite_I_black->setScale(fscale);
	sprite_I_blue->setScale(fscale);
	sprite_I_brown->setScale(fscale);
	sprite_I_green->setScale(fscale);
	sprite_I_orange->setScale(fscale);
	sprite_I_pink->setScale(fscale);
	sprite_I_purple->setScale(fscale);
	sprite_I_red->setScale(fscale);
	sprite_I_yellow->setScale(fscale);

	sprite_J_black->setScale(fscale);
	sprite_J_blue->setScale(fscale);
	sprite_J_brown->setScale(fscale);
	sprite_J_green->setScale(fscale);
	sprite_J_orange->setScale(fscale);
	sprite_J_pink->setScale(fscale);
	sprite_J_purple->setScale(fscale);
	sprite_J_red->setScale(fscale);
	sprite_J_yellow->setScale(fscale);

	sprite_L_black->setScale(fscale);
	sprite_L_blue->setScale(fscale);
	sprite_L_brown->setScale(fscale);
	sprite_L_green->setScale(fscale);
	sprite_L_orange->setScale(fscale);
	sprite_L_pink->setScale(fscale);
	sprite_L_purple->setScale(fscale);
	sprite_L_red->setScale(fscale);
	sprite_L_yellow->setScale(fscale);

	sprite_O_black->setScale(fscale);
	sprite_O_blue->setScale(fscale);
	sprite_O_brown->setScale(fscale);
	sprite_O_green->setScale(fscale);
	sprite_O_orange->setScale(fscale);
	sprite_O_pink->setScale(fscale);
	sprite_O_purple->setScale(fscale);
	sprite_O_red->setScale(fscale);
	sprite_O_yellow->setScale(fscale);

	sprite_S_black->setScale(fscale);
	sprite_S_blue->setScale(fscale);
	sprite_S_brown->setScale(fscale);
	sprite_S_green->setScale(fscale);
	sprite_S_orange->setScale(fscale);
	sprite_S_pink->setScale(fscale);
	sprite_S_purple->setScale(fscale);
	sprite_S_red->setScale(fscale);
	sprite_S_yellow->setScale(fscale);

	sprite_T_black->setScale(fscale);
	sprite_T_blue->setScale(fscale);
	sprite_T_brown->setScale(fscale);
	sprite_T_green->setScale(fscale);
	sprite_T_orange->setScale(fscale);
	sprite_T_pink->setScale(fscale);
	sprite_T_purple->setScale(fscale);
	sprite_T_red->setScale(fscale);
	sprite_T_yellow->setScale(fscale);

	sprite_Z_black->setScale(fscale);
	sprite_Z_blue->setScale(fscale);
	sprite_Z_brown->setScale(fscale);
	sprite_Z_green->setScale(fscale);
	sprite_Z_orange->setScale(fscale);
	sprite_Z_pink->setScale(fscale);
	sprite_Z_purple->setScale(fscale);
	sprite_Z_red->setScale(fscale);
	sprite_Z_yellow->setScale(fscale);

	lefttext->setPosition(155.61f * fscale.x, 350.44f * fscale.y); 
	lefttext->setLineSpacing(2.f);
	lefttext->setScale(fscale);

	shOfLefttext->setPosition(158.61f * fscale.x, 353.44f * fscale.y);//+3px
	shOfLefttext->setLineSpacing(2.f);
	shOfLefttext->setScale(fscale);

	score->setPosition((((408.8f / 2) - score->getLocalBounds().width) + 360.01f) * fscale.x, 350.44f * fscale.y);
	score->setScale(fscale);

	shOfScore->setPosition((((408.8f / 2) - score->getLocalBounds().width) + 363.01f) * fscale.x, 353.44f * fscale.y);//+3px
	shOfScore->setScale(fscale);

	best_score->setPosition((((408.8f / 2) - best_score->getLocalBounds().width) + 360.01f) * fscale.x, (86 + 350.44f) * fscale.y);
	best_score->setScale(fscale);

	shOfBest_score->setPosition((((408.8f / 2) - best_score->getLocalBounds().width) + 363.01f) * fscale.x, (86 + 353.44f) * fscale.y);//+3px
	shOfBest_score->setScale(fscale);

	level->setPosition((((408.8f / 2) - level->getLocalBounds().width) + 360.01f) * fscale.x, (172 + 350.44f) * fscale.y);
	level->setScale(fscale);

	shOfLevel->setPosition((((408.8f / 2) - level->getLocalBounds().width) + 363.01f) * fscale.x, (172 + 353.44f) * fscale.y);//+3px
	shOfLevel->setScale(fscale);

	lines->setPosition((((408.8f / 2) - lines->getLocalBounds().width) + 360.01f) * fscale.x, (258 + 350.44f) * fscale.y);
	lines->setScale(fscale);

	shOfLines->setPosition((((408.8f / 2) - lines->getLocalBounds().width) + 363.01f) * fscale.x, (258 + 353.44f) * fscale.y);//+3px
	shOfLines->setScale(fscale);

	speed->setPosition((((408.8f / 2) - speed->getLocalBounds().width) + 360.01f) * fscale.x, (344 + 350.44f) * fscale.y);
	speed->setScale(fscale);

	shOfSpeed->setPosition((((408.8f / 2) - speed->getLocalBounds().width) + 363.01f) * fscale.x, (344 + 353.44f) * fscale.y);//+3px
	shOfSpeed->setScale(fscale);

	player->setPosition(1353 * fscale.x, (338 + 3) * fscale.y);
	player->setScale(fscale);

	shOfPlayer->setPosition(1356 * fscale.x, (341 + 3) * fscale.y);//+3px
	shOfPlayer->setScale(fscale);

	name->setPosition((1761 - name->getLocalBounds().width) * fscale.x, 338 * fscale.y);
	name->setScale(fscale);

	shOfName->setPosition((1761 - name->getLocalBounds().width + 3) * fscale.x, 341 * fscale.y); 
	shOfName->setScale(fscale);

	if (namestr.size() > 12)
	{
		for (USHORT i = 13; i < 18; i++)
		{
			if (namestr.size() == i)
			{
				name->setCharacterSize(fontSize - (i - 12) * 3);
				shOfName->setCharacterSize(fontSize - (i - 12) * 3);
				name->setPosition((1761 - name->getLocalBounds().width) * fscale.x, (338 + (i - 12) * 3) * fscale.y);
				shOfName->setPosition((1761 - name->getLocalBounds().width + 3) * fscale.x, (341 + (i - 12) * 3) * fscale.y);
			}
		}
	}

	time2->setPosition(1353 * fscale.x, 535 * fscale.y);
	time2->setScale(fscale);

	shOfTime->setPosition(1356 * fscale.x, 538 * fscale.y);//+3px
	shOfTime->setScale(fscale);

	clockTime->setPosition((1761 - clockTime->getLocalBounds().width) * fscale.x, 535 * fscale.y);
	clockTime->setScale(fscale);

	shOfClockTime->setPosition((1761 - clockTime->getLocalBounds().width + 3) * fscale.x, 538 * fscale.y);
	shOfClockTime->setScale(fscale);

	spriteAn_1line_1->setScale(fscale);
	spriteAn_1line_2->setScale(fscale);
	spriteAn_1line_3->setScale(fscale);
	spriteAn_1line_4->setScale(fscale);
	spriteAn_1line_5->setScale(fscale);
	spriteAn_1line_6->setScale(fscale);
	spriteAn_1line_7->setScale(fscale);
	spriteAn_1line_8->setScale(fscale);
	spriteAn_1line_9->setScale(fscale);
	spriteAn_1line_10->setScale(fscale);
	spriteAn_1line_11->setScale(fscale);
	spriteAn_1line_12->setScale(fscale);
	spriteAn_1line_13->setScale(fscale);
	spriteAn_1line_14->setScale(fscale);
	spriteAn_1line_15->setScale(fscale);
	spriteAn_1line_16->setScale(fscale);
	spriteAn_1line_17->setScale(fscale);
	spriteAn_1line_18->setScale(fscale);
	spriteAn_1line_19->setScale(fscale);
	spriteAn_1line_20->setScale(fscale);
	spriteAn_1line_21->setScale(fscale);
	spriteAn_1line_22->setScale(fscale);

	spriteAn_2lines_1->setScale(fscale);
	spriteAn_2lines_2->setScale(fscale);
	spriteAn_2lines_3->setScale(fscale);
	spriteAn_2lines_4->setScale(fscale);
	spriteAn_2lines_5->setScale(fscale);
	spriteAn_2lines_6->setScale(fscale);
	spriteAn_2lines_7->setScale(fscale);
	spriteAn_2lines_8->setScale(fscale);
	spriteAn_2lines_9->setScale(fscale);
	spriteAn_2lines_10->setScale(fscale);
	spriteAn_2lines_11->setScale(fscale);
	spriteAn_2lines_12->setScale(fscale);
	spriteAn_2lines_13->setScale(fscale);
	spriteAn_2lines_14->setScale(fscale);
	spriteAn_2lines_15->setScale(fscale);
	spriteAn_2lines_16->setScale(fscale);
	spriteAn_2lines_17->setScale(fscale);
	spriteAn_2lines_18->setScale(fscale);
	spriteAn_2lines_19->setScale(fscale);
	spriteAn_2lines_20->setScale(fscale);
	spriteAn_2lines_21->setScale(fscale);
	spriteAn_2lines_22->setScale(fscale);

	spriteAn_3lines_1->setScale(fscale);
	spriteAn_3lines_2->setScale(fscale);
	spriteAn_3lines_3->setScale(fscale);
	spriteAn_3lines_4->setScale(fscale);
	spriteAn_3lines_5->setScale(fscale);
	spriteAn_3lines_6->setScale(fscale);
	spriteAn_3lines_7->setScale(fscale);
	spriteAn_3lines_8->setScale(fscale);
	spriteAn_3lines_9->setScale(fscale);
	spriteAn_3lines_10->setScale(fscale);
	spriteAn_3lines_11->setScale(fscale);
	spriteAn_3lines_12->setScale(fscale);
	spriteAn_3lines_13->setScale(fscale);
	spriteAn_3lines_14->setScale(fscale);
	spriteAn_3lines_15->setScale(fscale);
	spriteAn_3lines_16->setScale(fscale);
	spriteAn_3lines_17->setScale(fscale);
	spriteAn_3lines_18->setScale(fscale);
	spriteAn_3lines_19->setScale(fscale);
	spriteAn_3lines_20->setScale(fscale);
	spriteAn_3lines_21->setScale(fscale);
	spriteAn_3lines_22->setScale(fscale);

	spriteAn_4lines_1->setScale(fscale);
	spriteAn_4lines_2->setScale(fscale);
	spriteAn_4lines_3->setScale(fscale);
	spriteAn_4lines_4->setScale(fscale);
	spriteAn_4lines_5->setScale(fscale);
	spriteAn_4lines_6->setScale(fscale);
	spriteAn_4lines_7->setScale(fscale);
	spriteAn_4lines_8->setScale(fscale);
	spriteAn_4lines_9->setScale(fscale);
	spriteAn_4lines_10->setScale(fscale);
	spriteAn_4lines_11->setScale(fscale);
	spriteAn_4lines_12->setScale(fscale);
	spriteAn_4lines_13->setScale(fscale);
	spriteAn_4lines_14->setScale(fscale);
	spriteAn_4lines_15->setScale(fscale);
	spriteAn_4lines_16->setScale(fscale);
	spriteAn_4lines_17->setScale(fscale);
	spriteAn_4lines_18->setScale(fscale);
	spriteAn_4lines_19->setScale(fscale);
	spriteAn_4lines_20->setScale(fscale);
	spriteAn_4lines_21->setScale(fscale);
	spriteAn_4lines_22->setScale(fscale);

	spriteAn_1_inRow_1Row_1->setScale(fscale);
	spriteAn_1_inRow_1Row_2->setScale(fscale);
	spriteAn_1_inRow_2Rows_1->setScale(fscale);
	spriteAn_1_inRow_2Rows_2->setScale(fscale);
	spriteAn_1_inRow_3Rows_1->setScale(fscale);
	spriteAn_1_inRow_3Rows_2->setScale(fscale);
	spriteAn_1_inRow_4Rows_1->setScale(fscale);
	spriteAn_1_inRow_4Rows_2->setScale(fscale);
	spriteAn_1_inRow_4Rows_3->setScale(fscale);
	spriteAn_1_inRow_4Rows_4->setScale(fscale);
	spriteAn_1_inRow_5Rows_1->setScale(fscale);
	spriteAn_1_inRow_5Rows_2->setScale(fscale);
	spriteAn_1_inRow_5Rows_3->setScale(fscale);
	spriteAn_1_inRow_5Rows_4->setScale(fscale);
	spriteAn_1_inRow_6Rows_1->setScale(fscale);
	spriteAn_1_inRow_6Rows_2->setScale(fscale);
	spriteAn_1_inRow_6Rows_3->setScale(fscale);
	spriteAn_1_inRow_6Rows_4->setScale(fscale);
	spriteAn_1_inRow_7Rows_1->setScale(fscale);
	spriteAn_1_inRow_7Rows_2->setScale(fscale);
	spriteAn_1_inRow_7Rows_3->setScale(fscale);
	spriteAn_1_inRow_7Rows_4->setScale(fscale);
	spriteAn_1_inRow_7Rows_5->setScale(fscale);
	spriteAn_1_inRow_7Rows_6->setScale(fscale);
	spriteAn_1_inRow_8Rows_1->setScale(fscale);
	spriteAn_1_inRow_8Rows_2->setScale(fscale);
	spriteAn_1_inRow_8Rows_3->setScale(fscale);
	spriteAn_1_inRow_8Rows_4->setScale(fscale);
	spriteAn_1_inRow_8Rows_5->setScale(fscale);
	spriteAn_1_inRow_8Rows_6->setScale(fscale);
	spriteAn_1_inRow_9Rows_1->setScale(fscale);
	spriteAn_1_inRow_9Rows_2->setScale(fscale);
	spriteAn_1_inRow_9Rows_3->setScale(fscale);
	spriteAn_1_inRow_9Rows_4->setScale(fscale);
	spriteAn_1_inRow_9Rows_5->setScale(fscale);
	spriteAn_1_inRow_9Rows_6->setScale(fscale);
	spriteAn_1_inRow_10Rows_1->setScale(fscale);
	spriteAn_1_inRow_10Rows_2->setScale(fscale);
	spriteAn_1_inRow_10Rows_3->setScale(fscale);
	spriteAn_1_inRow_10Rows_4->setScale(fscale);
	spriteAn_1_inRow_10Rows_5->setScale(fscale);
	spriteAn_1_inRow_10Rows_6->setScale(fscale);
	spriteAn_1_inRow_10Rows_7->setScale(fscale);
	spriteAn_1_inRow_10Rows_8->setScale(fscale);
	spriteAn_1_inRow_11Rows_1->setScale(fscale);
	spriteAn_1_inRow_11Rows_2->setScale(fscale);
	spriteAn_1_inRow_11Rows_3->setScale(fscale);
	spriteAn_1_inRow_11Rows_4->setScale(fscale);
	spriteAn_1_inRow_11Rows_5->setScale(fscale);
	spriteAn_1_inRow_11Rows_6->setScale(fscale);
	spriteAn_1_inRow_11Rows_7->setScale(fscale);
	spriteAn_1_inRow_11Rows_8->setScale(fscale);
	spriteAn_1_inRow_12Rows_1->setScale(fscale);
	spriteAn_1_inRow_12Rows_2->setScale(fscale);
	spriteAn_1_inRow_12Rows_3->setScale(fscale);
	spriteAn_1_inRow_12Rows_4->setScale(fscale);
	spriteAn_1_inRow_12Rows_5->setScale(fscale);
	spriteAn_1_inRow_12Rows_6->setScale(fscale);
	spriteAn_1_inRow_12Rows_7->setScale(fscale);
	spriteAn_1_inRow_12Rows_8->setScale(fscale);
	spriteAn_1_inRow_13Rows_1->setScale(fscale);
	spriteAn_1_inRow_13Rows_2->setScale(fscale);
	spriteAn_1_inRow_13Rows_3->setScale(fscale);
	spriteAn_1_inRow_13Rows_4->setScale(fscale);
	spriteAn_1_inRow_13Rows_5->setScale(fscale);
	spriteAn_1_inRow_13Rows_6->setScale(fscale);
	spriteAn_1_inRow_13Rows_7->setScale(fscale);
	spriteAn_1_inRow_13Rows_8->setScale(fscale);
	spriteAn_1_inRow_13Rows_9->setScale(fscale);
	spriteAn_1_inRow_13Rows_10->setScale(fscale);
	spriteAn_1_inRow_14Rows_1->setScale(fscale);
	spriteAn_1_inRow_14Rows_2->setScale(fscale);
	spriteAn_1_inRow_14Rows_3->setScale(fscale);
	spriteAn_1_inRow_14Rows_4->setScale(fscale);
	spriteAn_1_inRow_14Rows_5->setScale(fscale);
	spriteAn_1_inRow_14Rows_6->setScale(fscale);
	spriteAn_1_inRow_14Rows_7->setScale(fscale);
	spriteAn_1_inRow_14Rows_8->setScale(fscale);
	spriteAn_1_inRow_14Rows_9->setScale(fscale);
	spriteAn_1_inRow_14Rows_10->setScale(fscale);
	spriteAn_1_inRow_15Rows_1->setScale(fscale);
	spriteAn_1_inRow_15Rows_2->setScale(fscale);
	spriteAn_1_inRow_15Rows_3->setScale(fscale);
	spriteAn_1_inRow_15Rows_4->setScale(fscale);
	spriteAn_1_inRow_15Rows_5->setScale(fscale);
	spriteAn_1_inRow_15Rows_6->setScale(fscale);
	spriteAn_1_inRow_15Rows_7->setScale(fscale);
	spriteAn_1_inRow_15Rows_8->setScale(fscale);
	spriteAn_1_inRow_15Rows_9->setScale(fscale);
	spriteAn_1_inRow_15Rows_10->setScale(fscale);
	spriteAn_1_inRow_16Rows_1->setScale(fscale);
	spriteAn_1_inRow_16Rows_2->setScale(fscale);
	spriteAn_1_inRow_16Rows_3->setScale(fscale);
	spriteAn_1_inRow_16Rows_4->setScale(fscale);
	spriteAn_1_inRow_16Rows_5->setScale(fscale);
	spriteAn_1_inRow_16Rows_6->setScale(fscale);
	spriteAn_1_inRow_16Rows_7->setScale(fscale);
	spriteAn_1_inRow_16Rows_8->setScale(fscale);
	spriteAn_1_inRow_16Rows_9->setScale(fscale);
	spriteAn_1_inRow_16Rows_10->setScale(fscale);
	spriteAn_1_inRow_16Rows_11->setScale(fscale);
	spriteAn_1_inRow_16Rows_12->setScale(fscale);
	spriteAn_1_inRow_17Rows_1->setScale(fscale);
	spriteAn_1_inRow_17Rows_2->setScale(fscale);
	spriteAn_1_inRow_17Rows_3->setScale(fscale);
	spriteAn_1_inRow_17Rows_4->setScale(fscale);
	spriteAn_1_inRow_17Rows_5->setScale(fscale);
	spriteAn_1_inRow_17Rows_6->setScale(fscale);
	spriteAn_1_inRow_17Rows_7->setScale(fscale);
	spriteAn_1_inRow_17Rows_8->setScale(fscale);
	spriteAn_1_inRow_17Rows_9->setScale(fscale);
	spriteAn_1_inRow_17Rows_10->setScale(fscale);
	spriteAn_1_inRow_17Rows_11->setScale(fscale);
	spriteAn_1_inRow_17Rows_12->setScale(fscale);


	spriteAn_2_inRow_1Row_1->setScale(fscale);
	spriteAn_2_inRow_1Row_2->setScale(fscale);
	spriteAn_2_inRow_2Rows_1->setScale(fscale);
	spriteAn_2_inRow_2Rows_2->setScale(fscale);
	spriteAn_2_inRow_3Rows_1->setScale(fscale);
	spriteAn_2_inRow_3Rows_2->setScale(fscale);
	spriteAn_2_inRow_4Rows_1->setScale(fscale);
	spriteAn_2_inRow_4Rows_2->setScale(fscale);
	spriteAn_2_inRow_4Rows_3->setScale(fscale);
	spriteAn_2_inRow_4Rows_4->setScale(fscale);
	spriteAn_2_inRow_5Rows_1->setScale(fscale);
	spriteAn_2_inRow_5Rows_2->setScale(fscale);
	spriteAn_2_inRow_5Rows_3->setScale(fscale);
	spriteAn_2_inRow_5Rows_4->setScale(fscale);
	spriteAn_2_inRow_6Rows_1->setScale(fscale);
	spriteAn_2_inRow_6Rows_2->setScale(fscale);
	spriteAn_2_inRow_6Rows_3->setScale(fscale);
	spriteAn_2_inRow_6Rows_4->setScale(fscale);
	spriteAn_2_inRow_7Rows_1->setScale(fscale);
	spriteAn_2_inRow_7Rows_2->setScale(fscale);
	spriteAn_2_inRow_7Rows_3->setScale(fscale);
	spriteAn_2_inRow_7Rows_4->setScale(fscale);
	spriteAn_2_inRow_7Rows_5->setScale(fscale);
	spriteAn_2_inRow_7Rows_6->setScale(fscale);
	spriteAn_2_inRow_8Rows_1->setScale(fscale);
	spriteAn_2_inRow_8Rows_2->setScale(fscale);
	spriteAn_2_inRow_8Rows_3->setScale(fscale);
	spriteAn_2_inRow_8Rows_4->setScale(fscale);
	spriteAn_2_inRow_8Rows_5->setScale(fscale);
	spriteAn_2_inRow_8Rows_6->setScale(fscale);
	spriteAn_2_inRow_9Rows_1->setScale(fscale);
	spriteAn_2_inRow_9Rows_2->setScale(fscale);
	spriteAn_2_inRow_9Rows_3->setScale(fscale);
	spriteAn_2_inRow_9Rows_4->setScale(fscale);
	spriteAn_2_inRow_9Rows_5->setScale(fscale);
	spriteAn_2_inRow_9Rows_6->setScale(fscale);
	spriteAn_2_inRow_10Rows_1->setScale(fscale);
	spriteAn_2_inRow_10Rows_2->setScale(fscale);
	spriteAn_2_inRow_10Rows_3->setScale(fscale);
	spriteAn_2_inRow_10Rows_4->setScale(fscale);
	spriteAn_2_inRow_10Rows_5->setScale(fscale);
	spriteAn_2_inRow_10Rows_6->setScale(fscale);
	spriteAn_2_inRow_10Rows_7->setScale(fscale);
	spriteAn_2_inRow_10Rows_8->setScale(fscale);
	spriteAn_2_inRow_11Rows_1->setScale(fscale);
	spriteAn_2_inRow_11Rows_2->setScale(fscale);
	spriteAn_2_inRow_11Rows_3->setScale(fscale);
	spriteAn_2_inRow_11Rows_4->setScale(fscale);
	spriteAn_2_inRow_11Rows_5->setScale(fscale);
	spriteAn_2_inRow_11Rows_6->setScale(fscale);
	spriteAn_2_inRow_11Rows_7->setScale(fscale);
	spriteAn_2_inRow_11Rows_8->setScale(fscale);
	spriteAn_2_inRow_12Rows_1->setScale(fscale);
	spriteAn_2_inRow_12Rows_2->setScale(fscale);
	spriteAn_2_inRow_12Rows_3->setScale(fscale);
	spriteAn_2_inRow_12Rows_4->setScale(fscale);
	spriteAn_2_inRow_12Rows_5->setScale(fscale);
	spriteAn_2_inRow_12Rows_6->setScale(fscale);
	spriteAn_2_inRow_12Rows_7->setScale(fscale);
	spriteAn_2_inRow_12Rows_8->setScale(fscale);
	spriteAn_2_inRow_13Rows_1->setScale(fscale);
	spriteAn_2_inRow_13Rows_2->setScale(fscale);
	spriteAn_2_inRow_13Rows_3->setScale(fscale);
	spriteAn_2_inRow_13Rows_4->setScale(fscale);
	spriteAn_2_inRow_13Rows_5->setScale(fscale);
	spriteAn_2_inRow_13Rows_6->setScale(fscale);
	spriteAn_2_inRow_13Rows_7->setScale(fscale);
	spriteAn_2_inRow_13Rows_8->setScale(fscale);
	spriteAn_2_inRow_13Rows_9->setScale(fscale);
	spriteAn_2_inRow_13Rows_10->setScale(fscale);
	spriteAn_2_inRow_14Rows_1->setScale(fscale);
	spriteAn_2_inRow_14Rows_2->setScale(fscale);
	spriteAn_2_inRow_14Rows_3->setScale(fscale);
	spriteAn_2_inRow_14Rows_4->setScale(fscale);
	spriteAn_2_inRow_14Rows_5->setScale(fscale);
	spriteAn_2_inRow_14Rows_6->setScale(fscale);
	spriteAn_2_inRow_14Rows_7->setScale(fscale);
	spriteAn_2_inRow_14Rows_8->setScale(fscale);
	spriteAn_2_inRow_14Rows_9->setScale(fscale);
	spriteAn_2_inRow_14Rows_10->setScale(fscale);
	spriteAn_2_inRow_15Rows_1->setScale(fscale);
	spriteAn_2_inRow_15Rows_2->setScale(fscale);
	spriteAn_2_inRow_15Rows_3->setScale(fscale);
	spriteAn_2_inRow_15Rows_4->setScale(fscale);
	spriteAn_2_inRow_15Rows_5->setScale(fscale);
	spriteAn_2_inRow_15Rows_6->setScale(fscale);
	spriteAn_2_inRow_15Rows_7->setScale(fscale);
	spriteAn_2_inRow_15Rows_8->setScale(fscale);
	spriteAn_2_inRow_15Rows_9->setScale(fscale);
	spriteAn_2_inRow_15Rows_10->setScale(fscale);
	spriteAn_2_inRow_16Rows_1->setScale(fscale);
	spriteAn_2_inRow_16Rows_2->setScale(fscale);
	spriteAn_2_inRow_16Rows_3->setScale(fscale);
	spriteAn_2_inRow_16Rows_4->setScale(fscale);
	spriteAn_2_inRow_16Rows_5->setScale(fscale);
	spriteAn_2_inRow_16Rows_6->setScale(fscale);
	spriteAn_2_inRow_16Rows_7->setScale(fscale);
	spriteAn_2_inRow_16Rows_8->setScale(fscale);
	spriteAn_2_inRow_16Rows_9->setScale(fscale);
	spriteAn_2_inRow_16Rows_10->setScale(fscale);
	spriteAn_2_inRow_16Rows_11->setScale(fscale);
	spriteAn_2_inRow_16Rows_12->setScale(fscale);
	spriteAn_2_inRow_17Rows_1->setScale(fscale);
	spriteAn_2_inRow_17Rows_2->setScale(fscale);
	spriteAn_2_inRow_17Rows_3->setScale(fscale);
	spriteAn_2_inRow_17Rows_4->setScale(fscale);
	spriteAn_2_inRow_17Rows_5->setScale(fscale);
	spriteAn_2_inRow_17Rows_6->setScale(fscale);
	spriteAn_2_inRow_17Rows_7->setScale(fscale);
	spriteAn_2_inRow_17Rows_8->setScale(fscale);
	spriteAn_2_inRow_17Rows_9->setScale(fscale);
	spriteAn_2_inRow_17Rows_10->setScale(fscale);
	spriteAn_2_inRow_17Rows_11->setScale(fscale);
	spriteAn_2_inRow_17Rows_12->setScale(fscale);


	spriteAn_3_inRow_1Row_1->setScale(fscale);
	spriteAn_3_inRow_1Row_2->setScale(fscale);
	spriteAn_3_inRow_2Rows_1->setScale(fscale);
	spriteAn_3_inRow_2Rows_2->setScale(fscale);
	spriteAn_3_inRow_3Rows_1->setScale(fscale);
	spriteAn_3_inRow_3Rows_2->setScale(fscale);
	spriteAn_3_inRow_4Rows_1->setScale(fscale);
	spriteAn_3_inRow_4Rows_2->setScale(fscale);
	spriteAn_3_inRow_4Rows_3->setScale(fscale);
	spriteAn_3_inRow_4Rows_4->setScale(fscale);
	spriteAn_3_inRow_5Rows_1->setScale(fscale);
	spriteAn_3_inRow_5Rows_2->setScale(fscale);
	spriteAn_3_inRow_5Rows_3->setScale(fscale);
	spriteAn_3_inRow_5Rows_4->setScale(fscale);
	spriteAn_3_inRow_6Rows_1->setScale(fscale);
	spriteAn_3_inRow_6Rows_2->setScale(fscale);
	spriteAn_3_inRow_6Rows_3->setScale(fscale);
	spriteAn_3_inRow_6Rows_4->setScale(fscale);
	spriteAn_3_inRow_7Rows_1->setScale(fscale);
	spriteAn_3_inRow_7Rows_2->setScale(fscale);
	spriteAn_3_inRow_7Rows_3->setScale(fscale);
	spriteAn_3_inRow_7Rows_4->setScale(fscale);
	spriteAn_3_inRow_7Rows_5->setScale(fscale);
	spriteAn_3_inRow_7Rows_6->setScale(fscale);
	spriteAn_3_inRow_8Rows_1->setScale(fscale);
	spriteAn_3_inRow_8Rows_2->setScale(fscale);
	spriteAn_3_inRow_8Rows_3->setScale(fscale);
	spriteAn_3_inRow_8Rows_4->setScale(fscale);
	spriteAn_3_inRow_8Rows_5->setScale(fscale);
	spriteAn_3_inRow_8Rows_6->setScale(fscale);
	spriteAn_3_inRow_9Rows_1->setScale(fscale);
	spriteAn_3_inRow_9Rows_2->setScale(fscale);
	spriteAn_3_inRow_9Rows_3->setScale(fscale);
	spriteAn_3_inRow_9Rows_4->setScale(fscale);
	spriteAn_3_inRow_9Rows_5->setScale(fscale);
	spriteAn_3_inRow_9Rows_6->setScale(fscale);
	spriteAn_3_inRow_10Rows_1->setScale(fscale);
	spriteAn_3_inRow_10Rows_2->setScale(fscale);
	spriteAn_3_inRow_10Rows_3->setScale(fscale);
	spriteAn_3_inRow_10Rows_4->setScale(fscale);
	spriteAn_3_inRow_10Rows_5->setScale(fscale);
	spriteAn_3_inRow_10Rows_6->setScale(fscale);
	spriteAn_3_inRow_10Rows_7->setScale(fscale);
	spriteAn_3_inRow_10Rows_8->setScale(fscale);
	spriteAn_3_inRow_11Rows_1->setScale(fscale);
	spriteAn_3_inRow_11Rows_2->setScale(fscale);
	spriteAn_3_inRow_11Rows_3->setScale(fscale);
	spriteAn_3_inRow_11Rows_4->setScale(fscale);
	spriteAn_3_inRow_11Rows_5->setScale(fscale);
	spriteAn_3_inRow_11Rows_6->setScale(fscale);
	spriteAn_3_inRow_11Rows_7->setScale(fscale);
	spriteAn_3_inRow_11Rows_8->setScale(fscale);
	spriteAn_3_inRow_12Rows_1->setScale(fscale);
	spriteAn_3_inRow_12Rows_2->setScale(fscale);
	spriteAn_3_inRow_12Rows_3->setScale(fscale);
	spriteAn_3_inRow_12Rows_4->setScale(fscale);
	spriteAn_3_inRow_12Rows_5->setScale(fscale);
	spriteAn_3_inRow_12Rows_6->setScale(fscale);
	spriteAn_3_inRow_12Rows_7->setScale(fscale);
	spriteAn_3_inRow_12Rows_8->setScale(fscale);
	spriteAn_3_inRow_13Rows_1->setScale(fscale);
	spriteAn_3_inRow_13Rows_2->setScale(fscale);
	spriteAn_3_inRow_13Rows_3->setScale(fscale);
	spriteAn_3_inRow_13Rows_4->setScale(fscale);
	spriteAn_3_inRow_13Rows_5->setScale(fscale);
	spriteAn_3_inRow_13Rows_6->setScale(fscale);
	spriteAn_3_inRow_13Rows_7->setScale(fscale);
	spriteAn_3_inRow_13Rows_8->setScale(fscale);
	spriteAn_3_inRow_13Rows_9->setScale(fscale);
	spriteAn_3_inRow_13Rows_10->setScale(fscale);
	spriteAn_3_inRow_14Rows_1->setScale(fscale);
	spriteAn_3_inRow_14Rows_2->setScale(fscale);
	spriteAn_3_inRow_14Rows_3->setScale(fscale);
	spriteAn_3_inRow_14Rows_4->setScale(fscale);
	spriteAn_3_inRow_14Rows_5->setScale(fscale);
	spriteAn_3_inRow_14Rows_6->setScale(fscale);
	spriteAn_3_inRow_14Rows_7->setScale(fscale);
	spriteAn_3_inRow_14Rows_8->setScale(fscale);
	spriteAn_3_inRow_14Rows_9->setScale(fscale);
	spriteAn_3_inRow_14Rows_10->setScale(fscale);
	spriteAn_3_inRow_15Rows_1->setScale(fscale);
	spriteAn_3_inRow_15Rows_2->setScale(fscale);
	spriteAn_3_inRow_15Rows_3->setScale(fscale);
	spriteAn_3_inRow_15Rows_4->setScale(fscale);
	spriteAn_3_inRow_15Rows_5->setScale(fscale);
	spriteAn_3_inRow_15Rows_6->setScale(fscale);
	spriteAn_3_inRow_15Rows_7->setScale(fscale);
	spriteAn_3_inRow_15Rows_8->setScale(fscale);
	spriteAn_3_inRow_15Rows_9->setScale(fscale);
	spriteAn_3_inRow_15Rows_10->setScale(fscale);
	spriteAn_3_inRow_16Rows_1->setScale(fscale);
	spriteAn_3_inRow_16Rows_2->setScale(fscale);
	spriteAn_3_inRow_16Rows_3->setScale(fscale);
	spriteAn_3_inRow_16Rows_4->setScale(fscale);
	spriteAn_3_inRow_16Rows_5->setScale(fscale);
	spriteAn_3_inRow_16Rows_6->setScale(fscale);
	spriteAn_3_inRow_16Rows_7->setScale(fscale);
	spriteAn_3_inRow_16Rows_8->setScale(fscale);
	spriteAn_3_inRow_16Rows_9->setScale(fscale);
	spriteAn_3_inRow_16Rows_10->setScale(fscale);
	spriteAn_3_inRow_16Rows_11->setScale(fscale);
	spriteAn_3_inRow_16Rows_12->setScale(fscale);
	spriteAn_3_inRow_17Rows_1->setScale(fscale);
	spriteAn_3_inRow_17Rows_2->setScale(fscale);
	spriteAn_3_inRow_17Rows_3->setScale(fscale);
	spriteAn_3_inRow_17Rows_4->setScale(fscale);
	spriteAn_3_inRow_17Rows_5->setScale(fscale);
	spriteAn_3_inRow_17Rows_6->setScale(fscale);
	spriteAn_3_inRow_17Rows_7->setScale(fscale);
	spriteAn_3_inRow_17Rows_8->setScale(fscale);
	spriteAn_3_inRow_17Rows_9->setScale(fscale);
	spriteAn_3_inRow_17Rows_10->setScale(fscale);
	spriteAn_3_inRow_17Rows_11->setScale(fscale);
	spriteAn_3_inRow_17Rows_12->setScale(fscale);
	spriteAn_3_inRow_18Rows_1->setScale(fscale);
	spriteAn_3_inRow_18Rows_2->setScale(fscale);
	spriteAn_3_inRow_18Rows_3->setScale(fscale);
	spriteAn_3_inRow_18Rows_4->setScale(fscale);
	spriteAn_3_inRow_18Rows_5->setScale(fscale);
	spriteAn_3_inRow_18Rows_6->setScale(fscale);
	spriteAn_3_inRow_18Rows_7->setScale(fscale);
	spriteAn_3_inRow_18Rows_8->setScale(fscale);
	spriteAn_3_inRow_18Rows_9->setScale(fscale);
	spriteAn_3_inRow_18Rows_10->setScale(fscale);
	spriteAn_3_inRow_18Rows_11->setScale(fscale);
	spriteAn_3_inRow_18Rows_12->setScale(fscale);

	spriteAn_4_inRow_1Row_1->setScale(fscale);
	spriteAn_4_inRow_1Row_2->setScale(fscale);
	spriteAn_4_inRow_2Rows_1->setScale(fscale);
	spriteAn_4_inRow_2Rows_2->setScale(fscale);
	spriteAn_4_inRow_3Rows_1->setScale(fscale);
	spriteAn_4_inRow_3Rows_2->setScale(fscale);
	spriteAn_4_inRow_4Rows_1->setScale(fscale);
	spriteAn_4_inRow_4Rows_2->setScale(fscale);
	spriteAn_4_inRow_4Rows_3->setScale(fscale);
	spriteAn_4_inRow_4Rows_4->setScale(fscale);
	spriteAn_4_inRow_5Rows_1->setScale(fscale);
	spriteAn_4_inRow_5Rows_2->setScale(fscale);
	spriteAn_4_inRow_5Rows_3->setScale(fscale);
	spriteAn_4_inRow_5Rows_4->setScale(fscale);
	spriteAn_4_inRow_6Rows_1->setScale(fscale);
	spriteAn_4_inRow_6Rows_2->setScale(fscale);
	spriteAn_4_inRow_6Rows_3->setScale(fscale);
	spriteAn_4_inRow_6Rows_4->setScale(fscale);
	spriteAn_4_inRow_7Rows_1->setScale(fscale);
	spriteAn_4_inRow_7Rows_2->setScale(fscale);
	spriteAn_4_inRow_7Rows_3->setScale(fscale);
	spriteAn_4_inRow_7Rows_4->setScale(fscale);
	spriteAn_4_inRow_7Rows_5->setScale(fscale);
	spriteAn_4_inRow_7Rows_6->setScale(fscale);
	spriteAn_4_inRow_8Rows_1->setScale(fscale);
	spriteAn_4_inRow_8Rows_2->setScale(fscale);
	spriteAn_4_inRow_8Rows_3->setScale(fscale);
	spriteAn_4_inRow_8Rows_4->setScale(fscale);
	spriteAn_4_inRow_8Rows_5->setScale(fscale);
	spriteAn_4_inRow_8Rows_6->setScale(fscale);
	spriteAn_4_inRow_9Rows_1->setScale(fscale);
	spriteAn_4_inRow_9Rows_2->setScale(fscale);
	spriteAn_4_inRow_9Rows_3->setScale(fscale);
	spriteAn_4_inRow_9Rows_4->setScale(fscale);
	spriteAn_4_inRow_9Rows_5->setScale(fscale);
	spriteAn_4_inRow_9Rows_6->setScale(fscale);
	spriteAn_4_inRow_10Rows_1->setScale(fscale);
	spriteAn_4_inRow_10Rows_2->setScale(fscale);
	spriteAn_4_inRow_10Rows_3->setScale(fscale);
	spriteAn_4_inRow_10Rows_4->setScale(fscale);
	spriteAn_4_inRow_10Rows_5->setScale(fscale);
	spriteAn_4_inRow_10Rows_6->setScale(fscale);
	spriteAn_4_inRow_10Rows_7->setScale(fscale);
	spriteAn_4_inRow_10Rows_8->setScale(fscale);
	spriteAn_4_inRow_11Rows_1->setScale(fscale);
	spriteAn_4_inRow_11Rows_2->setScale(fscale);
	spriteAn_4_inRow_11Rows_3->setScale(fscale);
	spriteAn_4_inRow_11Rows_4->setScale(fscale);
	spriteAn_4_inRow_11Rows_5->setScale(fscale);
	spriteAn_4_inRow_11Rows_6->setScale(fscale);
	spriteAn_4_inRow_11Rows_7->setScale(fscale);
	spriteAn_4_inRow_11Rows_8->setScale(fscale);
	spriteAn_4_inRow_12Rows_1->setScale(fscale);
	spriteAn_4_inRow_12Rows_2->setScale(fscale);
	spriteAn_4_inRow_12Rows_3->setScale(fscale);
	spriteAn_4_inRow_12Rows_4->setScale(fscale);
	spriteAn_4_inRow_12Rows_5->setScale(fscale);
	spriteAn_4_inRow_12Rows_6->setScale(fscale);
	spriteAn_4_inRow_12Rows_7->setScale(fscale);
	spriteAn_4_inRow_12Rows_8->setScale(fscale);
	spriteAn_4_inRow_13Rows_1->setScale(fscale);
	spriteAn_4_inRow_13Rows_2->setScale(fscale);
	spriteAn_4_inRow_13Rows_3->setScale(fscale);
	spriteAn_4_inRow_13Rows_4->setScale(fscale);
	spriteAn_4_inRow_13Rows_5->setScale(fscale);
	spriteAn_4_inRow_13Rows_6->setScale(fscale);
	spriteAn_4_inRow_13Rows_7->setScale(fscale);
	spriteAn_4_inRow_13Rows_8->setScale(fscale);
	spriteAn_4_inRow_13Rows_9->setScale(fscale);
	spriteAn_4_inRow_13Rows_10->setScale(fscale);
	spriteAn_4_inRow_14Rows_1->setScale(fscale);
	spriteAn_4_inRow_14Rows_2->setScale(fscale);
	spriteAn_4_inRow_14Rows_3->setScale(fscale);
	spriteAn_4_inRow_14Rows_4->setScale(fscale);
	spriteAn_4_inRow_14Rows_5->setScale(fscale);
	spriteAn_4_inRow_14Rows_6->setScale(fscale);
	spriteAn_4_inRow_14Rows_7->setScale(fscale);
	spriteAn_4_inRow_14Rows_8->setScale(fscale);
	spriteAn_4_inRow_14Rows_9->setScale(fscale);
	spriteAn_4_inRow_14Rows_10->setScale(fscale);
	spriteAn_4_inRow_15Rows_1->setScale(fscale);
	spriteAn_4_inRow_15Rows_2->setScale(fscale);
	spriteAn_4_inRow_15Rows_3->setScale(fscale);
	spriteAn_4_inRow_15Rows_4->setScale(fscale);
	spriteAn_4_inRow_15Rows_5->setScale(fscale);
	spriteAn_4_inRow_15Rows_6->setScale(fscale);
	spriteAn_4_inRow_15Rows_7->setScale(fscale);
	spriteAn_4_inRow_15Rows_8->setScale(fscale);
	spriteAn_4_inRow_15Rows_9->setScale(fscale);
	spriteAn_4_inRow_15Rows_10->setScale(fscale);
	spriteAn_4_inRow_16Rows_1->setScale(fscale);
	spriteAn_4_inRow_16Rows_2->setScale(fscale);
	spriteAn_4_inRow_16Rows_3->setScale(fscale);
	spriteAn_4_inRow_16Rows_4->setScale(fscale);
	spriteAn_4_inRow_16Rows_5->setScale(fscale);
	spriteAn_4_inRow_16Rows_6->setScale(fscale);
	spriteAn_4_inRow_16Rows_7->setScale(fscale);
	spriteAn_4_inRow_16Rows_8->setScale(fscale);
	spriteAn_4_inRow_16Rows_9->setScale(fscale);
	spriteAn_4_inRow_16Rows_10->setScale(fscale);
	spriteAn_4_inRow_16Rows_11->setScale(fscale);
	spriteAn_4_inRow_16Rows_12->setScale(fscale);
	spriteAn_4_inRow_17Rows_1->setScale(fscale);
	spriteAn_4_inRow_17Rows_2->setScale(fscale);
	spriteAn_4_inRow_17Rows_3->setScale(fscale);
	spriteAn_4_inRow_17Rows_4->setScale(fscale);
	spriteAn_4_inRow_17Rows_5->setScale(fscale);
	spriteAn_4_inRow_17Rows_6->setScale(fscale);
	spriteAn_4_inRow_17Rows_7->setScale(fscale);
	spriteAn_4_inRow_17Rows_8->setScale(fscale);
	spriteAn_4_inRow_17Rows_9->setScale(fscale);
	spriteAn_4_inRow_17Rows_10->setScale(fscale);
	spriteAn_4_inRow_17Rows_11->setScale(fscale);
	spriteAn_4_inRow_17Rows_12->setScale(fscale);
	spriteAn_4_inRow_18Rows_1->setScale(fscale);
	spriteAn_4_inRow_18Rows_2->setScale(fscale);
	spriteAn_4_inRow_18Rows_3->setScale(fscale);
	spriteAn_4_inRow_18Rows_4->setScale(fscale);
	spriteAn_4_inRow_18Rows_5->setScale(fscale);
	spriteAn_4_inRow_18Rows_6->setScale(fscale);
	spriteAn_4_inRow_18Rows_7->setScale(fscale);
	spriteAn_4_inRow_18Rows_8->setScale(fscale);
	spriteAn_4_inRow_18Rows_9->setScale(fscale);
	spriteAn_4_inRow_18Rows_10->setScale(fscale);
	spriteAn_4_inRow_18Rows_11->setScale(fscale);
	spriteAn_4_inRow_18Rows_12->setScale(fscale);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Курсор
	//SetClassLong(window.getSystemHandle(), NULL, IDC_CURSOR1);
	//SetCursor(LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR2)));
	window.setMouseCursorVisible(false);

	sprite_table2->setPosition(Vector2f(770.f * fscale.x, 219.f * fscale.y));//установка позиции сетки

	// Часы (таймер)
	Clock clock;
	srand(time(0));
	//fill_tetramino();
	// Главный цикл приложения. Выполняется, пока открыто окно
	//animation_1_line.restart();
	while (window.isOpen())
	{
		sizeOfWin.x = window.getSize().x;
		sizeOfWin.y = window.getSize().y;
		window.clear();
		//winPos = window.getPosition();
		
		/*int time_1_line = animation_1_line.getElapsedTime().asMilliseconds();
		cout << time_1_line << endl;*/
		//SetCursor(LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1)));
		Vector2i mousePos = Mouse::getPosition(window);
		Vector2f mousePosf;
		mousePosf.x = Mouse::getPosition(window).x;
		mousePosf.y = Mouse::getPosition(window).y;
		//sprite_myCursor->setPosition(mousePosf.x - 1317, mousePosf.y - 836); //default size
		//sprite_myCursor->setPosition(mousePosf.x - 921.9f * fscale.x, mousePosf.y - 585.2f * fscale.y);//позиция курсора
		sprite_myCursor->setPosition(mousePosf.x - 38 * fscale.x * 0.7f, mousePosf.y - 32 * fscale.y * 0.7f);//позиция курсора 0.7f это стандартноше масштабирование, поменять при надобности

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

					for (USHORT i = H - 1; i > 15; i--)
					{
						for (USHORT j = 0; j < W; j++)
						{
							
							field[i][j] = 1;
							//if(i < 7)
							//field[i][4] = 0;
							//if (i == 18) field[i][3] = 0;
							//if (i == 17) field[i][3] = 0;
				/*			if (i == 4) field[i][3] = 0;
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
							if (i == 19) field[i][8] = 0;*/

							if (i == 19)field[i][6] = 0;
							//if (i == 18)field[i][5] = 0;
							if (i == 18)field[i][6] = 0;
							//if (i == 17)field[i][5] = 0;
							if (i == 17)field[i][6] = 0;
							if (i == 16)field[i][6] = 0;

						}
					}
				}
				else if (event.key.code == Keyboard::F2)
				{
					enableAnimation_fast_falling_4InRow_18Rows = true;
				}
				else if (event.key.code == Keyboard::F3)
				{
					//window.draw(*spriteAn_1_inRow_1Row_2);
					//window.draw(*sprite_ays_yes1st);
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
				cout << event.size.width << '\t' << event.size.height << endl << endl << endl;*/
				cout << window.getSize().x << '\t' << window.getSize().y << endl << endl;
				enableResize = true;
				if (window.getSize().x < VideoMode().getFullscreenModes()[0].width / 1.5f && window.getSize().y < VideoMode().getFullscreenModes()[0].height / 1.5f)
					//window.setSize(Vector2u(VideoMode().getFullscreenModes()[0].width / 1.5f, VideoMode().getFullscreenModes()[0].height / 1.5f));
				
				//SetWindowLong(window.getSystemHandle(), GWL_STYLE, GetWindowLong(window.getSystemHandle(), GWL_STYLE) & ~WS_SIZEBOX);//не то пальто
				//window.create(VideoMode(VideoMode().getFullscreenModes()[0].width / 1.5f, VideoMode().getFullscreenModes()[0].height / 1.5f), "Tetris", Style::Titlebar | Style::Default, *context);// Это жесть
				//window.create(VideoMode(window.getSize().x, window.getSize().y), "Tetris", Style::Titlebar | Style::Default | Style::Resize, *context);
				//window.setPosition(winPos);
				//window.setSize(Vector2u(window.getSize().x, window.getSize().y));
				//window.setSize(sizeOfWin);
				//SetForegroundWindow(window.getSystemHandle());//чтобы сделать окно активным
				//goto scalemark;
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
				if (IntRect(216 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y) && !checkAus)
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
				else if (IntRect(1584 * fscale.x, 953 * fscale.y, 300 * fscale.x, 100 * fscale.y).contains(mousePos.x, mousePos.y))
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
				else if (IntRect(36 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
				{
					if (!soundOn_sounOff_button) soundOn_sounOff_button = true;
					else soundOn_sounOff_button = false;
				}

				//MusicOn/MusicOff
				else if (IntRect(126 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
				{
					if (!musicOn_musicOff_button) musicOn_musicOff_button = true;
					else musicOn_musicOff_button = false;
				}
				//Left minimize
				else if (IntRect(1629 * fscale.x, 32 * fscale.y, 85 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y))
				{
					//SendNotifyMessage(window.getSystemHandle(), WM_SYSCOMMAND, SC_MINIMIZE, 0); //МИНИМИЗАЦИЯ ОКНА
					CloseWindow(window.getSystemHandle());//вроде тоже самое что сверху
				}

				//Right close
				else if (IntRect(1799 * fscale.x, 32 * fscale.y, 85 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y)) window.close();

				//Middle restore
				else if (IntRect(1714 * fscale.x, 32 * fscale.y, 85 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y))
				{
				
					//window.setSize(Vector2u(700, 800));
					window.create(VideoMode(window.getSize().x/1.5f, window.getSize().y/1.5f), "Tetris", Style::Titlebar | Style:: Resize,*context);
					window.setIcon(38, 38, icon->getPixelsPtr());
					//winSizePrev = window.getSize();
					//SetForegroundWindow(window.getSystemHandle());//чтобы сделать окно активным
					//winPos = window.getPosition();
					//cout << winPos.x << "\t" << winPos.y << endl;
					goto scalemark;
				}
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
				//for (int i = 0; i < 4; i++)
				//{
				//	cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
					//cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				//}
				//cout << endl;
				//for (int i = 0; i < 4; i++)
				//{
					//cout << "a[" << i << "].x : " << a[i].x << '\t' << "a[" << i << "].y :" << a[i].y << endl;
					//cout << "e[" << i << "].x : " << e[i].x << '\t' << "e[" << i << "].y :" << e[i].y << endl;

				//}
				//cout << "===============================End=======================================" << endl;
				//cout << endl << endl;
				

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
		//window.clear(Color::White);
		//window.clear();
		window.draw(*sprite_background);
		window.draw(*sprite_left_frame);
		window.draw(*sprite_right_frame);
		window.draw(*sprite_right_frame_bottom);
		if (set_grid)
			//window.draw(*sprite_table);
			window.draw(*sprite_table2);

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
			if (IntRect(1584 * fscale.x, 953 * fscale.y, 300 * fscale.x, 100 * fscale.y).contains(mousePos.x, mousePos.y))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_start_st3);
				else window.draw(*sprite_button_start_st2);
			}
			else window.draw(*sprite_button_start_st1);

		//Отрисовка кнопки New game
		else if (start_newGame_button)
			if (IntRect(1584 * fscale.x, 953 * fscale.y, 300 * fscale.x, 100 * fscale.y).contains(mousePos.x, mousePos.y))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_newgame_st3);
				else window.draw(*sprite_button_newgame_st2);
			}
			else window.draw(*sprite_button_newgame_st1);

		//Отрисовка кнопки Options

		if (IntRect(36 * fscale.x, 32 * fscale.y, 256 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y))

		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				window.draw(*sprite_button_options_st3);
			}
			else window.draw(*sprite_button_options_st2);
		}
		else window.draw(*sprite_button_options_st1);

		//проверка для трех кнопок
		if (IntRect(1629 * fscale.x, 32 * fscale.y, 85 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y)) isLeftButton = true;
		else isLeftButton = false;

		if (IntRect(1799 * fscale.x, 32 * fscale.y, 85 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y)) isRightButton = true;
		else isRightButton = false;

		if (IntRect(1714 * fscale.x, 32 * fscale.y, 85 * fscale.x, 62 * fscale.y).contains(mousePos.x, mousePos.y)) isMiddleButton = true;
		else isMiddleButton = false;

		//Отрисовка трех кнопок сверху справа
		if(isLeftButton) draw_3buttons(window, mousePos, *sprite_button_left_st1, *sprite_button_left_st2, *sprite_button_left_st3, *sprite_button_right_st1, *sprite_button_right_st2, *sprite_button_right_st3,
			*sprite_button_middle_restore_st1, *sprite_button_middle_restore_st2, *sprite_button_middle_restore_st3, fscale);
		else if(isRightButton) draw_3buttons2(window, mousePos, *sprite_button_left_st1, *sprite_button_left_st2, *sprite_button_left_st3, *sprite_button_right_st1, *sprite_button_right_st2, *sprite_button_right_st3,
			*sprite_button_middle_restore_st1, *sprite_button_middle_restore_st2, *sprite_button_middle_restore_st3, fscale);
		else draw_3buttons3(window, mousePos, *sprite_button_left_st1, *sprite_button_left_st2, *sprite_button_left_st3, *sprite_button_right_st1, *sprite_button_right_st2, *sprite_button_right_st3,
			*sprite_button_middle_restore_st1, *sprite_button_middle_restore_st2, *sprite_button_middle_restore_st3, fscale);

		
		//Отрисовка кнопки pause
		if (!pause_resume_button)
		{
			if (IntRect(216 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
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
			if (IntRect(216 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left) && !checkAus)
					window.draw(*sprite_button_pause_st3);
				else window.draw(*sprite_button_pause_st4);
			else window.draw(*sprite_button_pause_st4);
		}
		
		//Отрисовка кнопки soundOn
		if(soundOn_sounOff_button)
		if (IntRect(36 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
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
			if (IntRect(36 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
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
			if (IntRect(126 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
				if (Mouse::isButtonPressed(Mouse::Left))
					window.draw(*sprite_button_musicOn_st3);
				else window.draw(*sprite_button_musicOn_st4);
			else window.draw(*sprite_button_musicOn_st1);

		//Отрисовка кнопки musicOn
		else if (musicOn_musicOff_button)
			if (IntRect(126 * fscale.x, 963 * fscale.y, 80 * fscale.x, 80 * fscale.y).contains(mousePos.x, mousePos.y))
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
						sprite_I_red->setOrigin((40 + 38 * 3 + 19), (40 + 19));
						sprite_I_red->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
						if (turnRight && !pauseBreak && check_rotate2)
						{
							
							sprite_I_red->rotate(90);
							//sprite_I_red->setScale(fscale);
							if (rotateBack90)sprite_I_red->rotate(-90);
							check_rotate2 = false;
						}
						if (turnLeft && !pauseBreak && check_rotate2)
						{
							sprite_I_red->rotate(270);
							//sprite_I_red->setScale(fscale);
							if (rotateForward90)sprite_I_red->rotate(-270);
							check_rotate2 = false;
						}
						if (set_prototype)window.draw(*sprite_I_red);
						break;
					case 2:
						sprite_I_blue->setOrigin(40 + 38 * 3 + 19, 40 + 19);
						sprite_I_blue->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_green->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_yellow->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_purple->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_orange->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_brown->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_pink->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_I_black->setPosition((e[0].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[0].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_red->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_blue->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_green->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_yellow->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_purple->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_orange->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_brown->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_pink->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_S_black->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_red->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_blue->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_green->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_yellow->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_purple->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_orange->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_brown->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_pink->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_Z_black->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_red->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_blue->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_green->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_yellow->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_purple->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_orange->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_brown->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_pink->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_T_black->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_red->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_blue->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_green->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_yellow->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_purple->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_orange->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_brown->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_pink->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_L_black->setPosition((e[2].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[2].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_red->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_blue->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_green->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_yellow->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_purple->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_orange->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_brown->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_pink->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_J_black->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3 + 19) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40 + 19) * fscale.y);
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
						sprite_O_red->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_red);
						break;
					case 2:
						sprite_O_blue->setOrigin(40 + 38, 40 + 38);
						sprite_O_blue->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_blue);
						break;
					case 3:
						sprite_O_green->setOrigin(40 + 38, 40 + 38);
						sprite_O_green->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_green);
						break;
					case 4:
						sprite_O_yellow->setOrigin(40 + 38, 40 + 38);
						sprite_O_yellow->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_yellow);
						break;
					case 5:
						sprite_O_purple->setOrigin(40 + 38, 40 + 38);
						sprite_O_purple->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_purple);
						break;
					case 6:
						sprite_O_orange->setOrigin(40 + 38, 40 + 38);
						sprite_O_orange->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_orange);
						break;
					case 7:
						sprite_O_brown->setOrigin(40 + 38, 40 + 38);
						sprite_O_brown->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_brown);
						break;
					case 8:
						sprite_O_pink->setOrigin(40 + 38, 40 + 38);
						sprite_O_pink->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
						if (set_prototype)window.draw(*sprite_O_pink);
						break;
					case 9:
						sprite_O_black->setOrigin(40 + 38, 40 + 38);
						sprite_O_black->setPosition((e[1].x * 38 + 922 - 154 + 40 + 38 * 3) * fscale.x, (e[1].y * 38 + 219 - 38 - 2 + 40) * fscale.y);
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
					
					sprite->setScale(fscale);
					sprite->scale(0.5, 0.5);
					// Устанавливаем позицию каждого кусочка тетрамино
					sprite->setPosition((d[i].x * 38 + 922) * fscale.x, (d[i].y * 38 + 219) * fscale.y);//тут править

					// Отрисовка спрайта
					if (a[i].y > -1)
					window.draw(*sprite);
				}
			}
			else if (!enableAnimation1line && !enableAnimation2lines && !enableAnimation2lines_with_void && !enableAnimation3lines
				&& !enableAnimation3lines_with_void && !enableAnimation4lines && !enableAnimation_fast_falling_3InRow_16Rows && !enableAnimation_fast_falling_1InRow_1Row &&
				!enableAnimation_fast_falling_1InRow_2Rows && !enableAnimation_fast_falling_1InRow_3Rows && !enableAnimation_fast_falling_1InRow_4Rows  &&
				!enableAnimation_fast_falling_1InRow_5Rows && !enableAnimation_fast_falling_1InRow_6Rows && !enableAnimation_fast_falling_1InRow_7Rows  &&
				!enableAnimation_fast_falling_1InRow_8Rows && !enableAnimation_fast_falling_1InRow_9Rows  && !enableAnimation_fast_falling_1InRow_10Rows  &&
				!enableAnimation_fast_falling_1InRow_11Rows && !enableAnimation_fast_falling_1InRow_12Rows && !enableAnimation_fast_falling_1InRow_13Rows &&
				!enableAnimation_fast_falling_1InRow_14Rows && !enableAnimation_fast_falling_1InRow_15Rows && !enableAnimation_fast_falling_1InRow_16Rows &&
				!enableAnimation_fast_falling_1InRow_17Rows && !enableAnimation_fast_falling_2InRow_1Row &&
				!enableAnimation_fast_falling_2InRow_2Rows && !enableAnimation_fast_falling_2InRow_3Rows && !enableAnimation_fast_falling_2InRow_4Rows &&
				!enableAnimation_fast_falling_2InRow_5Rows && !enableAnimation_fast_falling_2InRow_6Rows && !enableAnimation_fast_falling_2InRow_7Rows &&
				!enableAnimation_fast_falling_2InRow_8Rows && !enableAnimation_fast_falling_2InRow_9Rows && !enableAnimation_fast_falling_2InRow_10Rows &&
				!enableAnimation_fast_falling_2InRow_11Rows && !enableAnimation_fast_falling_2InRow_12Rows && !enableAnimation_fast_falling_2InRow_13Rows &&
				!enableAnimation_fast_falling_2InRow_14Rows && !enableAnimation_fast_falling_2InRow_15Rows && !enableAnimation_fast_falling_2InRow_16Rows &&
				!enableAnimation_fast_falling_2InRow_17Rows && !enableAnimation_fast_falling_3InRow_1Row &&
				!enableAnimation_fast_falling_3InRow_2Rows && !enableAnimation_fast_falling_3InRow_3Rows  && !enableAnimation_fast_falling_3InRow_4Rows &&
				!enableAnimation_fast_falling_3InRow_5Rows && !enableAnimation_fast_falling_3InRow_6Rows && !enableAnimation_fast_falling_3InRow_7Rows &&
				!enableAnimation_fast_falling_3InRow_8Rows && !enableAnimation_fast_falling_3InRow_9Rows && !enableAnimation_fast_falling_3InRow_10Rows &&
				!enableAnimation_fast_falling_3InRow_11Rows && !enableAnimation_fast_falling_3InRow_12Rows && !enableAnimation_fast_falling_3InRow_13Rows &&
				!enableAnimation_fast_falling_3InRow_14Rows && !enableAnimation_fast_falling_3InRow_15Rows && !enableAnimation_fast_falling_3InRow_16Rows &&
				!enableAnimation_fast_falling_3InRow_17Rows && !enableAnimation_fast_falling_3InRow_18Rows &&
				!enableAnimation_fast_falling_4InRow_1Row &&
				!enableAnimation_fast_falling_4InRow_2Rows && !enableAnimation_fast_falling_4InRow_3Rows  && !enableAnimation_fast_falling_4InRow_4Rows &&
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
					
					sprite->setScale(fscale);
					sprite->scale(0.5, 0.5);
					// Устанавливаем позицию каждого кусочка тетрамино
					sprite->setPosition((a[i].x * 38 + 922) * fscale.x, (a[i].y * 38 + 219) * fscale.y);//тут править

					// Отрисовка спрайта
						if (a[i].y > -1)
						window.draw(*sprite);
				}
			
			//отрисовка тетрамино в верхнем поле
			for (int i = 0; i < 4; i++)
			{
				// Разукрашиваем тетрамино
				sprite->setTextureRect(IntRect(colorNum2 * 76, 0, 76, 76));
				
				sprite->setScale(fscale);
				sprite->scale(0.5, 0.5);
				// Устанавливаем позицию каждого кусочка тетрамино

				sprite->setPosition((c[i].x * 38 + 922) * fscale.x, (c[i].y * 38 + 14) * fscale.y);//тут править

				//Смещение спрайтов верхних фигур
				switch (typeOfTetramino2)
				{
				case 0: sprite->move(0, 38 * fscale.y);
					break;
				case 1: sprite->move(19 * fscale.x, -19 * fscale.y);
					break;
				case 2: sprite->move(-19 * fscale.x, 19 * fscale.y);
					break;
				case 3: sprite->move(-19 * fscale.x, -19 * fscale.y);
					break;
				case 4: sprite->move(-57 * fscale.x, 19 * fscale.y);
					break;
				case 5: sprite->move(-19 * fscale.x, -19 * fscale.y);
					break;
				case 6: sprite->move(0, 57 * fscale.y);
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
					
					sprite->setScale(fscale);
					sprite->scale(0.5, 0.5);
					sprite->setPosition((j * 38 + 770) * fscale.x, (i * 38 + 219) * fscale.y);//тут править
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
			if (IntRect(735 * fscale.x, 547 * fscale.y, 85 * fscale.x, 37 * fscale.y).contains(mousePos.x, mousePos.y))
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
			if (IntRect(1113 * fscale.x, 547 * fscale.y, 71 * fscale.x, 37 * fscale.y).contains(mousePos.x, mousePos.y))
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
			spriteAn_1line_16, spriteAn_1line_17, spriteAn_1line_18, spriteAn_1line_19, spriteAn_1line_20, spriteAn_1line_21, spriteAn_1line_22, fscale);
		if(enableAnimation2lines)
			animation_2_linesFn(window, indexOfLastLine, spriteAn_2lines_1, spriteAn_2lines_2, spriteAn_2lines_3, spriteAn_2lines_4, spriteAn_2lines_5, spriteAn_2lines_6, spriteAn_2lines_7,
				spriteAn_2lines_8, spriteAn_2lines_9, spriteAn_2lines_10, spriteAn_2lines_11, spriteAn_2lines_12, spriteAn_2lines_13, spriteAn_2lines_14, spriteAn_2lines_15,
				spriteAn_2lines_16, spriteAn_2lines_17, spriteAn_2lines_18, spriteAn_2lines_19, spriteAn_2lines_20, spriteAn_2lines_21, spriteAn_2lines_22, fscale);
		if(enableAnimation3lines)
			animation_3_linesFn(window, indexOfLastLine, spriteAn_3lines_1, spriteAn_3lines_2, spriteAn_3lines_3, spriteAn_3lines_4, spriteAn_3lines_5, spriteAn_3lines_6, spriteAn_3lines_7,
				spriteAn_3lines_8, spriteAn_3lines_9, spriteAn_3lines_10, spriteAn_3lines_11, spriteAn_3lines_12, spriteAn_3lines_13, spriteAn_3lines_14, spriteAn_3lines_15,
				spriteAn_3lines_16, spriteAn_3lines_17, spriteAn_3lines_18, spriteAn_3lines_19, spriteAn_3lines_20, spriteAn_3lines_21, spriteAn_3lines_22, fscale);
		if(enableAnimation4lines)
			animation_4_linesFn(window, indexOfLastLine, spriteAn_4lines_1, spriteAn_4lines_2, spriteAn_4lines_3, spriteAn_4lines_4, spriteAn_4lines_5, spriteAn_4lines_6, spriteAn_4lines_7,
				spriteAn_4lines_8, spriteAn_4lines_9, spriteAn_4lines_10, spriteAn_4lines_11, spriteAn_4lines_12, spriteAn_4lines_13, spriteAn_4lines_14, spriteAn_4lines_15,
				spriteAn_4lines_16, spriteAn_4lines_17, spriteAn_4lines_18, spriteAn_4lines_19, spriteAn_4lines_20, spriteAn_4lines_21, spriteAn_4lines_22, fscale);
		if(enableAnimation2lines_with_void)
			animation_2_lines_with_voidFn(window, indexesOfIdLines, spriteAn_1line_1, spriteAn_1line_2, spriteAn_1line_3, spriteAn_1line_4, spriteAn_1line_5, spriteAn_1line_6, spriteAn_1line_7,
				spriteAn_1line_8, spriteAn_1line_9, spriteAn_1line_10, spriteAn_1line_11, spriteAn_1line_12, spriteAn_1line_13, spriteAn_1line_14, spriteAn_1line_15,
				spriteAn_1line_16, spriteAn_1line_17, spriteAn_1line_18, spriteAn_1line_19, spriteAn_1line_20, spriteAn_1line_21, spriteAn_1line_22, fscale);
		if (enableAnimation3lines_with_void)
			animation_3_lines_with_voidFn(window, indexesOfIdLines, spriteAn_1line_1, spriteAn_1line_2, spriteAn_1line_3, spriteAn_1line_4, spriteAn_1line_5, spriteAn_1line_6, spriteAn_1line_7,
				spriteAn_1line_8, spriteAn_1line_9, spriteAn_1line_10, spriteAn_1line_11, spriteAn_1line_12, spriteAn_1line_13, spriteAn_1line_14, spriteAn_1line_15,
				spriteAn_1line_16, spriteAn_1line_17, spriteAn_1line_18, spriteAn_1line_19, spriteAn_1line_20, spriteAn_1line_21, spriteAn_1line_22, spriteAn_2lines_1, spriteAn_2lines_2, spriteAn_2lines_3, spriteAn_2lines_4, spriteAn_2lines_5, spriteAn_2lines_6, spriteAn_2lines_7,
				spriteAn_2lines_8, spriteAn_2lines_9, spriteAn_2lines_10, spriteAn_2lines_11, spriteAn_2lines_12, spriteAn_2lines_13, spriteAn_2lines_14, spriteAn_2lines_15,
				spriteAn_2lines_16, spriteAn_2lines_17, spriteAn_2lines_18, spriteAn_2lines_19, spriteAn_2lines_20, spriteAn_2lines_21, spriteAn_2lines_22, fscale);
	
		if (enableAnimation_fast_falling_1InRow_1Row)
			animation_fast_falling_1InRow_1RowFn(window, spriteAn_1_inRow_1Row_1, spriteAn_1_inRow_1Row_2, fscale);
		if (enableAnimation_fast_falling_1InRow_2Rows)
			animation_fast_falling_1InRow_2RowsFn(window, spriteAn_1_inRow_2Rows_1, spriteAn_1_inRow_2Rows_2, fscale);
		if (enableAnimation_fast_falling_1InRow_3Rows)
			animation_fast_falling_1InRow_3RowsFn(window, spriteAn_1_inRow_3Rows_1, spriteAn_1_inRow_3Rows_2, fscale);
		if (enableAnimation_fast_falling_1InRow_4Rows)
			animation_fast_falling_1InRow_4RowsFn(window, spriteAn_1_inRow_4Rows_1, spriteAn_1_inRow_4Rows_2, spriteAn_1_inRow_4Rows_3, spriteAn_1_inRow_4Rows_4, fscale);
		if (enableAnimation_fast_falling_1InRow_5Rows)
			animation_fast_falling_1InRow_5RowsFn(window, spriteAn_1_inRow_5Rows_1, spriteAn_1_inRow_5Rows_2, spriteAn_1_inRow_5Rows_3, spriteAn_1_inRow_5Rows_4, fscale);
		if (enableAnimation_fast_falling_1InRow_6Rows)
			animation_fast_falling_1InRow_6RowsFn(window, spriteAn_1_inRow_6Rows_1, spriteAn_1_inRow_6Rows_2, spriteAn_1_inRow_6Rows_3, spriteAn_1_inRow_6Rows_4, fscale);
		if (enableAnimation_fast_falling_1InRow_7Rows)
			animation_fast_falling_1InRow_7RowsFn(window, spriteAn_1_inRow_7Rows_1, spriteAn_1_inRow_7Rows_2, spriteAn_1_inRow_7Rows_3, spriteAn_1_inRow_7Rows_4,
				spriteAn_1_inRow_7Rows_5, spriteAn_1_inRow_7Rows_6, fscale);
		if (enableAnimation_fast_falling_1InRow_8Rows)
			animation_fast_falling_1InRow_8RowsFn(window, spriteAn_1_inRow_8Rows_1, spriteAn_1_inRow_8Rows_2, spriteAn_1_inRow_8Rows_3, spriteAn_1_inRow_8Rows_4,
				spriteAn_1_inRow_8Rows_5, spriteAn_1_inRow_8Rows_6, fscale);
		if (enableAnimation_fast_falling_1InRow_9Rows)
			animation_fast_falling_1InRow_9RowsFn(window, spriteAn_1_inRow_9Rows_1, spriteAn_1_inRow_9Rows_2, spriteAn_1_inRow_9Rows_3, spriteAn_1_inRow_9Rows_4,
				spriteAn_1_inRow_9Rows_5, spriteAn_1_inRow_9Rows_6, fscale);
		if (enableAnimation_fast_falling_1InRow_10Rows)
		animation_fast_falling_1InRow_10RowsFn(window, spriteAn_1_inRow_10Rows_1, spriteAn_1_inRow_10Rows_2, spriteAn_1_inRow_10Rows_3, spriteAn_1_inRow_10Rows_4,
			spriteAn_1_inRow_10Rows_5, spriteAn_1_inRow_10Rows_6, spriteAn_1_inRow_10Rows_7, spriteAn_1_inRow_10Rows_8, fscale);
		if (enableAnimation_fast_falling_1InRow_11Rows)
		animation_fast_falling_1InRow_11RowsFn(window, spriteAn_1_inRow_11Rows_1, spriteAn_1_inRow_11Rows_2, spriteAn_1_inRow_11Rows_3, spriteAn_1_inRow_11Rows_4,
			spriteAn_1_inRow_11Rows_5, spriteAn_1_inRow_11Rows_6, spriteAn_1_inRow_11Rows_7, spriteAn_1_inRow_11Rows_8, fscale);
		if (enableAnimation_fast_falling_1InRow_12Rows)
			animation_fast_falling_1InRow_12RowsFn(window, spriteAn_1_inRow_12Rows_1, spriteAn_1_inRow_12Rows_2, spriteAn_1_inRow_12Rows_3, spriteAn_1_inRow_12Rows_4,
				spriteAn_1_inRow_12Rows_5, spriteAn_1_inRow_12Rows_6, spriteAn_1_inRow_12Rows_7, spriteAn_1_inRow_12Rows_8, fscale);
		if (enableAnimation_fast_falling_1InRow_13Rows)
			animation_fast_falling_1InRow_13RowsFn(window, spriteAn_1_inRow_13Rows_1, spriteAn_1_inRow_13Rows_2, spriteAn_1_inRow_13Rows_3, spriteAn_1_inRow_13Rows_4,
				spriteAn_1_inRow_13Rows_5, spriteAn_1_inRow_13Rows_6, spriteAn_1_inRow_13Rows_7, spriteAn_1_inRow_13Rows_8, spriteAn_1_inRow_13Rows_9, spriteAn_1_inRow_13Rows_10, fscale);
		if (enableAnimation_fast_falling_1InRow_14Rows)
			animation_fast_falling_1InRow_14RowsFn(window, spriteAn_1_inRow_14Rows_1, spriteAn_1_inRow_14Rows_2, spriteAn_1_inRow_14Rows_3, spriteAn_1_inRow_14Rows_4,
				spriteAn_1_inRow_14Rows_5, spriteAn_1_inRow_14Rows_6, spriteAn_1_inRow_14Rows_7, spriteAn_1_inRow_14Rows_8, spriteAn_1_inRow_14Rows_9, spriteAn_1_inRow_14Rows_10, fscale);
		if (enableAnimation_fast_falling_1InRow_15Rows)
			animation_fast_falling_1InRow_15RowsFn(window, spriteAn_1_inRow_15Rows_1, spriteAn_1_inRow_15Rows_2, spriteAn_1_inRow_15Rows_3, spriteAn_1_inRow_15Rows_4,
				spriteAn_1_inRow_15Rows_5, spriteAn_1_inRow_15Rows_6, spriteAn_1_inRow_15Rows_7, spriteAn_1_inRow_15Rows_8, spriteAn_1_inRow_15Rows_9, spriteAn_1_inRow_15Rows_10, fscale);
		if (enableAnimation_fast_falling_1InRow_16Rows)
			animation_fast_falling_1InRow_16RowsFn(window, spriteAn_1_inRow_16Rows_1, spriteAn_1_inRow_16Rows_2, spriteAn_1_inRow_16Rows_3, spriteAn_1_inRow_16Rows_4,
				spriteAn_1_inRow_16Rows_5, spriteAn_1_inRow_16Rows_6, spriteAn_1_inRow_16Rows_7, spriteAn_1_inRow_16Rows_8, spriteAn_1_inRow_16Rows_9, spriteAn_1_inRow_16Rows_10,
				spriteAn_1_inRow_16Rows_11, spriteAn_1_inRow_16Rows_12, fscale);
		if (enableAnimation_fast_falling_1InRow_17Rows)
			animation_fast_falling_1InRow_17RowsFn(window, spriteAn_1_inRow_17Rows_1, spriteAn_1_inRow_17Rows_2, spriteAn_1_inRow_17Rows_3, spriteAn_1_inRow_17Rows_4,
				spriteAn_1_inRow_17Rows_5, spriteAn_1_inRow_17Rows_6, spriteAn_1_inRow_17Rows_7, spriteAn_1_inRow_17Rows_8, spriteAn_1_inRow_17Rows_9, spriteAn_1_inRow_17Rows_10,
				spriteAn_1_inRow_17Rows_11, spriteAn_1_inRow_17Rows_12, fscale);

		if (enableAnimation_fast_falling_2InRow_1Row)
			animation_fast_falling_2InRow_1RowFn(window, spriteAn_2_inRow_1Row_1, spriteAn_2_inRow_1Row_2, fscale);
		if (enableAnimation_fast_falling_2InRow_2Rows)
			animation_fast_falling_2InRow_2RowsFn(window, spriteAn_2_inRow_2Rows_1, spriteAn_2_inRow_2Rows_2, fscale);
		if (enableAnimation_fast_falling_2InRow_3Rows)
			animation_fast_falling_2InRow_3RowsFn(window, spriteAn_2_inRow_3Rows_1, spriteAn_2_inRow_3Rows_2, fscale);
		if (enableAnimation_fast_falling_2InRow_4Rows)
			animation_fast_falling_2InRow_4RowsFn(window, spriteAn_2_inRow_4Rows_1, spriteAn_2_inRow_4Rows_2, spriteAn_2_inRow_4Rows_3, spriteAn_2_inRow_4Rows_4, fscale);
		if (enableAnimation_fast_falling_2InRow_5Rows)
			animation_fast_falling_2InRow_5RowsFn(window, spriteAn_2_inRow_5Rows_1, spriteAn_2_inRow_5Rows_2, spriteAn_2_inRow_5Rows_3, spriteAn_2_inRow_5Rows_4, fscale);
		if (enableAnimation_fast_falling_2InRow_6Rows)
			animation_fast_falling_2InRow_6RowsFn(window, spriteAn_2_inRow_6Rows_1, spriteAn_2_inRow_6Rows_2, spriteAn_2_inRow_6Rows_3, spriteAn_2_inRow_6Rows_4, fscale);
		if (enableAnimation_fast_falling_2InRow_7Rows)
			animation_fast_falling_2InRow_7RowsFn(window, spriteAn_2_inRow_7Rows_1, spriteAn_2_inRow_7Rows_2, spriteAn_2_inRow_7Rows_3, spriteAn_2_inRow_7Rows_4, spriteAn_2_inRow_7Rows_5, spriteAn_2_inRow_7Rows_6, fscale);
		if (enableAnimation_fast_falling_2InRow_8Rows)
			animation_fast_falling_2InRow_8RowsFn(window, spriteAn_2_inRow_8Rows_1, spriteAn_2_inRow_8Rows_2, spriteAn_2_inRow_8Rows_3, spriteAn_2_inRow_8Rows_4, spriteAn_2_inRow_8Rows_5, spriteAn_2_inRow_8Rows_6, fscale);
		if (enableAnimation_fast_falling_2InRow_9Rows)
			animation_fast_falling_2InRow_9RowsFn(window, spriteAn_2_inRow_9Rows_1, spriteAn_2_inRow_9Rows_2, spriteAn_2_inRow_9Rows_3, spriteAn_2_inRow_9Rows_4, spriteAn_2_inRow_9Rows_5, spriteAn_2_inRow_9Rows_6, fscale);
		if (enableAnimation_fast_falling_2InRow_10Rows)
			animation_fast_falling_2InRow_10RowsFn(window, spriteAn_2_inRow_10Rows_1, spriteAn_2_inRow_10Rows_2, spriteAn_2_inRow_10Rows_3, spriteAn_2_inRow_10Rows_4, spriteAn_2_inRow_10Rows_5, spriteAn_2_inRow_10Rows_6, spriteAn_2_inRow_10Rows_7, spriteAn_2_inRow_10Rows_8, fscale);
		if (enableAnimation_fast_falling_2InRow_11Rows)
			animation_fast_falling_2InRow_11RowsFn(window, spriteAn_2_inRow_11Rows_1, spriteAn_2_inRow_11Rows_2, spriteAn_2_inRow_11Rows_3, spriteAn_2_inRow_11Rows_4, spriteAn_2_inRow_11Rows_5, spriteAn_2_inRow_11Rows_6, spriteAn_2_inRow_11Rows_7, spriteAn_2_inRow_11Rows_8, fscale);
		if (enableAnimation_fast_falling_2InRow_12Rows)
			animation_fast_falling_2InRow_12RowsFn(window, spriteAn_2_inRow_12Rows_1, spriteAn_2_inRow_12Rows_2, spriteAn_2_inRow_12Rows_3, spriteAn_2_inRow_12Rows_4, spriteAn_2_inRow_12Rows_5, spriteAn_2_inRow_12Rows_6, spriteAn_2_inRow_12Rows_7, spriteAn_2_inRow_12Rows_8, fscale);
		if (enableAnimation_fast_falling_2InRow_13Rows)
			animation_fast_falling_2InRow_13RowsFn(window, spriteAn_2_inRow_13Rows_1, spriteAn_2_inRow_13Rows_2, spriteAn_2_inRow_13Rows_3, spriteAn_2_inRow_13Rows_4, spriteAn_2_inRow_13Rows_5, spriteAn_2_inRow_13Rows_6, spriteAn_2_inRow_13Rows_7, spriteAn_2_inRow_13Rows_8, spriteAn_2_inRow_13Rows_9, spriteAn_2_inRow_13Rows_10, fscale);
		if (enableAnimation_fast_falling_2InRow_14Rows)
			animation_fast_falling_2InRow_14RowsFn(window, spriteAn_2_inRow_14Rows_1, spriteAn_2_inRow_14Rows_2, spriteAn_2_inRow_14Rows_3, spriteAn_2_inRow_14Rows_4, spriteAn_2_inRow_14Rows_5, spriteAn_2_inRow_14Rows_6, spriteAn_2_inRow_14Rows_7, spriteAn_2_inRow_14Rows_8, spriteAn_2_inRow_14Rows_9, spriteAn_2_inRow_14Rows_10, fscale);
		if (enableAnimation_fast_falling_2InRow_15Rows)
			animation_fast_falling_2InRow_15RowsFn(window, spriteAn_2_inRow_15Rows_1, spriteAn_2_inRow_15Rows_2, spriteAn_2_inRow_15Rows_3, spriteAn_2_inRow_15Rows_4, spriteAn_2_inRow_15Rows_5, spriteAn_2_inRow_15Rows_6, spriteAn_2_inRow_15Rows_7, spriteAn_2_inRow_15Rows_8, spriteAn_2_inRow_15Rows_9, spriteAn_2_inRow_15Rows_10, fscale);
		if (enableAnimation_fast_falling_2InRow_16Rows)
			animation_fast_falling_2InRow_16RowsFn(window, spriteAn_2_inRow_16Rows_1, spriteAn_2_inRow_16Rows_2, spriteAn_2_inRow_16Rows_3, spriteAn_2_inRow_16Rows_4, spriteAn_2_inRow_16Rows_5, spriteAn_2_inRow_16Rows_6, spriteAn_2_inRow_16Rows_7, spriteAn_2_inRow_16Rows_8, spriteAn_2_inRow_16Rows_9, spriteAn_2_inRow_16Rows_10, spriteAn_2_inRow_16Rows_11, spriteAn_2_inRow_16Rows_12, fscale);
		if (enableAnimation_fast_falling_2InRow_17Rows)
			animation_fast_falling_2InRow_17RowsFn(window, spriteAn_2_inRow_17Rows_1, spriteAn_2_inRow_17Rows_2, spriteAn_2_inRow_17Rows_3, spriteAn_2_inRow_17Rows_4, spriteAn_2_inRow_17Rows_5, spriteAn_2_inRow_17Rows_6, spriteAn_2_inRow_17Rows_7, spriteAn_2_inRow_17Rows_8, spriteAn_2_inRow_17Rows_9, spriteAn_2_inRow_17Rows_10, spriteAn_2_inRow_17Rows_11, spriteAn_2_inRow_17Rows_12, fscale);
		
		if (enableAnimation_fast_falling_3InRow_1Row)
			animation_fast_falling_3InRow_1RowFn(window, spriteAn_3_inRow_1Row_1, spriteAn_3_inRow_1Row_2, fscale);
		if (enableAnimation_fast_falling_3InRow_2Rows)
			animation_fast_falling_3InRow_2RowsFn(window, spriteAn_3_inRow_2Rows_1, spriteAn_3_inRow_2Rows_2, fscale);
		if (enableAnimation_fast_falling_3InRow_3Rows)
			animation_fast_falling_3InRow_3RowsFn(window, spriteAn_3_inRow_3Rows_1, spriteAn_3_inRow_3Rows_2, fscale);
		if (enableAnimation_fast_falling_3InRow_4Rows)
			animation_fast_falling_3InRow_4RowsFn(window, spriteAn_3_inRow_4Rows_1, spriteAn_3_inRow_4Rows_2, spriteAn_3_inRow_4Rows_3, spriteAn_3_inRow_4Rows_4, fscale);
		if (enableAnimation_fast_falling_3InRow_5Rows)
			animation_fast_falling_3InRow_5RowsFn(window, spriteAn_3_inRow_5Rows_1, spriteAn_3_inRow_5Rows_2, spriteAn_3_inRow_5Rows_3, spriteAn_3_inRow_5Rows_4, fscale);
		if (enableAnimation_fast_falling_3InRow_6Rows)
			animation_fast_falling_3InRow_6RowsFn(window, spriteAn_3_inRow_6Rows_1, spriteAn_3_inRow_6Rows_2, spriteAn_3_inRow_6Rows_3, spriteAn_3_inRow_6Rows_4, fscale);
		if (enableAnimation_fast_falling_3InRow_7Rows)
			animation_fast_falling_3InRow_7RowsFn(window, spriteAn_3_inRow_7Rows_1, spriteAn_3_inRow_7Rows_2, spriteAn_3_inRow_7Rows_3, spriteAn_3_inRow_7Rows_4, spriteAn_3_inRow_7Rows_5, spriteAn_3_inRow_7Rows_6, fscale);
		if (enableAnimation_fast_falling_3InRow_8Rows)
			animation_fast_falling_3InRow_8RowsFn(window, spriteAn_3_inRow_8Rows_1, spriteAn_3_inRow_8Rows_2, spriteAn_3_inRow_8Rows_3, spriteAn_3_inRow_8Rows_4, spriteAn_3_inRow_8Rows_5, spriteAn_3_inRow_8Rows_6, fscale);
		if (enableAnimation_fast_falling_3InRow_9Rows)
			animation_fast_falling_3InRow_9RowsFn(window, spriteAn_3_inRow_9Rows_1, spriteAn_3_inRow_9Rows_2, spriteAn_3_inRow_9Rows_3, spriteAn_3_inRow_9Rows_4, spriteAn_3_inRow_9Rows_5, spriteAn_3_inRow_9Rows_6, fscale);
		if (enableAnimation_fast_falling_3InRow_10Rows)
			animation_fast_falling_3InRow_10RowsFn(window, spriteAn_3_inRow_10Rows_1, spriteAn_3_inRow_10Rows_2, spriteAn_3_inRow_10Rows_3, spriteAn_3_inRow_10Rows_4, spriteAn_3_inRow_10Rows_5, spriteAn_3_inRow_10Rows_6, spriteAn_3_inRow_10Rows_7, spriteAn_3_inRow_10Rows_8, fscale);
		if (enableAnimation_fast_falling_3InRow_11Rows)
			animation_fast_falling_3InRow_11RowsFn(window, spriteAn_3_inRow_11Rows_1, spriteAn_3_inRow_11Rows_2, spriteAn_3_inRow_11Rows_3, spriteAn_3_inRow_11Rows_4, spriteAn_3_inRow_11Rows_5, spriteAn_3_inRow_11Rows_6, spriteAn_3_inRow_11Rows_7, spriteAn_3_inRow_11Rows_8, fscale);
		if (enableAnimation_fast_falling_3InRow_12Rows)
			animation_fast_falling_3InRow_12RowsFn(window, spriteAn_3_inRow_12Rows_1, spriteAn_3_inRow_12Rows_2, spriteAn_3_inRow_12Rows_3, spriteAn_3_inRow_12Rows_4, spriteAn_3_inRow_12Rows_5, spriteAn_3_inRow_12Rows_6, spriteAn_3_inRow_12Rows_7, spriteAn_3_inRow_12Rows_8, fscale);
		if (enableAnimation_fast_falling_3InRow_13Rows)
			animation_fast_falling_3InRow_13RowsFn(window, spriteAn_3_inRow_13Rows_1, spriteAn_3_inRow_13Rows_2, spriteAn_3_inRow_13Rows_3, spriteAn_3_inRow_13Rows_4, spriteAn_3_inRow_13Rows_5, spriteAn_3_inRow_13Rows_6, spriteAn_3_inRow_13Rows_7, spriteAn_3_inRow_13Rows_8, spriteAn_3_inRow_13Rows_9, spriteAn_3_inRow_13Rows_10, fscale);
		if (enableAnimation_fast_falling_3InRow_14Rows)
			animation_fast_falling_3InRow_14RowsFn(window, spriteAn_3_inRow_14Rows_1, spriteAn_3_inRow_14Rows_2, spriteAn_3_inRow_14Rows_3, spriteAn_3_inRow_14Rows_4, spriteAn_3_inRow_14Rows_5, spriteAn_3_inRow_14Rows_6, spriteAn_3_inRow_14Rows_7, spriteAn_3_inRow_14Rows_8, spriteAn_3_inRow_14Rows_9, spriteAn_3_inRow_14Rows_10, fscale);
		if (enableAnimation_fast_falling_3InRow_15Rows)
			animation_fast_falling_3InRow_15RowsFn(window, spriteAn_3_inRow_15Rows_1, spriteAn_3_inRow_15Rows_2, spriteAn_3_inRow_15Rows_3, spriteAn_3_inRow_15Rows_4, spriteAn_3_inRow_15Rows_5, spriteAn_3_inRow_15Rows_6, spriteAn_3_inRow_15Rows_7, spriteAn_3_inRow_15Rows_8, spriteAn_3_inRow_15Rows_9, spriteAn_3_inRow_15Rows_10, fscale);
		if (enableAnimation_fast_falling_3InRow_16Rows)
			animation_fast_falling_3InRow_16RowsFn(window, spriteAn_3_inRow_16Rows_1, spriteAn_3_inRow_16Rows_2, spriteAn_3_inRow_16Rows_3, spriteAn_3_inRow_16Rows_4,
				spriteAn_3_inRow_16Rows_5, spriteAn_3_inRow_16Rows_6, spriteAn_3_inRow_16Rows_7, spriteAn_3_inRow_16Rows_8, spriteAn_3_inRow_16Rows_9,
				spriteAn_3_inRow_16Rows_10, spriteAn_3_inRow_16Rows_11, spriteAn_3_inRow_16Rows_12, fscale);
		if (enableAnimation_fast_falling_3InRow_17Rows)
			animation_fast_falling_3InRow_17RowsFn(window, spriteAn_3_inRow_17Rows_1, spriteAn_3_inRow_17Rows_2, spriteAn_3_inRow_17Rows_3, spriteAn_3_inRow_17Rows_4, spriteAn_3_inRow_17Rows_5, spriteAn_3_inRow_17Rows_6, spriteAn_3_inRow_17Rows_7, spriteAn_3_inRow_17Rows_8, spriteAn_3_inRow_17Rows_9, spriteAn_3_inRow_17Rows_10, spriteAn_3_inRow_17Rows_11, spriteAn_3_inRow_17Rows_12, fscale);
		if (enableAnimation_fast_falling_3InRow_18Rows)
			animation_fast_falling_3InRow_18RowsFn(window, spriteAn_3_inRow_18Rows_1, spriteAn_3_inRow_18Rows_2, spriteAn_3_inRow_18Rows_3, spriteAn_3_inRow_18Rows_4, spriteAn_3_inRow_18Rows_5, spriteAn_3_inRow_18Rows_6, spriteAn_3_inRow_18Rows_7, spriteAn_3_inRow_18Rows_8, spriteAn_3_inRow_18Rows_9, spriteAn_3_inRow_18Rows_10, spriteAn_3_inRow_18Rows_11, spriteAn_3_inRow_18Rows_12, fscale);
		//checkFullLineFn2(field); //хз для чего это тут

		if (enableAnimation_fast_falling_4InRow_1Row)
			animation_fast_falling_4InRow_1RowFn(window, spriteAn_4_inRow_1Row_1, spriteAn_4_inRow_1Row_2, fscale);
		if (enableAnimation_fast_falling_4InRow_2Rows)
			animation_fast_falling_4InRow_2RowsFn(window, spriteAn_4_inRow_2Rows_1, spriteAn_4_inRow_2Rows_2, fscale);
		if (enableAnimation_fast_falling_4InRow_3Rows)
			animation_fast_falling_4InRow_3RowsFn(window, spriteAn_4_inRow_3Rows_1, spriteAn_4_inRow_3Rows_2, fscale);
		if (enableAnimation_fast_falling_4InRow_4Rows)
			animation_fast_falling_4InRow_4RowsFn(window, spriteAn_4_inRow_4Rows_1, spriteAn_4_inRow_4Rows_2, spriteAn_4_inRow_4Rows_3, spriteAn_4_inRow_4Rows_4, fscale);
		if (enableAnimation_fast_falling_4InRow_5Rows)
			animation_fast_falling_4InRow_5RowsFn(window, spriteAn_4_inRow_5Rows_1, spriteAn_4_inRow_5Rows_2, spriteAn_4_inRow_5Rows_3, spriteAn_4_inRow_5Rows_4, fscale);
		if (enableAnimation_fast_falling_4InRow_6Rows)
			animation_fast_falling_4InRow_6RowsFn(window, spriteAn_4_inRow_6Rows_1, spriteAn_4_inRow_6Rows_2, spriteAn_4_inRow_6Rows_3, spriteAn_4_inRow_6Rows_4, fscale);
		if (enableAnimation_fast_falling_4InRow_7Rows)
			animation_fast_falling_4InRow_7RowsFn(window, spriteAn_4_inRow_7Rows_1, spriteAn_4_inRow_7Rows_2, spriteAn_4_inRow_7Rows_3, spriteAn_4_inRow_7Rows_4, spriteAn_4_inRow_7Rows_5, spriteAn_4_inRow_7Rows_6, fscale);
		if (enableAnimation_fast_falling_4InRow_8Rows)
			animation_fast_falling_4InRow_8RowsFn(window, spriteAn_4_inRow_8Rows_1, spriteAn_4_inRow_8Rows_2, spriteAn_4_inRow_8Rows_3, spriteAn_4_inRow_8Rows_4, spriteAn_4_inRow_8Rows_5, spriteAn_4_inRow_8Rows_6, fscale);
		if (enableAnimation_fast_falling_4InRow_9Rows)
			animation_fast_falling_4InRow_9RowsFn(window, spriteAn_4_inRow_9Rows_1, spriteAn_4_inRow_9Rows_2, spriteAn_4_inRow_9Rows_3, spriteAn_4_inRow_9Rows_4, spriteAn_4_inRow_9Rows_5, spriteAn_4_inRow_9Rows_6, fscale);
		if (enableAnimation_fast_falling_4InRow_10Rows)
			animation_fast_falling_4InRow_10RowsFn(window, spriteAn_4_inRow_10Rows_1, spriteAn_4_inRow_10Rows_2, spriteAn_4_inRow_10Rows_3, spriteAn_4_inRow_10Rows_4, spriteAn_4_inRow_10Rows_5, spriteAn_4_inRow_10Rows_6, spriteAn_4_inRow_10Rows_7, spriteAn_4_inRow_10Rows_8, fscale);
		if (enableAnimation_fast_falling_4InRow_11Rows)
			animation_fast_falling_4InRow_11RowsFn(window, spriteAn_4_inRow_11Rows_1, spriteAn_4_inRow_11Rows_2, spriteAn_4_inRow_11Rows_3, spriteAn_4_inRow_11Rows_4, spriteAn_4_inRow_11Rows_5, spriteAn_4_inRow_11Rows_6, spriteAn_4_inRow_11Rows_7, spriteAn_4_inRow_11Rows_8, fscale);
		if (enableAnimation_fast_falling_4InRow_12Rows)
			animation_fast_falling_4InRow_12RowsFn(window, spriteAn_4_inRow_12Rows_1, spriteAn_4_inRow_12Rows_2, spriteAn_4_inRow_12Rows_3, spriteAn_4_inRow_12Rows_4, spriteAn_4_inRow_12Rows_5, spriteAn_4_inRow_12Rows_6, spriteAn_4_inRow_12Rows_7, spriteAn_4_inRow_12Rows_8, fscale);
		if (enableAnimation_fast_falling_4InRow_13Rows)
			animation_fast_falling_4InRow_13RowsFn(window, spriteAn_4_inRow_13Rows_1, spriteAn_4_inRow_13Rows_2, spriteAn_4_inRow_13Rows_3, spriteAn_4_inRow_13Rows_4, spriteAn_4_inRow_13Rows_5, spriteAn_4_inRow_13Rows_6, spriteAn_4_inRow_13Rows_7, spriteAn_4_inRow_13Rows_8, spriteAn_4_inRow_13Rows_9, spriteAn_4_inRow_13Rows_10, fscale);
		if (enableAnimation_fast_falling_4InRow_14Rows)
			animation_fast_falling_4InRow_14RowsFn(window, spriteAn_4_inRow_14Rows_1, spriteAn_4_inRow_14Rows_2, spriteAn_4_inRow_14Rows_3, spriteAn_4_inRow_14Rows_4, spriteAn_4_inRow_14Rows_5, spriteAn_4_inRow_14Rows_6, spriteAn_4_inRow_14Rows_7, spriteAn_4_inRow_14Rows_8, spriteAn_4_inRow_14Rows_9, spriteAn_4_inRow_14Rows_10, fscale);
		if (enableAnimation_fast_falling_4InRow_15Rows)
			animation_fast_falling_4InRow_15RowsFn(window, spriteAn_4_inRow_15Rows_1, spriteAn_4_inRow_15Rows_2, spriteAn_4_inRow_15Rows_3, spriteAn_4_inRow_15Rows_4, spriteAn_4_inRow_15Rows_5, spriteAn_4_inRow_15Rows_6, spriteAn_4_inRow_15Rows_7, spriteAn_4_inRow_15Rows_8, spriteAn_4_inRow_15Rows_9, spriteAn_4_inRow_15Rows_10, fscale);
		if (enableAnimation_fast_falling_4InRow_16Rows)
			animation_fast_falling_4InRow_16RowsFn(window, spriteAn_4_inRow_16Rows_1, spriteAn_4_inRow_16Rows_2, spriteAn_4_inRow_16Rows_3, spriteAn_4_inRow_16Rows_4, spriteAn_4_inRow_16Rows_5, spriteAn_4_inRow_16Rows_6, spriteAn_4_inRow_16Rows_7, spriteAn_4_inRow_16Rows_8, spriteAn_4_inRow_16Rows_9, spriteAn_4_inRow_16Rows_10, spriteAn_4_inRow_16Rows_11, spriteAn_4_inRow_16Rows_12, fscale);
		if (enableAnimation_fast_falling_4InRow_17Rows)
			animation_fast_falling_4InRow_17RowsFn(window, spriteAn_4_inRow_17Rows_1, spriteAn_4_inRow_17Rows_2, spriteAn_4_inRow_17Rows_3, spriteAn_4_inRow_17Rows_4, spriteAn_4_inRow_17Rows_5, spriteAn_4_inRow_17Rows_6, spriteAn_4_inRow_17Rows_7, spriteAn_4_inRow_17Rows_8, spriteAn_4_inRow_17Rows_9, spriteAn_4_inRow_17Rows_10, spriteAn_4_inRow_17Rows_11, spriteAn_4_inRow_17Rows_12, fscale);
		if (enableAnimation_fast_falling_4InRow_18Rows)
			animation_fast_falling_4InRow_18RowsFn(window, spriteAn_4_inRow_18Rows_1, spriteAn_4_inRow_18Rows_2, spriteAn_4_inRow_18Rows_3, spriteAn_4_inRow_18Rows_4, spriteAn_4_inRow_18Rows_5, spriteAn_4_inRow_18Rows_6, spriteAn_4_inRow_18Rows_7, spriteAn_4_inRow_18Rows_8, spriteAn_4_inRow_18Rows_9, spriteAn_4_inRow_18Rows_10, spriteAn_4_inRow_18Rows_11, spriteAn_4_inRow_18Rows_12, fscale);
		
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
	{
		throw std::runtime_error("Failed to load image from memory.");
	}
	
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
	//LOGGER(rsrcDataSize)
	//	LOGGER(firstByte)
	//	LOGGER(texture != nullptr)
	//cout<<ID<<endl;
	if (!texture->loadFromMemory(firstByte, rsrcDataSize))
		throw std::runtime_error("Failed to load image from memory.");
		//return nullptr;
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

void draw_3buttons(RenderWindow &win, Vector2i &mpos, Sprite &splst1, Sprite &splst2, Sprite &splst3, Sprite &sprst1, Sprite &sprst2, Sprite &sprst3, Sprite &spmst1, Sprite &spmst2, Sprite &spmst3, Vector2f fsc)
{

	//Отрисовка кнопки right Close

	if (IntRect(1799 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(sprst3);
		else win.draw(sprst2);
	}
	else win.draw(sprst1);

	//Отрисовка кнопки middle restore

	if (IntRect(1714 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(spmst3);
		else win.draw(spmst2);
	}
	else win.draw(spmst1);

	//Отрисовка кнопки left Minimize

	if (IntRect(1629 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(splst3);
		else win.draw(splst2);
	}
	else win.draw(splst1);
}

void draw_3buttons2(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3, Vector2f fsc)
{
	//Отрисовка кнопки middle restore

	if (IntRect(1714 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(spmst3);
		else win.draw(spmst2);
	}
	else win.draw(spmst1);

	//Отрисовка кнопки left Minimize

	if (IntRect(1629 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(splst3);
		else win.draw(splst2);
	}
	else win.draw(splst1);

	//Отрисовка кнопки right Close

	if (IntRect(1799 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(sprst3);
		else win.draw(sprst2);
	}
	else win.draw(sprst1);
}

void draw_3buttons3(RenderWindow& win, Vector2i& mpos, Sprite& splst1, Sprite& splst2, Sprite& splst3, Sprite& sprst1, Sprite& sprst2, Sprite& sprst3, Sprite& spmst1, Sprite& spmst2, Sprite& spmst3, Vector2f fsc)
{
	//Отрисовка кнопки right Close

	if (IntRect(1799 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(sprst3);
		else win.draw(sprst2);
	}
	else win.draw(sprst1);

	//Отрисовка кнопки left Minimize

	if (IntRect(1629 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(splst3);
		else win.draw(splst2);
	}
	else win.draw(splst1);

	//Отрисовка кнопки middle restore

	if (IntRect(1714 * fsc.x, 32 * fsc.y, 85 * fsc.x, 62 * fsc.y).contains(mpos.x, mpos.y))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			win.draw(spmst3);
		else win.draw(spmst2);
	}
	else win.draw(spmst1);
}

void create_window_for_loading_screen(Sprite* scr, Sprite *Load)
{
	ContextSettings* context = new ContextSettings(0, 0, 16); //antialliasing
	//RenderWindow* loading_screen = new RenderWindow(VideoMode(1920, 1080), "Tetris", Style::Close | Style::Titlebar | Style::Fullscreen);
	//RenderWindow* loading_screen = new RenderWindow(VideoMode(1920, 1080), "Tetris", Style::None);
	//RenderWindow* loading_screen = new RenderWindow(VideoMode(1280, 1024), "Tetris", Style::None, *context);
	//RenderWindow* loading_screen = new RenderWindow(VideoMode().getDesktopMode(), "Tetris", Style::None, *context);
	RenderWindow* loading_screen = new RenderWindow(VideoMode().getFullscreenModes()[0], "Tetris", Style::None, *context);
	//SetForegroundWindow(loading_screen->getSystemHandle());//чтобы сделать окно активным
	
	loading_screen->setMouseCursorVisible(false);
	loading_screen->setFramerateLimit(60);
	Vector2f fScaleLS{ factorOfScaleFn(*loading_screen) };// фактор скалирования загрузочного экрана
	Vector2f sprPos1{ 1612.f, 930.f };//позиция спрайта на экране в разрешении 1920х1080
	
	Load->setScale(fScaleLS);
	Load->setPosition(sprPos1.x * fScaleLS.x, sprPos1.y * fScaleLS.y);//установка позиции спрайта на экране в разрешениии 1920х1080
	Load->scale(0.7f, 0.7f);
	Load->move(120 * fScaleLS.x, 80 * fScaleLS.y);
	

	scr->setScale(factorOfScaleFn(*loading_screen));
	
	Event ev;

	loading_clock->restart();
	while (loading_screen->isOpen())
	{
		while (loading_screen->pollEvent(ev))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			switch (ev.type)
			{
			case Event::Closed:
				// Тогда закрываем его
				loading_screen->close();
				break;
			}
		}
		//loading_screen->clear(Color::White);
		USHORT lclock = loading_clock->getElapsedTime().asMilliseconds();
		//cout << lclock << endl;
		loading_screen->clear();
		loading_screen->draw(*scr);
		if (lclock > 0 && lclock < 1000)loading_screen->draw(*Load);
		if (lclock >= 1800) loading_clock->restart();
		loading_screen->display();
		if (!for_loading_scr)loading_screen->close();
	}

	delete loading_clock;
	loading_clock = nullptr;
}

Vector2f factorOfScaleFn(RenderWindow& win)
{
	Vector2f vec;

		vec.x = static_cast<float>(win.getSize().x) / 1920;
		vec.y = static_cast<float>(win.getSize().y) / 1080;

	return vec;
}

void animation_1_lineFn(RenderWindow& win, USHORT index, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5,
	Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11,
	Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17,
	Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Vector2f scale)
{
	progressOfAnimationLines = true;
	
	spriteAn_1line_1->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 2) * scale.y);
	spriteAn_1line_2->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 5) * scale.y);
	spriteAn_1line_3->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 7) * scale.y);
	spriteAn_1line_4->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
	spriteAn_1line_5->setPosition((771 - 50) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 11) * scale.y);
	spriteAn_1line_6->setPosition((771 - 50) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
	spriteAn_1line_7->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 16) * scale.y);
	spriteAn_1line_8->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_9->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_10->setPosition((771 - 48 + 13) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_11->setPosition((771 - 49 + 27) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_12->setPosition((771 - 48 + 40) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_13->setPosition((771 - 49 + 54) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_14->setPosition((771 - 48 + 67) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_15->setPosition((771 - 49 + 81) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_16->setPosition((771 - 48 + 94) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_17->setPosition((771 - 48 + 108) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_18->setPosition((771 - 48 + 121) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_19->setPosition((771 - 48 + 135) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_20->setPosition((771 - 46 + 148) * scale.x, (index * 38 + (38 * 6) - 9 - 50 + 18) * scale.y);
	spriteAn_1line_21->setPosition((771 - 45 + 162) * scale.x, (index * 38 + (38 * 6) - 9 - 48 + 18) * scale.y);
	spriteAn_1line_22->setPosition((771 - 41 + 175) * scale.x, (index * 38 + (38 * 6) - 9 - 44 + 18) * scale.y);

	
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

void animation_2_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_2lines_1, Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5, Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11, Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17, Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22, Vector2f scale)
{
	progressOfAnimationLines = true;

	spriteAn_2lines_1->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 5) * scale.y);
	spriteAn_2lines_2->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
	spriteAn_2lines_3->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
	spriteAn_2lines_4->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 19) * scale.y);
	spriteAn_2lines_5->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 23) * scale.y);
	spriteAn_2lines_6->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 28) * scale.y);
	spriteAn_2lines_7->setPosition((771 - 50) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 32) * scale.y);
	spriteAn_2lines_8->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_9->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_10->setPosition((771 - 48 + 13) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_11->setPosition((771 - 49 + 27) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_12->setPosition((771 - 48 + 40) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_13->setPosition((771 - 49 + 54) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_14->setPosition((771 - 48 + 67) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_15->setPosition((771 - 49 + 81) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_16->setPosition((771 - 48 + 94) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
	spriteAn_2lines_17->setPosition((771 - 48 + 108) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 37) * scale.y);
	spriteAn_2lines_18->setPosition((771 - 47 + 121) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 37) * scale.y);
	spriteAn_2lines_19->setPosition((771 - 48 + 135) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 37) * scale.y);
	spriteAn_2lines_20->setPosition((771 - 46 + 148) * scale.x, (index * 38 + (38 * 6) - 9 - 50 + 37) * scale.y);
	spriteAn_2lines_21->setPosition((771 - 45 + 162) * scale.x, (index * 38 + (38 * 6) - 9 - 48 + 37) * scale.y);
	spriteAn_2lines_22->setPosition((771 - 41 +  175) * scale.x, (index * 38 + (38 * 6) - 9 - 44 + 37) * scale.y);

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

void animation_3_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_3lines_1, Sprite* spriteAn_3lines_2, Sprite* spriteAn_3lines_3, Sprite* spriteAn_3lines_4, Sprite* spriteAn_3lines_5, Sprite* spriteAn_3lines_6, Sprite* spriteAn_3lines_7, Sprite* spriteAn_3lines_8, Sprite* spriteAn_3lines_9, Sprite* spriteAn_3lines_10, Sprite* spriteAn_3lines_11, Sprite* spriteAn_3lines_12, Sprite* spriteAn_3lines_13, Sprite* spriteAn_3lines_14, Sprite* spriteAn_3lines_15, Sprite* spriteAn_3lines_16, Sprite* spriteAn_3lines_17, Sprite* spriteAn_3lines_18, Sprite* spriteAn_3lines_19, Sprite* spriteAn_3lines_20, Sprite* spriteAn_3lines_21, Sprite* spriteAn_3lines_22, Vector2f scale)
{
	progressOfAnimationLines = true;

	spriteAn_3lines_1->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 7) * scale.y);
	spriteAn_3lines_2->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
	spriteAn_3lines_3->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 21) * scale.y);
	spriteAn_3lines_4->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 28) * scale.y);
	spriteAn_3lines_5->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 35) * scale.y);
	spriteAn_3lines_6->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 42) * scale.y);
	spriteAn_3lines_7->setPosition((771 - 50) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 49) * scale.y);
	spriteAn_3lines_8->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_9->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_10->setPosition((771 - 48 + 13) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_11->setPosition((771 - 49 + 27) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_12->setPosition((771 - 48 + 40) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_13->setPosition((771 - 49 + 54) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_14->setPosition((771 - 48 + 67) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_15->setPosition((771 - 49 + 81) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_16->setPosition((771 - 48 + 94) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 56) * scale.y);
	spriteAn_3lines_17->setPosition((771 - 48 + 108) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 56) * scale.y);
	spriteAn_3lines_18->setPosition((771 - 47 + 121) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 56) * scale.y);
	spriteAn_3lines_19->setPosition((771 - 48 + 135) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 56) * scale.y);
	spriteAn_3lines_20->setPosition((771 - 46 + 148) * scale.x, (index * 38 + (38 * 6) - 9 - 50 + 56) * scale.y);
	spriteAn_3lines_21->setPosition((771 - 45 + 162) * scale.x, (index * 38 + (38 * 6) - 9 - 48 + 56) * scale.y);
	spriteAn_3lines_22->setPosition((771 - 41 + 175) * scale.x, (index * 38 + (38 * 6) - 9 - 44 + 56) * scale.y);

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

void animation_4_linesFn(RenderWindow& win, USHORT index, Sprite* spriteAn_4lines_1, Sprite* spriteAn_4lines_2, Sprite* spriteAn_4lines_3, Sprite* spriteAn_4lines_4, Sprite* spriteAn_4lines_5, Sprite* spriteAn_4lines_6, Sprite* spriteAn_4lines_7, Sprite* spriteAn_4lines_8, Sprite* spriteAn_4lines_9, Sprite* spriteAn_4lines_10, Sprite* spriteAn_4lines_11, Sprite* spriteAn_4lines_12, Sprite* spriteAn_4lines_13, Sprite* spriteAn_4lines_14, Sprite* spriteAn_4lines_15, Sprite* spriteAn_4lines_16, Sprite* spriteAn_4lines_17, Sprite* spriteAn_4lines_18, Sprite* spriteAn_4lines_19, Sprite* spriteAn_4lines_20, Sprite* spriteAn_4lines_21, Sprite* spriteAn_4lines_22, Vector2f scale)
{
	progressOfAnimationLines = true;


	spriteAn_4lines_1->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
	spriteAn_4lines_2->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 19) * scale.y);
	spriteAn_4lines_3->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 28) * scale.y);
	spriteAn_4lines_4->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 38) * scale.y);
	spriteAn_4lines_5->setPosition((771 - 52) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 47) * scale.y);
	spriteAn_4lines_6->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 56) * scale.y);
	spriteAn_4lines_7->setPosition((771 - 51) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 66) * scale.y);
	spriteAn_4lines_8->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_9->setPosition((771 - 49) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_10->setPosition((771 - 48 + 13) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_11->setPosition((771 - 49 + 27) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_12->setPosition((771 - 48 + 40) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_13->setPosition((771 - 49 + 54) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_14->setPosition((771 - 48 + 67) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_15->setPosition((771 - 49 + 81) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_16->setPosition((771 - 48 + 94) * scale.x, (index * 38 + (38 * 6) - 9 - 52 + 75) * scale.y);
	spriteAn_4lines_17->setPosition((771 - 48 + 108) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 75) * scale.y);
	spriteAn_4lines_18->setPosition((771 - 48 + 121) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 75) * scale.y);
	spriteAn_4lines_19->setPosition((771 - 48 + 135) * scale.x, (index * 38 + (38 * 6) - 9 - 51 + 75) * scale.y);
	spriteAn_4lines_20->setPosition((771 - 46 + 148) * scale.x, (index * 38 + (38 * 6) - 9 - 50 + 75) * scale.y);
	spriteAn_4lines_21->setPosition((771 - 45 + 162) * scale.x, (index * 38 + (38 * 6) - 9 - 48 + 75) * scale.y);
	spriteAn_4lines_22->setPosition((771 - 41 + 175) * scale.x, (index * 38 + (38 * 6) - 9 - 44 + 75) * scale.y);

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

void animation_2_lines_with_voidFn(RenderWindow& win, vector<USHORT>& vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5, Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11, Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17, Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Vector2f scale)
{
	progressOfAnimationLines = true;

	spriteAn_1line_1->setPosition((771 - 51) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 2) * scale.y);
	spriteAn_1line_2->setPosition((771 - 51) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 5) * scale.y);
	spriteAn_1line_3->setPosition((771 - 51) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 7) * scale.y);
	spriteAn_1line_4->setPosition((771 - 51) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
	spriteAn_1line_5->setPosition((771 - 50) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 11) * scale.y);
	spriteAn_1line_6->setPosition((771 - 50) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
	spriteAn_1line_7->setPosition((771 - 49) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 16) * scale.y);
	spriteAn_1line_8->setPosition((771 - 49) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_9->setPosition((771 - 49) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_10->setPosition((771 - 48 + 13) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_11->setPosition((771 - 49 + 27) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_12->setPosition((771 - 48 + 40) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_13->setPosition((771 - 49 + 54) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_14->setPosition((771 - 48 + 67) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_15->setPosition((771 - 49 + 81) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_16->setPosition((771 - 48 + 94) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_17->setPosition((771 - 48 + 108) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_18->setPosition((771 - 48 + 121) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_19->setPosition((771 - 48 + 135) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_20->setPosition((771 - 46 + 148) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 50 + 18) * scale.y);
	spriteAn_1line_21->setPosition((771 - 45 + 162) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 48 + 18) * scale.y);
	spriteAn_1line_22->setPosition((771 - 41 + 175) * scale.x, (vec[0] * 38 + (38 * 6) - 9 - 44 + 18) * scale.y);


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

	spriteAn_1line_1->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 2) * scale.y);
	spriteAn_1line_2->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 5) * scale.y);
	spriteAn_1line_3->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 7) * scale.y);
	spriteAn_1line_4->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
	spriteAn_1line_5->setPosition((771 - 50) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 11) * scale.y);
	spriteAn_1line_6->setPosition((771 - 50) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
	spriteAn_1line_7->setPosition((771 - 49) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 16) * scale.y);
	spriteAn_1line_8->setPosition((771 - 49) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_9->setPosition((771 - 49) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_10->setPosition((771 - 48 + 13) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_11->setPosition((771 - 49 + 27) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_12->setPosition((771 - 48 + 40) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_13->setPosition((771 - 49 + 54) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_14->setPosition((771 - 48 + 67) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_15->setPosition((771 - 49 + 81) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_16->setPosition((771 - 48 + 94) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
	spriteAn_1line_17->setPosition((771 - 48 + 108) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_18->setPosition((771 - 48 + 121) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_19->setPosition((771 - 48 + 135) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
	spriteAn_1line_20->setPosition((771 - 46 + 148) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 50 + 18) * scale.y);
	spriteAn_1line_21->setPosition((771 - 45 + 162) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 48 + 18) * scale.y);
	spriteAn_1line_22->setPosition((771 - 41 + 175) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 44 + 18) * scale.y);

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

void animation_3_lines_with_voidFn(RenderWindow& win, vector<USHORT>& vec, Sprite* spriteAn_1line_1, Sprite* spriteAn_1line_2, Sprite* spriteAn_1line_3, Sprite* spriteAn_1line_4, Sprite* spriteAn_1line_5, Sprite* spriteAn_1line_6, Sprite* spriteAn_1line_7, Sprite* spriteAn_1line_8, Sprite* spriteAn_1line_9, Sprite* spriteAn_1line_10, Sprite* spriteAn_1line_11, Sprite* spriteAn_1line_12, Sprite* spriteAn_1line_13, Sprite* spriteAn_1line_14, Sprite* spriteAn_1line_15, Sprite* spriteAn_1line_16, Sprite* spriteAn_1line_17, Sprite* spriteAn_1line_18, Sprite* spriteAn_1line_19, Sprite* spriteAn_1line_20, Sprite* spriteAn_1line_21, Sprite* spriteAn_1line_22, Sprite* spriteAn_2lines_1,
	Sprite* spriteAn_2lines_2, Sprite* spriteAn_2lines_3, Sprite* spriteAn_2lines_4, Sprite* spriteAn_2lines_5, Sprite* spriteAn_2lines_6, Sprite* spriteAn_2lines_7, Sprite* spriteAn_2lines_8, Sprite* spriteAn_2lines_9, Sprite* spriteAn_2lines_10, Sprite* spriteAn_2lines_11, Sprite* spriteAn_2lines_12, Sprite* spriteAn_2lines_13, Sprite* spriteAn_2lines_14, Sprite* spriteAn_2lines_15, Sprite* spriteAn_2lines_16, Sprite* spriteAn_2lines_17, Sprite* spriteAn_2lines_18, Sprite* spriteAn_2lines_19, Sprite* spriteAn_2lines_20, Sprite* spriteAn_2lines_21, Sprite* spriteAn_2lines_22, Vector2f scale)
{
	progressOfAnimationLines = true;
	if (indexesOfIdLines[0] - indexesOfIdLines[1] == 1)
	{
		spriteAn_1line_1->setPosition((771 - 51) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 2) * scale.y);
		spriteAn_1line_2->setPosition((771 - 51) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 5) * scale.y);
		spriteAn_1line_3->setPosition((771 - 51) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 7) * scale.y);
		spriteAn_1line_4->setPosition((771 - 51) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
		spriteAn_1line_5->setPosition((771 - 50) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 11) * scale.y);
		spriteAn_1line_6->setPosition((771 - 50) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
		spriteAn_1line_7->setPosition((771 - 49) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 16) * scale.y);
		spriteAn_1line_8->setPosition((771 - 49) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_9->setPosition((771 - 49) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_10->setPosition((771 - 48 + 13) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_11->setPosition((771 - 49 + 27) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_12->setPosition((771 - 48 + 40) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_13->setPosition((771 - 49 + 54) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_14->setPosition((771 - 48 + 67) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_15->setPosition((771 - 49 + 81) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_16->setPosition((771 - 48 + 94) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 18) * scale.y);
		spriteAn_1line_17->setPosition((771 - 48 + 108) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
		spriteAn_1line_18->setPosition((771 - 48 + 121) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
		spriteAn_1line_19->setPosition((771 - 48 + 135) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 18) * scale.y);
		spriteAn_1line_20->setPosition((771 - 46 + 148) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 50 + 18) * scale.y);
		spriteAn_1line_21->setPosition((771 - 45 + 162) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 48 + 18) * scale.y);
		spriteAn_1line_22->setPosition((771 - 41 + 175) * scale.x, (vec[2] * 38 + (38 * 6) - 9 - 44 + 18) * scale.y);

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


		spriteAn_2lines_1->setPosition((771 - 52) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 5) * scale.y);
		spriteAn_2lines_2->setPosition((771 - 52) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 9) * scale.y);
		spriteAn_2lines_3->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 14) * scale.y);
		spriteAn_2lines_4->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 19) * scale.y);
		spriteAn_2lines_5->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 23) * scale.y);
		spriteAn_2lines_6->setPosition((771 - 51) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 28) * scale.y);
		spriteAn_2lines_7->setPosition((771 - 50) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 32) * scale.y);
		spriteAn_2lines_8->setPosition((771 - 49) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_9->setPosition((771 - 49) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_10->setPosition((771 - 48 + 13) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_11->setPosition((771 - 49 + 27) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_12->setPosition((771 - 48 + 40) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_13->setPosition((771 - 49 + 54) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_14->setPosition((771 - 48 + 67) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_15->setPosition((771 - 49 + 81) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_16->setPosition((771 - 48 + 94) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 52 + 37) * scale.y);
		spriteAn_2lines_17->setPosition((771 - 48 + 108) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 37) * scale.y);
		spriteAn_2lines_18->setPosition((771 - 47 + 121) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 37) * scale.y);
		spriteAn_2lines_19->setPosition((771 - 48 + 135) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 51 + 37) * scale.y);
		spriteAn_2lines_20->setPosition((771 - 46 + 148) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 50 + 37) * scale.y);
		spriteAn_2lines_21->setPosition((771 - 45 + 162) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 48 + 37) * scale.y);
		spriteAn_2lines_22->setPosition((771 - 41 + 175) * scale.x, (vec[1] * 38 + (38 * 6) - 9 - 44 + 37) * scale.y);

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
		spriteAn_2lines_1->setPosition((771 - 52)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 5)* scale.y);
		spriteAn_2lines_2->setPosition((771 - 52)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 9)* scale.y);
		spriteAn_2lines_3->setPosition((771 - 51)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 14)* scale.y);
		spriteAn_2lines_4->setPosition((771 - 51)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 19)* scale.y);
		spriteAn_2lines_5->setPosition((771 - 51)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 23)* scale.y);
		spriteAn_2lines_6->setPosition((771 - 51)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 28)* scale.y);
		spriteAn_2lines_7->setPosition((771 - 50)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 32)* scale.y);
		spriteAn_2lines_8->setPosition((771 - 49)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_9->setPosition((771 - 49)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_10->setPosition((771 - 48 + 13)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_11->setPosition((771 - 49 + 27)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_12->setPosition((771 - 48 + 40)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_13->setPosition((771 - 49 + 54)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_14->setPosition((771 - 48 + 67)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_15->setPosition((771 - 49 + 81)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_16->setPosition((771 - 48 + 94)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 52 + 37)* scale.y);
		spriteAn_2lines_17->setPosition((771 - 48 + 108)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 37)* scale.y);
		spriteAn_2lines_18->setPosition((771 - 47 + 121)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 37)* scale.y);
		spriteAn_2lines_19->setPosition((771 - 48 + 135)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 51 + 37)* scale.y);
		spriteAn_2lines_20->setPosition((771 - 46 + 148)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 50 + 37)* scale.y);
		spriteAn_2lines_21->setPosition((771 - 45 + 162)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 48 + 37)* scale.y);
		spriteAn_2lines_22->setPosition((771 - 41 + 175)* scale.x, (vec[2] * 38 + (38 * 6) - 9 - 44 + 37)* scale.y);

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

	
		spriteAn_1line_1->setPosition((771 - 51)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 2)* scale.y);
		spriteAn_1line_2->setPosition((771 - 51)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 5)* scale.y);
		spriteAn_1line_3->setPosition((771 - 51)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 7)* scale.y);
		spriteAn_1line_4->setPosition((771 - 51)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 9)* scale.y);
		spriteAn_1line_5->setPosition((771 - 50)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 11)* scale.y);
		spriteAn_1line_6->setPosition((771 - 50)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 14)* scale.y);
		spriteAn_1line_7->setPosition((771 - 49)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 16)* scale.y);
		spriteAn_1line_8->setPosition((771 - 49)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_9->setPosition((771 - 49)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_10->setPosition((771 - 48 + 13)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_11->setPosition((771 - 49 + 27)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_12->setPosition((771 - 48 + 40)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_13->setPosition((771 - 49 + 54)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_14->setPosition((771 - 48 + 67)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_15->setPosition((771 - 49 + 81)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_16->setPosition((771 - 48 + 94)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 52 + 18)* scale.y);
		spriteAn_1line_17->setPosition((771 - 48 + 108)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 18)* scale.y);
		spriteAn_1line_18->setPosition((771 - 48 + 121)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 18)* scale.y);
		spriteAn_1line_19->setPosition((771 - 48 + 135)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 51 + 18)* scale.y);
		spriteAn_1line_20->setPosition((771 - 46 + 148)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 50 + 18)* scale.y);
		spriteAn_1line_21->setPosition((771 - 45 + 162)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 48 + 18)* scale.y);
		spriteAn_1line_22->setPosition((771 - 41 + 175)* scale.x, (vec[0] * 38 + (38 * 6) - 9 - 44 + 18)* scale.y);

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

void animation_fast_falling_1InRow_1RowFn(RenderWindow& win, Sprite* An_1_inRow_1Row_1, Sprite* An_1_inRow_1Row_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
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

void animation_fast_falling_1InRow_2RowsFn(RenderWindow& win, Sprite* An_1_inRow_2Rows_1, Sprite* An_1_inRow_2Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
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

void animation_fast_falling_1InRow_3RowsFn(RenderWindow& win, Sprite* An_1_inRow_3Rows_1, Sprite* An_1_inRow_3Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
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

void animation_fast_falling_1InRow_4RowsFn(RenderWindow& win, Sprite* An_1_inRow_4Rows_1, Sprite* An_1_inRow_4Rows_2, Sprite* An_1_inRow_4Rows_3, Sprite* An_1_inRow_4Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 76) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 76) * scale.y);
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

void animation_fast_falling_1InRow_5RowsFn(RenderWindow& win, Sprite* An_1_inRow_5Rows_1, Sprite* An_1_inRow_5Rows_2, Sprite* An_1_inRow_5Rows_3, Sprite* An_1_inRow_5Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 95) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 95) * scale.y);
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

void animation_fast_falling_1InRow_6RowsFn(RenderWindow& win, Sprite* An_1_inRow_6Rows_1, Sprite* An_1_inRow_6Rows_2, Sprite* An_1_inRow_6Rows_3, Sprite* An_1_inRow_6Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 114) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 114) * scale.y);
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

void animation_fast_falling_1InRow_7RowsFn(RenderWindow& win, Sprite* An_1_inRow_7Rows_1, Sprite* An_1_inRow_7Rows_2, Sprite* An_1_inRow_7Rows_3, Sprite* An_1_inRow_7Rows_4, Sprite* An_1_inRow_7Rows_5, Sprite* An_1_inRow_7Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 ) * scale.y);
		An_1_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 89) * scale.y);
		An_1_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 177) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 89) * scale.y);
		An_1_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 177) * scale.y);
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

void animation_fast_falling_1InRow_8RowsFn(RenderWindow& win, Sprite* An_1_inRow_8Rows_1, Sprite* An_1_inRow_8Rows_2, Sprite* An_1_inRow_8Rows_3, Sprite* An_1_inRow_8Rows_4, Sprite* An_1_inRow_8Rows_5, Sprite* An_1_inRow_8Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 90) * scale.y);
		An_1_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 202) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 90) * scale.y);
		An_1_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 202) * scale.y);
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

void animation_fast_falling_1InRow_9RowsFn(RenderWindow& win, Sprite* An_1_inRow_9Rows_1, Sprite* An_1_inRow_9Rows_2, Sprite* An_1_inRow_9Rows_3, Sprite* An_1_inRow_9Rows_4, Sprite* An_1_inRow_9Rows_5, Sprite* An_1_inRow_9Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 114) * scale.y);
		An_1_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 228) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 114) * scale.y);
		An_1_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 228) * scale.y);
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

void animation_fast_falling_1InRow_10RowsFn(RenderWindow& win, Sprite* An_1_inRow_10Rows_1, Sprite* An_1_inRow_10Rows_2, Sprite* An_1_inRow_10Rows_3, Sprite* An_1_inRow_10Rows_4, Sprite* An_1_inRow_10Rows_5, Sprite* An_1_inRow_10Rows_6, Sprite* An_1_inRow_10Rows_7, Sprite* An_1_inRow_10Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 95) * scale.y);
		An_1_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 190) * scale.y);
		An_1_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 285) * scale.y);

	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 95) * scale.y);
		An_1_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 190) * scale.y);
		An_1_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 285) * scale.y);

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

void animation_fast_falling_1InRow_11RowsFn(RenderWindow& win, Sprite* An_1_inRow_11Rows_1, Sprite* An_1_inRow_11Rows_2, Sprite* An_1_inRow_11Rows_3, Sprite* An_1_inRow_11Rows_4, Sprite* An_1_inRow_11Rows_5, Sprite* An_1_inRow_11Rows_6, Sprite* An_1_inRow_11Rows_7, Sprite* An_1_inRow_11Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 104) * scale.y);
		An_1_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 209) * scale.y);
		An_1_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 313) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 104) * scale.y);
		An_1_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 209) * scale.y);
		An_1_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 313) * scale.y);
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

void animation_fast_falling_1InRow_12RowsFn(RenderWindow& win, Sprite* An_1_inRow_12Rows_1, Sprite* An_1_inRow_12Rows_2, Sprite* An_1_inRow_12Rows_3, Sprite* An_1_inRow_12Rows_4, Sprite* An_1_inRow_12Rows_5, Sprite* An_1_inRow_12Rows_6, Sprite* An_1_inRow_12Rows_7, Sprite* An_1_inRow_12Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 114) * scale.y);
		An_1_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 228) * scale.y);
		An_1_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 342) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 114) * scale.y);
		An_1_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 228) * scale.y);
		An_1_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 342) * scale.y);
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

void animation_fast_falling_1InRow_13RowsFn(RenderWindow& win, Sprite* An_1_inRow_13Rows_1, Sprite* An_1_inRow_13Rows_2, Sprite* An_1_inRow_13Rows_3, Sprite* An_1_inRow_13Rows_4, Sprite* An_1_inRow_13Rows_5, Sprite* An_1_inRow_13Rows_6, Sprite* An_1_inRow_13Rows_7, Sprite* An_1_inRow_13Rows_8, Sprite* An_1_inRow_13Rows_9, Sprite* An_1_inRow_13Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 99) * scale.y);
		An_1_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 197) * scale.y);
		An_1_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 296) * scale.y);
		An_1_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 395) * scale.y);

	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 99) * scale.y);
		An_1_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 197) * scale.y);
		An_1_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 296) * scale.y);
		An_1_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15 + 395) * scale.y);

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

void animation_fast_falling_1InRow_14RowsFn(RenderWindow& win, Sprite* An_1_inRow_14Rows_1, Sprite* An_1_inRow_14Rows_2, Sprite* An_1_inRow_14Rows_3, Sprite* An_1_inRow_14Rows_4, Sprite* An_1_inRow_14Rows_5, Sprite* An_1_inRow_14Rows_6, Sprite* An_1_inRow_14Rows_7, Sprite* An_1_inRow_14Rows_8, Sprite* An_1_inRow_14Rows_9, Sprite* An_1_inRow_14Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 106) * scale.y);
		An_1_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 213) * scale.y);
		An_1_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 319) * scale.y);
		An_1_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 426) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 106) * scale.y);
		An_1_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 213) * scale.y);
		An_1_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 319) * scale.y);
		An_1_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15 + 426) * scale.y);
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

void animation_fast_falling_1InRow_15RowsFn(RenderWindow& win, Sprite* An_1_inRow_15Rows_1, Sprite* An_1_inRow_15Rows_2, Sprite* An_1_inRow_15Rows_3, Sprite* An_1_inRow_15Rows_4, Sprite* An_1_inRow_15Rows_5, Sprite* An_1_inRow_15Rows_6, Sprite* An_1_inRow_15Rows_7, Sprite* An_1_inRow_15Rows_8, Sprite* An_1_inRow_15Rows_9, Sprite* An_1_inRow_15Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 114) * scale.y);
		An_1_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_1_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 342) * scale.y);
		An_1_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 456) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 114) * scale.y);
		An_1_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 228) * scale.y);
		An_1_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 342) * scale.y);
		An_1_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15 + 456) * scale.y);
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


void animation_fast_falling_1InRow_16RowsFn(RenderWindow& win, Sprite* An_1_inRow_16Rows_1, Sprite* An_1_inRow_16Rows_2, Sprite* An_1_inRow_16Rows_3, Sprite* An_1_inRow_16Rows_4, Sprite* An_1_inRow_16Rows_5, Sprite* An_1_inRow_16Rows_6, Sprite* An_1_inRow_16Rows_7, Sprite* An_1_inRow_16Rows_8, Sprite* An_1_inRow_16Rows_9, Sprite* An_1_inRow_16Rows_10, Sprite* An_1_inRow_16Rows_11, Sprite* An_1_inRow_16Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 87) * scale.y);
		An_1_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 174) * scale.y);
		An_1_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 260) * scale.y);
		An_1_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 347) * scale.y);
		An_1_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 434) * scale.y);
		An_1_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 101 - 38 * 18 + 521) * scale.y);

	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 87) * scale.y);
		An_1_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 174) * scale.y);
		An_1_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 260) * scale.y);
		An_1_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 347) * scale.y);
		An_1_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 434) * scale.y);
		An_1_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 101 - 38 * 15 + 521) * scale.y);

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

void animation_fast_falling_1InRow_17RowsFn(RenderWindow& win, Sprite* An_1_inRow_17Rows_1, Sprite* An_1_inRow_17Rows_2, Sprite* An_1_inRow_17Rows_3, Sprite* An_1_inRow_17Rows_4, Sprite* An_1_inRow_17Rows_5, Sprite* An_1_inRow_17Rows_6, Sprite* An_1_inRow_17Rows_7, Sprite* An_1_inRow_17Rows_8, Sprite* An_1_inRow_17Rows_9, Sprite* An_1_inRow_17Rows_10, Sprite* An_1_inRow_17Rows_11, Sprite* An_1_inRow_17Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_1_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_1_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_1_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_1_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 92) * scale.y);
		An_1_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 184) * scale.y);
		An_1_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 277) * scale.y);
		An_1_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 369) * scale.y);
		An_1_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 461) * scale.y);
		An_1_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 101 - 38 * 18 + 553) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 0 && numberOfNarrow[0] % 4 == 0)
	{
		An_1_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 15) * scale.y);
		An_1_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15) * scale.y);
		An_1_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15) * scale.y);
		An_1_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 92) * scale.y);
		An_1_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 184) * scale.y);
		An_1_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 15 + 277) * scale.y);
		An_1_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 369) * scale.y);
		An_1_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 15 + 461) * scale.y);
		An_1_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 101 - 38 * 15 + 553) * scale.y);
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


void animation_fast_falling_2InRow_1RowFn(RenderWindow& win, Sprite* An_2_inRow_1Row_1, Sprite* An_2_inRow_1Row_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
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

void animation_fast_falling_2InRow_2RowsFn(RenderWindow& win, Sprite* An_2_inRow_2Rows_1, Sprite* An_2_inRow_2Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
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

void animation_fast_falling_2InRow_3RowsFn(RenderWindow& win, Sprite* An_2_inRow_3Rows_1, Sprite* An_2_inRow_3Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
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

void animation_fast_falling_2InRow_4RowsFn(RenderWindow& win, Sprite* An_2_inRow_4Rows_1, Sprite* An_2_inRow_4Rows_2, Sprite* An_2_inRow_4Rows_3, Sprite* An_2_inRow_4Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 76) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 76) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 76) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 76) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 76) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 76) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 76) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 76) * scale.y);
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

void animation_fast_falling_2InRow_5RowsFn(RenderWindow& win, Sprite* An_2_inRow_5Rows_1, Sprite* An_2_inRow_5Rows_2, Sprite* An_2_inRow_5Rows_3, Sprite* An_2_inRow_5Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 95) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
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

void animation_fast_falling_2InRow_6RowsFn(RenderWindow& win, Sprite* An_2_inRow_6Rows_1, Sprite* An_2_inRow_6Rows_2, Sprite* An_2_inRow_6Rows_3, Sprite* An_2_inRow_6Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 114) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
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


void animation_fast_falling_2InRow_7RowsFn(RenderWindow& win, Sprite* An_2_inRow_7Rows_1, Sprite* An_2_inRow_7Rows_2, Sprite* An_2_inRow_7Rows_3, Sprite* An_2_inRow_7Rows_4, Sprite* An_2_inRow_7Rows_5, Sprite* An_2_inRow_7Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 ) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 177) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 ) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 177) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 177) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 177) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 177) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 177) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 177) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 177) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 177) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 89) * scale.y);
		An_2_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 177) * scale.y);
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

void animation_fast_falling_2InRow_8RowsFn(RenderWindow& win, Sprite* An_2_inRow_8Rows_1, Sprite* An_2_inRow_8Rows_2, Sprite* An_2_inRow_8Rows_3, Sprite* An_2_inRow_8Rows_4, Sprite* An_2_inRow_8Rows_5, Sprite* An_2_inRow_8Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{

		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 202) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 202) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 202) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 202) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 202) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 202) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 202) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 202) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 202) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 202) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 101) * scale.y);
		An_2_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 202) * scale.y);
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

void animation_fast_falling_2InRow_9RowsFn(RenderWindow& win, Sprite* An_2_inRow_9Rows_1, Sprite* An_2_inRow_9Rows_2, Sprite* An_2_inRow_9Rows_3, Sprite* An_2_inRow_9Rows_4, Sprite* An_2_inRow_9Rows_5, Sprite* An_2_inRow_9Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 228) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 228) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 228) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 228) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 228) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 228) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
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

void animation_fast_falling_2InRow_10RowsFn(RenderWindow& win, Sprite* An_2_inRow_10Rows_1, Sprite* An_2_inRow_10Rows_2, Sprite* An_2_inRow_10Rows_3, Sprite* An_2_inRow_10Rows_4, Sprite* An_2_inRow_10Rows_5, Sprite* An_2_inRow_10Rows_6, Sprite* An_2_inRow_10Rows_7, Sprite* An_2_inRow_10Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 285) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 285) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 285) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 285) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 285) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 285) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 285) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 285) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 285) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 95)* scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
		An_2_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 190) * scale.y);
		An_2_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 285) * scale.y);
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

void animation_fast_falling_2InRow_11RowsFn(RenderWindow& win, Sprite* An_2_inRow_11Rows_1, Sprite* An_2_inRow_11Rows_2, Sprite* An_2_inRow_11Rows_3, Sprite* An_2_inRow_11Rows_4, Sprite* An_2_inRow_11Rows_5, Sprite* An_2_inRow_11Rows_6, Sprite* An_2_inRow_11Rows_7, Sprite* An_2_inRow_11Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 313) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 313) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 313) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 313) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 313) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 313) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 313) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 313) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 313) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 104) * scale.y);
		An_2_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 209) * scale.y);
		An_2_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 313) * scale.y);
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

void animation_fast_falling_2InRow_12RowsFn(RenderWindow& win, Sprite* An_2_inRow_12Rows_1, Sprite* An_2_inRow_12Rows_2, Sprite* An_2_inRow_12Rows_3, Sprite* An_2_inRow_12Rows_4, Sprite* An_2_inRow_12Rows_5, Sprite* An_2_inRow_12Rows_6, Sprite* An_2_inRow_12Rows_7, Sprite* An_2_inRow_12Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 342) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 342) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 342) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 342) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 342) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 342) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 228) * scale.y);
		An_2_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
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

void animation_fast_falling_2InRow_13RowsFn(RenderWindow& win, Sprite* An_2_inRow_13Rows_1, Sprite* An_2_inRow_13Rows_2, Sprite* An_2_inRow_13Rows_3, Sprite* An_2_inRow_13Rows_4, Sprite* An_2_inRow_13Rows_5, Sprite* An_2_inRow_13Rows_6, Sprite* An_2_inRow_13Rows_7, Sprite* An_2_inRow_13Rows_8, Sprite* An_2_inRow_13Rows_9, Sprite* An_2_inRow_13Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 395) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 395) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 395) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 395) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 395) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 395) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 296) * scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18 + 395) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197)* scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 296)* scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18 + 395) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 197)* scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 296)* scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16 + 395) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 197)* scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 296)* scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 99) * scale.y);
		An_2_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 197)* scale.y);
		An_2_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 296)* scale.y);
		An_2_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 395) * scale.y);
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

void animation_fast_falling_2InRow_14RowsFn(RenderWindow& win, Sprite* An_2_inRow_14Rows_1, Sprite* An_2_inRow_14Rows_2, Sprite* An_2_inRow_14Rows_3, Sprite* An_2_inRow_14Rows_4, Sprite* An_2_inRow_14Rows_5, Sprite* An_2_inRow_14Rows_6, Sprite* An_2_inRow_14Rows_7, Sprite* An_2_inRow_14Rows_8, Sprite* An_2_inRow_14Rows_9, Sprite* An_2_inRow_14Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 425) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 425) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 425) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 425) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 425) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 425) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18 + 425) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18 + 425) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16 + 425) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 106) * scale.y);
		An_2_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 213) * scale.y);
		An_2_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 319) * scale.y);
		An_2_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 425) * scale.y);
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

void animation_fast_falling_2InRow_15RowsFn(RenderWindow& win, Sprite* An_2_inRow_15Rows_1, Sprite* An_2_inRow_15Rows_2, Sprite* An_2_inRow_15Rows_3, Sprite* An_2_inRow_15Rows_4, Sprite* An_2_inRow_15Rows_5, Sprite* An_2_inRow_15Rows_6, Sprite* An_2_inRow_15Rows_7, Sprite* An_2_inRow_15Rows_8, Sprite* An_2_inRow_15Rows_9, Sprite* An_2_inRow_15Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 456) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 456) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 456) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 456) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 456) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19 + 456) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18 + 456) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18 + 456) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16 + 456) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_2_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 228) * scale.y);
		An_2_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 342) * scale.y);
		An_2_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17 + 456) * scale.y);
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

void animation_fast_falling_2InRow_16RowsFn(RenderWindow& win, Sprite* An_2_inRow_16Rows_1, Sprite* An_2_inRow_16Rows_2, Sprite* An_2_inRow_16Rows_3, Sprite* An_2_inRow_16Rows_4, Sprite* An_2_inRow_16Rows_5, Sprite* An_2_inRow_16Rows_6, Sprite* An_2_inRow_16Rows_7, Sprite* An_2_inRow_16Rows_8, Sprite* An_2_inRow_16Rows_9, Sprite* An_2_inRow_16Rows_10, Sprite* An_2_inRow_16Rows_11, Sprite* An_2_inRow_16Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 348) * scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 435) * scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 19 + 522) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 1 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 348) * scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 435) * scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 17 + 522) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 348) * scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 435) * scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 19 + 522) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 2 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 348) * scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 435) * scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 17 + 522) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 348) * scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 435) * scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 17 + 522) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 348) * scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 435) * scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 19 + 522) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 348)* scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 435)* scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 18 + 522) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 348)* scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 435)* scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 18 + 522) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 348)* scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 435)* scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 16 + 522) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 348)* scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 435)* scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 20 + 522) * scale.y);
	}

	else if (typeOfTetramino1 == 6)
	{
		An_2_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 87) * scale.y);
		An_2_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 174) * scale.y);
		An_2_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 261) * scale.y);
		An_2_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 348)* scale.y);
		An_2_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2)* scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 435)* scale.y);
		An_2_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 17 + 522) * scale.y);
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

void animation_fast_falling_2InRow_17RowsFn(RenderWindow& win, Sprite* An_2_inRow_17Rows_1, Sprite* An_2_inRow_17Rows_2, Sprite* An_2_inRow_17Rows_3, Sprite* An_2_inRow_17Rows_4, Sprite* An_2_inRow_17Rows_5, Sprite* An_2_inRow_17Rows_6, Sprite* An_2_inRow_17Rows_7, Sprite* An_2_inRow_17Rows_8, Sprite* An_2_inRow_17Rows_9, Sprite* An_2_inRow_17Rows_10, Sprite* An_2_inRow_17Rows_11, Sprite* An_2_inRow_17Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219

	if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 17) * scale.y);
		An_2_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17) * scale.y);
		An_2_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_2_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 92) * scale.y);
		An_2_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 184) * scale.y);
		An_2_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 277) * scale.y);
		An_2_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 369) * scale.y);
		An_2_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 17 + 461) * scale.y);
		An_2_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 17 + 553) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 3 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 19) * scale.y);
		An_2_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19) * scale.y);
		An_2_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_2_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 92) * scale.y);
		An_2_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 184) * scale.y);
		An_2_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 277) * scale.y);
		An_2_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 369) * scale.y);
		An_2_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 19 + 461) * scale.y);
		An_2_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 19 + 553) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_2_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_2_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_2_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 369) * scale.y);
		An_2_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 461) * scale.y);
		An_2_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 18 + 553) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 4 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_2_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_2_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_2_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_2_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 369) * scale.y);
		An_2_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 18 + 461) * scale.y);
		An_2_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 18 + 553) * scale.y);
	}

	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && (numberOfNarrow[0] % 4 == 2 || numberOfNarrow[0] % 4 == -2))
	{
		An_2_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 16) * scale.y);
		An_2_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16) * scale.y);
		An_2_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16) * scale.y);
		An_2_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 92) * scale.y);
		An_2_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 184) * scale.y);
		An_2_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 16 + 277) * scale.y);
		An_2_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 369) * scale.y);
		An_2_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 16 + 461) * scale.y);
		An_2_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38 * 2) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 16 + 553) * scale.y);
	}
	else if ((numberOfWide[0] % 2 == 1 || numberOfWide[0] % 2 == -1) && typeOfTetramino1 == 5 && numberOfNarrow[0] % 4 == 0)
	{
		An_2_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 104 - 38 * 20) * scale.y);
		An_2_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20) * scale.y);
		An_2_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20) * scale.y);
		An_2_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 92) * scale.y);
		An_2_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 184) * scale.y);
		An_2_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 20 + 277) * scale.y);
		An_2_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 369) * scale.y);
		An_2_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 106 - 38 * 20 + 461) * scale.y);
		An_2_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 102 - 38) * scale.x, (a[0].y * 38 + 941 - 102 - 38 * 20 + 553) * scale.y);
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

void animation_fast_falling_3InRow_1RowFn(RenderWindow& win, Sprite* An_3_inRow_1Row_1, Sprite* An_3_inRow_1Row_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
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

void animation_fast_falling_3InRow_2RowsFn(RenderWindow& win, Sprite* An_3_inRow_2Rows_1, Sprite* An_3_inRow_2Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
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

void animation_fast_falling_3InRow_3RowsFn(RenderWindow& win, Sprite* An_3_inRow_3Rows_1, Sprite* An_3_inRow_3Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
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

void animation_fast_falling_3InRow_4RowsFn(RenderWindow& win, Sprite* An_3_inRow_4Rows_1, Sprite* An_3_inRow_4Rows_2, Sprite* An_3_inRow_4Rows_3, Sprite* An_3_inRow_4Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 76) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
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

void animation_fast_falling_3InRow_5RowsFn(RenderWindow& win, Sprite* An_3_inRow_5Rows_1, Sprite* An_3_inRow_5Rows_2, Sprite* An_3_inRow_5Rows_3, Sprite* An_3_inRow_5Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
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

void animation_fast_falling_3InRow_6RowsFn(RenderWindow& win, Sprite* An_3_inRow_6Rows_1, Sprite* An_3_inRow_6Rows_2, Sprite* An_3_inRow_6Rows_3, Sprite* An_3_inRow_6Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
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

void animation_fast_falling_3InRow_7RowsFn(RenderWindow& win, Sprite* An_3_inRow_7Rows_1, Sprite* An_3_inRow_7Rows_2, Sprite* An_3_inRow_7Rows_3, Sprite* An_3_inRow_7Rows_4, Sprite* An_3_inRow_7Rows_5, Sprite* An_3_inRow_7Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 ) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 ) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 177) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_3_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 177) * scale.y);
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

void animation_fast_falling_3InRow_8RowsFn(RenderWindow& win, Sprite* An_3_inRow_8Rows_1, Sprite* An_3_inRow_8Rows_2, Sprite* An_3_inRow_8Rows_3, Sprite* An_3_inRow_8Rows_4, Sprite* An_3_inRow_8Rows_5, Sprite* An_3_inRow_8Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;


	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 203) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 102) * scale.y);
		An_3_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 203) * scale.y);
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

void animation_fast_falling_3InRow_9RowsFn(RenderWindow& win, Sprite* An_3_inRow_9Rows_1, Sprite* An_3_inRow_9Rows_2, Sprite* An_3_inRow_9Rows_3, Sprite* An_3_inRow_9Rows_4, Sprite* An_3_inRow_9Rows_5, Sprite* An_3_inRow_9Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 228) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
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

void animation_fast_falling_3InRow_10RowsFn(RenderWindow& win, Sprite* An_3_inRow_10Rows_1, Sprite* An_3_inRow_10Rows_2, Sprite* An_3_inRow_10Rows_3, Sprite* An_3_inRow_10Rows_4, Sprite* An_3_inRow_10Rows_5, Sprite* An_3_inRow_10Rows_6, Sprite* An_3_inRow_10Rows_7, Sprite* An_3_inRow_10Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 ) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95) * scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 190) * scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 95)* scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 190)* scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 285) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95)* scale.y);
		An_3_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190)* scale.y);
		An_3_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
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

void animation_fast_falling_3InRow_11RowsFn(RenderWindow& win, Sprite* An_3_inRow_11Rows_1, Sprite* An_3_inRow_11Rows_2, Sprite* An_3_inRow_11Rows_3, Sprite* An_3_inRow_11Rows_4, Sprite* An_3_inRow_11Rows_5, Sprite* An_3_inRow_11Rows_6, Sprite* An_3_inRow_11Rows_7, Sprite* An_3_inRow_11Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 313) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_3_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_3_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
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

void animation_fast_falling_3InRow_12RowsFn(RenderWindow& win, Sprite* An_3_inRow_12Rows_1, Sprite* An_3_inRow_12Rows_2, Sprite* An_3_inRow_12Rows_3, Sprite* An_3_inRow_12Rows_4, Sprite* An_3_inRow_12Rows_5, Sprite* An_3_inRow_12Rows_6, Sprite* An_3_inRow_12Rows_7, Sprite* An_3_inRow_12Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 342) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_3_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
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

void animation_fast_falling_3InRow_13RowsFn(RenderWindow& win, Sprite* An_3_inRow_13Rows_1, Sprite* An_3_inRow_13Rows_2, Sprite* An_3_inRow_13Rows_3, Sprite* An_3_inRow_13Rows_4, Sprite* An_3_inRow_13Rows_5, Sprite* An_3_inRow_13Rows_6, Sprite* An_3_inRow_13Rows_7, Sprite* An_3_inRow_13Rows_8, Sprite* An_3_inRow_13Rows_9, Sprite* An_3_inRow_13Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 ) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 197) * scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 296) * scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 197)* scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3)* scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 296)* scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 395) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_3_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197)* scale.y);
		An_3_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296)* scale.y);
		An_3_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
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

void animation_fast_falling_3InRow_14RowsFn(RenderWindow& win, Sprite* An_3_inRow_14Rows_1, Sprite* An_3_inRow_14Rows_2, Sprite* An_3_inRow_14Rows_3, Sprite* An_3_inRow_14Rows_4, Sprite* An_3_inRow_14Rows_5, Sprite* An_3_inRow_14Rows_6, Sprite* An_3_inRow_14Rows_7, Sprite* An_3_inRow_14Rows_8, Sprite* An_3_inRow_14Rows_9, Sprite* An_3_inRow_14Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 425) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_3_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_3_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_3_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
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

void animation_fast_falling_3InRow_15RowsFn(RenderWindow& win, Sprite* An_3_inRow_15Rows_1, Sprite* An_3_inRow_15Rows_2, Sprite* An_3_inRow_15Rows_3, Sprite* An_3_inRow_15Rows_4, Sprite* An_3_inRow_15Rows_5, Sprite* An_3_inRow_15Rows_6, Sprite* An_3_inRow_15Rows_7, Sprite* An_3_inRow_15Rows_8, Sprite* An_3_inRow_15Rows_9, Sprite* An_3_inRow_15Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 456) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_3_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_3_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_3_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
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

void animation_fast_falling_3InRow_16RowsFn(RenderWindow& win, Sprite* An_3_inRow_16Rows_1, Sprite* An_3_inRow_16Rows_2, Sprite* An_3_inRow_16Rows_3, Sprite* An_3_inRow_16Rows_4, Sprite* An_3_inRow_16Rows_5, Sprite* An_3_inRow_16Rows_6, Sprite* An_3_inRow_16Rows_7, Sprite* An_3_inRow_16Rows_8, Sprite* An_3_inRow_16Rows_9, Sprite* An_3_inRow_16Rows_10, Sprite* An_3_inRow_16Rows_11, Sprite* An_3_inRow_16Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 303) * scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 404) * scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 303) * scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 404) * scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 303) * scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 404) * scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 303) * scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 404) * scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 303) * scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 404) * scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 303) * scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 404) * scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 303)* scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3)* scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 404)* scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 303)* scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 404)* scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 303)* scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3)* scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 404)* scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19 + 505) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_3_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 202) * scale.y);
		An_3_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 108 - 38)* scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 303)* scale.y);
		An_3_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38)* scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 404)* scale.y);
		An_3_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 505) * scale.y);
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

void animation_fast_falling_3InRow_17RowsFn(RenderWindow& win, Sprite* An_3_inRow_17Rows_1, Sprite* An_3_inRow_17Rows_2, Sprite* An_3_inRow_17Rows_3, Sprite* An_3_inRow_17Rows_4, Sprite* An_3_inRow_17Rows_5, Sprite* An_3_inRow_17Rows_6, Sprite* An_3_inRow_17Rows_7, Sprite* An_3_inRow_17Rows_8, Sprite* An_3_inRow_17Rows_9, Sprite* An_3_inRow_17Rows_10, Sprite* An_3_inRow_17Rows_11, Sprite* An_3_inRow_17Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 17 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 92) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19 + 553) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 91) * scale.y);
		An_3_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_3_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 277) * scale.y);
		An_3_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_3_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_3_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
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

void animation_fast_falling_3InRow_18RowsFn(RenderWindow& win, Sprite* An_3_inRow_18Rows_1, Sprite* An_3_inRow_18Rows_2, Sprite* An_3_inRow_18Rows_3, Sprite* An_3_inRow_18Rows_4, Sprite* An_3_inRow_18Rows_5, Sprite* An_3_inRow_18Rows_6, Sprite* An_3_inRow_18Rows_7, Sprite* An_3_inRow_18Rows_8, Sprite* An_3_inRow_18Rows_9, Sprite* An_3_inRow_18Rows_10, Sprite* An_3_inRow_18Rows_11, Sprite* An_3_inRow_18Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;

	if (typeOfTetramino1 == 4 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 4 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 17) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 17 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 17 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 17 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 5 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 3 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 1 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && numberOfWide[0] % 4 == 0)
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 19 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 19 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 3) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 19 + 586) * scale.y);
	}

	else if (typeOfTetramino1 == 2 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_3_inRow_18Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_3_inRow_18Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 98) * scale.y);
		An_3_inRow_18Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 195) * scale.y);
		An_3_inRow_18Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 293) * scale.y);
		An_3_inRow_18Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 391) * scale.y);
		An_3_inRow_18Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 488) * scale.y);
		An_3_inRow_18Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 586) * scale.y);
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

void animation_fast_falling_4InRow_1RowFn(RenderWindow& win, Sprite* An_4_inRow_1Row_1, Sprite* An_4_inRow_1Row_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_1Row_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_1Row_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
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

void animation_fast_falling_4InRow_2RowsFn(RenderWindow& win, Sprite* An_4_inRow_2Rows_1, Sprite* An_4_inRow_2Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_2Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_2Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
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

void animation_fast_falling_4InRow_3RowsFn(RenderWindow& win, Sprite* An_4_inRow_3Rows_1, Sprite* An_4_inRow_3Rows_2, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_3Rows_1->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_3Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
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

void animation_fast_falling_4InRow_4RowsFn(RenderWindow& win, Sprite* An_4_inRow_4Rows_1, Sprite* An_4_inRow_4Rows_2, Sprite* An_4_inRow_4Rows_3, Sprite* An_4_inRow_4Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_4Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_4Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_4Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_4Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 76) * scale.y);
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

void animation_fast_falling_4InRow_5RowsFn(RenderWindow& win, Sprite* An_4_inRow_5Rows_1, Sprite* An_4_inRow_5Rows_2, Sprite* An_4_inRow_5Rows_3, Sprite* An_4_inRow_5Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_5Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_5Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_5Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_5Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
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

void animation_fast_falling_4InRow_6RowsFn(RenderWindow& win, Sprite* An_4_inRow_6Rows_1, Sprite* An_4_inRow_6Rows_2, Sprite* An_4_inRow_6Rows_3, Sprite* An_4_inRow_6Rows_4, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_6Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_6Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_6Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_6Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
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

void animation_fast_falling_4InRow_7RowsFn(RenderWindow& win, Sprite* An_4_inRow_7Rows_1, Sprite* An_4_inRow_7Rows_2, Sprite* An_4_inRow_7Rows_3, Sprite* An_4_inRow_7Rows_4, Sprite* An_4_inRow_7Rows_5, Sprite* An_4_inRow_7Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_4_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 177) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_7Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_7Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 89) * scale.y);
		An_4_inRow_7Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 177) * scale.y);
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

void animation_fast_falling_4InRow_8RowsFn(RenderWindow& win, Sprite* An_4_inRow_8Rows_1, Sprite* An_4_inRow_8Rows_2, Sprite* An_4_inRow_8Rows_3, Sprite* An_4_inRow_8Rows_4, Sprite* An_4_inRow_8Rows_5, Sprite* An_4_inRow_8Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_4_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 202) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_8Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_8Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 101) * scale.y);
		An_4_inRow_8Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 202) * scale.y);
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

void animation_fast_falling_4InRow_9RowsFn(RenderWindow& win, Sprite* An_4_inRow_9Rows_1, Sprite* An_4_inRow_9Rows_2, Sprite* An_4_inRow_9Rows_3, Sprite* An_4_inRow_9Rows_4, Sprite* An_4_inRow_9Rows_5, Sprite* An_4_inRow_9Rows_6, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_4_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_9Rows_1->setPosition((a[0].x * 38 + 960 - 106 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_2->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_9Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_4_inRow_9Rows_6->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
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

void animation_fast_falling_4InRow_10RowsFn(RenderWindow& win, Sprite* An_4_inRow_10Rows_1, Sprite* An_4_inRow_10Rows_2, Sprite* An_4_inRow_10Rows_3, Sprite* An_4_inRow_10Rows_4, Sprite* An_4_inRow_10Rows_5, Sprite* An_4_inRow_10Rows_6, Sprite* An_4_inRow_10Rows_7, Sprite* An_4_inRow_10Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_4_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_4_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_10Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_10Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 95) * scale.y);
		An_4_inRow_10Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 190) * scale.y);
		An_4_inRow_10Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 285) * scale.y);
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

void animation_fast_falling_4InRow_11RowsFn(RenderWindow& win, Sprite* An_4_inRow_11Rows_1, Sprite* An_4_inRow_11Rows_2, Sprite* An_4_inRow_11Rows_3, Sprite* An_4_inRow_11Rows_4, Sprite* An_4_inRow_11Rows_5, Sprite* An_4_inRow_11Rows_6, Sprite* An_4_inRow_11Rows_7, Sprite* An_4_inRow_11Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_4_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_4_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_11Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_11Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 104) * scale.y);
		An_4_inRow_11Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 209) * scale.y);
		An_4_inRow_11Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 313) * scale.y);
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

void animation_fast_falling_4InRow_12RowsFn(RenderWindow& win, Sprite* An_4_inRow_12Rows_1, Sprite* An_4_inRow_12Rows_2, Sprite* An_4_inRow_12Rows_3, Sprite* An_4_inRow_12Rows_4, Sprite* An_4_inRow_12Rows_5, Sprite* An_4_inRow_12Rows_6, Sprite* An_4_inRow_12Rows_7, Sprite* An_4_inRow_12Rows_8, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_4_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_4_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_12Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_12Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_4_inRow_12Rows_7->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 228) * scale.y);
		An_4_inRow_12Rows_8->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
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

void animation_fast_falling_4InRow_13RowsFn(RenderWindow& win, Sprite* An_4_inRow_13Rows_1, Sprite* An_4_inRow_13Rows_2, Sprite* An_4_inRow_13Rows_3, Sprite* An_4_inRow_13Rows_4, Sprite* An_4_inRow_13Rows_5, Sprite* An_4_inRow_13Rows_6, Sprite* An_4_inRow_13Rows_7, Sprite* An_4_inRow_13Rows_8, Sprite* An_4_inRow_13Rows_9, Sprite* An_4_inRow_13Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_4_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_4_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_4_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_13Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_13Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 99) * scale.y);
		An_4_inRow_13Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 197) * scale.y);
		An_4_inRow_13Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 296) * scale.y);
		An_4_inRow_13Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 395) * scale.y);
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

void animation_fast_falling_4InRow_14RowsFn(RenderWindow& win, Sprite* An_4_inRow_14Rows_1, Sprite* An_4_inRow_14Rows_2, Sprite* An_4_inRow_14Rows_3, Sprite* An_4_inRow_14Rows_4, Sprite* An_4_inRow_14Rows_5, Sprite* An_4_inRow_14Rows_6, Sprite* An_4_inRow_14Rows_7, Sprite* An_4_inRow_14Rows_8, Sprite* An_4_inRow_14Rows_9, Sprite* An_4_inRow_14Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_4_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_4_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_4_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_14Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_14Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 106) * scale.y);
		An_4_inRow_14Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 213) * scale.y);
		An_4_inRow_14Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 319) * scale.y);
		An_4_inRow_14Rows_10->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 425) * scale.y);
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

void animation_fast_falling_4InRow_15RowsFn(RenderWindow& win, Sprite* An_4_inRow_15Rows_1, Sprite* An_4_inRow_15Rows_2, Sprite* An_4_inRow_15Rows_3, Sprite* An_4_inRow_15Rows_4, Sprite* An_4_inRow_15Rows_5, Sprite* An_4_inRow_15Rows_6, Sprite* An_4_inRow_15Rows_7, Sprite* An_4_inRow_15Rows_8, Sprite* An_4_inRow_15Rows_9, Sprite* An_4_inRow_15Rows_10, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_4_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_4_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_4_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_15Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_15Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 114) * scale.y);
		An_4_inRow_15Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 228) * scale.y);
		An_4_inRow_15Rows_9->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 342) * scale.y);
		An_4_inRow_15Rows_10->setPosition((a[0].x * 38 + 960 - 105 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18 + 456) * scale.y);
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

void animation_fast_falling_4InRow_16RowsFn(RenderWindow& win, Sprite* An_4_inRow_16Rows_1, Sprite* An_4_inRow_16Rows_2, Sprite* An_4_inRow_16Rows_3, Sprite* An_4_inRow_16Rows_4, Sprite* An_4_inRow_16Rows_5, Sprite* An_4_inRow_16Rows_6, Sprite* An_4_inRow_16Rows_7, Sprite* An_4_inRow_16Rows_8, Sprite* An_4_inRow_16Rows_9, Sprite* An_4_inRow_16Rows_10, Sprite* An_4_inRow_16Rows_11, Sprite* An_4_inRow_16Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 87) * scale.y);
		An_4_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 174) * scale.y);
		An_4_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 260) * scale.y);
		An_4_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 347) * scale.y);
		An_4_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 434) * scale.y);
		An_4_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 521) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_16Rows_1->setPosition((a[0].x * 38 + 960 - 104 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_16Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 87) * scale.y);
		An_4_inRow_16Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 174) * scale.y);
		An_4_inRow_16Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 260) * scale.y);
		An_4_inRow_16Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 347) * scale.y);
		An_4_inRow_16Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 434) * scale.y);
		An_4_inRow_16Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 521) * scale.y);
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

void animation_fast_falling_4InRow_17RowsFn(RenderWindow& win, Sprite* An_4_inRow_17Rows_1, Sprite* An_4_inRow_17Rows_2, Sprite* An_4_inRow_17Rows_3, Sprite* An_4_inRow_17Rows_4, Sprite* An_4_inRow_17Rows_5, Sprite* An_4_inRow_17Rows_6, Sprite* An_4_inRow_17Rows_7, Sprite* An_4_inRow_17Rows_8, Sprite* An_4_inRow_17Rows_9, Sprite* An_4_inRow_17Rows_10, Sprite* An_4_inRow_17Rows_11, Sprite* An_4_inRow_17Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_4_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_4_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 276) * scale.y);
		An_4_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_4_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_4_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_17Rows_1->setPosition((a[0].x * 38 + 960 - 105 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 105 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_2->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_3->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_4->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_5->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_6->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18) * scale.y);
		An_4_inRow_17Rows_7->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 92) * scale.y);
		An_4_inRow_17Rows_8->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 184) * scale.y);
		An_4_inRow_17Rows_9->setPosition((a[0].x * 38 + 960 - 108 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 108 - 38 * 18 + 276) * scale.y);
		An_4_inRow_17Rows_10->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 369) * scale.y);
		An_4_inRow_17Rows_11->setPosition((a[0].x * 38 + 960 - 107 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 107 - 38 * 18 + 461) * scale.y);
		An_4_inRow_17Rows_12->setPosition((a[0].x * 38 + 960 - 103 - 38 * 4) * scale.x, (a[0].y * 38 + 941 - 103 - 38 * 18 + 553) * scale.y);
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


void animation_fast_falling_4InRow_18RowsFn(RenderWindow& win, Sprite* An_4_inRow_18Rows_1, Sprite* An_4_inRow_18Rows_2, Sprite* An_4_inRow_18Rows_3, Sprite* An_4_inRow_18Rows_4, Sprite* An_4_inRow_18Rows_5, Sprite* An_4_inRow_18Rows_6, Sprite* An_4_inRow_18Rows_7, Sprite* An_4_inRow_18Rows_8, Sprite* An_4_inRow_18Rows_9, Sprite* An_4_inRow_18Rows_10, Sprite* An_4_inRow_18Rows_11, Sprite* An_4_inRow_18Rows_12, Vector2f scale)
{
	if (!progressOfAnimationFF) animation_fast_falling_clock.restart();
	progressOfAnimationFF = true;
	//a[i].x * 38 + 922, a[i].y * 38 + 219
	if (typeOfTetramino1 == 0 && (numberOfWide[0] % 4 == 2 || numberOfWide[0] % 4 == -2))
	{
		An_4_inRow_18Rows_1->setPosition((a[0].x * 38 + 884 - 105 + 38) * scale.x, (a[0].y * 38 + 257 - 105) * scale.y);
		An_4_inRow_18Rows_2->setPosition((a[0].x * 38 + 884 - 107 + 38) * scale.x, (a[0].y * 38 + 257 - 107) * scale.y);
		An_4_inRow_18Rows_3->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_4->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_5->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_6->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_7->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108 + 98) * scale.y);
		An_4_inRow_18Rows_8->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108 + 195) * scale.y);
		An_4_inRow_18Rows_9->setPosition((a[0].x * 38 + 884 - 108 + 38) * scale.x, (a[0].y * 38 + 257 - 108 + 293) * scale.y);
		An_4_inRow_18Rows_10->setPosition((a[0].x * 38 + 884 - 107 + 38) * scale.x, (a[0].y * 38 + 257 - 107 + 391) * scale.y);
		An_4_inRow_18Rows_11->setPosition((a[0].x * 38 + 884 - 107 + 38) * scale.x, (a[0].y * 38 + 257 - 107 + 488) * scale.y);
		An_4_inRow_18Rows_12->setPosition((a[0].x * 38 + 884 - 103 + 38) * scale.x, (a[0].y * 38 + 257 - 103 + 585) * scale.y);
	}
	else if (typeOfTetramino1 == 0 && numberOfWide[0] % 4 == 0)
	{
		An_4_inRow_18Rows_1->setPosition((a[0].x * 38 + 884 - 105 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 105) * scale.y);
		An_4_inRow_18Rows_2->setPosition((a[0].x * 38 + 884 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 107) * scale.y);
		An_4_inRow_18Rows_3->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_4->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_5->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_6->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108) * scale.y);
		An_4_inRow_18Rows_7->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108 + 98) * scale.y);
		An_4_inRow_18Rows_8->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108 + 195) * scale.y);
		An_4_inRow_18Rows_9->setPosition((a[0].x * 38 + 884 - 108 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 108 + 293) * scale.y);
		An_4_inRow_18Rows_10->setPosition((a[0].x * 38 + 884 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 107 + 391) * scale.y);
		An_4_inRow_18Rows_11->setPosition((a[0].x * 38 + 884 - 107 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 107 + 488) * scale.y);
		An_4_inRow_18Rows_12->setPosition((a[0].x * 38 + 884 - 103 - 38 * 2) * scale.x, (a[0].y * 38 + 257 - 103 + 585) * scale.y);
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


void fill_tetramino()
{
	// задаём тип тетрамино
	beginGame = false;
	typeOfTetramino1 = rand() % 7;
	//typeOfTetramino1 = 0;
	//typeOfTetramino2 = 0;
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
			if (i == (19 - indexOfLastLine + indexOfLastLine))break;//ЧТО БЛЯ?
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