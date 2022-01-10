#include <stdio.h>
#include <pthread.h>

void *threadfun(void *arg) {
    (void)arg;
    puts("Hello world from the thread!");
    return NULL;
}
int main(int argc, char const *argv[])
{
    pthread_t thread;
    pthread_create(&thread, NULL, threadfun, NULL);
    puts("Hello world!");
    return 0;
}
