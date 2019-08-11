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

//@@@@@@@
//@ snippet dijkstra
//@ options head
vector<i64> dijkstra(const WGraph &G, int src) // {{{
{
    vector<i64> dist(G.size(), LINF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()) {
        const i64 nowCost = pq.top().first;
        const int nowNode = pq.top().second;
        pq.pop();
        if (dist[nowNode] < nowCost) continue;

        for (const auto &e : G[nowNode]) {
            const i64 newCost = nowCost + e.cost;
            if (chmin(dist[e.to], newCost)) {
                pq.emplace(newCost, e.to);
            }
        }
    }

    return dist;
}
// }}}
//@@@@@@@@


/*
   Verified On: 2019-07-14
   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
*/
void AOJ_GRL_1_A() // {{{
{
    int V, E, src;
    cin >> V >> E >> src;

    WGraph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        G[s].emplace_back(t, c);
    }

    auto dist = dijkstra(G, src);

    for (i64 d : dist) {
        if (d >= LINF) cout << "INF" << endl;
        else cout << d << endl;
    }
}
// }}}

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    AOJ_GRL_1_A();

    return 0;
}
