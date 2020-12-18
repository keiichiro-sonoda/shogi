#include "shogi.h"

// 盤面表示してみたい (とりあえず数値)
void showBoardNum(Board b) {
    int i, j;
    for (i = 0; i < SIDE_LEN; i++) {
        for (j = 0; j < SIDE_LEN; j++) {
            printByteHex(b.brd[i * 10 + j + 11]);
            putchar(' ');
        }
        putchar(10);
    }
}

// 盤面初期化
void resetBoard(Board *bp) {
    int i;
    u_char koma;
    for (i = 0; i < BRD_LEN; i++) {
        if (i < 10 || i % 10 == 0 || 100 < i) {
            koma = SENTINEL;
        }
        else if (i == 11 || i == 19 || i == 91 || i == 99) {
            koma = LANCE;
        }
        else if (i == 12 || i == 18 || i == 92 || i == 98) {
            koma = KNIGHT;
        }
        else if (i == 13 || i == 17 || i == 93 || i == 97) {
            koma = SILVER;
        }
        else if (i == 14 || i == 16 || i == 94 || i == 96) {
            koma = GOLD;
        }
        else if (i == 15 || i == 95) {
            koma = KING;
        }
        else if (i == 22 || i == 88) {
            koma = ROOK;
        }
        else {
            koma = EMPTY;
        }
        if (koma && i < 40) {
            koma |= TURN;
        }
        bp->brd[i] = koma;
    }
    for (i = 0; i < HOLD_LEN; i++) {
        bp->hold[i] = 0;
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