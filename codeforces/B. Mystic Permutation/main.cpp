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

int find_min(const int *v, int s, int e) {
  int min = s;
  for (int i = s + 1; i <= e; i++)
    if (v[i] < v[min])
      min = i;
  return min;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t_case;

  while (t_case--) {
    // your code here
    cin >> n;
    vector<int> o(n);
    vector<int> p(n);
    for (auto &i : p)
      cin >> i, o.push_back(i);

    if (n == 1) {
      std::cout << -1 << std::endl;
      continue;
    }

    std::cerr << "--------" << std::endl;
    debug(p);
    for (int k = 0; k < n; k++) {
      if (k == n - 1) {
        if (p.back() == o.back()) {
          std::cerr << "swapping last" << std::endl;
          debug(p);
          int v = p[n - 1];
          p[n - 1] = p[n - 2];
          p[n - 2] = v;
          debug(p);
        }
        continue;
      }

      int m = find_min(p.data(), k, n - 1);

      if (m == k && )
        continue;

      if (m == k) {
        k++;
        m = find_min(p.data(), k, n - 1);
        int v = p[m];
        std::cerr << "shifting" << std::endl;
        debug(k, p);
        for (int i = m; i >= k; i--) {
          p[i] = p[i - 1];
        }
        k--;
        p[k] = v;
        debug(k, p);
      } else {
        int v = p[m];
        std::cerr << "shifting" << std::endl;
        debug(k, p);
        for (int i = m; i > k; i--) {
          p[i] = p[i - 1];
          shifted[i] = true;
        }
        p[k] = v;
        debug(k, p);
      }
    }

    std::cout << p[0];
    for (int i = 1; i < n; i++)
      std::cout << " " << p[i];
    std::cout << std::endl;
  }

  return 0;
}
