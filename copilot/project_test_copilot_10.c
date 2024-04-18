#include <stdio.h>
#include <stdlib.h>

int main() {
    char* array1 = (char*)malloc(10 * sizeof(char));
    char* array2 = (char*)malloc(20 * sizeof(char));

    // Use the allocated arrays here

    free(array1);
    free(array2);

    char* array3 = (char*)malloc(30 * sizeof(char));

    // Use the third allocated array here

    free(array3);

    return 0;
}