#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int codigo;
    char nome[50];
    int quantidade;
    struct No *esq, *dir;
} No;

// Funções
No* inserir(No* raiz, int codigo, char nome[], int quantidade);
No* buscar(No* raiz, int codigo);
void emOrdem(No* raiz);
No* menor(No* raiz);
No* maior(No* raiz);
void liberar(No* raiz);

#endif