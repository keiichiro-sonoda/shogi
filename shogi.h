#ifndef SHOGI_H
#define SHOGI_H

#include "macros01.h"

// 駒を列挙型で定義してみた
enum PIECES {EMPTY, PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, SENTINEL};

typedef struct board {
    u_char b[111];
} Board;

#endif