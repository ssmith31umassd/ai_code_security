#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyStringAfterCharacter(char *srcBuf, char *destBuf, char ch) {
    // Reference:
    // MITRE. "CWE-787: Out-of-bounds Write." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/787.html (retrieved Feb. 22, 2024).
    strncpy(destBuf, &srcBuf[find(srcBuf, ch)], 1024);
    // end
}

int main(int argc, char **argv) {
    return 0;
}
