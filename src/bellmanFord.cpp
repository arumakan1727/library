#include "bits/stdc++.h"
#include "./commonHeader.hpp"

#include "./graphTemplate.cpp"

//@@@@@@@@
//@ snippet bellmanFord
//@ options head
// If it find NEGATIVE-CYCLE, it returns EMPTY.
vector<i64> bellmanFord(const WGraph &G, int src) // {{{
{
    const int V = G.size();
    vector<i64> dist(V, LINF);

    dist[src] = 0;

    int loop;
    bool updated = true;
    for (loop = 0; updated && loop <= V; ++loop) {
        updated = false;
        rep(s, V) if (dist[s] < LINF) {
            for (const auto &e : G[s]) updated |= chmin(dist[e.to], dist[s] + e.cost);
        }
    }

    if (loop > V) return {};
    else return dist;
}
// }}}
//@@@@@@@
