#ifndef INCLUDED_COMMON_HEADER_HPP
#define INCLUDED_COMMON_HEADER_HPP

#include "bits/stdc++.h"
// Begin Header {{{
#define all(x)      x.begin(), x.end()
#define rep(i,n)    for (i64 i = 0; i < (n); ++i)
#define reps(i,s,t) for (i64 i = (s); i <= (t); ++i)
#define repr(i,s,t) for (i64 i = (s); i >= (t); --i)

#ifdef DBG
#define trace(...) _trace(#__VA_ARGS__, __VA_ARGS__);
#else
#define trace(...)
#endif

using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template<class T, class U>inline bool chmax(T &a, const U &b){return b>a ? (a=b,1) : 0;}
template<class T, class U>inline bool chmin(T &a, const U &b){return b<a ? (a=b,1) : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

template<class T>
ostream& operator<< (ostream &os, const vector<T> &vec) {
    rep(i, vec.size()) os << vec[i] << (i+1 == vec.size() ? "" : " ");
    return os;
}

template<class T, class U>
ostream& operator<< (ostream &os, const pair<T, U> &p) {
    return os << p.first << ' ' << p.second;
}

template <class T>
void _trace(const char *s, T&& x)
{
    clog << '{';
    while(*s != '\0' && *s != ',') clog << *(s++);
    clog << ":" << setw(3) << x << '}' << endl;
}

template <class Head, class... Tail>
void _trace(const char *s, Head&& head, Tail&&... tail)
{
    clog << '{';
    while(*s != ',') clog << *(s++);
    clog << ":" << setw(3) << head << "}, ";
    for (++s; !isgraph(*s); ++s);
    _trace(s, std::forward<Tail>(tail)...);
}
// }}} End Header

#endif /* End of include-guard */
