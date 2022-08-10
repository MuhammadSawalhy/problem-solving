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

#define f(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define int ll

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int t_case;

int lcm(int a, int b) { return a * b / __gcd(a, b); }

int count_divisible_nums(int n, vector<int> nums) {
  int cnt = 0;

  // I don't want all bits to be zero,
  // so let's skip this case ans start at 1
  int c = 1;

  while (c < 1 << nums.size()) {
    char sign = __builtin_popcountll(c) % 2 ? 1 : -1;
    int d = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (c & (1 << i))
        d = d * nums[i] / __gcd(d, nums[i]); // lcm
    }

    cnt += sign * n / d;
    c++;
  }

  return cnt;
}

// int count_divisible_nums(int n, vector<int> &nums, int depth = 1, int d = 0, int sign = 1) {
//   if ((ull)depth > nums.size()) {
//     if (d == 0)
//       return 0;
//     return sign * n / d;
//   }
//
//   int cnt = 0;
//
//   if (d == 0) {
//     cnt += count_divisible_nums(n, nums, depth + 1, d);
//     cnt += count_divisible_nums(n, nums, depth + 1, nums[depth - 1]);
//   } else {
//     cnt += count_divisible_nums(n, nums, depth + 1, d, sign);
//     cnt += count_divisible_nums(n, nums, depth + 1, lcm(d, nums[depth - 1]), sign * -1);
//   }
//
//   return cnt;
// }

void solve() {
  int n, m, a, d;
  cin >> n >> m >> a >> d;

  vector<int> divisors = {
      (a + 0 * d), (a + 1 * d), (a + 2 * d), (a + 3 * d), (a + 4 * d),
  };

  int ans = 0;

  ans = count_divisible_nums(m, divisors);
  ans -= count_divisible_nums(n - 1, divisors);

  std::cout << (m - n + 1) - ans << std::endl; // not divisible
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
