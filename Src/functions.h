#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char FULLTILE = '#';
const char EMPTYTILE = '.';
const char BOMBTILE = '*';

void clearCMD(){
    printf("\e[1;1H\e[2J");
}

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

void printBoard(char** matrixField, int rowSize, int colSize){
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

char calNums(char** matrixField, int rowSize, int colSize, int currentRow, int currentCol){
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

char** checkNeighbours(char** matrixTop, char** matrixBot, int rowSize, int colSize, int currentRow, int currentCol){
    const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    if(matrixBot[currentRow][currentCol] == '0' && matrixTop[currentRow][currentCol] == FULLTILE){
        matrixTop[currentRow][currentCol] = matrixBot[currentRow][currentCol];
        for(int i = 0; i < 8; i++ ){
            int nRow = currentRow + dx[i];
            int nCol = currentCol + dy[i];
        
            if(nRow < 0 || nRow >= rowSize || nCol < 0 || nCol >= colSize)
                continue;
            
            checkNeighbours(matrixTop, matrixBot, rowSize, colSize, nRow, nCol);
            matrixTop[nRow][nCol] = matrixBot[nRow][nCol];
        }
    } 
    else if(matrixBot[currentRow][currentCol] == BOMBTILE && matrixTop[currentRow][currentCol] == FULLTILE){
        return matrixBot;
    }
    else matrixTop[currentRow][currentCol] = matrixBot[currentRow][currentCol];
    
    return matrixTop;
}



char** addNums(char** matrixField, int rowSize, int colSize){

    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if(matrixField[row][col] == '.'){
                matrixField[row][col] = '0' + calNums(matrixField, rowSize, colSize, row, col);
            }
        }
        
    }
    

    return matrixField;
}

char** addBombsAndNums(int bombsNum, int rowSize, int colSize){
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
    matrixBombField = addNums(matrixBombField, rowSize, colSize);
    
    return matrixBombField;
}

int winCon(char** matrixTop, char** matrixBot, int rowSize, int colSize, int bombsNum){
    int count;
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if(matrixTop[row][col] == FULLTILE){
                count++;
            }
        }
    }
    if(count > bombsNum){
        return 0;
    } else if (count == bombsNum){
        printBoard(matrixBot, rowSize, colSize);
        printf("Parabens voce ganhou!");
        return 1;
    } else
    printBoard(matrixBot, rowSize, colSize);
    printf("Voce perdeu!");
    return 1;
}

char** CheckMove(char** matrixTop, char** matrixBot, int rowSize, int colSize, int row, int col){
    if (matrixBot[row][col] != BOMBTILE){
        checkNeighbours(matrixTop, matrixBot, rowSize, colSize, row, col);
        return matrixTop;
    }
    return matrixBot;
}