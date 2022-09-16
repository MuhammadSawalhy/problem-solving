// ----------------------------------------------------------------------------
// Problem : C. Tourist Problem
// Author  : Muahmmad Assawalhy
// Date    : 15-09-22
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
  int n;
  cin >> n;
  vector<ull> a(n);
  ull sum = 0;
  for (auto &i : a)
    cin >> i, sum += i;
  sort(all(a));
  ull nom = sum;
  ull deno = n;

  for (int i = 0; i < n; i++) {
    nom += 2 * (sum - a[i] * (n - i));
    sum -= a[i];
  }

  ull g = gcd(nom, deno);
  nom /= g;
  deno /= g;
  cout << nom << " " << deno << endl;
  return 0;
}
