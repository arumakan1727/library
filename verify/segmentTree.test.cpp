#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
// Verified On: 2019-09-08

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/segmentTree.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, Q;
    int com, x, y;

    scanf("%d%d", &N, &Q);
    SegmentTree<int> seg(N, (1LL << 31) - 1, [](int a, int b){ return min(a,b); });

    while(Q--) {
        scanf("%d%d%d", &com, &x, &y);
        if (com == 0) {
            seg.update(x, y);
        } else {
            printf("%d\n", seg.query(x, y+1));
        }
    }

    return 0;
}
