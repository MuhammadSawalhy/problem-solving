#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

typedef long long ll;

ll mod = 998244353;

ll qq(ll b) {
  ll ans = 1;
  ll a = 2;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

string s, t = "nunhehheh";

const int N = 1E5 + 10;
ll dp[10][N];
ll pre[N];

int main() {
  IOS int T;
  cin >> T;
  for (int k = 1; k <= T; ++k) {
    cin >> s;
    int sz = s.size(), tz = t.size();
    for (int i = 1; i <= sz; ++i) {
      pre[i] = 0;
      if (s[i - 1] == 'a')
        pre[i] = 1;
      pre[i] += pre[i - 1];
    }

    ll ans = 0;
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= sz; ++i)
      dp[0][i] = 1;

    for (int i = 1; i <= sz; ++i) {
      for (int j = 1; j <= tz; ++j) {
        /* 根据是否相等执行不同操作，因为此时需要匹配t[0 :
         * j]，而只有相等是才可以允许只匹配t[0 : j-1] */
        if (s[i - 1] == t[j - 1])
          dp[j][i] = (dp[j - 1][i - 1] + dp[j][i - 1]) % mod;
        else
          dp[j][i] = dp[j][i - 1];
      }

      ll x = pre[sz] - pre[i]; // remaining a's
      ll y = (dp[tz][i] - dp[tz][i - 1] + mod) % mod;

      if (y && x) {
        y = y * (qq(x) - 1) % mod;
        ans = (ans + y) % mod;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
