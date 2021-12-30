#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    // process a
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else if (rc == 0) {
        printf("%d the value of x in the child\n", x);
        x = 50;
        printf("%d the value of x in the child after mutating\n", x);
    } else {
        printf("%d the value of x in the parent\n", x);
        wait(NULL);
        printf("%d the value of x in the parent after mutating\n", x);
    }
    return 0;
}

