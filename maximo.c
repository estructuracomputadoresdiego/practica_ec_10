#include <stdio.h>
#include <stdlib.h>

void inicializa (int *p, int n);
int calculamaximo(int *p, int n);
void imprimirPuntero(int *p, int n);

void inicializa (int *p, int n){

	for(int i = 0; i < n; ++i){
		
		printf("Introduzca un numero\n");
		scanf("%d",&*(p+i));
	}
}

int calculamaximo(int *p, int n){

	int maximo = *p;

	for(int i = 1; i < n; ++i){
		if (maximo < *(p+i))
		{
			maximo = *(p+i);
		}
	}

	return maximo;
}

void imprimirPuntero(int *p, int n){

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(p+i) );
	}
	printf("\n");
}

int main(int argc, char const *argv[]){
	int cuantosEnteros, maximo;

	printf("¿De cuantos numeros quieres hallar el maximo?\n");
	scanf("%d",&cuantosEnteros);

	int *enteros;
	enteros = (int *)malloc(sizeof(int)*cuantosEnteros);

	inicializa(enteros, cuantosEnteros);
	maximo = calculamaximo(enteros, cuantosEnteros);
	printf("El maximo es %d\n", maximo);
	printf("El puntero dado es: ");
	imprimirPuntero(enteros, cuantosEnteros);

	return 0;
}