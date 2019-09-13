#include "bits/stdc++.h"
using namespace std;

#include "./graphTemplate.cpp"

//@@@@@@@@@@
//@ snippet DoublingLCA
//@ alias   LCA
//@ options head
class DoublingLCA { // {{{
public:
    const int V;
    const int LOG_V;
    Graph G;
    vector<int> depth;
    vector<int64_t> weightSum;
    vector<vector<int>> table;  // table[k][v] = ノード v から根へ 2^k だけ登った先のノード番号

    DoublingLCA() = delete;

    // ノード番号 [0, n) を管理する
    DoublingLCA(int n) :
        V(n),
        LOG_V(32 - __builtin_clz(V)),   // ceil(log2(V))
        G(V),
        depth(V),
        weightSum(V),
        table(LOG_V, vector<int>(V, -1)) {}


    // u-v間に無向辺を張る。重みは省略可
    inline void addEdge(int u, int v, int64_t weight = 0) noexcept {
        G.addEdge(u, v, weight);
        G.addEdge(v, u, weight);
    }

    // 前計算
    void build(int root) noexcept {
        dfs(root, -1, 0, 0);
        for (int k = 0; (k + 1) < LOG_V; ++k) {
            for (int v = 0; v < V; ++v) {
                if (table[k][v] == -1) continue;
                table[k + 1][v] = table[k][table[k][v]];
            }
        }
    }

    // u,v のLCAを求める
    inline int lca(int u, int v) const noexcept {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = LOG_V - 1; i >= 0; --i) {
            if ((depth[v] - depth[u]) & (1 << i)) v = table[i][v];
        }

        if (u == v) return u;

        for (int i = LOG_V - 1; i >= 0; --i) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    // v から根へ k だけ登った先のノードを求める
    inline int climb(int v, int k) const noexcept {
        int i = 0;
        while(k > 0) {
            if (k & 1) v = table[i][v];
            ++i;
            k >>= 1;
        }
        return v;
    }

    // u-v間のパスの重みの和を求める
    inline int pathWeight(int u, int v) const noexcept {
        return weightSum[u] + weightSum[v] - 2 * weightSum[lca(u, v)];
    }

    // u-v間のパスの「辺の本数」を求める
    inline int pathLength(int u, int v) const noexcept {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

private:
    void dfs(int v, int par, int dep, int64_t ws) noexcept {
        depth[v] = dep;
        weightSum[v] = ws;
        table[0][v] = par;
        for (const auto &e : G[v]) {
            if (e.to != par) dfs(e.to, v, dep + 1, ws + e.cost);
        }
    }
};  // }}}
//@@@@@@@@@@
