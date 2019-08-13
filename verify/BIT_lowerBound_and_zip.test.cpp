#define PROBLEM https://yukicoder.me/problems/no/649
// Verified On: 2019-08-12

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/zip.cpp"
#include "../src/fenwickTree.cpp"

signed main()
{
    int Q, K;
    cin >> Q >> K;

    Zip<i64> appearNumbers;
    appearNumbers.reserve(Q);

    vector<pii> query(Q);


    rep(i, Q) {
        int com; cin >> com;

        if (com == 1) {
            i64 v; cin >> v;
            appearNumbers.emplace_back(v);
            query[i] = pii(com, v);
        } else {
            query[i] = pii(com, -1);
        }
    }

    appearNumbers.compress();

    const int N = appearNumbers.size();

    FenwickTree<i64> ft(N);
    rep(i, Q) {
        if (query[i].first == 1) {
            const auto val = query[i].second;
            ft.add(appearNumbers(val), 1);
        } else {
            if (ft.sum(N) < K) {
                cout << -1 << '\n';
            } else {
                const int id = ft.lower_bound(K);
                ft.add(id, -1);
                cout << appearNumbers[id] << '\n';
            }
        }
    }

    return 0;
}
