#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do elemento da pilha
typedef struct Elemento {
    char nome[50];
    int numero;
    struct Elemento *proximo;
} Elemento;

// Estrutura da pilha
typedef struct {
    Elemento *top;
    int qtd;
} Pilha;

// Cria um novo elemento
Elemento* criaElemento(char *nome, int numero) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo) {
        strcpy(novo->nome, nome);
        novo->numero = numero;
        novo->proximo = NULL;
    }
    return novo;
}

// Inicializa a pilha
void inicializaPilha(Pilha *p) {
    p->top = NULL;
    p->qtd = 0;
}

// Verifica se a pilha está vazia
int isEmpty(Pilha *p) {
    return p->top == NULL;
}

// Empilha (push)
void push(Pilha *p, Elemento *e) {
    e->proximo = p->top;
    p->top = e;
    p->qtd++;
}

// Desempilha (pop)
Elemento* pop(Pilha *p) {
    if (isEmpty(p)) return NULL;
    Elemento *removido = p->top;
    p->top = removido->proximo;
    removido->proximo = NULL;
    p->qtd--;
    return removido;
}

// Consulta o topo (top)
Elemento* top(Pilha *p) {
    return p->top;
}

// Tamanho da pilha
int sizeOf(Pilha *p) {
    return p->qtd;
}

// Imprime a pilha
void imprimePilha(Pilha *p) {
    printf("Elementos da pilha (topo -> base):\n");
    printf("--------------------------------------------\n");
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n");
    } else {
        Elemento *e = p->top;
        while (e != NULL) {
            printf("%s | %d --> ", e->nome, e->numero);
            e = e->proximo;
        }
        printf("None\n");
    }
    printf("--------------------------------------------\n");
}

// Teste
int main() {
    Pilha p;
    inicializaPilha(&p);

    imprimePilha(&p);

    push(&p, criaElemento("A", 1));
    push(&p, criaElemento("B", 2));
    push(&p, criaElemento("C", 3));

    imprimePilha(&p);

    Elemento *removido = pop(&p);
    if (removido) {
        printf("\nRemovido: %s | %d\n", removido->nome, removido->numero);
        free(removido);
    }

    imprimePilha(&p);

    Elemento *t = top(&p);
    if (t) printf("\nTopo atual: %s | %d\n", t->nome, t->numero);

    return 0;
}