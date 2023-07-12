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

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> adj[n];

    if (k == 1) {
        cout << "1\n";
        return;
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cnt(n);

    function<void(int, int)> dfs = [&](int i, int p) {
        for (auto j: adj[i]) {
            if (j == p) continue;
            dfs(j, i);
            cnt[i] += cnt[j] + 1;
        }
    };

    int start = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            start = i;
            break;
        }
    }

    assert(~start);
    dfs(start, start);

    Z total = 0;
    function<void(int, int)> calc2 = [&](int i, int p) {
        vector<int> mine{n - cnt[i] - 1};
        for (auto j: adj[i]) {
            if (j == p) continue;
            calc2(j, i);
            mine.push_back(cnt[j] + 1);
        }

        Z sum = 0;
        for (auto x: mine) {
            total += sum * x;
            sum += x;
        }
    };

    if (k == 2) {
        calc2(start, start);
        total += n * (n - 1);
        cout << total / (n * (n - 1) / 2) << endl;
        return;
    }

    function<void(int, int)> calc3 = [&](int i, int p) {
        vector<int> mine{n - cnt[i] - 1};
        for (auto j: adj[i]) {
            if (j == p) continue;
            calc3(j, i);
            mine.push_back(cnt[j] + 1);
        }

        Z sum = 0;
        Z two = 0;
        debug(i, mine);
        for (auto x: mine) {
            total += two * x;
            two += sum * x;
            sum += x;
        }
    };

    calc2(start, start);
    debug(total);
    calc3(start, start);
    debug(total);

    cout << total / (n * (n - 1) * (n - 2) / 6) << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
