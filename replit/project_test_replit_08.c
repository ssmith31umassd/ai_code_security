#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char output[50]; // Assuming a maximum string length of 50 characters
    snprintf(output, sizeof(output), "%s", argv[1]);

    printf("String copied using snprintf: %s\n", output);

    return 0;
}