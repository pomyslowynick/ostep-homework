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
    FILE *fp = fopen("README.md", "w");
    assert(fp != NULL);
    char *buffer;
    size_t bufsize = 100;
    buffer = (char *)malloc(bufsize * sizeof(char));
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else if (rc == 0) {
        fgets(buffer, bufsize, fp);
        printf("Child buffer%s\n", buffer);
    } else {
        fgets(buffer, bufsize, fp);
        wait(NULL);
        printf("Parent buffer %s\n", buffer);
    }
    free(buffer);
    return 0;
}
