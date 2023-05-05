// ﷽
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
        if (x < 0)
            x = x % mod + mod;
        if (x >= mod)
            x %= mod;
        return x;
    }

public:
    T x;
    T val() const { return x; }
    mint(T x = 0) : x(norm(x)) {}
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
        is >> v;
        a = mint(v);
        return is;
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

template<typename T = long long>
struct Sum {
    T value;
    Sum(T value = 0) : value(value) {}
    Sum &operator+=(const Sum &other) { return value += other.value, *this; }
    Sum operator+(const Sum &other) const { return value + other.value; }
};

template<typename T = long long>
struct Max {
    T value;
    Max(T value = numeric_limits<T>::min() / 2) : value(value) {}
    Max &operator+=(const Max &other) { return value = max(value, other.value), *this; }
    Max operator+(const Max &other) const { return Max(max(value, other.value)); }
};

template<typename T = long long>
struct Min {
    T value;
    Min(T value = numeric_limits<T>::max() / 2) : value(value) {}
    Min &operator+=(const Min &other) { return value = min(value, other.value), *this; }
    Min operator+(const Min &other) const { return Min(min(value, other.value)); }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct Segtree {
    int n;
    vector<T> tree;

    Segtree() = default;
    Segtree(int n) : n(n) {
        tree.resize(n * 2);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    auto query(int l, int r) {
        T res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res.value;
    }
};

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;
const int N = 2e5 + 5;

Z p2[N];

void solve() {
    ll n, k;
    cin >> n >> k;

    ll a[n];
    map<ll, int> fr;
    Segtree<Min<ll>> mn(n);
    Segtree<Max<ll>> mx(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
        mn.update(i, a[i]);
        mx.update(i, a[i]);
    }

    vector<int> b(fr.size()), f(fr.size());
    int sz = 0;
    for (auto [x, y]: fr)
        b[sz] = x, f[sz] = y, sz++;

    Z subarr = 0, subseq = 0;

    for (int i = 0; i < n; i++) {
        int s = -1, e = i;
        while (e - s > 1) {
            int mid = (s + e) / 2;
            ll x = mn.query(mid, i);
            ll y = mx.query(mid, i);
            if (abs(x - y) > k)
                s = mid;
            else
                e = mid;
        }

        subarr += (i - e + 1);
    }

    Z prod[sz + 1];
    prod[sz] = 1;

    for (int i = sz - 1; i > -1; i--) {
        prod[i] = prod[i + 1] * p2[f[i]];
    }

    for (int i = 0; i < sz; i++) {
        int j = upper_bound(all(b), b[i] + k) - b.begin();
        subseq += prod[i + 1] / prod[j] * (p2[f[i]] - 1);
    }

    cout << subarr << ' ' << subseq << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    p2[0] = 1;

    for (int i = 1; i < N; i++)
        p2[i] = p2[i - 1] * 2;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
