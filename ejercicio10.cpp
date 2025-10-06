// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 3
int main() {
    int matrizA[FILAS][COLUMNAS];
    int matrizATrans[COLUMNAS][FILAS];
    srand(time(NULL));
    printf("Matriz A:\n");
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matrizA[i][j] = rand() % 10; // <--- Llenado matriz A
            printf("%2d  ", matrizA[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLUMNAS; j++)
            matrizATrans[j][i] = matrizA[i][j]; //<--- Transponer la matriz
    printf("\nMatriz A Transpuesta:\n");
    for (int i = 0; i < COLUMNAS; i++) 
    {
        for (int j = 0; j < FILAS; j++) 
            printf("%2d  ", matrizATrans[i][j]);// <--- Imprime la matriz Transpuesta
        printf("\n");
    }
    return 0;
}

