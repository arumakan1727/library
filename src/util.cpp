#include "bits/stdc++.h"
using namespace std;
using i64 = int_fast64_t;
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
#define UNIQUE(a) \
    do{ sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }while(0);
//@@@@


//@@@@@@@@@@
//@ snippet divup
//@ options head
const auto divup = [](i64 a, i64 b) { return (a + b - 1) / b; };
//@@@@@@@@@@


//@@@@@@@@@@
//@ snippet clamp
//@ options head
template <class T, class Low, class High>
common_type_t<T, Low, High> clamp(const T &x, const Low &low, const High &high) {
    return (x < low) ? low : (x > high) ? high : x;
}
//@@@@@@@@@@


//@@@@@@@@@@
//@ snippet sigma
//@ options head
const auto sigma = [](i64 n) { return n * (n + 1) / 2; };
//@@@@@@@@@


//@@@@@@@@@@
//@ snippet bSearch
//@ alias   binSearch binarySearch
//@ options head
// binarySearch {{{
i64 bSearch(const pii &range, function<bool(i64)> isOK)
{
    i64 ng = range.first;
    i64 ok = range.second;

    while(abs(ok - ng) > 1) {
        const i64 mid = (ng + ok) / 2;
        (isOK(mid) ? ok : ng) = mid;
    }

    return ok;
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
}
// }}}
