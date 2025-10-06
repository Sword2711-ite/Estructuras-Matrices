//Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#define FILAS 4  //<---limitar la matriz
#define COLUMNAS 4
int main() 
{
    int matriz[FILAS][COLUMNAS];
    printf("Ingrese 16 numeros:\n");
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++) 
        {
            scanf("%d", &matriz[i][j]);// <--- ingresar numeros
        }
    }
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++) 
        {
            printf("%d  ", matriz[i][j]);// <--- Imprimir resultado
        }
        printf("\n");
    }
    return 0;
}
