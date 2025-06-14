#include "Src/functions.h"

// gcc -std=c99 -Wall -Werror -fsanitize=address .\main.c
int main(){
    int rowSize;
    int colSize;
    int bombsNum;
    int row;
    int col;
    printf("Fileiras: ");
    scanf("%d", &rowSize);
    printf("Colunas: ");
    scanf("%d", &colSize);
    printf("Bombas: ");
    scanf("%d", &bombsNum);

    //int rowSize = 9;
    //int colSize = 9;

    char** matrixTesteTop = createMinefield(rowSize,colSize, FULLTILE);
    char** matrixTesteBot = addBombsAndNums(bombsNum, rowSize, colSize);

    while (winCon(matrixTesteTop, matrixTesteTop, rowSize, colSize, bombsNum) == 0)
    {
        clearCMD();
        //printBoard(matrixTesteBot, rowSize, colSize);
        //printf("\n");
        printBoard(matrixTesteTop, rowSize, colSize);
        printf("Escolha a fileira: ");
        scanf("%d", &row);
        printf("Escolha a coluna: ");
        scanf("%d", &col);
        matrixTesteTop = CheckMove(matrixTesteTop, matrixTesteBot, rowSize, colSize, row, col);
        
    }
    
    

    return 0;
}