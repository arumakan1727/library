#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp
// Verified On: 2019-08-12

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/primeNumber.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    int ans = 0;
    rep(i, N) {
        int p; cin >> p;
        if (isPrime(p)) ++ans;
    }

    cout << ans << endl;

    return 0;
}
