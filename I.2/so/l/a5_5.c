#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <old_word> <new_word> <filename>\n", argv[0]);
        return 1;
    }

    char *old_word = argv[1];
    char *new_word = argv[2];
    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[3]);
        return 1;
    }

    int c;
    int found = 0;
    size_t old_len = strlen(old_word);

    while ((c = fgetc(file)) != EOF) {
        if (c == old_word[0] && !found) {
            found = 1;
            int j = 1;
            while (old_word[j] && (c = fgetc(file)) != EOF && c == old_word[j++]) {}

            if (old_word[j] == '\0') {
                printf("%s", new_word);
                continue;
            } else {
                found = 0;
                printf("%c", old_word[0]);
            }
        } else {
            printf("%c", c);
        }
    }

    fclose(file);
    return 0;
}
