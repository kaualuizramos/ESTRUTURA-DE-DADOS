#include <stdio.h>
#define MAX 50

typedef struct {
    int chave;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int topo; // índice do topo (-1 = vazia)
} PilhaArray;

void inicializaPilha(PilhaArray *p) {
    p->topo = -1;
}

int isEmpty(PilhaArray *p) {
    return p->topo == -1;
}

int isFull(PilhaArray *p) {
    return p->topo == MAX - 1;
}

void push(PilhaArray *p, ELEMENTO e) {
    if (isFull(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->A[p->topo] = e;
}

ELEMENTO pop(PilhaArray *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        ELEMENTO e = {0};
        return e;
    }
    return p->A[p->topo--];
}

ELEMENTO top(PilhaArray *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        ELEMENTO e = {0};
        return e;
    }
    return p->A[p->topo];
}

void imprimePilha(PilhaArray *p) {
    printf("Pilha (topo -> base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->A[i].chave);
    }
    printf("\n");
}

int main() {
    PilhaArray pilha;
    inicializaPilha(&pilha);

    ELEMENTO e;

    e.chave = 10; push(&pilha, e);
    e.chave = 20; push(&pilha, e);
    e.chave = 30; push(&pilha, e);
    imprimePilha(&pilha);

    ELEMENTO removido = pop(&pilha);
    printf("Pop: %d\n", removido.chave);
    imprimePilha(&pilha);

    return 0;
}