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
int m, n, k;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t_case;

  vector<char> a, b;
  while (t_case--) {
    string c;
    char ia = 0, ib = 0;
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);

    for (char &i : a)
      cin >> i;
    for (char &i : b)
      cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    debug(a);
    debug(b);

    int k_;
    char l = 'a';
    bool first = true;
    while (true) {
      k_ = k;

      if (ia >= n || ib >= m) {
        break;
      }

      if (!first) {
        if (l == 'a') {
          l = 'b';
          c += b[ib];
          ib++;
          k_--;
        } else {
          l = 'a';
          c += a[ia];
          ia++;
          k_--;
        }
      }

      if (ia >= n || ib >= m) {
        break;
      }

      first = false;

      while (k_--) {
        debug((ull)ia, (ull)ib, c);
        if (a[ia] < b[ib]) {
          if (l != 'a') {
            l = 'a';
            k_ = k - 1;
          }

          c += a[ia];
          ia++;
          if (ia >= n || ib >= m) {
            break;
          }
        } else {
          if (l != 'b') {
            l = 'b';
            k_ = k - 1;
          }

          c += b[ib];
          ib++;
          if (ia >= n || ib >= m) {
            break;
          }
        }
      }
    }

    std::cout << c << std::endl;
  }

  return 0;
}
