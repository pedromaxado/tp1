#include <bits/stdc++.h>

using namespace std;

#ifdef NDEBUG
    #define DEBUG if (false)
#else
    #define DEBUG if (true)
#endif

#pragma GCC diagnostic warning "-Wall"
#define ALL(x) (x).begin(), (x).end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Edge{
    int v, rev;
    int cap;
    Edge(int v_, int cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
};

struct MaxFlow{
    vector<vector<Edge> > g;
    vector<int> level;
    queue<int> q;

    int flow, n;

    MaxFlow(int n_) : g(n_), level(n_), n(n_) {}

    void addEdge(int u, int v, int cap){

        if(u == v) return;

        Edge e(v, cap, int(g[v].size()));
        Edge r(u, 0, int(g[u].size()));

        g[u].push_back(e);
        g[v].push_back(r);
    }

    bool buildLevelGraph(int src, int sink){

        fill(ALL(level), -1);

        while(not q.empty()) q.pop();

        level[src] = 0;

        q.push(src);

        while(not q.empty()){

            int u = q.front();
            q.pop();

            FOREACH(e, g[u]){

                if( not e->cap or level[e->v] != -1 )
                    continue;

                level[e->v] = level[u] + 1;
                    if(e->v == sink) return true;

                q.push(e->v);
            }
        }

        return false;
    }

    int blockingFlow(int u, int sink, int f) {

        if(u == sink or not f)
            return f;

        int fu = f;

        FOREACH(e, g[u]){

            if(not e->cap or level[e->v] != level[u] + 1)
                continue;

            int mincap = blockingFlow(e->v, sink, min(fu, e->cap));

            if(mincap){

                g[e->v][e->rev].cap += mincap;
                e->cap -= mincap;
                fu -= mincap;
            }
        }

        if( f == fu )
            level[u] = -1;

        return f - fu;
    }

    int maxFlow(int src, int sink){
        flow = 0;

        while(buildLevelGraph(src, sink))
            flow += blockingFlow(src, sink, numeric_limits<int>::max());

        return flow;
    }
};

int main() {

    int vertex, cycleTracks, franchises, vertexWithClients,
    u, v, m,
    f, c,
    i;

    scanf("%d %d %d %d", &vertex, &cycleTracks, &franchises, &vertexWithClients);

    MaxFlow mf(vertex+2);

    for ( i = 0; i < cycleTracks; i++ ) {
        scanf("%d %d %d", &u, &v, &m);

        mf.addEdge( u, v, m );
    }

    for ( i = 0; i < franchises; i++ ) {
        scanf("%d", &f);

        mf.addEdge( vertex, f, INT_MAX );
    }

    for ( i = 0; i < vertexWithClients; i++ ) {
        scanf("%d", &c);

        mf.addEdge( c, vertex+1, INT_MAX );
    }

    int res = mf.maxFlow( vertex, vertex+1 );

    printf("%d\n", res);

    return 0;
}
