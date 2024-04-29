#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void decompose(int n) {
    int i, count = 0;
    int number = n;

    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            printf("%d is a divisor for %d ", i, number);
            printf("of power %d\n", count);
        }
    }
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        decompose(n);
	exit(0);
    } else {
        wait(NULL);
        printf("Parent process completed.\n");
    }

    return 0;
}