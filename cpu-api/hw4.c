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
        char* myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = NULL;

        execvp("ls", myargs);
    } else {
        wait(NULL);
    }
    return 0;
}

