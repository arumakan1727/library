#include "bits/stdc++.h"
// Custom Header {{{
#define ALL(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

//@@@@@@@
//@ snippet edge
//@ alias   graph
//@ options  head
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
using Ugraph = vector<vector<int>>;
// }}}
//@@@@@@


//@@@@@@@
//@ snippet MatrixGraph
//@ alias   matrixGraph
//@ options  head
template<size_t N>
struct MatrixGraph { // {{{
    i64 G[N][N];
    constexpr explicit MatrixGraph() {
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) G[i][j] = LINF;
        for (int i = 0; i < N; ++i) G[i][i] = 0;
    }
    i64* operator[] (size_t i) { return G[i]; }
    const i64* operator[] (size_t i) const { return G[i]; }
};
// }}}
//@@@@@@@@

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



//@@@@@@@@
//@ snippet bellmanFord
//@ options head
// 負閉路検出は別途 checkNegativeCycle() を用いてね
vector<i64> bellmanFord(const Edges &es, int V, int src) // {{{
{
    vector<i64> dist(V, LINF);
    dist[src] = 0;

    bool updated = true;
    for (int i = 0; updated && i < V-1; ++i) {
        updated = false;
        for (const auto &e : es) {
            if (dist[e.src] == LINF) continue;
            updated |= chmin(dist[e.to], dist[e.src] + e.cost);
        }
    }

    return dist;
}
// }}}
//@@@@@@@


//@@@@@@@@
//@ snippet negativeCycle
//@ alias   checkNegativeCycle
//@ options head
vector<uint8_t> checkNegativeCycle(const Edges &es, int V, const vector<i64> &dist) // {{{
{
    vector<uint8_t> negative(V, 0);
    for (int i = 0; i < V; ++i) {
        for (const auto &e : es) {
            if (dist[e.src] >= LINF) continue;
            negative[e.to] |= negative[e.src] |= (dist[e.to] > dist[e.src] + e.cost);
        }
    }
    return negative;
}
// }}}
//@@@@@@@


//@@@@@@@@
//@ snippet SPFA
//@ alias   spfa
//@ options head
vector<i64> SPFA(const WGraph &G, int src) // {{{
{
    vector<i64> dist(G.size(), LINF);
    vector<int> cnt(G.size(), 0);
    vector<bool> pending(G.size(), false);
    queue<int> que;

    que.emplace(src);
    ++cnt[src];
    dist[src] = 0;

    while(!que.empty()) {
        const int u = que.front(); que.pop();
        pending[u] = false;
        for (const auto &e : G[u]) {
            if (!chmin(dist[e.to], dist[u] + e.cost)) continue;
            if (pending[e.to]) continue;
            if (++cnt[e.to] >= G.size()) return {};
            pending[e.to] = true;
            que.emplace(e.to);
        }
    }

    return dist;
}
// }}}
//@@@@@@@@


//@@@@@@@@
//@ snippet floyd
//@ alias   warshall warshallFloyd
//@ options head
template<size_t N>
int floyd(MatrixGraph<N> &G, int V) // {{{
{
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            if (G[i][k] >= LINF) continue;
            for (int j = 0; j < V; ++j) {
                if (G[k][j] >= LINF) continue;
                chmin(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    for (int i = 0; i < V; ++i) if (G[i][i] < 0) return -1;
    return 0;
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


/*
   Verified On: 2019-07-14
   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
*/
void AOJ_GRL_1_B() // {{{
{
    int V, E, src;
    cin >> V >> E >> src;

    WGraph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        G[s].emplace_back(t, c);
    }

    auto dist = SPFA(G, src);

    if (dist.empty()) {
        cout << ("NEGATIVE CYCLE") << endl;
    } else {
        for (auto e : dist) {
            if (e >= LINF) cout << "INF" << endl;
            else cout << e << endl;
        }
    }
}
// }}}

/*
   Verified On: 2019-07-14
   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
*/
void AOJ_GRL_1_C() // {{{
{
    static MatrixGraph<105> G;
    int V, E;

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        G[s][t] = c;
    }

    if (floyd(G, V) < 0) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << (G[i][j] >= LINF ? "INF" : to_string(G[i][j])) << ((j < V-1) ? ' ' : '\n');
            }
        }
    }

}
// }}}

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    AOJ_GRL_1_C();
    return 0;
}
