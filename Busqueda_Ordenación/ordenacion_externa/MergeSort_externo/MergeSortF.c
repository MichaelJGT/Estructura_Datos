/*
-------------------------------------------------
								
	Alumno: Michaël josé González Togni.      
								
	Asignatura: Estructura de Datos.		
								
	1º Exámen Parcial			
								
-------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "reg_fichero.h"			//Fichero que contiene definido el registro ALUMNO con sus respectivos campos.
#define CAT 100						//Se define el tamaño de los vectores de caracteres que almacenarán el nombre de algunos ficheros.
#define  error_Lectura_F 25  		//Aquí se define nuestro propio código de error de lectura, en caso de error obtendremos un 25.



int  leer_F(char *nombre_f);				//PROTOTIPOS DE LAS FUNCIONES EMPLEADAS.

void separar_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec, int *elem_f);
										                              										                             
void Mezcla_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec,int elem_f);
										                           										                             
void Clasif_Mezcla(char *nombre_f,char *nombre_f1,char *nombre_f2);



int main(){


  FILE *f;
			
	

  if ((f = fopen("copia de datos","rb")) == NULL)
  {
    fprintf(stderr,"Error apertura de fichero binario \n");		//stderr: muestra el mensaje por pantalla si hay error de apertura.
  }

  /*fseek(f, 0L, SEEK_END);										Para contar los registros (tipo = ALUMNO) almacenados en "copia de datos".
  int sz = ftell(f);  sz = sz/sizeof(ALUMNO);

  printf("numero de registros : %d\n",sz);*/



  fclose(f);

  char nombre[]="copia de datos";			//Se definen los nombres de los ficheros empleados en los módulos.
  char nombre1[]="F1";
  char nombre2[]="F2";
  
  printf("\n---------------SIN ORDENAR---------------\n");

  leer_F(nombre);							//Llamada a la función Leer_F para visualizar el campo clave de los registros desordenados.

 Clasif_Mezcla(nombre, nombre1, nombre2);	//Llamada a Clasif_Mezcla => Se ordenan los registros por el campo elegido.

  /*printf("F1\n");
  leer_F(nombre1);							//Para visualizar la división de los registos entre los ficheros.

  printf("F2\n");
  leer_F(nombre2);*/

  printf("\n---------------ORDENADO------------------\n");
  leer_F(nombre);

	return 0;
}


/*
  Nombre Funcion : leer_F

  Descripcion : Módulo que permite leer los campos del los registros almacenados en el fichero. 

  Declaracion : int leer_f(char *nombre_f);

  Parametros =>	nombre_f : nombre de fichero origen.
 
 Valor de Retorno : Esta funcion devuelve 0 si no hay error de apertura, de lo contrario devuelve 1. 

*/

int  leer_F(char *nombre_f){				

	ALUMNO reg;
	FILE *f;

	if ((f = fopen(nombre_f,"rb")) == NULL)						//Apertura del fichero para lectura en binario, con su respectiva comprobación de error.
  	{
  	  fprintf(stderr,"Error apertura de fichero binario \n");	
	  return 1;
 	 }

	fread(&reg,sizeof(ALUMNO),1,f);								//Lectura de los registros almacenados en el fichero.
  
    while (!feof(f)){											//Seguir leyendo hasta que se acabe el fichero.
     
      printf("Nota:%f\n ", reg.nota);	
	  fread(&reg,sizeof(ALUMNO),1,f);					
	}

	fclose(f);
}







/*
  Nombre Funcion : seperar_directa

  Descripcion : Módulo que realiza la separación de los registros almacenados en el fichero F en dos ficheros auxiliares, F1 y F2. 

  Declaracion : void separar_directa(char *nombre_f, char *nombre_f1, char *nombre_f2 , int tam_sec, int *elem_f);

  Parametros => nombre_f : nombre de fichero origen 
				
				nombre_f1: nombre del primer fichero auxiliar.
				
				nombre_f2: nombre del segundo fichero auxiliar.
				
				tam_sec: tamaño de separación de la secuencia 
				
				elem_f: número de registros almacenados en el fichero origen.
 
 Valor de Retorno : Esta funcion devuelve vacio o void 

*/

void separar_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec, int *elem_f) 
										                              
										                              
{


 ALUMNO REG;       	 //Se define la primera variable de tipo = REGISTRO, llamada REG. 
 FILE *F1,*F2,*F;	//Declaración de los ficheros 
 int N;			   //Contador de registros escritos en cada operación de escritura.


 if (NULL == (F = fopen(nombre_f,"rb")))							//Apertura de nombre_f para lectura en binario, con su respectiva comprobación de error.
 {
 	fprintf(stderr, "Error apertura de fichero f\n");				
 	exit(error_Lectura_F);
 }

 if (NULL == (F1 = fopen(nombre_f1,"wb")))							//Apertura del primer fichero auxiliar para escritura en binario.
 {
 	fprintf(stderr, "Error apertura de fichero f1\n");				
  	exit(error_Lectura_F);
 }
  
 if (NULL == (F2 = fopen(nombre_f2,"wb")))							//Apertura del segundo fichero auxiliar para escritura en binario.
 {
 	fprintf(stderr, "Error apertura de fichero f2\n");				
 	exit(error_Lectura_F);
 }
 



*elem_f = 0;

fread(&REG,sizeof(ALUMNO),1,F);

while(!feof(F)){													//Mientras no se acabe de leer el fichero origen:

	N = 0;

	while (!feof(F) && N < tam_sec){								//Comprobamos que el número de registros es menor que el tamaño de la secuencia(se definirá su valor posteriormente en el módulo Clasif_Mezcla).
		
		fwrite(&REG,sizeof(ALUMNO),1,F1);  N= N + 1;				//Escribimos el registro leído en el primer fichero auxiliar.

		fread(&REG,sizeof(ALUMNO),1,F);    *elem_f = *elem_f + 1;
	}

	N=0;

	while (!feof(F) && N < tam_sec){								//Repetimos el proceso pero esta vez escribiendo el registro leído en el segundo fichero auxiliar
		
		fwrite(&REG,sizeof(ALUMNO),1,F2);   N = N + 1;

		fread(&REG,sizeof(ALUMNO),1,F);    *elem_f = *elem_f + 1;
	}
}

fclose(F);
fclose(F1);
fclose(F2);

}




/*
  Nombre Funcion : Mezcla_directa

  Descripcion : Módulo que realiza la mezcla de los ficheros auxiliares copiando los registros sobre el fichero original.

  Declaracion : void Mezcla_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec, int elem_f);

  Parametros =>	nombre_f : nombre de fichero origen .
				
				nombre_f1: nombre del primer fichero auxiliar.
				
				nombre_f2: nombre del segundo fichero auxiliar.
				
				tam_sec: tamaño de separación de la secuencia 
				
				elem_f: número de registros almacenados en el fichero origen.
 
 Valor de Retorno : Esta funcion retorna void o vacío. 

*/


void Mezcla_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec, int elem_f){
										                             

										                            
ALUMNO REG1,REG2;
FILE *F1,*F2,*F;
int resta, resta_f1, resta_f2;

if (NULL == (F = fopen(nombre_f,"wb"))){
 	fprintf(stderr, "Error apertura de fichero f\n");
 	exit(error_Lectura_F);
 }

 if (NULL == (F1 = fopen(nombre_f1,"rb"))){
 		  fprintf(stderr, "Error apertura de fichero f1\n");			//Apertura de los tres ficheros con su respectiva comprobación de error.
  		  exit(error_Lectura_F);
 }
  
 if (NULL == (F2 = fopen(nombre_f2,"rb"))){
 	fprintf(stderr, "Error apertura de fichero f2\n");
 	exit(error_Lectura_F);
 }


resta= elem_f;									//La variable "resta" hace refecencia a los registros totales que quedan por mezclar.

do{

if (resta >= tam_sec)  resta_f1=tam_sec;		//Se calcula el número de registros que quedan por mezclar en el primer fichero auxiliar.
else resta_f1=resta;

resta= resta-resta_f1;

if(resta>=tam_sec)  resta_f2=tam_sec;			//Se calcula el número de registros que quedan por mezclar en el segundo fichero auxiliar.
else resta_f2=resta;

resta=resta-resta_f2;


fread(&REG1,sizeof(ALUMNO),1,F1);				//Se léen los ficheros auxiliares.
fread(&REG2,sizeof(ALUMNO),1,F2);

while(resta_f1!=0  &&  resta_f2!=0){			//Mientras queden registros por leer en los dos ficheros auxiliares:

	if(REG1.nota < REG2.nota)					//Se ordenan los campos clave de los ficheros auxiliares y se escriben el fichero original,en esta condición leémos del primer fichero auxiliar.
	{
		fwrite(&REG1,sizeof(ALUMNO),1,F); 

		resta_f1 = resta_f1 - 1;

		if(resta_f1 != 0)    fread(&REG1,sizeof(ALUMNO),1,F1);
	}

	else
	{
		fwrite(&REG2,sizeof(ALUMNO),1,F); 		//Si el campo clave almacenado en el segundo fichero es mayor que el del primer fichero auxiliar, leémos del segundo y lo escribimos en el original.

		resta_f2= resta_f2 - 1;

		if(resta_f2 != 0)  fread(&REG2,sizeof(ALUMNO),1,F2);
	}
}


while(resta_f2 != 0)							//En éstos dos últimos bucles comprobamos por separado si quedan registros por leer en cada fichero auxiliar, de ser así repetimos la lectura y escribimos en el original. 
{
	fwrite(&REG2,sizeof(ALUMNO),1,F); 
	resta_f2 = resta_f2 -1 ;

	if(resta_f2 != 0)    fread(&REG2,sizeof(ALUMNO),1,F2);
}


while(resta_f1 != 0)
{
	fwrite(&REG1,sizeof(ALUMNO),1,F); 
	resta_f1 = resta_f1 -1 ;

	if(resta_f1 != 0)    fread(&REG1,sizeof(ALUMNO),1,F1);
}


}while(resta != 0);

fclose(F);
fclose(F1);										//Cerramos los ficheros.
fclose(F2);

}





/*
  Nombre Funcion : Clasif_Mezcla

  Descripcion : Módulo que incrementa el tamaño de la secuencia y aplica los módulos previamente definidos.Como resultado obtenemos un fichero con registros ordenados por el campo elegido.

  Declaracion : void Clasif_Mezcla(char *nombre_f,char *nombre_f1,char *nombre_f2)

  Parametros =>	nombre_f : nombre de fichero origen 
				
				nombre_f1: nombre del primer fichero auxiliar.
				
				nombre_f2: nombre del segundo fichero auxiliar.
 
 Valor de Retorno : Esta funcion devuelve 0 si no hay error de apertura, de lo contrario devuelve 1. 

*/


void Clasif_Mezcla(char *nombre_f,char *nombre_f1,char *nombre_f2)
{

int num_elem;
int tam_sec;


tam_sec=1;

do
{
   separar_directa(nombre_f, nombre_f1, nombre_f2, tam_sec, &num_elem );	  //Llamada a la función "separar_directa".

   Mezcla_directa(nombre_f, nombre_f1, nombre_f2, tam_sec, num_elem );		//Llamada a la función "Mezcla_directa".

   tam_sec=tam_sec*2;													  //Se multiplica el tamaño de la secuencia de registros por 2 en cada iteración.
 
}
while(tam_sec < num_elem);											    //Mientras el tamaño de la secuencia sea menor que el número de registros se sigue iterando.


}