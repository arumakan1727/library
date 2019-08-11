#include "bits/stdc++.h"
// Custom Header {{{
#define all(x) x.begin(), x.end()
#define rep(i,n)    for (i64 i = 0; i < (n); ++i)
#define reps(i,s,t) for (i64 i = (s); i <= (t); ++i)
#define repr(i,s,t) for (i64 i = (n); i >= (t); --i)
using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

//@@@@@@@@@@
//@ snippet zip
//@ alias   compress
//@ options head
template<class T>
class Zip {
    vector<T> data;
    unordered_map<T, size_t> zipIndex;

public:
    explicit Zip() {}

    template<class InputItr>
    explicit Zip(InputItr begin, InputItr end) : data(begin, end)
    { }

    template<class... Args>
    void emplace(Args&&... args) { data.emplace_back(std::forward<Args>(args)...); }

    template<class InputItr>
    void assign(InputItr begin, InputItr end) { data.assign(begin, end); zipIndex.clear(); }

    void build() {
        sort(begin(data), end(data));
        data.erase(unique(begin(data), end(data)), end(data));
        for (int i = 0; i < data.size(); ++i) {
            zipIndex[data[i]] = i;
        }
    }

    auto begin() { return data.begin(); }
    auto end()   { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end()   const { return data.end(); }

    const T& operator[] (size_t i)      const { return data[i]; }

    size_t operator() (const T &value)  const { return zipIndex.at(value); }
};
//@@@@@@@@@@
