// ----------------------------------------------------------------------------
// Problem : B. Buses
// Author  : Muahmmad Assawalhy
// Date    : 15-09-22
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, int>> t;
  priority_queue<pair<int, int>> s;

  vector<int> vals(m + 1);

  Z val = 0;
  for (int i = 1; i <= m; i++) {
    int ss, tt;
    cin >> ss >> tt;
    t.push({tt, i});
    s.push({ss, i});
  }

  while (!t.empty() && t.top().first == n) {
    vals[t.top().second] = 1;
    val += 1;
    t.pop();
  }

  while (!t.empty()) {
    int tt = t.top().first;
    // remove unreachable buses, in a stop front of the current
    while (!s.empty() && s.top().first > tt) {
      val -= vals[s.top().second];
      s.pop();
    }

    // go to the previos bus stop
    int cnt = 0;
    while (!t.empty() && t.top().first == tt) {
      vals[t.top().second] = val.x;
      cnt++;
      t.pop();
    }
    val += val * cnt;
  }

  // remove unreachable buses, in a stop front of the current
  while (!s.empty() && s.top().first > 0) {
    val -= vals[s.top().second];
    s.pop();
  }

  cout << val << endl;
  return 0;
}
