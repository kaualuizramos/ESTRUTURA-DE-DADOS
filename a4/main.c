#include <stdio.h>
#include "arvore.h"

int main() {
    No* raiz = NULL;
    int opcao, codigo, quantidade;
    char nome[50];

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Buscar produto\n");
        printf("3 - Listar produtos\n");
        printf("4 - Mostrar menor codigo\n");
        printf("5 - Mostrar maior codigo\n");
        printf("6 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("Codigo: ");
                scanf("%d", &codigo);

                printf("Nome: ");
                scanf(" %[^\n]", nome);

                printf("Quantidade: ");
                scanf("%d", &quantidade);

                raiz = inserir(raiz, codigo, nome, quantidade);
                break;

            case 2: {
                printf("Codigo para busca: ");
                scanf("%d", &codigo);

                No* res = buscar(raiz, codigo);

                if (res != NULL)
                    printf("Encontrado: %s | Quantidade: %d\n",
                           res->nome, res->quantidade);
                else
                    printf("Produto nao encontrado.\n");
                break;
            }

            case 3:
                if (raiz == NULL)
                    printf("Arvore vazia.\n");
                else
                    emOrdem(raiz);
                break;

            case 4: {
                No* m = menor(raiz);
                if (m != NULL)
                    printf("Menor codigo: %d (%s)\n", m->codigo, m->nome);
                else
                    printf("Arvore vazia.\n");
                break;
            }

            case 5: {
                No* m = maior(raiz);
                if (m != NULL)
                    printf("Maior codigo: %d (%s)\n", m->codigo, m->nome);
                else
                    printf("Arvore vazia.\n");
                break;
            }

            case 6:
                liberar(raiz);
                printf("Memoria liberada. Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 6);

    return 0;
}