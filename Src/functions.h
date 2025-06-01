#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char FULLTILE = '#';
const char EMPTYTILE = '.';
const char BOMBTILE = '*';

char** createMinefield( int rowSize, int colSize, char tileType){

    char** matrixField = malloc(rowSize * sizeof(char*));
    
    for (int row = 0; row < rowSize; row++)
    {
        matrixField[row] = malloc(colSize * sizeof(int));

        for (int col = 0; col < colSize; col++)
        {
            matrixField[row][col] = tileType;
        }
        
    }

    return matrixField;
}

void printField(char** matrixField, int rowSize, int colSize){
    int rowCount = 0;
    
    printf("  | ");
    for (int colCount = 0; colCount < colSize; colCount++){ printf("%d ",colCount); }
    printf("\n");
    printf("--+");
    for (int colCount = 0; colCount < colSize; colCount++){ printf("--"); }
    printf("\n");
    
    for (int row = 0; row < rowSize; row++)
    {
        if(rowCount < rowSize){ printf("%d | ",rowCount++);}

        for (int col = 0; col < colSize; col++)
        {
            printf("%c ",matrixField[row][col]);
        }
        printf("\n");
    }
    
} 


char** addBombs(int bombsNum, int rowSize, int colSize){
    char** matrixBombField = createMinefield(rowSize, colSize, EMPTYTILE);
    srand(time(0));
    for (int i = 0; i < bombsNum; i++)
    {
        int row = rand() % rowSize;
        int col = rand() % colSize;
        while(matrixBombField[row][col] != '.'){
            row = rand() % rowSize;
            col = rand() % colSize;
        }
        matrixBombField[row][col] = BOMBTILE;
    }
        
    return matrixBombField;
}

char checkNeighbors(char** matrixField, int rowSize, int colSize, int currentRow, int currentCol){
    const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    int count = 0;

    for(int i = 0; i < 8; i++ ){
        int nRow = currentRow + dx[i];
        int nCol = currentCol + dy[i];

        if(nRow < 0 || nRow >= rowSize || nCol < 0 || nCol >= colSize)
            continue;
        
        if(matrixField[nRow][nCol] == BOMBTILE){
            count++;
        }
    }
    return count;
}

char** addNums(char** matrixField, int rowSize, int colSize){

    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if(matrixField[row][col] == '.'){
                matrixField[row][col] = '0' + checkNeighbors(matrixField, rowSize, colSize, row, col);
            }
        }
        
    }
    

    return matrixField;
}