#include <stdio.h>
#include <unistd.h>

#define BUFSIZER1   512
#define BUFSIZER2   ((BUFSIZER1/2) - 8)

int main(int argc, char **argv) {
   char *buf1R1;
   char *buf2R1;
   char *buf2R2;
   char *buf3R2;

   buf1R1 = (char *) malloc(BUFSIZER1);
   buf2R1 = (char *) malloc(BUFSIZER1);
   buf2R2 = (char *) malloc(BUFSIZER2);
   buf3R2 = (char *) malloc(BUFSIZER2);

   read(0, buf1R1, BUFSIZER1);
   read(0, buf2R1, BUFSIZER1);
   read(0, buf2R2, BUFSIZER2);
   read(0, buf3R2, BUFSIZER2);

   return 0;
}