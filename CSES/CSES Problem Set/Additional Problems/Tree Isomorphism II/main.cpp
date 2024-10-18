// ﷽
// https://cses.fi/problemset/task/1700

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int H = 2;
typedef array<long long, H> val;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 998244353,
        // 1000000009,
};

val tmp;

val operator*(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = a[i] * b[i] % M[i];
    return tmp;
}

val operator-(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] - b[i] + M[i]) % M[i];
    return tmp;
}

val operator+(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] + b[i]) % M[i];
    return tmp;
}

val getval(int x) {
    for (int i = 0; i < H; i++) tmp[i] = x % M[i];
    return tmp;
}

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, getval(1));
        for (int i = 0; i < H; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1]);
}

struct Hash {
    vector<val> h;

    Hash(const string &s) : Hash(vector<int>(s.begin(), s.end())) {}

    Hash(const vector<int> &s) {
        vector<val> v;
        for (auto x: s) v.push_back(getval(x));
        *this = Hash(v);
    }

    Hash(const vector<val> &s) : h(s.size() + 1) {
        setB(s.size());
        for (int i = 0; i < (int) s.size(); i++)
            h[i + 1] = h[i] * B[1] + s[i];
    }

    val get(int l, int r) { return h[r + 1] - h[l] * B[r - l + 1]; }
};

const int N = 2e5 + 5;
int vals[N];
map<val, int> mp;

int gethashnum(val children_hash) {
    if (mp.find(children_hash) == mp.end()) {
        mp[children_hash] = (int) mp.size() + 1;
    }
    return mp[children_hash];
}

int calc(int u, int p, vvi &adj) {
    vector<int> cur;

    for (int v: adj[u]) {
        if (v == p) continue;
        cur.push_back(calc(v, u, adj));
    }

    val children_hash = getval(0);

    if (cur.size()) {
        sort(all(cur));
        Hash h(cur);
        children_hash = h.get(0, cur.size() - 1);
    }

    return vals[u] = gethashnum(children_hash);
}

void dfs(int u, int p, int up, vvi &adj, set<int> &s) {
    vector<int> cur;
    ordered_set<pair<int, int>> nodes;

    for (int v: adj[u]) {
        if (v == p) continue;
        cur.push_back(vals[v]);
        nodes.insert({vals[v], v});
    }

    if (up != -1) {
        cur.push_back(up);
        nodes.insert({up, p});
    }

    sort(all(cur));
    Hash h(cur);

    s.insert(gethashnum(h.get(0, cur.size() - 1)));

    for (int v: adj[u]) {
        if (v == p) continue;
        int i = (int) nodes.order_of_key({vals[v], v});
        val down = i - 1 >= 0 ? h.get(0, i - 1) : getval(0);
        if (i + 1 < cur.size()) {
            down = down * B[cur.size() - i - 1] + h.get(i + 1, cur.size() - 1);
        }

        dfs(v, u, gethashnum(down), adj, s);
    }
}

void solve() {
    int n;
    cin >> n;

    vvi adj1(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    vvi adj2(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    calc(1, 0, adj1);
    int x = vals[1];
    debug_itr(vals, n + 1);

    set<int> y;
    calc(1, 0, adj2);
    dfs(1, 0, -1, adj2, y);
    debug_itr(vals, n + 1);

    debug(x);
    debug(y);

    if (y.count(x)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    setB(3e5);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
