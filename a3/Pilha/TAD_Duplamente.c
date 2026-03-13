#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;

// Estrutura da pilha
typedef struct {
    No *top;   // topo da pilha
    int tamanho;  // quantidade de elementos
} Pilha;

// Criar pilha vazia
Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->top = NULL;
    p->tamanho = 0;
    return p;
}

// Verificar se a pilha está vazia
int isEmpty(Pilha *p) {
    return p->top == NULL;
}

// Inserir no topo (push)
void push(Pilha *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = p->top;

    if (p->top != NULL) {
        p->top->anterior = novo;
    }

    p->top = novo;
    p->tamanho++;
}

// Remover do topo (pop)
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1; // valor de erro
    }

    No *removido = p->top;
    int valor = removido->valor;

    p->top = removido->proximo;
    if (p->top != NULL) {
        p->top->anterior = NULL;
    }

    free(removido);
    p->tamanho--;

    return valor;
}

// Consultar o topo
int top(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->top->valor;
}

// Tamanho da pilha
int size(Pilha *p) {
    return p->tamanho;
}

// Imprimir pilha
void imprimePilha(Pilha *p) {
    No *atual = p->top;
    printf("Pilha (topo -> base): ");
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Liberar memória
void liberarPilha(Pilha *p) {
    while (!isEmpty(p)) {
        pop(p);
    }
    free(p);
}

// Teste
int main() {
    Pilha *p = criarPilha();

    push(p, 10);
    push(p, 20);
    push(p, 30);

    imprimePilha(p);
    printf("Topo: %d\n", top(p));
    printf("Tamanho: %d\n\n", size(p));

    printf("Pop: %d\n", pop(p));
    imprimePilha(p);
    printf("Topo: %d\n", top(p));
    printf("Tamanho: %d\n\n", size(p));

    push(p, 40);
    imprimePilha(p);
    printf("Topo: %d\n", top(p));
    printf("Tamanho: %d\n", size(p));

    liberarPilha(p);
    return 0;
}