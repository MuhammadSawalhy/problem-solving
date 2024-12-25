// ﷽
// https://codeforces.com/contest/2051/problem/B

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
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int m = mid / 3 * 3;
        int d = (a + b + c) * m / 3;
        if (mid >= m + 1) {
            d += a;
        }
        if (mid >= m + 2) {
            d += b;
        }
        debug(mid, d);
        if (d >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
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
