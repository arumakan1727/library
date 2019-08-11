#include "bits/stdc++.h"
// Custom Header {{{
#define all(x) x.begin(), x.end()
#define rep(i,n)    for (i64 i = 0; i < (n); ++i)
#define reps(i,s,t) for (i64 i = (s); i <= (t); ++i)
#define repr(i,s,t) for (i64 i = (s); i >= (t); --i)
using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

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


