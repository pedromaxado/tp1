#include <stdlib.h>
#include "vertex.h"

struct vertex_t {

    int index,
        parent,
        cost;
};

vertex new_vertex( int index, int parent, int cost ) {

    vertex n = ( vertex ) malloc( sizeof( struct vertex_t ) );

    n->index    = index;
    n->parent   = parent;
    n->cost     = cost;

    return n;
}

void delete_vertex( vertex n ) {
    free(n);
}

void setIndex( vertex v, int index ) {
    v->index = index;
}

void setParent( vertex v, int parent ) {
    v->parent = parent;
}

void setCost( vertex v, int cost ) {
    v->cost = cost;
}

int getIndex( vertex n ) {
    return n->index;
}

int getParent( vertex n ) {
    return n->parent;
}

int getCost( vertex n ) {
    return n->cost;
}
