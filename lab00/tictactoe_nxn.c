#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define N 5
#define CELL_MAX (N * N)-1

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[N][N])
{
    int cell = 0;

    print_sep(N);
    for (int row = 0; row < N; ++row) {
        for (int column = 0; column < N; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(N);
    }
}

char get_winner(char board[N][N])
{
    char winner = '-';
    //  
        bool band;
        //Horizontal
        for(int i=0;i<N;i++){
            band = true;
            for(int j=0;j<(N-1);j++){
                if(board[i][j] != board[i][j+1]){
                    band = false;
                    break;
                }
            }
            if(band){
                winner = board[i][0];
                break;
            }
        }
        //Vertical
        for(int j=0;j<N;j++){
            band = true;
            for(int i=1;i<N;i++){
                if(board[i][j] != board[i-1][j]){
                    band = false;
                    break;
                }
            }
            if(band){
                winner = board[0][j];
                break;
            }
        }
        //Diagonals
            //primary
            band = true;
            for(int i=1;i<N;i++){
                if(board[i][i]!=board[i-1][i-1]){
                    band = false;
                    break;
                }
            }
            if(band) winner = board[0][0];
            //secondary
            band = true;
            int i=N-2,j=1;
            while(band && i>-1 && j<N){
                if(board[i][j] != board[i+1][j-1]){
                    band = false;
                    break;
                }
                if(!band) break;
                i--;
                j++;
            }
            if(band) winner = board[N-1][0];    
    //
    return winner;
}

bool has_free_cell(char board[N][N])
{
    bool free_cell = false;
    //
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='-'){
                    free_cell = true;
                }
            }
        }
    //
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    //init

    char board[N][N];

    //board padding

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = '-';  
        }
    }

    //game

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / N;
            int colum = cell % N;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
