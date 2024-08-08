// ﷽
// https://codeforces.com/contest/1997/problem/D

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
vector<int> adj[N];
int a[N];

int dfs(int i) {
    int mn = 1e18;

    for (auto j: adj[i]) {
        minit(mn, dfs(j));
    }

    if (mn == 1e18) return a[i];

    if (i == 0) {
        return mn + a[i];
    }

    if (mn >= a[i]) {
        mn = a[i] + (mn - a[i]) / 2;
    }

    debug(i, mn);
    return mn;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p, p--;
        adj[p].push_back(i);
    }

    debug(n);

    cout << dfs(0) << endl;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
