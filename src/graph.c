/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * graph.c - Define funções relacionadas a manipulação de   *
 * um TAD grafo implementada com lista de adjacência e      *
 * matriz para armazenar o valor das arestas.               *
 * ======================================================== */

#include <stdlib.h>
#include <string.h>

#include "graph.h"

/*
 * Struct da TAD graph encapsulada.
 *
 * Membros:
 *   edges - lista de adjacências para armazenar as arestas
 *   q     - fila de vértices para definir os níveis
 *   size  - quantidade de vértices no grafo
 */
struct graph_t {
    vector* edges;
    queue q;
    int* level;
    int size;
};

graph new_graph( int v ) {

    int size = v + 2;

    graph g = ( graph ) malloc( sizeof( struct graph_t ) );

    g->size  = size;

    g->edges = ( vector* ) malloc( size * sizeof( vector ) );
    g->level = ( int*    ) malloc( size * sizeof( int    ) );

    g->q     = new_queue();

    for ( int i = 0; i < size; i++ ) {
        g->edges[i] = new_vector();
    }

    return g;
}

void delete_graph( graph g ) {

    for ( int i = 0; i < g->size; i++ ) {
        for ( int j = 0; j < vectorSize( g->edges[i] ); j++ ) {
            delete_edge( get( g->edges[i], j ) );
        }

        delete_vector( g->edges[i] );
    }

    delete_queue( g->q );

    free( g->level );
    free( g->edges );

    free( g );
}

void addEdge( graph g, int u, int v, int cap ) {

    if ( u == v )
        return;

    edge e = new_edge( v, cap, vectorSize( g->edges[v] ) );
    edge r = new_edge( u,   0, vectorSize( g->edges[u] ) );

    add(g->edges[u], e);
    add(g->edges[v], r);
}

/*
 * Define o nível de cada vértice no grafo, e retorna verdadeiro
 * caso ainda haja um caminho aumentante.
 *
 * Parâmetros:
 *   * g    - grafo
 *   * src  - fonte
 *   * sink - sumidouro
 *
 * Retorna:
 *   * bool - true se existe caminho, false caso contrário
 */
bool hasLevelGraph( graph g, int src, int sink ) {

    memset( g->level, -1, sizeof( int ) * g->size );

    while ( !isQueueEmpty( g->q ) )
        pop( g->q );

    g->level[src] = 0;

    push( g->q, src );

    while ( !isQueueEmpty( g->q ) ) {

        int u = front( g->q );
        pop( g->q );

        /* visita todos os vértices adjacentes primeiramente */
        for ( int i = 0; i < vectorSize( g->edges[u] ); i++ ) {

            int vtx = getVertex( get( g->edges[u], i ) );
            int cap = getCap   ( get( g->edges[u], i ) );

            /* se a aresta tiver custo zero ou o vértice tem seu nível definido,
             * parta para a próxima aresta na fila */
            if ( cap == 0 || g->level[vtx] != -1 )
                continue;

            /* define o nível do vértice */
            g->level[vtx] = g->level[u] + 1;

            /* se foi possível chegar no sink, temos um grafo de nível válido,
             * e consequentemente um caminho aumentante */
            if ( vtx == sink )
                return true;

            push( g->q, vtx );
        }
    }

    return false;
}

/*
 * Bloqueia o fluxo nas aresta em um grafo dado por meio de um
 * DFS. O algoritmo encontra a aresta de menor custo ao longo do
 * caminho e volta na recursão subtraindo o fluxo de cada aresta.
 * Para cada fluxo encontrado, somamos em uma variável que repre-
 * senta o fluxo máximo no grafo residual.
 *
 * Parâmetros:
 *   * g - grafo
 *   * u - vértice origem
 *   * sink - sumidouro
 *   * flow - fluxo
 *
 * Retorna:
 *   * int - fluxo máximo obtido no grafo residual
 */
int blockFlow( graph g, int u, int sink, int flow ) {

    if ( u == sink || flow == 0 )
        return flow;

    int flow_u = flow;

    for ( int i = 0; i < vectorSize( g->edges[u] ); i++ ) {

        edge e = get( g->edges[u], i );

        int vtx = getVertex( e );
        int rev = getRev   ( e );
        int cap = getCap   ( e );

        edge rev_e = get( g->edges[vtx], rev );

        int rev_cap = getCap ( rev_e );

        if ( cap == 0 || g->level[vtx] != g->level[u] + 1 )
            continue;

        int minCap = blockFlow( g, vtx, sink, flow_u < cap ? flow_u : cap );

        if ( minCap > 0 ) {
            setCap( rev_e, rev_cap + minCap );
            setCap(     e,     cap - minCap );
            flow_u -= minCap;
        }
    }

    if ( flow == flow_u )
        g->level[u] = -1;

    return flow - flow_u;
}

int maxFlow( graph g, int src, int sink ) {

    int flow = 0;

    while ( hasLevelGraph( g, src, sink ) )
        flow += blockFlow( g, src, sink, INF );

    return flow;
}
