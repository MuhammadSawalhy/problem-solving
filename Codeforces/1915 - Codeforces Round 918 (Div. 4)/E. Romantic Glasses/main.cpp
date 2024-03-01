// ﷽
// https://codeforces.com/contest/1915/problem/E

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, bool> valid;
    valid[0] = true;
    bool ok = false;
    pair<int, int> cur;
    debug(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1) cur.second += a[i];
        else cur.first += a[i];
        int d = cur.second - cur.first;
        debug(i, d, cur);
        ok |= valid[d];
        valid[d] = true;
    }

    cout << (ok ? "YES" : "NO") << endl;
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
