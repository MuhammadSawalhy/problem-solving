// ﷽
// https://cses.fi/problemset/task/2080

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int n, k1, k2;

const int N = 2e5 + 5;
vi edges[N];
int par[N], siz[N], fr[N], lazy[N];
bool removed[N];

struct Centroids {
    int n;

    Centroids(int n) : n(n) {}

    void add_edge(int a, int b) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void find_size(int i, int p = -1) {
        siz[i] = 1;
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            find_size(j, i), siz[i] += siz[j];
        }
    }

    int find_centroid(int i, int p, int n) {
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            if (siz[j] > n / 2) return find_centroid(j, i, n);
        }
        return i;
    }

    int mx;

    int calc(int i, int p, int d) {
        if (d > k2) return 0;
        // apply lazy updates
        int l = k1 - d, r = k2 - d;
        int ans = l > mx ? 0 : fr[min(mx, r)] - (l > 0 ? fr[l - 1] : 0);
        debug(i, ans);
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            ans += calc(j, i, d + 1);
            if (p == -1) {
                add(j, i, d + 1);
                for (int i = 0; i <= mx; i++) {
                    lazy[i + 1] += lazy[i];
                    fr[i] += lazy[i];
                    lazy[i] = 0;
                }
                assert(lazy[mx + 1] == fr[mx]);
            }
        }
        return ans;
    }

    void add(int i, int p, int d) {
        if (d > k2) return;
        maxit(mx, d); // changes applied up to mx
        lazy[d]++;
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            add(j, i, d + 1);
        }
    }

    int build(int v = 0, int p = -1) {
        find_size(v);
        int c = find_centroid(v, -1, siz[v]);
        mx = 0, lazy[1] = fr[0] = 1;
        debug(c);
        int ans = calc(c, -1, 0);
        for (int i = 0; i <= siz[v]; i++) fr[i] = lazy[i] = 0;
        removed[c] = true, par[c] = p;

        for (int x: edges[c])
            if (!removed[x]) ans += build(x, c);
        return ans;
    }
};

char in[1 << 24];
struct Scanner {
    char const *o;
    Scanner() : o(in) { load(); }
    void load() { in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; }
    unsigned readInt() {
        unsigned u = 0;
        while (*o && *o <= 32) ++o;
        while (*o >= '0' && *o <= '9')
            u = u * 10 + (*o++ - '0');
        return u;
    }
    unsigned readDigit() {
        while (*o && *o <= 32) ++o;
        if (*o >= '0' && *o <= '9')
            return *o++ - '0';
        assert(false);
    }
} sc;

void solve() {
    n = sc.readInt(), k1 = sc.readInt(), k2 = sc.readInt();

    Centroids G(n);
    for (int i = 0; i < n - 1; i++) {
        int a = sc.readInt(), b = sc.readInt();
        a--, b--;
        G.add_edge(a, b);
    }

    int ans = G.build();
    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
