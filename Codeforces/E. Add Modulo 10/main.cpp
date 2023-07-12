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

int n;
vector<ull> a;

bool doit50() {
  ull aa = a.back();
  a.pop_back();

  if (aa % 10 != 0)
    aa += aa % 10;

  for (int i : a) {
    if (i % 10 != 0)
      i += i % 10;
    if (i != aa)
      return false;
  }

  return true;
}

bool doit() {
  ull i = a.back();
  a.pop_back();

  if (i % 5 == 0)
    return false;

  while (i % 10 != 6)
    i += i % 10;

  bool is = (i / 10) & 1;

  for (ull i : a) {
    if (i % 5 == 0)
      return false;
    while (i % 10 != 6)
      i += i % 10;

    bool isis = (i / 10) & 1;

    if (is != isis)
      return false;
  }

  return true;
}

void solve() {
  cin >> n;
  a = vector<ull>(n);

  for (auto &i : a)
    cin >> i;

  if (a[0] % 5 == 0) {
    if (doit50())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } else {
    if (doit())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
