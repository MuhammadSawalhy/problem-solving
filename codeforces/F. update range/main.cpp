//============================================================================
// Problem     : F. update range
// Author      : Muahmmad Assawalhy
// Date        : 01-09-22
//============================================================================

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
#define rep(i, s, e) for (int i = s; i < e; i++)

const int N = 1e5 + 1;
int n, q;
ll a[N];

void solve() {
  int n, q, x, y, val;
  cin >> n >> q;
  vector<ull> v(n + 1), v2(n + 1);
  rep(i, 0, n) cin >> v[i];
  rep(i, 0, q) {
    cin >> x >> y >> val;
    v2[x - 1] += val;
    v2[y] -= val;
  }

  rep(i, 1, n + 1) v2[i] += v2[i - 1];
  rep(i, 0, n) cout << v[i] + v2[i] << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}

