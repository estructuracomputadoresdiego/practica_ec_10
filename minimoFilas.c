#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaMatriz(int *p, int filas, int columnas);
void minimoF(int *p, int *min, int filas, int columnas);
void imprimeMatriz2D(int *p, int filas, int columnas);
void imprimeMatriz1D(int *p, int columnas);

void inicializaMatriz(int *p, int filas, int columnas){

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			*(p+i*columnas+j) = 35 + rand()%(70-35);
		}
	}
}

void imprimeMatriz2D(int *p, int filas, int columnas){

	printf("\nLa matriz es: \n");

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			printf("%d\t", *(p+i*columnas+j));
		}
		printf("\n");
	}
}

void imprimeMatriz1D(int *p, int filas){

	printf("\nLos valores minimos de cada fila son: \n");

	for (int j = 0; j < filas; ++j){
		printf("%d\t", *(p+j));
	}
	printf("\n");
}

void minimoF(int *p, int *min, int filas, int columnas){

	for (int j = 0; j < filas; ++j){

		*(min + j) = *(p + j*columnas);

		for (int i = 0; i < columnas; ++i){
			if (*(min + j) > *(p + j*columnas + i)){

				*(min + j) = *(p + j*columnas + i);
			}
		}
	}
}


int main(int argc, char const *argv[])
{

	srand(time(NULL));
	
	int *matriz;
	int *valoresMinimos;
	int filas, columnas;

	printf("Introduzca el numero de filas\n");
	scanf("%d", &filas);
	printf("Introduzca el numero de columnas\n");
	scanf("%d", &columnas);

	matriz = (int *)malloc(sizeof(int)*filas*columnas);
	valoresMinimos = (int *)malloc(sizeof(int)*filas);

	inicializaMatriz(matriz, filas, columnas);
	minimoF(matriz, valoresMinimos, filas, columnas);

	imprimeMatriz2D(matriz, filas, columnas);
	imprimeMatriz1D(valoresMinimos, filas);

	return 0;
}