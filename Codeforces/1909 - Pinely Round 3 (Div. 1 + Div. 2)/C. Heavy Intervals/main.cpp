// ﷽
// https://codeforces.com/contest/1909/problem/C

#include <bits/stdc++.h>
#include <queue>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    cin >> n;
    vector<int> l;
    vector<int> c(n);
    vector<pair<int, int>> point;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        point.push_back({l, -1});
    }

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        point.push_back({l, +1});
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(all(point));
    priority_queue<int> pq;
    for (int i = 0; i < 2 * n; i++) {
        if (point[i].second == -1) {
            pq.push(point[i].first);
        } else {
            int x = pq.top();
            pq.pop();
            l.push_back(point[i].first - x);
        }
    }

    sort(rall(l));
    sort(all(c));
    debug(l);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += l[i] * c[i];
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
