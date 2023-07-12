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

void solve() {
  string s;
  getline(cin, s);
  int n;
  cin >> n;

  string str;
  for (char c : s) {
    if (c != ' ')
      str += c;
  }

  sort(all(str));

  vector<string> dic;
  vector<vector<string>> ana;
  while (n--) {
    string w;
    cin >> w;
    dic.push_back(w);
  }

  for (int i = 0;)

  for (auto &vs : ana) {
    for (int i = 0; i < sz(vs); i++)
      cout << vs[i] << " \n"[i == sz(vs) - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
