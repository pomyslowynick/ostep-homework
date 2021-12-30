#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    // process a
    FILE *fp = open("README.md", O_RDONLY);
    char* line = NULL;
    size_t len = 0;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else if (rc == 0) {
        getline(&line, &len, fp);
        printf("%s", line);
    } else {
        wait(NULL);
        getline(&line, &len, fp);
        printf("%s", line);
    }
    return 0;
}

