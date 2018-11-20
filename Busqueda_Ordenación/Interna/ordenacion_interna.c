
/*---------------------------------------------------------
	
	Alumno: Michaël José González Togni

	Asignatura: Estructura de datos.

	1º Examen Parcial

--------------------------------------------------------*/


#include <stdio.h>
#include "prototipos.h"
#define TAM 10


void insercion_directa(int v[], int n)//Método de la baraja: ordena el vector o campo introducido, se requiere que los elementos de su izquierda estén previamente ordenados,en nusestro caso 2 elementos.
{ 
    int i, j, aux;    
    
    for(i=1; i<n; i++)    //Recorremos el vector desde la segunda posicion.
    {  
        aux = v[i];    //Introducimos el valor de la posicion actual en la variable aux que actuará como bufer.

        j=i;        //Introducimos la posicion por la que vamos en el array dentro de la variable j para poder manejar dicha posicion en el bucle while siguiente.
        

        while((v[j-1]>aux) && (j>0))    //Mientras que el valor de la posicion anterior sea mayor al valor de la posicion actual que estamos examinando.
        {    
            v[j]=v[j-1];    //Asignamos el valor anterior del vector como valor de la pos actual.

            j--;        //Por cada vuelta de bucle, le restamos uno al contador j para situarnos en la posicion anterior del array
        }

        v[j]=aux;        //Almacenamos el valor de aux en el vector origen.
    }          

                                                             
}





void insercion_binaria(int v[], int n) 	//
{
    int i, j, aux, IZQ=0, DER;    
    
for(i=1; i<n; i++)
{    //Recorremos el vector
        aux = v[i];    //Introducimos el valor de la posicion actual en una variable aux que copiara su valor y ayudara a realizar el cambio de elementos en su orden correcto
		
      IZQ=1;		//Se definen los extremos del vector con los que trabajaremos.
	DER=i-1;
        

        while(IZQ<=DER)		//Mientras no se llegue al extremo final del vector se sigue con el proceso.
	  {   
	   int CEN=(IZQ+DER)/2;		// Se calcula la posición central del vector

		      if(v[CEN] <= aux)		//Si el valor de la posición central es menor o igual que el valor de aux, dicha posicion pasa a ser el extremo izquierdo.
			{
			IZQ=CEN+1;		// se incrementan los extremos para avanzar posiciones dentro del vector (en este caso IZQ).
			} 
			else 			//De lo contrario se considera como extremo derecho.
			{
			DER=CEN-1;
			}     
        }
    
	j=i;
	
	while(j>IZQ)		//situamos al vector en la posición IZQ

	{

	v[j]=v[j-1];
	j--;

	}

v[IZQ]=aux;		//Se coloca el valor en su nueva posición

}          

                                                             
}



 void ordenacion_seleccion_directa( int N, int v[N]){	//Este módulo no requiere de un vector parcialmente ordenado.


                           
  int I, J, K; 

  int AUX;  


 for(I=0;I<=(N-1);I++){ 		//Se recorren todas las posiciones del vector 

  K=I; 
  AUX= v[I];  		//Almacenamos el valor del vector (desde el principio del vector) en aux en cada iteracion.

     

  	for(J=(I+1);J<N;J++){ 	//Se comprueban los valores posteriores a aux, si hay alguno menor se almacena en AUX.

	 	if(v[J]<AUX ){ 

 		 K=J;    

		 AUX=v[J];    

 		}

	}

     

 	v[K]=v[I];    

 	v[I]=AUX;   //Se introduce el valor de AUX en el vector en la posición de la iteración actual.
 }

}




void ordenacion_intercambio_izq_der(int V[], int N)
{
	int I, J, AUX;
	for ( J=0;J<=(N-2);J++ ) //este for va reduciendo el array a medida que se van colocando los valores más grandes a la derecha, es decir, cuando está el más grande a la derecha ya no lo tiene en cuenta y así sucesivamente
	{
		for ( I=0;I<(N-J-1);I++) //este for e if compara el primer valor con el segundo, el segundo con el tercero y así hasta comparar todos para poner el valor más grande a la derecha
		{
			if ( V[I] > V[I+1] )
			{
				AUX=V[I];
				V[I]=V[I+1];
				V[I+1]=AUX;
			}
		}
	}
}

void ordenacion_sacudida(int V[], int N)	// Método de ordenación por vibración: 
{
	int I, IZQ, DER, AUX;
	IZQ=0;
	DER=N-1;
	while ( IZQ != DER )
	{
		for ( I=IZQ;I<=DER-1;I++)
		{
			if ( V[I] > V[I+1] )
			{
				AUX=V[I];
				V[I]=V[I+1];
				V[I+1]=AUX;
			}
		}
		DER=DER-1;
		if ( IZQ != DER )
		{
			for ( I=DER;I>=IZQ+1;I-- )
			{
				if ( V[I-1] > V[I] )
				{
					AUX=V[I-1];
					V[I-1]=V[I];
					V[I]=AUX;
				}
			}
			IZQ=IZQ+1;
		}
	}
}



int ordenacion_shell(int v[], int n)
{
int i, j, aux, distancia=n; //distancia igual al tamaño del verctor

	while (distancia != 1)  //salimos del bucle cuando lleguemeos a 1 en la distancia recorrida
	{

	distancia = distancia/2;  // en nuestro caso distancia inicial es la mitad de el tamaño del array.

		for (i=distancia; i < n ;i++) // Recorremos desde cada distancia hasta el final del array
		{

		aux= v[i];      //Almacenamos cada iteracion en la variable aux para cada distancia
		j=i;
		
		


			while ( ((j-distancia) >= 1) && (v[j-distancia] > aux) )
			{

			v[j]= v[j-distancia];
			j=j-distancia;
			
							//...

			}

		v[j]=aux;	

		

		}


	}


}




void mezclar( int V[TAM], int IZQ, int CEN, int DER ) 	//Divide y vencerás: en este algoritmo se divide el vector en dos mitades que serán ordenadas (en este módulo Mezclar) de forma recursiva.
{
	int TEMP[10];
	int I1, I2, I_TEMP;

	I1= IZQ;
	I2= CEN+1;
	I_TEMP= IZQ;

	while ( (I1 <= CEN) && (I2 <= DER) )	//Mientras no se haya recorrido completamente cada mitad, se comprueban los valores de cada una y se almacenan en el vector I_TEMP.
	{
		if ( V[I1] < V[I2] )		//Si el valor que está en la mitad izquierda es menor que el de la derecha, se almacena dicho valor del vector original (V[]) en  el bufer I_TEMP
		{
			TEMP[I_TEMP]=V[I1];
			I1=I1+1;				//Aumentamos la posición de la izquierda en una unidad.
		}
		else 						//De lo contrario almacenamos el valor de la mitad Derecha en el bufer I_TEMP y avanzamos la posicion de derecha.
		{
			TEMP[I_TEMP]=V[I2];
			I2=I2+1;
		}
		I_TEMP=I_TEMP+1; 	//Avanzamos la posicion del vector que actúa como bufer.
	}


	while ( I1 <= CEN )			//Realizamos el mismo proceso que arriba pero esta vez por separado, ya que se ha acabado de recorrer alguna de las dos mitades.
	{
		TEMP[I_TEMP]=V[I1];		// Recorremos en este bucle la mitad izquierda.
		I1=I1+1;
		I_TEMP=I_TEMP+1;
	}


	while ( I2 <= DER )			//Si la izquierda ya se ha recorrido en el primer bucle de este módulo saltamos directamente a este bucle para acabar de recorrer la derecha.
	{
		TEMP[I_TEMP]=V[I2];
		I2=I2+1;
		I_TEMP=I_TEMP+1;
	}


	for ( I_TEMP = IZQ;I_TEMP<=DER;I_TEMP++ )  //Escribimos los valores almacenados del vector bufer I_TEMP en en vector original V.
	{
		V[I_TEMP]=TEMP[I_TEMP];
	}
}

void ordenacion_por_mezcla( int V[TAM], int IZQ, int DER ) // En este módulo se divide V en dos mitades y se ordenan de forma recursiva luego se mezclan de ambas mitades conservando el orden.
{
	int CEN;
	if ( IZQ < DER )
	{
		CEN = (IZQ+DER)/2;
		ordenacion_por_mezcla( V, IZQ, CEN );  // Primera mitad,Izquierda.

		ordenacion_por_mezcla( V, (CEN+1), DER ); // Segunda mitad, Derecha

		mezclar( V, IZQ, CEN, DER );  //Llamada al módulo Mezclar
	}
}



void ordenacion_rapida(int v[10],int IZQ,int DER)
{

int i,j;

int pivote,aux;

i=IZQ;
j=DER;

pivote=v[(IZQ+DER)/2];

while(i<=j)
{
	while(v[i]<pivote)
	{
	 i=i+1;
	}

	while(v[j]>pivote)
	{
	 j=j-1;	
	}

	
	if(i<=j)
	{
	 aux=v[i];
	 v[i]=v[j];
	 v[j]=aux;
	 i=i+1;
	 j=j-1;
	}
}

if(IZQ<j)
{
ordenacion_rapida(v,IZQ,j);		//Llamada recursiva del propio módulo.

}

if(DER>i)
{

ordenacion_rapida(v,i,DER);

}


}




void mostrar(int tam, int c[]) // Módulo que muestra un vector de N elementos.

{
int z;

	for(z=0;z<tam;z++)
	{ // Para I desde 1 hasta N-1
			
			
     			printf(" %d", c[z]);
			
	}
                  printf("\n");  
}
