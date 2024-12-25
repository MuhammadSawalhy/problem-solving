// ﷽
// https://codeforces.com/contest/2051/problem/C

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
    int n, m, k;
    cin >> n >> m >> k;

    int a[m];

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    set<int> vals;
    for (int i = 0; i < n; i++) {
        vals.insert(i + 1);
    }
    int b[k];
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        vals.erase(b[i]);
    }

    if (k < n - 1) {
        cout << string(m, '0') << '\n';
    } else if (k == n) {
        cout << string(m, '1') << '\n';
    } else {
        string s = string(m, '0');
        s[*vals.begin() - 1] = '1';
        cout << s << '\n';
    }
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
