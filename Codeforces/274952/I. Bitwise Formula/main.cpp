// ----------------------------------------------------------------------------
// Problem : I. Bitwise Formula
// Author  : Muahmmad Assawalhy
// Date    : 06-09-22
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

int n, m;
vector<array<string, 4>> exprs;

unordered_map<string, int> vals;
int count_ones(int i, int y) {
  int cnt = 0;

  for (int j = 0; j < n; j++) {
    const string op = exprs[j][2];
    const string &ll = exprs[j][1], &rr = exprs[j][3];
    int l = ll == "?" ? y : ll[0] <= '1' ? (ll[i] == '0' ? 0 : 1) : vals[ll];
    int r = rr == "?" ? y : rr[0] <= '1' ? (rr[i] == '0' ? 0 : 1) : vals[rr];

    int res;
    if (op == "AND") {
      res = r & l;
    } else if (op == "OR") {
      res = r | l;
    } else if (op == "XOR") {
      res = r ^ l;
    } else {
      res = r;
    }

    vals[exprs[j][0]] = res;
    cnt += res;
  }

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  cin.get();

  for (int i = 0; i < n; i++) {
    // varname := <number>
    // varname := <lhs> <op> <rhs>
    string line;
    getline(cin, line);
    istringstream is(line);
    string var, expr;
    getline(is, var, ' ');
    getline(is, expr, ' ');
    getline(is, expr);

    string rr, ll, o;
    if (expr.find(' ') != string::npos) {
      // operation involved
      istringstream is(expr);
      getline(is, ll, ' ');
      getline(is, o, ' ');
      getline(is, rr, ' ');
    } else {
      o = "";
      ll = rr = expr;
    }

    exprs.push_back({var, ll, o, rr});
  }

  string mn, mx;
  for (int i = 0; i < m; i++) {
    int cnt0 = count_ones(i, 0);
    int cnt1 = count_ones(i, 1);

    if (cnt0 == cnt1) {
      mn += "0";
      mx += "0";
    } else if (cnt0 < cnt1) {
      mn += "0";
      mx += "1";
    } else {
      mn += "1";
      mx += "0";
    }
  }

  cout << mn << endl;
  cout << mx << endl;

  return 0;
}
