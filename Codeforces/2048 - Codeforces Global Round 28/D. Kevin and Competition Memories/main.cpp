// ﷽
// https://codeforces.com/contest/2048/problem/D

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

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a + 1, a + n);
    debug_itr(b, m);
    for (int i = 0; i < m; i++) {
        if (b[i] <= a[0]) b[i] = 1;
        else {
            int j = (a + n) - lower_bound(a + 1, a + n, b[i]);
            b[i] = j + 1;
        }
    }
    debug_itr(b, m);
    sort(b, b + m);

    for (int k = 1; k <= m; k++) {
        int sum = 0;
        for (int j = k; j <= m; j += k) {
            sum += b[j - 1];
        }
        cout << sum << ' ';
    }
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
