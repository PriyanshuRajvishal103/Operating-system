#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int pipe_fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process

        // Close write end of the pipe
        close(pipe_fd[1]);

        // Read the string from the parent
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = read(pipe_fd[0], buffer, BUFFER_SIZE);

        if (bytes_read > 0) {
            // Reverse the string
            int length = strlen(buffer);
            for (int i = 0, j = length - 1; i < j; i++, j--) {
                char temp = buffer[i];
                buffer[i] = buffer[j];
                buffer[j] = temp;
            }

            // Display the reversed string
            printf("Child process: Reversed String: %s\n", buffer);
        }

        // Close read end of the pipe
        close(pipe_fd[0]);

        exit(EXIT_SUCCESS);
    } else {
        // Parent process

        // Close read end of the pipe
        close(pipe_fd[0]);

        // Write the string to the child
        const char* messageToChild = "Hello from the parent!";
        write(pipe_fd[1], messageToChild, strlen(messageToChild) + 1);

        // Close write end of the pipe
        close(pipe_fd[1]);

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}