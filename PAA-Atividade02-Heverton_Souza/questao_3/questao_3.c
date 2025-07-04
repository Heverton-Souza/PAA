#include <stdio.h>

#define N 30 

/* --------------------------------------------------
 * Lê N inteiros do teclado
 * --------------------------------------------------*/
void lerVetor(int v[N]) {
    for (int i = 0; i < N; ++i) {
        printf("V[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

/* --------------------------------------------------
 * Devolve a maior soma de k elementos consecutivos
 * --------------------------------------------------*/
int maiorSomaIntervalo(const int v[N], int k) {
    int maxSoma = 0;    

    for (int i = 0; i <= N - k; ++i) {
        int somaAtual = 0;
        for (int j = 0; j < k; ++j)    
            somaAtual += v[i + j];

        if (i == 0 || somaAtual > maxSoma)
            maxSoma = somaAtual;
    }
    return maxSoma;
}

/* --------------------------------------------------
 * main
 * --------------------------------------------------*/
int main(void) {
    int V[N];
    int k;

    lerVetor(V);

    /* lê k garantindo 1 ≤ k ≤ 4 */
    while (k < 1 || k > 4){
        printf("Digite k (1-4): ");
        scanf("%d", &k);
    }

    int resultado = maiorSomaIntervalo(V, k);

    printf("\nMaior soma de %d elementos consecutivos = %d\n", k, resultado);
    return 0;
}
