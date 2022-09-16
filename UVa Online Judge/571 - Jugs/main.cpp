//============================================================================
// Problem     : UVa Online Judge/571 - Jugs
// Author      : Muahmmad Assawalhy
// Date        : 30-08-22
//============================================================================

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

int frompair(const pair<int, int> &p) { return p.first * 10000 + p.second; }

pair<int, int> topair(int p) { return make_pair(p / 10000, p % 10000); }

void solve() {
  int a, b, n;
  while (cin >> a >> b >> n) {
    debug(a, b, n);
    const int N = 1001;
    vector<int> dist(N * N, INT_MAX);
    vector<string> point(N * N);
    vector<int> parent(N * N);

    int e;
    dist[0] = 0;
    typedef pair<int, int> quelement;
    priority_queue<quelement, vector<quelement>, greater<quelement>> qu;
    qu.push({0, 0});

    while (!qu.empty()) {
      auto front = qu.top();
      int c = front.second;
      int d = front.first;
      int oldc = c;
      auto p = topair(c);
      qu.pop();

      if (p.first == n || p.second == n) {
        e = c;
        break;
      }

      if (dist[c] < d)
        continue;

      vector<pair<pair<int, int>, string>> moves = {
          {{a, p.second}, "fill A"},
          {{0, p.second}, "empty A"},
          {{p.first, b}, "fill B"},
          {{p.first, 0}, "empty B"},
          {{p.first + p.second - min(b, p.first + p.second),
            min(b, p.first + p.second)},
           "pour A B"},
          {{min(a, p.first + p.second),
            p.second + p.first - min(a, p.first + p.second)},
           "pour B A"},
      };

      for (const auto &move : moves) {
        c = frompair(move.first);
        if (d + 1 < dist[c]) {
          debug(p, move);
          dist[c] = d + 1;
          parent[c] = oldc;
          point[c] = move.second;
          qu.push({d + 1, c});
        }
      }
    }

    vector<string> ans;
    while (e != 0) {
      ans.push_back(point[e]);
      e = parent[e];
    }

    while (!ans.empty()) {
      cout << ans.back() << endl;
      ans.pop_back();
    }

    cout << "success" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
