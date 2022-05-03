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
} Tarea; //Tarea es tipo tarea: "Ttarea"

struct Nodo {
    Tarea *T;
    struct Nodo *Siguiente;
};
typedef struct Nodo Tnodo;

Tarea * crearTarea(int );
Tnodo * crearNodo(Tarea *);
void insertarNodo(Tnodo **, Tarea *);
Tnodo * eliminarNodo(Tnodo *, int );//Elimina y devuelve el nodo siguiente
void mostrarLista(Tnodo *);
void liberarLista(Tnodo *);
void control(Tnodo *, Tnodo **);//si la tarea se ha realizado, la mueve a la segunda lista
void buscarID(Tnodo *);
void buscarPalabra(Tnodo *);


int main()
{
    srand((int)time(NULL));
    rand();

    Tnodo *pendientes = NULL; //lista con tareas pendientes
    Tnodo *realizadas = NULL; //lista con tareas realizadas

    int nTareas, id; 

    printf("\nIngrese la cantidad de tareas a realizar: ");
    scanf("%d", &nTareas);

    for (int i = 0; i < nTareas; i++) 
    {
        insertarNodo(&pendientes, crearTarea(i));        
    }
    printf("\nTareas generadas: \n");
    mostrarLista(pendientes);

    // FUNCION BUSCAR TAREAS
    buscarID(pendientes);
    buscarPalabra(pendientes);

    // FUNCION CONTROL REALIZADAS/PENDIENTES Y MOVER
    printf("\n");
    control(pendientes, &realizadas);

    printf("\nTareas por realizar: \n");
    mostrarLista(pendientes);
    printf("\nTareas realizadas: \n");
    mostrarLista(realizadas);

    // FUNCION LIBERAR MEMORIA
    liberarLista(pendientes);
    liberarLista(realizadas);

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

    if(*start == NULL) {
        nuevo->Siguiente = NULL;
    } else {
        nuevo->Siguiente = *start;
    }
    //sin if?) nuevo->siguiente = *start;
    *start = nuevo;
}

void buscarID(Tnodo *lista)
{
    int id;
    printf("\nBuscar - Ingrese nro de ID: ");
    scanf("%d", &id);
    while (lista != NULL) {
        if(lista->T->TareaID == id){
            printf("T%d - %s - Duración: %d\n", lista->T->TareaID, lista->T->Descripcion, lista->T->Duracion);
            break;
        }
        lista = lista->Siguiente;
    }
}

void buscarPalabra(Tnodo *lista)
{
    char *Buff;
    Buff = (char *)malloc(32*sizeof(char));
    printf("\nBuscar - Ingrese la palabra: ");
    fflush(stdin);
    gets(Buff);
    
    while (lista != NULL) {
        if(strstr(lista->T->Descripcion, Buff) != NULL){
            printf("T%d - %s - Duración: %d\n", lista->T->TareaID, lista->T->Descripcion, lista->T->Duracion);
        }
        lista = lista->Siguiente;
    }
    free(Buff);
}

void mostrarLista(Tnodo *lista)
{
    while (lista != NULL) {
        printf("T%d - %s - Duración: %d\n", lista->T->TareaID, lista->T->Descripcion, lista->T->Duracion);
        lista = lista->Siguiente;
    }
}

void liberarLista(Tnodo *lista)
{
    Tnodo *aux;
    while (lista != NULL) {
       free(lista->T->Descripcion);
       aux = lista;
       lista = lista->Siguiente;
       free(aux);
    }
}

void control(Tnodo *pendientes, Tnodo **realizadas)
{
    int respuesta; //toma 0 o 1 como respuesta si se realizaó la tarea o no
    Tnodo *aux = pendientes;
    
    while(aux != NULL){
        printf("Se realizó la tarea de %s? (0 / 1): ", aux->T->Descripcion);
        scanf("%d", &respuesta);
        if(respuesta) {
            insertarNodo(realizadas, aux->T);
            aux = eliminarNodo(pendientes, pendientes->T->TareaID);
        } else {
            aux = aux->Siguiente;
        }
    }
}

Tnodo * eliminarNodo(Tnodo *pendientes, int i)
{
    Tnodo *aux = pendientes;
    Tnodo *auxAnterior = pendientes;

    // if(aux->T->Descripcion == i) {//si el nodo a borrar es el primero
    //     pendientes = aux->Siguiente;//modificar cabecera, usar puntero doble
    //     free(aux);
    // }

    while (aux != NULL && aux->T->TareaID == i) {
        auxAnterior = aux;
        aux = aux->Siguiente;
    }
    if(aux!=NULL) {
        auxAnterior->Siguiente = aux->Siguiente;
        free(aux); 
    }
    return auxAnterior->Siguiente;
}