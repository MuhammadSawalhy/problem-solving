// ----------------------------------------------------------------------------
// Problem : F. Vanya and Label
// Author  : Muahmmad Assawalhy
// Date    : 04-09-22
// ----------------------------------------------------------------------------

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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

int chartoint(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'A' && c <= 'Z')
    return 10 + c - 'A';
  if (c >= 'a' && c <= 'z')
    return 36 + c - 'a';
  if (c == '-')
    return 62;
  return 63;
}

ull count(char c) {
  int n = chartoint(c);
  ull cnt = 0;
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      if ((i & j) == n)
        cnt++;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;

  ull ans = 1;
  for (int i = 0; i < sz(s); i++) {
    ans *= count(s[i]);
    ans %= int(1e9 + 7);
  }

  cout << ans << endl;
  return 0;
}
