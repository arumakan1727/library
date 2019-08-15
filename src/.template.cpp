#include "bits/stdc++.h"
// Begin Header {{{
#define all(x)      x.begin(), x.end()
#define SIZE(x)     static_cast<i64>(x.size())
#define rep(i,n)    for (i64 i = 0, i ## _limit = (n); i < i ## _limit; ++i)
#define reps(i,s,t) for (i64 i = (s), i ## _limit = (t); i <= i ## _limit; ++i)
#define repr(i,s,t) for (i64 i = (s), i ## _limit = (t); i >= i ## _limit; --i)

#ifdef DBG
#define trace(...) _trace(#__VA_ARGS__, __VA_ARGS__);
#else
#define trace(...)
#endif

using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template<class T, class U>inline bool chmax(T &a, const U &b){return b>a && (a=b, true);}
template<class T, class U>inline bool chmin(T &a, const U &b){return b<a && (a=b, true);}
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

template<class Itr>
ostream& printContainer(Itr begin, Itr end, const string &separator = " ", ostream &os = cout) {
    const auto rbegin = std::prev(end);
    for (; begin != rbegin; ++begin) os << *begin << separator;
    os << *rbegin;
    return os;
}

ostream& operator<< (ostream &os, ostream&) {
    return os;
}

template <class T>
void _trace(const char *s, T&& x) {
    clog << '{';
    while(*s != '\0') clog << *(s++);
    clog << ":" << setw(3) << x << '}' << endl;
}

template <class Head, class... Tail>
void _trace(const char *s, Head&& head, Tail&&... tail) {
    clog << '{';
    while(*s != ',') clog << *(s++);
    clog << ":" << setw(3) << head << "}, ";
    for (++s; !isgraph(*s); ++s);
    _trace(s, std::forward<Tail>(tail)...);
}
// }}} End Header

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(nullptr);

    return 0;
}
