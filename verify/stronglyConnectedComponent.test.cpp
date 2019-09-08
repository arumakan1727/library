#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
// Verified On : 2019-09-08

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/stronglyConnectedComponents.cpp"

using namespace std;

int GRL_3_C()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    var(int, V, E);

    StronglyConnectedComponents scc(V);

    rep(i, E) {
        var(int, s, t);
        scc.addEdge(s, t);
    }

    scc.build();

    var(int, Q);
    while(Q--) {
        var(int, u, v);
        print(scc[u] == scc[v]);
    }

    return 0;
}

int main()
{
    return GRL_3_C();
}
