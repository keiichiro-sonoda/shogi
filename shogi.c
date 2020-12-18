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

// 盤面の駒をアルファベットで表示したい
void showBoard(Board b) {
    int i, j, k;
    char str[BUF_LEN];
    u_char koma;
    k = strcatPlus(str, "hold2: ", BUF_LEN);
    for (i = PAWN; i < KING; i++) {
        str[k++] = PIECES_CHAR[i];
        str[k++] = b.hold[i | 8] + '0';
        str[k++] = ' ';
    }
    str[k++] = 10;
    for (i = 0; i < SIDE_LEN; i++) {
        for (j = 0; j < SIDE_LEN; j++) {
            if ((koma = b.brd[i * 10 + j + 11]) & PROMOTED) {
                str[k++] = '+';
            } else {
                str[k++] = ' ';
            }
            str[k++] = PIECES_CHAR[koma & 0xf];
            if (koma & TURN) {
                str[k++] = '2';
            } else if (koma) {
                str[k++] = '1';
            } else {
                str[k++] = ' ';
            }
            str[k++] = ' ';
        }
        str[k++] = '\n';
    }
    str[k] = 0;
    puts(str);
    printDecimal(k);
}

// 盤面初期化
void resetBoard(Board *bp) {
    int i, row;
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
        else if (i == 28 || i == 82) {
            koma = BISHOP;
            koma |= PROMOTED;
        }
        else if ((row = i / 10) == 3 || row == 7) {
            koma = PAWN;
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
    bp->hold[BISHOP | TURN] = 3;
    /*
    for (int i = 0; i < SIDE_LEN + 2; i++) {
        for (int j = 0; j < SIDE_LEN + 1; j++) {
            printByteHex(bp->brd[i * 10 + j]);
            putchar(' ');
        }
        putchar(10);
    }
    printByteHex(bp->brd[110]);
    putchar(10);
    */
}