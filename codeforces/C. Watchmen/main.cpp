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

void solve() {
  int n;

  map<ll, int> xfreq, yfreq;
  map<pair<ll, ll>, ull> freq;
  ull ans = 0;

  cin >> n;

  while (n--) {
    int x, y;
    cin >> x >> y;
    ans += xfreq[x];
    ans += yfreq[y];
    ans -= freq[{x, y}]; // they  have been added twice
    xfreq[x]++;
    yfreq[y]++;
    freq[{x, y}]++;
  }

  debug(xfreq);
  debug(yfreq);

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
