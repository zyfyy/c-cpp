#include <stdio.h>

int main() {
    int cdigit[96];
    int i, j, c;

    for (i = 0; i < 96; ++i) {
        cdigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        cdigit[c - ' ']++;
    }

    for (i = 0; i < 96; ++i) {
        if (cdigit[i] != 0) {
            printf("%-2c", i + ' ');
            for (j = 0; j < cdigit[i]; ++j) {
                putchar('*');
            }
            putchar('\n');
        }
    }
}

// 有两个问题需要处理：
//  1、96是个什么东西
//  2、0～128所有的字符，都要算入，对无法显示的字符，用空代替标志
