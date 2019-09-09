#ifndef INCLUDED_YDK_STDCPP_H
#define INCLUDED_YDK_STDCPP_H

// C langueage
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

// C++ lang support
#include <limits>
#include <typeinfo>
#include <initializer_list>

// C++ utilities
#include <bitset>
#include <chrono>
#include <functional>
#include <tuple>
#include <typeindex>
#include <utility>

// C++ string
#include <string>
#include <regex>

// C++ container
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// C++ Others
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>


#ifndef DBG
#define DBG
#endif

template <class T, class U>
inline std::ostream& operator<< (std::ostream &out, const std::pair<T, U> &p) {
    return out << '(' << p.first << ' ' << p.second << ')';
}

template <class T>
inline std::ostream& operator<< (std::ostream &out, const std::vector<std::vector<T>> &mat) {
    static constexpr const char *tail[] = { "\n", "" };
    for (int i = 0; i < mat.size(); ++i) {
        const auto &row = mat[i];
        out << "[" << std::setw(2) << i << "] " << std::setw(2) << row << tail[&row == &mat.back()];
    }
    return out;
}

template <class T>
void trace_(const char *s, T&& x) {
    std::clog << '{';
    while(*s != '\0') std::clog << *(s++);
    std::clog << ":" << std::setw(3) << x << '}' << std::endl;
}

template <class Head, class... Tail>
void trace_(const char *s, Head&& head, Tail&&... tail) {
    std::clog << '{';
    while(*s != ',') std::clog << *(s++);
    std::clog << ":" << std::setw(3) << head << "}, ";
    for (++s; !isgraph(*s); ++s);
    trace_(s, std::forward<Tail>(tail)...);
}

#define trace(...)      trace_(#__VA_ARGS__, __VA_ARGS__)

#endif /* end of include-guard */
