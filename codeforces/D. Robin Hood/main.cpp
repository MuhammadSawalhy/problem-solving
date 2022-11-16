// Date: 29-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n, k;
  scanf("%d%d", &n, &k);

  int a[n];
  map<int, int> fr;
  for (int i = 0; i < n; i++)
    scanf("%d", a + i), fr[a[i]]++;

  deque<pair<int, int>> ms(all(fr));

  while (ms.size() > 2 && k) {
    auto [mx, m] = ms.back();
    auto [mn, M] = ms.front();
    int mx2 = ms[ms.size() - 2].first;
    int mn2 = ms[1].first;
    int s = min({k, (mx - mx2) * m, (mn2 - mn) * M});
    k -= s;

    {
      int newmx = mx - s / m;
      if (s % m == 0) {
        ms.pop_back();
        if (ms.back().first == newmx) {
          m += ms.back().second;
          ms.pop_back();
          ms.push_back({newmx, m});
        } else {
          ms.push_back({newmx, m});
        }
      } else {
        ms.pop_back();
        if (ms.back().first == newmx - 1) {
          int mm = s % m + ms.back().second;
          ms.pop_back();
          ms.push_back({newmx - 1, mm});
        } else {
          ms.push_back({newmx - 1, s % m});
        }
        ms.push_back({newmx, m - s % m});
      }
    }

    {
      int newmn = mn + s / M;
      if (s % M == 0) {
        ms.erase(ms.begin());
        if (ms.begin()->first == newmn) {
          M += ms.begin()->second;
          ms.erase(ms.begin());
          ms.push_front({newmn, M});
        } else {
          ms.push_front({newmn, M});
        }
      } else {
        ms.erase(ms.begin());
        if (ms.begin()->first == newmn + 1) {
          int mm = s % M + ms.begin()->second;
          ms.pop_front();
          ms.push_front({newmn + 1, mm});
        } else {
          ms.push_front({newmn + 1, s % M});
        }
        ms.push_front({newmn, M - s % M});
      }
    }
  }

  if (ms.size() == 1) {
    printf("0");
  } else {// 2
    int s = 0, e = k + 1;
    auto [mx, m] = ms.back();
    auto [mn, M] = ms.front();

    if (k == 0) {
      printf("%d", mx - mn);
      return 0;
    }

    while (e - s > 1) {
      int mid = (s + e) / 2;
      if (mid <= k && mx - (mid + m - 1) / m >= mn + (mid + M - 1) / M) {
        s = mid;
      } else {
        e = mid;
      }
    }
    printf("%d", mx - s / m - (mn + s / M));
  }

  return 0;
}
