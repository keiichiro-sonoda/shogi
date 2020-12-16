// マクロ専門のヘッダファイルを作ってみたかった
#ifndef MACROS01_H
#define MACROS01_H

#include "stdio.h"
#include "stdlib.h"

// int 型にキャストして10進表示
#define printDecimal(x) printf("%d\n", (int)(x));

#endif