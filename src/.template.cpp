#include "bits/stdc++.h"
// Begin Header {{{
#define let             const auto
#define all(x)          (x).begin(), (x).end()
#define SIZE(x)         static_cast<i64>(x.size())
#define rep(i, n)       for (i64 i = 0, i##_limit = (n); i < i##_limit; ++i)
#define reps(i, s, t)   for (i64 i = (s), i##_limit = (t); i <= i##_limit; ++i)
#define repr(i, s, t)   for (i64 i = (s), i##_limit = (t); i >= i##_limit; --i)
#define VAR(Type, ...)  Type __VA_ARGS__; input(__VA_ARGS__)
#define VEC(Type, varName, sz)   vector<Type> varName((sz) + 1)
#define lowerBound(...)              _lowerBound(__VA_ARGS__)
#define upperBound(...)              _upperBound(__VA_ARGS__)
#define _lowerBound(begin, end, ...) (lower_bound((begin), (end), __VA_ARGS__) - (begin))
#define _upperBound(begin, end, ...) (upper_bound((begin), (end), __VA_ARGS__) - (begin))

#ifdef DBG
#define trace(...) _internal::_trace(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif

using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<class T, class U>inline bool chmax(T &a, const U &b){return b>a && (a=b, true);}
template<class T, class U>inline bool chmin(T &a, const U &b){return b<a && (a=b, true);}
inline i64  sigma(i64 n)                    { return n * (n + 1) >> 1; }
inline i64  divup(i64 a, i64 b)             { return (a + b - 1) / b; }
inline bool inner(i64 a, i64 low, i64 high) { return (low <= a && a < high); }
inline string to_string(char c)             { return string(1,c); }
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

// Input, Output {{{
namespace _internal { // {{{
    template<size_t> struct _Uint{};
    template<class Tuple>
        ostream& _print_tuple(ostream &out, const Tuple &t, _Uint<1>) {
            return out << std::get< std::tuple_size<Tuple>::value - 1 >(t);
        }
    template<class Tuple, size_t Index>
        ostream& _print_tuple(ostream &out, const Tuple &t, _Uint<Index>) {
            out << std::get< std::tuple_size<Tuple>::value - Index >(t) << ' ';
            return _print_tuple(out, t, _Uint<Index-1>());
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
} // }}}

template<class T>
inline void input(T &x) { cin >> x; }

template<class Head, class... Tail>
inline void input(Head &head, Tail&... tail) { cin >> head; input(tail...); }

template<class... Args>
inline void outl(Args&&... args) { cout << make_tuple(std::forward<Args>(args)...) << "\n"; }

template<class T>
ostream& operator<< (ostream &out, const vector<T> &vec) {
    static const char *delim[] = { " ", "" };
    rep(i, vec.size()) out << vec[i] << delim[i+1 == vec.size()];
    return out;
}

template<class T, class U>
ostream& operator<< (ostream &out, const pair<T, U> &p) {
    return out << p.first << ' ' << p.second;
}

template<class... Types>
ostream& operator<< (ostream &out, const tuple<Types...> &t) {
    return _internal::_print_tuple(out, t, _internal::_Uint<sizeof...(Types)>());
}

template<class Itr>
ostream& print(Itr begin, Itr end, ostream &out = cout, const string &separator = " ") {
    const auto rbegin = std::prev(end);
    for (; begin != rbegin; ++begin) out << *begin << separator;
    out << *rbegin;
    return out;
} // }}}

// }}} End Header

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    return 0;
}
