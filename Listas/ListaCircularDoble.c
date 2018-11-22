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

		inicio = NULL;		//Se hace apuntar el primer nodo a NULL una vez que se deispone de la memoria dinámica.
	}

	return inicio;
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
  Nombre Función : Insertar_despues()

  Descripción : Este módulo se encarga de introducir un nodo en la posición designada por p.

  Declaración : void Insertar_despues(NODO_L **inicio, NODO_L *p, int elemento);

  Parámetros :	-NODO_L *inicio: primer nodo de la lista.

  				-NODO_L *p: nodo que apunta a la posición de inserción.

  				-int elemento: dato que se introduce en el nuevo nodo.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_despues(NODO_L **inicio, NODO_L *p, int elemento)
{
	NODO_L *nuevo;

	nuevo = malloc(sizeof(NODO_L *));

	if( nuevo == NULL) printf("No hay memoria.\n");
	else{
		nuevo->dato = elemento;

		if (Lista_vacia(*inicio) == verdadero){
			
			nuevo->siguiente = nuevo;
			nuevo->anterior = nuevo;
			*inicio = nuevo;
		}
		else{
			 nuevo->siguiente = p->siguiente;		//Si la lista no está vacía
			 nuevo->anterior = p;

			 p->siguiente->anterior = nuevo; 		//Redefinimos el enlace siguiente de p.									

			 p->siguiente = nuevo; 	// Le decimos 
		}
	}
}




/*
################################################################################################
  Nombre Función : Eliminar

  Descripción : Este módulo se encarga de borrar un nodo referenciado por la posición.

  Declaración : void Eliminar(NODO_L **inicio, NODO_L *p);

  Parámetros :	-NODO_L *inicio: pasamos el primer nodo de la lista.

  				-NODO_L *p: apunta al nodo que se va a eliminar.

 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Eliminar(NODO_L **inicio, NODO_L *p)
{
	if(Lista_vacia(*inicio) == verdadero)  printf("Error: lista vacía.\n");

	else{
		if(p == p->siguiente){

			free(p);
			*inicio = NULL;
		}  
		else{
			if(*inicio == p) *inicio = (*inicio)->siguiente;

			 p->siguiente->anterior = p->anterior;
			 p->anterior->siguiente = p->siguiente;
			 free(p);
		}
	}
}




/*
################################################################################################
  Nombre Función : Insertar_en_orden()

  Descripción : Este módulo se encarga de introducir un nodo en la posición designada por p.

  Declaración : void Insertar_en_orden(NODO_L **inicio, int elemento)

  Parámetros :	-NODO_L **inicio: puntero a la dirección de memoria del primer nodo de la lista.

  				-int elemento: dato que se introduce en el nuevo nodo.
 
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

			nuevo->dato = elemento;				//Introducimos el valor en el nodo creado.
			nuevo->anterior = nuevo;
			nuevo->siguiente = nuevo;			//Al ser una lista circular nuevo apunta a sí mismo.
			*inicio = nuevo;					//Inicio apunta al primer nodo la lista (y por ahora único nodo).
		}
		else{
			p = *inicio;						//Situamos el puntero de referencia p al inicio de la lista.

			while( (p->siguiente != *inicio) && (p->dato < elemento)){	//Mientras no se encuentre un valor mayor a nuestro elemento

				p = p->siguiente;										//seguimos recorriendo la lista.
			}

			if(p->dato < elemento)  nuevo->dato = elemento;   //Si el valor almacenado en p es menor que el que queremos introducir,
			else{											  //almacenamos nuestro valor en nuevo.
				nuevo->dato = p->dato;	
				p->dato = elemento;							  //De lo contrario p y nuevo intercambian valores.
			}

			nuevo->siguiente = p->siguiente;			// 
			nuevo->anterior = p;						//Definimos los enlaces que salen de nuevo.

			nuevo->anterior->siguiente = nuevo;			//
			nuevo->siguiente->anterior = nuevo;			//Definimos los enlaces de los nodos que apuntan a nuevo.
		}
	}
}




void main()
{
	NODO_L *inicio,*p;

	inicio = Crear_lista_vacia(inicio);

	p = inicio;

	Insertar_despues(&inicio, p,20);

	p = Buscar(inicio, 20);

	Insertar_despues(&inicio, p,100);
	/* 
	p = Buscar(inicio, 100);
	Insertar_despues(&inicio, p,101);
	p = Buscar(inicio, 101);
	Insertar_despues(&inicio, p,102);
	*/
	Insertar_en_orden(&inicio,150);
	Insertar_en_orden(&inicio,7);
	Insertar_en_orden(&inicio,3000);
	sInsertar_en_orden(&inicio,75);

	Recorrer_lista_pej_mostrar(inicio);
}