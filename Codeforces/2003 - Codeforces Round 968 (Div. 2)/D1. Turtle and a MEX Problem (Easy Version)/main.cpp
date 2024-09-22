// ﷽
// https://codeforces.com/contest/2003/problem/D1

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr[n];
    pair<int, int> mex[n];

    int mx = 0;
    debug(n);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int a;
            cin >> a;
            arr[i].push_back(a);
        }

        sort(all(arr[i]));
        arr[i].erase(unique(all(arr[i])), arr[i].end());
        debug(arr[i]);
        int j = 0;
        int x = 0;
        while (j < arr[i].size() && x == arr[i][j]) x++, j++;
        mex[i].first = x;
        x++;
        while (j < arr[i].size() && x == arr[i][j]) x++, j++;
        mex[i].second = x;
        maxit(mx, x);
    }

    debug_itr(mex, n);
    int ans = 0;
    if (m >= mx) ans += m * (m + 1) / 2 - mx * (mx - 1) / 2;

    for (int x = min(m, mx - 1); x >= 0; x--) {
        ans += mx;
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
