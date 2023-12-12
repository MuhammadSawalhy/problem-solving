// ﷽
// https://codeforces.com/contest/716/problem/E

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
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 1e5 + 5;
int mod;
int power10[N], invpower10[N];

// source: https://codeforces.com/blog/entry/23365
// a and b must be co-prime. returns (1 / a) mod b.
ll mod_inv(ll a, ll b) {
    return 1 < a ? b - mod_inv(b % a, a) * b / a : 1;
}

struct Centroids {
    vector<vector<pair<int, int>>> edges;
    vector<bool> removed;
    vector<int> par;
    vector<int> sz;
    int n;
    int ans = 0;

    Centroids(int n) : n(n) {
        edges.resize(n), removed.resize(n);
        sz.resize(n), par.assign(n, -1);
    }

    void add_edge(int a, int b, int cost) {
        edges[a].push_back({b, cost});
        edges[b].push_back({a, cost});
    }

    void find_size(int v, int p = -1) {
        sz[v] = 1;
        for (auto [x, _]: edges[v]) {
            if (x == p || removed[x]) continue;
            find_size(x, v), sz[v] += sz[x];
        }
    }

    int find_centroid(int v, int p, int n) {
        for (auto [x, _]: edges[v]) {
            if (x == p || removed[x]) continue;
            if (sz[x] > n / 2) return find_centroid(x, v, n);
        }
        return v;
    }

    map<int, int> required;

    void update_required(int u, int p, int val, int d, int change) {
        required[val] += change;
        ans += val == 0;
        for (auto [x, cost]: edges[u]) {
            if (x == p || removed[x]) continue;
            update_required(x, u, (val + cost * power10[d]) % mod, d + 1, change);
        }
    }

    void calc_ans(int u, int p, int val, int d) {
        debug(u, val);
        ans += required[(mod - val) % mod];
        ans += val == 0;
        for (auto [x, cost]: edges[u]) {
            if (x == p || removed[x]) continue;
            calc_ans(x, u, (val + cost * invpower10[d]) % mod, d + 1);
        }
    }

    void build(int v = 0, int p = -1) {
        find_size(v);
        int c = find_centroid(v, -1, sz[v]);
        removed[c] = true, par[c] = p;
        required.clear();

        for (auto [x, cost]: edges[c])
            if (!removed[x])
                update_required(x, c, cost % mod, 1, 1);

        debug(c);
        debug(required);

        for (auto [x, cost]: edges[c])
            if (!removed[x]) {
                int y = ans;
                update_required(x, c, cost % mod, 1, -1);
                debug(x, required);
                ans = y;
                calc_ans(x, c, (cost * invpower10[1]) % mod, 2);
                y = ans;
                update_required(x, c, cost % mod, 1, 1);
                ans = y;
            }

        debug(c, ans);
        for (auto [x, _]: edges[c])
            if (!removed[x]) build(x, c);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n >> mod;

    Centroids cen(n);
    for (int i = 0, a, b, c; i < n - 1; i++) {
        cin >> a >> b >> c;
        cen.add_edge(a, b, c);
    }

    invpower10[1] = mod_inv(10, mod), power10[1] = 10;
    invpower10[0] = power10[0] = 1;
    for (int i = 2; i < N; i++) {
        power10[i] = (power10[i - 1] * 10) % mod;
        invpower10[i] = (invpower10[i - 1] * invpower10[1]) % mod;
    }

    cen.build();

    cout << cen.ans << endl;

    return 0;
}
