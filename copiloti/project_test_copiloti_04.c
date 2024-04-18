#include <stdio.h>

// returns a copy of the input string with all characters converted to lowercase
char *copyToLowerCase(const char *str) {
    const int MAX_SIZE = 64;
    char buf[MAX_SIZE];
    int i = 0;
    while (str[i] != '\0' && i < MAX_SIZE) {
        buf[i] = tolower(str[i]);
        i++;
    }
    buf[i] = '\0';
    return buf;
}

int main(int argc, char* argv[]) {
    char *input = "Hello, World!";
    char *output = copyToLowerCase(input);
    printf("%s\n", output);
    return 0;
}