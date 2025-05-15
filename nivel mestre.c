#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 10
#define SHIP 3
#define WATER 0
#define ABILITY 5
#define SKILL_SIZE 5 // As matrizes de habilidade serão 5x5

// Função para inicializar o tabuleiro
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = WATER;
}

// Função para posicionar manualmente alguns navios
void placeShips(int board[BOARD_SIZE][BOARD_SIZE]) {
    board[1][1] = SHIP;
    board[1][2] = SHIP;
    board[1][3] = SHIP;

    board[4][5] = SHIP;
    board[5][5] = SHIP;
    board[6][5] = SHIP;

    board[7][1] = SHIP;
    board[8][2] = SHIP;
    board[9][3] = SHIP;

    board[3][9] = SHIP;
    board[4][8] = SHIP;
    board[5][7] = SHIP;
}

// Gera matriz de habilidade em formato de cone (aponta para baixo)
void generateCone(int skill[SKILL_SIZE][SKILL_SIZE]) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (j >= (SKILL_SIZE - 1) / 2 - i && j <= (SKILL_SIZE - 1) / 2 + i)
                skill[i][j] = 1;
            else
                skill[i][j] = 0;
        }
    }
}

// Gera matriz de habilidade em formato de cruz
void generateCross(int skill[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (i == center || j == center)
                skill[i][j] = 1;
            else
                skill[i][j] = 0;
        }
    }
}

// Gera matriz de habilidade em formato de octaedro (losango)
void generateOctahedron(int skill[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (abs(i - center) + abs(j - center) <= center)
                skill[i][j] = 1;
            else
                skill[i][j] = 0;
        }
    }
}

// Sobrepõe uma matriz de habilidade ao tabuleiro principal
void applySkillToBoard(int board[BOARD_SIZE][BOARD_SIZE], int skill[SKILL_SIZE][SKILL_SIZE], int originRow, int originCol) {
    int offset = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            int r = originRow + i - offset;
            int c = originCol + j - offset;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && skill[i][j] == 1) {
                if (board[r][c] == WATER) // não sobrescreve navios
                    board[r][c] = ABILITY;
            }
        }
    }
}

// Função para exibir o tabuleiro com legenda
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Habilidade\n\n");
    for (int i = 0; i
