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
        }
        else {
            bp->brd[i] = EMPTY;
        }
    }
    for (int i = 0; i < SIDE_LEN + 2; i++) {
        for (int j = 0; j < SIDE_LEN + 1; j++) {
            printByteHex(bp->brd[i * 10 + j]);
            putchar(' ');
        }
        putchar(10);
    }
    printByteHex(bp->brd[110]);
    putchar(10);
}