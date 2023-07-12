// Date: 23-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

auto doit(long long k, int i, vector<int> &stack) {
  long long kk = k, m = k;
  pair<long long, int> res = {-1, -2};
  for (int j = i; j >= 0; j--) {
    kk += stack[j];
    if (kk < 0) {
      return res;
    }
    if (kk >= m) {
      res = {kk - k, j};
      m = kk;
    }
  }

  return make_pair(-1LL, -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  scanf("%d", &t_cases);
  while (t_cases--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    k--;

    int a;
    vector<int> left, right;
    for (int i = 0; i < k; i++) {
      scanf("%d", &a);
      left.push_back(a);
    }

    scanf("%lld", &k);
    for (int i = n - 1 - left.size(); i--;) {
      scanf("%d", &a);
      right.push_back(a);
    }
    reverse(right.begin(), right.end());

    int i = left.size() - 1, j = right.size() - 1;

    while (true) {
      auto vl = doit(k, i, left);
      if (vl.second == -1) {
        puts("YES");
        break;
      }
      auto vr = doit(k, j, right);
      if (vr.second == -1) {
        puts("YES");
        break;
      }

      if (vl.second != -2) {
        k += vl.first;
        i = vl.second - 1;
      }

      if (vr.second != -2) {
        k += vr.first;
        j = vr.second - 1;
      }

      if (vr.second == -2 && vl.second == -2) {
        puts("NO");
        break;
      }
    }
  }

  return 0;
}

