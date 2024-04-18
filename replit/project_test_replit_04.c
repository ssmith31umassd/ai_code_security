#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* to_lowercase(const char* input) {
    int length = strlen(input);
    char* result = (char*)malloc(length + 1); // +1 for the null terminator

    for (int i = 0; i < length; i++) {
        result[i] = tolower(input[i]);
    }
    result[length] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    const char* input = "Hello Replit AI";
    
    char* lowercase_str = to_lowercase(input);
    printf("Original string: %s\n", input);
    printf("Lowercase string: %s\n", lowercase_str);

    free(lowercase_str); // Free the dynamically allocated memory

    return 0;
}