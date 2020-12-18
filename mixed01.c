
#include "mixed01.h"

// 長さを返り値とする
int strcatPlus(char *dst, const char *src, int dst_size) {
    int l;
    // オーバーフロー対策
    if (strlen(dst) + strlen(src) < dst_size) {
        strcat(dst, src);
    }
    l = strlen(dst);
    dst[l] = '\0';
    return l;
}