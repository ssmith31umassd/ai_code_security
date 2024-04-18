#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* convertToLowercase(const char* str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        result[i] = tolower(str[i]);
    }
    result[len] = '\0';

    return result;
}

int main() {
    const char* input = "Hello, World!";
    char* lowercase = convertToLowercase(input);
    printf("Lowercase: %s\n", lowercase);
    free(lowercase);

    return 0;
}