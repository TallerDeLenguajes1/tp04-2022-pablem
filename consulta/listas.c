#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Tnodo
{
	int valor;    
	struct Tnodo *siguiente;
}typedef Tnodo;

Tnodo * CrearNodo( );
void CrearNodoV2(Tnodo **);
void main(){

  srand(time(NULL));
  
  Tnodo *start2;
  Tnodo *start1;
  start1 =CrearNodo();
  CrearNodoV2(&start2);
  printf("start1 %d",start1->valor);
  printf("start2 %d",start2->valor);
  
  getchar();
}

Tnodo * CrearNodo()
{
	Tnodo * NNodo; 
    NNodo= (Tnodo *) malloc (sizeof(Tnodo));
	NNodo->valor = rand() % 99;
	NNodo->siguiente = NULL;
	return NNodo;
}

void CrearNodoV2(Tnodo ** Nodo)
{
	Tnodo * NNodo; 
    NNodo= (Tnodo *) malloc (sizeof(Tnodo));
	NNodo->valor = rand() % 99;
	NNodo->siguiente = NULL;
	
    *Nodo=NNodo;
}
