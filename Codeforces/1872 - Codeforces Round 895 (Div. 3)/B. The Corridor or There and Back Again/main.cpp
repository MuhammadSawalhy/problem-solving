// ﷽
// https://codeforces.com/contest/1872/problem/B
// Codeforces -> Codeforces Round 895 (Div. 3) -> B. The Corridor or There and Back Again

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

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));

    debug(v);

    int k = 1000;
    for (int i = 0; i < n; i++) {
        if (v[i].first > k) break;

        k = min(k, v[i].first + (v[i].second - 1) / 2);
    }

    cout << k << endl;
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
