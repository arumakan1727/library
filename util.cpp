#include "bits/stdc++.h"
using namespace std;

//@@@@@@
//@ snippet fastIO
//@ alias   fastio
//@ options head
struct FastIO {
    FastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); }
} fastIO_ydk ;
//@@@@


//@@@@@@
//@ snippet digits
//@ options head
inline vector<int> digits(unsigned long long n) {
    vector<int> ret;
    do { ret.push_back(n % 10); n /= 10; } while(n > 0);
    return ret;
}
//@@@@


//@@@@@@
//@ snippet compress
//@ options head
#define compress(a) \
    do{ sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }while(0);
//@@@@


//@@@@@@
//@ snippet posDict
//@ alias   posdict
//@ options head
template<class T>
inline map<T,int> posDict(vector<T> &dat) {
    map<T,int> dict;
    for (int i = 0; i < dat.size(); ++i) dict[dat[i]] = i;
    return dict;
}
//@@@@


//@@@@@@
//@ snippet ruisekiwa
//@ options head
using v64 = vector<long long>;

template<class Array>
v64 ruisekiwa(const Array src, int N)
{
    v64 s(N, src[0]);
    for (int i = 1; i < N; ++i) s[i] = s[i-1] + src[i];
    return s;
}

inline long long partSum(const v64 &s, int l, int r)
{
    if (l > r) swap(l, r);
    return s[r] - (l <= 0 ? 0 : s[l-1]);
}
//@@@@

