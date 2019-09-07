#define PROBLEM https://atcoder.jp/contests/agc033/tasks/agc033_a
// Verified On : 2019-09-07

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/gridBFS.cpp"

using namespace std;

int AGC033_A()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    var(int, H, W);
    vector<string> mat(H);
    vector<pair<int,int>> starts;

    rep(i, H) {
        input(mat[i]);
        rep(j, W) {
            if (mat[i][j] == '#') starts.emplace_back(i, j);
        }
    }

    const auto dist = gridBFS(mat, starts, "#");

    int res = 0;
    rep(i, H) rep(j, W) chmax(res, dist[i][j]);

    print(res);

    return 0;
}


int main()
{
    return AGC033_A();
}
