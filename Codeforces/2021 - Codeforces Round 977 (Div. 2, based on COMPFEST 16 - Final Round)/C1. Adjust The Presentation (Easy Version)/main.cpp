// ﷽
// https://codeforces.com/contest/2021/problem/C1

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    vector<int> ind(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        ind[a[i]] = i;
    }

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        cin >> b[i], b[i]--;
    }

    map<int, bool> app;

    vector<int> bb;
    for (int i = 0; i < m; i++) {
        if (app[b[i]]) continue;
        app[b[i]] = true;
        bb.push_back(b[i]);
    }

    debug(a);
    debug(b);
    debug(bb);

    bool ok = true;
    for (int i = 0; i < sz(bb); i++) {
        if (bb[i] != a[i]) ok = false;
    }

    if (ok) cout << "YA\n";
    else cout << "TIDAK\n";
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
