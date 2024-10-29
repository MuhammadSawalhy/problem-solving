// ﷽
// https://csacademy.com/ieeextreme18/task/sierpinski/statement/

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

int getit(int x, int y) {
    if (x <= 2) return 1;
    int sz = 2;
    while (sz < x) sz = sz << 1 | 1;
    int prev = (sz - 1) / 2;

    int newy = y;
    int newx = x - prev - 1;
    if (y > newx && y <= x - newx) return 0;

    int middle = x - newx * 2;
    if (y > x - newx) {
        newy = y - newx - middle;
    }

    return getit(newx, newy);
}

void solve() {
    int x, y;
    cin >> x >> y;
    cout << getit(x, y) << '\n';
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
