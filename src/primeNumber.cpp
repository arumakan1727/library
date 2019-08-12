#include "bits/stdc++.h"
#include "commonHeader.hpp"

//@@@@@@@
//@ snippet eratosthenes
//@ options head
// Make PrimeTable [0, N] in Compile Time.
template<size_t N> struct Eratosthenes { // {{{
#ifdef DBG
#define constexpr /* Disable constexpr */
#endif

    bool isPrime[N+1] {};

    constexpr explicit Eratosthenes() {
        if (N < 2) return;
        isPrime[2] = true;
        for (int i = 3; i <= N; i += 2) isPrime[i] = true;
        for (int i = 3; i*i <= N; i += 2) {
            if (isPrime[i]) for (int k = i*i; k <= N; k += i) isPrime[k] = false;
        }
    }

    constexpr vector<int> primes(size_t n = N) const {
        if ((n = min(n,N)) < 2) return {};
        vector<int> a { 2 };
        for(int i=3; i <= n; i+=2) if (isPrime[i]) a.push_back(i);
        return a;
    }

    constexpr bool operator[] (size_t i) const { return isPrime[i]; }

#ifdef constexpr
#undef constexpr
#endif
}; // }}}
//@@@@@@@


//@@@@@@@
//@ snippet isPrime
//@ options head
// n が素数ならtrueを返す。 O(sqrt(N))
constexpr bool isPrime(i64 n) // {{{
{
    if (n < 2) return false;
    if (n % 2 == 0) return (n == 2);
    for(i64 i=3; i*i <= n; i += 2) if(n % i == 0) return false;
    return true;
} // }}}
//@@@@@@@
