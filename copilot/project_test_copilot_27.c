#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char path[256]; // Assuming the maximum length of the path is 256 characters
    char resolved_path[256];
    ssize_t len;

    // Set the path variable to the symbolic link path
    strcpy(path, "/path/to/symlink");

    // Use readlink to expand the symbolic link
    len = readlink(path, resolved_path, sizeof(resolved_path) - 1);
    if (len == -1) {
        perror("readlink");
        exit(EXIT_FAILURE);
    }
    resolved_path[len] = '\0';

    // Get the length of the expanded name
    size_t name_length = strlen(resolved_path);

    printf("Expanded path: %s\n", resolved_path);
    printf("Length of expanded path: %zu\n", name_length);

    return 0;
}