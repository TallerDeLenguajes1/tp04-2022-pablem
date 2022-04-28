/* Trabajo Práctio No4 - Juarez Palmieri */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *descripcionesTareas[] = {"Sacar la basura", "Imprimir reportes", "Regar las plantas", "Pedir delivery", "Ordenar la oficina"};

typedef struct {
    int TareaID;       // Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;

int main()
{
    srand((int)time(NULL));
    rand();

    Tarea **vectorTareas; //vector con los elementos punteros a struct tarea
    Tarea **tareasRealizadas;
    int nTareas; //filas de ambos vectores
    int respuesta; //toma 0 o 1 como respuesta si se realizaó la tarea o no 

    char *buff = (char *)malloc(64 * sizeof(char)); //variable auxiliar para copiar una frase del arreglo descripciones

    printf("\nIngrese la cantidad de tareas a cargar: ");
    scanf("%d", &nTareas);

    vectorTareas = (Tarea **)malloc(nTareas * sizeof(Tarea *));
    tareasRealizadas = (Tarea **)malloc(nTareas * sizeof(Tarea *));

    for (int i = 0; i < nTareas; i++) {
        tareasRealizadas[i] = NULL;
    }

    for (int i = 0; i < nTareas; i++) {

        vectorTareas[i] = (Tarea *)malloc(sizeof(Tarea));

        vectorTareas[i]->TareaID = i;
        vectorTareas[i]->Duracion = rand() % 91 + 10; //(de 0 a 90) + 1

        //campo descripción:
        strcpy(buff, descripcionesTareas[rand() % 5]);
        vectorTareas[i]->Descripcion = (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vectorTareas[i]->Descripcion, buff);
    }
    free(buff);

    for (int i = 0; i < nTareas; i++) {

        printf("Se realizó la tarea de %s? (0 / 1)\n", vectorTareas[i]->Descripcion);
        scanf("%d", &respuesta);

        if (respuesta) {
            tareasRealizadas[i] = vectorTareas[i];
            vectorTareas[i] = NULL;
        }
    }

    // FUNCION MOSTRAR TAREAS
    printf("Tareas por realizar: \n");
    for (int i = 0; i < nTareas; i++) {

        if (vectorTareas[i] != NULL)
            printf("\t%d) %s. \tDuración: %d.\n", i + 1, vectorTareas[i]->Descripcion, vectorTareas[i]->Duracion);
    }

    printf("\nTareas realizadas: \n");
    for (int i = 0; i < nTareas; i++) {

        if (tareasRealizadas[i] != NULL)
            printf("\t%d) %s. \tDuración: %d.\n", i + 1, tareasRealizadas[i]->Descripcion, tareasRealizadas[i]->Duracion);
    }

    // FUNCION LIBERAR MEMORIA
    for (int i = 0; i < nTareas; i++) {
        free(vectorTareas[i]->Descripcion);
        free(vectorTareas[i]);
    }
    for (int i = 0; i < nTareas; i++) {
        free(tareasRealizadas[i]->Descripcion);
        free(tareasRealizadas[i]);
    }
    free(vectorTareas);
    free(tareasRealizadas);

    return 0;
}