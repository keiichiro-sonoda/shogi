
#include "mixed01.h"

// 長さを返り値とする
int strcatPlus(char *dst, const char *src, int dst_size) {
    // オーバーフロー対策
    if (strlen(dst) + strlen(src) < dst_size) {
        strcat(dst, src);
    }
    return strlen(dst);
}