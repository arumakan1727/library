#include "bits/stdc++.h"
using namespace std;


//@@@@@@@
//@ snippet modPow
//@ options head
constexpr long long modPow(long long n, long long p, const int mod = int(1e9)+7)
{
    long long ret = 1;
    while(p) {
        if (p & 1) ret = (ret * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }
    return ret;
}
//@@@@@



//@@@@@@
//@ snippet ModInt
//@ alias   Mint
//@ options head
template<int MOD> class ModInt {
private:
    long long n;
    using T = ModInt<MOD>;
public:
    static constexpr const int mod = MOD;
    constexpr inline ModInt(long long n_) : n(n_ % MOD) {}
    template<class Int> constexpr explicit inline operator Int() const { return n; }
    friend ostream& operator<<(ostream &os, T m) { os << m.n; return os; }
    constexpr inline T operator~() const { return modPow(n, MOD-2, MOD); }
    constexpr inline T& operator+=(T o) { n = (n + o.n) % MOD; return *this; }
    constexpr inline T& operator-=(T o) { n = (n - o.n + MOD) % MOD; return *this; }
    constexpr inline T& operator*=(T o) { n = (n * o.n) % MOD; return *this; }
    constexpr inline T& operator/=(T o) { n = (n * (~o).n) % MOD; return *this; }
};
using Mint = ModInt<int(1e9)+7>;
Mint operator+(Mint a, Mint b) { return Mint(a) += b; }
Mint operator-(Mint a, Mint b) { return Mint(a) -= b; }
Mint operator*(Mint a, Mint b) { return Mint(a) *= b; }
Mint operator/(Mint a, Mint b) { return Mint(a) /= b; }
//@@@@@



//@@@@@@
//@ snippet Factrial
//@ alias   nCr nPr
//@ options head
template<size_t N, int MOD=int(1e9)+7> struct Factrial {
    using Mint = ModInt<MOD>;
    long long a[N+1];

#ifdef YDK
    inline Factrial() : a{1} { for (int i = 1; i <= N; ++i) a[i] = (a[i-1] * i) % MOD; }
#else
    constexpr inline Factrial() : a{1} { for (int i = 1; i <= N; ++i) a[i] = (a[i-1] * i) % MOD; }
#endif

    constexpr inline Mint operator[] (size_t i) const { return a[i]; }
};

Factrial<100010> fact;

Mint nCr(int n, int r) { return (r < 0 || n < r) ? 0 : (fact[n] / (fact[r] * fact[n-r])); }

Mint nPr(int n, int r) { return (r < 0 || n < r) ? 0 : (fact[n] / fact[r]); }

Mint nHr(int n, int r) { return nCr(n+r-1, r); }
//@@@@@@




struct FastIO {
    FastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); }
} fastIO_ydk ;


/*
 * Verified on : 2019-06-18
 * https://atcoder.jp/contests/arc077/tasks/arc077_b
 */
void ARC077_D()
{
    int N;
    int a[100010];
    bool exist[100010] {};
    int twice;

    cin >> N;
    for (int i = 0; i < N+1; ++i) {
        cin >> a[i];
        if (exist[a[i]]) {
            twice = a[i];
        } else {
            exist[a[i]] = true;
        }
    }

    int l, r;
    for (l = 0; a[l] != twice; ++l);
    for (r = N; a[r] != twice; --r);

    const int M = N - (r - l);

    for (int k = 1; k <= N+1; ++k) {
        cout << nCr(N+1, k) - nCr(M, k-1) << '\n';
    }
    return;
}

signed main()
{
    ARC077_D();

    return 0;
}
