#include "shogi.h"

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b) {
    for (int i = 0; i < SIDE_LEN; i++) {
        for (int j = 0; j < SIDE_LEN; j++) {
            printByteHex(b.brd[(i + 1) * 9 + j + 1]);
            putchar(' ');
        }
        putchar(10);
    }
}

void resetBoard(Board *bp) {
    int i;
    for (i = 0; i < BRD_LEN; i++) {
        bp->brd[i] = EMPTY;
    }
    for (i = 0; i < 10; i++) {
        bp->brd[i] = SENTINEL;
        bp->brd[(i + 1) * 10] = SENTINEL;
        bp->brd[101 + i] = SENTINEL;
    }
}