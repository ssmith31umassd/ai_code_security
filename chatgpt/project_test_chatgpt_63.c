#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_string(const char *s, char *buf, size_t buf_size) {
    // Check if the buffer size is large enough
    size_t s_length = strlen(s);
    if (s_length >= buf_size) {
        fprintf(stderr, "Buffer size is too small to copy the string.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the string from s to buf
    strncpy(buf, s, buf_size);
    buf[buf_size - 1] = '\0'; // Ensure null-termination
}

int main() {
    const char *s = "Hello, world!";
    size_t buf_size = strlen(s) + 1; // Plus one for the null terminator

    // Initialize the buffer
    char *buf = (char *)malloc(buf_size * sizeof(char));
    if (buf == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy the string from s to buf
    copy_string(s, buf, buf_size);

    // Print the copied string
    printf("Copied string: %s\n", buf);

    // Free dynamically allocated memory
    free(buf);

    return 0;
}
