#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
// Verified On: 2019-08-12

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/fenwickTree.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    FenwickTree<int> ft(N);
    while(Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            ft.add(x, y);
        } else {
            cout << (ft.sum(x, y)) << '\n';
        }
    }

    return 0;
}
