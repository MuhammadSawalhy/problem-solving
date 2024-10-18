// ﷽
// https://codeforces.com/contest/2025/problem/C

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
    int k, n;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> fr;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    vector<pii> b(all(fr));
    debug(b);

    queue<pii> d;

    int ans = 0, cur = 0;

    for (int i = sz(b) - 1; ~i; i--) {
        if (i + 1 < n && b[i].first + 1 != b[i + 1].first) {
            while (d.size()) d.pop();
            cur = 0;
        }

        if (d.size() && b[i].first + k <= d.front().first) {
            cur -= d.front().second;
            d.pop();
        }

        d.push({b[i].first, b[i].second});
        cur += b[i].second;
        maxit(ans, cur);
    }

    cout << ans << '\n';
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
