/*
-------------------------------------------------
								
	Alumno: Michaël josé González Togni.      
								
	Asignatura: Estructura de Datos.		
								
	1º Exámen Parcial			
								
-------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#define  error_Lectura_F 25 		//Aquí se define nuestro propio código de error de lectura, en caso de error obtendremos un 25.
#include "reg_fichero.h"			//Fichero que contiene definido el registro ALUMNO con sus respectivos campos.
#define CAT 100						//Se define el tamaño de los vectores de caracteres que almacenarán el nombre de algunos ficheros.




int  leer_F(char *nombre_f);


void separar_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec,int *elem_f);		//PROTOTIPOS DE LAS FUNCIONES EMPLEADAS.
										                              							
										                              
void Mezcla_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, int tam_sec,int elem_f);
										                             

										                             
void Clasif_Mezcla(char *nombre_f,char *nombre_f1,char *nombre_f2);




int main(){

  int tam_sec= 1;
  int num_elem;

  FILE *f;

  ALUMNO reg;
	
  if ((f = fopen("MezclaDir2","rb")) == NULL)
  {
    fprintf(stderr,"Error apertura de fichero binario \n");
	return 1;
  }

  fseek(f, 0L, SEEK_END);						//Para contar los registros de
  int sz = ftell(f);  sz = sz/sizeof(ALUMNO);

  printf("numero de registros : %d\n",sz);



  fclose(f);

  char nombre[]="MezclaDir2";
  char nombre1[]="F1";
  char nombre2[]="F2";
  
  leer_F(nombre);

  //separar_directa( nombre, nombre1, nombre2, tam_sec,&num_elem);
 Clasif_Mezcla(nombre, nombre1, nombre2);

  printf("F1\n");
  leer_F(nombre1);

  printf("F2\n");
  leer_F(nombre2);

   printf("F_ORDENADO:\n");
  leer_F(nombre);

	return 0;
}

int  leer_F(char *nombre_f){

	ALUMNO reg;
	FILE *f;

	if ((f = fopen(nombre_f,"rb")) == NULL)
  	{
  	  fprintf(stderr,"Error apertura de fichero binario \n");
	  return 1;
 	 }

	fread(&reg,sizeof(ALUMNO),1,f);
  
    while (!feof(f)){		
     
      printf("Nota: %f\n ", reg.nota);
	  fread(&reg,sizeof(ALUMNO),1,f);
	}

	fclose(f);
}







/*
  Nombre Funcion : seperar_directa

  Descripcion : 
  					Módulo que realiza la separación de los registros almacenados en el 
  					fichero F en dos ficheros auxiliares, F1 y F2. 

  Declaracion : void separar_directa(char nombre_f, char nombre_f1, char , int, int *);

  Parametros : 
				nombre_f : nombre de fichero origen 
				.
				.
				.
				.
				.
 
 Valor de Retorno : 

 				Esta funcion devuelve vacio o void 

*/

void separar_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, 
										                              int tam_sec,
										                              int *elem_f) 
{


 ALUMNO REG;        //Se define la primera variable de tipo = REGISTRO, llamada REG. 
 FILE *F1,*F2,*F;	//Declaración de los ficheros 
 int N;


 if (NULL == (F = fopen(nombre_f,"rb"))){
 	fprintf(stderr, "Error apertura de fichero f\n");
 	exit(error_Lectura_F);
 }

 if (NULL == (F1 = fopen(nombre_f1,"wb"))){
 		  fprintf(stderr, "Error apertura de fichero f1\n");
  		  exit(error_Lectura_F);
 }
  
 if (NULL == (F2 = fopen(nombre_f2,"wb"))){
 	fprintf(stderr, "Error apertura de fichero f2\n");
 	exit(error_Lectura_F);
 }
 




*elem_f = 0;
fread(&REG,sizeof(ALUMNO),1,F);

while(!feof(F)){

	N = 0;

	while (!feof(F) && N < tam_sec){
		
		fwrite(&REG,sizeof(ALUMNO),1,F1);  N= N + 1;

		fread(&REG,sizeof(ALUMNO),1,F);    *elem_f = *elem_f + 1;
	}

	N=0;

	while (!feof(F) && N < tam_sec){
		
		fwrite(&REG,sizeof(ALUMNO),1,F2);   N = N + 1;

		fread(&REG,sizeof(ALUMNO),1,F);    *elem_f = *elem_f + 1;
	}
}

fclose(F);
fclose(F1);
fclose(F2);

}


void Mezcla_directa(char *nombre_f, char *nombre_f1, char *nombre_f2, 
										                             int tam_sec,

										                             int elem_f){
ALUMNO REG1,REG2;
FILE *F1,*F2,*F;
int resta, resta_f1, resta_f2;

if (NULL == (F = fopen(nombre_f,"wb"))){
 	fprintf(stderr, "Error apertura de fichero f\n");
 	exit(error_Lectura_F);
 }

 if (NULL == (F1 = fopen(nombre_f1,"rb"))){
 		  fprintf(stderr, "Error apertura de fichero f1\n");
  		  exit(error_Lectura_F);
 }
  
 if (NULL == (F2 = fopen(nombre_f2,"rb"))){
 	fprintf(stderr, "Error apertura de fichero f2\n");
 	exit(error_Lectura_F);
 }


resta= elem_f;

do{

if (resta >= tam_sec)  resta_f1=tam_sec;
else resta_f1=resta;

resta= resta-resta_f1;

if(resta>=tam_sec)  resta_f2=tam_sec;
else resta_f2=resta;

resta=resta-resta_f2;


fread(&REG1,sizeof(ALUMNO),1,F1);
fread(&REG2,sizeof(ALUMNO),1,F2);

while(resta_f1!=0  &&  resta_f2!=0){

	if(REG1.nota < REG2.nota)
	{
		fwrite(&REG1,sizeof(ALUMNO),1,F); 

		resta_f1 = resta_f1 - 1;

		if(resta_f1 != 0)    fread(&REG1,sizeof(ALUMNO),1,F1);
	}

	else
	{
		fwrite(&REG2,sizeof(ALUMNO),1,F); 

		resta_f2= resta_f2 - 1;

		if(resta_f2 != 0)  fread(&REG2,sizeof(ALUMNO),1,F2);
	}
}


while(resta_f2 != 0)
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
fclose(F1);
fclose(F2);

}


void Clasif_Mezcla(char *nombre_f,char *nombre_f1,char *nombre_f2)
{

int num_elem;
int tam_sec;


tam_sec=1;

do
{
   separar_directa(nombre_f, nombre_f1, nombre_f2, tam_sec, &num_elem );//Mirar parámetros.
   
   Mezcla_directa(nombre_f, nombre_f1, nombre_f2, tam_sec, num_elem );

   tam_sec=tam_sec*2;
 
}
while(tam_sec < num_elem);


}