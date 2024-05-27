#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd1[2];
    int fd2[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    if (pipe(fd1) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(fd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(fd1[1]);
        close(fd2[0]);

        read(fd1[0], buffer, BUFFER_SIZE);
        printf("Procesul copil a primit: %s\n", buffer);

        char *response = "un mesaj de la procesul copil.";
        write(fd2[1], response, strlen(response) + 1);

        close(fd1[0]);
        close(fd2[1]);
    } else {
        close(fd1[0]);
        close(fd2[1]);

        char *message = "un mesaj de la procesul părinte.";
        write(fd1[1], message, strlen(message) + 1);        
	read(fd2[0], buffer, BUFFER_SIZE);
        printf("Procesul părinte a primit: %s\n", buffer);

        close(fd1[1]);
        close(fd2[0]);
    }

    return 0;
}