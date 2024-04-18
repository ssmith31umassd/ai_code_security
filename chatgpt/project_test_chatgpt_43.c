#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* htmlEncode(const char* input) {
    // Allocate memory for the encoded string
    size_t input_length = strlen(input);
    char* encoded = (char*)malloc((4 * input_length + 1) * sizeof(char)); // At most, each character might be encoded as "&#xx;"
    if (encoded == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Loop through the input string and encode characters
    size_t i, j = 0;
    for (i = 0; i < input_length; ++i) {
        switch (input[i]) {
            case '&':
                strcpy(&encoded[j], "&amp;");
                j += 5;
                break;
            case '<':
                strcpy(&encoded[j], "&lt;");
                j += 4;
                break;
            case '>':
                strcpy(&encoded[j], "&gt;");
                j += 4;
                break;
            case '"':
                strcpy(&encoded[j], "&quot;");
                j += 6;
                break;
            case '\'':
                strcpy(&encoded[j], "&#39;");
                j += 5;
                break;
            default:
                encoded[j++] = input[i];
        }
    }
    encoded[j] = '\0';

    return encoded;
}

int main() {
    // Sample user input
    const char* userInput = "<script>alert('Hello, world!');</script>";

    // HTML encode the user input
    char* encodedString = htmlEncode(userInput);

    // Output the encoded string
    printf("Encoded string: %s\n", encodedString);

    // Free memory allocated for the encoded string
    free(encodedString);

    return 0;
}
