#include "./bits/stdc++.h"

using namespace std;

//@@@@@@@@@@
//@ snippet StronglyConnectedComponents
//@ alias   SCC
//@ options head
class StronglyConnectedComponents { // {{{
private:
    const int V;
    vector<vector<int>> gg, rg;
    vector<int> topoOrder;
    int sccCnt;

public:
    // ノード番号 [0, n) を管理する
    StronglyConnectedComponents(int n) noexcept :
        V(n),
        gg(V), rg(V),
        topoOrder(V, -1),
        sccCnt(0) {}

    // fromからtoへ辺を張る
    inline void addEdge(int from, int to) noexcept {
        gg[from].push_back(to);
        rg[to].push_back(from);
    }

    // ノード v のトポロジカル順序。 [0, sccCount) 未満の値を取る。
    inline int operator[](int v) const noexcept {
        return topoOrder[v];
    }

    // 各ノードのトポロジカル順序を求める(=どの強連結成分に属するか求める)
    void build() noexcept {
        vector<int> used(V, 0);
        vector<int> visitedNodes;
        visitedNodes.reserve(V);
        sccCnt = 0;

        for (int i = 0; i < V; ++i) {
            dfs(i, visitedNodes, used);
        }
        for (auto it = visitedNodes.crbegin(); it != visitedNodes.crend(); ++it) {
            if (topoOrder[*it] == -1) rdfs(*it, sccCnt++);
        }
    }

    // 強連結成分の個数
    inline int sccCount() const noexcept {
        return sccCnt;
    }

    // 強連結成分ごとに縮約した結果のDAGを新しく作る
    // ノード番号が小さいほどトポロジカル順序が早い
    // (2つのノード番号a, bについて、a < b なら b から a へ行けない)
    vector<vector<int>> createDAG() const noexcept {
        vector<vector<int>> C(sccCnt);
        for (int v = 0; v < V; ++v) {
            for (const int &to : gg[v]) {
                if (topoOrder[v] != topoOrder[to]) {
                    C[topoOrder[v]].push_back(topoOrder[to]);
                }
            }
        }
        for (int i = 0; i < sccCnt; ++i) {
            sort(C[i].begin(), C[i].end());
            C[i].erase(unique(C[i].begin(), C[i].end()), C[i].end());
        }
        return C;
    }

private:
    void dfs(int v, vector<int> &visitedNodes, vector<int> &used) noexcept {
        if (used[v]++) return;
        for (const int nxt : gg[v]) dfs(nxt, visitedNodes, used);
        visitedNodes.push_back(v);
    }

    void rdfs(int v, int cnt) noexcept {
        if (topoOrder[v] != -1) return;
        topoOrder[v] = cnt;
        for (const int nxt : rg[v]) rdfs(nxt, cnt);
    }
}; // }}}
//@@@@@@@@@@
