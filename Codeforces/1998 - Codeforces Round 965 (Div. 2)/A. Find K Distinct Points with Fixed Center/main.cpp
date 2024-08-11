// ﷽
// https://codeforces.com/contest/1998/problem/A

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
    int x, y, k;
    cin >> x >> y >> k;

    int xx[k], yy[k];
    for (int i = 0; i < k; i++) {
        xx[i] = x;
    }
    for (int i = 0; i < k / 2; i++) {
        xx[i] = x - i - 1;
        xx[k - 1 - i] = x + i + 1;
    }
    for (int i = 0; i < k; i++) {
        cout << xx[i] << ' ' << y << endl;
    }
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
