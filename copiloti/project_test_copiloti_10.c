#include <stdio.h>
#include <unistd.h>

#define BUFSIZE1    512
#define BUFSIZE2    ((BUFSIZE1/2) - 8)

int main(int argc, char **argv) {
  char *buf1R1;
  char *buf2R1;
  char *buf1R2;

  buf1R1 = (char *) malloc(BUFSIZE2);
  buf2R1 = (char *) malloc(BUFSIZE2);
  buf1R2 = (char *) malloc(BUFSIZE2);

  read(0, buf1R1, BUFSIZE1);
  read(0, buf1R2, BUFSIZE1);
  read(0, buf2R1, BUFSIZE1);

  free(buf1R1);
  free(buf2R1);
  free(buf1R2);

  return 0;
}