// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 4
int main() 
{
    int matriz[FILAS][COLUMNAS];
    int maximo = 0;
    int minimo = 99;
    int filaMaxima = 0, columnaMaxima = 0; // <--- coordenadas del número máximo
    int filaMinima = 0, columnaMinima = 0; // <--- coordenadas del número mínimo
    srand(time(NULL));
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j] = rand() % 100;  // Números aleatorios del 0 al 99
            printf("%2d  ", matriz[i][j]); 
            if (matriz[i][j] > maximo) 
			{
                maximo = matriz[i][j];// <---Verificar si el valor actual es el nuevo maximo
                filaMaxima = i;
                columnaMaxima = j;
            }
            if (matriz[i][j] < minimo)
			{
                minimo = matriz[i][j];// <---Verificar si el valor actual es el nuevo mínimo
                filaMinima = i;
                columnaMinima = j;
            }
        }
        printf("\n");
    }
    printf("maximo de: %d en [%d][%d]\n", maximo,columnaMaxima + 1 ,filaMaxima + 1 );
    printf("minimo de: %d en [%d][%d]\n", minimo,columnaMinima + 1 ,filaMinima + 1 );
    return 0;
}

