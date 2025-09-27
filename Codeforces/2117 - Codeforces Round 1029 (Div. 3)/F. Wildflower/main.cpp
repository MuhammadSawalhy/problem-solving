#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

template<int32_t mod>
struct mint {
    using Z = mint;
    int32_t x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    inline int32_t norm(int32_t x) const {
        return x >= mod ? x - mod : (x < 0 ? x + mod : x);
    }
    Z power(ll b) const {
        assert(b >= 0);
        Z res = 1, a = x;
        for (; b; b >>= 1, a *= a)
            if (b & 1) res *= a;
        return res;
    }
    Z inv() const { return assert(x != 0), power(mod - 2); }
    Z operator-() const { return -x; }
    Z &operator*=(const Z &r) { return *this = (ll) x * r.x; }
    Z &operator+=(const Z &r) { return *this = x + r.x; }
    Z &operator-=(const Z &r) { return *this = x - r.x; }
    Z &operator/=(const Z &r) { return *this *= r.inv(); }
    friend Z operator*(const Z &l, const Z &r) { return Z(l) *= r; }
    friend Z operator+(const Z &l, const Z &r) { return Z(l) += r; }
    friend Z operator-(const Z &l, const Z &r) { return Z(l) -= r; }
    friend Z operator/(const Z &l, const Z &r) { return Z(l) /= r; }
    friend ostream &operator<<(ostream &os, const Z &a) { return os << a.x; }
    friend istream &operator>>(istream &is, Z &a) {
        ll y = 0;
        return is >> y, a = y, is;
    }
};

#define MOD 1000000007
using Z = mint<MOD>;


void solve() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int one = 0;
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1) one++;

    if (one - (adj[0].size() == 1) > 2) {
        cout << 0 << endl;
        return;
    }

    if (one - (adj[0].size() == 1) == 1) {
        cout << Z(2).power(n) << endl;
        return;
    }

    Z ans = 1;

    vector<int> vis(n);
    int root = 0;

    if (adj[root].size() == 1) {
        while (adj[root].size() != 3) {
            vis[root] = true;
            ans *= 2;
            for (auto j: adj[root]) {
                if (vis[j]) continue;
                root = j;
            }
        }
    }

    vis[root] = true;
    ans *= 2;
    int i = -1, j = -1;
    for (auto v: adj[root]) {
        if (vis[v]) continue;
        if (i == -1) i = v;
        else j = v;
    }

    assert(~i && ~j);

    int cnti = 0;
    int cntj = 0;

    while (true) {
        cnti++;
        vis[i] = true;
        if (adj[i].size() == 1) break;
        for (auto v: adj[i]) {
            if (vis[v]) continue;
            i = v;
        }
    }

    while (true) {
        cntj++;
        vis[j] = true;
        if (adj[j].size() == 1) break;
        for (auto v: adj[j]) {
            if (vis[v]) continue;
            j = v;
        }
    }


    debug(cnti, cntj);

    auto calc = [&]() -> Z {
        int one = cnti, two = cntj;
        if (one <= two) return Z(2).power(two - one);
        return Z(2).power(one - two - 1);
    };

    Z ext = calc();
    swap(cnti, cntj);
    ext += calc();


    cout << ans * ext << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
