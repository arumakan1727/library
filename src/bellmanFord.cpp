#include "bits/stdc++.h"
using namespace std;

#include "./graphTemplate.cpp"

//@@@@@@@@
//@ snippet bellmanFord
//@ options head
// [使い方]
//      最短経路 : bellmanFord(graph, startNode)
//      最長経路 : bellmanFord<greater<>, LLONG_MIN>(graph, startNode)
// [戻り値]
//      startNodeからの距離を格納した vector。
//      ただし、不閉路がある場合は空の vector {} を返す。
template<class Compare = less<>, int64_t INF = 0x3f3f3f3f3f3f3f3fLL>
vector<int64_t> bellmanFord(const WeightedGraph &G, int src) // {{{
{
    const auto isBetter = Compare();
    const auto grow = [&isBetter](int64_t &a, const int64_t b) -> bool {
        return isBetter(b, a) && (a = b, true);
    };

    const int V = G.size();

    vector<int64_t> dist(V, INF);
    dist[src] = 0;

    int loop;
    bool updated = true;
    for (loop = 0; updated && loop <= V; ++loop) {
        updated = false;
        for (int s = 0; s < V; ++s) {
            if (dist[s] != INF) {
                for (const auto &e : G[s]) updated |= grow(dist[e.to], dist[s] + e.cost);
            }
        }
    }

    if (loop > V) {
        return {};
    } else {
        return dist;
    }
}
// }}}
//@@@@@@@

