// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define ll long long
#define all(v) v.begin(), v.end()

char in[1 << 24];
struct scanner {
    char const *o;
    scanner() : o(in) { load(); }
    void load() { in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; }
    unsigned readInt() {
        unsigned u = 0;
        while (*o && *o <= 32)
            ++o;
        while (*o >= '0' && *o <= '9')
            u = u * 10 + (*o++ - '0');
        return u;
    }
} sc;

constexpr int N = 2e5 + 5;
int ans = 1e9;
int dist[N];
vector<int> adj[N];

void dfs(int i, int p) {
    for (auto j: adj[i]) {
        if (j == p) continue;
        if (dist[i] + 1 < dist[j]) {
            dist[j] = dist[i] + 1;
            if (dist[j] < ans)
                dfs(j, i);
        } else {
            ans = min(ans, dist[i] + dist[j] + 1);
        }
    }
}

void set_black(int i) {
    ans = min(ans, dist[i]);
    dist[i] = 0;
    dfs(i, -1);
}

void solve() {
    ans = 1e9;
    int n = sc.readInt(), c = sc.readInt() - 1;
    int sq[n - 1];

    for (int i = 0; i < n; i++) adj[i].clear(), dist[i] = 1e9;
    for (int i = 0; i < n - 1; i++) {
        sq[i] = sc.readInt() - 1;
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        u = sc.readInt() - 1, v = sc.readInt() - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set_black(c);

    for (int i = 0; i < n - 1; i++) {
        set_black(sq[i]);
        printf("%d ", ans);
    }
    puts("");

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = sc.readInt();
    while (t--)
        solve();

    return 0;
}
