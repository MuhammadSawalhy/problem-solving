#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

char invertcase(char c) {
  if (c >= 'a' && c <= 'z')
    return c & '_';
  return c | ' ';
}

void solve() {
  string s, t;
  cin >> s >> t;

  map<char, int> ss, tt;
  set<char> sset;

  for (char c : s) {
    ss[c]++;
    sset.insert(c);
  }

  for (char c : t)
    tt[c]++;

  int a = 0, b = 0;
  for (char c : sset) {
    int v = min(tt[c], ss[c]);
    a += v;
    ss[c] -= v;
    tt[c] -= v;
  }

  for (char c : sset) {
    b += min(ss[c], tt[invertcase(c)]);
  }

  cout << a << " " << b << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
