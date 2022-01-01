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
        struct fd_pair pipe_hw = pipe();
        fprintf(pipe[1], "hello from the other child");
        int rc1 = fork();
        if (rc1 < 0) {
            fprintf(stderr, "Error forking\n");
            exit(1);
        } else if (rc1 == 0) {
            // close(STDOUT_FILENO);
            printf("%s\n", pipe_hw[0]);
        }
        
    } else {
        int wstatus;
        printf("Child status %d\n", wstatus);
        int ret = waitpid(rc, &wstatus, 0);
        printf("Parent wait ret %d\n", ret);
        printf("Child status %d\n", wstatus);
    }
    return 0;
}
