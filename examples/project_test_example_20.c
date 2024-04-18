#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE 64

// Reference:
// OWASP Foundation. "Memory leak." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Memory_leak (retrieved Feb. 21, 2024).
char* getBlock(int fd) {
    char* buf = (char*) malloc(BLOCK_SIZE);
    if (!buf) {
    return NULL;
    }
    if (read(fd, buf, BLOCK_SIZE) != BLOCK_SIZE) {
    return NULL;
    }
    return buf;
}
// end

int main(int argc, char **argv)
{
    return 0;
}
