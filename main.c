#include "Src/functions.h"

// gcc -std=c99 -Wall -Werror -fsanitize=address .\main.c
int main(){
    int rowSize;
    int colSize;
    int bombsNum;
    printf("Fileiras: ");
    scanf("%d", &rowSize);
    printf("Colunas: ");
    scanf("%d", &colSize);
    printf("Bombas: ");
    scanf("%d", &bombsNum);

    //int rowSize = 9;
    //int colSize = 9;

    char** campoTesteTop = createMinefield(rowSize,colSize, FULLTILE);
    char** campoTesteBot = addBombs(bombsNum, rowSize, colSize);


    printField(campoTesteTop, rowSize, colSize);
    printf("\n");
    printField(campoTesteBot, rowSize, colSize);
    printf("\n");
    printField(addNums(campoTesteBot, rowSize, colSize), rowSize, colSize);
    

    return 0;
}