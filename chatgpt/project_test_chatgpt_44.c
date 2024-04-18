#include <stdio.h>

int main() {
    int array[4]; // Create an array of size 4
    int count = 0; // Counter to keep track of how many odd numbers are added
    
    // Iterate through odd numbers and add them to the array
    for (int i = 1; count < 4; i += 2) {
        array[count] = i;
        count++;
    }

    // Output the array elements
    printf("Array: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
