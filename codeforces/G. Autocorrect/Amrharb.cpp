#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  vector<pair<string, ll>> ans;
  map<char, ll> mp;
  for (auto &it : s)
    mp[it]++;
  int t;
  cin >> t;
  while (t--) {
    string x;
    map<char, ll> mk;
    cin >> x;
    ll cnt = 0, mat = 0;
    for (auto &it : x)
      mk[it]++;
    for (auto &it : mk) {
      for (auto &el : mp) {
        cnt += it.second * 1LL * el.second;
        if (it.first == el.first)
          mat += it.second * 1LL * el.second;
      }
    }
    long double k = mat * 1.0 / cnt * 1000, z;
    ll l = k;
    z = k;
    bool flag = 0;
    while (l % 10 >= 5) {
      if (l % 10 > 5) {
        flag = 1;
        break;
      }
      k *= 10;
      l = k;
      l %= 10;
    }
    l = z;
    l /= 10;
    if (flag)
      l++;
    ans.push_back({x, l});
  }

  debug(ans);
  sort(ans.begin(), ans.end(), [&](pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second)
      return a.first > b.first;
    return a.second > b.second;
  });
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << fixed << setprecision(2)
         << ans[i].second / 100.0 << endl;
  return 0;
}
