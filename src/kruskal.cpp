#include "bits/stdc++.h"
using namespace std;

#include "unionFind.cpp"
#include "graphTemplate.cpp"

#ifndef INCLUDED_YDK_KRUSKAL_CPP
#define INCLUDED_YDK_KRUSKAL_CPP

//@@@@@@@@@@
//@ snippet kruskal
//@ options head
int64_t kruskal(vector<Edge> &es, int V) // {{{
{
    UnionFind uf(V);
    int64_t costSum = 0;

    sort(es.begin(), es.end());
    for (const auto &e : es) {
        if (uf.unite(e.src, e.to)) costSum += e.cost;
    }

    return costSum;
} // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
