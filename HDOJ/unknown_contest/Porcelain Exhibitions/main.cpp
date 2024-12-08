// ﷽
// https://acm.hdu.edu.cn/showproblem.php?pid=4129

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

int n, m, mink, maxk, p;

void solve() {
    debug(n, m, mink, maxk, p);
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        cerr << x[i] << ' ' << y[i] << endl;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cerr << "Segment " << x[u] << ' ' << y[u] << ' ' << x[v] << ' ' << y[v] << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n >> m >> mink >> maxk >> p, n && m) {
        solve();
    }

    return 0;
}
