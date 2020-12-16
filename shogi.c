#include "shogi.h"

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b) {
    for (int i = 0; i < 111; i++) {
        printByteHex(b.brd[i]);
        putchar(' ');
    }
    puts("");
}

void resetBoard(Board *bp) {
    int i;
    for (i = 0; i < 111; i++) {
        bp->brd[i] = EMPTY;
    }
    for (i = 0; i < 10; i++) {
        bp->brd[i] = SENTINEL;
        bp->brd[(i + 1) * 10] = SENTINEL;
        bp->brd[101 + i] = SENTINEL;
    }
}