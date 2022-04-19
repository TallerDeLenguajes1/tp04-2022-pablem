/* Trabajo Práctio No4 - Juarez Palmieri */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *descripcionesTareas[] = {"Sacar la basura", "Imprimir reportes", "Regar las plantas", "Pedir delivery", "Ordenar la oficina"};

typedef struct
{
    int TareaID;       // Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;

int main()
{
    srand((int)time(NULL));
    rand();

    // char **descripciones; // vector con punteros a cada descripción
    Tarea **vectorTareas; // vector con punteros a struct tarea
    int nTareas;          // filas de ambos vectores

    char *buff = (char *)malloc(32 * sizeof(char));
    // Tarea *buffTarea = (Tarea *)malloc(sizeof(Tarea));

    printf("\nIngrese la cantidad de tareas a cargar: ");
    scanf("%d", &nTareas);

    vectorTareas = (Tarea **)malloc(nTareas * sizeof(Tarea *));

    for (int i = 0; i < nTareas; i++)
    {
        vectorTareas[i] = (Tarea *)malloc(sizeof(Tarea));
        vectorTareas[i]->TareaID = i;
        vectorTareas[i]->Descripcion = descripcionesTareas[rand() % 5];
        vectorTareas[i]->Duracion = rand() % 91 + 10; //(de 0 a 90) + 1
    }
    // free(buff);
    // free()

        return 0;
}