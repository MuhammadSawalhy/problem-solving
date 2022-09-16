#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define Endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(n) for (int i = 0; i < (n); i++)
const long long inf = (long long)1e18;
#define fast                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
int N = 2e5 + 5;
#define YES cout << "YES\n"
#define NO cout << "NO\n"
template <class t> void print(t printed) { cout << printed << endl; }
void file() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1,
                   int end = -1) {
  if (start < 0)
    start = 0;
  if (end < 0)
    end = int(v.size());

  for (int i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
/**************** Solution start from here *******************/

int main() {
  // file();
  fast;

  int tc = 1;
  cin >> tc;

  while (tc--) {

    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      mp[MSB(x)]++;
    }

    ll ans = 0;

    for (auto x : mp) {
      ll n = x.second;
      ans += n * (n - 1) / 2;
    }

    cout << ans << endl;
  }
}
