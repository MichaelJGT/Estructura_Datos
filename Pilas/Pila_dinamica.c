#include <stdio.h>
#include <stdlib.h>

#define verdadero 1
#define falso 0


struct nodo_p{

	int dato;
	struct nodo_p *enlace;
};
typedef struct nodo_p NODO_P;




/*
################################################################################################
  Nombre Función : Pila_vacia

  Descripción : Comprueba si la pila está vacía. 

  Declaración : int Pila_vacia(NODO_P *cima);

  Parámetros =>	-NODO_P *cima: primer nodo accesible de la pila.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Pila_vacia(NODO_P *cima)
{
	if(cima == NULL) return verdadero;
	else return falso;
}




/*
################################################################################################
  Nombre Función : Apilar

  Descripción : Introduce un elemento en la pila. 

  Declaración : void Apilar(int elemento, NODO_P **cima);

  Parámetros =>	-int elemento: valor que se introduce en la pila.

  				-NODO_P *cima: primer nodo accesible de la pila.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
void Apilar(int elemento, NODO_P **cima)
{
	NODO_P *nuevo;

	nuevo = malloc(sizeof(NODO_P));

	if(nuevo == NULL) printf("No hay memoria.\n");
	else{

		nuevo->dato = elemento;
		nuevo->enlace = *cima;
		*cima = nuevo;
	}
}




/*
################################################################################################
  Nombre Función : Desapilar

  Descripción : Elimina el correspondiente elemento de la pila. 

  Declaración : int Desapilar(int *elemento, NODO_P **cima);

  Parámetros =>	-int *elemento: valor que se quita de la pila.
  
  				-NODO_P **cima: primer nodo accesible de la pila.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Desapilar(int *elemento, NODO_P **cima)
{
	NODO_P *nodo;

	if(Pila_vacia(*cima) == verdadero){

		printf("Pila vacía, no se puede desapilar.\n");
		return falso;
	}
	else{
		*elemento = (*cima)->dato;
		nodo = (*cima)->enlace;
		free(*cima);
		*cima = nodo;
		return verdadero;
	}
}




/*
################################################################################################
  Nombre Función : Valor_cima

  Descripción : comprueba el valor que se encuentra en la cima (el ultimo que ha entrado).

  Declaración : int Valor_cima(int *elemento, NODO_P *cima);

  Parámetros =>	-int *elemento: valor que se quita de la pila.
  
  				-NODO_P *cima: primer nodo accesible de la pila.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Valor_cima(int *elemento, NODO_P *cima)
{
	if(Pila_vacia(cima) == verdadero){

		printf("La pila está vacía.\n");
		return falso;
	}
	else {
		*elemento = cima->dato;
		return verdadero;
	}
}





/*
################################################################################################
  Nombre Función : Eliminar

  Descripción : elimina el valor que se encuentra en la cima (el ultimo que ha entrado).

  Declaración : void Eliminar(NODO_P **cima);

  Parámetros =>	-NODO_P *cima: primer nodo accesible de la pila.
 
 Valor de Retorno : esta función retorna void ó vacio.
#################################################################################################
*/
void Eliminar(NODO_P **cima)
{
	int elemento;

	while(Pila_vacia(*cima) == falso){

		Desapilar(&elemento, cima);
	}
}




/*
################################################################################################
  Nombre Función : Crear_pila

  Descripción : Módulo que permite crear el primer nodo de la lista (apuntando a NULL). 

  Declaración : NODO_P* Crear_pila(NODO_P *cima);

  Parámetros =>	-NODO_P *cima: primer nodo accesible de la pila.
 
 Valor de Retorno : esta función retorna un puntero a NODO_P.
#################################################################################################
*/
NODO_P* Crear_pila(NODO_P *cima)
{
	cima = malloc(sizeof(NODO_P *));   

	if(cima == NULL) printf("\nError al reservar memoria dinámica.\n");
	else{

		cima = NULL;		//Se hace apuntar el primer nodo a NULL una vez que se deispone de la memoria dinámica.
	}

	return cima;
}






/*
################################################################################################
  Nombre Función : Recorrer_pila

  Descripción : Este módulo sirve para aplicar una modificación a todos los nodos de la lista.

  Declaración : void Recorrer_pila_pej_mostrar(NODO_P *inicio);

  Parámetros :	-NODO_P *cima: pasamos el primer nodo de la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Recorrer_pila_pej_mostrar(NODO_P *cima)
{
	NODO_P *p;
	int i=1;

	p = cima;

	while(p != NULL){

		printf("Posición %d con valor %d\n", i, p->dato);		//Hacer algo (p->dato);  REALIZAR LA MODIFICACIÓN .
		p = p->enlace;
		i++;
	}
}



void main()
{
	NODO_P *cima,*pila;
	int elemento;

	cima = Crear_pila(cima);

	Apilar(5, &cima);
	Apilar(25, &cima);
	Apilar(15357, &cima);
	Apilar(155, &cima);

	//Desapilar(&elemento,&cima);
	Recorrer_pila_pej_mostrar(cima);
}