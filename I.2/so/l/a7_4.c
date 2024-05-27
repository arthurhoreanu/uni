#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_word(char c) {
    return (is_alpha(c) || (c >= '0' && c <= '9'));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    int word_count = 0;
    int in_word = 0;
    char c;

    int fd[2];
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        close(fd[0]);

        while ((c = fgetc(file)) != EOF) {
            if (is_word(c)) {
                if (!in_word) {
                    in_word = 1;
                    word_count++;
                }
            } else {
                in_word = 0;
            }
        }

        fclose(file);
        write(fd[1], &word_count, sizeof(int));
        close(fd[1]);
        exit(0);
    } else {
        close(fd[1]);

        int child_word_count;
        read(fd[0], &child_word_count, sizeof(int));
        close(fd[0]);
        wait(NULL);

        word_count += child_word_count;
    }

    printf("The file '%s' contains %d words.\n", argv[1], word_count);

    return 0;
}