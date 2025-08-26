#include <stdio.h>
#include <string.h>

#define N 100

// Definição da struct
typedef struct {
    int matricula;
    char nome[50];
    float nota1, nota2, media;
} Aluno;

// Função para inserir aluno mantendo ordem alfabética
void inserirOrdenado(Aluno alunos[], int *n, Aluno novo) {
    int i = *n - 1;
    while (i >= 0 && strcmp(alunos[i].nome, novo.nome) > 0) {
        alunos[i + 1] = alunos[i];  // desloca para frente
        i--;
    }
    alunos[i + 1] = novo;
    (*n)++;
}

// Busca binária por nome
int buscaBinaria(Aluno alunos[], int n, char nome[]) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        int cmp = strcmp(alunos[meio].nome, nome);

        if (cmp == 0) {
            return 1; // encontrado
        } else if (cmp < 0) {
            inicio = meio + 1; // procura na direita
        } else {
            fim = meio - 1; // procura na esquerda
        }
    }
    return 0; // não encontrado
}

int main() {
    Aluno alunos[N];
    int qtd = 0;
    Aluno temp;
    char busca[50];

    // Inserindo alunos em ordem
    for (int i = 0; i < N; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &temp.matricula);

        printf("Primeiro nome (Ex: Maria): ");
        scanf("%s", temp.nome);

        printf("Nota 1: ");
        scanf("%f", &temp.nota1);

        printf("Nota 2: ");
        scanf("%f", &temp.nota2);

        temp.media = (temp.nota1 + temp.nota2) / 2.0;

        // Insere já na posição correta
        inserirOrdenado(alunos, &qtd, temp);
    }

    // Busca
    printf("\nInforme o nome para busca: ");
    scanf("%s", busca);

    if (buscaBinaria(alunos, qtd, busca)) {
        printf("\nAluno %s encontrado!\n", busca);
    } else {
        printf("\nAluno %s NAO encontrado.\n", busca);
    }

    return 0;
}
