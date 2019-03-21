#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaMatriz(int *p, int filas, int columnas);
void multiplicacionF(int *A, int *B, int *C, int filas, int columnas);
void imprimeMatriz2D(int *p, int filas, int columnas);
void inicializaCero(int *p, int filas, int columnas);

void inicializaCero(int *p, int filas, int columnas){

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			*(p+i*columnas+j) = 0;
		}
	}	
}

void inicializaMatriz(int *p, int filas, int columnas){

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			*(p+i*columnas+j) = 1 + rand()%(11-1);
		}
	}
}

void imprimeMatriz2D(int *p, int filas, int columnas){

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			printf("%d\t", *(p+i*filas+j));
		}
		printf("\n");
	}
}

void multiplicacionF(int *A, int *B, int *C, int filas, int columnas){

	int tamanyo = filas; //La variable tamanyo tiene como proposito aclarar el for(int k)

	int f1,f2,r;

	for (int i = 0; i < filas; ++i){

		for (int j = 0; j < columnas; ++j){
			for (int k = 0; k < tamanyo; ++k){

			*(C + i*tamanyo + j) = *(C + i*tamanyo + j) + *(A + i*filas + k) * *(B + k*columnas + j);
			}
		}
	}
}


int main(int argc, char const *argv[])
{

	srand(time(NULL));
	
	int *matrizA;
	int *matrizB;
	int *matrizC;
	int filas, columnas;

	printf("Introduzca el tamanyo de la matriz\n");
	scanf("%d", &filas);
	columnas = filas;


	matrizA = (int *)malloc(sizeof(int)*filas*columnas);
	matrizB = (int *)malloc(sizeof(int)*filas*columnas);
	matrizC = (int *)malloc(sizeof(int)*filas*columnas);

	inicializaMatriz(matrizA, filas, columnas);
	inicializaMatriz(matrizB, filas, columnas);
	inicializaCero(matrizC, filas, columnas);

	multiplicacionF(matrizA, matrizB, matrizC, filas, columnas);

	printf("\nMatriz A:\n");
	imprimeMatriz2D(matrizA, filas, columnas);

	printf("\nMatriz B:\n");	
	imprimeMatriz2D(matrizB, filas, columnas);

	printf("\nMatriz C:\n");	
	imprimeMatriz2D(matrizC, filas, columnas);

	free(matrizA);
	free(matrizB);		
	free(matrizC);

	return 0;
}