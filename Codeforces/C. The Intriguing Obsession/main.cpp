// Date: 29-09-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
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
  Z(long long x) : x(norm(x % mod)) {}
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
    x = (long long)x * rhs.x % mod;
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
    long long v;
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

Z doit(int a, int b) {
  Z r = 1;
  if (a > b)
    swap(a, b);

  Z perm = 1;
  for (int i = 1; i <= a; i++) {
    perm *= i;
    r += pascal[a][i] * pascal[b][i] * perm;
  }

  return r;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  Z ans = 0;
  ans = doit(a, b);
  ans *= doit(a, c);
  ans *= doit(b, c);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  build_pascal(5000);
  while (t_cases--) {
    solve();
  }
  return 0;
}
