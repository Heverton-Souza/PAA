#include <stdio.h>
#include <stdlib.h> 

#define N 40 

/* --------------------------------------------------
 * Função: input_vector
 * Solicita N inteiros ao usuário e preenche o vetor.
 * --------------------------------------------------*/
void input_vector(int v[N]) {
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("V[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

/* --------------------------------------------------
 * Função: is_valid
 * Calcula:
 *   soma  =  sum(x*|V1_i|)  (i ímpar)
 *   produto = prod(y*V2_j)  (j par)
 * Retorna 1 se soma <= produto, caso contrário 0.
 * --------------------------------------------------*/
int is_valid(int x, int y, int v1[N], int v2[N]) {
    int sum = 0;
    int product = 1;    
    
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 1) {
            sum += x * abs(v1[i]);
        } else {
            product *= y * v2[i];
        }
    }
    if (sum <= product){
        return 1;
    }
    else{
        return 0;
    }
}

/* --------------------------------------------------
 * main
 * --------------------------------------------------*/
int main(void) {
    int x, y;
    int V1[N], V2[N];

    /* leitura dos vetores */
    input_vector(V1);
    input_vector(V2);

    /* leitura de x e y  */
    printf("\nInsira um valor para x: ");
    scanf("%d", &x);
    printf("Insira um valor para y: ");
    scanf("%d", &y);

    if (x == 0 || y == 0)
    {
        printf("\nx e y devem ser diferentes de 0");
        return 0;
    }

    int resultado = is_valid(x, y, V1, V2);

    if (resultado == 1)
        printf("\nCondicao verdadeira\n");
    else
        printf("\nCondicao falsa\n");

    return 0;
}
