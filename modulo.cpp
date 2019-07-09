#include "bits/stdc++.h"
using namespace std;

//@@@@@@@
//@ snippet modulo
//@ options head
namespace modulo { // {{{
    constexpr int MOD = int(1e9) + 7;
    using i64 = long long;

    constexpr i64 modPow(i64 n, i64 p, const int mod = MOD) { // {{{
        i64 ret = 1;
        for(; p > 0; p >>= 1) {
            if (p & 1) ret = (ret * n) % mod;
            n = (n * n) % mod;
        }
        return ret;
    }
    //////////////////////////////// }}}

    class modint { // {{{
    private:
        i64 n;
    public:
        constexpr inline modint(i64 n_) : n(n_ % MOD) {}
        template<class Int> constexpr explicit inline operator Int() const { return n; }
        friend ostream& operator<<(ostream &os, modint m) { os << m.n; return os; }
        constexpr inline modint operator~() const { return modPow(n, MOD-2, MOD); }
        constexpr inline modint& operator+=(modint o) { n = (n + o.n) % MOD; return *this; }
        constexpr inline modint& operator-=(modint o) { n = (n - o.n + MOD) % MOD; return *this; }
        constexpr inline modint& operator*=(modint o) { n = (n * o.n) % MOD; return *this; }
        constexpr inline modint& operator/=(modint o) { n = (n * (~o).n) % MOD; return *this; }
    };

    modint operator+(modint a, modint b) { return modint(a) += b; }
    modint operator-(modint a, modint b) { return modint(a) -= b; }
    modint operator*(modint a, modint b) { return modint(a) *= b; }
    modint operator/(modint a, modint b) { return modint(a) /= b; }
    //////////////////////////////// }}}

    // Factrial, InvFact {{{
#ifdef YDK
#define constexpr
#endif
    template<size_t N> struct Factrial {
        i64 f[N+1];
        constexpr inline Factrial() : f{1} { for (int i = 1; i <= N; ++i) f[i] = (f[i-1] * i) % MOD; }
        constexpr inline modint operator[] (size_t i) const { return f[i]; }
    };
    template<size_t N> struct InvFact {
        i64 inv[N+1];
        i64 f[N+1];
        constexpr inline InvFact() : inv{0, 1}, f{1, 1} {
            for (int i = 2; i < N; ++i) {
                inv[i] = (MOD - MOD/i) * inv[MOD % i] % MOD;
                f[i] = f[i-1] * inv[i] % MOD;
            }
        }
        constexpr inline modint operator[] (size_t i) const { return f[i]; }
    };
#ifdef YDK
#undef constexpr
#endif
    //////////////////////////////// }}}

    Factrial<100010> fact;
    InvFact<100010> invFact;

    modint nCr(int n, int r) { return (r < 0 || n < r) ? 0 : (fact[n] * (invFact[r] * invFact[n-r])); }
    modint nPr(int n, int r) { return (r < 0 || n < r) ? 0 : (fact[n] * invFact[r]); }
    modint nHr(int n, int r) { return nCr(n+r-1, r); }
}

using namespace modulo;
//}}}
//@@@@@@



/*
 * Verified on : 2019-07-10
 * https://atcoder.jp/contests/arc077/tasks/arc077_b
 */
struct FastIO {
    FastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); }
} fastIO_ydk ;
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
