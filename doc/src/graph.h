/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * graph.h - Define a estrutura de dados e cabeçalho de     *
 * funções relacionadas a manipulação de um TAD grafo       *
 * implementada com lista de adjacência e matriz para       *
 * armazenar o valor das arestas.                           *
 * ======================================================== */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdbool.h>
#include <limits.h>

#include "edge.h"
#include "vector.h"
#include "queue.h"

#define INF INT_MAX

typedef struct graph_t* graph;

/*
* Cria um grafo vazio.
*
* Parâmetro:
*   * size - número de vértices do grafo
*
* Retorna:
*   * grafo - novo grafo criado
*/
graph new_graph( int size );

/*
* Libera a memória utilizada pelo grafo.
*
* Parâmetro:
*   * g - grafo a ser apagado
*/
void delete_graph( graph g );

/*
 * Adiciona a aresta u ---cost---> v
 *
 * Parâmetros:
 *   * g    - grafo em questão
 *   * u    - vértice origem
 *   * v    - vértice destino
 *   * cost - custo da aresta
 */
void addEdge( graph g, int u, int v, int cost );

/*
 * Obtém o fluxo máximo de um determinado grafo dado sua
 * fonte e seu sumidouro.
 *
 * Parâmetros:
 *   * g    - grafo em questão
 *   * src  - fonte do grafo
 *   * sink - sumidouro do grafo
 */
int maxFlow( graph g, int source, int sink );

#endif
