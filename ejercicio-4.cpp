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
    int suma=0;
    float promedio=0;
    srand(time(NULL));
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++) 
        {
            matriz[i][j] = rand() % 10; // <---- ingresa numeros aleatorios
            printf("%d  ", matriz[i][j]);  // <---- Imprime la matriz
            suma=suma+ matriz[i][j]; // <---- Suma los numeros de la matriz
        }
        printf("\n");
    }
    promedio=suma/(FILAS*COLUMNAS);// <---- hace un promedio
    printf("Suma total: %d", suma);
    printf("\nPromedio: %.2f\n", promedio);// <---- Imprime los resultados
    return 0;
}
