// Date: 03-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

map<pair<int, int>, pair<array<int, 3>, vector<string>>> memo;
vector<pair<int, int>> mats;

pair<array<int, 3>, vector<string>> mincost(int i, int j) {
  if (memo.find({i, j}) != memo.end())
    return memo[{i, j}];

  if (i + 1 == j) {
    return memo[{i, j}] = {{mats[i].first, mats[i].second, 0}, {}};
  }

  int cost = INT_MAX;
  array<int, 2> size;
  vector<string> grouping;

  for (int k = i + 1; k < j; k++) {
    auto left = mincost(i, k);
    auto right = mincost(k, j);
    assert(left.first[1] == right.first[0]);
    size = {left.first[0], right.first[1]}; // is the same for all cases
    int newcost = right.first[2] + left.first[2] +
                  left.first[0] * left.first[1] * right.first[1];
    if (newcost < cost) {
      cost = newcost;
      grouping = {to_string(i) + "-"};
      for (auto g : left.second) {
        grouping.push_back(g);
      }
      for (auto g : right.second) {
        grouping.push_back(g);
      }
      grouping.push_back(to_string(j - 1) + "+");
    }
  }

  return memo[{i, j}] = {{size[0], size[1], cost}, grouping};
}

void solve(int n) {
  mats.resize(n);
  memo.clear();
  for (int i = 0; i < n; i++)
    cin >> mats[i].first >> mats[i].second;
  auto ans = mincost(0, n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < (int)ans.second.size() && ans.second[j] == to_string(i) + "-") {
      cout << "(";
      j++;
    }
    cout << "A" << i + 1;
    while (j < (int)ans.second.size() && ans.second[j] == to_string(i) + "+") {
      cout << ")";
      j++;
    }

    if (i < n - 1) {
      cout << " x ";
    }
  }

  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  int t = 0;
  while (cin >> n, n) {
    cout << "Case " << ++t << ": ";
    solve(n);
  }
  return 0;
}
