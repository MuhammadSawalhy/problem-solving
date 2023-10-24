// ﷽
// https://codeforces.com/contest/1884/problem/C

#include <algorithm>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

int n, m;
int solve(vector<pair<int, int>> ranges) {
    vector<pair<int, int>> points;
    sort(all(ranges), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    while (ranges.size() && ranges.back().second == m) {
        ranges.pop_back();
    }

    for (int i = 0; i < ranges.size(); i++) {
        points.emplace_back(ranges[i].first, -1);
        points.emplace_back(ranges[i].second, +1);
    }
    sort(all(points));

    debug(points);

    int cur = 0;
    int mx = 0;
    for (int i = 0; i < points.size(); i++) {
        cur -= points[i].second;
        maxit(mx, cur);
    }

    debug(mx);
    return mx;
}

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> points;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        points.emplace_back(l, r);
    }

    debug(n, m);
    int ans = solve(points);
    for (int i = 0; i < n; i++) {
        points[i].first = m - points[i].first + 1;
        points[i].second = m - points[i].second + 1;
        swap(points[i].first, points[i].second);
    }
    ans = max(ans, solve(points));
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
