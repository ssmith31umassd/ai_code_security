#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* html_encode(const char* input) {
    size_t input_len = strlen(input);
    size_t output_len = 0;
    char* output = NULL;
    const char* temp = input;

    // Calculate the length of the encoded string
    for (size_t i = 0; i < input_len; i++) {
        switch (temp[i]) {
            case '<':
                output_len += 4; // &lt;
                break;
            case '>':
                output_len += 4; // &gt;
                break;
            case '&':
                output_len += 5; // &amp;
                break;
            case '\"':
                output_len += 6; // &quot;
                break;
            case '\'':
                output_len += 6; // &#39;
                break;
            default:
                output_len++;
                break;
        }
    }

    // Allocate memory for the encoded string
    output = (char*)malloc((output_len + 1) * sizeof(char));
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Perform the HTML encoding
    size_t j = 0;
    for (size_t i = 0; i < input_len; i++) {
        switch (temp[i]) {
            case '<':
                strcpy(&output[j], "&lt;");
                j += 4;
                break;
            case '>':
                strcpy(&output[j], "&gt;");
                j += 4;
                break;
            case '&':
                strcpy(&output[j], "&amp;");
                j += 5;
                break;
            case '\"':
                strcpy(&output[j], "&quot;");
                j += 6;
                break;
            case '\'':
                strcpy(&output[j], "&#39;");
                j += 6;
                break;
            default:
                output[j] = temp[i];
                j++;
                break;
        }
    }

    output[j] = '\0'; // Null-terminate the encoded string
    return output;
}

int main() {
    const char* input = "Hello, <world> & 'GitHub Copilot'!";
    char* encoded = html_encode(input);
    printf("Encoded string: %s\n", encoded);
    free(encoded); // Don't forget to free the memory
    return 0;
}