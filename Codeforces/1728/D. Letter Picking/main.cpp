// ----------------------------------------------------------------------------
// Problem : D. Letter Picking
// Author  : Muahmmad Assawalhy
// Date    : 08-09-22
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

int memo[2000][2000][2];
string s;
vector<char> choice[2];

int winner(int i, int j, bool p) {
  if (i > j) {
    for (int k = choice[0].size() - 1; k >= 0; k--) {
      if (choice[0][k] < choice[1][k]) {
        return 0;
      }

      if (choice[1][k] < choice[0][k]) {
        return 1;
      }
    }

    return 2;
  }

  int &w = memo[i][j][p];
  if (w != -1)
    return w;

  choice[p].push_back(s[i]);
  int c1 = winner(i + 1, j, !p);
  choice[p].pop_back();
  int c2 = c1;
  if (i < j) {
    choice[p].push_back(s[j]);
    c2 = winner(i, j - 1, !p);
    choice[p].pop_back();
  }

  if (c1 == p || c2 == p)
    w = p;
  else if (c1 == 2 || c2 == 2)
    w = 2;
  else
    w = !p; // == c2, the other player

  return w;
}

int main() {
  freopen("/home/ms/myp/problem-solving/input", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    cin >> s;
    int i = 0, j = s.size() - 1;
    memset(memo, -1, sizeof memo);
    int w = winner(0, s.size() - 1, 0);
    if (w == 0) {
      cout << "Alice" << endl;
    } else if (w == 1) {
      cout << "Bob" << endl;
    } else {
      cout << "Draw" << endl;
    }
  }

  return 0;
}

/*

1
abba

*/