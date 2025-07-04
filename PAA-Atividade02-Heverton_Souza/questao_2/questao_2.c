#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

/* --------------------------------------------------
 * Função: preencherVetor
 * Preenche V com inteiros aleatórios de 1 a 100.
 * --------------------------------------------------*/
void preencherVetor(int V[N]) {
    for (int i = 0; i < N; i++){
        V[i] = rand() % 100 + 1; /* 1‑100 */
    }
}

/* --------------------------------------------------
 * Função: modificarVetor
 * Transforma V[i] na soma de todos os demais elementos.
 * (sem vetor auxiliar)
 * --------------------------------------------------*/
void modificarVetor(int V[N]) {
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (i != j)
            {
                V[i] += V[j];
            }
        }
    }
}

/* --------------------------------------------------
 * Função: imprimirVetor
 * Mostra o vetor com uma mensagem identificadora.
 * --------------------------------------------------*/
void imprimirVetor(int V[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", V[i]);
    }
}

/* --------------------------------------------------
 * Função principal
 * --------------------------------------------------*/
int main(void) {
    int V[N];

    /* Inicializa gerador de aleatórios uma única vez */
    srand((unsigned)time(NULL));

    preencherVetor(V);
    printf("\nVetor Original: \n");
    imprimirVetor(V);
    printf("\n");
    printf("\nVetor Modificado: \n");
    modificarVetor(V);
    imprimirVetor(V);

    return 0;
}
