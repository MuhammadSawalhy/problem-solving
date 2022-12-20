// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

constexpr int mod = 998244353;

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
    x = (ll) x * rhs.x % mod;
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

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<Z> nonsplitting(n + 1);
  vector<Z> dp(n + 1);
  nonsplitting[0] = 1;
  dp[0] = 1;

  for (int i = 2; i <= n; i += 2) {
    nonsplitting[i] = Z(m).power(i / 2);
    for (int j = 2; j <= i / 2; j += 2) {
      nonsplitting[i] -= nonsplitting[i - 2 * j] * dp[j];
    }

    for (int j = 2; j <= i; j += 2) {
      // how to make it good but with no slicing possible in the part with j length at the edge
      // so that edge part will be palindrome itself with no sub-palindromes
      dp[i] += dp[i - j] * nonsplitting[j];
      debug(i, j, nonsplitting[j]);
    }
  };

  debug(dp);
  cout << dp[n] << endl;
  return 0;
}
