#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
const int Max = 50;
ll t, n, m, arr[Max], x, ans = 0;
ll Min = 1e9;
const int val = 1e9 + 7;
int mat[28][10];
map<ll, int> Map;

ll pow(ll x, int n) {
  ll y = 1;
  ll u = x % val;
  while (n) {
    if (n & 1) {
      y = y * u % val;
    }
    n >>= 1;
    u = u * u % val;
  }
  return y;
}

void solve(int s, int e, int flag, long long res) {
  if (e == s) {
    if (flag)
      Map[res]++;
    else
      // if we didn't use mod, it is x / res
      ans += Map[x * pow(res, val - 2) % val];
  } else {
    for (int i = 0; i < 6; i++)
      solve(s + 1, e, flag, res * mat[s][i] % val);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    ans = 0;
    Map.clear();
    int n;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++) {
        cin >> mat[i][j];
      }
    }

    // divide and conqer
    solve(0, n / 2, 1, 1); // (6 ^ 7) is good
    solve(n / 2, n, 0, 1); // complete
    cout << ans << endl;
  }
  return 0;
}
