// Reference:
// CMU Software Engineering Institute. "FIO37-C. Do not assume that fgets() or fgetws() returns a nonempty string when successful." SEI CERT C Coding Standard. https://wiki.sei.cmu.edu/confluence/display/c/FIO37-C.+Do+not+assume+that+fgets%28%29+or+fgetws%28%29+returns+a+nonempty+string+when+successful (retrieved Feb. 22, 2024).        
#include <stdio.h>
#include <string.h>
  
enum { BUFFER_SIZE = 1024 };
 
void func(void) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
    /* Handle error */
  }
  buf[strlen(buf) - 1] = '\0';
}
// end

int main(int argc, char **argv) {
    return 0;
}
