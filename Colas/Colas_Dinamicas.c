#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadero 1
#define falso 0
#define TAM 200




struct nodo_cola{

	char letra;
	struct nodo_cola *enlace;
};
typedef struct nodo_cola NODO_C;




int Cola_vacia(NODO_C *ptro_cola)
{
	if(ptro_cola == NULL) return verdadero;
	else return falso;
}




void Encolar(char elemento, NODO_C **entrada, NODO_C **salida)
{
	NODO_C *nuevo;

	nuevo = malloc(sizeof(NODO_C));

	if(nuevo == NULL) printf("No hay memoria disponible.\n");
	else{
		nuevo->letra=elemento;
		nuevo->enlace = NULL;

		if(Cola_vacia(*salida) == verdadero) *salida = nuevo;

		else	(*entrada)->enlace = nuevo;

	}

	*entrada = nuevo;
}




int Desencolar(char *elemento, NODO_C **entrada, NODO_C **salida)
{
	NODO_C *p;


	if(Cola_vacia(*entrada) == verdadero){

		printf("La cola está vacía.\n");
		return falso;
	}
	else{

		*elemento = (*salida)->letra;
		p = *salida;
		*salida = (*salida)->enlace;

		if(*salida == NULL){
			*entrada = NULL;
		}

		free(p);
	}

	return verdadero;

}




int Imprimir( NODO_C **entrada, NODO_C **salida)
{
	NODO_C *p;

	if(Cola_vacia(*entrada) == verdadero){

		printf("La cola está vacía.\n");
		return falso;
	}
	else{

		while(*salida != NULL){

		char elemento=(*salida)->letra;
		printf("%c",elemento);
		p = *salida;
		*salida = (*salida)->enlace;


		if(*salida == NULL) {*entrada = NULL;}

		free(p);

	}
		return verdadero;

	}

	

}




int Acceder(NODO_C *salida,char *elemento)
{
	if(Cola_vacia(salida) == verdadero){

		printf("La cola está vacía.\n");
		return falso;
	}
	else{
		*elemento=salida->letra;
		return verdadero;
	}
}




void Vaciar(NODO_C **entrada, NODO_C **salida)
{
	char elemento;

	while(Cola_vacia(*entrada) == falso){

		Desencolar(&elemento, entrada, salida);
	}
}



void main()
{
	char texto[TAM],vocales[]="aeiou",let;
	NODO_C **Entrada=NULL,**Salida=NULL;
	int i,j;
	FILE *fich;
	char *Elemento =malloc(sizeof(char));
	char a;

	Entrada=malloc(sizeof(NODO_C ));
	Salida=malloc(sizeof(NODO_C ));

	if((fich=fopen("fichero","w"))==NULL) printf("Error de apertura\n");
	 

	 printf("Introduce una frase:\n");
	 fgets(texto,TAM,stdin);
	 fprintf(fich,"%s",texto);
	 fclose(fich);

	 printf("Introduce una vocal:\n");
	 scanf(" %c",&let);

	if((fich=fopen("fichero","r"))==NULL) printf("Error de apertura\n");
	 
	 while(!feof(fich)){
	 a=fgetc(fich);
	 		

	 		if(a!=EOF){
			 	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
			 	{
			 		Encolar(let,Entrada,Salida);
			 		//printf("%c",let );
			 	}
			 	else {
			 		Encolar(a,Entrada,Salida);
			 		//printf("%c",a );
			 	}
			 }
			 	

	  }

//	printf("PASO1\n");

	fclose(fich); 

//*Elemento ='k';
	for(i=0;i<strlen(texto);i++){

		//printf("%d\n",strlen(texto) );
		 Desencolar(Elemento,Entrada,Salida); 
		 printf("%c", *Elemento);
		 
	}


 //Imprimir(Entrada,Salida);
		 

}



