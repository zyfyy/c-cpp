#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    int fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d :%6d\n", fahr, celsius);
        fahr += STEP;
    }
}
