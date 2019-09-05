#include "bits/stdc++.h"
using namespace std;

#ifndef INCLUDED_YDK_GRAPH_CPP
#define INCLUDED_YDK_GRAPH_CPP

//@@@@@@@
//@ snippet edge
//@ alias   graph
//@ options  head
struct Edge { // {{{
    int src, to;
    int64_t cost = 0;

    inline Edge() noexcept {}
    inline Edge(int s,  int t, int64_t c) noexcept : src(s), to(t), cost(c) {}

    bool operator< (const Edge &o) const noexcept { return cost < o.cost; }
    bool operator> (const Edge &o) const noexcept { return o < *this; }

    operator int() const noexcept { return to; }

    Edge& operator=(int rhs_to) noexcept {
        this->to = rhs_to;
        return *this;
    }
};
// }}}
using WeightedGraph     = vector<vector<Edge>>;
using UnWeightedGraph   = vector<vector<int>>;
//@@@@@@

class Graph : public vector<vector<Edge>> {
    using super = vector<vector<Edge>>;
public:
    Graph() noexcept {}
    Graph(int V) noexcept : super(V + 1) {}

    Graph& addEdge(int from, int to, int64_t cost = 0) noexcept {
        super::operator[](from).emplace_back(from, to, cost);
        return *this;
    }

    Graph reverseGraph() const noexcept {
        const int V = super::size();
        Graph revG(V);
        for (int i = 0; i < V; ++i) {
            const auto &nodes = super::operator[](i);
            revG.reserve(nodes.size());
            for (const auto &e : nodes) revG.emplace_back(e.to, e.src, e.cost);
        }
        return revG;
    }
};

//@@@@@@@
//@ snippet MatrixGraph
//@ alias   matrixGraph
//@ options  head
template<size_t N>
class MatrixGraph { // {{{
    int64_t G[N][N];

public:
    constexpr MatrixGraph() noexcept { init(); }

    inline void init() noexcept {
        memset(G, 0x3f, sizeof(G));
        for (int i = 0; i < N; ++i) G[i][i] = 0;
    }

    int64_t* operator[](int i) noexcept {
        return G[i];
    }

    const int64_t* operator[] (int i) const noexcept {
        return G[i];
    }
};
// }}}
//@@@@@@@@


//@@@@@@@@@@
//@ snippet dfs_arrivable
//@ alias   arrivable
//@ options head
template<class GraphType>
void dfs_arrivable(int u, const GraphType &G, bool visited[]) { // {{{
    if (!visited[u]) {
        visited[u] = true;
        for (const int to : G[u]) dfs_arrivable(to, G, visited);
    }
} // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
