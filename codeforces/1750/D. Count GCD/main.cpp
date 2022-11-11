// Date: 06-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
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

void solve() {
  int n, m;
  cin >> n >> m;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> primes;

  int first = a[0];
  for (int i = 2; i * i <= first; i += i & 1, i++) {
    if (first % i == 0) {
      primes.push_back(i);
      while (first % i == 0)
        first /= i;
    }
  }

  if (first != 1)
    primes.push_back(first);

  Z ans = 1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] % a[i] != 0) {
      cout << 0 << endl;
      return;
    }

    int x = a[i - 1] / a[i];
    int y = m / a[i];

    vector<int> xprimes;
    for (auto p: primes) {
      if (x % p == 0) {
        xprimes.push_back(p);
      }
    }

    Z cop = 0;

    for (int mask = 0; mask < (1 << (int) xprimes.size()); mask++) {
      int cnt = 0;

      int f = 1;
      for (int i = 0; i < xprimes.size(); i++) {
        if (!((1 << i) & mask))
          continue;
        f *= xprimes[i];
        cnt++;
      }

      cop += (ll)(cnt & 1 ? -1 : 1) * y / f;
    }

    // question 1:
    //   -> who to get number of coprimes of x that are <= y?
    //
    // observations:
    //   -> let's say that I have the primes of a[i - 1],
    //      we can get the primes of a[i] in 9 steps at most
    //   -> if I have primes of a[i - 1] I can get primes of x
    //   -> I can calc no. of non-coprimes then cop = (y - noncop)
    //      or directly calc cop with inclusion exclusion principle
    //   -> I need the primes factors then do it in 2 ^ 9 at most

    ans *= cop;

    vector<int> next_primes;
    for (auto p: primes)
      if (a[i] % p == 0)
        next_primes.push_back(p);
    primes = next_primes;
  }

  cout << ans << endl;
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
