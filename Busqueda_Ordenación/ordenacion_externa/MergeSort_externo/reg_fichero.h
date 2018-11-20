/************************************************************************ 
*  							reg_ficheros.h     * 
*           * 
* Tipos y constantes utilizadas en los ejercicios de ficheros          * 
*           * 
*      (c) María Luisa Pérez Delgado -- 2015                              * 
************************************************************************/ 
#define TAM 80 

struct alumno
{ 
    char nombre[TAM];	  // nombre
	char apellidos[TAM];  // apellidos
    int NIA;              // número de id. académica 
    float nota;           // nota del alumnos
	int edad;			  // edad del alumno 
}; 

typedef struct alumno ALUMNO; 
