#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width;

    // Prompting user for the height and width of the game board
    printf("Enter the height of the game board: ");
    scanf("%d", &height);
    printf("Enter the width of the game board: ");
    scanf("%d", &width);

    // Dynamically allocating memory for the game board
    int *board = (int *)malloc(height * width * sizeof(int));
    if (board == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Initializing the squares of the board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // You can initialize the squares as needed
            board[i * width + j] = (i + 1) * (j + 1); // Example initialization
        }
    }

    // Printing the squares of the board (for demonstration)
    printf("Squares of the board:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d\t", board[i * width + j]);
        }
        printf("\n");
    }

    // Freeing the dynamically allocated memory
    free(board);

    return 0;
}
