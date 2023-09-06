// ﷽
// https://codeforces.com/contest/1852/problem/B
// Codeforces -> Codeforces Round 887 (Div. 1) -> B. Imbalanced Arrays

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;

    int a[n];
    deque<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back({a[i], i});
    }

    vector<int> ans(n);
    sort(all(v));

    for (int x = n, y = 0; x >= 1; x--) {
        if (v.back().first == y + x) { // +
            ans[v.back().second] = x;
            v.pop_back();
            y++;
        } else if (v.front().first == y) { // -
            ans[v.front().second] = -x;
            v.pop_front();
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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
