#include <stdio.h>

int main(int argc, char *argv[]) {
    const int MAX_SIZE = 64;
    char buf[64], in[MAX_SIZE];
    int bytes = 0;
    printf("Enter buffer contents:\n");
    read(0, in, MAX_SIZE);
    printf("Bytes to copy");
    scanf("%d", &bytes);
    strncpy(buf, in, bytes);
    printf("Buffer contents: %s\n", buf);
    return 0;
}