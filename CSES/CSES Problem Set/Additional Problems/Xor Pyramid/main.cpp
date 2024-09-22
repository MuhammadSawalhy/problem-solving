// ﷽
// https://cses.fi/problemset/task/2419

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

vi getit(int x) {
    if (__popcount(x) == 1) return vi(x, 1);
    int y = x - (1 << (32 - __builtin_clz(x) - 1));
    debug(x, y);
    auto sub = getit(y);
    vi ans(x, 0);
    for (int i = 0; i < y; i++) {
        ans[i] = sub[i];
        ans[x - 1 - i] = sub[i];
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto s = getit(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i])
            ans ^= a[i];
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    for (int i = 1; i < 8; i++) {
        debug(getit(i));
    }

    int t = 1;
    while (t--)
        solve();

    return 0;
}
