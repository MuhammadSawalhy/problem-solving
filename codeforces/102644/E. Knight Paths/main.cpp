// Date: 21-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef vector<vector<unsigned int>> vvll;
struct matrix {
  vvll mat;
  int n, m;

  matrix(int n, int m) : n(n), m(m) { mat = vvll(n, vector<unsigned int>(m)); }

  matrix(vvll mat) : mat(mat) {
    n = mat.size();
    m = mat[0].size();
  }

  matrix operator*(matrix other) {
    assert(m == other.n);
    matrix mult = vvll(n, vector<unsigned int>(other.m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < other.m; j++) {
        for (int k = 0; k < m; k++) {
          mult.mat[i][j] += (mat[i][k]) * (other.mat[k][j]);
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
      }
    }
    return s;
  }

  matrix power(unsigned int p) {
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

  static matrix identity(int size) {
    matrix I = vvll(size, vector<unsigned int>(size));
    for (int i = 0; i < size; i++)
      I.mat[i][i] = 1;
    return I;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  unsigned int k;
  cin >> k;

  matrix M(vector<vector<unsigned int>>(65, vector<unsigned int>(65)));
  matrix inistate(vector<vector<unsigned int>>(65, vector<unsigned int>(1, 1)));
  inistate.mat[64][0] = 0;
  M.mat[64][0] = 1;
  M.mat[64][64] = 1;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        for (int l = 0; l < 8; l++) {
          if (abs((k - i) * (l - j)) == 2) {
            M.mat[i * 8 + j][k * 8 + l] = 1;
          }
        }
      }
    }
  }

  cout << (M.power(k + 1) * inistate).mat[64][0] << endl;
  return 0;
}
