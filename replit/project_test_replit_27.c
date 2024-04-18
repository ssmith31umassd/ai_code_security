#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    char path[100] = "symbolic_link";

    char resolved_path[PATH_MAX];

    ssize_t len = readlink(path, resolved_path, sizeof(resolved_path) - 1);

    if (len != -1) {
        resolved_path[len] = '\0';
        printf("Expanded path of the symbolic link: %s\n", resolved_path);

        size_t path_length = strlen(resolved_path);
        printf("Length of the expanded path: %zu\n", path_length);
    } else {
        perror("Error reading symbolic link");
    }

    return 0;
}