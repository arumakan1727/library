#include "bits/stdc++.h"
#include "./commonHeader.hpp"

#include "./graphTemplate.cpp"

//@@@@@@@@
//@ snippet floyd
//@ alias   warshall warshallFloyd
//@ options head
// [戻り値]
//      (不閉路あり) => -1
//      (不閉路なし) => 0
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
