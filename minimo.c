#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaMatriz(int *p, int filas, int columnas);
int calculaMinimo(int *p, int filas, int columnas);
void imprimeMatriz(int *p, int filas, int columnas);

void inicializaMatriz(int *p, int filas, int columnas){

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			*(p+i*columnas+j) = 25 + rand()%(101-25);
		}
	}
}

int calculaMinimo(int *p, int filas, int columnas){

	int minimo = *p;

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			if (*(p+i*columnas+j) < minimo)
			{
				minimo = *(p+i*columnas+j);
			}
		}
	}

	return minimo;
}

void imprimeMatriz(int *p, int filas, int columnas){

	printf("\nLa matriz es: \n");

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			printf("%d\t", *(p+i*columnas+j));
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{

	srand(time(NULL));

	int *matriz;
	int filas, columnas;

	printf("Introduzca el numero de filas\n");
	scanf("%d", &filas);
	printf("Introduzca el numero de columnas\n");
	scanf("%d", &columnas);

	matriz = (int *)malloc(sizeof(int)*filas*columnas);
	inicializaMatriz(matriz, filas, columnas);
	imprimeMatriz(matriz, filas, columnas);

	printf("\nEl minimo es %d \n", calculaMinimo(matriz, filas, columnas));

	return 0;
}