// ﷽
// https://codeforces.com/contest/2044/problem/E

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

int inter(int a, int b, int l, int r) {
    l = max(l, a);
    r = min(r, b);
    if (r >= l) return r - l + 1;
    return 0;
}

void solve() {
    long long k, a, b, l, r;
    cin >> k >> a >> b >> l >> r;

    int kk = 1;
    int ans = 0;

    while (kk < 1e10) {
        int L = (l + kk - 1) / kk;
        int R = r / kk;
        ans += inter(a, b, L, R);
        kk *= k;
    }

    cout << ans << endl;
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
