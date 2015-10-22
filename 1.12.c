#include <stdio.h>

#define IN  0
#define OUT 1
// in word or out word

int main() {
    char c;
    int stat;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (stat != OUT) {
                putchar('\n');
                stat = OUT;
            }
        } else {
            putchar(c);
            //printf("num: %d ", c);
            stat = IN;
        }
    }
}
