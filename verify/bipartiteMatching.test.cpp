#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A
// Verified On : 2019-09-12

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"
#include "../src/bipartiteMatching.cpp"

using namespace std;

int GRL_7_A()
{
    var(int, X, Y, E);

    BipartiteMatching G(X + Y);

    rep(i, E) {
        var(int, x, y);
        G.addEdge(x, y + X);
    }

    print(G.build());

    return 0;
}

int main()
{
    return GRL_7_A();
}
