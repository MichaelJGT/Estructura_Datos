/*
	Tabulado empleado al editar
		Tab Size: 4
*/

#include <stdio.h>
#include <stdlib.h>
#define verdadero 1
#define falso 0



struct Nodo_lista{						    	//Definición de la estructura que actuará como nodo en la lista.
	int dato;
	struct Nodo_lista *siguiente;			//Puntero al siguiente nodo de la lista. 
};
typedef struct Nodo_lista NODO_L;




/*
################################################################################################
  Nombre Función : crear_lista_vacia

  Descripción : Módulo que permite crear el primer nodo de la lista (apuntando a NULL). 

  Declaración : NODO_L* Crear_lista_vacia(NODO_L *inicio);

  Parámetros =>	-NODO_L *inicio: primer nodo.
 
 Valor de Retorno : esta función retorna un puntero a NODO_L.
#################################################################################################
*/
NODO_L* Crear_lista(NODO_L *inicio)
{
	inicio = malloc(sizeof(NODO_L *));   

	if(inicio == NULL) printf("\nError al reservar memoria dinámica.\n");
	else{

		inicio = NULL;		//Se hace apuntar el primer nodo a NULL una vez que se deispone de la memoria dinámica.
	}

	return inicio;
}




/*
################################################################################################
  Nombre Función : Lista_vacia

  Descripción : Este módulo comprueba si hay elementos en la lista.

  Declaración : int Lista_vacia(int num_elementos);

  Parámetros :	-NODO_L *inicio: primer 
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Lista_vacia(NODO_L *inicio)
{
	if (inicio == NULL) return verdadero;

	else return falso; 
}




/*
################################################################################################
  Nombre Función : insertar_después

  Descripción : Permite la inserción de un nuevo nodo después de la posición a la que apunta  el 
  				nodo *p en la lista.

  Declaración : void insertar_despues(NODO_L **inicio, NODO_L *p, int elemento);

  Parámetros :	-NODO_L **inicio: pasamos el primer nodo de la lista por "referencia".
				
				-NODO_L *p: puntero a un nodo existente, actúa como referencia al nuevo nodo.

				-int elemento: valor del nuevo nodo incorporado a la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_despues(NODO_L **inicio, NODO_L *p, int elemento)
{
	NODO_L *nuevo;

	if( (nuevo = malloc(sizeof (NODO_L*)) ) == NULL ) printf("No hay memoria\n"); //creación de memoria dinámica.
	else{
		nuevo->dato = elemento;					//se introduce el valor en el nuevo nodo.

		if( Lista_vacia(*inicio) == verdadero){  //Si la lista está vacía el nuevo nodo apunta a NULL.
			*inicio = nuevo;
			nuevo->siguiente = NULL;
		}
		else{
			nuevo->siguiente = p->siguiente;     //Si ya hay nodos implementados en la lista apuntamos el nuevo nodo al elemento que 
			p->siguiente = nuevo;				//esté apuntando "p" y "p" pasa a apuntar al nuevo nodo.
		}
	}
}




/*
################################################################################################
  Nombre Función : Eliminar

  Descripción : Elimina un nodo de la lista teniendo como referencia su posición.

  Declaración : void Eliminar(NODO_L **inicio, NODO_L *p);

  Parámetros :	-NODO_L **inicio: pasamos el primer nodo de la lista por "referencia".
				
				-NODO_L *p: puntero a un nodo existente, actúa como referencia al nuevo nodo.

				-int elemento: valor del nuevo nodo incorporado a la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Eliminar(NODO_L **inicio, NODO_L *p)
{
	NODO_L *previo;

	if( Lista_vacia(*inicio) == verdadero)  printf("Error: lista vacía.\n");

	else{
		previo = *inicio;

		while(previo->siguiente != p)   //Se recorre la lista desde el inicio hasta encontrar 
		{
			previo = previo->siguiente;
		}
		previo->siguiente = p->siguiente;							//el nodo que se quiera eliminar.
	}

	free(p);
}




/*
################################################################################################
  Nombre Función : Buscar

  Descripción : Busca un nodo en la lista tomando como referencia el valor que almacena.

  Declaración : NODO_L* Buscar(NODO_L *inicio, int valor);

  Parámetros :	-NODO_L *inicio: pasamos el primer nodo de la lista.
				
				-int valor: valor que almacena el nodo(dato).
 
 Valor de Retorno : esta función retorna un puntero a NODO_L.
#################################################################################################
*/
NODO_L* Buscar(NODO_L *inicio, int valor)
{
	NODO_L *p;

	p = inicio;

	while(p != NULL){					//Recorremos toda la lista.

		if(p->dato == valor) return p;	//Si el valor existe en algún nodo retornamos dicho nodo.
		p = p->siguiente;
	}

	return NULL;				
}




/*
################################################################################################
  Nombre Función : Eliminar_valor

  Descripción : Elimina un nodo de la lista teniendo como referencia su valor.

  Declaración : void Eliminar_valor(NODO_L **inicio, int valor);

  Parámetros :	-NODO_L **inicio: pasamos el primer nodo de la lista por "referencia".

				-int valor: valor que se quiere eliminar.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Eliminar_valor(NODO_L **inicio, int valor)
{
	NODO_L *p;

	p = Buscar(*inicio, valor);

	if (p == NULL) printf("El valor no forma parte de la lista.\n");

	else Eliminar(inicio, p);		//Si encontramos el nodo con el valor que buscamos eliminamos dicho nodo.
}




/*
################################################################################################
  Nombre Función : Recorrer_lista

  Descripción : Este módulo sirve para aplicar una modificación a todos los nodos de la lista.

  Declaración : void Recorrer_lista(NODO_L *inicio);

  Parámetros :	-NODO_L *inicio: pasamos el primer nodo de la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Recorrer_lista_pej_mostrar(NODO_L *inicio)
{
	NODO_L *p;
	int i=1;

	p = inicio;

	while(p != NULL){

		printf("Nodo %d con valor %d\n", i, p->dato);		//Hacer algo (p->dato);  REALIZAR LA MODIFICACIÓN .
		p = p->siguiente;
		i++;
	}
}




/*
################################################################################################
  Nombre Función : Recorrer_lista

  Descripción : Este módulo sirve para aplicar una modificación a todos los nodos de la lista.

  Declaración : void Recorrer_lista(NODO_L *inicio);

  Parámetros :	-NODO_L *inicio: pasamos el primer nodo de la lista.

  				-int i: posición del nodo al que se accede.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Acceder_nodo(NODO_L *inicio, int i)
{
	NODO_L *p;
	int j;

	p = inicio;
	j = 0;

	while(j < i){
		p = p->siguiente;
		j++;
	}

	//TRATAR(P);   Hacer algo con dicho nodo.
}




/*
################################################################################################
  Nombre Función : Vaciar_lista

  Descripción : Este módulo se encarga de borrar todos los nodos la lista generada.

  Declaración : void Vaciar_lista(NODO_L **inicio);

  Parámetros :	-NODO_L *inicio: pasamos el primer nodo de la lista.

 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Vaciar_lista(NODO_L **inicio)
{
	NODO_L *p;

	while( Lista_vacia(*inicio) == falso ){

		p = (*inicio)->siguiente;
		free(inicio);
		*inicio = p;
	}
}




/*
################################################################################################
  Nombre Función : insertar_en_orden

  Descripción : Permite la inserción de un nuevo nodo en función del campo clave escogido.

  Declaración : void Insertar_en_orden(NODO_L **inicio, int elemento);

  Parámetros :	-NODO_L **inicio: pasamos el primer nodo de la lista por "referencia".

				-int elemento: valor del nuevo nodo incorporado a la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_en_orden(NODO_L **inicio, int elemento)
{
	NODO_L *nuevo;
	NODO_L *p_anterior, *p_siguiente;

	if( (nuevo = malloc(sizeof(NODO_L)) ) == NULL ) printf("No hay memoria\n"); //Reservamos memoria para el nuevo nodo.
	else{
		nuevo->dato = elemento;			//Introducimos el valor en el campo correspondiente del nuevo nodo.
		p_anterior = NULL;				
		p_siguiente = *inicio;			//situamos LOS PUNTEROS P al comienzo de la lista (los dos punteros, uno al NULL inicial y otro a inicio).

		while( (p_siguiente != NULL) && (p_siguiente->dato < elemento) ){  //mientras no se encuentre un dato mayor al nuestro,recorremos la lista.

			p_anterior = p_siguiente;		
			p_siguiente = p_siguiente->siguiente;	//Avanzamos los punteros de referencia una posición en la lista por vuelta del bucle.
		}

		nuevo->siguiente = p_siguiente;	
		//Nótese que si no se encuentra un dato mayor al nuestro, el puntero de referencia p_siguiente apuntará a NULL y p_anterior al último nodo.

		if(p_siguiente == *inicio) *inicio = nuevo;
		else{
			p_anterior->siguiente = nuevo;		//Una vez encontrado el elemento mayor al nuestro, el nuevo nodo se incorpora delante del nodo que contiene dicho dato mayor.
		}										//De no encontrar uno mayor, se situará como último nodo de la lista.
	}

}	




/*
################################################################################################
  Nombre Función : Ordenacion_seleccion_Lsimples

  Descripción : Ordena la lista con el método de Selección Directa.

  Declaración : void Ordenacion_seleccion_Lsimples(NODO_L **inicio);

  Parámetros :	-NODO_L **inicio: pasamos el primer nodo de la lista por "referencia".
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Ordenacion_seleccion_Lsimples(NODO_L **inicio)
{
	NODO_L *orden_i, *orden_f;
	NODO_L *no_orden_i;
	NODO_L *p_min, *p_min_prev, *q, *q_prev;

	if(Lista_vacia(*inicio) == verdadero){

		printf("La lista está vacía, no se puede ordenar.\n");
		exit(0);
	}
	
	orden_i = NULL;
	orden_f = NULL;
	no_orden_i = *inicio;

	while(no_orden_i->siguiente != NULL){	//Se busca el menor elemento de la lista no ordenada.
		
		p_min_prev = NULL;
		p_min = no_orden_i;

		q_prev = no_orden_i;
		q = no_orden_i->siguiente;

		while(q != NULL){

			if(q->dato < p_min->dato){

				p_min_prev = q_prev;
				p_min = q;
			}

			//Se avanza un nodo en la lista no ordenada.

			q_prev = q;
			q = q->siguiente;
		}

		//Se desconecta de la lista no ordenada.

		if(p_min_prev != NULL){

			p_min_prev->siguiente = p_min->siguiente;
		}

		if(p_min == no_orden_i){

			no_orden_i = no_orden_i->siguiente;
		}

		//Se conecta a la lista ordenada.

		if(orden_i == NULL){

			orden_i = p_min;
		}
		else{
			orden_f->siguiente = p_min;
		}

		orden_f = p_min;

		p_min->siguiente = NULL;
	}

	//Se enlaza a la lista ordenada el último nodo.

	orden_f->siguiente = no_orden_i;

	*inicio = orden_i;
}


void main(){

	NODO_L *inicio;
	NODO_L *p;
	NODO_L *L;

	inicio = Crear_lista(inicio); //Creación de la lista vacía.

/* 
	Tras la creación del primer nodo de la lista con la función mencionada 
arriba, ya podemos proceder con la implementación de los diferentes módulos 
según las necesidades del consumidor.

	He aquí un ejemplo:
*/


	Insertar_despues(&inicio,inicio,5);    //Inserción del primer nodo con valor(dato) 5.

	p = inicio;

	Insertar_despues(&inicio, p,761);

	Insertar_despues(&inicio, p,10);

	Insertar_despues(&inicio, p,361);

	Insertar_despues(&inicio, p, 51);

	Insertar_despues(&inicio, p,1661);

	Ordenacion_seleccion_Lsimples(&inicio);

	Recorrer_lista_pej_mostrar(inicio);	  //Módulo modificado para mostrar el valor
										  // de los nodos de la lista.


}
