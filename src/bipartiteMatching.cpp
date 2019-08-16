#include "bits/stdc++.h"
#include "commonHeader.hpp"

//@@@@@@@@@@
//@ snippet bipartiteMatching
//@ alias   biMatch
//@ options head
struct BipartiteMatching { // {{{
    vector<vector<int>> G;
    vector<int> match, used;
    vector<uint8_t> dead;
    int timestamp = 0;

    BipartiteMatching() {}
    BipartiteMatching(int N)
        : G(N+1), match(N+1, -1), used(N+1, 0), dead(N+1, false) {};

    void addEdge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int dfs(int cur) {
        used[cur] = timestamp;
        for (const int to : G[cur]) {
            if (dead[to]) continue;
            const int m = match[to];
            if (m == -1 || (used[m] < timestamp && !dead[m] && dfs(m))) {
                match[cur] = to;
                match[to] = cur;
                return 1;
            }
        }
        return 0;
    }

    int build() {
        int res = 0;
        for (int v = 0; v < G.size(); ++v) {
            if (dead[v] || ~match[v]) continue;
            ++timestamp;
            res += dfs(v);
        }
        return res;
    }

    int disable(int v) {
        dead[v] = true;
        match[v] = -1;
        const int m = match[v];
        if (m == -1) {
            return 0;
        } else {
            match[m] = -1;
            ++timestamp;
            return dfs(m) - 1;
        }
    }

    int enable(int v) {
        dead[v] = false;
        ++timestamp;
        return dfs(v);
    }
}; // }}}
//@@@@@@@@@@

signed main()
{
}
