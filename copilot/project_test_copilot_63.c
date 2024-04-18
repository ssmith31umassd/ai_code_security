#include <stdio.h>
#include <string.h>

void copyString(char* s, char* buf) {
    strcpy(buf, s);
}

int main() {
    char s[] = "Hello, world!";
    char buf[20];

    copyString(s, buf);

    printf("Copied string: %s\n", buf);

    return 0;
}