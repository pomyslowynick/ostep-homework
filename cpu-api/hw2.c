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
    char *buffer;
    size_t bufsize = 100;
    buffer = (char *)malloc(bufsize * sizeof(char));
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else if (rc == 0) {
        getline(&buffer, &bufsize, fp);
        printf("%s", buffer);
    } else {
        getline(&buffer, &bufsize, fp);
        wait(NULL);
        printf("%s", buffer);
    }
    free(buffer);
    return 0;
}
