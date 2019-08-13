#include "bits/stdc++.h"
#include "commonHeader.hpp"

//@@@@@@@@@@
//@ snippet ruisekiwa
//@ alias   partSum
//@ options head
class Ruisekiwa : public vector<i64> { // {{{
    using super = vector<i64>;
    using super::super; // コンストラクタを継承

public:
    inline void build() {
        const auto sz = super::size();
        for (int i = 1; i < sz; ++i) (*this)[i] += (*this)[i-1];
    }

    inline i64 sum(int r) const {
        return (r < 0) ? 0 : (*this)[r];
    }

    inline i64 sum(int l, int r) const {
        return sum(r) - sum(l - 1);
    }

    inline int lower_bound(i64 key) const {
        return std::lower_bound(super::begin(), super::end(), key) - super::begin();
    }
};
// }}}
//@@@@@@@@

//@@@@@@@@@@
//@ snippet ruisekiwa2d
//@ options head
class Ruisekiwa2D { // {{{
    vector<vector<i64>> s;
public:
    Ruisekiwa2D() {}
    Ruisekiwa2D(int h, int w) : s(h+1, vector<i64>(w+1, 0)) {}

    inline void build() {
        const int h = s.size();
        const int w = s[0].size();
        for (int j = 1; j < w; ++j) {
            s[0][j] += s[0][j-1];
        }
        for (int i = 1; i < h; ++i) {
            s[i][0] += s[i-1][0];
            for (int j = 1; j < w; ++j) {
                s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            }
        }
        return;
    }

    inline i64 at(int y, int x) const {
        return (y < 0) || (x < 0) ? 0 : s[y][x];
    }

    inline i64 sum(int sy, int sx, int gy, int gx) const {
        return s[gy][gx] - at(sy-1, gx) - at(gy, sx-1) + at(sy-1, sx-1);
    }

    inline void resize(int h, int w) { s.assign(h+1, vector<i64>(w+1, 0)); }
    inline const vector<i64>& operator[] (size_t i) const { return s[i]; }
    inline vector<i64>&       operator[] (size_t i)       { return s[i]; }
}; // }}}
//@@@@@@@@@@@


/*
 * Verified On : 2019-07-22
 * https://atcoder.jp/contests/abc005/tasks/abc005_4
 */
// Ruisekiwa2D - Verify {{{
void ABC005_D()
{
    using i64 = long long;

    int N; cin >> N;

    Ruisekiwa2D mat(N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }

    mat.build();

    vector<i64> ans(N*N + 10, 0);
    reps(h, 1, N) reps(w, 1, N) {
        for (int i = 0; i+h <= N; ++i) {
            for (int j = 0; j+w <= N; ++j) {
                chmax(ans[h*w], mat.sum(i,j, i+h-1, j+w-1));
            }
        }
    }
    for (int i = 1; i < ans.size(); ++i) {
        chmax(ans[i], ans[i-1]);
    }

    int Q; cin >> Q;
    while (Q--) {
        int p; cin >> p;
        cout << ans[p] << "\n";
    }
}
// }}}

void test_Ruisekiwa2D() // {{{
{
    Ruisekiwa2D mat(2, 2);
    mat[0][0] = 2;  mat[0][1] = 1;
    mat[1][0] = 3;  mat[1][1] = 5;

    mat.build();

    assert(mat[0][0] == 2); assert(mat[0][1] == 3);
    assert(mat[1][0] == 5); assert(mat[1][1] == 11);

    assert(mat.sum(0,0, 0,0) == 2);
    assert(mat.sum(0,0, 1,0) == 5);
    assert(mat.sum(0,0, 0,1) == 3);
    assert(mat.sum(0,0, 1,1) == 11);

    assert(mat.sum(0,1, 0,1) == 1);
    assert(mat.sum(0,1, 1,1) == 6);

    assert(mat.sum(1,0, 1,0) == 3);
    assert(mat.sum(1,0, 1,1) == 8);

    assert(mat.sum(1,1, 1,1) == 5);
} // }}}

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    Ruisekiwa rui {{ 3, 1, 4, 1, 5 }};
    trace(/* before */ rui);

    rui.build();
    trace(/* after */ rui);

    return 0;
}
