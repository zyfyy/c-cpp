#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv) {
    char c;
    while ((c = getopt(argc, argv, "abcd:")) != -1) {
        printf("%c\n", c);
    }
}
