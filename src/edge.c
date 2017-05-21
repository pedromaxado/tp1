/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * edge.h - Define funções relacionadas a manipulação de    *
 * um TAD edge.                                             *
 * ======================================================== */

#include <stdlib.h>
#include "edge.h"

struct edge_t {
    int v,
        rev,
        cap;
};

edge new_edge( int v, int cap, int rev ) {

    edge e = ( edge ) malloc( sizeof( struct edge_t ) );

    e->v   = v;
    e->rev = rev;
    e->cap = cap;

    return e;
}

void delete_edge( edge e ) {
    free(e);
}

void setCap( edge e, int cap ) {
    e->cap = cap;
}

int getVertex( edge e ) {
    return e->v;
}

int getRev( edge e ) {
    return e->rev;
}

int getCap( edge e ) {
    return e->cap;
}
