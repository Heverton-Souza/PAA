#include <stdio.h>
#include <math.h>

/* ---------- Prototipação das funções ---------- */
double soma_fracao_potencia(int a, int n);
float soma_produtos_dupla(int n, int m);
int eh_primo(int n);

/* ---------- Funções ---------- */
double soma_fracao_potencia(int a, int n)
{
    double s = 0.0;
    for (int i = 1; i <= n; ++i){
        s += (double)i / pow(a, i);
    }
    return s;
}

float soma_produtos_dupla(int n, int m)
{
    float s = 0.0f;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            s += (float)(i * j);
        }
    }
    return s;
}

int eh_primo(int n)
{
    if (n < 2){
        return 0;
    }
    for (int i = 2; i < n; ++i){
        if (n % i == 0){
            return 0;
        } 
    }
    return 1;
}

/* ---------- Função principal ---------- */
int main(void)
{
    while (1)
    {
        char item;
        printf("\nEscolha o item a executar (a-c) (sair = q): ");
        scanf(" %c", &item);

        switch (item)
        {
            case 'a': case 'A':
            {
                int a, n;
                printf("Entre com um valor para 'a' (a != 0): ");
                scanf("%d", &a);
                if (a == 0) {
                    puts("Erro: 'a' deve ser diferente de 0.");
                    break;
                }

                printf("Entre com um valor para 'n' (n >= 1): ");
                scanf("%d", &n);
                if (n < 1) {
                    puts("Erro: 'n' deve ser >= 1.");
                    break;
                }

                double resultado = soma_fracao_potencia(a, n);
                printf("Resultado (a): S = %.10f\n", resultado);
                break;
            }

            case 'b': case 'B':
            {
                int n, m;
                printf("Entre com um valor para 'n' (n >= 1): ");
                scanf("%d", &n);
                if (n < 1) {
                    puts("Erro: 'n' deve ser >= 1.");
                    break;
                }

                printf("Entre com um valor para 'm' (m >= 1): ");
                scanf("%d", &m);
                if (m < 1) {
                    puts("Erro: 'm' deve ser >= 1.");
                    break;
                }

                float resultado = soma_produtos_dupla(n, m);
                printf("Resultado (b): S = %.2f\n", resultado);
                break;
            }

            case 'c': case 'C':
            {
                int n;
                printf("Entre com um valor para 'n' (n > 0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    puts("Erro: 'n' deve ser > 0.");
                    break;
                }

                int primo = eh_primo(n);
                if (primo){
                    printf("Resultado (c): %d e primo.\n", n);
                }
                else{
                    printf("Resultado (c): %d NAO e primo.\n", n);
                }
                break;
            }

            case 'q': case 'Q':
                puts("Saindo. Ate mais!");
                return 0;

            default:
                puts("Opção invalida.");
        }
    }
}
