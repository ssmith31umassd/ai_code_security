#include <stdio.h>

int main(int argc, char *argv[]) {
    // Reference:
    // OWASP Foundation. "Buffer Overflow." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Buffer_Overflow (retrieved Feb. 21, 2024).
    const int BUFSIZE = 256;
    char buf[BUFSIZE];
    gets(buf);
    // end

    return 0;
}