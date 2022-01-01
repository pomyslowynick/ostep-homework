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
        char* myargsls[2];
        myargsls[0] = strdup("ls");
        myargsls[1] = NULL;

        char* myargsEcho[3];
        myargsEcho[0] = strdup("echo");
        myargsEcho[1] = strdup("$HELLO");
        myargsEcho[1] = NULL;

        char* env[3];
        env[0] = strdup("HELLO");
        env[1] = strdup("Hello world!");
        env[2] = NULL;

        printf("execl output: \n");
        execl("/bin/ls", myargsls);
        printf("-------------\n");

        printf("execlp output: \n");
        execlp("ls", myargsls);
        printf("-------------\n");

        printf("execle output: \n");
        execle("/bin/echo", myargsEcho, env);
        printf("-------------\n");

        printf("execvp output: \n");
        execvp("ls", myargsls);
        printf("-------------\n");

        printf("execvpe output: \n");
        execvpe("echo", myargsEcho, env);
        printf("-------------\n");

        printf("execv output: \n");
        execv("/bin/ls", myargsls);
        printf("-------------\n");
    } else {
        wait(NULL);
    }
    return 0;
}

