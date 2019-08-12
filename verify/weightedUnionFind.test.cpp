#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/weightedUnionFind.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    WeightedUnionFind<int> wuf(N);

    while(Q--) {
        int com, x, y, z;
        cin >> com;

        if (com == 0) {
            cin >> x >> y >> z;
            wuf.unite(x, y, z);
        } else {
            cin >> x >> y;

            if (wuf.same(x, y))
                cout << wuf.diff(x, y) << "\n";
            else
                cout << '?' << "\n";
        }
    }

    return 0;
}
