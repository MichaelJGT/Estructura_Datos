
/*---------------------------------------------------------
	
	Alumno: Michaël José González Togni

	Asignatura: Estructura de datos.

	1º Examen Parcial

--------------------------------------------------------*/




#include <stdio.h>
#include <stdlib.h>
#include "reg_fichero.h"			//Se importa el fichero con el registro de tipo ALUMNO declarado con sus respectivos campos.
#define verdadero 1
#define falso 0



/*
  Nombre Funcion : buscar_todos

  Descripcion : Módulo que busca UN valor VARIAS veces en varios registros, almacenados en un fichero de forma ORDENADA.

  Declaracion : void buscar_todos(char *nombre_f, int x)

  Parametros => nombre_f : nombre del fichero que contiene los registros. 
				
				x : Valor que se busca.
 
 Valor de Retorno : Esta funcion retorna void o vacío.

*/

void buscar_todos(char *nombre_f, int x)
{
	int i=0;								//contador de veces que se ha encontrado el valor.
	ALUMNO REG;
	int salir,existe;					  //Marcadores de búsqueda, variables lógicas.
	FILE *F;

	salir=falso;
	existe=falso;

	if( (F=fopen(nombre_f,"rb") )==NULL) { printf("ERROR de apertura.\n");  exit(-1); }
	

	while((!feof(F)) && salir==falso )				//Mientras no se acabe de leér el fichero se sigue buscando el valor.
	{
		fread(&REG,sizeof(ALUMNO),1,F);

		if(REG.NIA > x)								//Si encontramos un valor superior al buscado (como los registros están ordenados), cambiamos el marcador salir a verdadero para interrumpir la búsqueda.
		{
			salir = verdadero;
		}
		else 
		{
			if(REG.NIA == x)						//Si encontramos el valor buscado, cambiamos el valor de "existe" a verdadero.
			{
				i++;								//Contador de cuántos valores buscados hemos encontrado.
				existe = verdadero;
			}
		}
	}	

	

	if(existe == falso)	printf("Valor %d no encontrado\n",x);				//Mensajes para mostrar al usuario el resultado de la búsqueda.
	else printf("Número de veces que aparece el valor %d: %d \n",x,i);

	fclose(F);

}

void main()
{
	char nombre_f[]="copia de datos (copia)";								
	int x;

	printf("Introduce el valor buscado:\n");			//Introducimos el valor buscado.
	scanf(" %d",&x);

	buscar_todos(nombre_f,x);							//Llamada a la función "buscar1"
}
