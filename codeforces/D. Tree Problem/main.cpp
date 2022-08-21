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

vector<ull> memo;
vector<bool> used;
vector<int> parent;
vector<vector<int>> adjlist;

ull calc_sub(int x) {
  ull &r = memo[x];
  if (used[x])
    return r;
  used[x] = true;

  for (int c : adjlist[x]) {
    if (used[c])
      continue;
    parent[c] = x;
    r += calc_sub(c);
    r++;
  }

  return r;
}

void solve() {
  int n;
  cin >> n;
  adjlist = vector<vector<int>>(n + 1);
  memo = vector<ull>(n + 1);
  used = vector<bool>(n + 1);
  parent = vector<int>(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }

  int q;
  cin >> q;
  ull qmem[(int)1e5 + 1] = {};
  while (q--) {
    int x;
    cin >> x;

    if (qmem[x]) {
      cout << qmem[x] << endl;
      continue;
    }

    ull sum;
    ull ans = 0;
    vector<ull> nums;

    calc_sub(x);
    for (auto v : adjlist[x]) {
      if (v == parent[x])
        continue;
      nums.push_back(calc_sub(v) + 1);
      sum += nums.back();
    }

    nums.push_back(n - 1 - sum);
    sum = n - 1;

    ans += sum;
    for (int i = 0; i < sz(nums) - 1; i++) {
      sum -= nums[i];
      ans += nums[i] * sum;
    }

    qmem[x] = ans;

    cout << qmem[x] << endl;
  }

  debug(adjlist);
  debug(memo);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
