#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipe_p[2], res;
    char buf[50];
    pid_t pid;

    printf("Creating a pipe.\n");
    res = pipe(pipe_p);

    if (res == -1) {
        perror("pipe error:");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork error:");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("child:\n");
    } else {
        printf("father:\n");
    }
}
