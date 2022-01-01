#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <features.h>

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

        const char *env[] = { "HELLO=Hello", (char *)NULL };


        printf("execl output: \n");
        //execl("/bin/ls", myargsls[0], (char *)NULL);
        printf("-------------\n");

        printf("execlp output: \n");
        //execlp("echo", myargsEcho[0], myargsEcho[1], (char *)NULL);
        printf("-------------\n");

        printf("execle output: \n");
        // interesting point, the variable expansion is done by the shell, so executing this without
        // the shell doesn't print the right env variable
        //execle("/bin/bash","bash", "-c", "echo $HELLO", (char *)NULL, env);
        printf("-------------\n");

        printf("execvp output: \n");
        //execvp("ls", myargsls);
        printf("-------------\n");

        printf("execvpe output: \n");
        //execvpe does not work on my system, or I haven't found a way to run on Ubuntu16.04
        //execvpe("/bin/bash","bash", "-c", "echo $HELLO", (char *)NULL, env);
        printf("-------------\n");

        printf("execv output: \n");
        execv("/bin/ls", myargsls);
        printf("-------------\n");
    } else {
        wait(NULL);
    }
    return 0;
}
