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
        alunos[i + 1] = alunos[i];  // desloca
        i--;
    }
    alunos[i + 1] = novo;
    (*n)++;
}

// Função recursiva de busca binária
int buscaBinariaRecursiva(Aluno alunos[], int inicio, int fim, char nome[]) {
    if (inicio > fim) {
        return 0; // não encontrado
    }

    int meio = (inicio + fim) / 2;
    int cmp = strcmp(alunos[meio].nome, nome);

    if (cmp == 0) {
        return 1; // encontrado
    } else if (cmp > 0) {
        return buscaBinariaRecursiva(alunos, inicio, meio - 1, nome);
    } else {
        return buscaBinariaRecursiva(alunos, meio + 1, fim, nome);
    }
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

        // Insere em ordem alfabética
        inserirOrdenado(alunos, &qtd, temp);
    }

    // Busca
    printf("\nInforme o nome para busca: ");
    scanf("%s", busca);

    if (buscaBinariaRecursiva(alunos, 0, qtd - 1, busca)) {
        printf("\nAluno %s encontrado!\n", busca);
    } else {
        printf("\nAluno %s NAO encontrado.\n", busca);
    }

    return 0;
}
