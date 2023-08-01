// ﷽
// https://codeforces.com/group/ARb1vgiFev/contest/465051/problem/L
// Codeforces -> Team Contest #9 2023 -> L. Loop Invariant

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

template <typename T = void> struct OtherType { typedef ll type; };

template <> struct OtherType<ll> { typedef __int128 type; };

template <typename T, T mod, typename V = typename OtherType<T>::type>
struct mint {
private:
  T norm(T x) const {
    if (x < 0)
      x += mod;
    if (x >= mod)
      x -= mod;
    return x;
  }

public:
  T x;
  T val() const { return x; }
  mint(V x = 0) : x(norm(x % mod)) {}
  mint operator-() const { return mint(norm(mod - x)); }
  mint inv() const {
    assert(x != 0);
    return power(mod - 2);
  }
  mint power(T b) const {
    mint res = 1, a = x;
    for (; b; b >>= 1, a *= a) {
      if (b & 1)
        res *= a;
    }
    return res;
  }
  mint &operator*=(const mint &rhs) {
    x = (V)x * rhs.x % mod;
    return *this;
  }
  mint &operator+=(const mint &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res *= rhs;
    return res;
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res += rhs;
    return res;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res -= rhs;
    return res;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res /= rhs;
    return res;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.x == rhs.x;
  }
  friend std::istream &operator>>(std::istream &is, mint &a) {
    T v;
    return is >> v, a = mint(v), is;
  }
  friend std::ostream &operator<<(std::ostream &os, const mint &a) {
    return os << a.val();
  }
  friend mint max(mint a, mint b) { return a.x > b.x ? a : b; }
  friend mint min(mint a, mint b) { return a.x < b.x ? a : b; }
};

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

class Hash {
public:
  // change M and B if you want
  static const ll M = (1LL << 61) - 1;
  static const ll B;

  // pow[i] contains P^i % M
  static vector<mint<ll, M>> pow;
  // hash of the prefixes
  vector<mint<ll, M>> p_hash;

public:
  Hash(const string &s) : p_hash(s.size() + 1) {
    while (pow.size() < (int)s.size())
      pow.push_back(pow.back() * B);
    for (int i = 0; i < s.size(); i++)
      p_hash[i + 1] = p_hash[i] * B + s[i];
  }

  /** get the have in [start, end] substring (0-based) */
  auto get(int start, int end) {
    auto raw_val = p_hash[end + 1] - p_hash[start] * pow[end - start + 1];
    return raw_val;
  }
};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<mint<ll, Hash::M>> Hash::pow = {1};
const ll Hash::B = uniform_int_distribution<ll>(0, M - 1)(rng);

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  string s;
  cin >> s;
  int n = s.length();

  Hash hash(s);

  int val = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '(')
      val++;
    else
      val--;
    if (val == 0) {
      auto a = hash.get(0, i);
      auto b = hash.get(i + 1, n - 1) * Hash::pow[i + 1];
      if ((a + b).x != hash.get(0, n - 1).x) {
        cout << s.substr(i + 1) + s.substr(0, i + 1) << endl;
        return 0;
      }
    }
  }

  cout << "no\n";

  return 0;
}
