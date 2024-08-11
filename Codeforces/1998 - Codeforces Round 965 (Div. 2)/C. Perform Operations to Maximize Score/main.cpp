
// https://codeforces.com/contest/1998/problem/C

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);

    ordered_set<pair<int, int>> s, ss;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    sort(all(a));

    debug(a);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].second) {
            int m = n / 2 - 1;
            if (i <= m) m++;
            assert(m < n);
            maxit(ans, a[i].first + k + a[m].first);
        }
    }

    int l = 0, r = 1e9 + 1;

    while (r - l > 1) {
        int x = (r + l) / 2;
        int cnt = 0;
        int kk = k;
        for (int i = n - 1; i >= 0; i--) {
            int y = a[i].first;
            if (a[i].second) {
                int d = max(min(x - y, kk), 0ll);
                kk -= d;
                y += d;
            }
            cnt += y >= x;
        }

        if (cnt >= n - (n / 2) + 1) {
            l = x;
        } else {
            r = x;
        }
    }

    int m1 = l;
    l = 0, r = 1e9 + 1;

    while (r - l > 1) {
        int x = (r + l) / 2;
        int cnt = 0;
        int kk = k;
        for (int i = n - 1; i >= 0; i--) {
            int y = a[i].first;
            if (a[i].second) {
                int d = max(min(x - y, kk), 0ll);
                kk -= d;
                y += d;
            }
            cnt += y >= x;
        }

        if (cnt >= n - (n / 2 + 1) + 1) {
            l = x;
        } else {
            r = x;
        }
    }

    int m2 = l;
    debug(m1, m2);

    for (int i = 0; i < n; i++) {
        if (a[i].second == 0) {
            if (i <= n / 2 - 1) {
                maxit(ans, a[i].first + m2);
            } else {
                maxit(ans, a[i].first + m1);
            }
        }
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
