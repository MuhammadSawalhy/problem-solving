// ﷽
#include <bits/stdc++.h>
#include <queue>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    vector<vector<int>> fr(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], fr[a[i]].push_back(i);

    priority_queue<array<int, 3>> pq;
    priority_queue<int> p;

    int ans[2][n];
    for (int i = 1; i <= n; i++) {
        if (fr[i].size() == 2) {
            pq.push({i, fr[i][0], fr[i][1]});
        } else if (fr[i].size() == 0) {
            p.push(i);
        } else if (fr[i].size() == 1) {
            ans[0][fr[i][0]] = i;
            ans[1][fr[i][0]] = i;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if (pq.size() != p.size()) {
        cout << "NO" << endl;
        return;
    }

    while (pq.size()) {
        auto [v, i, j] = pq.top();
        pq.pop();
        auto x = p.top();
        p.pop();
        if (x > v) {
            cout << "NO" << endl;
            return;
        }
        ans[0][i] = x; 
        ans[0][j] = v; 
        ans[1][j] = x; 
        ans[1][i] = v; 
    }

    cout << "YES" << endl;
    for (int j: {0, 1})
        for (int i = 0; i < n; i++)
            cout << ans[j][i] << " \n"[i == n - 1];
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
