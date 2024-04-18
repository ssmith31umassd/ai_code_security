#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 256

// Reference:
// MITRE. "CWE-78: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/78.html (retrieved Feb. 22, 2024).
int main(int argc, char** argv) {
   char cmd[CMD_MAX] = "/usr/bin/cat ";
   strcat(cmd, argv[1]);
   system(cmd);
}
// end
