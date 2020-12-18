#ifndef SHOGI_H
#define SHOGI_H

#include "macros01.h"

// 盤面型で使われる長さ
#define BRD_LEN 111

// 辺の長さ
#define SIDE_LEN 9

// 駒を列挙型で定義してみた
enum PIECES {EMPTY, PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, SENTINEL=0xff};

// 駒に付加されるフラグ
// 5ビット目: 成フラグ, 6ビット目: 手番フラグ
enum FLAGS {PROMOTED = 0b10000, TURN = 0b100000};

// 盤面型
// 番兵を含む111要素の符号なし文字型配列
typedef struct board {
    u_char brd[BRD_LEN];
} Board;

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b);

void resetBoard(Board *bp);

#endif