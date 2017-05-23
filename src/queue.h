/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * queue.h - Define a estrutura de dados e cabeçalho de     *
 * funções relacionadas a manipulação de um TAD fila        *
 * implementada com lista encadeada.                        *
 * ======================================================== */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdbool.h>

typedef int Type;

/* definição do tipo priority queue */
typedef struct queue_t* queue;

/*
* Cria uma fila vazia.
*
* Retorna:
*   * queue - Nova fila criada
*/
queue new_queue();

/*
* Libera a memória utilizada pela fila.
*
* Parâmetro:
*   * q - fila a ser apagado
*/
void delete_queue(queue q);

/*
* Insere um elemento na fila.
*
* Parâmtros:
*   * q - fila
*   * k - elemento a ser inserido
*/
void push( queue q, Type k );

/*
* Retorna o primeiro elemento da fila.
*
* Parâmetros:
*   * q - fila
*/
Type front( queue q );

/*
* Remove o primeiro elemento da fila.
*
* Parâmetros:
*   * q - fila
*/
void pop(queue q);

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
int queueSize(queue q);

/*
* Retorna se uma fila está vazia ou não.
*
* Parâmetro:
*   * q - fila
*
* Retorna:
*   * bool - true se vazio, false se não
*/
bool isQueueEmpty(queue q);

#endif  // _PRIORITY_QUEUE_H_
