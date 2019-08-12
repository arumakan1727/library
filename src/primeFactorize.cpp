#include "bits/stdc++.h"
#include "./commonHeader.hpp"

//@@@@@@@
//@ snippet primeFactorize
//@ options head
// n の素因数を (素因数, 個数) のペアで列挙して返す。O(sqrt(N))
map<i64, int> primeFactorize(i64 n) // {{{
{
    map<i64, int> pf;
    for (i64 i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            pf[i] += 1;
            n /= i;
        }
    }
    if (n != 1) pf[n] = 1;
    return pf;
} // }}}
//@@@@@@@
