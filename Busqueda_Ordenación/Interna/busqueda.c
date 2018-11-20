/*---------------------------------------------------------
	
	Alumno: Michaël José González Togni

	Asignatura: Estructura de datos.

	1º Examen Parcial

--------------------------------------------------------*/


#include <stdio.h>
#include "prototipos.h"

void busqueda_lineal_desordenado(int V[], int N, int X){

int I=0; // contador del vector, valor inicial la primera posición del array.

	while( V[I] != X && I<(N-1) ){		 // Bucle que se repite mientras:
				  						// la posicion del vector no contenga el valor buscado.
				  						// Y que no hayamos revisado todas las posiciones del vector.
	I++;//(I=I+1)			 			 // N-1 para no salirnos del vector porque la posicion del décimo caracter es la 9(se empieza en 0)

	}


	if(V[I] == X ){  //== para comparación.

	printf("\nEncontrado en posición %d\n", I);

	}

	else{

	printf("\nNo se ha encontrado\n ");

	}

}




	void busqueda_lineal_ordenado(int V[], int N, int X){

	int I=0; 							// contador del vector, valor inicial la primera posición del array.

		while( V[I] < X && I<(N-1) ){ 	// Bucle que se repite mientras:
			
					  					// la posicion del vector sea menor que el valor buscado,cuando sea mayor se para porque está ordenado crecientemente y no ha aparecido.
					  
		I++;//(I=I+1)			 		// N-1 para no salirnos del vector porque la posicion del décimo caracter es la 9(se empieza en 0)

		}


		if(V[I] == X ){  //== para comparación.

		printf("\nEncontrado en posición %d\n", I);

		}

		else{

		printf("\nNo se ha encontrado\n ");

		}

	}






void busqueda_binaria(int V[], int N, int X){ //Para orden creciente.

int I=0, DER=(N-1),IZQ=0,CEN=(IZQ+DER)/2;

while((V[CEN]!=X) &&  (IZQ<DER)){
	
	if(V[CEN]>X){      //Para buscar en orden decreciente poner <
	
	DER=CEN-1;	//Recorre desde el centro hasta la posición menor o igual en la que esté X(el número que buscamos).
		
	}

	else{
	
	IZQ= CEN+1;  	//Recorre desde la posición central hasta la posicón en la que esté X, sólo si la posición es menor que la central.
		
	}
CEN=(IZQ+DER)/2;   //La pos.central*vuelta es la suma de ambos lados entre 2.

}

			
			//Para buscar en orden decreciente poner >

if(V[CEN]=X){

printf("\nEncontrado en la posición %d\n", CEN);
printf("\nSe han requerido %d vueltas\n", I);
}

else{

printf("\nNo existe el valor buscado\n");

}

}






	


