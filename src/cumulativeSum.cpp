#include "bits/stdc++.h"
#include "commonHeader.hpp"

//@@@@@@@@@@
//@ snippet CumulativeSum
//@ options head
class CumulativeSum { // {{{{
    vector<i64> cum;

public:
    CumulativeSum() : cum(1) {}

    CumulativeSum(int sz) : cum(sz + 1) {}

    template<class T>
        CumulativeSum(initializer_list<T> il) { assign(il.begin(), il.end()); }

    template<class Iterator>
        CumulativeSum(Iterator begin, Iterator end) { assign(begin, end); }

    template<class Iterator>
        inline void assign(Iterator begin, Iterator end) {
            cum.assign(distance(begin, end) + 1, 0);
            std::copy(begin, end, cum.begin() + 1);
        }

    inline void build() {
        for (int i = 1; i < cum.size(); ++i) {
            cum[i] += cum[i-1];
        }
    }

    // "半開区間" [0, r) までの総和
    inline i64 sum(int r) const {
        return cum[r];
    }

    // "半開区間" [l, r) までの総和
    inline i64 sum(int l, int r) const {
        return sum(r) - sum(l);
    }

    ///////////////////////////////////////////////////////////////////////////
    // vector like methods
    inline void resize(int sz) {
        cum.resize(sz + 1);
    }
    template<class... Args>
        inline void emplace_back(Args&&... args) {
            cum.emplace_back(args...);
        }
    inline i64 size() const noexcept {
        return static_cast<i64>(cum.size()) - 1;
    }
    inline const auto& data() const noexcept {
        return cum;
    }
    inline auto begin() const noexcept {
        return cum.begin() + 1;
    }
    inline auto end() const noexcept {
        return cum.end();
    }
    inline i64 operator[](int i) const {
        return cum[i + 1];
    }
    inline i64& operator[](int i) {
        return cum[i + 1];
    }
};
// }}}
//@@@@@@@@

//@@@@@@@@@@
//@ snippet CumulativeSum2D
//@ options head
class CumulativeSum2D { // {{{
    vector<vector<i64>> cum;
public:
    CumulativeSum2D() {}
    CumulativeSum2D(int h, int w) : cum(h+1, vector<i64>(w+1, 0)) {}

    inline void build() {
        const auto h = cum.size(),  w = cum[0].size();
        for (int y = 1; y < h; ++y) {
            for (int x = 1; x < w; ++x) {
                cum[y][x] += cum[y][x - 1] + cum[y - 1][x] - cum[y - 1][x - 1];
            }
        }
    }

    // Usage: sum({sy, sx}, {gy, gx})
    inline i64 sum(pair<int, int> s, pair<int, int> t) const {
        return sum(s.first, s.second, (t.first - s.first), (t.second - s.second));
    }

    inline i64 sum(int sy, int sx, int h, int w) const {
        return cum[sy + h][sx + w] - cum[sy][sx + w] - cum[sy + h][sx] + cum[sy][sx];
    }

    inline i64 operator() (int y, int x) const {
        return cum[y + 1][x + 1];
    }

    inline i64& operator() (int y, int x) {
        return cum[y + 1][x + 1];
    }

    inline void resize(int h, int w) {
        cum.assign(h+1, vector<i64>(w+1, 0));
    }

    inline i64 height() const noexcept {
        return cum.size() - 1;
    }

    inline i64 width() const noexcept {
        return cum[0].size() - 1;
    }

    friend ostream& operator<< (ostream &out, const CumulativeSum2D &mat) {
        const auto h = mat.cum.size();
        const auto w = mat.cum[0].size();
        for (int i = 1; i < h; ++i) {
            for (int j = 1; j < w; ++j) {
                out << mat.cum[i][j] << " \n"[j + 1 == w && i + 1 < h];
            }
        }
        return out;
    }

}; // }}}
//@@@@@@@@@@@

void test_CumulativeSum1D() // {{{
{
    vector<i64> src {{ 3, 2, 0, 4 }};
    CumulativeSum cum(src.begin(), src.end());

    cum.build();

    print(src);
    print(cum.data());

    assert(cum.size() == 4);
    assert(cum[0] == 3);
    assert(cum[1] == 5);
    assert(cum[2] == 5);
    assert(cum[3] == 9);
    assert(cum.sum(0) == 0);
    assert(cum.sum(1) == 3);
    assert(cum.sum(2) == 5);
    assert(cum.sum(3) == 5);
    assert(cum.sum(4) == 9);
    assert(cum.sum(0, 1) == 3);
    assert(cum.sum(0, 4) == 9);
    assert(cum.sum(2, 3) == 0);


    cum.resize(0);
    assert(cum.size() == 0);
    assert(cum.data().size() == 1);


    cum.emplace_back(0);
    cum.emplace_back(10);
    cum.build();
    assert(cum.size() == 2);
    assert(cum.sum(0) == 0);
    assert(cum.sum(1) == 0);
    assert(cum.sum(2) == 10);


    cum = CumulativeSum(2);
    assert(cum.size() == 2);
    assert(cum.sum(0) == 0);
    assert(cum.sum(1) == 0);
    assert(cum.sum(2) == 0);

    print(__func__, ": AC");
} // }}}

void test_CumulativeSum2D() // {{{
{
    CumulativeSum2D mat(2, 2);
    mat(0, 0) = 2;  mat(0, 1) = 1;
    mat(1, 0) = 3;  mat(1, 1) = 5;
    assert(mat.height() == 2);
    assert(mat.width() == 2);

    print("--------");
    print(mat); // before

    mat.build();

    print("--------");
    print(mat); // after

    assert(mat(0, 0) == 2); assert(mat(0, 1) == 3);
    assert(mat(1, 0) == 5); assert(mat(1, 1) == 11);

    assert(mat.sum(0,0, 1,1) == 2);
    assert(mat.sum(0,0, 2,1) == 5);
    assert(mat.sum(0,0, 1,2) == 3);
    assert(mat.sum(0,0, 2,2) == 11);

    assert(mat.sum(0,1, 1,1) == 1);
    assert(mat.sum(0,1, 2,1) == 6);

    assert(mat.sum(1,0, 1,1) == 3);
    assert(mat.sum(1,0, 1,2) == 8);

    assert(mat.sum(1,1, 1,1) == 5);

    // ------------------------------------------------------------
    mat.resize(2, 3);
    assert(mat.height() == 2);
    assert(mat.width() == 3);

    mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3;
    mat(1, 0) = 4; mat(1, 1) = 5; mat(1, 2) = 6;

    mat.build();


    print("---------------");
    print(mat);
    cout.flush();

    assert(mat.sum({0, 0}, {1, 1}) == 1);
    assert(mat.sum({0, 1}, {1, 2}) == 2);
    assert(mat.sum({1, 2}, {2, 3}) == 6);

    assert(mat.sum({0, 0}, {2, 3}) == 21);
    assert(mat.sum({0, 0}, {1, 3}) == 6);
    assert(mat.sum({1, 0}, {2, 3}) == 15);
    assert(mat.sum({0, 0}, {2, 2}) == 12);

    print(__func__, ": AC");
} // }}}


signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    test_CumulativeSum1D();

    test_CumulativeSum2D();

    return 0;
}
