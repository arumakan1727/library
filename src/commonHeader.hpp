#ifndef INCLUDED_COMMON_HEADER_HPP
#define INCLUDED_COMMON_HEADER_HPP

#include "bits/stdc++.h"
// Begin Header {{{
#define let             const auto
#define all(x)          (x).begin(), (x).end()
#define rep(i, n)       for (i64 i = 0, i##_limit = (n); i < i##_limit; ++i)
#define reps(i, s, t)   for (i64 i = (s), i##_limit = (t); i <= i##_limit; ++i)
#define repr(i, s, t)   for (i64 i = (s), i##_limit = (t); i >= i##_limit; --i)
#define var(Type, ...)  Type __VA_ARGS__; input(__VA_ARGS__)

using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template<class T, class U>inline bool chmax(T &a, const U &b){return b>a && (a=b, true);}
template<class T, class U>inline bool chmin(T &a, const U &b){return b<a && (a=b, true);}
inline i64  sigma(i64 n)            { return (n * (n + 1) >> 1); }
inline i64  updiv(i64 a, i64 b)     { return (a + b - 1) / b; }
inline i64  sqr(i64 n)              { return n * n; }
inline string to_string(char c)     { return string(1, c); }
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
inline vector<T> makeVec(size_t sz) { return vector<T>(sz); }

template <class T, class... Args>
inline auto makeVec(size_t sz, Args... args) {
    return vector<decltype(makeVec<T>(args...))>(sz, makeVec<T>(args...));
}

template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) {
    for(auto &e:t) fill_v(e,v);
}

template <class T>
inline void input(T &x) { cin >> x; }

template <class T>
inline void input(vector<T> &vec) { for (auto &e : vec) cin >> e; }

template <class Head, class... Tail>
inline void input(Head &head, Tail&... tail) { cin >> head; input(tail...); }

inline void print() { cout << "\n"; }

template <class Head, class... Tail>
inline void print(Head &&head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T, class U>
inline ostream& operator<< (ostream &out, const pair<T, U> &p) {
    return out << p.first << ' ' << p.second;
}

template <class T>
inline ostream& operator<< (ostream &out, const vector<T> &vec) {
    static constexpr const char *delim[] = { " ", "" };
    for (const auto &e : vec) out << e << delim[&e == &vec.back()];
    return out;
}

template <class T>
inline ostream& operator<< (ostream &out, const vector<vector<T>> &mat) {
    static constexpr const char *tail[] = { "\n", "" };
    for (const auto &row : mat) out << row << tail[&row == &mat.back()];
    return out;
}

template <class T>
void trace_(const char *s, T&& x) {
    clog << '{';
    while(*s != '\0') clog << *(s++);
    clog << ":" << setw(3) << x << '}' << endl;
}

template <class Head, class... Tail>
void trace_(const char *s, Head&& head, Tail&&... tail) {
    clog << '{';
    while(*s != ',') clog << *(s++);
    clog << ":" << setw(3) << head << "}, ";
    for (++s; !isgraph(*s); ++s);
    trace_(s, std::forward<Tail>(tail)...);
}
// }}} End Header

#endif /* End of include-guard */

