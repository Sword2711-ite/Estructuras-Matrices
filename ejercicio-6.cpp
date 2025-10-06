// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 4
int main() 
{
    int matriz[FILAS][COLUMNAS];
    int sumaFila;              
    int sumaColumna[COLUMNAS] = {0}; 
    srand(time(NULL)); 
    for (int i = 0; i < FILAS; i++) 
    {
        sumaFila = 0; // <--- inicializa la variable de conteo
        for (int j = 0; j < COLUMNAS; j++) 
        {
            matriz[i][j] = rand() % 10; 
            printf("%2d  ", matriz[i][j]);
            sumaFila += matriz[i][j];// <--- suma fila valor por valor 
            sumaColumna[j] += matriz[i][j];
        }
        printf("| Suma de fila %d = %d\n", i + 1, sumaFila); // <--- imprime suma correcta por fila
    }
    printf("\nSuma por columnas:\n");
    for (int j = 0; j < COLUMNAS; j++) 
    {
        printf("Columna %d = %d\n", j + 1, sumaColumna[j]); // <--- imprime suma por columna
    }
    return 0;
}

