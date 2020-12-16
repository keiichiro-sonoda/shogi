#ifndef SHOGI_H
#define SHOGI_H

#include "macros01.h"

// 駒を列挙型で定義してみた
enum PIECES {EMPTY, PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, SENTINEL=0xff};

typedef struct board {
    u_char brd[111];
} Board;

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b);

void resetBoard(Board *bp);

#endif