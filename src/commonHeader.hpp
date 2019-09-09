#ifndef INCLUDED_COMMON_HEADER_HPP
#define INCLUDED_COMMON_HEADER_HPP

#include "bits/stdc++.h"
// Begin Header {{{
#define all(x)          (x).begin(), (x).end()
#define rep(i, n)       for (i64 i = 0, i##_limit = (n); i < i##_limit; ++i)
#define reps(i, s, t)   for (i64 i = (s), i##_limit = (t); i <= i##_limit; ++i)
#define repr(i, s, t)   for (i64 i = (s), i##_limit = (t); i >= i##_limit; --i)
#define var(Type, ...)  Type __VA_ARGS__; input(__VA_ARGS__)
#ifndef DBG
#define trace(...)
#endif
using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template <class T, class U> inline bool chmax(T &a, const U &b) { return b > a && (a = b, true); }
template <class T, class U> inline bool chmin(T &a, const U &b) { return b < a && (a = b, true); }
inline i64  sigma(i64 n)            { return (n * (n + 1) >> 1); }
inline i64  updiv(i64 a, i64 b)     { return (a + b - 1) / b; }
inline i64  sqr(i64 n)              { return n * n; }
inline string to_string(char c)     { return string(1, c); }
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
inline vector<T> make_v(const T &initValue, size_t sz) {
    return vector<T>(sz, initValue);
}
template <class T, class... Args>
inline auto make_v(const T &initValue, size_t sz, Args... args) {
    return vector<decltype(make_v<T>(initValue, args...))>(sz, make_v<T>(initValue, args...));
}

inline void input() {}
template <class Head, class... Tail>
inline void input(Head &head, Tail&... tail) { cin >> head; input(tail...); }

inline void print() { cout << "\n"; }
template <class Head, class... Tail>
inline void print(Head &&head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
inline ostream& operator<< (ostream &out, const vector<T> &vec) {
    static constexpr const char *delim[] = { " ", "" };
    for (const auto &e : vec) out << e << delim[&e == &vec.back()];
    return out;
}
// }}} End Header

#endif /* End of include-guard */

