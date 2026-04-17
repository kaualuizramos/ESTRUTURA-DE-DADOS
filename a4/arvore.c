#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

No* criarNo(int codigo, char nome[], int quantidade) {
    No* novo = (No*) malloc(sizeof(No));
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int codigo, char nome[], int quantidade) {
    if (raiz == NULL)
        return criarNo(codigo, nome, quantidade);

    if (codigo < raiz->codigo)
        raiz->esq = inserir(raiz->esq, codigo, nome, quantidade);
    else if (codigo > raiz->codigo)
        raiz->dir = inserir(raiz->dir, codigo, nome, quantidade);
    else
        printf("Erro: codigo %d ja existe!\n", codigo);

    return raiz;
}

No* buscar(No* raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo)
        return raiz;

    if (codigo < raiz->codigo)
        return buscar(raiz->esq, codigo);
    else
        return buscar(raiz->dir, codigo);
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("Codigo: %d | Nome: %s | Quantidade: %d\n",
               raiz->codigo, raiz->nome, raiz->quantidade);
        emOrdem(raiz->dir);
    }
}

No* menor(No* raiz) {
    if (raiz == NULL) return NULL;

    while (raiz->esq != NULL)
        raiz = raiz->esq;

    return raiz;
}

No* maior(No* raiz) {
    if (raiz == NULL) return NULL;

    while (raiz->dir != NULL)
        raiz = raiz->dir;

    return raiz;
}

void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}