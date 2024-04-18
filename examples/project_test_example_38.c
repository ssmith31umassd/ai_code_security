#include <stdio.h>
#include <stdlib.h>

#define SIZE 64

int err = 0;
int abrt = 0;

void logError(const char *message, char *ptr) {}

void testInput() {
    // Reference:
    // OWASP Foundation. "Using freed memory." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Using_freed_memory (retrieved Feb. 21, 2024).
    char* ptr = (char*)malloc (SIZE);

    // ...

    if (err) {
    abrt = 1;
    free(ptr);
    }

    // ...

    if (abrt) {
    logError("operation aborted before commit", ptr);
    }
    // end
}

int main(int argc, char **argv) {
    return 0;
}
