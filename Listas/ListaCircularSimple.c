#include <stdio.h>
#include <stdlib.h>
#define verdadero 1
#define falso 0

struct nodo_l{

	int dato;
	struct nodo_l *siguiente;
	struct nodo_l *anterior;
};
typedef struct nodo_l NODO_L;



/*
################################################################################################
  Nombre Función : Lista_vacia

  Descripción : Este módulo comprueba si hay elementos en la lista.

  Declaración : int Lista_vacia(int num_elementos);

  Parámetros :	-NODO_L *inicio: primer nodo.
 
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
  Nombre Función : Eliminar()

  Descripción : Este módulo elimina un nodo de la lista.

  Declaración : void Eliminar(NODO_L **inicio, NODO_L *p);

  Parámetros :	-NODO_L **inicio: primer nodo.

  				NODO_L *p: puntero al nodo que se desea eliminar.
 
 Valor de Retorno : esta función retorna void ó vacío.
#################################################################################################
*/
void Eliminar(NODO_L **inicio, NODO_L *p)
{
	NODO_L *previo;

	if (Lista_vacia(*inicio) == verdadero)	printf("Lista vacía\n");

	else{

		if(p == p->siguiente){
			free(p);
			*inicio = NULL;
		}
		else{

			if(*inicio == p)	*inicio = (*inicio)->siguiente;
			previo =*inicio;

			while(previo->siguiente != p){
				previo = previo->siguiente;
			}
			previo->siguiente = p->siguiente;
			free(p);

		}
	}
	
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

	if(Lista_vacia(inicio) == falso){
		p = inicio;

		do{					//Recorremos toda la lista.

			if(p->dato == valor) return p;	//Si el valor existe en algún nodo retornamos dicho nodo.
			p = p->siguiente;
		}while(p != inicio);
	}

	return NULL;
	printf("Valor no encontro\n");				
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

	if(Lista_vacia(inicio) == falso){
		p = inicio;

		do{//p != NULL;

			printf("Nodo %d con valor %d\n", i, p->dato);		//Hacer algo (p->dato);  REALIZAR LA MODIFICACIÓN .
			p = p->siguiente;
			i++;
		}
		while(p != inicio);
	}
}





/*
################################################################################################
  Nombre Función : crear_lista_vacia

  Descripción : Módulo que permite crear el primer nodo de la lista (apuntando a NULL). 

  Declaración : NODO_L* Crear_lista_vacia(NODO_L *inicio);

  Parámetros =>	-NODO_L *inicio: primer nodo.
 
 Valor de Retorno : esta función retorna un puntero a NODO_L.
#################################################################################################
*/
NODO_L* Crear_lista_vacia(NODO_L *inicio)
{
	inicio = malloc(sizeof(NODO_L ));   

	if(inicio == NULL) printf("\nError al reservar memoria dinámica.\n");
	else{

		inicio = NULL;		//Se hace apuntar el primer nodo a NULL una vez que se dispone de la memoria dinámica.
	}

	return inicio;
}




/*
################################################################################################
  Nombre Función : Insertar_despues_C()

  Descripción : Este módulo se encarga de introducir un nodo en la posición designada por p.

  Declaración : void Insertar_despues(NODO_L **inicio, NODO_L *p, int elemento);

  Parámetros :	-NODO_L *inicio: primer nodo de la lista.

  				-NODO_L *p: nodo que apunta a la posición de inserción.

  				-int elemento: dato que se introduce en el nuevo nodo.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_despues_C(NODO_L **inicio, NODO_L *p, int elemento)
{
	NODO_L *nuevo;

	nuevo = malloc(sizeof(NODO_L *));

	if( nuevo == NULL) printf("No hay memoria.\n");
	else{
		nuevo->dato = elemento;

		if (Lista_vacia(*inicio) == verdadero){
			
			nuevo->siguiente = nuevo;
			*inicio = nuevo;
		}
		else{
			nuevo->siguiente = p->siguiente;		//Si la lista no está vacía
			p->siguiente = nuevo;
		}

	}
}




/*
################################################################################################
  Nombre Función : Vaciar_lista()

  Descripción : Este módulo se encarga de recorrer todo la lista eliminando cada nodo a su paso.

  Declaración : void Vaciar_lista(NODO_L **inicio)

  Parámetros :	-NODO_L **inicio: puntero a la dirección de memoria del primer nodo de la lista.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Vaciar_lista(NODO_L **inicio){

	NODO_L *p;

	while(Lista_vacia(*inicio) != verdadero){

		if(*inicio == (*inicio)->siguiente){

			free(*inicio);
			*inicio == NULL;
		}
		else{
			p = (*inicio)->siguiente;
			(*inicio)->siguiente = p->siguiente;
			free(p);
		}
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

	printf("El nodo de la posición %d almacena un %d\n", i, p->dato);//TRATAR(P);   Hacer algo con dicho nodo.
}




/*
################################################################################################
  Nombre Función : Insertar_en_orden

  Descripción : Este módulo inserta en orden los elementos (no recoloca los que ya forman parte de la lista).

  Declaración : void Insertar_en_orden(NODO_L **inicio, int elemento);

  Parámetros :	-NODO_L *inicio: pasamos el primer nodo de la lista.

  				-int elemento: valor que se va a introducir en el nuevo nodo.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_en_orden(NODO_L **inicio, int elemento)
{
	NODO_L *nuevo,*p;

	nuevo = malloc(sizeof(NODO_L *));

	if( nuevo == NULL) printf("No hay memoria.\n");		//Reservamos memoria para el nuevo nodo.
	else{
		if(Lista_vacia(*inicio) == verdadero){			//Si la lista está vacía (creamos el primer nodo).

			nuevo->siguiente = nuevo;			//Al ser una lista circular nuevo apunta a sí mismo.
			nuevo->dato = elemento;				//Introducimos el valor en el nodo creado.
			*inicio = nuevo;					//Inicio apunta al primer nodo la lista (y por ahora único nodo).
		}
		else{
			p = *inicio;						//Situamos el puntero de referencia p al inicio de la lista.

			while( (p->siguiente != *inicio) && (p->dato < elemento)){	//Mientras no se encuentre un valor mayor a nuestro elemento

				p = p->siguiente;										//seguimos recorriendo la lista.
			}

			if(p->dato < elemento){			
				nuevo->dato = elemento;				//Definimos el valor de nuevo.
				nuevo->siguiente = p->siguiente;	//Enlazamos a nuevo con el primer nodo.
				p->siguiente = nuevo;				//Enlazamos a p con nuevo.
			}
			else{
				nuevo->dato = p->dato;				//Le damos el valor de p al nuevo nodo.
				nuevo->siguiente = p->siguiente;	//nuevo apunta a donde apunte p.
				p->dato = elemento;					//Le damos el nuevo valor (elemento) a p.
				p->siguiente = nuevo;				//El nodo p ahora apunta a nuevo.
			}
		}
	}
}


void main(){

	int i;
	NODO_L *inicio,*nuevo,*p;


	inicio = Crear_lista_vacia(inicio); 
	p=inicio;

	Insertar_despues_C(&inicio, p, 20);
	p = Buscar(inicio,20);

	Insertar_despues_C(&inicio, p, 100);
	p = Buscar(inicio,100);

	Insertar_despues_C(&inicio, p, 133);

	/*
	Insertar_en_orden(&inicio,1500);
	Insertar_en_orden(&inicio,25);
	Insertar_en_orden(&inicio,315);
	Insertar_en_orden(&inicio,157);
	Insertar_en_orden(&inicio,82);
	*/

	Recorrer_lista_pej_mostrar(inicio); 
	
}
