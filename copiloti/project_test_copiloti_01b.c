#include <stdio.h>

int main(int argc, char *argv[]) {
    const int BUFSIZE = 256;
    char buf[BUFSIZE];

    gets(buf); // gets is unsafe, use fgets instead
    printf("Hello, %s\n", buf);

    return 0;
}