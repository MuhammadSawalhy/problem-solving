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
int a[2000];

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int x = 0, y;
  for (int i = 0; i < n - 1; i++) {
    x ^= a[i];
    y = 0;
    int j = i + 1;

    while (j <= n) {
      if (j == n) {
        if (x == y) {
          cout << "YES" << endl;
          return;
        }
        break;
      }

      if (y == x) {
        y = 0;
      }

      y ^= a[j];
      j++;
    }
  }

  x = 0;
  for (int i = n - 1; i > 0; i--) {
    x ^= a[i];
    y = 0;
    int j = i - 1;

    while (j >= -1) {
      if (j == -1) {
        if (x == y) {
          cout << "YES" << endl;
          return;
        }
        break;
      }

      if (y == x) {
        y = 0;
      }

      y ^= a[j];
      j--;
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  map<int, double> m;
  for (int i = 0; i < 2e8; i++)
    m[1] = cos(acos(0));
  while (t_cases--)
    solve();
  return 0;
}
