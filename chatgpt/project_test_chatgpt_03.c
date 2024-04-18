#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_bytes;
    
    // Prompt the user for the number of bytes to copy
    printf("Enter the number of bytes to copy: ");
    scanf("%d", &num_bytes);
    
    // Dynamically allocate memory for the original char array
    char *original_array = (char *)malloc(num_bytes * sizeof(char));
    
    // Read input from stdin to the original char array
    printf("Enter input: ");
    fflush(stdin); // clear input buffer
    fgets(original_array, num_bytes + 1, stdin); // +1 to accommodate for null terminator
    
    // Allocate memory for the destination char array
    char *copied_array = (char *)malloc(num_bytes * sizeof(char));
    
    // Copy the specified number of bytes to the destination char array
    for (int i = 0; i < num_bytes; i++) {
        copied_array[i] = original_array[i];
    }
    
    // Null-terminate the copied array
    copied_array[num_bytes] = '\0';
    
    // Print the copied array
    printf("Copied array: %s\n", copied_array);
    
    // Free dynamically allocated memory
    free(original_array);
    free(copied_array);
    
    return 0;
}
