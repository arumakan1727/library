#include "bits/stdc++.h"
#include "commonHeader.hpp"

#ifndef INCLUDED_YDK_SEGMENT_TREE_CPP
#define INCLUDED_YDK_SEGMENT_TREE_CPP

//@@@@@@@@@@@
//@ snippet SegmentTree
//@ options head
template<class Monoid> struct SegmentTree { // {{{
    using Func = function<Monoid(Monoid, Monoid)>;
    const int sz;
    const Func merge;
    const Monoid unity;
    vector<Monoid> dat;

    SegmentTree(int n, const Monoid &u, Func f)
        : sz(1 << (__lg(n+5) + 1)), merge(f), unity(u), dat(sz*2, unity) {}

    void set(int k, const Monoid &v) { dat[k + sz] = v; }

    Monoid& operator[] (int k) { return dat[k + sz]; }
    const Monoid& operator[] (int k) const { return dat[k + sz]; }

    void build() { for (int k = sz-1; k > 0; --k) dat[k] = merge(dat[2*k], dat[2*k+1]); }

    void update(int k, const Monoid &v) {
        dat[ k += sz ] = v;
        while(k >>= 1) dat[k] = merge(dat[2*k], dat[2*k+1]);
    }

    Monoid query(int a, int b) const {
        Monoid L = unity,  R = unity;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = merge(L, dat[a++]);
            if (b & 1) R = merge(dat[--b], R);
        }
        return merge(L, R);
    }
}; // }}}
//@@@@@@@@@

#endif /* End of include-guard */
