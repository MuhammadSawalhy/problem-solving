// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

template<typename T = void>
struct OtherType {
    typedef ll type;
};

template<>
struct OtherType<ll> {
    typedef __int128 type;
};

template<typename T, T mod, typename V = typename OtherType<T>::type>
struct mint {
private:
    T norm(T x) const {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
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
            if (b & 1) res *= a;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (V) x * rhs.x % mod;
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
    friend mint max(mint a, mint b) {
        return a.x > b.x ? a : b;
    }
    friend mint min(mint a, mint b) {
        return a.x < b.x ? a : b;
    }
};

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

vector<Z> fact = {1};
vector<Z> fact_inv = {1};

void build_fact(int n = 1e6) {
    while ((int) fact.size() < n + 1)
        fact.push_back(fact.back() * (int) fact.size());
    fact_inv.resize(fact.size());
    fact_inv.back() = fact.back().inv();
    for (int j = fact_inv.size() - 2; fact_inv[j].x == 0; j--)
        fact_inv[j] = fact_inv[j + 1] * (j + 1);
}

Z ncr(int n, int r) {
    if (r > n || r < 0) return 0;
    if ((int) fact.size() < n + 1) build_fact(n);
    return fact[n] * fact_inv[r] * fact_inv[n - r];
}

Z calc(int k, vector<int> &seeds) {
    int fixed = 0, elem_fixed = 0, nonelem_fixed = 0;
    debug(seeds);
    set<int> elem, nonelem;
    for (int i = 1 << (k - 1); i < 1 << k; i++) {
        if (seeds[i] != -1) {
            elem.insert((seeds[i] + 1) / 2);
            elem_fixed++;
        }
    }
    for (int i = 0; i < 1 << (k - 1); i++) {
        if (seeds[i] != -1) {
            nonelem.insert((seeds[i] + 1) / 2);
            nonelem_fixed++;
        }
    }
    set<int> boxes;
    for (int i = 0; i < 1 << k; i++) {
        if (seeds[i] != -1)
            boxes.insert((seeds[i] + 1) / 2);
    }
    if (elem.size() != elem_fixed || nonelem.size() != nonelem_fixed) return 0;
    fixed = boxes.size();
    assert(fixed <= (1 << (k - 1)));
    debug(fixed);

    return Z(2).power((1 << (k - 1)) - fixed) * fact[(1 << (k - 1)) - elem_fixed];
}

void solve() {
    int k;
    cin >> k;
    build_fact(1 << (k + 1));

    vector<int> seeds(1 << k, -1);
    for (int i = 0; i < 1 << k; i++) {
        int team;
        cin >> team;
        if (team != -1)
            seeds[team - 1] = i + 1;
    }

    Z ans = 1;
    while (k) {
        Z v = calc(k--, seeds);
        debug(k, v);
        ans *= v;
        for (int i = 0; i < 1 << k; i++) {
            if (seeds[i] != -1)
                seeds[i] = (seeds[i] + 1) / 2;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
