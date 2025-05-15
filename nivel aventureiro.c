#include <stdio.h>

#define BOARD_SIZE 10
#define SHIP_SIZE 3
#define WATER 0
#define SHIP 3

// Inicializa o tabuleiro com água (0)
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = WATER;
}

// Verifica se é possível posicionar o navio sem ultrapassar bordas e sem sobrepor
int canPlaceShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, char direction[]) {
    for (int k = 0; k < SHIP_SIZE; k++) {
        int r = startRow;
        int c = startCol;

        if (direction[0] == 'h') c += k;
        else if (direction[0] == 'v') r += k;
        else if (direction[0] == 'd' && direction[1] == 'p') { r += k; c += k; }
        else if (direction[0] == 'd' && direction[1] == 's') { r += k; c -= k; }

        if (r >= BOARD_SIZE || r < 0 || c >= BOARD_SIZE || c < 0) return 0;
        if (board[r][c] != WATER) return 0;
    }
    return 1;
}

// Posiciona o navio na direção indicada
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, char direction[]) {
    for (int k = 0; k < SHIP_SIZE; k++) {
        int r = startRow;
        int c = startCol;

        if (direction[0] == 'h') c += k;
        else if (direction[0] == 'v') r += k;
        else if (direction[0] == 'd' && direction[1] == 'p') { r += k; c += k; }
        else if (direction[0] == 'd' && direction[1] == 's') { r += k; c -= k; }

        board[r][c] = SHIP;
    }
}

// Imprime o tabuleiro no console
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) printf("%2d", i);
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%2d", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    // Exemplo de posições (sem sobreposição)
    // Navio horizontal
    if (canPlaceShip(board, 1, 1, "h"))
        placeShip(board, 1, 1, "h");

    // Navio vertical
    if (canPlaceShip(board, 4, 4, "v"))
        placeShip(board, 4, 4, "v");

    // Navio diagonal principal
    if (canPlaceShip(board, 6, 1, "dp"))
        placeShip(board, 6, 1, "dp");

    // Navio diagonal secundária
    if (canPlaceShip(board, 0, 9, "ds"))
        placeShip(board, 0, 9, "ds");

    // Exibe o tabuleiro
    printf("Tabuleiro com 4 navios posicionados (horizontal, vertical, e diagonais):\n");
    printBoard(board);

    return 0;
}
