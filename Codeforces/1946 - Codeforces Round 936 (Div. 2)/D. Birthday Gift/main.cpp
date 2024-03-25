// ﷽
// https://codeforces.com/contest/1946/problem/D

#include <bits/stdc++.h>
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, x, ans = -1;
    cin >> n >> x, x++;
    vector<int> a(n), newa;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int b = 30; ~b; b--) {
        int y = 0, i = 0;
        for (newa.clear(); i < sz(a); i++) {
            y ^= a[i];
            if (~y >> b & 1) newa.push_back(y), y = 0;
        }
        if (x >> b & 1) {
            if (~y >> b & 1) maxit(ans, sz(newa));
        } else if (y >> b & 1) break;
        else a = newa;
    }
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
