#include <stdio.h>
#include <stdlib.h>

#define verdadero 1
#define falso 0
#define TAM 10





/*
################################################################################################
  Nombre Función : Lista_llena

  Descripción : Este módulo comprueba si la lista contiene todos los elementos que puede almacenar el vector.

  Declaración : int Lista_llena( int num_elem, int N);

  Parámetros :	-int num_elem: tamaño de la lista.

  				-int N: tamaño del vector
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Lista_llena( int num_elem, int N)
{
	if(num_elem == N) return verdadero;
	else{

		return falso;
	}
}




/*
################################################################################################
  Nombre Función : Insertar

  Descripción : Este módulo permite insertar un elemento en la lista.

  Declaración : void Insertar(int elemento, int posicion,int Lista[], int N, int num_elem);

  Parámetros :	-int elemento: valor a introducir en la lista.

  				-int posicion: posición de inserción.

  				-int Lista[]: vector lista.

  				-int N: tamaño del vector.

  				-int num_elem: longitud de la lista.
 
 Valor de Retorno : Esta función retorna void ó vacío.
#################################################################################################
*/
void Insertar(int elemento, int posicion,int Lista[], int N, int num_elem)
{
	int i; //contador

	if(Lista_llena(num_elem, N) == verdadero) printf("Lista llena.\n");
	else{

		if( (posicion > num_elem  ) || (posicion < 0) ) printf("Posición de inserción no válida.\n");
		else{
			if(posicion <= num_elem){

				for(i = num_elem; i < posicion;i++){
					Lista[i+1] = Lista[i];
				}
			}

			Lista[posicion] = elemento;
			num_elem = (num_elem) + 1;
		}
	}

}



/*
################################################################################################
  Nombre Función : Lista_vacia

  Descripción : Este módulo comprueba si la lista no tiene elementos.

  Declaración : int Lista_vacia(int num_elem);

  Parámetros :	-int num_elem: tamaño de la lista.
 
 Valor de Retorno : esta función retorna un entero "booleano".
#################################################################################################
*/
int Lista_vacia(int num_elem)
{
	if(num_elem == 0) return verdadero;
	else return falso;
}



/*
################################################################################################
  Nombre Función : Recorrer_lista_mostrar

  Descripción : Este módulo recorre la lista aplicando una acción a cada elemento de la misma,en este caso la imprime.

  Declaración : void Recorrer_lista_mostrar(int Lista[], int num_elem);

  Parámetros :	-int Lista[]: vector lista.

  				-int num_elem: longitud de la lista.
 
 Valor de Retorno : Esta función retorna void ó vacío.
#################################################################################################
*/
void Recorrer_lista_mostrar(int Lista[], int num_elem)
{
	int i; //contador.

	if(Lista_vacia(num_elem) == verdadero) printf("La lista está vacía.\n");
	else{
		for(i=0;i < num_elem; i++){

			printf("El %d elemento de la lista es: %d\n", i+1, Lista[i] );
		}
	}

}




/*
################################################################################################
  Nombre Función : Eliminar_posicion

  Descripción : Este módulo elimina un elemento de la lista según la posición.

  Declaración : void Eliminar_posicion(int posicion, int num_elem, int Lista[]);

  Parámetros :	-int posicion: posición de inserción.

  				-int num_elem: longitud de la lista.

  				-int Lista[]: vector lista.
 
 Valor de Retorno : Esta función retorna void ó vacío.
#################################################################################################
*/
void Eliminar_posicion(int posicion, int num_elem, int Lista[])
{
	int i;

	if(Lista_vacia(num_elem) == verdadero) printf("Lista vacía\n");
	else{

		if( (posicion > num_elem) || (posicion < 0)) printf("Posición de eliminación no válida.\n");
		else{
			i = posicion;

			while(i < num_elem){
				Lista[i] = Lista[i+1];
				i++;
			}

			num_elem = num_elem-1;
		}
	}
}





/*
################################################################################################
  Nombre Función : busqueda_lineal_desordenado

  Descripción : Este módulo realiza una búsqueda en la lista.

  Declaración : void busqueda_lineal_desordenado(int V[], int N, int X);

  Parámetros :	-int V[]: vector.

  				-int N: cantidad de elementos del vector.

  				-int X: elemento buscado.
 
 Valor de Retorno : Esta función retorna void ó vacío.
#################################################################################################
*/
int busqueda_lineal_desordenado(int V[], int N, int X){

int I=0; // contador del vector, valor inicial la primera posición del array.

	while( V[I] != X && I<(N-1) ){		 // Bucle que se repite mientras:
				  						// la posicion del vector no contenga el valor buscado.
				  						// Y que no hayamos revisado todas las posiciones del vector.
	I++;//(I=I+1)			 			 // N-1 para no salirnos del vector porque la posicion del décimo caracter es la 9(se empieza en 0)

	}


	if(V[I] == X ){ 

		return I;
	//printf("\nEncontrado en posición %d\n", I);

	}

	else{

	printf("\nNo se ha encontrado\n ");

	}

}




/*
################################################################################################
  Nombre Función : Eliminar_valor

  Descripción : Este módulo elimina un valor de la lista.

  Declaración : void Eliminar_valor(int valor, int num_elem, int Lista[], int N);

  Parámetros :	-int valor: valor a eliminar.

  				-int num_elem: longitud de la lista.

  				-int Lista[]: vector lista.

  				-int N: tamaño del vector.
 
 Valor de Retorno : Esta función retorna void ó vacío.
#################################################################################################
*/
void Eliminar_valor(int valor, int num_elem, int Lista[], int N)
{
	int posicion;

	posicion = busqueda_lineal_desordenado(Lista, num_elem, valor);

	if(posicion < 0) printf("El valor no forma parte de la lista.\n");
	else{
		Eliminar_posicion(posicion, num_elem, Lista);
	}
}



/*
################################################################################################
  Nombre Función : Insertar_en_orden

  Descripción : Este módulo introduce un valor en la lista de forma ordenada (no ordena los ya existentes).

  Declaración : void Insertar_en_orden(int elemento, int N, int num_elem, int Lista[]);

  Parámetros :	-int elemento: valor a eliminar.

  				-int N: tamaño del vector.

  				-int num_elem: longitud de la lista.

  				-int Lista[]: vector lista.
 
 Valor de Retorno : Esta función retorna void ó vacío.
#################################################################################################
*/
void Insertar_en_orden(int elemento, int N, int num_elem, int Lista[])
{
	int i; 
	
	if(Lista_llena(num_elem, N) == verdadero) printf("Lista llena.\n");
	else{
		i = num_elem ;

		while( (Lista[i-1] > elemento) && (i > 0)){

			Lista[i] = Lista[i-1];
			i--;
		}

		Lista[i] = elemento;
		num_elem = num_elem + 1;
	}	

}




void main()
{	
//void Insertar(int elemento, int posicion,int Lista[], int N, int num_elem)
	
	int Lista[TAM];
	int i;
	int num_elem;

	for(i=0;i<TAM;i++){

		Insertar(i+2, i, Lista, TAM, i);
	}

	num_elem =i;
	Recorrer_lista_mostrar(Lista,num_elem);


	printf("\nEliminamos el 3 de la lista.\n");

	Eliminar_valor(3,10,Lista,10);

	Insertar_en_orden(6, 10, 9, Lista);

	Recorrer_lista_mostrar(Lista,num_elem);
}