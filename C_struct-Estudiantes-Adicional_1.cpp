//Jean Carlo Lopez Torres
//24760859
#include <stdio.h>  
#include <stdlib.h>
struct Estudiante {  //se genera la estructura "Estudiante" que tiene tres campos 
    char nombre[50]; //guarda el nombre
    int edad;        //guarda la edad en un numero entero
    float promedio;  //guarda el promedio en un numero decimal
};
int main() {
    struct Estudiante estudiantes[3];  //Declara un arreglo de 3 estructuras Estudiante para almacenar datos de estudiantes
    int i;  //es una variable que se usara para contar
    FILE *archivo;  // Puntero para manejar un archivo de texto
    float sumaPromedios = 0.0;//Variable que acumula la suma de promedios y calcula el promedio general
    int indiceMejor = 0; //estudiante con el mejor promedio
    archivo = fopen("estudiantes.txt", "r");  // Abre el archivo 
    if (archivo != NULL) {  // verifica si el archivo existe
        printf("Cargando datos desde el archivo...\n");
        for (i = 0; i < 3; i++) {  // for para leer datos del archivo
            fscanf(archivo, "%s %d %f", estudiantes[i].nombre, &estudiantes[i].edad, &estudiantes[i].promedio);  // Lee nombre, edad y promedio desde el archivo
        }
        fclose(archivo);  // Cierra el archivo después de leer
        printf("Datos cargados exitosamente.\n\n");  // Confirma que los datos se cargaron
    } else {  // Si el archivo no existe
        printf("Archivo no existe. Ingresa los datos...\n");// Imprime mensaje en pantalla
        //se usa un for para ingresar los datos de los 3 estudiantes
        for (i = 0; i < 3; i++) {
            printf("Ingresa el nombre del estudiante %d: ", i + 1);// imprime en pantalla el mensaje
            scanf("%s", estudiantes[i].nombre); //Guarda el nombre ingresado por el usuario

            printf("Ingresa la edad del estudiante %d: ", i + 1);// imprime en pantalla el mensaje
            scanf("%d", &estudiantes[i].edad);  //Guarda la edad ingresado por el usuario

            printf("Ingresa el promedio del estudiante %d: ", i + 1);// imprime en pantalla el mensaje
            scanf("%f", &estudiantes[i].promedio); //Guarda el promedio ingresado por el usuario 
        }
    }
    // Calcular el promedio general del grupo
    for (i = 0; i < 3; i++) {  // Ciclo para sumar todos los promedios
        sumaPromedios += estudiantes[i].promedio;  // Acumula el promedio de cada estudiante
    }
    printf("Promedio general del grupo: %.2f\n\n", sumaPromedios / 3.0);  // Imprime el promedio general
    // Encontrar el estudiante con el mejor promedio
    for (i = 1; i < 3; i++) {  // Ciclo desde el segundo estudiante para compararlos
        if (estudiantes[i].promedio > estudiantes[indiceMejor].promedio) {
            indiceMejor = i;  // Actualiza el índice del mejor estudiante
        }
    }
    printf("Estudiante con el mejor promedio:\n");  // Imprime encabezado
    printf("Nombre: %s\n", estudiantes[indiceMejor].nombre);  // Imprime nombre del mejor
    printf("Edad: %d\n", estudiantes[indiceMejor].edad);  // Imprime edad del mejor
    printf("Promedio: %.2f\n\n", estudiantes[indiceMejor].promedio);  // Imprime promedio del mejor
    printf("Datos de los estudiantes:\n");  // Imprime en pantalla
    for (i = 0; i < 3; i++) {//ciclo para imprimir alumno pr alumno 
        printf("Estudiante %d:\n", i + 1); //identifica cual estudiante es el que se imprime
        printf("Nombre: %s\n", estudiantes[i].nombre);  //imprime nombre
        printf("Edad: %d\n", estudiantes[i].edad);  //imprime edad
        printf("Promedio: %.2f\n", estudiantes[i].promedio);  //imprime promedio
        printf("\n");
    } 
    // Guardar los datos en el archivo "estudiantes.txt"
    archivo = fopen("estudiantes.txt", "w");  // Abre el archivo en modo escritura
    if (archivo == NULL) {  // Si no se puede abrir el archivo
        printf("Error al abrir el archivo para guardar.\n");  // Imprime error
        exit(1);  // Sale del programa con código de error
    }
    for (i = 0; i < 3; i++) {  // for para escribir datos  en el archivo
        fprintf(archivo, "%s %d %.2f\n", estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].promedio);  //ingresa los datos de los alunos
    }
    fclose(archivo);  // Cierra el archivo después de escribir
    printf("Datos guardados en 'estudiantes.txt'.\n");  // Confirma que se guardaron
    return 0;
}
