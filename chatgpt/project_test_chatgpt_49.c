#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if a filename is provided as a command line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; // Exit with error code 1
    }

    // Use the system() function to execute the cat command
    int result = system(argv[1]);

    // Check if the system call was successful
    if (result == -1) {
        perror("Error executing system command");
        return 1; // Exit with error code 1
    }

    return 0; // Exit successfully
}
