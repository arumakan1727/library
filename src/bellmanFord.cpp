#include "bits/stdc++.h"
// Custom Header {{{
#define all(x) x.begin(), x.end()
#define rep(i,n)    for (i64 i = 0; i < (n); ++i)
#define reps(i,s,t) for (i64 i = (s); i <= (t); ++i)
#define repr(i,s,t) for (i64 i = (n); i >= (t); --i)
using namespace std;
using i64 = int_fast64_t;
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


//@@@@@@@@
//@ snippet bellmanFord
//@ options head
// If it find NEGATIVE-CYCLE, it returns EMPTY.
vector<i64> bellmanFord(const WGraph &G, int src) // {{{
{
    const int V = G.size();
    vector<i64> dist(V, LINF);
    dist[src] = 0;

    bool updated = true;
    for (int i = 0; updated && i < V-1; ++i) {
        updated = false;
        rep(s, V) if (dist[s] < LINF) {
            for (const auto &e : G[s]) updated |= chmin(dist[e.to], dist[s] + e.cost);
        }
    }

    rep(s, V) for (const auto &e : G[s]) {
        if (dist[s] + e.cost < dist[e.to]) return {};
    }

    return dist;
}
// }}}
//@@@@@@@


/*
   Verified On: 2019-08-11
   https://atcoder.jp/contests/abc137/tasks/abc137_e
*/
void arrivableNodeDFS(int u, const WGraph &G, bool vist[]) // {{{
{
    if (!vist[u]) {
        vist[u] = true;
        for (const auto &e : G[u]) arrivableNodeDFS(e.to, G, vist);
    }
} // }}}
void ABC137_E() // {{{
{
    int N, M, P;
    cin >> N >> M >> P;

    WGraph G(N), revG(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        c -= P;
        G[a].emplace_back(a, b, -c);
        revG[b].emplace_back(b, a, -c);
    }

    bool canArrive[2555] {};
    bool canGoal[2555] {};

    arrivableNodeDFS(0, G, canArrive);
    arrivableNodeDFS(N-1, revG, canGoal);

    WGraph H(N);
    rep(u, N) {
        if (canArrive[u] && canGoal[u]) {
            for (const auto &e : G[u]) H[u].emplace_back(e);
        }
    }

    const auto cost = bellmanFord(H, 0);
    if (cost.empty()) {
        cout << -1 << endl;
    } else {
        cout << max<i64>(0, -cost[N-1]) << endl;
    }
}
// }}}

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    ABC137_E();

    return 0;
}

