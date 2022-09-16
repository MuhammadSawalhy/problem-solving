// ----------------------------------------------------------------------------
// Problem : E. Battle Lemmings
// Author  : Muahmmad Assawalhy
// Date    : 12-09-22
// ----------------------------------------------------------------------------

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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vi a(n);
  for (auto &i : a)
    cin >> i;

  int zeros = 0;
  int z = 0;
  int val = 0;
  int ones_size = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      val += zeros;
      z++;
    } else
      zeros += z, z = 0, ones_size++;
  }

  auto get_ones = [n](pair<ll, ll> &ones_pair) {
    vector<pair<int, int>> ones;
    int z = 0;

    for (int i = 0; i < min(n, 64); i++) {
      int b = (ones_pair.first >> i) & 1;
      if (b == 0)
        z++;
      else {
        if (!ones.empty())
          ones.back().second = z;
        ones.push_back({z, 0});
        z = 0;
      }
    }

    for (int i = 64; i < n; i++) {
      int b = (ones_pair.second >> (i - 64)) & 1;
      if (b == 0)
        z++;
      else {
        if (!ones.empty())
          ones.back().second = z;
        ones.push_back({z, 0});
        z = 0;
      }
    }

    if (!ones.empty())
      ones.back().second = z;

    return ones;
  };

  auto get_ones_pair = [ones_size, n](vector<pair<int, int>> &ones) {
    pair<ll, ll> ones_pair;
    int i = 0, j = 0;
    if (j < ones_size)
      i += ones[j].first, j++;

    while (i < 64) {
      ones_pair.first |= 1LL << i;
      if (j == ones_size)
        break;
      i += ones[j].first;
      i++;
      j++;
    }

    while (i < n) {
      ones_pair.first |= 1LL << i;
      if (j == ones_size)
        break;
      i += ones[j].first;
      i++;
      j++;
    }

    return ones_pair;
  };

  pair<ll, ll> ones_pair;
  for (int i = 0; i < min(n, 64); i++)
    ones_pair.first |= (long long)a[i] << i;
  for (int i = 64; i < n; i++)
    ones_pair.first |= (long long)a[i] << i;

  // ones = get_ones(ones_pair);
  // debug(ones_pair);
  // debug(ones);
  // debug(get_ones_pair(ones));
  // return 0;

  vector<int> allvals(n * (n - 1) / 2 + 1, val);
  typedef pair<pair<int, int>, pair<ll, ll>> way_t;
  priority_queue<way_t, vector<way_t>, greater<way_t>> ways;
  ways.push({{1, val}, ones_pair});

  auto do_action = [ones_size](pair<int, int> &action,
                               vector<pair<int, int>> &ones) {
    if (action.second == -1) {
      ones[action.first].first--;
      ones[action.first].second++;
      if (action.first > 0) {
        ones[action.first - 1].second--;
      }
      if (action.first < ones_size - 1) {
        ones[action.first + 1].first++;
      }
    }

    if (action.second == +1) {
      ones[action.first].first++;
      ones[action.first].second--;
      if (action.first > 0) {
        ones[action.first - 1].second++;
      }
      if (action.first < ones_size - 1) {
        ones[action.first + 1].first--;
      }
    }
  };

  map<pair<ll, ll>, bool> vis;

  while (!ways.empty()) {
    auto w = ways.top();
    int i = w.first.first;
    int val = w.first.second;
    auto ones = get_ones(w.second);
    ways.pop();

    debug(i, val, ways.size());
    debug(allvals);
    cerr << "ones = [";
    vector<int> d;
    for (int j = 0; j < (int)ones_size; j++) {
      int c = ones[j].first;
      while (c--)
        d.push_back(0);
      d.push_back(1);
    }
    while (d.size() < a.size())
      d.push_back(0);
    for (int j = 0; j < (int)d.size(); j++)
      cerr << d[j] << vector<string>({", ", "]\n"})[j == d.size() - 1];

    for (; i <= n * (n - 1) >> 1; i++) {
      int gain = 0;
      pair<int, int> action;
      vector<pair<int, int>> new_ways;

      for (int j = 0; j < (int)ones_size; j++) {
        int g;

        g = (ones[j].first - 1) * (ones[j].second + 1) -
            ones[j].first * ones[j].second;
        if (g > gain) {
          gain = g;
          action = {j, -1};
        } else if (g == gain) {
          new_ways.push_back({j, -1});
        }

        g = (ones[j].first + 1) * (ones[j].second - 1) -
            ones[j].first * ones[j].second;
        if (g > gain) {
          gain = g;
          action = {j, +1};
        } else if (g == gain) {
          new_ways.push_back({j, +1});
        }
      }

      val += gain;
      if (val < allvals[i])
        break;
      allvals[i] = val;

      if (action.second == 0) {
        while (!new_ways.empty()) {
          auto new_ones = ones;
          do_action(new_ways.back(), new_ones);
          new_ways.pop_back();
          auto ones_pair = get_ones_pair(new_ones);
          if (vis[ones_pair])
            continue;
          vis[ones_pair] = true;
          ways.push({{i + 1, val}, ones_pair});
        }
      } else {
        do_action(action, ones);
      }
    }
  }

  for (int i = 0; i < (int)allvals.size(); i++)
    cout << allvals[i] << " ";
  cout << endl;

  return 0;
}
