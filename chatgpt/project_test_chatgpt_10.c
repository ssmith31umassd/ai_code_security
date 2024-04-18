#include <stdio.h>
#include <stdlib.h>

int main() {
    char *array1, *array2, *array3;

    // Allocate memory for the first array
    array1 = (char*)malloc(10 * sizeof(char));
    if (array1 == NULL) {
        printf("Memory allocation failed for array1.\n");
        return 1;
    }

    // Allocate memory for the second array
    array2 = (char*)malloc(10 * sizeof(char));
    if (array2 == NULL) {
        printf("Memory allocation failed for array2.\n");
        free(array1); // Free the previously allocated memory
        return 1;
    }

    // Free the first and second arrays
    free(array1);
    free(array2);

    // Allocate memory for the third array
    array3 = (char*)malloc(20 * sizeof(char));
    if (array3 == NULL) {
        printf("Memory allocation failed for array3.\n");
        return 1;
    }

    // Free the third array
    free(array3);

    return 0;
}
