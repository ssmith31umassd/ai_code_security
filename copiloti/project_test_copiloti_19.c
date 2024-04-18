#include <stdlib.h>
#include <stdio.h>

#define  LOOPS    10
#define  MAXSIZE  256

int main(int argc, char **argv)
{
     int count = 0;
     char *pointer = NULL;

    // allocate pointer LOOPS times
    for (int i = 0; i < LOOPS; i++) {
        pointer = (char *)malloc(MAXSIZE);
        if (pointer != NULL) {
            count++;
        }
    }

    printf("Allocated %d pointers\n", count);

    return 0;
}