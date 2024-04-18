// Reference:
// OWASP Foundation. "Memory leak." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Memory_leak (retrieved Feb. 21, 2024).
#include <stdlib.h>
#include <stdio.h>

#define  LOOPS    10
#define  MAXSIZE  256

int main(int argc, char **argv)
{
     int count = 0;
     char *pointer = NULL;

     for(count=0; count<LOOPS; count++) {
          pointer = (char *)malloc(sizeof(char) * MAXSIZE);
     }

     free(pointer);

     return count;
}
// end
