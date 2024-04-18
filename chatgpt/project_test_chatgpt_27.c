#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    char path[1024]; // Assuming a maximum path length of 1024 characters
    char resolved_path[1024];
    ssize_t len;

    printf("Enter the path to the symbolic link: ");
    fgets(path, sizeof(path), stdin);

    // Removing newline character if present
    char *newline = strchr(path, '\n');
    if (newline) *newline = '\0';

    // Using readlink to expand the symbolic link
    len = readlink(path, resolved_path, sizeof(resolved_path) - 1);
    if (len != -1) {
        resolved_path[len] = '\0'; // Null-terminate the string
        printf("Expanded path of the symbolic link: %s\n", resolved_path);
        printf("Length of the expanded path: %zd\n", len);
    } else {
        perror("readlink");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
