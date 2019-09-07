#include "bits/stdc++.h"
using namespace std;

#include "./graphTemplate.cpp"

//@@@@@@@@@@
//@ snippet HeavyLightDecomposition
//@ alias   HLD HLDecomp
//@ options head
class HeavyLightDecomposition { // {{{
public:
    const int V;                // ノード数
    Graph G;                    // グラフ
    vector<int> parent;         // 親
    vector<int> treeSize;       // 自分も含めた部分木のサイズ
    vector<int> head;           // HL分解後の自分が属するグループ(チェイン)の先頭ノード
    vector<int> vid;            // 根からDFSしたときにそのノードを訪れた順番
    vector<int> nodeOfVid;      // vidからノードを逆算する用
    vector<int64_t> weightSum;  // 根からのコストの総和
    vector<int> depth;          // 根からの深さ(経由するエッジの数)

    HeavyLightDecomposition() = delete;

    // 空の木を構築する。管理できるノードは [0, V]。
    explicit HeavyLightDecomposition(int n) noexcept :
        V(n + 1),
        G(V),
        parent(V, -1), treeSize(V), head(V),
        vid(V), nodeOfVid(V),
        weightSum(V, 0),
        depth(V, 0) {}


    // u-v間に無向辺を張る。重みは省略可
    inline void addEdge(int u, int v, int64_t weight = 0) noexcept {
        G[u].emplace_back(u, v, weight);
        G[v].emplace_back(v, u, weight);
    }

    // 根を root としてHL分解、その他もろもろ前計算
    inline void build(int root) noexcept {
        int timestamp = 0;
        head[root] = root;
        dfs_treeSize(root);
        dfs_HLDecomp(root, timestamp);
    }

    // u,v の最小共通祖先を求める
    inline int lca(int u, int v) const noexcept {
        while(head[u] != head[v]) {
            if (vid[u] > vid[v]) swap(u, v);
            v = parent[head[v]];
        }
        return (vid[u] < vid[v]) ? u : v;
    }

    // v から根へ k だけ登った先のノードを求める
    inline int climb(int v, int k) const noexcept {
        while(1) {
            const int h = head[v];
            if (vid[v] - k >= vid[h]) return nodeOfVid[vid[v] - k];
            k -= vid[v] - vid[h] + 1;
            v = parent[h];
        }
    }

    // u-v間のパスの重みの和を求める
    inline int64_t pathWeight(int u, int v) const noexcept {
        return weightSum[u] + weightSum[v] - 2 * weightSum[lca(u, v)];
    }

    // u-v間のパスの「エッジの個数」を求める
    inline int pathLength(int u, int v) const noexcept {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

private: // {{{

    // treeSize[v], parent[v], depth[v], weightSum[v] を再帰によって計算
    // v の子の中で最もheavyなやつを G[v] の先頭にもってくる
    int dfs_treeSize(int v) noexcept {
        treeSize[v] = 1;
        if (!G[v].empty() && G[v].front().to == parent[v]) swap(G[v].front(), G[v].back());
        for (auto &e : G[v]) {
            if (e.to == parent[v]) continue;
            parent[e.to] = v;
            depth[e.to] = depth[v] + 1;
            weightSum[e.to] = weightSum[v] + e.cost;
            treeSize[v] += dfs_treeSize(e.to);
            if (treeSize[e.to] > treeSize[G[v].front()]) swap(e, G[v].front());
        }
        return treeSize[v];
    }

    // G[v] の先頭に v の子中で最もheavyなノードがある前提でHL分解し、
    // vid[v], nodeOfVid[v], head[v] を求める
    void dfs_HLDecomp(int v, int &timestamp) noexcept {
        vid[v] = timestamp;
        nodeOfVid[timestamp] = v;
        ++timestamp;
        for (const int to : G[v]) {
            if (to == parent[v]) continue;
            head[to] = (to == G[v].front() ? head[v] : to);
            dfs_HLDecomp(to, timestamp);
        }
    } // }}}
}; // }}}
//@@@@@@@@@@
