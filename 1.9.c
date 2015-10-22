#include <stdio.h>

#define C ' '
#define D 'd'

int main() {
    char c, pre;

    while( (c = getchar()) != EOF) {
        if (c == C) {
            if (pre != C) {
                putchar(c);
            }
            pre = C;
        } else {
            putchar(c);
            pre = D;
        }
    }
}
