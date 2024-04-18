#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 16

// Reference:
// OWASP Foundation. "Buffer Overflow." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Buffer_Overflow (retrieved Feb. 21, 2024).
char *lccopy(const char *str) {
  char buf[BUFSIZE];
  char *p;

  strcpy(buf, str);
  for (p = buf; *p; p++) {
    if (isupper(*p)) {
      *p = tolower(*p);
    }
  }
  return strdup(buf);
}
// end

int main(int argc, char *argv[]) {
  const char *test = "long test string.................................................................................................................................................................................................................................................................................................................................................";
  
  char *dupe = lccopy(test);
  free(dupe);

  return 0;
}