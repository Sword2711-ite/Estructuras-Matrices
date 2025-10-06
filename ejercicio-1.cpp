//Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
//SE LIMITA LA MATRIZ 
#define FILAS 4
#define COLUMNAS 4
int main() 
{
    int matriz[FILAS][COLUMNAS]; //SE DECLARA LA MATRIZ
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j] = 0; //<--SE LLENAN LOS ESPACIOS EN 0
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
