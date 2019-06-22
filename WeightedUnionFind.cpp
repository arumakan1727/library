#include "bits/stdc++.h"
using namespace std;

//@@@@@@
//@ snippet WeightedUnionFind
//@ alias   PotentialedUnionFind
//@ options head
template<class Abel>
struct WeightedUnionFind {
    vector<int> p;      // 親もしくは連結成分の数
    vector<Abel> dw;    // 親ノードとの差分

    explicit WeightedUnionFind(int n, Abel SUM_UNITY = 0)
        : p(n+5, -1), dw(n+5, SUM_UNITY) {}

    inline int root(int x) {
        if (p[x] < 0) {
            return x;
        } else {
            const int r = root(p[x]);
            return (dw[x] += dw[p[x]]), (p[x] = r);
        }
    }

    // diff(x, y) == w となるようにする
    inline bool unite(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        if ((x=root(x)) == (y=root(y))) return false;
        p[x] += p[y]; p[y] = x;
        dw[y] = w;
        return true;
    }

    inline bool same(int x, int y) { return root(x) == root(y); }
    inline int  size(int x)        { return -p[root(x)]; }
    inline Abel diff(int x, int y) { return weight(y) - weight(x); }
    inline Abel weight(int x)      { root(x); return dw[x]; }
};
//@@@@@@@




struct FastIO {
    FastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); }
} fastIO_ydk ;


/*
 * Verified on 2019-06-22
 * https://atcoder.jp/contests/abc087/submissions/3917126
 */
void ABC087_D()
{
    using i64 = int_fast64_t;

    int N, M;
    cin >> N >> M;

    WeightedUnionFind<i64> uf(N);

    while(M--) {
        int l, r, d;
        cin >> l >> r >> d;

        uf.unite(l, r, d);
        if (uf.diff(l, r) != d) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    return;
}

int main()
{
    ABC087_D();
    return 0;
}
