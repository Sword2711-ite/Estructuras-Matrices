//Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4 //<---limitar la matriz
#define COLUMNAS 4
int main() 
{
    int matriz[FILAS][COLUMNAS];
    int pares = 0;    // <---- Declaracion de variables
    int impares = 0;
    srand(time(NULL));
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++) 
        {
            matriz[i][j] = rand() % 10; // <---- ingresa numeros aleatorios
            printf("%d  ", matriz[i][j]);  // <---- Imprime la matriz
            if (matriz[i][j] % 2 == 0) pares++; // <---- Verifica si son pares o no
            else impares++;
        }
        printf("\n");
    }
    printf("\nCantidad de pares: %d", pares);
    printf("\nCantidad de impares: %d\n", impares);
    return 0;
}
