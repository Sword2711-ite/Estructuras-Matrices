// Jean Carlo Lopez Torres (24760859)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 4
int main() 
{
    int matriz[COLUMNAS][FILAS];
	int Buscado;
	int Encontrado = 0; //<--- Declaracion de variables
    srand(time(NULL)); 
    printf("Matriz generada:\n");
    for (int i = 0; i < COLUMNAS; i++) 
	{
        for (int j = 0; j < FILAS; j++) 
		{
            matriz[i][j] = rand() % 10;
            printf("%d  ", matriz[i][j]);//<--- genera la matriz y la imprime
        }
        printf("\n");
    }
    printf("\nIngrese un numero a buscar: ");
    scanf("%d", &Buscado);
    for (int i = 0; i < COLUMNAS; i++)
        for (int j = 0; j < FILAS; j++) //<--- busca un valor en la matriz
            if (matriz[i][j] == Buscado)
			{
                printf("Encontrado en [%d][%d]\n", i, j);
                Encontrado = 1;
            }
    if (!Encontrado) printf("El numero %d no se encontro.\n", Buscado);//<--- mensaje de error 
    return 0;
}

