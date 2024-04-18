#include <stdio.h>
#include <stdlib.h>

// Function to validate user input
int validateInput(int min, int max) {
    int input;
    while (1) {
        printf("Enter a number between %d and %d: ", min, max);
        if (scanf("%d", &input) != 1) {
            // If input is not a number
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else if (input < min || input > max) {
            // If input is out of range
            printf("Input out of range. Please enter a number between %d and %d.\n", min, max);
        } else {
            break; // Input is valid
        }
    }
    return input;
}

int main() {
    int height, width;

    // Prompt user for height and width
    printf("Enter the height of the game board: ");
    height = validateInput(1, 100); // Assuming a maximum height of 100

    printf("Enter the width of the game board: ");
    width = validateInput(1, 100); // Assuming a maximum width of 100

    // Allocate memory for the game board squares
    int *board = (int *)malloc(height * width * sizeof(int));
    if (board == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Output confirmation
    printf("Game board with %d rows and %d columns created.\n", height, width);

    // Free allocated memory
    free(board);

    return 0;
}
