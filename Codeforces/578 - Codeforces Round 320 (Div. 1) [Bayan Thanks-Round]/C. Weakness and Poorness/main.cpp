// ﷽
// https://codeforces.com/contest/1993/problem/E#

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
#define pii pair<int, int>
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    double l = -1e10, r = 1e10;

    auto calc = [&](double x) {
        double ans = 0, mx = 0, mn = 0;

        for (int i = 0; i < n; i++) {
            mx = max({ mx - x + a[i], - x + a[i], 0.0 });
            mn = min({ mn - x + a[i], - x + a[i], 0.0 });
            maxit(ans, mx, abs(mn));
        }

        return ans;
    };

    for (int iter = 0; iter < 200; iter++) {
        double a = l + (r - l) / 3;
        double b = r - (r - l) / 3;
        auto A = calc(a), B = calc(b);
        debug(a, b, A, B);
        if (A > B) {
            l = a;
        } else if (A < B) {
            r = b;
        } else {
            l = a, r = b;
        }
        l = min(l, r);
        r = max(l, r);
    }

    cout << fixed << setprecision(15) << calc(l) << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}

