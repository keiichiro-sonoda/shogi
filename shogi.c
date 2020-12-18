#include "shogi.h"

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b) {
    for (int i = 0; i < SIDE_LEN; i++) {
        for (int j = 0; j < SIDE_LEN; j++) {
            printByteHex(b.brd[i * 10 + j + 11]);
            putchar(' ');
        }
        putchar(10);
    }
}

// 盤面初期化
void resetBoard(Board *bp) {
    for (int i = 0; i < BRD_LEN; i++) {
        if (i < 10 || i % 10 == 0 || 100 < i) {
            bp->brd[i] = SENTINEL;
        } else {
            bp->brd[i] = PAWN;
        }
    }
}