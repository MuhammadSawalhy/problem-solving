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

void solve(int n) {
  if (n < 0) return;
  int s = sqrt(n);
  if (s * s < n) s++;
  s = s * s - n;
  solve(s - 1);
  for (int i = n; i >= s; i--)
    cout << i << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;
    solve(n - 1);
    cout << endl;
  }
  return 0;
}
