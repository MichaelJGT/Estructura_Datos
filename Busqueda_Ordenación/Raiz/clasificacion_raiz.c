#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reg_fichero.h"			//Importo el fichero que contiene el registro tipo ALUMNO definido con sus respectivos campos.
#define falso 0
#define verdadero 1



/*
  Nombre Funcion : obtener_cifra

  Descripcion : En este módulo se calcula la cifra de la clave que posteriormente se escribirá en uno de los 10 ficheros auxiliares. 

  Declaracion : int obtener_cifra(int clave,int iteracion,int *seguir)  

  Parametros =>	clave: clave de un registro.

  				iteración: iteración actual.

  				seguir: seguir/no seguir iterando.
 
 Valor de Retorno : Esta funcion devuelve la cifra de la clave.

*/

int obtener_cifra(int clave,int iteracion,int *seguir)  
{
	int i;
	int cifra;
	int N;

	N=clave;

	for(i=0;i<iteracion;i++)		//El número de iteraciones es igual al número de cifras del mayor dígito a ordenar.
	{
		cifra= (N % 10);			// Se calcula la unidad,decena,centena...a escribir en los ficheros auxiliares.El valor de iteracion aumenta para avancar en la escala, de unidades a dedcenas en la segunda iteración,decenas a centenas en la tercera y así sucesivamente.
		N = (N/10);
	}

	if(N != 0)
	{
		*seguir=verdadero;			// Si el Valor de N no es nulo se sigue iterando(el valor de "iteracion" se modifica en el módulo clasificacion_raiz).
	}
	//printf("cifra: %d\n",cifra);	//El valor de "seguir" se reasigna en varios módulos por lo que es necesario trabajar con su dirección de memoria.
	return cifra;
}





/*
  Nombre Funcion : separar_raiz

  Descripcion : Esta función se encarga de dividir los valores clave del fichero original en los 10 ficheros auxiliares

  Declaracion : void separar_raiz(char *nombre_origen,char nombre_destino[][50],int iteracion,int *seguir)

  Parametros =>	nombre_origen: nombre del fichero a ordenar.

  				nombre_destino: nombre de los ficheros auxiliares.

  				iteración: iteración actual.

  				seguir: seguir/no seguir iterando.
 
 Valor de Retorno : Esta funcion devuelve void o vacío.

*/

void separar_raiz(char *nombre_origen,char nombre_destino[][50],int iteracion,int *seguir)	
{	
	FILE *F_D[10]; 		//Decalaración de un vector de tipo fichero. Aquí se declaran los ficheros auxiliares.
	ALUMNO REG;
	int cifra;			
	FILE *F_O;			//Declaración del fichero con los campos clave a ordenar, el fichero origen.
	int i;

	*seguir=falso;

	for(i=0;i<10;i++)
	{	
		char nombre_destino[5];				
  		sprintf(nombre_destino,"%d",i);			//Conversion del entero i a caracteres ( sprintf(char nombre_variable,"contenido",variable_del_contenido) )para llamar a cada fichero por un número del 0 al 9.

		if( (F_D[i]=fopen(nombre_destino,"wb") ) == NULL)		//Apertura del fichero auxiliar 0-9 (valor de i) en modo "escritura en binario".
		{
    		fprintf(stderr,"Error apertura de fichero binario \n");
			;
		}						
	}

	if( (F_O = fopen(nombre_origen, "rb") ) == NULL)		//Apertura del fichero origen para lectura en binario.
	{
    	fprintf(stderr,"Error apertura de fichero binario \n");
	
	}

	

	while(!feof(F_O))
	{
		if(fread(&REG,sizeof(ALUMNO),1,F_O)==1)	{	//Lée el fichero origen y lo almacena en el registro REG de tipo ALUMNO.
		
		cifra= obtener_cifra(REG.NIA, iteracion, seguir);	//Obtenemos la cifra a escribir en los diferentes ficheros auxiliares a través del módulo previamente comentado.

		//printf("REG.NIA: %d\n", REG.NIA);

		fwrite(&REG,sizeof(ALUMNO),1,F_D[cifra]);	//Escribe en el fichero auxiliar "[número de cifra valorada]" el valor de todo el número seleccionado.
		}
	}



	for(i=0;i<10;i++)
	{
		fclose(F_D[i]);
	}																	//PUNTO DE COMPROBACIÓN

	/*
	for(i=0;i<10;i++)
	{
		char nombre_destino[5];
  		sprintf(nombre_destino,"%d",i);

		if( (F_D[i]=fopen(nombre_destino,"rb") ) == NULL)
		{
    		fprintf(stderr,"Error apertura de fichero binario \n");
		
		}
	}

for(i=0;i<10;i++){

	while(!feof(F_D[i]))
	{

		if(fread(&REG,sizeof(ALUMNO),1,F_D[i])==1)
		
		
		printf("i= %d,REG.NIA: %d\n", i, REG.NIA);
		
	}
}

for(i=0;i<10;i++){

	fclose(F_D[i]);
}
		*/

	fclose(F_O);
}





/*
  Nombre Funcion : concatenar

  Descripcion : En este módulo se pasan los números "ordenados" de los ficheros auxiliares al fichero original.

  Declaracion : void concatenar(char nombre_destino[][50],char *nombre_origen)

  Parametros =>	nombre_origen: nombre del fichero a ordenar.

  				nombre_destino: nombre de los ficheros auxiliares.
 
 Valor de Retorno : Esta funcion devuelve void o vacío.

*/

void concatenar(char nombre_destino[][50],char *nombre_origen)		
{
	ALUMNO REG;
	FILE *F_O;
	FILE *F_D[10];
	int i;

	for(i=0;i<10;i++)
	{
		char nombre_destino[50];
  		sprintf(nombre_destino, "%d", i);			//Conversion del entero i a caracteres para llamar a cada fichero por un número del 0 al 9.
  			
		if( (F_D[i]=fopen(nombre_destino,"rb") ) == NULL)
		{
    		fprintf(stderr,"Error apertura de fichero binario \n");
		
		}

	}


	if( (F_O = fopen(nombre_origen, "wb") ) == NULL)
	{
    	fprintf(stderr,"Error apertura de fichero binario \n");
		
	}

	for(i=0;i<10;i++)
	{

		while(!feof(F_D[i]))
		{

			if(fread(&REG,sizeof(ALUMNO),1,F_D[i])==1)			
			fwrite(&REG,sizeof(ALUMNO),1,F_O);					//Escribimos en el fichero original el contenido de cada fichero auxiliar.
			
		}

	}




	for(i=0;i<10;i++)
	{
		fclose(F_D[i]);
	}

	fclose(F_O);
}





/*
  Nombre Funcion : clasificacion_raiz

  Descripcion : En este módulo se unen los anteriores para reaizar la ordenación, es el módulo principal.

  Declaracion : void clasificacion_raiz( char *nombre_origen,char nombre_destino[][50] );

  Parametros =>	nombre_origen: nombre del fichero a ordenar.

  				nombre_destino: nombre de los ficheros auxiliares.
 
 Valor de Retorno : Esta funcion devuelve void o vacío.

*/

void clasificacion_raiz( char *nombre_origen,char nombre_destino[][50] )
{
	int seguir;
	int iteracion;

	seguir=verdadero;
	iteracion =1;

	do
	{	
		separar_raiz(nombre_origen,nombre_destino,iteracion+1,&seguir);  //Llamadas a los módulos anteriores hasta que se indique lo contrario a través del marcador lógico "seguir".
	
		concatenar(nombre_destino, nombre_origen );

		iteracion = iteracion + 1;

		//printf("Iteracion: %d\n\n",iteracion);

	}while(seguir != falso);

}




void main()
{	
	int i,j;
	FILE *F_D[10];
	char nombre_destino[10][50];
	char nombre_origen[]="copia de datos (copia)";
	ALUMNO REG;

	FILE *F_O;

	for(i=0;i<10;i++)
	{
		
		sprintf(nombre_destino[i],"%d",i);

	}
	

	printf("-------------------DESORDENADO---------------------\n");


	if( (F_O = fopen(nombre_origen, "rb") ) == NULL)
	{
    	fprintf(stderr,"Error apertura de fichero binario \n");
	
	}

	while(!feof(F_O)){

		if(fread(&REG,sizeof(ALUMNO),1,F_O)==1)
		printf("REG.NIA:%d\n",REG.NIA);
	}


	fclose(F_O);
	
	
	clasificacion_raiz(nombre_origen, nombre_destino);

	
printf("---------------------ORDENADO-----------------------\n");
	

	if( (F_O = fopen(nombre_origen, "rb") ) == NULL)
	{
    	fprintf(stderr,"Error apertura de fichero binario \n");
	
	}

	while(!feof(F_O)){

		if(fread(&REG,sizeof(ALUMNO),1,F_O)==1)
		printf("REG.NIA:%d\n",REG.NIA);
	}

	fclose(F_O);

}