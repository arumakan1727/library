#include "bits/stdc++.h"
#include "commonHeader.hpp"

#ifndef INCLUDED_YDK_MOD_INT_CPP
#define INCLUDED_YDK_MOD_INT_CPP

//@@@@@@@
//@ snippet modint
//@ options head
// ModInt {{{
template<i64 MOD>
class ModInt {
private:
    i64 n;
public:
    inline ModInt(i64 n = 0) : n((n >= MOD) ? (n % MOD) : (n < 0) ? ((n + MOD) % MOD) : n) {}
    inline ModInt  operator~() const    { return pow(n, MOD-2); }
    inline ModInt& operator+=(ModInt o) { n = (n + o.n) % MOD; return *this; }
    inline ModInt& operator-=(ModInt o) { n = (MOD + n - o.n) % MOD; return *this; }
    inline ModInt& operator*=(ModInt o) { n = (n * o.n) % MOD; return *this; }
    inline ModInt& operator/=(ModInt o) { n = (n * (~o).n) % MOD; return *this; }
    inline bool operator==(ModInt o) const { return n == o.n; }
    inline bool operator!=(ModInt o) const { return !(*this == o); }
    template<class Int> explicit inline operator Int() const { return static_cast<Int>(n); }
    friend ostream& operator<<(ostream &os, ModInt o) { os << o.n; return os; }
    friend istream& operator>>(istream &is, ModInt &o) { is >> o.n; return is; }
    static constexpr inline ModInt pow(i64 n, i64 p) {
        i64 ret = 1;
        for(; p > 0; p >>= 1) {
            if (p & 1) ret = (ret * n) % MOD;
            n = (n * n) % MOD;
        }
        return ret;
    }
};
template<i64 MOD> auto operator+(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) += b; }
template<i64 MOD> auto operator-(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) -= b; }
template<i64 MOD> auto operator*(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) *= b; }
template<i64 MOD> auto operator/(ModInt<MOD> a, ModInt<MOD> b) { return ModInt<MOD>(a) /= b; }
// }}}
using modint = ModInt<int(1e9) + 7>;
//@@@@@@


//@@@@@@@@@@
//@ snippet modulo
//@ options head
struct Modulo { // {{{
    const i64 MOD;
    const i64 value;

    explicit Modulo(i64 val, i64 mod) :
        MOD(mod),
        value((val >= MOD) ? (val % MOD) : (val < 0) ? ((val + MOD) % MOD) : val) { }

    inline Modulo add(i64 x) const noexcept { return Modulo(value + x, MOD); }
    inline Modulo sub(i64 x) const noexcept { return Modulo(value - x, MOD); }
    inline Modulo mul(i64 x) const noexcept { return Modulo(value * x, MOD); }
    inline Modulo div(i64 x) const noexcept { return Modulo(x, MOD).pow(MOD-2).mul(value); }

    inline Modulo add(Modulo m) const noexcept { return add(m.value); }
    inline Modulo sub(Modulo m) const noexcept { return sub(m.value); }
    inline Modulo mul(Modulo m) const noexcept { return mul(m.value); }
    inline Modulo div(Modulo m) const noexcept { return div(m.value); }

    inline Modulo pow(i64 p) const noexcept {
        i64 ret = 1;
        i64 v = value;
        for (; p > 0; p >>= 1) {
            if (p & 1) (ret *= v) %= MOD;
            (v *= v) %= MOD;
        }
        return Modulo(ret, MOD);
    }
}; // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
