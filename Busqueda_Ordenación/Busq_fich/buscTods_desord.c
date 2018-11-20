
/*---------------------------------------------------------
	
	Alumno: Michaël José González Togni

	Asignatura: Estructura de datos.

	1º Examen Parcial

--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "reg_fichero.h"
#define verdadero 1
#define falso 0



/*
  Nombre Funcion : buscar_todos

  Descripcion : Módulo que busca UN valor VARIAS veces en varios registros, almacenados en un fichero de forma DESORDENADA.

  Declaracion : void buscar_todos(char *nombre_f, int x)

  Parametros => nombre_f : nombre del fichero que contiene los registros. 
				
				x : Valor que se busca.
 
 Valor de Retorno : Esta funcion retorna void o vacío.

*/

void buscar_todos(char *nombre_f, int x)
{
	int i=0;				 //contador de veces que se ha encontrado el valor.
	ALUMNO REG;
	int encontrado;		    //Marcador de búsqueda, variable lógica.
	FILE *F;

	if( (F=fopen(nombre_f,"rb") )==NULL) { printf("ERROR de apertura.\n");  exit(-1); }
	
	encontrado = falso;

	while((!feof(F)) )												//Mientras no se acabe de leér el fichero se sigue buscando el valor.
	{
		fread(&REG,sizeof(ALUMNO),1,F);

		if(REG.NIA == x)											//Se compara el valor buscado con el leido.
		{
			i++;													//Contamos cuantas veces hemos encontrado el valor.
			//hacer algo con dicho valor(escribirlo,moverlo,etc.)
			encontrado = verdadero;
		}
	}	

	

	if(encontrado == falso)	printf("Valor %d no encontrado\n",x);		//Mostramos con mensajes el resultado de la búsqueda.
	else printf("Número de veces que aparece el valor %d: %d \n",x,i);

	fclose(F);

}

void main()
{
	char nombre_f[]="copia de datos (copia)";
	int x;

	printf("Introduce el valor buscado:\n");			//Introducimos el valor buscado.
	scanf(" %d",&x);

	buscar_todos(nombre_f,x);							//Llamada a la función "buscar_todos"		
}
