// Date: 28-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
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

vector<Z> fact(1, 1);
vector<Z> fact_inv(1, 1);

Z choose(int n, int k) {
  assert (n >= k && k >= 0);
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    fact_inv.push_back(1 / fact.back());
  }
  return fact[n] * fact_inv[k] * fact_inv[n - k];
}

void solve() {
  int n, k;
  cin >> n >> k;

  if (k == 0) {
    cout << Z(3).power(n) << endl;
    return;
  }

  Z ans = 0;

  for (int q = 1; q <= min({ n, 2 * k, 2 * (n - k) + 1 }); q++) {
    // some combinatorics here
    //                       (ones buckets, zeros ..)   (ones, zeros)
    // 1,     q = 1 -> MSB 1 -> 1 1                     -> (1 0)
    // 01,    q = 2 -> MSB 0 -> 1 2                     -> (1 1)
    // 101,   q = 3 -> MSB 1 -> 2 2                     -> (2 1)
    // 0101,  q = 4 -> MSB 0 -> 2 3                     -> (2 2)

    int ones_buckets = (q + 1) / 2, zeros_buckets = q / 2 + 1;
    int ones = k - (q + 1) / 2, zeros = n - q - ones;
    debug(q);
    Z cnt = choose(ones + ones_buckets - 1, ones) * choose(zeros + zeros_buckets - 1, zeros);
    ans += Z(3).power(n - q) * cnt;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
