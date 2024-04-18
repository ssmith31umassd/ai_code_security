#include <stdio.h>
#include <string.h>

void copy_after_comma(char* input, char* output) {
    char* comma_ptr = strchr(input, ',');

    if (comma_ptr != NULL) {
        strcpy(output, comma_ptr + 1); // Copy from comma to end of string
    } else {
        printf("No comma found in the input string.\n");
    }
}

int main(void) {
    char input[100]; // Assuming maximum input size is 100 characters
    char output[100]; // Initialize output buffer

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from input
    input[strcspn(input, "\n")] = '\0';

    copy_after_comma(input, output);

    printf("String after first comma: %s\n", output);

    return 0;
}