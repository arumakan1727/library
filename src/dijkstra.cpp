#include "bits/stdc++.h"
using namespace std;

#include "./graphTemplate.cpp"

//@@@@@@@
//@ snippet dijkstra
//@ options head
template<class Compare = less<>, int64_t INF = 0x3f3f3f3f3f3f3f3fLL>
vector<int64_t> dijkstra(const Graph &G, const vector<int> &startNodes) // {{{
{
    using pii = pair<int64_t, int>;
    const auto isBetter = Compare();

    vector<int64_t> dist(G.size(), INF);
    priority_queue<pii, vector<pii>, Compare> pq;

    for (const int startNode : startNodes) {
        dist[startNode] = 0LL;
        pq.emplace(-0LL, startNode);
    }

    while(!pq.empty()) {
        const int64_t nowCost = -(pq.top().first);
        const int     nowNode = pq.top().second;
        pq.pop();

        if (isBetter(dist[nowNode], nowCost)) continue;

        for (const auto &e : G[nowNode]) {
            const int64_t newCost = nowCost + e.cost;
            if (isBetter(newCost, dist[e.to])) {
                dist[e.to] = newCost;
                pq.emplace(-newCost, e.to);
            }
        }
    }

    return dist;
}
// }}}
//@@@@@@@@

