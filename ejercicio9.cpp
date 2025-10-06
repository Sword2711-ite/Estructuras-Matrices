// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int matrizA[2][3];
    int matrizB[3][2];//<---- Generar matrices compatibles para multiplicar
    int matrizC[2][2] = {0}; 
    srand(time(NULL));
    printf("Matriz A:\n");
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            matrizA[i][j] = rand() % 10; //<---- Llenado matrizA
            printf("%2d  ", matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz B:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 2; j++)
        {
            matrizB[i][j] = rand() % 10; //<---- Llenado matrizB 
            printf("%2d  ", matrizB[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];// <---Multiplicación de la matriz A*B resulta matrizC
            }
        }
    }
    printf("\nMatriz C (A x B):\n");
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            printf("%3d  ", matrizC[i][j]);//<---- Imprimir matrizC
        }
        printf("\n");
    }
    return 0;
}


