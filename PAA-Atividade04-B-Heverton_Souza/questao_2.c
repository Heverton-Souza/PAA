#include <stdio.h>

// Função de ordenação por Insertion Sort
void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        // Move os elementos maiores que chave para a direita
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

// Função para imprimir o vetor
void imprime_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função principal com entrada do usuário
int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nVetor original:\n");
    imprime_vetor(v, n);

    insertion_sort(v, n);

    printf("\nVetor ordenado:\n");
    imprime_vetor(v, n);

    return 0;
}
