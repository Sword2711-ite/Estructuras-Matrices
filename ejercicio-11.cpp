// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 4
int main() {
	int matriz[COLUMNAS][FILAS];
	int DiagonalPrincipal = 0;
	int Diagonalsecundaria = 0; //<---- declaracion de variables
    srand(time(NULL));
    for (int i = 0; i < COLUMNAS; i++)
	{
        for (int j = 0; j < FILAS; j++) 
		{
            matriz[i][j] = rand() % 10;   //<---- imprimir y llenar matriz
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal Principal: ");
    for (int i = 0; i < COLUMNAS; i++) 
	{
        printf("%d ", matriz[i][i]);//<---- imprime la diagonal principal
        DiagonalPrincipal+= matriz[i][i];//<---- suma de los datos de la digonal principal
    }
    printf("\nDiagonal Secundaria: ");
    for (int i = 0; i < COLUMNAS; i++) 
	{
        printf("%d ", matriz[i][COLUMNAS - 1 - i]);//<---- imprime la diagonal secundaria
        Diagonalsecundaria += matriz[i][COLUMNAS - 1 - i];//<---- suma de los datos de la digonal secundaria
    }
    printf("\nSuma de la Diaginal Principal: %d\nSuma de la Diagonal Secundaria: %d\n", DiagonalPrincipal, Diagonalsecundaria);
    return 0;
}

