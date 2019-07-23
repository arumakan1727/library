#include "bits/stdc++.h"
using namespace std;
using i64 = long long;
using pii = pair<i64,i64>;

//@@@@@@
//@ snippet digits
//@ options head
inline vector<int> digits(unsigned long long n) { // {{{
    vector<int> ret;
    do { ret.push_back(n % 10); n /= 10; } while(n > 0);
    reverse(ret.begin(), ret.end());
    return ret;
} // }}}
//@@@@


//@@@@@@
//@ snippet compress
//@ alias   unique
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
//@ snippet countTable
//@ options head
// countTable {{{
template<class Container, class InputIt>
Container countTable(InputIt first, InputIt last)
{
    Container cnt;
    for (; first != last; ++first) { ++cnt[*first]; }
    return cnt;
} // }}}
//@@@@@

//@@@@@@@@@@
//@ snippet divup
//@ options head
const auto divup = [](i64 a, i64 b) { return (a + b - 1) / b; };
//@@@@@@@@@@

//@@@@@@@@@@
//@ snippet bSearch
//@ alias   binSearch binarySearch
//@ options head
// binarySearch {{{
template<class T>
pii bSearch(T key, const pii &range, function<bool(i64, T)> isOK)
{
    i64 ng = range.first;
    i64 ok = range.second;

    while(abs(ok - ng) > 1) {
        const i64 mid = (ng + ok) / 2;
        (isOK(mid, key) ? ok : ng) = mid;
    }

    return {ng, ok};
}
// }}}
//@@@@@@@@@@

//@@@@@@@@@@
//@ snippet syakutori
//@ alias   shakutori
//@ options head
// syakutori {{{
    template<class Array>
i64 syakutori(const Array &a, int N)
{
    i64 ans = 0;
    int left, right = 0;

    const auto isOK = [&](int i) { return i; };
    const auto proc = [&](int i) { i; };

    for (left = 0; left < N; ++left) {
        while(right < N && isOK(right)) {
            proc(right);
            ++right;
        }

        /* TODO update ans */

        if (right == left) {
            ++right;
        } else {
            // sum -= a[left];
        }
    }

    return ans;
}
// }}}
//@@@@@@@@@@

//@@@@@@@@@@
//@ snippet split
//@ options head
vector<string> split(const string &str, const string &delim) // {{{
{
    vector<string> ret;
    string buf;

    for (char c : str) {
        if (any_of(delim.begin(), delim.end(), [c](char x) { return c == x; })) {
            if (!buf.empty()) { ret.push_back(buf); buf.clear(); }
        } else {
            buf += c;
        }
    }

    return ret;
} // }}}
//@@@@@@@@@@


signed main() // {{{
{
    for (const string &e : split("  3 + 342 ::  0x3f  ", " ")) {
        cout << e << endl;
    }

}
// }}}
