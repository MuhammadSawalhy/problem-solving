//============================================================================
// Problem     : 10192 - Vacation
// Author      : Muahmmad Assawalhy
// Date        : 03-09-22
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

char a[101], b[101];
int sa, sb;
int memo[100][100];

int maxseq(int i, int j) {
  if (i >= sa || j >= sb)
    return 0;
  int &r = memo[i][j];
  if (r != -1)
    return r;

  if (a[i] == b[j]) {
    r = max(r, 1 + maxseq(i + 1, j + 1));
  } else {
    r = max(r, maxseq(i + 1, j));
    r = max(r, maxseq(i, j + 1));
  }

  return r;
}

void solve() {
  int c = 0;
  while (true) {
    cin.getline(a, 1000, '\n');
    sa = strlen(a);
    if (a[0] == '#' && sa == 1)
      break;
    cin.getline(b, 1000, '\n');
    sb = strlen(b);
    memset(memo, -1, sizeof memo);
    printf("Case #%d: you can visit at most %d cities.\n", ++c, maxseq(0, 0));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
