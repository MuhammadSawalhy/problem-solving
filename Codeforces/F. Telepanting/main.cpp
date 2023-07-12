// ----------------------------------------------------------------------------
// Problem : F. Telepanting
// Author  : Muahmmad Assawalhy
// Date    : 13-09-22
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x[n + 1];
  int y[n + 1];
  bool s[n + 1];
  vector<Z> rtime(n + 1, 0);
  x[0] = 0;

  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i] >> s[i];

  Z ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += x[i] - x[i - 1];
    int j = lower_bound(x, x + n, y[i]) - x;
    rtime[i] = x[i] - y[i];
    rtime[i] += rtime[i - 1];
    rtime[i] -= rtime[j - 1];
    if (s[i])
      ans += rtime[i];
    rtime[i] += rtime[i - 1];
  }

  ans += 1;
  cout << ans << endl;

  return 0;
}
