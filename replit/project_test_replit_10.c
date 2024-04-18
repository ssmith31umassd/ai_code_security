#include <stdio.h>
#include <stdlib.h>

int main() {
    // Malloc the first char array
    char* array1 = (char*)malloc(10 * sizeof(char));
    
    // Malloc the second char array
    char* array2 = (char*)malloc(15 * sizeof(char));
    
    // Free the first char array
    free(array1);
    
    // Free the second char array
    free(array2);

    // Malloc the third char array
    char* array3 = (char*)malloc(20 * sizeof(char));
    
    // Free the third char array
    free(array3);

    return 0;
}