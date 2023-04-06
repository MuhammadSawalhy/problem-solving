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

#define ll long long
#define all(v) v.begin(), v.end()

template<typename T>
struct Node {
    T mx;
    T sum;

    Node(T value = 0) : mx(value), sum(value) {}

    Node &operator+=(const Node &other) {
        sum += other.sum;
        mx = max(mx, other.mx);
        return *this;
    }

    Node operator+(const Node &other) const {
        Node res;
        res.mx = max(mx, other.mx);
        res.sum = sum + other.sum;
        return res;
    }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct segtree {
    int n;
    vector<Node<T>> tree;

    segtree(int n) : n(n) {
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

    Node<T> query(int l, int r) {
        Node<T> res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

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

constexpr int MOD = 1000000007;// 998244353
using Z = mint<int32_t, MOD>;

constexpr int N = 5005;
int n, k;

Z dp[N][N];
int c[N], fr[N][N];
segtree<int> sg(N);

int solve_max(int sz) {
    for (int i = n; i > 0; i--) {
        int j = lower_bound(fr[c[i]], fr[c[i]] + n + 1, fr[c[i]][i] + sz - 1) - fr[c[i]];
        if (j > n) {
            sg.update(i, 0);
        } else {
            int x = 0;
            if (j < n)
                x = sg.query(j + 1, n).mx;
            sg.update(i, x + sz);
        }
    }
    return sg.query(1, n).mx;
}

Z count(int sz) {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j].x = -1;

    

    return 0;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            fr[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        fr[c[i]][i] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fr[i][j] += fr[i][j - 1];

    int mx = solve_max(k);

    if (mx == 0) {
        cout << "1\n";
        return;
    }

    vector<int> withmx{k};

    for (int i = k + k; i <= mx; i += k) {
        if (solve_max(i) == mx) withmx.push_back(i);
    }

    debug(mx);

    Z ans = 0;
    for (auto sz : withmx)
        ans += count(sz);

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
