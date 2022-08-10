/// shaylhalk ya zbala yal bttshal fe ekwam

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>

using ll = long long;
using ii = pair<ll, ll>;

#define pb push_back
#define F first
#define S second
#define f(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define mp(x, y) make_pair(x, y)
#define popCnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define int ll

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 5, LG = log2(N) + 1, MOD = 1e9 + 7;
const double PI = acos(-1);

void doWork() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for (char c = 'a'; c <= 'c'; c++) {
    if (count(all(s), c) != count(all(t), c)) {
      cout << "NO\n";
      return;
    }
  }

  int cnt = 0;
  f(i, 0, n) {
    if (s[i] == 'a') {
      cnt += 1;
    } else if (s[i] == 'c') {
      if (cnt) {
        cout << "NO\n";
        return;
      }
    }
    if (t[i] == 'a') {
      if (cnt) {
        cnt -= 1;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  f(i, 0, n) {
    if (t[i] == 'c') {
      cnt += 1;
    } else if (t[i] == 'a') {
      if (cnt) {
        cout << "NO\n";
        return;
      }
    }
    if (s[i] == 'c') {
      if (cnt) {
        cnt -= 1;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
}
int32_t main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
