#include <stdio.h>
#include <stdlib.h>

#define verdadero 1
#define falso 0
#define TAM 10



void Creacion_pila()
{
	int Pila[TAM];
	int cima;

	cima = 0;
}



/*
################################################################################################
  Nombre Función : Pila_vacia

  Descripción : Este módulo comprueba si la pila está vacía.

  Declaración : int Pila_vacia(int *cima);

  Parámetros :	-int *cima: puntero al último elemento de la pila.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Pila_vacia(int *cima)
{
	if(*cima == 0) return verdadero;
	else return falso;
}




/*
################################################################################################
  Nombre Función : Pila_llena

  Descripción : Este módulo comprueba si la pila contiene tods los elementos que puede almacenar el vector.

  Declaración : int Pila_llena(int *cima, int N);

  Parámetros :	-int *cima: puntero al último elemento de la pila.

  				-int N: Número de elementos que puede almacenar el vector Pila.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Pila_llena(int *cima, int N){

	if(*cima == N) return verdadero;
	else return falso;
}




/*
################################################################################################
  Nombre Función : Apilar

  Descripción : Este módulo introduce un elemento en la pila en la posición designada por el puntero cima.

  Declaración : void Apilar(int *cima, int Pila[], int elemento, int N);

  Parámetros :	-int *cima: puntero al último elemento de la pila.

  				-int Pila[]: vector Pila.

  				-int elemento: valor que se introduce en la pila

  				-int N: cantidad de elementos que puede almacenra la pila como máximo.
 
 Valor de Retorno : esta función retorna void ó vacío.
#################################################################################################
*/
void Apilar(int *cima, int Pila[], int elemento, int N)
{
	if(Pila_llena(cima,N) == verdadero) printf("Pila llena, no se puede apilar.\n");
	else{
		Pila[*cima] = elemento;
		*cima = *cima +1;
	}
}




/*
################################################################################################
  Nombre Función : Desapilar

  Descripción : Este módulo elimina un elemento de la pila en la posición designada por el puntero cima.

  Declaración : int Desapilar(int *elemento, int *cima, int Pila[]);

  Parámetros :	-int *elemento: valor que se saca de la pila

  				-int *cima: puntero al último elemento de la pila.

  				-int Pila[]: vector Pila.
 
 Valor de Retorno : esta función retorna void ó vacío.
#################################################################################################
*/
int Desapilar(int *elemento, int *cima, int Pila[])
{
	if(Pila_vacia(cima) == falso){

		*elemento = Pila[*cima];
		*cima = *cima - 1;
		return verdadero;
	}
	else{
		printf("Pila vacía. No se puede desapilar.\n");
		return falso;
	}
}




/*
################################################################################################
  Nombre Función : Valor_cima

  Descripción : Este módulo  comprueba si un valor determinado está en la cima de la pila.

  Declaración : int Valor_cima(int *elemento, int *cima, int Pila[];

  Parámetros :	-int *elemento: valor que se consulta.

  				-int *cima: puntero al último elemento de la pila.

  				-int Pila[]: vector Pila.
 
 Valor de Retorno : esta función retorna void ó vacío.
#################################################################################################
*/
int Valor_cima(int *elemento, int *cima, int Pila[])
{
	if(Pila_vacia(cima) == falso){

		*elemento = Pila[*cima];
		return verdadero;
	}
	else{
		printf("Pila vacía.\n");
		return falso;
	}
}




void main()
{
	int N = TAM;
	int Pila[N];
	int cima = 0;
	int elemento;
	
		
	Apilar(&cima, Pila, 5, N);
	Apilar(&cima, Pila, 15, N);

	elemento =15;
	Desapilar(&elemento,&cima,Pila);
	//El módulo desapilado no elimina el valor del vector, pero permite sobreescribirlo
	//en la siguiente operación de apilado.

	printf("cima %d,y pila es %d \t %d\n", cima, Pila[0],Pila[1]);
}