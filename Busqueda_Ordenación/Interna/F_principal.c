/*FUNCION PRINCIPAL*/


#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"





void main(){
		//aplicar busqueda lineal

int N=10;

                       int vector1[10]= {1, 45, 25, 6, 0, 8, 9, 2, 3, 4};
			int vector2[10]= { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
			int vector3[10]= {0, 1, 2, 3, 8, 5, 6, 7, 45, 50};
			int vector4[10]= {2, 3, 8, 6, 15, 8, 9, 4, 11, 40};



printf("\nvector 4\n");
mostrar( N, vector4);

insercion_binaria(vector4, 10);

printf("\ninserción binaria\n");
mostrar( N, vector4);




printf("\nvector 1\n");
mostrar( N, vector1);

insercion_directa(vector1, N);

printf("\ninserción directa\n");
mostrar( N, vector1);




printf("\nvector 3\n");
mostrar( N, vector3);

ordenacion_seleccion_directa( N, vector3);

printf("\nordenacion seleccion directa\n");
mostrar( N, vector3);




 int vector5[10]= {1, 45, 25, 6, 0, 8, 9, 2, 3, 4};

printf("\nvector 5\n");
mostrar( N, vector5);

ordenacion_intercambio_izq_der(vector5, 10);

printf("\nordenacion intercambio izq-der\n");
mostrar( N, vector5);



int vector6[10]= {0, 1, 2, 3, 8, 5, 6, 7, 45, 50};

printf("\nvector 6\n");
mostrar( N, vector6);

ordenacion_sacudida(vector6, 10);

printf("\nordenacion_sacudida\n");
mostrar( N, vector6);




int vector7[10]= {2, 3, 8, 6, 15, 8, 9, 4, 11, 40};

printf("\nvector 7\n");
mostrar( N, vector7);

ordenacion_shell(vector7, 10);

printf("\nordenacion_shell\n");
mostrar( N, vector7);




int vector8[10]= {1, 45, 25, 6, 7, 8, 9, 2, 3, 4};

printf("\nvector 8\n");
mostrar( N, vector8);

ordenacion_por_mezcla( vector8, 0, 9 );

printf("\nordenacion por mezcla\n");
mostrar( N, vector8);




printf("\nvector 1\n");
mostrar( N, vector1);

busqueda_lineal_desordenado(vector1, 10, 0);   // (nombre V, número de elementos N, número que se busca X)
 
printf("\nbusqueda lineal\n");

mostrar( N, vector1);



printf("\nvector 1\n");
mostrar( N, vector1);

busqueda_binaria(vector1, 10, 1);  //Los datos tienen que estar ordenados, ascendentemente o descendientemente.

printf("\nbusqueda binaria\n");

mostrar( N, vector1);


int vector10[10]= {2, 3, 8, 6, 15, 8, 9, 4, 11, 40};
printf("\nvector 7\n");
mostrar( N, vector10);
ordenacion_rapida(vector10,0,9);

printf("\nordenacion rapida\n");
mostrar( N, vector10);



}
