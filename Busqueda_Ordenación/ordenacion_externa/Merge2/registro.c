/*
-------------------------------------------------
								|
	Alumno: Michaël josé González Togni.      |
								|
	Asignatura: Estructura de Datos.		|
								|
	1º Exámen Parcial					|
								|
-------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include "reg_fichero.h"  // fichero en el que se define el registro a emplear.
#define TAM 11	//Defino la cantidad de registros
#define CAT 80





ALUMNO pru[TAM];



void escritura_fichero()
{

int i;


FILE *fichero;


if( (fichero=fopen("MezclaDir2","w")) ==NULL)
{
  printf("Error de apertura\n");
  exit(-1);
}

for(i=0;i<TAM;i++)
{
  printf("\nIntroduce el nombre:\n");
  fgets(pru[i].nombre,CAT,stdin);

  printf("\nIntroduce los apellidos:\n");
  fgets(pru[i].apellidos,CAT,stdin);

  printf("Introduce el NIA:\n");
  scanf(" %d", &pru[i].NIA);

  printf("Introduce la nota:\n");
  scanf(" %f", &pru[i].nota);

  printf("Introduce la edad:\n");
  scanf(" %d", &pru[i].edad);

  getchar(); 

}


fwrite(pru, sizeof(ALUMNO), TAM,fichero);

fclose(fichero);

}





void lectura()
{


int i,j;

FILE *fich;

if( (fich=fopen("MezclaDir2","r"))==NULL )
{
  printf("Error de apertura\n");
  exit(-1);
}

while(!feof(fich))
{



    if(fread(&pru,sizeof(ALUMNO),TAM,fich)){
    
      for(j=0;j<TAM;j++)
      {
        printf("\nNombre: %s \nEdad: %d \nNota: %f\n", pru[j].nombre, pru[j].edad, pru[j].nota);
      }
    
 
     }

}

fclose(fich);

}



void main()
{

escritura_fichero();

lectura();

}
