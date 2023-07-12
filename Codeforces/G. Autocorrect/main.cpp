#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define int ll
#define f(i, b) for (ll i = 0; i < b; i++)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

typedef vector<int> vi;
typedef vector<bool> vb;

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int t_case;

void solve() {
  string w;
  int n;
  cin >> w;
  cin >> n;

  vector<pair<string, double>> res;

  string s;
  int mat;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mat = 0;
    for (char c : s) {
      for (char cc : w) {
        if (c == cc)
          mat++;
      }
    }

    double index = (double)mat / (s.size() * w.size());
    debug(index);

    // round it
    index += 0.00444444444444444444444444444444444444444444444444444444444444;
    index = (int)(index * 100) / 100.0;
    debug(index);

    res.push_back({s, index});
  }

  sort(all(res), [](const auto &v, const auto &k) {
    return v.second == k.second ? v.first > k.first : v.second > k.second;
  });

  for (const auto &v : res) {
    std::cout << v.first << " " << fixed << setprecision(2) << v.second
              << std::endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
