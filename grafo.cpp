#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////
// Programa que implementa um grafo //
///////////////////////////////////// 

const int TAMANHO = 5;

int setTamanho () { // escolhe o tamanho da matriz
	
	int retorno = 0;
	
	printf("Determine o tamanho do grafo: ");
	scanf("%d", &retorno);
	
	return retorno;
	
}

int** criar (int tamanho) { // funcao que cria matriz -> int** = ponteiro (que representa uma linha),
							// que aponta para um ponteiro (que representa uma coluna) que aponta para um int 
	
	int i = 0;
	int j = 0;
	
	int **grafo = (int **) malloc(tamanho * sizeof(int *));

	for (i = 0; i < tamanho; i++) {
		
		grafo[i] = (int *) malloc(tamanho * sizeof(int));
		
	}

	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < tamanho; j++) {
			
			grafo[i][j] = 0;
			
		}
		
	}
	
	return grafo;
	
}

void preencher (int **grafo, int tamanho) {
	
	int i = 0;
	int j = 0;
	int amigo = 0;
	
	for (i = 0; i < (tamanho - 1); i++) {
		for (j = (i + 1); j < tamanho; j++) {
			
			printf("Digite <1> se %d for amigo de %d:\t", i, j);
			scanf("%d", &amigo);
			
			grafo[i][j] = amigo;
			grafo[j][i] = amigo;			
		}
		
	}
	
}

void imprimir(int ** grafo, int tamanho) {
	
	int i = 0;
	int j = 0;
	
	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < tamanho; j++) {
			
			printf("%d\t", grafo[i][j]);
			
		}
		
		printf("\n");
	}
	
}

int descobrirVerticeMaisPopular(int **grafo, int tamanho) {
	
	int vertice = -1;
	int qtdAmigo = 0;
	int contador = 0; 
	int i = 0;
	int j = 0;
	
	for (i = 0; i < tamanho; i++) {
		contador = 0;
	
		for (j = 0; j < tamanho; j++) {
			
			if (grafo[i][j]) {
				
				contador++;
				
			}
			
		}
		
		if (contador > qtdAmigo) {
			
			vertice = i;
			qtdAmigo = contador;
			
		}
	}
	
	return vertice;
	
}

int main () {
	
	int tamanho = setTamanho();
	
	int **grafo = criar(tamanho);
	
	preencher(grafo, tamanho);
	
	imprimir(grafo, tamanho);
	
	int vertice = descobrirVerticeMaisPopular(grafo, tamanho);
	printf("O vertice mais popular eh: %d\n", vertice);
	
}
