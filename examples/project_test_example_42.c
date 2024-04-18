#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reference:
// MITRE. "CWE-122: Heap-based Buffer Overflow." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/122.html (retrieved Feb. 22, 2024).
#define BUFSIZE 256
int main(int argc, char **argv) {
   char *buf;
   buf = (char *)malloc(sizeof(char)*BUFSIZE);
   strcpy(buf, argv[1]);
}
// end
