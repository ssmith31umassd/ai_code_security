#include <stdio.h>
#include <unistd.h>
#include <string.h>

void readFromFileAndCopyToBuffer(FILE *cfgfile, char *inputbuf) {
    // Reference:
    // OWASP Foundation. "String Termination Error." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/String_Termination_Error (retrieved Feb. 21, 2024).
    #define MAXLEN 1024
    char *pathbuf[MAXLEN];
    read(cfgfile,inputbuf,MAXLEN); //does not null terminate
    strcpy(pathbuf,input_buf); //requires null terminated input
    // end
}

int main(int argc, char *argv[]) {
    return 0;
}
