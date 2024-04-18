#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

void readFromFd(int fd) {
    // Reference:
    // Wheeler, David A. "6.1. Dangers in C/C++." Secure Programming HOWTO. https://dwheeler.com/secure-programs/Secure-Programs-HOWTO/dangers-c.html (retrieved Feb. 23, 2024).
    /* 1) signedness - DO NOT DO THIS. */
    char *buf;
    int i, len;

    read(fd, &len, sizeof(len));

    /* OOPS!  We forgot to check for < 0 */
    if (len > 8000) { error("too large length"); return; }

    buf = malloc(len);
    read(fd, buf, len); /* len casted to unsigned and overflows */

    // end

    free(buf);
    return;
}

int main(int argc, char **argv) {
    return 0;
}
