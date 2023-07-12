// ----------------------------------------------------------------------------
// Problem : C. Digital Logarithm
// Author  : Muahmmad Assawalhy
// Date    : 08-09-22
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;

    map<int, int> afr, bfr;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      afr[a]++;
    }

    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      if (afr[b])
        afr[b]--;
      else
        bfr[b]++;
    }

    int ops = 0;
    vi a;
    vi b;

    for (auto p : afr) {
      while (p.second--) {
        a.push_back(p.first);
      }
    }

    for (auto p : bfr) {
      while (p.second--) {
        b.push_back(p.first);
      }
    }

    if (a.size() == 0) {
      cout << ops << endl;
      continue;
    }

    debug("---------");

    debug(a);
    debug(b);

    auto applyon_a = [&](bool one) {
      for (int i = 0; i < a.size(); i++) {
        if (a[i] > 9 || one && a[i] != 1) {
          a[i] = (int)log10(a[i]) + 1;
          ops++;
        }
        afr[a[i]]++;
      }
    };

    auto applyon_b = [&](bool one) {
      for (int i = 0; i < b.size(); i++) {
        if (b[i] > 9 || one && b[i] != 1) {
          b[i] = (int)log10(b[i]) + 1;
          ops++;
        }
        if (afr[b[i]])
          afr[b[i]]--;
        else
          bfr[b[i]]++;
      }
    };

    afr.clear();
    bfr.clear();

    applyon_a(0);
    applyon_b(0);

    a.clear();
    b.clear();

    for (auto p : afr) {
      while (p.second--) {
        a.push_back(p.first);
      }
    }

    for (auto p : bfr) {
      while (p.second--) {
        b.push_back(p.first);
      }
    }

    debug(a);
    debug(b);

    if (a.size() == 0) {
      cout << ops << endl;
      continue;
    }

    applyon_a(true);
    applyon_b(true);

    debug(a);
    debug(b);

    cout << ops << endl;
    continue;
  }
  return 0;
}
