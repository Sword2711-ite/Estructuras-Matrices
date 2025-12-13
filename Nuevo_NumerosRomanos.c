//Jean Carlo Lopez Torres 24760859
#include <stdio.h>
#include <string.h> //biblioteca para el manejo de cadenas

// Funcion auxiliar, convierte un caracter a su valor equivalente en numeros romanos
int roman_to_int(char x) {
    switch (x) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            printf("Caracteres en minusculas o no valido: %c\n", x); //Si el caracter no tiene valor como numero romano lo marca invalido
            return 0;  
    }
}

// Funcion principal, convierte una cadena romana a su equivalente arabigo
int romano_a_arabico(const char *romano) 
{
    int total = 0; //variable para la acumulacion del valor
    int len = strlen(romano); //convierte la longitud de los caracteres en un valor numerico
    int repe = 1;
    int i = 0;
    for (i; i < len; i++)
    {
        int actual = roman_to_int(romano[i]); //evalua el caracter actual
        int siguiente = (i + 1 < len) ? roman_to_int(romano[i + 1]) : 0;

        if (i > 0 && romano[i] == romano[i - 1])
        {
            if (romano[i] == 'V' || romano[i] == 'L' || romano[i] == 'D')
            {
                printf("El caracter '%c' no puede repetirse\n", romano[i]); //CONDICION DE NO REPETICION
                return 0;
            }

            repe++;
            if (repe > 3)
            {
                printf("No se puede repetir un caracter mas de 3 veces\n"); //REPETICION MAX 3 VECES
                return -1;
            }
        }
        else
        {
            repe = 1;
        }

        if (actual < siguiente)
        {
            total -= actual; // Caso de resta
        } 
        else 
        {
            total += actual; // Caso de suma
        }
    }
    return total; //devuelve el total
}

int main() 
{
    char numero_romano[100];

    printf("Numeros romanos a arabigos\n");
    printf("Introduce un numero romano: ");
    scanf("%s", numero_romano); //ingreso de datos

    printf("El numero arabigo equivalente es: %d\n",
           romano_a_arabico(numero_romano));

    return 0;
}

