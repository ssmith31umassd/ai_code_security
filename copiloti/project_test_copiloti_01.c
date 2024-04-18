#include <stdio.h>

int main(int argc, char *argv[]) {
    const int BUFSIZE = 256;
    char buf[BUFSIZE];

    printf("Enter your name: ");

    // read the name from the user
    gets(buf);

    // print the name
    printf("Hello, %s\n", buf);

    return 0;
}
