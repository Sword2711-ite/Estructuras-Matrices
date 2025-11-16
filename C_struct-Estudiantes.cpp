//Jean Carlo Lopez Torres
//24760859

#include <stdio.h> 
struct Estudiante {  //se genera la estructura "Estudiante" que tiene tres campos 
    char nombre[50]; //guarda el nombre
    int edad;        //guarda la edad en un numero entero
    float promedio;  //guarda el promedio en un numero decimal
};
int main() {
    struct Estudiante estudiantes[3];
    int i;  //es una variable que se usara para contar
    //se usa un ciclo for para pedir los datos de los 3 estudiantes
    for (i = 0; i < 3; i++) {
        printf("Ingresa el nombre del estudiante %d: ", i + 1);// imprime en pantalla el mensaje
        scanf("%s", estudiantes[i].nombre); //Guarda el nombre ingresado por el usuario
        printf("Ingresa la edad del estudiante %d: ", i + 1);// imprime en pantalla el mensaje
        scanf("%d", &estudiantes[i].edad);  //Guarda la edad ingresado por el usuario
        printf("Ingresa el promedio del estudiante %d: ", i + 1);// imprime en pantalla el mensaje
        scanf("%f", &estudiantes[i].promedio); //Guarda el promedio ingresado por el usuario 
    }
    printf("\nDatos de los estudiantes:\n");  // Imprime en pantalla
    for (i = 0; i < 3; i++) {//ciclo para imprimir alumno pr alumno 
        printf("Estudiante %d:\n", i + 1); //identifica cual estudiante es el que se imprime
        printf("Nombre: %s\n", estudiantes[i].nombre);  //imprime nombre
        printf("Edad: %d\n", estudiantes[i].edad);  //imprime edad
        printf("Promedio: %.2f\n", estudiantes[i].promedio);  //imprime promedio
        printf("\n");
    } 
    return 0;
}
