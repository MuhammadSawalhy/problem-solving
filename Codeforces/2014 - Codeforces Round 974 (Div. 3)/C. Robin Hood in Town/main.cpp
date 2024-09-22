// ﷽
// https://codeforces.com/contest/2014/problem/C

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxit(mx, a[i]);
    }

    if (n <= 2) {
        cout << "-1\n";
        return;
    }

    int s = -1, e = 1e18;
    while (e - s > 1) {
        int x = (s + e) / 2;

        int cnt = 0;
        bool done = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx && !done)
                cnt += (a[i] + x) * n * 2 < (sum + x), done = true;
            else
                cnt += a[i] * n * 2 < (sum + x);
        }

        if (cnt > n / 2) {
            e = x;
        } else {
            s = x;
        }
    }

    cout << e << endl;
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
