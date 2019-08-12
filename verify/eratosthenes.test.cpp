// Verified On: 2019-08-12
#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/primeNumber.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    const vector<int> primes = Eratosthenes<1'000'005>().primes();

    int n;
    while(cin >> n) {
        cout << upper_bound(all(primes), n) - begin(primes) << endl;
    }

    return 0;
}
