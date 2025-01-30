// ﷽
// https://codeforces.com/contest/2055/problem/D

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

#define double long double

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double s = a[0];
    double x = k;
    a[0] = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > x) a[i] = max(x, a[i] - s);
        if (a[i] <= x) {
            a[i] = min(a[i] + s, x);
            x = max(x, a[i] + k);
        } else {
            double needed = (a[i] - x) / 2;
            s += needed;
            a[i] -= needed;
            x = a[i] + k;
        }
        if (x >= l) break;
    }

    debug(s, x);

    if (x < l) {
        s += l - x;
    }

    cout << (int) (s * 2 + 0.001) << endl;
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
