#include "./bits/stdc++.h"

using namespace std;

//@@@@@@@@@@
//@ snippet topologicalSort
//@ options head
namespace topologicalSort { /// {{{
    namespace {
        template <class Edge> using Graph = vector<vector<Edge>>;
    }

    template <class Edge>
    vector<int> sortedNodeArray(const Graph<Edge> &G) {
        const int V = G.size();
        vector<int> indeg(V, 0);
        vector<int> ans, stk;
        ans.reserve(V);
        stk.reserve(V);

        for (int v = 0; v < V; ++v) {
            for (const int to : G[v]) ++indeg[to];
        }
        for (int v = 0; v < V; ++v) {
            if (indeg[v] == 0) stk.emplace_back(v);
        }

        while (stk.size()) {
            const int v = stk.back(); stk.pop_back();
            ans.emplace_back(v);
            for (const int to : G[v]) {
                if (--indeg[to] == 0) stk.emplace_back(to);
            }
        }

        return ans;
    }

    template <class Edge>
    vector<int> orderTable(const Graph<Edge> &G) {
        const auto sorted = sortedNodeArray(G);
        vector<int> order(G.size());

        for (int i = 0; i < sorted.size(); ++i) {
            order[sorted[i]] = i;
        }

        return order;
    }
} // }}}
//@@@@@@@@@@
