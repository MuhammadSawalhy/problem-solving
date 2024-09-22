// ﷽
// https://codeforces.com/contest/2009/problem/E

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
    int n, k;
    cin >> n >> k;

    // ans = min x = min ( i * k - (n - i) * k + i * (i + 1) / 2 - (n - i) * (n - i + 1) / 2 )

    int l = 1, r = n;

    auto getsum = [&](int l, int r) {
        return (r * (r + 1) / 2 - l * (l - 1) / 2);
    };

    auto getx = [&](int i) {
        return abs(i * k - (n - i) * k + getsum(0, i - 1) - getsum(i, n - 1));
    };

    while (r - l > 10) {
        // ternary search
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int x1 = getx(m1);
        int x2 = getx(m2);

        if (x1 < x2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    int ans = 1e18;
    for (; l <= r; l++) {
        minit(ans, getx(l));
    }

    cout << ans << endl;
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
