// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 4
int main() 
{
    int matrizA[FILAS][COLUMNAS];
	int matrizB[4][4];
	int matrizC[4][4];
    srand(time(NULL));
    printf("Matriz A:\n");
    for (int i = 0; i < FILAS; i++) 
	{
        for (int j = 0; j < COLUMNAS; j++)
		{
            matrizA[i][j] = rand() % 10;//<---LLenado de datos de la matriz A
            printf("%d  ", matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz B:\n");
    for (int i = 0; i < FILAS; i++) 
	{
        for (int j = 0; j < COLUMNAS; j++)
		{
            matrizB[i][j] = rand() % 10;//<---LLenado de datos de la matriz B
            printf("%d  ", matrizB[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz C:\n");
    for (int i = 0; i < FILAS; i++)
	{
        for (int j = 0; j < COLUMNAS; j++) 
		{
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];//<---resta de los valores de la matriz A y B por casillas
            //lo mismo del ejercicio 7 pero con un menos 
            printf("%d  ", matrizC[i][j]);//<---IMPRIMIR matriz C
        }
        printf("\n");
    }
    return 0;
}

