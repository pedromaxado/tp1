/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * vertex.h - Define a estrutura de dados e cabeçalhos de   *
 * funções relacionadas a manipulação de um TAD vertex.     *
 * ======================================================== */

#ifndef _VERTEX_H_
#define _VERTEX_H_

typedef struct vertex_t* vertex;

/*
* Cria um vértice.
*
* Parâmetro:
*   * index  - chave do vértice
*   * parent - pai do vértice
*   * cost   - custo passando pelo vértice
*
* Retorna:
*   * vertex - novo vértice criado
*/
vertex new_vertex( int index, int parent, int cost );

/*
 * Define o índice de um vértice.
 *
 * Parâmetros:
 *   * v     - vértice
 *   * index - índice do vértice
 */
void setIndex( vertex v, int index );

/*
 * Define o pai de um vértice.
 *
 * Parâmetros:
 *   * v      - vértice
 *   * parent - pai do vértice
 */
void setParent( vertex v, int parent );

/*
 * Define o custo de um vértice ligado a seu pai.
 *
 * Parâmetros:
 *   * v    - vértice
 *   * cost - custo do vértice ligado a seu pai
 */
void setCost( vertex v, int cost );

/*
 * Libera a memória utilizada por um vértice.
 *
 * Parâmetro:
 *   * v - vértice a ser apagado
 */
void delete_vertex( vertex v );

/*
* Obtém a chave do vértice.
*
* Parâmetro:
*   * v - vértice
*
* Retorna:
*   * int - index do vértice
*/
int getIndex( vertex v );

/*
* Obtém a chave do vértice pai.
*
* Parâmetro:
*   * v - vértice
*
* Retorna:
*   * int - index do vértice pai
*/
int getParent( vertex v );

/*
* Obtém o custo passando pelo vértice.
*
* Parâmetro:
*   * v - vértice
*
* Retorna:
*   * int - custo do vértice
*/
int getCost( vertex v );

#endif
