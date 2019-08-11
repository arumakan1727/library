#include "bits/stdc++.h"
// Custom Header {{{
#define ALL(x) x.begin(), x.end()
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

//@@@@@@@@@@
//@ snippet exprTokens
//@ alias   exprtoken tokensplit splitToken
//@ options head
vector<string> exprTokens(const string &expr) // {{{
{
    vector<string> ret;
    string buf;

    const auto store = [&ret](string &s) {
        if (!s.empty()) { ret.emplace_back(move(s)); s.clear(); }
    };

    for (char c : expr) {
        if (isspace(c)) store(buf);
        else if (isdigit(c)) buf += c;
        else store(buf), ret.emplace_back(string() + c);
    }
    store(buf);

    return ret;
} // }}}
//@@@@@@@@@



//@@@@@@@@@@
//@ snippet poland
//@ alias   rpn reversePolishNotation exprParse
//@ options head
vector<string> convertToReversePolishNotation(const vector<string> &infixNotation) // {{{
{
    static const auto rank = [](char c) {
        switch(c) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        default: return 0;
        }
    };

    vector<string> ret;
    stack<string> st;

    for (const auto &e : infixNotation) {
        const char c = e[0];
        if (isdigit(c)) {
            ret.emplace_back(e);
        }
        else if (c == '(') {
            st.emplace(e);
        }
        else if (c == ')') {
            while(st.top()[0] != '(') {
                ret.emplace_back(move(st.top()));
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && rank(c) <= rank(st.top()[0])) {
                ret.emplace_back(move(st.top()));
                st.pop();
            }
            st.emplace(e);
        }
    }

    while(!st.empty()) {
        ret.emplace_back(st.top()); st.pop();
    }

    return ret;
} // }}}
//@@@@@@@@@@


signed main() // {{{
{
    string s;

    while(getline(cin, s)) {
        const auto tokens = exprTokens(s);
        for (const auto &e: tokens) cout << e << ' ';
        cout << endl;
    }

    return 0;
} // }}}

// vim: set foldmethod=marker :
