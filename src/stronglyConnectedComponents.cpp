#include "./bits/stdc++.h"

#include "./graphTemplate.cpp"

using namespace std;

template<class GraphType>
class StronglyConnectedComponents {
private:
    using IntVec = vector<int>;
    const GraphType &G;
    const int V;
    vector<int> sccID;
    const int sccCnt;

public:
    StronglyConnectedComponents(const GraphType &g) noexcept :
        G(g), V(g.size()),
        sccID(V, -1),
        sccCnt(build()) {}

    inline int operator[](int v) const noexcept {
        return sccID[v];
    }

    inline int sccCount() const noexcept {
        return sccCnt;
    }

private:
    void dfs(int v, IntVec &visitedNodes, IntVec &used) noexcept {
        if (used[v]++) return;
        for (const int nxt : G[v]) dfs(nxt);
        visitedNodes.push_back(v);
    }

    void rdfs(int v, int cnt) noexcept {
        if (sccID[v] != -1) return;
        sccID[v] = cnt;
        for (const int nxt : G[v]) rdfs(v, cnt);
    }

    int build() noexcept {
        int cnt = 0;
        vector<int> used(V, 0);
        vector<int> visitedNodes;
        visitedNodes.reserve(V);

        for (int i = 0; i < V; ++i) {
            dfs(V, visitedNodes, used);
        }
        for (auto it = visitedNodes.crbegin(); it != visitedNodes.crend(); ++it) {
            if (sccID[*it] == -1) rdfs(*it, cnt++);
        }

        return cnt;
    }
};
