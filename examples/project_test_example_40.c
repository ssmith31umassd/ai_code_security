#include <stdio.h>
#include <stdlib.h>

typedef char board_square_t;

void die(const char *error) {
    fprintf(stderr, "Error: %s", error);
    exit(1);
}

// Reference:
// MITRE. "CWE-20: Improper Input Validation." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/20.html (retrieved Feb. 22, 2024).
#define MAX_DIM 100
/* board dimensions */

board_square_t *create2DBoard() {
    int m,n, error;
    board_square_t *board;
    printf("Please specify the board height: \n");
    error = scanf("%d", &m);
    if ( EOF == error ){
    die("No integer passed: Die evil hacker!\n");
    }
    printf("Please specify the board width: \n");
    error = scanf("%d", &n);
    if ( EOF == error ){
    die("No integer passed: Die evil hacker!\n");
    }
    if ( m > MAX_DIM || n > MAX_DIM ) {
    die("Value too large: Die evil hacker!\n");
    }
    board = (board_square_t*) malloc( m * n * sizeof(board_square_t));

    return board;
}
// end

int main(int argc, char **argv) {
    return 0;
}
