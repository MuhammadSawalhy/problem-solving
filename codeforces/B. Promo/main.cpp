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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<ull> p(n + 1);

  for (int i = 1; i < n + 1; i++)
    cin >> p[i];

  sort(p.begin(), p.end());

  for (int i = 1; i < n + 1; i++) {
    p[i] += p[i - 1];
  }

  debug(p);

  int x, y;
  ull s;

  while (q--) {
    cin >> x >> y;
    // if(x == n)
    //   s = p[n - x + y - 1];
    s = p[n - x + y] - p[n - x];

    std::cout << s << std::endl;
  }

  return 0;
}
