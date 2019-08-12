#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
// Verified On: 2019-08-12
#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/unionFind.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while(Q--) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << (uf.same(x, y) ? 1 : 0) << '\n';
        }
    }

    return 0;
}
