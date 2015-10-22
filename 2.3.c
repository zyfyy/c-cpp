#include <stdio.h>
#include <string.h>

#define YES 1
#define NO  0


int htoi(char s[]);

int main() {
    char s[] = "0X1";
    printf("%d\n", htoi(s));
}

int htoi (char s[]) {
    int i, d, inhex, total;

    i = 0;
    if (s[i] == '0') {
        i++;
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
    }

    total = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            d = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            d = s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            d = s[i] - 'a' + 10;
        } else {
            inhex = NO;
        }

        if (inhex == YES) {
            total = total * 16 + d;
        }

    }

    return total;
}
