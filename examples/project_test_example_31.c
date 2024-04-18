#include <stdio.h>
#include <unistd.h>

#define DECODE_FAIL 1
#define DECODE_SUCCESS 0

void decodeBlock(char *buf) {
}

int checkChecksum(char *buf) {
    return 0;
}

// Reference:
// OWASP Foundation. "Unreleased Resource." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Unreleased_Resource (retrieved Feb. 21, 2024).
int decodeFile(char* fName)
{
   char buf[BUF_SZ];
   FILE* f = fopen(fName, "r");

   if (!f) {
      printf("cannot open %s\n", fName);
      return DECODE_FAIL;
   } else {
      while (fgets(buf, BUF_SZ, f)) {
         if (!checkChecksum(buf)) {
            return DECODE_FAIL;
         } else {
            decodeBlock(buf);
         }
      }
   }
   fclose(f);
   return DECODE_SUCCESS;
}
// end

int main(int argc, char **argv) {
    return 0;
}