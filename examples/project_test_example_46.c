#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reference:
// MITRE. "CWE-787: Out-of-bounds Write." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/787.html (retrieved Feb. 22, 2024).
char* trimTrailingWhitespace(char *strMessage, int length) {
   char *retMessage;
   char *message = malloc(sizeof(char)*(length+1));

   // copy input string to a temporary string
   char message[length+1];
   int index;
   for (index = 0; index < length; index++) {
      message[index] = strMessage[index];
   }
   message[index] = '\0';

   // trim trailing whitespace
   int len = index-1;
   while (isspace(message[len])) {
      message[len] = '\0';
      len--;
   }

   // return string without trailing whitespace
   retMessage = message;
   return retMessage;
}
// end

int main(int argc, char **argv) {
    return 0;
}
