#include "bits/stdc++.h"
#include "./commonHeader.hpp"

#ifndef INCLUDED_YDK_ZIP_CPP
#define INCLUDED_YDK_ZIP_CPP

//@@@@@@@@@@
//@ snippet zip
//@ alias   compress
//@ options head
template<class T>
class Zip {
    unordered_map<T, int> zipIndex;

public:
    vector<T> data;

    explicit Zip() {}

    template<class InputItr>
    explicit Zip(InputItr begin, InputItr end) : data(begin, end)
    { }

    template<class... Args>
    void emplace(Args&&... args) { data.emplace_back(std::forward<Args>(args)...); }

    template<class InputItr>
    void assign(InputItr begin, InputItr end) { data.assign(begin, end); zipIndex.clear(); }

    void reserve(size_t sz) { data.reserve(sz); }

    void compress() {
        sort(all(data));
        data.erase(unique(all(data)), data.end());
        for (int i = 0; i < data.size(); ++i) {
            zipIndex[data[i]] = i;
        }
    }

    auto begin() { return data.begin(); }
    auto end()   { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end()   const { return data.end(); }

    int size() const { return data.size(); }

    const T& operator[] (int i) const { return data[i]; }
    T& operator[] (int i ) { return data[i]; }

    int operator() (const T &value) const { return zipIndex.at(value); }
};
//@@@@@@@@@@

#endif /* End of include-guard */
