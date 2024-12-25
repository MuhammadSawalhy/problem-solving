// ﷽
// https://codeforces.com/contest/2051/problem/E

#include <bits/stdc++.h>
#include <cmath>
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
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        events.push_back({a[i] + 1, -1});
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        events.push_back({b[i] + 1, 0});
    }
    sort(all(events));

    int ans = 0;
    int neg = 0;
    int cnt = n;
    for (int i = 0; i < sz(events);) {
        if (neg <= k) {
            maxit(ans, (events[i].first - 1) * cnt);
        }
        int j = i;
        while (j < sz(events) && events[j].first == events[i].first) j++;
        for (int r = i; r < j; r++) {
            if (events[r].second == -1) {
                neg++;
            } else {
                neg--;
                cnt--;
            }
        }
        i = j;
    }

    cout << ans << endl;
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
