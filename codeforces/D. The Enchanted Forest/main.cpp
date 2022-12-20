#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef SAWALHY
// and placeholder
#define debug1(...) 0
#define debug2(...) 0
#define debug_arr(...) 0
#else
#define debug1(x)    cerr << #x << ": " << x << endl
#define debug2(x, y) cerr << #x << ", " << #y << ": " << x << ", " << y << endl
#define debug_arr(arr, n) cerr << #arr << ": " << arr[0]; for (int i = 1; i < n; i++) cerr << ", " << b[i]; cerr << endl
#endif

template <class T> inline bool ckmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> inline bool ckmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> inline void clear(T *arr, int val, int n) { for (int i = 0; i < n; arr[i++] = val); }
// clang-format on

typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, k;

  cin >> t;

  while (t--) {
    cin >> n;
    cin >> k;

    ull a[n];

    cin >> a[0];
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
    }

    if (k < n) {
      ull max_sum = a[k - 1];
      for (int i = k; i < n; i++)
        max_sum = max(max_sum, a[i] - a[i - k]);
      std::cout << max_sum + (ull)(k - 1) * (k) / 2 << std::endl;
    } else {
      std::cout << a[n - 1] + (ull)n * k - (ull)n * (1 + n) / 2 << std::endl;
    }
  }

  return 0;
}


