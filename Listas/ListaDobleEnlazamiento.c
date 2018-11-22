/*
	Este archivo recoge los módulos necesarios para manejar las Listas
doblemente enlazadas. Algunas funciones empleadas para las Listas lineales 
simples son reutilizadas en este archivo. 
 
 	Dichas funciones son:	- int Lista_vacia(NODO_L *inicio);
 							- void Recorrer_lista_pej_mostrar(NODO_L *inicio);
 							- void Acceder_nodo(NODO_L *inicio, int i);
 							- NODO_L* Buscar(NODO_L *inicio, int valor);
 							- void Vaciar_lista(NODO_L **inicio);

 	Tabulado empleado en esta edición (Tab size: 4).

*/

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
			
			*inicio = nuevo;
			nuevo->anterior = NULL;
			nuevo->siguiente = NULL;
		}
		else{
			nuevo->siguiente = p->siguiente;		//Si la lista no está vacía
			nuevo->anterior = p;

			if(p->siguiente != NULL){
			  p->siguiente->anterior = nuevo; 		//Redefinimos el enlace siguiente de p.
			}									

			p->siguiente = nuevo; 	// Le decimos 
		}
	}
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

	while(p != NULL){//;

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

	printf("El nodo de la posición %d almacena un %d\n", i, p->dato);//TRATAR(P);   Hacer algo con dicho nodo.
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
		free(*inicio);
		*inicio = p;
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
		if(p == *inicio)  *inicio = (*inicio)->siguiente;

		if(p->anterior != NULL)  p->anterior->siguiente = p->siguiente;

		if(p->siguiente != NULL)  p->siguiente->anterior = p->anterior;
	}

	free(p);
}




/*
################################################################################################
  Nombre Función : Insertar_antes()

  Descripción : Este módulo se encarga de introducir un nodo antes de la posición designada por p.

  Declaración : void Insertar_despues(NODO_L **inicio, NODO_L *p, int elemento);

  Parámetros :	-NODO_L *inicio: primer nodo de la lista.

  				-NODO_L *p: nodo que apunta a la posición de inserción.

  				-int elemento: dato que se introduce en el nuevo nodo.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_antes(NODO_L **inicio, NODO_L *p, int elemento){

	NODO_L *nuevo;

	nuevo = malloc(sizeof(NODO_L *));

	if( nuevo == NULL) printf("No hay memoria.\n");		//Reservamos memoria para el nuevo nodo.
	else{
		nuevo->dato = elemento;				//Introducimos el valor en el campo correspondiente del nuevo nodo.

		if (Lista_vacia(*inicio) == verdadero){
			
			*inicio = nuevo;		//Si la lista está vacía el primer nodo es el introducido, por lo tanto será a donde apunte inicio.
			nuevo->anterior = NULL;
			nuevo->siguiente = NULL;
		}
		else{
			nuevo->siguiente = p;		//Si la lista no está vacía introducimos el nodo antes de la posición referenciada por p (lo enlazamos con p).	

			if(p->anterior != NULL){				//Si p NO es el primer nodo de la lista.

			  p->anterior->siguiente = nuevo; 		//El nodo siguiente al nodo que estaba DELANTE de p, será el nuevo nodo (lo enlazamos con nuevo).
			  nuevo->anterior = p->anterior;		//Enlazamos nuevo con el nodo anterior a p.
			}									
			else {									// Si P ES EL PRIMER NODO.
				*inicio = nuevo;					//El inicio ahora será el nuevo nodo.
				nuevo->anterior = NULL;				//Lo enlazamos por delante con NULL.
			}

			p->anterior = nuevo; 	// Le decimos a p que el nodo que ahora está delante es el nodo nuevo.
			
		}
	}
}




/*
################################################################################################
  Nombre Función : Insertar_en_orden()

  Descripción : Introduce un nodo en función del orden de los campos clave.

  Declaración : void Insertar_en_orden(NODO_L **inicio, int elemento)

  Parámetros :	-NODO_L **inicio: puntero al primer nodo de la lista.

  				-int elemento: dato que se introduce en el nuevo nodo.
 
 Valor de Retorno : esta función retorna Void ó vacío.
#################################################################################################
*/
void Insertar_en_orden(NODO_L **inicio, int elemento)
{
	NODO_L *nuevo;
	NODO_L *p_anterior,*p_siguiente;

	nuevo = malloc(sizeof(NODO_L));

	if( nuevo == NULL ) printf("No hay memoria\n");		//Reservamos memoria para el nuevo nodo.
	else{
		nuevo->dato = elemento;			//Introducimos el valor en el campo correspondiente del nuevo nodo.
		p_anterior= NULL;
		p_siguiente = *inicio;			//situamos LOS PUNTEROS P al comienzo de la lista (los dos punteros, uno al NULL inicial y otro a inicio).

		while( (p_siguiente != NULL) && (p_siguiente->dato < elemento))	//mientras no se encuentre un dato mayor al nuestro,recorremos la lista.
		{
			p_anterior = p_siguiente;
			p_siguiente = p_siguiente->siguiente;	//Avanzamos los punteros de referencia una posición en la lista por vuelta del bucle.
		}

		nuevo->siguiente = p_siguiente; //El siguiente nodo al nuevo será el que contenga el campo->dato mayor al nuesrto.
		nuevo->anterior = p_anterior;	//El nodo anterior a nuevo será el mayor de todos los datos menores a nuevo->dato.

		//Nótese que si no se encuentra un dato mayor al nuestro, nodo de referencia p_siguiente apuntará a NULL y p_anterior al último nodo.

		if(p_siguiente != NULL) p_siguiente->anterior = nuevo; 

		if(p_anterior != NULL) p_anterior->siguiente = nuevo; //Si nuevo se introduce antes del final de la lista definimos los enlaces que apuntan a nuevo.

		if(p_siguiente == *inicio) *inicio = nuevo; //Si se introduce al principio de la lista redefinimos la posición inicio como el nodo nuevo.
	}

}




/*
EJEMPLOS DE IMPLEMENTACIÓN DE LAS FUNCIONES.
*/
void main()
{
	int i;
	NODO_L *inicio,*nuevo,*p;


	inicio = Crear_lista_vacia(inicio); //Creando el primer nodo que apunta a NULL.

	p = inicio;							//p es n puntero a un nodo, empleado para insertar,eliminar...nodos.

	Insertar_despues(&inicio, p, 20); 	//insertamos un nodo despues del inicio con valor 20. 

	p = Buscar(inicio, 20);			//Apuntamos "p" al último nodo introducido(con valor 20).

	Insertar_despues(&inicio,p,100);

	p = Buscar(inicio, 100);

	for(i=0;i<=5;i++){

		Insertar_despues(&inicio, p, i);  //Creación de 5 nodos con valor, "i".

		p = Buscar(inicio, i);
	}
	
	Recorrer_lista_pej_mostrar(inicio);  //Mostramos la lista generada hasta el momento.

	p= Buscar(inicio, 20);		//Buscamos la posición del nodo con valor 20 y guardamos su posicion en p. 

	Eliminar(&inicio, p);		//Ahora ya podemos eliminar el primer nodo.

	printf("\n-------------Eliminamos el primer Nodo--------------\n\n");

	Recorrer_lista_pej_mostrar(inicio);

	printf("\n---------Insertamos en la primera posición de la lista un 500----------\n\n");

	//Ahora metemos otro nodo con valor 100 en la primera posición.

	p = Buscar(inicio,100);
	Insertar_antes(&inicio,p,500);

	Recorrer_lista_pej_mostrar(inicio);

	printf("\n--------------Vaciamos la lista-------------\n\n");


	Vaciar_lista(&inicio);
	Recorrer_lista_pej_mostrar(inicio);

	printf("\n--------------Con Insertar antes-------------\n\n");

	//inicio = Crear_lista_vacia(inicio); //Creando el primer nodo que apunta a NULL.

	Insertar_antes(&inicio, inicio, 20);

	p = Buscar(inicio,20);
	Insertar_antes(&inicio, p, 100);

	//p = Buscar(inicio,100);
	Insertar_antes(&inicio, p, 333);

	//Recorrer_lista_pej_mostrar(inicio);

/*
	Insertar_en_orden(&inicio,20);

	Insertar_en_orden(&inicio,3);

	Insertar_en_orden(&inicio,415);

	Insertar_en_orden(&inicio,81);

	Insertar_en_orden(&inicio,15);
/*/
	Recorrer_lista_pej_mostrar(inicio); 

}