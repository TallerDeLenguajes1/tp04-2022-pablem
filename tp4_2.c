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

struct Nodo {
    Tarea *T;
    struct Nodo *Siguiente;
};

typedef struct Nodo Tnodo;

Tarea * crearTarea(int );
Tnodo * crearNodo(Tarea *);
void insertarNodo(Tnodo **, Tarea *);


int main()
{
    srand((int)time(NULL));
    rand();

    Tnodo **pendientes = NULL; //lista con tareas pendientes
    Tnodo **realizadas = NULL; //lista con tareas realizadas

    int nTareas; 
    int respuesta; //toma 0 o 1 como respuesta si se realizaó la tarea o no 

    printf("\nIngrese la cantidad de tareas a cargar: ");
    scanf("%d", &nTareas);

    for (int i = 0; i < nTareas; i++) {

        insertarNodo(pendientes, crearTarea(i));        

    //CONTROL REALIZADAS/PENDIENTES
    }

    // FUNCION MOSTRAR TAREAS
    printf("Tareas por realizar: \n");
    for (int i = 0; i < nTareas; i++) {

        // if (vectorTareas[i] != NULL)
        printf("\t%d) %s. \tDuración: %d.\n", i + 1, pendientes[i]->T->Descripcion, pendientes[i]->T->Duracion);
    }

    // FUNCION LIBERAR MEMORIA
    for (int i = 0; i < nTareas; i++) {
        free(pendientes[i]->T->Descripcion);
        free(pendientes[i]->T);
    }
    // for (int i = 0; i < nTareas; i++) {
    //     free(tareasRealizadas[i]->Descripcion);
    //     free(tareasRealizadas[i]);
    // }

    return 0;
}

Tarea * crearTarea(int i)
{
    char *buff = (char *) malloc(64 * sizeof(char));
    Tarea *T = (Tarea *) malloc(sizeof(Tarea));

    T->TareaID = i;
    T->Duracion = rand() % 91 + 10; //(de 0 a 90) + 1
    //campo descripción:
    strcpy(buff, descripcionesTareas[rand() % 5]);
    T->Descripcion = (char *) malloc((strlen(buff)+1)*sizeof(char));
    strcpy(T->Descripcion, buff);
    free(buff);

    return T;
}

Tnodo * crearNodo(Tarea *T) 
{
    Tnodo *nuevo = (Tnodo*) malloc(sizeof(Tnodo));
    nuevo->T = T;
    nuevo->Siguiente = NULL;

    return nuevo;
}

void insertarNodo(Tnodo **start, Tarea *T)
{
    Tnodo *nuevo = crearNodo(T);
    nuevo->Siguiente = *start; //error
    *start = nuevo;
}