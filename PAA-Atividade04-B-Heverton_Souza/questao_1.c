#include <stdio.h>
#include <limits.h>  // para INT_MAX e INT_MIN

// Função (d): mínimo da soma das colunas
int min_soma_colunas(int n, int m, int A[n][m]) {
    int min = INT_MAX;

    for (int j = 0; j < m; j++) {
        int soma = 0;
        for (int i = 0; i < n; i++) {
            soma += A[i][j];
        }
        if (soma < min)
            min = soma;
    }

    return min;
}

// Função (e): máximo do produto das linhas
int max_prod_linhas(int n, int m, int B[n][m]) {
    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = 0; j < m; j++) {
            prod *= B[i][j];
        }
        if (prod > max)
            max = prod;
    }

    return max;
}

// Função (f): soma dos elementos acima da diagonal principal
int soma_acima_diagonal(int n, int C[n][n]) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            soma += C[i][j];
        }
    }

    return soma;
}

// Função para ler uma matriz
void ler_matriz(int n, int m, int M[n][m]) {
    printf("Digite os elementos da matriz (%dx%d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

int main() {
    char opcao;
    int n, m;

    while (1) {
        printf("\nEscolha a função para executar:\n");
        printf("d - Mínimo da soma das colunas\n");
        printf("e - Máximo do produto das linhas\n");
        printf("f - Soma acima da diagonal principal\n");
        printf("q - Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'q' || opcao == 'Q') {
            printf("Encerrando o programa.\n");
            break;
        }

        switch (opcao) {
            case 'd': case 'D': {
                printf("\n--- Mínimo da soma das colunas ---\n");
                printf("Digite o número de linhas (n): ");
                scanf("%d", &n);
                printf("Digite o número de colunas (m): ");
                scanf("%d", &m);

                int A[n][m];
                ler_matriz(n, m, A);

                int resultado = min_soma_colunas(n, m, A);
                printf("Resultado: %d\n", resultado);
                break;
            }

            case 'e': case 'E': {
                printf("\n--- Máximo do produto das linhas ---\n");
                printf("Digite o número de linhas (n): ");
                scanf("%d", &n);
                printf("Digite o número de colunas (m): ");
                scanf("%d", &m);

                int B[n][m];
                ler_matriz(n, m, B);

                int resultado = max_prod_linhas(n, m, B);
                printf("Resultado: %d\n", resultado);
                break;
            }

            case 'f': case 'F': {
                printf("\n--- Soma acima da diagonal principal ---\n");
                printf("Digite a ordem da matriz quadrada (n): ");
                scanf("%d", &n);

                int C[n][n];
                ler_matriz(n, n, C);

                int resultado = soma_acima_diagonal(n, C);
                printf("Resultado: %d\n", resultado);
                break;
            }

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
