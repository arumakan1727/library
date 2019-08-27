#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
// Verified On: 2019-08-27

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/graphTemplate.cpp"
#include "../src/bellmanFord.cpp"

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int V, E, src; cin >> V >> E >> src;

    WeightedGraph G(V);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].emplace_back(s, t, w);
    }

    const auto dist = bellmanFord<less<>, LINF>(G, src);

    if (dist.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, V) {
            cout << (dist[i] < LINF ? to_string(dist[i]) : "INF") << "\n";
        }
    }

    return 0;
}

