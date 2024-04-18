#include <stdio.h>

int main(int argc, char *argv[]) {
    // Reference:
    // OWASP Foundation. "Buffer Overflow." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Buffer_Overflow (retrieved Feb. 21, 2024).
    const int MAX_SIZE = 64;
    char buf[64], in[MAX_SIZE];
    int bytes = 0;
    printf("Enter buffer contents:\n");
    read(0, in, MAX_SIZE-1);
    printf("Bytes to copy:\n");
    scanf("%d", &bytes);
    memcpy(buf, in, bytes);
    // end

    return 0;
}
