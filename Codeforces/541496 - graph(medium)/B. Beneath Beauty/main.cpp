#include <bits/stdc++.h>
#pragma gcc optimize("Ofast,unroll-loops")
using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int) v.size()
#define cout(v)                         \
    for (auto el: v) cout << el << " "; \
    cout << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Ones(n) __builtin_popcount(n)
#define Onesll(n) __builtin_popcountll(n)

ll MOD = 1e9 + 7;

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) {}
};

mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}

mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}

mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }

mi poww(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : poww(a * a, p / 2) * (p & 1 ? a : 1);
}

mi inv(mi a) {
    assert(a.v != 0);
    return poww(a, MOD - 2);
}

mi operator/(mi a, mi b) { return a * inv(b); }
bool prime(long long n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    ll d = sqrtl(n);
    for (ll i = 3; i <= d; i += 2)
        if (n % i == 0) return false;
    return true;
}

string to_binary(long long x) {
    string s = "";
    while (x) {
        long long d = x % 2;
        char c = d + '0';
        s += c;
        x /= 2;
    }
    return s;
}

long long to_dec(string s) {
    long long su = 0;
    int d = 0;
    for (long long i = 0; i < (s.size()); i++) {
        if (s[i] == '0') continue;
        long long q = round(pow(2LL, i));
        su += q;
    }
    return su;
}

vector<ll> pri;

const int N = 2e5 + 5;
ll cost_p[N], F_p[N], qq2[N];
int par[N][19], dep[N];

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != 0 && dep[par[u][i]] >= dep[v]) {
            u = par[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
};


void Nozarashi() {

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dep[0] = -1;
    dep[1] = 0;
    queue<ll> qq;
    qq.push(1);
    par[1][0] = 0;
    while (!qq.empty()) {
        ll u = qq.front();
        qq.pop();
        for (ll v: adj[u]) {
            if (v == par[u][0]) continue;
            dep[v] = dep[u] + 1;
            par[v][0] = u;
            qq.push(v);
        }
    }

    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1] != 0) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            } else {
                par[i][j] = 0;
            }
        }
    }

    vector<pair<ll, ll>> queries(q);
    vector<ll> lcas_arr(q);
    for (int j = 0; j < q; j++) {
        ll u, v;
        cin >> u >> v;
        queries[j] = {u, v};
        lcas_arr[j] = lca(u, v);
    }

    vector<ll> ans_arr(q, 1e18);
    vector<bool> visited(n + 1, false);

    for (int p: pri) {
        fill(all(visited), false);
        int c = 0;
        qq2[c++] = 1;
        F_p[1] = cost_p[1];
        visited[1] = true;

        for (int i = 0; i < c; i++) {
            int u = qq2[i];
            for (int v: adj[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                F_p[v] = F_p[u] + (p - a[v] % p) % p;
                qq2[c++] = v;
            }
        }

        for (int j = 0; j < q; j++) {
            int u = queries[j].first;
            int v = queries[j].second;
            int lc = lcas_arr[j];
            ll total = F_p[u] + F_p[v] - 2 * F_p[lc] + (p - a[lc] % p) % p;
            if (total < ans_arr[j]) {
                ans_arr[j] = total;
            }
        }
    }

    for (int j = 0; j < q; j++) {
        cout << ans_arr[j] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1000; i++) {
        if (prime(i)) pri.pb(i);
    }

    for (int i = 1001; i < 2000; i++) {
        if (prime(i)) {
            pri.pb(i);
            break;
        }
    }

    ll t = 1;
    cin >> t;
    while (t--) {
        Nozarashi();
    }
    return 0;
}
