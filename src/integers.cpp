#include "bits/stdc++.h"
#include "./commonHeader.hpp"

//@@@@@@@
//@ snippet divisors
//@ options head
// Returns n divisors ORDER BY ASC.
vector<i64> getDivisors(i64 n) // {{{
{
    vector<i64> ret;
    i64 i = 1;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            ret.emplace_back(n / i);
        }
    }
    if (i * i == n) ret.emplace_back(i);
    sort(begin(ret), end(ret));
    return ret;
} // }}}
//@@@@@@@



//@@@@@@@
//@ snippet GCD
//@ alias   gcd
//@ options head
// Returns GCD of |a| and |b|.
// If (a == 0) then return b, If (b == 0) then return a.
i64 GCD(i64 a, i64 b) // {{{
{
    a = abs(a); b = abs(b);
    if (a > b) swap(a, b);
    while(b > 0) {
        i64 r = a % b;
        a = b;
        b = r;
    }
    return a;
} // }}}
//@@@@@@



//@@@@@@@
//@ snippet LCM
//@ alias   lcm
//@ options head
// Returns LCM of |a| and |b|
i64 LCM(i64 a, i64 b) // {{{
{
    return abs(a) / GCD(a,b) * abs(b);
} // }}}
//@@@@@@



//@@@@@@@
//@ snippet extGCD
//@ alias   extgcd
//@ options head
// Find x,y WHERE (a*x + b*y == gcd(a,b))
i64 extGCD(i64 a, i64 b, i64 &x, i64 &y) // {{{
{
    x = 1, y = 0;
    i64 g = a;
    if (b != 0) {
        g = extGCD(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
} // }}}
//@@@@@@



//@@@@@@@
//@ snippet combTable
//@ alias   comb combination CombTable
//@ options head
// Make Combination table using "Pascal's Triangle" at Compile-Time
template<size_t N> struct CombTable { // {{{
    static_assert(N < 70u, "Template parameter <N> is too large. It may be Overflow.");
    i64 mat[N+1][N+1];
    constexpr explicit CombTable() {
        for (int n = 0; n <= N; ++n) {
            for (int r = 0; r <= n; ++r) {
                mat[n][r] = ((r == 0 || n == r) ? (1) : (mat[n-1][r-1] + mat[n-1][r]));
            }
        }
    }
    i64 operator() (int n, int r) const { return (r < 0 || n < r) ? 0 : mat[n][r]; }
}; // }}}
//@@@@@@@
