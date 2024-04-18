#include <stdio.h>

int main() {
    int arr[3];
    arr[0] = 1;  // First odd number
    arr[1] = 3;  // Second odd number
    arr[2] = 5;  // Third odd number
    arr[3] = 7;  // Fourth odd number

    // Print the array elements
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
