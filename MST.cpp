#include "bits/stdc++.h"
// Custom Header {{{
#define ALL(x) x.begin(), x.end()
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

struct Edge { // {{{
    int src, to;
    i64 cost;
    Edge(int src,  int to, i64 cost) : src(src), to(to), cost(cost) {}
    Edge(int to, i64 cost = 0) : Edge(-1, to, cost) {}
    Edge() {}
    bool operator< (const Edge &o) const { return cost < o.cost; }
    bool operator> (const Edge &o) const { return cost > o.cost; }
};
using Edges = vector<Edge>;
using WGraph = vector<vector<Edge>>;
using UGraph = vector<vector<int>>;
// }}}

struct UnionFind { // {{{
    vector<int> u;
    explicit UnionFind(int n): u(n+5, -1) {}
    int  size(int i)        { return (-u[root(i)]); }
    int  root(int x)        { return (u[x] < 0)? x : u[x] = root(u[x]); }
    bool same(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y){ return (x=root(x)) == (y=root(y))? false : (u[x]+=u[y], u[y]=x, true); }
}; // }}}

//@@@@@@@@@@
//@ snippet kruskal
//@ options head
i64 kruskal(Edges &es, int V) // {{{
{
    UnionFind uf(V);
    i64 costSum = 0;

    sort(es.begin(), es.end());
    for (const auto &e : es) {
        if (uf.unite(e.src, e.to)) costSum += e.cost;
    }

    return costSum;
} // }}}
//@@@@@@@@@@

/*
 *  Verified on : 2019-07-21
 *  https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
 */
void AOJ_GRL_2_A() // {{{
{
    int V, E;
    cin >> V >> E;

    Edges es(E);
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        es[i] = Edge(s, t, w);
    }

    cout << kruskal(es, V) << endl;
} // }}}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    AOJ_GRL_2_A();

    return 0;
}
