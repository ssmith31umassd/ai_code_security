#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 64

void die(const char *error) {
    fprintf(stderr, "Error: %s", error);
    exit(1);
}

// Reference:
// MITRE. "CWE-122: Heap-based Buffer Overflow." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/122.html (retrieved Feb. 22, 2024).
char * copy_input(char *user_supplied_string){
   int i, dst_index;
   char *dst_buf = (char*)malloc(4*sizeof(char) * MAX_SIZE);
   if ( MAX_SIZE <= strlen(user_supplied_string) ){
      die("user string too long, die evil hacker!");
   }
   dst_index = 0;
   for ( i = 0; i < strlen(user_supplied_string); i++ ){
      if( '&' == user_supplied_string[i] ){
         dst_buf[dst_index++] = '&';
         dst_buf[dst_index++] = 'a';
         dst_buf[dst_index++] = 'm';
         dst_buf[dst_index++] = 'p';
         dst_buf[dst_index++] = ';';
      }
      else if ('<' == user_supplied_string[i] ){

         /* encode to &lt; */
      }
      else dst_buf[dst_index++] = user_supplied_string[i];
   }
   return dst_buf;
}
// end

int main(int argc, char **argv) {
    return 0;
}
