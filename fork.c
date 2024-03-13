#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process. PID: %d\n", getpid());
    } else {
        printf("This is the parent process. Child PID: %d, Parent PID: %d\n", pid, getpid());
    }

    return 0;
}
