#include "bits/stdc++.h"
#include "commonHeader.hpp"

#ifndef INCLUDED_YDK_MOD_INT_CPP
#define INCLUDED_YDK_MOD_INT_CPP

//@@@@@@@
//@ snippet modint
//@ options head
// ModInt {{{
template<int64_t MOD>
class ModInt {
    int64_t n;
public:
    inline ModInt(int64_t n = 0) : n((n >= MOD) ? (n % MOD) : (n < 0) ? ((n + MOD) % MOD) : n) {}
    inline ModInt inv() const noexcept { return pow(n, MOD-2); }

    inline ModInt& operator+=(ModInt o) noexcept { n = (n + o.n) % MOD; return *this; }
    inline ModInt& operator-=(ModInt o) noexcept { n = (MOD + n - o.n) % MOD; return *this; }
    inline ModInt& operator*=(ModInt o) noexcept { n = (n * o.n) % MOD; return *this; }
    inline ModInt& operator/=(ModInt o) noexcept { n = (n * (~o).n) % MOD; return *this; }

    inline bool operator==(ModInt o) const noexcept { return n == o.n; }
    inline bool operator!=(ModInt o) const noexcept { return !(*this == o); }

    template<class Int>
    explicit inline operator Int() const noexcept { return static_cast<Int>(n); }

    friend ostream& operator<<(ostream &os, ModInt o) { os << o.n; return os; }
    friend istream& operator>>(istream &is, ModInt &o) { is >> o.n; return is; }

    static constexpr inline ModInt pow(int64_t n, int64_t p) noexcept {
        int64_t ret = 1;
        for(; p > 0; p >>= 1) {
            if (p & 1) ret = (ret * n) % MOD;
            n = (n * n) % MOD;
        }
        return ret;
    }
};
template<int64_t MOD> auto operator+(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) += b; }
template<int64_t MOD> auto operator-(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) -= b; }
template<int64_t MOD> auto operator*(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) *= b; }
template<int64_t MOD> auto operator/(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) /= b; }
template<int64_t MOD> auto operator+(ModInt<MOD> a, int64_t b) { return ModInt<MOD>(a) += b; }
template<int64_t MOD> auto operator-(ModInt<MOD> a, int64_t b) { return ModInt<MOD>(a) -= b; }
template<int64_t MOD> auto operator*(ModInt<MOD> a, int64_t b) { return ModInt<MOD>(a) *= b; }
template<int64_t MOD> auto operator/(ModInt<MOD> a, int64_t b) { return ModInt<MOD>(a) /= b; }
// }}}

using modint = ModInt<int(1e9) + 7>;
//@@@@@@


//@@@@@@@@@@
//@ snippet modulo
//@ options head
struct Modulo { // {{{
    const int64_t MOD;
    const int64_t value;

    explicit Modulo(int64_t val, int64_t mod) :
        MOD(mod),
        value((val >= MOD) ? (val % MOD) : (val < 0) ? ((val + MOD) % MOD) : val) { }

    inline Modulo add(int64_t x) const noexcept { return Modulo(value + x, MOD); }
    inline Modulo sub(int64_t x) const noexcept { return Modulo(value - x, MOD); }
    inline Modulo mul(int64_t x) const noexcept { return Modulo(value * x, MOD); }
    inline Modulo div(int64_t x) const noexcept { return Modulo(x, MOD).pow(MOD-2).mul(value); }

    inline Modulo add(Modulo m) const noexcept { return add(m.value); }
    inline Modulo sub(Modulo m) const noexcept { return sub(m.value); }
    inline Modulo mul(Modulo m) const noexcept { return mul(m.value); }
    inline Modulo div(Modulo m) const noexcept { return div(m.value); }

    inline Modulo pow(int64_t p) const noexcept {
        int64_t ret = 1;
        int64_t v = value;
        for (; p > 0; p >>= 1) {
            if (p & 1) (ret *= v) %= MOD;
            (v *= v) %= MOD;
        }
        return Modulo(ret, MOD);
    }
}; // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
