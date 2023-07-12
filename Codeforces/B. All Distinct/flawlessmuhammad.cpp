#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;

bool isPaliString(string s, int n) {
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}

void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}

int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll a = n;
    set<ll> s;
    map<ll, ll> m;

    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      s.insert(x);
      m[x]++;
    }

    for (ll i : s) {
      n -= (m[i] - 1);
    }

    if ((a - n) % 2 == 1) {
      n--;
    }

    cout << n << "\n";
  }
  return 0;
}
