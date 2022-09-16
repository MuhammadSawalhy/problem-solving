// ----------------------------------------------------------------------------
// Problem : E. Guess the Cycle Size
// Author  : Muahmmad Assawalhy
// Date    : 12-09-22
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

ll ask(ll i, ll j) {
  cout << "? " << i << " " << j << endl;
  ll ans;
  cin >> ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n = 2;

  while (true) {
    ll x = ask(1, n); 
    if (x == -1) {
      n--;
      break;
    }
    ll y = ask(n, 1);
    if (x != y) {
      n = x + y;
      break;
    }
    n++;
  }

  cout << "! " << n << endl;
  return 0;
}
