#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
// Verified On: 2019-09-08

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/graphTemplate.cpp"
#include "../src/bellmanFord.cpp"

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int V, E, src; cin >> V >> E >> src;

    Graph G(V);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        G.addEdge(s, t, w);
    }

    const vector<i64> dist = bellmanFord<less<>, LINF>(G, src);

    if (dist.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, V) {
            cout << (dist[i] < LINF ? to_string(dist[i]) : "INF") << "\n";
        }
    }

    return 0;
}

