
/*---------------------------------------------------------
	
	Alumno: Michaël José González Togni

	Asignatura: Estructura de datos.

	1º Examen Parcial

--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "reg_fichero.h"
#define	verdadero 1
#define falso 0
#define T 50



/*
  Nombre Funcion : buscar1

  Descripcion : Módulo que busca UN valor en varios registros almacenados en un fichero de forma DESORDENADA.

  Declaracion : int buscar1(char *nombre_f, int x, ALUMNO reg_buscado);

  Parametros => nombre_f : nombre del fichero que contiene los registros. 
				
				x : Valor que se busca.
				
				ALUMNO reg_buscado: Variable de tipo ALUMNO (es el registro), llamada reg_buscado.
 
 Valor de Retorno : Esta funcion retorna un valor lógico (1 ó 0).

*/


int buscar1(char *nombre_f, int x, ALUMNO reg_buscado)  
{
	int encontrado;
	ALUMNO reg;
	FILE *F;

	if( (F=fopen(nombre_f,"rb") )==NULL) { printf("ERROR de apertura.\n");  exit(-1); }

	encontrado= falso;

	while( (encontrado == falso) && (!feof(F)) )	/*Mientras no se acabe de leer el fichero que contiene los registros y no se encuentre el valor buscado, se sigue leyendo el fichero.*/
	{
		fread(&reg,sizeof(ALUMNO),1,F);

		if(reg.NIA == x)
		{
			reg_buscado = reg;		//En caso de encontrar el valor, el registro que lo contiene pasa a ser el registro buscado.
			encontrado = verdadero;	//Cambiamos el valor lógico de "encontrado" al encontrar el valor buscado.
		}

	}

	fclose(F);

	if(encontrado==1) printf("ENCONTRADO\n");
	else printf("NO ENCONTRADO\n");
	
	return encontrado;		//Se devuelve el valor lógico como resultado del módulo.

	

}



int main()
{	
	int x;
	ALUMNO REG;

	char nombre_fich[]="copia de datos (copia)";

	

	printf("Introduce el número que buscas.\n");	//Se pide que el usuario introduzca el valor que será buscado en los registros.
	scanf(" %d", &x);

	buscar1(nombre_fich, x, REG);				//Llamada a la función "buscar1".

	

}