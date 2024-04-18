#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width;
    int* game_board;
    
    printf("Enter the height of the game board: ");
    scanf("%d", &height);
    
    printf("Enter the width of the game board: ");
    scanf("%d", &width);
    
    // Allocate memory for the game board
    game_board = (int*)malloc(height * width * sizeof(int));
    
    if (game_board == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Initialize the squares of the game board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            game_board[i * width + j] = (i + 1) * (j + 1);
        }
    }
    
    // Display the squares of the game board
    printf("Squares of the game board:\n");
    for (int k = 0; k < height * width; k++) {
        printf("%d ", game_board[k]);
    }
    
    // Free the allocated memory
    free(game_board);

    return 0;
}