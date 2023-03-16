// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <utility>
#include <vector>
#include <functional>
#include <assert.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

template<int mod>
struct mint {
private:
    // assume -P <= x < 2P, (it's faster)
    int norm(int x) const {
        if (x < 0)
            x += mod;
        if (x >= mod)
            x -= mod;
        return x;
    }

public:
    int x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    mint power(ll b) const {
        mint res = 1, a = x;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (ll) x * rhs.x % mod;
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
    friend std::istream &operator>>(std::istream &is, mint &a) {
        ll v;
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

constexpr int MOD = 998244353;// 1000000007
using Z = mint<MOD>;

// clang-format off
template <typename T> struct Node {
    T value = 0;
    ll relative_update = 0;
    bool pending_update = false;
    Node(){};
    Node(T value) : value(value){};

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void update(const T &val) {
        value = val;
        relative_update = 0;
        pending_update = true;
    }

    void relupdate(const T &val) {
        relative_update += val;
    }

    void propagate(int node, vector<Node<T>> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        if (pending_update) {
            if (left < sz) {
                tree[left].value = value;
                tree[left].relative_update = 0;
                tree[left].pending_update = true;
            }
            if (right < sz) {
                tree[right].value = value;
                tree[right].relative_update = 0;
                tree[right].pending_update = true;
            }
            pending_update = false;
        }

        value += count_children(node, sz) * relative_update;
        if (left < sz)
            tree[left].relative_update += relative_update;
        if (right < sz)
            tree[right].relative_update += relative_update;
        relative_update = 0;
    }

    friend ostream& operator<<(ostream &cout, const Node<T> &n) {
        cout << "(value: " << n.value << ", rel: " << n.relative_update << ")";
        return cout;
    }
};

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

Z choose(int n, int r) {
    if (r > n || r < 0) return 0;
    if ((int) fact.size() < n + 1) build_fact(n);
    return fact[n] * fact_inv[r] * fact_inv[n - r];
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    int when[n + k + 1];
    when[0] = 0;
    for (int i = 1; i <= n + k; i++) {
        if (s.count(i - 1)) {
            when[i] = when[i - 1];
        } else {
            when[i] = when[i - 1] + 1;
        }
    }

    Z ans = 0;
    for (int i = 0; i <= n + k; i++) {
        int x = k - when[i] - 1;
        if (x < 0) break;
        ans += choose(x + i, i);
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
