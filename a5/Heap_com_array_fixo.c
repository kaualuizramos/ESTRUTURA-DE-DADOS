#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 20

typedef struct {
    int id;
    char descricao[100];
    int prioridade;
} Chamado;

typedef struct {
    Chamado data[MAX_HEAP_SIZE];
    int size;
} HeapMax;

// Índices
int parent(int i) { return (i - 1) / 2; }
int left_child(int i) { return (2 * i + 1); }
int right_child(int i) { return (2 * i + 2); }

// Troca
void swap(Chamado *a, Chamado *b) {
    Chamado temp = *a;
    *a = *b;
    *b = temp;
}

// Subir
void heapify_up(HeapMax *heap, int index) {
    while (index > 0 &&
           heap->data[index].prioridade >
           heap->data[parent(index)].prioridade) {

        swap(&heap->data[index], &heap->data[parent(index)]);
        index = parent(index);
    }
}

// Descer
void heapify_down(HeapMax *heap, int index) {
    int left = left_child(index);
    int right = right_child(index);
    int largest = index;

    if (left < heap->size &&
        heap->data[left].prioridade >
        heap->data[largest].prioridade) {
        largest = left;
    }

    if (right < heap->size &&
        heap->data[right].prioridade >
        heap->data[largest].prioridade) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapify_down(heap, largest);
    }
}

// Inicializa
void init_heap(HeapMax *heap) {
    heap->size = 0;
}

// Inserir
void heap_insert(HeapMax *heap, Chamado c) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Erro: Heap cheio!\n");
        return;
    }

    heap->data[heap->size] = c;
    heapify_up(heap, heap->size);
    heap->size++;

    printf("Chamado inserido com sucesso.\n");
}

// Remover maior
Chamado heap_extract_max(HeapMax *heap) {
    Chamado vazio = {-1, "", -1};

    if (heap->size == 0) {
        printf("Erro: Heap vazio!\n");
        return vazio;
    }

    Chamado max = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    heapify_down(heap, 0);

    return max;
}

// Ver topo
void heap_peek(HeapMax *heap) {
    if (heap->size == 0) {
        printf("Heap vazio!\n");
        return;
    }

    Chamado c = heap->data[0];
    printf("Proximo: ID %d | Prioridade %d | %s\n",
           c.id, c.prioridade, c.descricao);
}

// Listar
void print_heap(HeapMax *heap) {
    if (heap->size == 0) {
        printf("Heap vazio!\n");
        return;
    }

    for (int i = 0; i < heap->size; i++) {
        printf("ID %d | Prioridade %d | %s\n",
               heap->data[i].id,
               heap->data[i].prioridade,
               heap->data[i].descricao);
    }
}

// MAIN (menu)
int main() {
    HeapMax heap;
    init_heap(&heap);

    int op;
    Chamado c;

    do {
        printf("\n1-Inserir\n2-Atender\n3-Ver topo\n4-Listar\n5-Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                printf("ID: ");
                scanf("%d", &c.id);

                printf("Descricao: ");
                scanf(" %[^\n]", c.descricao);

                printf("Prioridade: ");
                scanf("%d", &c.prioridade);

                if (c.prioridade <= 0) {
                    printf("Prioridade deve ser positiva!\n");
                    break;
                }

                heap_insert(&heap, c);
                break;

            case 2: {
                Chamado atendido = heap_extract_max(&heap);
                if (atendido.id != -1) {
                    printf("Chamado atendido: ID %d | Prioridade %d | %s\n",
                           atendido.id,
                           atendido.prioridade,
                           atendido.descricao);
                }
                break;
            }

            case 3:
                heap_peek(&heap);
                break;

            case 4:
                print_heap(&heap);
                break;

            case 5:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 5);

    return 0;
}