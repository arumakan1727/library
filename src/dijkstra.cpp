#include "bits/stdc++.h"
#include "./commonHeader.hpp"

#include "./graphTemplate.cpp"

//@@@@@@@
//@ snippet dijkstra
//@ options head
vector<i64> dijkstra(const WGraph &G, int src) // {{{
{
    vector<i64> dist(G.size(), LINF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()) {
        const i64 nowCost = pq.top().first;
        const int nowNode = pq.top().second;
        pq.pop();
        if (dist[nowNode] < nowCost) continue;

        for (const auto &e : G[nowNode]) {
            const i64 newCost = nowCost + e.cost;
            if (chmin(dist[e.to], newCost)) {
                pq.emplace(newCost, e.to);
            }
        }
    }

    return dist;
}
// }}}
//@@@@@@@@

