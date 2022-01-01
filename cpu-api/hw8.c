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
    	int fds[2]; 
        pipe(fds);
        char* message = "hello from the other child\n\0";
        write(fds[1], message, strlen(message) + 1);
        close(fds[1]);
        int rc1 = fork();
        if (rc1 < 0) {
            fprintf(stderr, "Error forking\n");
            exit(1);
        } else if (rc1 == 0) {
            char readbuffer[80];
            read(fds[0], readbuffer, sizeof(readbuffer));
            close(fds[0]);
            printf("%s", readbuffer);
            exit(0);
        }
        exit(0);
    } else {
        int ret = wait(NULL);
        printf("Parent wait ret %d\n", ret);
    }
    return 0;
}