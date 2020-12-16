/*
    選ばれた動物の鳴き声を表示
*/

#include "shogi.h"

enum animal {Dog, Cat, Monkey, Invalid};

/*--- 犬が鳴く ---*/
void dog(void) {
    puts("ワンワン!!");
}

/*--- 猫が鳴く ---*/
void cat(void) {
    puts("ニャ〜オ!!");
}

/*--- 猿が鳴く ---*/
void monkey(void) {
    puts("キッキッ!!");
}

/*--- 動物を選ぶ ---*/
enum animal selectAnimal(void) {
    int tmp;
    do {
        printf("0… 犬  1… 猫  2… 猿  3… 終了：");
        scanf("%d", &tmp);
    } while (tmp < Dog || tmp > Invalid);
    return tmp;
}

int main(void) {
    Board b;
    resetBoard(&b);
    showBoardNum(b);
    return 0;
}