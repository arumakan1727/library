#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
// Verified On: 2019-09-07

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/graphTemplate.cpp"
#include "../src/doublingLCA.cpp"

using namespace std;

int GRL_5_C()
{
    var(int, N);

    DoublingLCA G(N);
    rep(i, N) {
        var(int, numChildlen);
        rep(j, numChildlen) {
            var(int, ch);
            G.addEdge(i, ch);
        }
    }

    G.build(0);

    var(int, Q);
    while(Q--) {
        var(int, u, v);
        print(G.lca(u, v));
    }

    return 0;
}

int main()
{
    GRL_5_C();
}
