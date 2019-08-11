#include "bits/stdc++.h"
// Custom Header {{{
#define all(x)      x.begin(), x.end()
#define rep(i,n)    for (i64 i = 0; i < (n); ++i)
#define reps(i,s,t) for (i64 i = (s); i <= (t); ++i)
#define repr(i,s,t) for (i64 i = (n); i >= (t); --i)
#define LF          '\n'

#ifdef DBG
#define err(...)    fprintf(stderr, __VA_ARGS__)
#define dump(x)     clog << std::setw(6) << (#x) << ": " << (x) << endl
#else
#define err(...)
#define dump(x)
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
// }}}

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(nullptr);

    return 0;
}

