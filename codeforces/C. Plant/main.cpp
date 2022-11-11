// Date: 24-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

constexpr ll mod = 1e9 + 7;

typedef vector<vector<ll>> vvll;
struct matrix {
  vvll mat;
  int n, m;

  matrix(vvll mat) : mat(mat) {
    n = mat.size();
    m = mat[0].size();
  }

  matrix(int n, int m) : n(n), m(m) { mat = vvll(n, vector<ll>(m)); }

  matrix operator*(matrix other) {
    assert(m == other.n);
    matrix mult = vvll(n, vector<ll>(other.m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < other.m; j++) {
        for (int k = 0; k < m; k++) {
          mult.mat[i][j] += mat[i][k] * other.mat[k][j] % mod;
          mult.mat[i][j] %= mod;
        }
      }
    }
    return mult;
  }

  matrix operator+(matrix other) {
    assert(m == other.m && n == other.n);
    matrix s = mat;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s.mat[i][j] += other.mat[i][j];
        s.mat[i][j] %= mod;
      }
    }
    return s;
  }

  matrix operator-(matrix other) {
    assert(m == other.m && n == other.n);
    matrix s = mat;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s.mat[i][j] -= other.mat[i][j];
        s.mat[i][j] %= mod;
      }
    }
    return s;
  }

  matrix power(ll p) {
    // start with identity matrix
    matrix res = identity(n);
    matrix m = *this;
    while (p) {
      if (p & 1)
        res = res * m;
      m = m * m;
      p >>= 1;
    }
    return res;
  }

  ll det() {
    assert(n == m);
    if (n == 2)
      return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
    ll d = 0;
    int sign = 1;
    for (int i = 0; i < n; i++) {
      matrix submat(n - 1, n - 1);
      for (int j = 0; j < n - 1; j++) {
        int x = 0;
        for (int k = 0; k < n; k++) {
          if (i == k)
            continue;
          submat.mat[j][x++] = mat[j + 1][k];
        }
      }
      debug(sign * mat[0][i], submat.mat);
      d += sign * mat[0][i] * submat.det();
      sign *= -1;
    }

    return d;
  }

  static matrix identity(int size) {
    matrix I = vvll(size, vector<ll>(size));
    for (int i = 0; i < size; i++)
      I.mat[i][i] = 1;
    return I;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  ll n;
  cin >> n;

  matrix ini = vvll{{1}, {0}};
  matrix mat = vvll{{3, 1}, {1, 3}};

  cout << (mat.power(n) * ini).mat[0][0] << endl;

  return 0;
}
