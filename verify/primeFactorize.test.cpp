#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
// Verified On: 2019-08-12

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/primeFactorize.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    vector<int> ans;
    for (const auto &e : primeFactorize(N)) {
        rep (i, e.second) ans.push_back(e.first);
    }

    cout << N << ": " << ans << endl;

    return 0;
}
