#include "bits/stdc++.h"
#include "commonHeader.hpp"

#include "unionFind.cpp"
#include "graphTemplate.cpp"

#ifndef INCLUDED_YDK_KRUSKAL_CPP
#define INCLUDED_YDK_KRUSKAL_CPP

//@@@@@@@@@@
//@ snippet kruskal
//@ options head
i64 kruskal(Edges &es, int V) // {{{
{
    UnionFind uf(V);
    i64 costSum = 0;

    sort(es.begin(), es.end());
    for (const auto &e : es) {
        if (uf.unite(e.src, e.to)) costSum += e.cost;
    }

    return costSum;
} // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
