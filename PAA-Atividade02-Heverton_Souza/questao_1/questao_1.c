#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* --------------------------------------------------
 * Utilidades
 * --------------------------------------------------*/
void inputMatrix(int A[N][N]) {
    printf("\nDigite os %d x %d elementos da matriz (0-9):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
}

void randomMatrix(int A[N][N]) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            A[i][j] = rand() % 10; /* 0‑9 */
        }
    }
}

void printMatrix(int A[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j){
            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }
}

/* --------------------------------------------------
 * Subitens (funções)
 * --------------------------------------------------*/
int item_a(int A[N][N]) { /* soma de todos os elementos */
    int S = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            S += A[i][j];
        }
    }
    return S;
}

int item_b(int A[N][N]) { /* mesma soma, ordem invertida */
    int S = 0;
    for (int j = 0; j < N; ++j){
        for (int i = 0; i < N; ++i){
            S += A[i][j];
        }
    }
    return S;
}

int item_c(int A[N][N]) { /* soma fora da diagonal */
    int S = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (i != j){
                S += A[i][j];
            }
        }
    }
    return S;
}

int item_d(int A[N][N]) { /* soma na diagonal principal */
    int S = 0;
    for (int i = 0; i < N; ++i){
        S += A[i][i];
    }
    return S;
}

int item_e(int A[N][N]) { /* soma acima da diagonal */
    int S = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if(j > i){
                S += A[i][j];
            }
        }
    }
    return S;
}

int item_f(int A[N][N]) { /* soma abaixo da diagonal */
    int S = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < i; ++j){ 
            if(j < i){
                S += A[i][j];
            }
        }
    }
    return S;
}

int item_g(int A[N][N]) { /* soma dos produtos a_ij * a_ji com i < j (abaixo da diagonal) */
    int S = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if(i < j){
                S += A[i][j] * A[j][i];
            }
        }
    }
    return S;
}

int item_h(int A[N][N], int x) { /* soma x * A[i][j] */
    int S = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            S += x * A[i][j];
        }
    }
    return S;
}

void item_i(int A[N][N], int V[N]) { /* soma por linha */
    for (int i = 0; i < N; ++i) {
        int somaLinha = 0;
        for (int j = 0; j < N; ++j){
            somaLinha += A[i][j];
        }
        V[i] = somaLinha;
    }
    printf("\nVetor V (soma das linhas):\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", V[i]);
    putchar('\n');
}

void item_j(int A[N][N], int P[N]) { /* produto por coluna */
    for (int j = 0; j < N; ++j) {
        int produtoColuna = 1;
        for (int i = 0; i < N; ++i){
            produtoColuna *= A[i][j];
        }
        P[j] = produtoColuna;
    }
    printf("\nVetor P (produto das colunas):\n");
    for (int j = 0; j < N; ++j)
        printf("%d ", P[j]);
    putchar('\n');
}

/* --------------------------------------------------
 * Função principal
 * --------------------------------------------------*/
int main(void) {
    int A[N][N];

    /* Escolha de entrada */
    char resp;
    printf("Deseja digitar a matriz (d) ou gerar aleatoriamente (r)? ");
    scanf(" %c", &resp);

    if (resp == 'd' || resp == 'D')
        inputMatrix(A);
    else
        randomMatrix(A);

    /* Exibe a matriz gerada/digitada */
    printf("\nMatriz A:\n");
    printMatrix(A);

    /* Seleção do item */
    while(1){
        char item;
        printf("\nEscolha o item a executar (a-j) (sair = q): ");
        scanf(" %c", &item);

        int resultado; /* usado nos itens que retornam int */
        int V[N];
        int P[N];

        switch (item) {
            case 'a': case 'A':
                resultado = item_a(A);
                printf("\n(a) Soma total: %d\n", resultado);
                break;
            case 'b': case 'B':
                resultado = item_b(A);
                printf("\n(b) Soma total (ordem invertida): %d\n", resultado);
                break;
            case 'c': case 'C':
                resultado = item_c(A);
                printf("\n(c) Soma fora da diagonal: %d\n", resultado);
                break;
            case 'd': case 'D':
                resultado = item_d(A);
                printf("\n(d) Soma da diagonal principal: %d\n", resultado);
                break;
            case 'e': case 'E':
                resultado = item_e(A);
                printf("\n(e) Soma acima da diagonal: %d\n", resultado);
                break;
            case 'f': case 'F':
                resultado = item_f(A);
                printf("\n(f) Soma abaixo da diagonal: %d\n", resultado);
                break;
            case 'g': case 'G':
                resultado = item_g(A);
                printf("\n(g) Soma dos produtos a_ij * a_ji (i<j): %d\n", resultado);
                break;
            case 'h': case 'H': {
                int x;
                printf("Digite o valor de x: ");
                scanf("%d", &x);
                resultado = item_h(A, x);
                printf("\n(h) Soma de x*A[i][j]: %d\n", resultado);
                break; }
            case 'i': case 'I':
                item_i(A, V);
                break;
            case 'j': case 'J':
                item_j(A, P);
                break;
            case 'q': case 'Q':
                return 0;
            default:
                printf("\nOpcao invalida.\n");
        }
    }

}
