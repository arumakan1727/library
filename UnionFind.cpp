#include "bits/stdc++.h"
using namespace std;

//@@@@@@@@@@
//@ snippet UnionFind
//@ options head
struct UnionFind {
    vector<int> u;
    explicit UnionFind(int n): u(n+5, -1) {}
    int  size(int i)        { return (-u[root(i)]); }
    int  root(int x)        { return (u[x] < 0)? x : u[x] = root(u[x]); }
    bool same(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y){ return (x=root(x)) == (y=root(y))? false : (u[x]+=u[y], u[y]=x, true); }
};
//@@@@@@@@@


/*
 * Verified on 2019-06-01
 * https://atc001.contest.atcoder.jp/tasks/unionfind_a
 */
void ATC001_B()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while(Q--) {
        int p, a, b;
        cin >> p >> a >> b;
        if (p == 0) {
            uf.unite(a, b);
        } else {
            cout << (uf.same(a,b) ? "Yes" : "No") << '\n';
        }
    }
    return;
}

signed main()
{
    ATC001_B();
    return 0;
}
