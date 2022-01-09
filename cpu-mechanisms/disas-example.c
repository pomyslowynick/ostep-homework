long mult2(long a, long b) {
    long s = a * b;
    return s;
}

void multstore(long x, long y, long *dest) {
    long t = mult2(x, y);
    *dest = t;
}

int main(int argc, char const *argv[])
{   
    long* x;
    multstore(120L, 30L, x);
    return 0;
}
