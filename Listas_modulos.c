
#include <stdio.h>
#include <stdlib.h>



struct Nodo_lista{						    	//Definición de la estructura que actuará como nodo en la lista.
	int valor;
	struct Nodo_lista *siguiente;			//Puntero al siguiente nodo de la lista. 
};
typedef struct Nodo_lista NODO_L;



/*
################################################################################################
  Nombre Funcion : crear_lista

  Descripcion : Módulo que permite crear el primer nodo de la lista (apuntando a NULL). 

  Declaracion : void crear_lista();

  Parametros =>	SIN PARÁMETROS.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void crear_lista()
{
	NODO_L *inicio;

	inicio = malloc(sizeof(NODO_L *));   

	if(inicio == NULL) printf("\nError al reservar memoria dinámica.\n");
	else{

		inicio = NULL;		//Se hace apuntar el primer nodo a NULL una vez que se deispone de la memoria dinámica.
	}
}



/*
################################################################################################
  Nombre Funcion : insertar_después

  Descripcion : Permite la inserción de un nuevo nodo después de la posición a la que apunta  el 
  				nodo *p en la lista.

  Declaracion : void insertar_despues(NODO_L **inicio, NODO_L *p, int elemento);

  Parametros :	-NODO_L **inicio: pasamos el primer nodo de la lista por "referencia".
				
				-NODO_L *p: puntero a un nodo existente, actúa como referencia al nuevo nodo.

				-int elemento: valor del nuevo nodo incorporado a la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void insertar_despues(NODO_L **inicio, NODO_L *p, int elemento)
{

}


void main(){

}