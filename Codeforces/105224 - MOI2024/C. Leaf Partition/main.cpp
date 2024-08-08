#include <bits/stdc++.h>

#define ll long long
#define mk make_pair
#define fi first
#define se second

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    for (; (c < '0' || c > '9'); c = getchar()) {
        if (c == '-') f = -1;
    }
    for (; (c >= '0' && c <= '9'); c = getchar()) x = x * 10 + (c & 15);
    return x * f;
}

const int mod = 998244353;
int ksm(int x, ll y, int p = mod) {
    int ans = 1;
    y %= (p - 1);
    for (int i = y; i; i >>= 1, x = 1ll * x * x % p)
        if (i & 1) ans = 1ll * ans * x % p;
    return ans % p;
}
int inv(int x, int p = mod) { return ksm(x, p - 2, p) % p; }
mt19937 rnd(time(0));
int randint(int l, int r) { return rnd() % (r - l + 1) + l; }
void add(int &x, int v) {
    x += v;
    if (x >= mod) x -= mod;
}
void Mod(int &x) {
    if (x >= mod) x -= mod;
}
int cmod(int x) {
    if (x >= mod) x -= mod;
    return x;
}

template<typename T>
void cmax(T &x, T v) { x = max(x, v); }
template<typename T>
void cmin(T &x, T v) { x = min(x, v); }

const int N = 10005;
const int K = 22;

int f[N][K][K], n, k, sz[N], t[K][K];
vector<int> G[N];

void DP(int u, int fa) {
    memset(f[u], 63, sizeof(f[u]));
    if (G[u].size() == 1) return f[u][0][1] = f[u][1][0] = 0, sz[u] = 1, void();
    for (int v: G[u])
        if (v != fa) DP(v, u);
    // cout<<"DP "<<u<<" "<<fa<<endl;
    f[u][0][0] = 0;
    for (int v: G[u])
        if (v != fa) {
            memset(t, 63, sizeof(t));
            // cout<<" + v = "<<v<<" -> f = \n";
            for (int i = 0; i <= min(k, sz[u]); i++)
                for (int j = 0; j + i <= min(k, sz[u]); j++) {
                    for (int p = 0; p <= min(k, sz[v]); p++)
                        for (int q = 0; q + max(j, p) <= k; q++) {
                            for (int c = 0; c <= min(i, p); c++) cmin(t[i + p - c][j + q], f[u][i][j] + f[v][p][q] + p);
                        }
                }
            sz[u] += sz[v];
            for (int i = 0; i <= min(k, sz[u]); i++)
                for (int j = 0; j + i <= min(k, sz[u]); j++) f[u][i][j] = t[i][j];
            // for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)if(f[u][i][j]<=100)cout<<" "<<i<<","<<j<<" : "<<f[u][i][j]<<endl;
        }

    memset(t, 63, sizeof(t));
    for (int i = 0; i <= min(k, sz[u]); i++)
        for (int j = 0; i + j <= min(k, sz[u]); j++) {
            for (int c = 0; c <= i; c++) cmin(t[i - c][j + c], f[u][i][j]);
        }
    for (int i = 0; i <= min(k, sz[u]); i++)
        for (int j = 0; i + j <= min(k, sz[u]); j++) {
            f[u][i][j] = t[i][j];
        }
    // cout<<" -> f "<<u<<" = \n";
    // for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)if(f[u][i][j]<=100)cout<<" "<<i<<","<<j<<" : "<<f[u][i][j]<<endl;
}

signed main(void) {

#ifndef ONLINE_JUDGE
    // freopen("in.txt","r",stdin);
    // freopen("c.in","r",stdin);
#endif

    n = read(), k = read();
    vector<int> deg(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u = read(), v = read();
        deg[u]++, deg[v]++;
        G[u].emplace_back(v), G[v].emplace_back(u);
    }
    int Leaf = 0;
    for (int i = 1; i <= n; i++) Leaf += (deg[i] == 1);
    if (Leaf < k) return puts("-1"), 0;
    int root = 0;
    for (int i = 1; i <= n; i++)
        if (G[i].size() >= 2) {
            root = i;
            break;
        }
    DP(root, 0);
    cout << 2 * f[root][0][k] << endl;

    return 0;
}
