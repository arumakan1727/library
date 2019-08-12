#define PROBLEM https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0264?year=2012
// Verified On: 2019-08-12

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/exprParser.cpp"
#include "../src/modint.cpp"

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int mod;
    char expr[100100];

    while (scanf(" %d: ", &mod), mod != 0) {
        fgets(expr, sizeof(expr), stdin);
        const vector<string> infixNotation = exprTokens(expr);
        const vector<string> rpn = convertToReversePolishNotation(infixNotation);

        stack<i64> S;

        for (const auto &token : rpn) {
            if (isdigit(token[0])) {
                S.push(stoi(token));
            } else {
                const i64 b = S.top(); S.pop();
                const i64 a = S.top(); S.pop();

                switch (token[0]) {
                case '+': S.push(Modulo(a, mod).add(b).value); break;
                case '-': S.push(Modulo(a, mod).sub(b).value); break;
                case '*': S.push(Modulo(a, mod).mul(b).value); break;
                case '/':
                          if (b == 0) { puts("NG"); goto NEXT_INPUT; }
                          S.push(Modulo(a, mod).div(b).value); break;
                }
            }
        }

        for (const auto &token : infixNotation) printf("%s", token.c_str());
        printf(" = %ld (mod %d)\n", S.top(), mod);

NEXT_INPUT:;
    }

    return 0;
}
