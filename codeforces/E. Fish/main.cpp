// Date: 26-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

vector<vector<double>> mat;
vector<vector<double>> memo;
vector<vector<double>> eaten_prop(18, vector<double>(1 << 18, -1));
int n;

double calc_eaten_prop(int i, int mask, int cnt) {
  if (eaten_prop[i][mask] != -1) {
    return eaten_prop[i][mask];
  }

  double sum = 0;
  for (int j = 0; j < n; j++) {
    if (mask >> j & 1 || j == i)
      continue;
    sum += mat[j][i]; // j eats i
  }

  return eaten_prop[i][mask] = sum * 2 / (n - cnt) / (n - cnt - 1);
}

double calc(int i, int mask, int cnt = 0) {
  if (cnt == n - 1)
    return 0;

  if (memo[i][mask] != -1)
    return memo[i][mask];

  double val = calc_eaten_prop(i, mask, cnt);

  for (int j = 0; j < n; j++) {
    if (mask >> j & 1 || j == i)
      continue;
    val += calc_eaten_prop(j, mask, cnt) * calc(i, mask | (1 << j), cnt + 1);
  }

  return memo[i][mask] = val;
}

void solve() {
  cin >> n;
  mat = vector<vector<double>>(n, vector<double>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    memo = vector<vector<double>>(n, vector<double>(1 << 18, -1));
    cout << fixed << 1 - calc(i, 0) << " ";
  }

  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
