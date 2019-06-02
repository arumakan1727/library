#include "bits/stdc++.h"
using namespace std;

//@@@@@@
//@ snippet fastIO
//@ alias   fastio
//@ options head
struct FastIO {
  FastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); }
} fastIO_ydk ;
//@@@@


//@@@@@@
//@ snippet digits
//@ options head
vector<int> digits(unsigned long long n) {
  if (n == 0) return { 0 };
  vector<int> ret;
  while(n > 0) { ret.push_back(n % 10); n /= 10; }
  return ret;
}
//@@@@


//@@@@@@
//@ snippet compress
//@ options head
template<class T>
vector<T> compress(vector<T> &dat) {
  sort(dat.begin(), dat.end());
  dat.erase(unique(dat.begin(), dat.end()), dat.end());
  return dat;
}
//@@@@


//@@@@@@
//@ snippet posDict
//@ alias   posdict
//@ options head
template<class T>
map<T,int> posDict(vector<T> &dat) {
  map<T,int> dict;
  for (int i = 0; i < dat.size(); ++i) dict[dat[i]] = i;
  return dict;
}
//@@@@
