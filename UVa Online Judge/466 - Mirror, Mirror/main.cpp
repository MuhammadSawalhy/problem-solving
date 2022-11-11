// Date: 19-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int n;
int t;

vector<vector<char>> rotate90(vector<vector<char>> s) {
  vector<vector<char>> r(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[j][n - 1 - i] = s[i][j];
    }
  }
  return r;
}

vector<vector<char>> rotate180(vector<vector<char>> s) {
  return rotate90(rotate90(s));
}

vector<vector<char>> rotate270(vector<vector<char>> s) {
  return rotate90(rotate90(rotate90((s))));
}

vector<vector<char>> reflect_vert(vector<vector<char>> s) {
  vector<vector<char>> r(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[n - 1 - i][j] = s[i][j];
    }
  }
  return r;
}

void solve() {
  vector<vector<char>> s(n, vector<char>(n));
  vector<vector<char>> t(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> s[i][j];
    }
    for (int j = 0; j < n; j++) {
      cin >> t[i][j];
    }
  }

  auto r90 = rotate90(s);
  auto r180 = rotate180(s);
  auto r270 = rotate270(s);
  auto reflected = reflect_vert(s);

  if (s == t) {
    cout << "preserved." << endl;
  } else if (r90 == t) {
    cout << "rotated 90 degrees." << endl;
  } else if (r180 == t) {
    cout << "rotated 180 degrees." << endl;
  } else if (r270 == t) {
    cout << "rotated 270 degrees." << endl;
  } else if (reflected == t) {
    cout << "reflected vertically." << endl;
  } else if (rotate90(reflected) == t) {
    cout << "reflected vertically and rotated 90 degrees." << endl;
  } else if (rotate180(reflected) == t) {
    cout << "reflected vertically and rotated 180 degrees." << endl;
  } else if (rotate270(reflected) == t) {
    cout << "reflected vertically and rotated 270 degrees." << endl;
  } else {
    cout << "improperly transformed." << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  while (cin >> n && ++t)
    cout << "Pattern " << t << " was ", solve();

  return 0;
}
