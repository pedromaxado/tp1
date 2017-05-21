#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

int main() {

    int vertex, cycleTracks, franchises, vertexWithClients,
        u, v, m,
        f, c,
        i;

    graph g;

    if ( !scanf("%d %d %d %d", &vertex, &cycleTracks, &franchises, &vertexWithClients) )
        exit( EXIT_FAILURE );

    g = new_graph( vertex+2 );

    const int SRC = vertex, SINK = vertex+1;

    for ( i = 0; i < cycleTracks; i++ ) {
         if ( scanf("%d %d %d", &u, &v, &m) )
            addEdge( g, u, v, m );
    }

    for ( i = 0; i < franchises; i++ ) {
        if ( scanf("%d", &f) )
            addEdge( g, SRC, f, INF );
    }

    for ( i = 0; i < vertexWithClients; i++ ) {
        if ( scanf("%d", &c) )
            addEdge( g, c, SINK, INF );
    }

    int result = maxFlow( g, SRC, SINK );

    printf("%d\n", result);

    delete_graph( g );

    return 0;
}
