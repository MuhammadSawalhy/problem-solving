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

#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

vi ans;
vector<pair<int, int>> m;
bool valid = true;
int sum, limit;

void get_sum(int sum, int offset, int c) {
  debug(sum, offset, c);

  int v = min(sum, (c + 1) / 2);
  sum -= v;

  if (sum) {
    if (sum & 1) {
      sum += 1;
      v--;
    }

    int newoffset = offset + (c + 1) / 2;

    if (newoffset >= limit) {
      valid = false;
      return;
    }

    get_sum(sum / 2, newoffset, limit - newoffset);
  }

  for (int i = offset; i < offset + v; i++) {
    debug(i, m[i]);
    ans.push_back(m[i].second);
  }
}

void solve() {
  cin >> sum >> limit;
  ans.clear();

  for (int i = 1; i <= limit; i++)
    m.push_back({1 << LSB(i), i});

  sort(all(m), [](auto l, auto r) {
    return l.first == r.first ? l.second < r.second : l.first < r.first;
  });
  debug(m);

  get_sum(sum, 0, limit);

  if (!valid) {
    cout << -1 << endl;
    return;
  }

  cout << sz(ans) << endl;
  for (int i = 0; i < sz(ans); i++)
    cout << ans[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
