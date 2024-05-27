#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "extension_fifo"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *extension = strrchr(filename, '.');

    if (extension == NULL) {
        printf("File has no extension.\n");
        return 1;
    }

    mkfifo(FIFO_FILE, 0666);

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error creating child process.\n");
        return 1;
    } else if (pid == 0) {
        int fd = open(FIFO_FILE, O_RDONLY);
        if (fd == -1) {
            printf("Error opening FIFO file.\n");
            return 1;
        }

        char buffer[256];
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
        if (bytesRead == -1) {
            printf("Error reading from FIFO file.\n");
            return 1;
        }

        buffer[bytesRead] = '\0';
        printf("File type: %s\n", buffer);
        close(fd);
    } else {
        int fd = open(FIFO_FILE, O_WRONLY);
        if (fd == -1) {
            printf("Error opening FIFO file.\n");
            return 1;
        }

        write(fd, extension + 1, strlen(extension + 1));
        close(fd);

        unlink(FIFO_FILE);
    }

    return 0;
}