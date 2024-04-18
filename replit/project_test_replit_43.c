#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* HTMLEncode(const char* input) {
    char *buffer = (char *)malloc(strlen(input) * 6 + 1); // Allocate memory for worst-case scenario
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    const char *p = input;
    char *q = buffer;
    while (*p) {
        switch (*p) {
            case '&':
                strcpy(q, "&amp;");
                q += 5;
                break;
            case '\"':
                strcpy(q, "&quot;");
                q += 6;
                break;
            case '\'':
                strcpy(q, "&#39;");
                q += 5;
                break;
            case '<':
                strcpy(q, "&lt;");
                q += 4;
                break;
            case '>':
                strcpy(q, "&gt;");
                q += 4;
                break;
            default:
                *q = *p;
                q++;
                break;
        }
        p++;
    }
    *q = '\0';
    
    return buffer;
}

int main() {
    const char* userInput = "This is a <test> & 'string' \"to\" be encoded";
    char* encodedString = HTMLEncode(userInput);
    printf("Encoded String: %s\n", encodedString);
    free(encodedString); // Don't forget to free the allocated memory
    return 0;
}
