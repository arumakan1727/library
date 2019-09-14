#include "bits/stdc++.h"
using namespace std;

template< typename G >
struct LowLink {
    const G &g;
    vector<int> used, ord, low;
    vector<int> articulation;
    vector<pair<int, int>> bridge;

    LowLink(const G &g) : g(g) {}

    int dfs(int idx, int k, int par) {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false;
        int cnt = 0;
        for(auto &to : g[idx]) {
            if(!used[to]) {
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                is_articulation |= ~par && low[to] >= ord[idx];
                if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
            } else if(to != par) {
                low[idx] = min(low[idx], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if(is_articulation) articulation.push_back(idx);
        return k;
    }

    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for(int i = 0; i < g.size(); i++) {
            if(!used[i]) k = dfs(i, k, -1);
        }
    }
};

void GRL3_A()
{
    using UnWeightedGraph = vector<vector<int>>;

    int V, E;
    scanf("%d %d", &V, &E);
    UnWeightedGraph g(V);
    for(int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    LowLink< UnWeightedGraph > lowlink(g);
    lowlink.build();
    sort(lowlink.articulation.begin(), lowlink.articulation.end());
    for(auto &v : lowlink.articulation) printf("%d\n", v);
}


void GRL3_B()
{
    using UnWeightedGraph = vector<vector<int>>;

    int V, E;
    scanf("%d %d", &V, &E);
    UnWeightedGraph g(V);
    for(int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    LowLink< UnWeightedGraph > lowlink(g);
    lowlink.build();
    sort(lowlink.bridge.begin(), lowlink.bridge.end());
    for(auto &p : lowlink.bridge) printf("%d %d\n", p.first, p.second);
}
