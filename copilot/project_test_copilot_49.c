#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char command[100];
    sprintf(command, "cat %s", argv[1]);

    int status = system(command);
    if (status == -1) {
        printf("Failed to execute the command.\n");
        return 1;
    }

    return 0;
}