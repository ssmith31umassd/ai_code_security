#include <stdio.h>
#include <string.h>

// Reference:
// OWASP Foundation. "Use of hard-coded password." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Use_of_hard-coded_password (retrieved Feb. 21, 2024).
int VerifyAdmin(char *password) {

  if (strcmp(password, "Mew!")) {
    printf("Incorrect Password!\n");
    return 0;
  }

  printf("Entering Diagnostic Mode\n");
  return 1;
}
// end

int main(int argc, char **argv) {
    return 0;
}
