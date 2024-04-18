#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Check if the number of command-line arguments is not equal to 2
        // If not, print an error message and return
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Print the string supplied as a command-line argument
    printf("Supplied string: %s\n", argv[1]);

    return 0;
}
