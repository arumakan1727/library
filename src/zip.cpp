#include "bits/stdc++.h"
#include "./commonHeader.hpp"

#ifndef INCLUDED_YDK_ZIP_CPP
#define INCLUDED_YDK_ZIP_CPP

//@@@@@@@@@@
//@ snippet zip
//@ alias   compress
//@ options head
template<class T> class Zip : public vector<T> { // {{{
    using super = vector<T>;
    using super::super; // 基底クラスのコンストラクタを継承
    using super::begin;
    using super::end;

    unordered_map<T, int> zipIndex;

public:
    void compress() {
        std::sort(begin(), end());
        super::erase(unique(begin(), end()), end());

        const int sz = super::size();
        for (int i = 0; i < sz; ++i) {
            zipIndex[(*this)[i]] = i;
        }
    }

    inline int operator() (const T &value) const {
        return zipIndex.at(value);
    }
}; // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
