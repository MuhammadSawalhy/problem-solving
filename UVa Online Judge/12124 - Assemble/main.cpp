#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

bool comp_up(const pair<ll, ll> &l, const pair<ll, ll> &r) {
  return l.second < r.second;
}

bool comp_so(const pair<ll, ll> &l, const pair<ll, ll> &r) {
  return l.second == r.second ? l.first < r.first : l.second < r.second;
}

void solve() {
  ll n, b;
  cin >> n >> b;

  map<string, vector<pair<ll, ll>>> comps;

  for (ll i = 0; i < n; i++) {
    string t, m;
    cin >> t >> m;
    ll p, q;
    cin >> p >> q;
    comps[t].emplace_back(p, q);
  }

  map<string, pair<ll, ll>> ans;

  for (auto &c : comps) {
    auto m = min_element(all(c.second));
    ans[c.first] = *m;
    b -= m->first;
    sort(all(c.second), comp_so);
  }

  while (true) {
    string mt;
    pair<ll, ll> mq = {0, LONG_LONG_MAX};

    for (auto &a : ans) {
      if (a.second.second < mq.second) {
        mt = a.first;
        mq = a.second;
      }
    }

    auto ub = upper_bound(all(comps[mt]), mq, comp_up);

    if (ub == comps[mt].end())
      break;

    b += mq.first;
    b -= ub->first;

    if (b < 0)
      break;

    ans[mt] = *ub;
  }

  ll aa = LONG_LONG_MAX;
  for (auto &p : ans)
    aa = min(aa, p.second.second);
  cout << aa << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
