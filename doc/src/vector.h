/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * stack.c - Define a estrutura de dados e cabeçalho de     *
 * funções relacionadas a manipulação de um TAD vetor       *
 * implementado com array de inteiros.                      *
 * ======================================================== */

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdbool.h>
#include "edge.h"

typedef edge type;

/* definição do tipo vector */
typedef struct vector_t* vector;

/*
* Cria um vetor vazio.
*
* Retorna:
*   * vector - Novo vetor criado
*/
vector new_vector	(  );

/*
* Libera a memória utilizada pelo vetor.
*
* Parâmetro:
*   * v - vetor a ser apagado
*/
void delete_vector	( vector v );

/*
* Insere um elemento no vetor.
*
* Parâmtros:
*   * v - vetor
*   * k - elemento a ser inserido
*/
void add			( vector v, type o );

/*
* Retorna o elemento do vetor em uma dada posição.
*
* Parâmtros:
*   * v - vetor
*   * pos - posição do elemento
*/
type get			( vector v, int pos );

/*
* Retorna o tamanho do vetor, aka, quantidade de
* elementos nele contido.
*
* Parâmetro:
*   * v - vetor
*
* Retorna:
*   * int - Tamanho do vetor
*/
int vectorSize		( vector v );

/*
* Retorna a capacidade atual do vetor.
*
* Parâmetro:
*   * v - vetor
*
* Retorna:
*   * int - Capacidade do vetor
*/
int capacity        ( vector v );

/*
* Retorna se um vetor está vazio ou não.
*
* Parâmetro:
*   * v - vetor
*
* Retorna:
*   * bool - true se vazio, false se não
*/
bool isVectorEmpty	( vector v );

#endif
