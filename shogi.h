#ifndef SHOGI_H
#define SHOGI_H

#include "macros01.h"

// 盤面型で使われる長さ
#define BRD_LEN 111

// 持ち駒配列の長さ
#define HOLD_LEN 16

// 辺の長さ
#define SIDE_LEN 9

// 駒の文字
#define PIECES_CHAR " PLNSGBRK"

// 駒を列挙型で定義してみた
enum PIECES {EMPTY, PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, SENTINEL=0xff};

// 駒に付加されるフラグ
// 5ビット目: 手番フラグ, 6ビット目: 成フラグ
enum FLAGS {TURN = 0b10000, PROMOTED = 0b100000};

// 盤面型
// 番兵を含む111要素の符号なし文字型配列
// 各種持ち駒と手番フラグの和 (論理和) を添字として, 持ち駒の数を保持する
// 添字 0 と 8 は使わない?
typedef struct board {
    u_char brd[BRD_LEN];
    u_char hold[HOLD_LEN];
} Board;

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b);

// 盤面の駒をアルファベットで表示したい
void showBoard(Board b);

void resetBoard(Board *bp);

#endif