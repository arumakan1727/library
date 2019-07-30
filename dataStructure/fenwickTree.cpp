#include "bits/stdc++.h"
using namespace std;

//@@@@@
//@ snippet FenwickTree
//@ alias   BIT
//@ options head
template <class T> struct FenwickTree { // {{{
    vector<T> dat;
    const size_t SIZE_POW2;
    explicit FenwickTree(int size): dat(size+5, 0), SIZE_POW2(1 << (__lg(size+5)+1)) {}

    inline void add(int i, const T &v){
        for (++i; i < dat.size(); i += i & -i) dat[i]+=v;
    }
    inline T sum(int i) const {
        T s = 0;
        for (++i; i > 0; i -= i & -i) s += dat[i];
        return s;;
    }
    inline T sum(int s, int t) const {
        if (s > t) swap(s, t);
        return sum(t) - sum(s - 1);
    }
    inline int lower_bound(T v) const {
        if (v <= 0) return 0;
        int i = 0;
        for (int w = SIZE_POW2; w > 0; w >>= 1) {
            if (i + w < dat.size() && dat[i + w] < v) {
                v -= dat[i + w];
                i += w;
            }
        }
        return i;
    }
}; // }}}
//@@@@@


/*
 * Verified on : 2019-07-30
 * https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
 */
void AOJ_DSL_2_B() // {{{
{
    int N, Q;
    cin >> N >> Q;

    FenwickTree<int> ft(N);
    while(Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            ft.add(x, y);
        } else {
            cout << (ft.sum(x, y)) << '\n';
        }
    }
} // }}}

/*
 * Verified on : 2019-07-30
 * https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
 */
void ARC033_C() // {{{
{
    FenwickTree<int> ft(200'000);
    int Q;
    cin >> Q;

    while(Q--) {
        int com, x;
        cin >> com >> x;
        if (com == 1) {
            ft.add(x, 1);
        } else {
            int p = ft.lower_bound(x);
            cout << p << "\n";
            ft.add(p, -1);
        }
    }

    return;
} // }}}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    // AOJ_DSL_2_B();
    // ARC033_C();

    return 0;
}
