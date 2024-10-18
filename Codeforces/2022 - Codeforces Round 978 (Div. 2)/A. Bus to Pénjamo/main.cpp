// ﷽
// https://codeforces.com/contest/2022/problem/A

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
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    int ans = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        odd += a[i] & 1;
        ans += a[i] / 2;
    }

    r -= ans;
    debug(odd, r);

    if (odd > r) {
        odd -= r;
        r -= odd;
        ans *= 2;
        ans += r;
        cout << ans << '\n';
    } else {
        ans *= 2;
        ans += odd;
        cout << ans << '\n';
    }
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
