#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Check if the number of command-line arguments is not equal to 2
        // If not, print an error message and return
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Define a char array to hold the string
    char buffer[100]; // Adjust the size as per your requirement

    // Use snprintf to write the string to the char array
    int written_chars = snprintf(buffer, sizeof(buffer), "%s", argv[1]);

    if (written_chars >= sizeof(buffer)) {
        // If the written characters exceed the size of the buffer, handle the error
        printf("String too long for buffer!\n");
        return 1;
    }

    // Print the string written to the char array
    printf("String written to buffer: %s\n", buffer);

    return 0;
}
