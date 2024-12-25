// ﷽
// https://codeforces.com/contest/2049/problem/B

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool ss = false, pp = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == 's') ss = true;
        if (s[i] == 'p') pp = true;
    }

    if (n == 1 || ss ^ pp || s == string(n, '.')) {
        cout << "YES\n";
        return;
    }

    if (s[0] == 's') {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (s[i] == 's') ok = false;
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }

    if (s[n - 1] == 'p') {
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'p') ok = false;
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
