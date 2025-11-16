//Jean Carlo Lopez Torres
//24760859

#include <stdio.h>
#include <stdlib.h> 

struct Materia {  // genera la estructura "Materia"
    char nombre[30];     // guarda el nombre de la materia
    float calificacion;  // guarda la calificación de la materia
};

struct Estudiante { // genera la estructura "Estudiante"
    int matricula; // guarda la matricula, numero entero
    char nombre[50];// guarda el nombre, caracteres
    int edad;    // guarda la edad, numero entero
    float promedio; // guarda el promedio, tipo flotante
    struct Materia materias[3]; // tres materias por estudiante
};

int main() {
    struct Estudiante estudiantes[3]; 
    int numEstudiantes = 0;  // contador es estudiantes
    int opcion;  // guarda la seleccion de el menu
    FILE *archivo;  // Puntero a FILE para manejar el archivo de texto "estudiantes.txt"
    int i, j;  // i para estudiantes y j para materias

    archivo = fopen("estudiantes.txt", "r");  // Abre el archivo en modo lectura
    if (archivo != NULL) {  // Si el archivo existe
        printf("Cargando datos desde el archivo...\n");  // Imprime mensaje de carga
        fscanf(archivo, "%d", &numEstudiantes);  // Lee el número de estudiantes guardados en el archivo
        if (numEstudiantes > 3) numEstudiantes = 3;
        for (i = 0; i < numEstudiantes; i++) {  // Ciclo para leer datos de cada estudiante
            fscanf(archivo, "%d %s %d %f", &estudiantes[i].matricula, estudiantes[i].nombre, &estudiantes[i].edad, &estudiantes[i].promedio);  // matrícula, nombre, edad y promedio
            for (j = 0; j < 3; j++) {  // leer las 3 materias de cada estudiante
                fscanf(archivo, "%s %f", estudiantes[i].materias[j].nombre, &estudiantes[i].materias[j].calificacion);  //nombre y calificación de cada materia
            }
        }
        fclose(archivo);  // Cierra el archivo después de leer
        printf("Datos cargados exitosamente. Estudiantes cargados: %d\n\n", numEstudiantes);
    } else {  // Si el archivo no existe, inicia con 0 estudiantes
        printf("Archivo no encontrado. lista vacía.\n\n");  // Imprime lista vacía
    }

    do {  // Inicia el bucle para el menu
        printf("Menu de opciones:\n");  // Imprime en pantalla
        printf("1. Nuevo estudiante\n");  // guardar info de nuevos estudiantes
        printf("2. Mostrar todos\n");  //mostrar todos los estudiantes
        printf("3. Buscar por matricula\n");  // buscar un estudiante por matrícula
        printf("4. Salir\n");  //salir del programa
        printf("Selecciona una opcion: ");  // imprime en pantalla
        scanf("%d", &opcion);  // Lee la opción seleccionada por el usuario

        switch (opcion) {  //switch para cada opccion
            case 1:  // Opción 1: Nuevo estudiante
                if (numEstudiantes < 3) {  // Verifica si hay menos de 3 estudiantes
                    printf("Capturando estudiante %d:\n", numEstudiantes + 1);  // Imprime mensaje en pantalla
                    printf("Ingresa matricula: ");  // Pide la matrícula
                    scanf("%d", &estudiantes[numEstudiantes].matricula);  // Lee la matrícula
                    printf("Ingresa nombre: ");  // Pide el nombre
                    scanf("%s", estudiantes[numEstudiantes].nombre);  // Lee el nombre
                    printf("Ingresa edad: ");  // Pide la edad
                    scanf("%d", &estudiantes[numEstudiantes].edad);  // Lee la edad
                    printf("Ingresa promedio: ");  // Pide el promedio
                    scanf("%f", &estudiantes[numEstudiantes].promedio);  // Lee el promedio
                    for (j = 0; j < 3; j++) {  // for para capturar las 3 materias
                        printf("Ingresa nombre de materia %d: ", j + 1);  // Pide nombre de la materia
                        scanf("%s", estudiantes[numEstudiantes].materias[j].nombre);  // Lee nombre de la materia
                        printf("Ingresa calificacion de materia %d: ", j + 1);  // Pide la calificación
                        scanf("%f", &estudiantes[numEstudiantes].materias[j].calificacion);  // Lee la calificación
                    }
                    numEstudiantes++;  // incrementa en uno los estudiantes
                    printf("Estudiante capturado exitosamente.\n\n");  // imprime en pantalla
                } else {  // no hay espacio para un nuevo estudiante, ya hay 3
                    printf("Maximo de estudiantes alcanzado (3).\n\n");  // Imprime en pantalla
                }
                break;

            case 2:  // Opción 2: Mostrar todos
                if (numEstudiantes == 0) {  // si esta vacio
                    printf("No hay estudiantes para mostrar.\n\n");  // Imprime mensaje 
                } else {  // Si hay estudiantes
                    printf("Datos de todos los estudiantes:\n");  // Imprime en pantalla
                    for (i = 0; i < numEstudiantes; i++) {  // Ciclo para mostrar los estudiantes uno a un
                        printf("Estudiante %d:\n", i + 1);  // Imprime número de el estudiante
                        printf("Matricula: %d\n", estudiantes[i].matricula);  // Imprime la matrícula
                        printf("Nombre: %s\n", estudiantes[i].nombre);  // Imprime el nombre
                        printf("Edad: %d\n", estudiantes[i].edad);  // Imprime la edad
                        printf("Promedio: %.2f\n", estudiantes[i].promedio);  // Imprime el promedio
                        printf("Materias:\n");  // Imprime en pantalla
                        for (j = 0; j < 3; j++) {  // for para mostrar cada materia
                            printf("  %s: %.2f\n", estudiantes[i].materias[j].nombre, estudiantes[i].materias[j].calificacion);  // Imprime nombre y calificación de la materia
                        }
                        printf("\n"); 
                    }
                    int indiceMejor = 0;  //estudiante con mejor promedio
                    for (i = 1; i < numEstudiantes; i++) {  // for para comparar promedios
                        if (estudiantes[i].promedio > estudiantes[indiceMejor].promedio) {  // Si el promedio actual es mayor
                            indiceMejor = i;  // Actualiza 
                        }
                    }
                    printf("Estudiante con el mejor promedio:\n");  // Imprime en pantalla
                    printf("Matricula: %d\n", estudiantes[indiceMejor].matricula);  // Imprime matrícula del mejor estudiante
                    printf("Nombre: %s\n", estudiantes[indiceMejor].nombre);  // Imprime nombre del mejor estudiante
                    printf("Edad: %d\n", estudiantes[indiceMejor].edad);  // Imprime edad del mejor estudiante
                    printf("Promedio: %.2f\n", estudiantes[indiceMejor].promedio);  // Imprime promedio del mejor estudiante
                    printf("Materias:\n");  // Imprime materias del mejor estudiante
                    for (j = 0; j < 3; j++) {  // fr para mostrar materias del mejor
                        printf("  %s: %.2f\n", estudiantes[indiceMejor].materias[j].nombre, estudiantes[indiceMejor].materias[j].calificacion);  // Imprime cada materia
                    }
                    printf("\n");
                }
                break;

            case 3:  // Opción 3: Buscar por matrícula
                if (numEstudiantes == 0) { 
                    printf("No hay estudiantes para buscar.\n\n");  // Imprime mensaje vacío
                } else {  // Si hay estudiantes
                    int matriculaBuscar;  // Variable para la matrícula a buscar
                    printf("Ingresa la matricula a buscar: ");  // Pide matrícula
                    scanf("%d", &matriculaBuscar);  // Lee la matrícula
                    int encontrado = 0;
                    for (i = 0; i < numEstudiantes; i++) {  // for para buscar en la lista
                        if (estudiantes[i].matricula == matriculaBuscar) {  // Si coincide la matrícula
                            printf("Estudiante encontrado:\n");  // Imprime mensaje de encontrado
                            printf("Matricula: %d\n", estudiantes[i].matricula);  // Imprime matrícula
                            printf("Nombre: %s\n", estudiantes[i].nombre);  // Imprime nombre
                            printf("Edad: %d\n", estudiantes[i].edad);  // Imprime edad
                            printf("Promedio: %.2f\n", estudiantes[i].promedio);  // Imprime promedio
                            printf("Materias:\n");  // Imprime materias
                            for (j = 0; j < 3; j++) {  // for para mostrar materias
                                printf("  %s: %.2f\n", estudiantes[i].materias[j].nombre, estudiantes[i].materias[j].calificacion);  // Imprime cada materia
                            }
                            encontrado = 1;  // Marca como encontrado
                            break;
                        }
                    }
                    if (!encontrado) {  // Si no se encontró
                        printf("Estudiante con matricula %d no encontrado.\n\n", matriculaBuscar);  // Imprime mensaje de no encontrado
                    } else {  // Si se encontró
                        printf("\n");
                    }
                }
                break;

            case 4:  // Opción 4: Salir
                printf("Saliendo del programa...\n");  // Imprime en pantalla
                break;

            default:  // Opción inválida
                printf("Opcion invalida. Intenta de nuevo.\n\n");  // no selecciono una opccion
                break;
        }
    } while (opcion != 4);  // Repite el menú hasta que se seleccione salir

    // Guardar todos los datos en el archivo "estudiantes.txt" antes de salir
    archivo = fopen("estudiantes.txt", "w");  // Abre el archivo en modo escritura
    if (archivo == NULL) {  // Si no se puede abrir
        printf("Error al abrir el archivo para guardar.\n");  // Imprime error
        exit(1);
    }
    fprintf(archivo, "%d\n", numEstudiantes);  // Escribe el número de estudiantes al inicio
    for (i = 0; i < numEstudiantes; i++) {  // Ciclo para escribir cada estudiante
        fprintf(archivo, "%d %s %d %.2f\n", estudiantes[i].matricula, estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].promedio);  // Escribe datos 
        for (j = 0; j < 3; j++) {  // Ciclo para escribir cada materia
            fprintf(archivo, "%s %.2f\n", estudiantes[i].materias[j].nombre, estudiantes[i].materias[j].calificacion);  // Escribe nombre y calificación
        }
    }
    fclose(archivo);  // Cierra el archivo
    printf("Datos guardados en 'estudiantes.txt'.\n");  // Confirma guardado

    return 0;  // Retorna 0 para indicar éxito
}  