// ----------------------------------------------------------------------------
// Problem : D. Count Paths
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

constexpr int mod = 1000000007;

struct Z {
private:
  // assume -P <= x < 2P
  int norm(int x) const {
    if (x < 0)
      x += mod;
    if (x >= mod)
      x -= mod;
    return x;
  }

public:
  int x;
  Z(int x = 0) : x(norm(x)) {}
  Z(ll x) : x(norm(x % mod)) {}
  int val() const { return x; }
  Z operator-() const { return Z(norm(mod - x)); }
  Z inv() const {
    assert(x != 0);
    return power(mod - 2);
  }
  Z power(Z b) const {
    Z res = 1;
    Z a = x;
    for (; b.x; a *= a, b.x >>= 1) {
      if (b.x % 2)
        res *= a;
    }
    return res;
  }
  Z &operator*=(const Z &rhs) {
    x = ll(x) * rhs.x % mod;
    return *this;
  }
  Z &operator+=(const Z &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  friend Z operator*(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator+(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator/(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
  friend std::istream &operator>>(std::istream &is, Z &a) {
    ll v;
    is >> v;
    a = Z(v);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const Z &a) {
    return os << a.val();
  }
};

typedef vector<vector<ll>> matrix;
struct matrix_expo {
  // it must be square matrix
  matrix mat;
  matrix_expo(matrix mat) : mat(mat){};

  matrix_expo operator*(matrix_expo m) {
    assert(mat[0].size() == m.mat.size());
    matrix_expo mult = matrix(mat.size(), vector<long long>(m.mat[0].size()));
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < m.mat[0].size(); j++) {
        for (int k = 0; k < m.mat.size(); k++) {
          mult.mat[i][j] += mat[i][k] * m.mat[k][j] % mod;
          mult.mat[i][j] %= mod;
        }
      }
    }
    return mult;
  }

  matrix_expo power(long long n) {
    // start with identity matrix
    matrix_expo res(matrix(mat.size(), vector<ll>(mat.size())));
    for (int i = 0; i < mat.size(); i++)
      res.mat[i][i] = 1;
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

  int n, m, k;
  cin >> n >> m >> k;
  matrix mat(n, vector<ll>(n));

  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b, a--, b--;
    // a contributes to the next state of b
    mat[b][a] = 1;
  }

  matrix_expo paths(mat);
  matrix_expo ini_paths(matrix(n, vector<ll>(1, 1)));
  paths = paths.power(k) * ini_paths;
  Z ans = 0;
  for (int i = 0; i < n; i++)
    ans += paths.mat[i][0];
  cout << ans << endl;
  return 0;
}
