
/*---------------------------------------------------------
	
	Alumno: Michaël José González Togni

	Asignatura: Estructura de datos.

	1º Examen Parcial

--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reg_fichero.h"		//Se importa el fichero con el registro de tipo ALUMNO declarado con sus respectivos campos.
#define verdadero 1
#define falso 0


/*
  Nombre Funcion : buscar1

  Descripcion : Módulo que busca UN valor en varios registros, almacenados en un fichero de forma ORDENADA.

  Declaracion : int buscar1(char *nombre_f, char x[50],ALUMNO reg_buscado)

  Parametros => nombre_f : nombre del fichero que contiene los registros. 
				
				x : Valor que se busca.
				
				ALUMNO reg_buscado: Variable de tipo ALUMNO (es el registro), llamada reg_buscado.
 
 Valor de Retorno : Esta funcion retorna un valor lógico (1 ó 0).

*/


int buscar1(char *nombre_f, char x[50],ALUMNO reg_buscado)
{
	FILE *F;
	int acabar;
	int a;
	ALUMNO REG;

	if( (F=fopen(nombre_f,"rb") )==NULL) { printf("ERROR de apertura.\n");  exit(-1); }

	acabar=falso;

	while( (acabar == falso) && (!feof(F)) )		/*Mientras no se acabe de leer el fichero que contiene los registros y no se encuentre el valor buscado, se sigue leyendo el fichero.*/ 
	{
		fread(&REG,sizeof(ALUMNO),1,F);				//Se lee el fichero.
		a=strcmp(REG.nombre, x);					//Strcmp (cadena1,cadena2)=> Para comparar cadenas lexicograficamente.Si a<0 (cadena1<cadena2), a>0 (cadena1>cadena2), a=0 (cadena1=cadena2).
		if(a==0)
		{
			//hacer lago con dicho valor.
			acabar = verdadero;						//Si encontramos la cadena buscada, modificamos el valor de acabar a verdadero.
		}
	}

	if(acabar==verdadero) printf("ENCONTRADO\n");
	else printf("NO ENCONTRADO\n");


	fclose(F);
	
	return acabar;
}



int main()
{
	char x[50];
	ALUMNO REG;

	char nombre_f[]="copia de datos (copia)";

	

	printf("Introduce el nombre que buscas.\n");	//Se pide al usuario que introduzca la cadena buscada.
	scanf(" %s", &x);

	buscar1(nombre_f, x, REG);						//Llamada a la funcion "buscar1".
}
