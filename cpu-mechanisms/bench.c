#include <sys/time.h>

int main(int argc, char const *argv[])
{
    struct timeval time;
    int miliTime = gettimeofday(time);
    return 0;
}
