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

bool win(int a, int b) {
  if (a < b)
    swap(a, b);

  if (a % b == 0)
    return true;

  if (a / b > 1) {
    if (!win(a - a / b * b + b, b))
      return true;
  }

  if (!win(a - a / b * b, b))
    return true;

  return false;
}

void solve() {
  int a, b;
  while (true) {
    cin >> a >> b;
    if (a == 0)
      break;
    if (win(a, b))
      cout << "Stan wins" << endl;
    else
      cout << "Ollie wins" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
