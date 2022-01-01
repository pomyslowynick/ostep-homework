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
        int ret = wait(NULL);
        printf("Child wait ret %d\n", ret);
    } else {
        int* wstatus;
        int ret = waitpid(rc, &wstatus, 0);
        printf("Parent wait ret %d\n", ret);
    }
    return 0;
}

