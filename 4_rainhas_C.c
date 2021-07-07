#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 4

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    // Verifica a linha
    for (i = 0; i < col; i++)
        if (board[row][i]) return false;
    // Verifica as diagonais
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return false;
    return true;
}

//A recursive utility problem to solve N queens problem.
bool solveNQUtil(int board[N][N], int col, int queens_position[N]) {

    if (col >= N){
    // Caso já tenha colocado todas rainhas
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            queens_position[i] = col;
            /* Chamada recursiva */
            if (solveNQUtil(board, col + 1, queens_position)){
                    return true;
            } else{
                board[i][col] = 0;
            }
        }
    }
    return false;
}

//Printa as posições das Rainhas
void printSolution(int queens_position[N]) {
    printf("Posicoes possiveis para rainha = [");
    for (int i = 0; i < N; i++) {
        printf("%d ", (queens_position[i]+1));
    }
    printf("]");
}

int main() {
    int board[N][N];
    int queens_position[N];
    for (int p = 0; p < N; p++){
        memset(board, 0, sizeof board);
        memset(queens_position, 0, sizeof queens_position);
        // Coloca uma rainha em cada linha da primeira coluna, teremos todos as solução para N = 4
        board[p][0] = 1;
        bool hasSolution;
        hasSolution = solveNQUtil(board, 1, queens_position);
        if(hasSolution){
            printSolution(queens_position);
            printf("\n");
        }
    }

    return 0;
}
