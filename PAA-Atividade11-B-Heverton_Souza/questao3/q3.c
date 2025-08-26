#include <stdio.h>
#include <string.h>

#define N 100

// Definição da struct
typedef struct {
    int matricula;
    char nome[50];
    float nota1, nota2, media;
} Aluno;

// Função de busca sequencial
int buscaSequencial(Aluno alunos[], int n, float M) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (alunos[i].media >= M) {
            count++;
        }
    }
    return count;
}

int main() {
    Aluno alunos[N];
    float M;

    // Preenchimento do vetor
    for (int i = 0; i < N; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Primeiro nome: ");
        scanf("%s", alunos[i].nome);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
    }

    // Busca
    printf("\nInforme a media M para busca: ");
    scanf("%f", &M);

    int resultado = buscaSequencial(alunos, N, M);
    printf("\nQuantidade de alunos com media >= %.2f: %d\n", M, resultado);

    return 0;
}