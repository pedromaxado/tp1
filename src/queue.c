/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * queue.c - Define funções para manipulação de uma TAD     *
 * fila implementada com lista encadeada                    *
 * ======================================================== */

#include <stdlib.h>
#include "queue.h"

/*
 * Struct Node que armazena a chave do nó e define como os dados
 * serão organizados na memória.
 *
 * Membros:
 *   * key  - chave do nó
 *   * prev - nó anterior
 *   * next - nó posterior
 */
typedef struct node_t {

    Type key;

    struct node_t* prev;
    struct node_t* next;
} Node;

/*
* Struct da TAD encapsulada.
*
* Membros:
*   * end  - sentinela: nó que aponta para o início e final da fila
*   * size - inteiro que armazena o tamanho atual da fila
*/
struct queue_t{

    Node* end;
    int size;
};

/*
* Cria uma fila vazia.
*
* Retorna:
*   * queue - Nova fila criada
*/
queue new_queue() {

    queue q = malloc(sizeof(struct queue_t));

    q->size = 0;

    q->end = malloc(sizeof(struct node_t));
    q->end->next = q->end;
    q->end->prev = q->end;

    return q;
}

/*
* Libera a memória utilizada pela fila.
*
* Parâmetro:
*   * q - fila a ser apagado
*/
void delete_queue(queue q) {

    while (!isQueueEmpty(q)) {
        pop(q);
    }

    free(q->end);
    free(q);
}

/*
* Insere um elemento na fila.
*
* Parâmtros:
*   * q - fila
*   * k - elemento a ser inserido
*/
void push( queue q, Type k ) {

    Node *lastItem = q->end->prev;

    Node* node  = malloc(sizeof( struct node_t ) );
    node->key   = k;
    node->prev  = lastItem;
    node->next  = q->end;

    lastItem->next  = node;
    q->end->prev    = node;

    q->size++;
}

/*
* Retorna o primeiro elemento da fila.
*
* Parâmetros:
*   * q - fila
*
* Retorna:
*   * Type - elemento do tipo Type
*/
Type front( queue q ) {
    return q->end->next->key;
}

/*
* Remove o primeiro elemento da fila.
*
* Parâmetros:
*   * q - fila
*/
void pop( queue q ) {

    Node* first = q->end->next;

    first->prev->next = first->next;
    first->next->prev = first->prev;

    free(first);
    q->size--;
}

/*
* Retorna o tamanho da fila, aka,
* quantidade de elementos nela contida.
*
* Parâmetro:
*   * q - fila
*
* Retorna:
*   * int - Tamanho do vetor
*/
int queueSize( queue q ) {
    return q->size;
}

/*
* Retorna se uma fila está vazia ou não.
*
* Parâmetro:
*   * q - fila
*
* Retorna:
*   * bool - true se vazio, false se não
*/
bool isQueueEmpty( queue q ) {
    return q->size == 0;
}
