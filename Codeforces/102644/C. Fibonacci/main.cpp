// ----------------------------------------------------------------------------
// Problem : C. Fibonacci
// Author  : Muahmmad Assawalhy
// Date    : 07-09-22
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

constexpr int mod = 1e9 + 7;

struct matrix_expo {
  typedef vector<vector<long long>> matrix;
  // it must be square matrix
  matrix mat;
  matrix_expo(matrix mat) : mat(mat) { assert(mat.size() == mat[0].size()); };

  matrix_expo operator*(matrix_expo m) {
    int s = mat.size();
    matrix_expo mult = matrix(s, vector<long long>(s));
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        for (int k = 0; k < s; k++) {
          mult.mat[i][j] += mat[i][k] * m.mat[k][j] % mod;
          mult.mat[i][j] %= mod;
        }
      }
    }
    return mult;
  }

  matrix_expo power(long long n) {
    matrix_expo res({{1, 0}, {0, 1}});
    matrix_expo m = *this;
    while (n) {
      if (n & 1)
        res = res * m;
      m = m * m;
      n >>= 1;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  matrix_expo fib({{0, 1}, {1, 1}});
  fib = fib.power(n);
  cout << fib.mat[0][1] << endl;
  return 0;
}
