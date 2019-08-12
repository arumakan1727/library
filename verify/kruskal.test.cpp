#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
// Verified On: 2019-08-13

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/kruskal.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    Edges es(E);
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        es[i] = Edge(s, t, w);
    }

    cout << kruskal(es, V) << endl;

    return 0;
}
