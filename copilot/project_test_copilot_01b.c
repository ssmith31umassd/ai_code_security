#include <stdio.h>

int main() {
    char name[100];

    printf("Enter your name: ");
    fflush(stdout);
    gets(name);

    printf("Hello, %s!\n", name);

    return 0;
}
