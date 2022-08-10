#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

int t_case;
int n;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);

  vector<ul> a;
  vector<ul> b;

  auto can = [&]() {
    ul gzero = 0;
    ul d = ULONG_MAX;

    if (a[0] < b[0]) return false;
    if (b[0] == 0) gzero = a[0];
    else d = a[0] - b[0];
    debug(d, gzero);

    for (int i = 1; i < n; i++) {
      if (b[i] == 0) {
        gzero = max(a[i], gzero);
        if (gzero > d) return false;
        continue;
      }

      if (a[i] < b[i]) return false;
      if (d != ULONG_MAX && d != a[i] - b[i]) return false;
      d = a[i] - b[i];
      if (d < gzero) return false;
      debug(d, gzero);
    }
    return true;
  };

  cin >> t_case;
  while (t_case--) {
    cin >> n;
    a.clear();
    a.resize(n);
    b.clear();
    b.resize(n);
    for (auto &i : a)
      cin >> i;
    for (auto &i : b)
      cin >> i;

    std::cerr << "-----------" << std::endl;
    debug(a);
    debug(b);

    if (can())
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}
