// Date: 24-09-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

constexpr long long mod = 1e9 + 7;

typedef vector<vector<long long>> vvll;
struct matrix {
  vvll mat;
  int n, m;

  matrix(vvll mat) : mat(mat) {
    n = mat.size();
    m = mat[0].size();
  }

  matrix(int n, int m) : n(n), m(m) { mat = vvll(n, vector<long long>(m)); }

  matrix operator*(matrix other) {
    assert(m == other.n);
    matrix mult = vvll(n, vector<long long>(other.m));
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

  matrix power(long long p) {
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

  long long det() {
    assert(n == m);
    if (n == 2)
      return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
    long long d = 0;
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
    matrix I = vvll(size, vector<long long>(size));
    for (int i = 0; i < size; i++)
      I.mat[i][i] = 1;
    return I;
  }
};

void solve() {
  long long d12, d13, d14, d23, d24, d34;
  cin >> d12 >> d13 >> d14 >> d23 >> d24 >> d34;
  d12 *= d12;
  d13 *= d13;
  d14 *= d14;
  d23 *= d23;
  d24 *= d24;
  d34 *= d34;
  matrix m = vvll({{000, 001, 001, 001, 001},
                   {001, 000, d12, d13, d14},
                   {001, d12, 000, d23, d24},
                   {001, d13, d23, 000, d34},
                   {001, d14, d24, d34, 000}});
  cout << setprecision(14);
  cout << sqrt((double)m.det() / 288.0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
