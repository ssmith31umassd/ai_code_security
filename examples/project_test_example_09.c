#include <stdio.h>
#include <unistd.h>

void testChrootVulnerability(const char *filename, FILE *network) {
    char buf[256];
    FILE *localfile;

    // Reference:
    // OWASP Foundation. "Directory Restriction Error." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Directory_Restriction_Error (retrieved Feb. 21, 2024).
    chroot("/var/ftproot");
    // ...
    fgets(filename, sizeof(filename), network);
    localfile = fopen(filename, "r");
    while ((len = fread(buf, 1, sizeof(buf), localfile)) != EOF) {
        fwrite(buf, 1, sizeof(buf), network);
    }
    fclose(localfile);
    // end
}

int main(int argc, char **argv) {
    return 0;
}
