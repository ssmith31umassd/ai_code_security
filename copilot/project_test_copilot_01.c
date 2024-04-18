#include <stdio.h>

int main() {
    char name[100];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Hello, %s\n", name);

    return 0;
}
