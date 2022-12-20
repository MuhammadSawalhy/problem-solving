// Date: 25-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void Um_nik() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << "1 3" << endl;
    return;
  }

  ll d = n;
  ll sum = (d + n - 1) * (d + n - 1) - (ll) n * (n + 1) / 2 - d;
  assert(sum >= 0);

  // where 0 <= b[1] <= b[i] <= b[n];
  // sum = n * b[1] + sigma(2, n-1, b[i] - b[1])
  //                        0 <= sigma <= d * (n - 2)

  // ------------------------------------------------------------------
  // choose b[1] big enough then we have to compute the last part (sigma)
  // ------------------------------------------------------------------

  ll b[n + 1];
  b[1] = sum / n;
  b[n] = b[1] + d;
  sum %= n;
  b[n - 1] = b[1] + sum;
  for (int i = 2; i <= n - 2; i++) {
    b[i] = b[1];
  }

  for (int i = 1; i <= n; i++) {
    cout << b[i] + i << " ";
  }
  cout << endl;
}

template<class T>
void choose(int cnt, vector<T> &v, vector<vector<T>> &res, int i = 0,
            vector<T> choosen = vector<T>()) {

  if (cnt == 0) {
    res.push_back(choosen);
    return;
  }

  if (i >= (int) v.size())
    return;

  choosen.push_back(v[i]);
  choose(cnt - 1, v, res, i + 1, choosen);
  choosen.pop_back();
  choose(cnt, v, res, i + 1, choosen);
}

void solve() {
  int n;
  cin >> n;

  if (n & 1) {
    // TODO
    return;
  }

  int x = n;
  for (int i = x - n / 2; i <= x + n / 2; ++i, i += i == x) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
