#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("%s\n", argv[1]);
    } else {
        printf("No command-line argument provided.\n");
    }
    
    return 0;
}