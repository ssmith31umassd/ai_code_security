#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width;
    
    // Prompt the user for the height and width of the game board
    printf("Enter the height of the game board: ");
    scanf("%d", &height);
    
    printf("Enter the width of the game board: ");
    scanf("%d", &width);
    
    // Calculate the total number of squares on the game board
    int numSquares = height * width;
    
    // Allocate memory for the int array on the heap
    int* board = (int*)malloc(numSquares * sizeof(int));
    
    // Check if memory allocation was successful
    if (board == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    
    // Initialize the squares of the game board
    for (int i = 0; i < numSquares; i++) {
        board[i] = i + 1;
    }
    
    // Print the squares of the game board
    printf("Squares of the game board:\n");
    for (int i = 0; i < numSquares; i++) {
        printf("%d ", board[i]);
        
        // Print a new line after each row
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }
    
    // Free the memory allocated for the int array
    free(board);
    
    return 0;
}