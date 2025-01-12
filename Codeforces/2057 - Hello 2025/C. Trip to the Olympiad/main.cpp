// ﷽
// https://codeforces.com/contest/2057/problem/C

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
    int l, r;
    cin >> l >> r;
    int ans = 1e18;
    int ii, jj, kk;
    for (int i = l; i < min(r, l + 15); i++) {
        for (int j = i + 1; j <= min(r, l + 15); j++) {
            for (int k = j + 1; k <= min(r, l + 15); k++) {
                int cur = (i ^ j) + (j ^ k) + (i ^ k);
                if (cur < ans) ans = cur, ii = i, jj = j, kk = k;
            }
        }
    }

    int a = l, b = r, c = l;
    int i = 30;
    while ((a >> i & 1) == (b >> i & 1)) {
        i--;
    }
    for (int j = i - 1; j >= 0; j--) {
        if ((a >> j & 1) == (b >> j & 1)) {
            if (a >> j & 1) b ^= 1 << j;
            else a ^= 1 << j;
        }
    }
    while (c == a || c == b) c++;
    debug((a ^ b) + (a ^ c) + (b ^ c));
    cout << a << ' ' << b << ' ' << c << endl;
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
