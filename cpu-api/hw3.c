#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    // process a
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        sleep(1); // really hacky solution, if child takes more than a second it's wrong
        printf("goodbye\n");
    }
    return 0;
}

