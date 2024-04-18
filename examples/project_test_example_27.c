#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAXPATH 16

int getLengthOfFilenameWithSymlink(const char *filename) {
    // Reference:
    // OWASP Foundation. "String Termination Error." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/String_Termination_Error (retrieved Feb. 21, 2024).
    char buf[MAXPATH];
    readlink(path, buf, MAXPATH);
    int length = strlen(filename);
    // end

    return length;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int len = getLengthOfFilenameWithSymlink(argv[1]);
        printf("length %d\n", len);
    }
    
    return 0;
}
