#include <stdio.h>
#include <stdlib.h>

#define verdadero 1
#define falso 0
#define TAM 10




int siguiente(int indice, int N)
{
	return (indice + 1) % N;
}




int Cola_vacia(int num_elem)
{
	if(num_elem == 0) return verdadero;
	else return falso;
}




int Cola_llena(int num_elem, int N)
{
	if(num_elem == N) return verdadero;
	else return falso;
}




void Encolar(int Cola[], int *entrada, int *salida, int *num_elem, int N, int elemento)
{
	if(Cola_llena(*num_elem, N) == verdadero) printf("Cola llena. No se puede encolar.\n");
	else{
		*entrada = siguiente(*entrada,N);

		if(Cola_vacia(*num_elem) == verdadero) { *salida = *entrada; }

		Cola[*entrada] = elemento;

		*num_elem = *num_elem + 1;
	}
}




int Desencolar(int Cola[], int *entrada, int *salida, int *num_elem, int N, int *elemento)
{
	if(Cola_vacia(*num_elem) == verdadero){

		printf("Cola vacía. No se puede desencolar.\n");
		return falso;
	}
	else{
		*elemento = Cola[*salida];
		*salida = siguiente(*salida,N);
		//*num_elem = *num_elem - 1;

		if(Cola_vacia(*num_elem) == verdadero){

			*entrada = -1;
			*salida =-1;
		}

		return verdadero;
	}
}




int Acceder(int Cola[], int salida, int num_elem, int *elemento)
{
	if(Cola_vacia(num_elem) == verdadero){

		printf("Cola vacía. No se puede desencolar.\n");
		return falso;
	}
	else{
		*elemento = Cola[salida];
		return verdadero;
	}
}




void Mostrar(int Cola[], int *num_elem,int salida)
{
	int i;

	for(i = salida;i<*num_elem;i++){

		printf("Elemento %d de la cola con valor %d || salida %d \n",i+1, Cola[i],salida);
	}
}




void main()
{
	int N = TAM;
	int Cola[N];
	int salida = -1;
	int entrada = -1;
	int num_elem = 0;
	int elemento;
	int i;

	//void Encolar(int Cola[], int *entrada, int *salida, int *num_elem, int N, int elemento)

	Encolar(Cola, &entrada, &salida, &num_elem, N, 15);
	Encolar(Cola, &entrada, &salida, &num_elem, N, 45);
	Encolar(Cola, &entrada, &salida, &num_elem, N, 86);
	Encolar(Cola, &entrada, &salida, &num_elem, N, 381);
	Encolar(Cola, &entrada, &salida, &num_elem, N, 500);

	Mostrar(Cola,&num_elem,salida);
//int Desencolar(int Cola[], int *entrada, int *salida, int *num_elem, int N, int *elemento)
	//int Acceder(int Cola[], int salida, int num_elem, int *elemento)
	//Acceder(Cola, salida, num_elem,&elemento);
	Desencolar(Cola, &entrada, &salida, &num_elem, N, &elemento);
	Desencolar(Cola, &entrada, &salida, &num_elem, N, &elemento);

printf("\n-------------------\n");

	Mostrar(Cola, &num_elem, salida);

printf("\n-------------------\n");

	Encolar(Cola, &entrada, &salida, &num_elem, N, 500);


	Mostrar(Cola, &num_elem, salida);

printf("\n-------------------\n");

	Desencolar(Cola, &entrada, &salida, &num_elem, N, &elemento);
	Mostrar(Cola, &num_elem, salida);

}


