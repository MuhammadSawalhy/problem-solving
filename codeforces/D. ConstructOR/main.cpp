// Date: 27-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

ll mod = 1000000007;

struct Z {
  private:
  // assume -P <= x < 2P
  ll norm(ll x) const {
    return (x % mod + mod) % mod;
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
      if (b.x & 1)
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

void solve() {
  ll a, b, d;
  cin >> a >> b >> d;
  debug(a, b, d);

  if ((d & -d) > (a & -a) || (d & -d) > (b & -b)) {
    cout << -1 << endl;
    return;
  }

  int shift = 0;
  while ((1 << shift & d) == 0) {
    shift++;
  }

  d >>= shift;
  a >>= shift;
  b >>= shift;

  mod = d;
  ll kk = (-Z((a | b))).x;
  Z two = 2;
  Z d_plus_one_halfed = (d + 1) / 2;
  for (int i = 2; i <= 30 - shift; i++) {
    d_plus_one_halfed *= (d + 1) / 2;
    two *= 2;
  }
  Z k = kk * d_plus_one_halfed;
  assert((k * two).x == kk);// should be the same
  ll x = (ll)k.x << (30 - shift) | a | b;
  assert(x % d == 0);
  cout << (x << shift) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
