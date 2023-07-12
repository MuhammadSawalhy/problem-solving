// ﷽
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> wins(n);
    int s = 0, mine = 0;
    int order[n];
    iota(order, order + n, 0);
    sort(order, order + n, [&](int i, int j) { return a[i] == a[j] ? i > j : a[i] < a[j]; });

    for (int i = 0; i < n; i++) {
        wins[i] += i;
        s += a[order[i]];
        if (s <= m)
            mine++;
        else {
            if (i > 0 && s - a[order[i - 1]] >= a[order[i]] && s - a[order[i - 1]] <= m && order[i - 1] < order[i]) {
                wins[order[i - 1]]++;
            } else {
                wins[order[i]]++;
            }
        }
    }

    debug(mine, wins);
    wins.resize(unique(all(wins)) - wins.begin());
    cout << wins.end() - upper_bound(all(wins), mine) + 1 << endl;
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
