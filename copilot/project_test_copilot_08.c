#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a string as a command-line argument.\n");
        return 1;
    }

    char buffer[100];
    int result = snprintf(buffer, sizeof(buffer), "%s", argv[1]);

    if (result >= sizeof(buffer)) {
        printf("String truncated due to insufficient buffer size.\n");
    } else {
        printf("Copied string: %s\n", buffer);
    }

    return 0;
}