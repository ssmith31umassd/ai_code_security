#define MAX_DIM 100

char *board;

// ask user for board dimensions and initialize the 2D game board
void init_board() {
    int rows, cols;
    printf("Insert the number of rows: ");
    scanf("%d", &rows);
    printf("Insert the number of columns: ");
    scanf("%d", &cols);
    board = (char *)malloc(rows * cols * sizeof(char));
}

// print the game board
void print_board() {
    int rows, cols;
    printf("Insert the number of rows: ");
    scanf("%d", &rows);
    printf("Insert the number of columns: ");
    scanf("%d", &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", board[i * cols + j]);
        }
        printf("\n");
    }
}

// free the memory allocated for the game board
void free_board() {
    free(board);
}

void main() {
    init_board();
    print_board();
    free_board();
}