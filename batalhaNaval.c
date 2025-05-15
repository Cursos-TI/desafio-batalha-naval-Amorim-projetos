#include <stdio.h>

#define BOARD_SIZE 10
#define SHIP_SIZE 3

// Função para inicializar o tabuleiro com água (0s)
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0; // Água é representada por 0
        }
    }
}

// Função para posicionar um navio na horizontal no tabuleiro
void placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    for (int j = col; j < col + SHIP_SIZE; j++) {
        board[row][j] = 3; // Partes do navio são representadas por 3
    }
}

// Função para posicionar um navio na vertical no tabuleiro
void placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    for (int i = row; i < row + SHIP_SIZE; i++) {
        board[i][col] = 3; // Partes do navio são representadas por 3
    }
}

// Função para exibir o tabuleiro no console
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // Números de coluna acima do tabuleiro
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // Números de linha à esquerda do tabuleiro
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]); // Imprime o conteúdo de cada célula
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    // Inicializa o tabuleiro com água (0s)
    initializeBoard(board);

    // Posiciona um navio horizontalmente (exemplo)
    int ship1_row = 2;
    int ship1_col = 3;
    placeHorizontalShip(board, ship1_row, ship1_col);

    // Posiciona um navio verticalmente (exemplo)
    int ship2_row = 5;
    int ship2_col = 7;
    placeVerticalShip(board, ship2_row, ship2_col);

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro com os navios posicionados:\n");
    printBoard(board);

    return 0;
}
