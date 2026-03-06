#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da lista
typedef struct No {
    char url[100];
    struct No *anterior;
    struct No *proximo;
} No;

// Estrutura do navegador
typedef struct {
    No *cabeca;
    No *cauda;
    No *pagina_atual;
    int tamanho;
} Navegador;


// Criar navegador
void iniciar_navegador(Navegador *nav){

    nav->cabeca = (No*) malloc(sizeof(No));
    nav->cauda = (No*) malloc(sizeof(No));

    nav->cabeca->proximo = nav->cauda;
    nav->cabeca->anterior = NULL;

    nav->cauda->anterior = nav->cabeca;
    nav->cauda->proximo = NULL;

    nav->pagina_atual = NULL;
    nav->tamanho = 0;
}


// visitar página
void visitar_pagina(Navegador *nav, char *url){

    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->url, url);

    novo->anterior = nav->cauda->anterior;
    novo->proximo = nav->cauda;

    nav->cauda->anterior->proximo = novo;
    nav->cauda->anterior = novo;

    nav->pagina_atual = novo;

    nav->tamanho++;
}


// voltar página
char* voltar(Navegador *nav){

    if(nav->pagina_atual == NULL || nav->pagina_atual->anterior == nav->cabeca){
        printf("Nao ha paginas para voltar\n");
        return NULL;
    }

    nav->pagina_atual = nav->pagina_atual->anterior;

    return nav->pagina_atual->url;
}


// avançar página
char* avancar(Navegador *nav){

    if(nav->pagina_atual == NULL || nav->pagina_atual->proximo == nav->cauda){
        printf("Nao ha paginas para avancar\n");
        return NULL;
    }

    nav->pagina_atual = nav->pagina_atual->proximo;

    return nav->pagina_atual->url;
}


// mostrar histórico
void exibir_historico(Navegador *nav){

    No *atual = nav->cabeca->proximo;

    while(atual != nav->cauda){

        printf("%s <-> ", atual->url);

        atual = atual->proximo;
    }

    printf("FIM\n");
}


// buscar página
int buscar_pagina(Navegador *nav, char *url){

    No *atual = nav->cabeca->proximo;

    while(atual != nav->cauda){

        if(strcmp(atual->url, url) == 0)
            return 1;

        atual = atual->proximo;
    }

    return 0;
}


// remover página
void remover_pagina(Navegador *nav, char *url){

    No *atual = nav->cabeca->proximo;

    while(atual != nav->cauda){

        if(strcmp(atual->url, url) == 0){

            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;

            if(nav->pagina_atual == atual)
                nav->pagina_atual = atual->anterior;

            free(atual);

            nav->tamanho--;

            printf("Removendo '%s' do historico...\n", url);

            return;
        }

        atual = atual->proximo;
    }

    printf("Pagina nao encontrada\n");
}


// total de páginas
int obter_numero_paginas(Navegador *nav){
    return nav->tamanho;
}


// liberar memória
void liberar_navegador(Navegador *nav){

    No *atual = nav->cabeca;

    while(atual != NULL){

        No *temp = atual;

        atual = atual->proximo;

        free(temp);
    }
}


// MAIN
int main(){

    Navegador navegador;

    iniciar_navegador(&navegador);

    visitar_pagina(&navegador,"google.com");
    visitar_pagina(&navegador,"github.com");
    visitar_pagina(&navegador,"stackoverflow.com");

    printf("Historico de navegacao:\n");
    exibir_historico(&navegador);

    printf("Voltando para: %s\n", voltar(&navegador));
    printf("Voltando para: %s\n", voltar(&navegador));

    printf("Avancando para: %s\n", avancar(&navegador));

    printf("Buscando 'github.com': %s\n",
        buscar_pagina(&navegador,"github.com") ?
        "Encontrado" : "Nao encontrado");

    remover_pagina(&navegador,"github.com");

    printf("Historico apos remocao:\n");
    exibir_historico(&navegador);

    printf("Total de paginas visitadas: %d\n",
        obter_numero_paginas(&navegador));

    liberar_navegador(&navegador);

    return 0;
}