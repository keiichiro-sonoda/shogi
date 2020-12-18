// マクロ専門のヘッダファイルを作ってみたかった
#ifndef MACROS01_H
#define MACROS01_H

#include "stdio.h"
#include "stdlib.h"

#define BUF_LEN 1024

// int 型にキャストして10進表示
#define printDecimal(x) printf("%d\n", (int)(x))
// バイト数を表示
#define printSize(x) printf("%ld\n", sizeof(x))
// 下位8ビット (1バイト) のみ16進表示
#define printByteHex(x) printf("%02x", (x) & 0xff)

#endif