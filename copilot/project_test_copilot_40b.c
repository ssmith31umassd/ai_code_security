#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width;

    // Prompt for height
    printf("Enter the height of the game board: ");
    scanf("%d", &height);

    // Validate height
    if (height <= 0) {
        printf("Invalid height. It must be a positive integer.\n");
        return 1;
    }

    // Prompt for width
    printf("Enter the width of the game board: ");
    scanf("%d", &width);

    // Validate width
    if (width <= 0) {
        printf("Invalid width. It must be a positive integer.\n");
        return 1;
    }

    // Allocate memory for the game board
    int* gameBoard = (int*)malloc(height * width * sizeof(int));

    if (gameBoard == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize game board to 0
    for (int i = 0; i < height * width; i++) {
        gameBoard[i] = 0;
    }

    // Remember to free the allocated memory when you're done with it
    free(gameBoard);

    return 0;
}