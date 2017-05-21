/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * edge.h - Define a estrutura de dados e cabeçalhos de     *
 * funções relacionadas a manipulação de um TAD edge.       *
 * ======================================================== */

#ifndef _EDGE_H_
#define _EDGE_H_

typedef struct edge_t* edge;

/*
* Cria uma aresta.
*
* Parâmetro:
*   * v   - vértice adacente
*   * cap - capacidade da aresta
*
* Retorna:
*   * edge - nova aresta criada
*/
edge new_edge( int v, int cap, int rev );

/*
 * Libera a memória utilizada por uma aresta.
 *
 * Parâmetro:
 *   * e - aresta a ser apagada
 */
void delete_edge( edge e );

/*
 * Define a capacidade de uma aresta.
 *
 * Parâmetros:
 *   * e   - aresta
 *   * cap - capacidade
 */
void setCap( edge e, int cap );

/*
* Obtém o vértice da extremidade da aresta.
*
* Parâmetro:
*   * e - aresta
*
* Retorna:
*   * int - index do vértice
*/
int getVertex( edge e );

/*
* Obtém a posição do vértice na lissta de adjacência
* do vértice pai.
*
* Parâmetro:
*   * e - aresta
*
* Retorna:
*   * int - index do vértice
*/
int getRev( edge e );

/*
* Obtém capacidade da aresta.
*
* Parâmetro:
*   * e - aresta
*
* Retorna:
*   * int - capacidade da aresta
*/
int getCap( edge e );

#endif
