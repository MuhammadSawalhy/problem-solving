// ﷽
// https://codeforces.com/contest/1950/problem/F

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
    int a, b, c;
    cin >> a >> b >> c;
    debug(a, b, c);

    if (c != a + 1) {
        cout << -1 << endl;
        return;
    }


    if (a == 0) {
        cout << b << endl;
        return;
    }

    int x = 1, last = 1;
    int ans = 0;
    while (x * 2 + 1 <= a + c) {
        x = x * 2 + 1;
        last *= 2;
        ans += 1;
    }

    if (x != a + c) {
        ans++;
    } else {
        last = 0;
    }

    debug(x, last);

    x = a + c - x;
    assert(x & 1 ^ 1);

    last -= x / 2;

    b -= min(b, last);

    debug(b);

    ans += (b + c - 1) / c;

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
