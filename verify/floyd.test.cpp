#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/graphTemplate.cpp"
#include "../src/floyd.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    static MatrixGraph<105> G;
    int V, E;

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        G[s][t] = c;
    }

    if (floyd(G, V) < 0) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << (G[i][j] >= LINF ? "INF" : to_string(G[i][j])) << ((j < V-1) ? ' ' : '\n');
            }
        }
    }

    return 0;
}
