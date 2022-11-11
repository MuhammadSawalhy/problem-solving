// Date: 21-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

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
    x = (ll)x * rhs.x % mod;
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

vector<vector<Z>> pascal;
void build_pascal(int d) {
  pascal = {{1}};
  while (d--) {
    vector<Z> &lastrow = pascal.back();
    int s = lastrow.size();
    vector<Z> newrow(s + 1);
    newrow.front() = 1;
    newrow.back() = 1;
    for (int i = 1; i < s; i++)
      newrow[i] = lastrow[i] + lastrow[i - 1];
    pascal.push_back(newrow);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<Z> dp(k + 1);
  build_pascal(k);

  for (int i = 2; i <= k; i++) {
    dp[i] = Z(i - 1).power(n - 1) * i; // all possibilities
    for (int j = 2; j < i; j++) {
      // cancel possibilities with less than i colors
      dp[i] -= dp[j] * pascal[i][j];
    }
  }

  cout << dp[k] << endl;

  return 0;
}
