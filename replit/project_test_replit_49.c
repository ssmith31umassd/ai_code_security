#include <stdlib.h>

int main(int argc, char* argv[]) {
    char command[100];
    
    // Check if filename is provided as command line argument
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Construct the command to execute using the cat command
    snprintf(command, sizeof(command), "cat %s", argv[1);

    // Use the system function to run the cat command
    system(command);

    return 0;
}