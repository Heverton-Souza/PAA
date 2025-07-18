#include <stdio.h>

// Função (d): mínimo da soma das colunas
int min_soma_colunas(int n, int m, int A[n][m]) {
    int min = 9999999;

    for (int j = 0; j < m; j++) {
        int soma = 0;
        for (int i = 0; i < n; i++) {
            soma += A[i][j];
        }
        if (soma < min){
            min = soma;
        }
    }

    return min;
}

// Função (e): máximo do produto das linhas
int max_prod_linhas(int n, int m, int B[n][m]) {
    int max = -9999999;

    for (int i = 0; i < n; i++) {           
        int prod = 1;                     
        for (int j = 0; j < m; j++) {       
            prod *= B[i][j];                
        }
        if (prod > max){                  
            max = prod;                  
        }
    }

    return max;
}

// Função (f): soma dos elementos acima da diagonal principal
int soma_acima_diagonal(int n, int C[n][n]) {
    int soma = 0;

    for (int i = 0; i < n; i++) {          //n+1
        for (int j = 0; j < n; j++) {      //n*(n+1)
            if(i < j){                     //n*n
                soma += C[i][j];           //n*n
            }
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
        printf("\nEscolha a funcao para executar:\n");
        printf("d - Minimo da soma das colunas\n");
        printf("e - Maximo do produto das linhas\n");
        printf("f - Soma acima da diagonal principal\n");
        printf("q - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'q' || opcao == 'Q') {
            printf("Encerrando o programa.\n");
            break;
        }

        switch (opcao) {
            case 'd': case 'D': {
                printf("\n--- Minimo da soma das colunas ---\n");
                printf("Digite o numero de linhas (n): ");
                scanf("%d", &n);
                printf("Digite o numero de colunas (m): ");
                scanf("%d", &m);

                int A[n][m];
                ler_matriz(n, m, A);

                int resultado = min_soma_colunas(n, m, A);
                printf("Resultado: %d\n", resultado);
                break;
            }

            case 'e': case 'E': {
                printf("\n--- Maximo do produto das linhas ---\n");
                printf("Digite o numero de linhas (n): ");
                scanf("%d", &n);
                printf("Digite o numero de colunas (m): ");
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
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
