// ﷽
// https://codeforces.com/contest/1901/problem/E

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


const int N = 5e5 + 5;
int a[N], val[N];
int n;
vector<int> adj[N];

int ans;

int getup(multiset<int> &mx, int possum, int cnt, int x) {
    int val;
    if (mx.size() > 1) {
        val = max({x, *prev(mx.end()), x + *prev(mx.end()) + *prev(prev(mx.end())), cnt > 1 ? x + possum : (ll) -1e18});
    } else if (mx.size() == 1) {
        val = max({x, *prev(mx.end())});
    } else {
        val = x;
    }

    return val;
}


int dfs(int i, int p) {
    multiset<int> mx;

    int possum = 0, cnt = 0;
    for (int j: adj[i]) {
        if (j == p) continue;
        int v = dfs(j, i);
        mx.insert(v);
        if (v > 0) possum += v, cnt++;
    }

    return val[i] = getup(mx, possum, cnt, a[i]);
}

int getans(multiset<int> &mx, int possum, int cnt, int x) {
    int a = max({x, cnt != 2 ? x + possum : 0ll, 0ll});
    if (mx.size()) {
        maxit(a, x + *prev(mx.end()));
    }
    if (mx.size() > 2) {
        maxit(a, x + *prev(mx.end()) + *prev(prev(mx.end())) + *prev(prev(prev(mx.end()))));
    }
    return a;
}

void calc(int i, int p, int up) {
    multiset<int> mx;

    int possum = max(up, 0ll), cnt = 0;

    if (i != 0) {
        mx.insert(up);
        cnt += up > 0;
    }

    for (int j: adj[i]) {
        if (j == p) continue;
        mx.insert(val[j]);
        if (val[j] > 0) possum += val[j], cnt++;
    }

    for (int j: adj[i]) {
        if (j == p) continue;
        mx.erase(mx.find(val[j]));
        if (val[j] > 0) possum -= val[j], cnt--;
        calc(j, i, getup(mx, possum, cnt, a[i]));
        if (val[j] > 0) possum += val[j], cnt++;
        mx.insert(val[j]);
    }


    int ANS = getans(mx, possum, cnt, a[i]);
    debug(i, ANS, mx, possum, cnt);
    maxit(ans, ANS);
}

void solve() {
    cin >> n;
    debug("==>", n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    dfs(0, -1);
    debug_itr(val, n);
    calc(0, -1, 0);
    cout << max(ans, 0ll) << endl;
    for (int i = 0; i < n; i++) adj[i].clear();
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
