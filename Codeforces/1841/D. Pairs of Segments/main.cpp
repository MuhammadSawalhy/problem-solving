// ﷽
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

void solve() {
    int n;
    cin >> n;
    pair<int, int> ranges[n];

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].second >> ranges[i].first;
    }

    sort(ranges, ranges + n);

    int ans = 0;
    // contian ranges that can be used later
    // or all will be reject in case of a pair is taken
    set<int> pool;

    int last_pair_end = -1;

    for (int i = 0; i < n; i++) {
        if (ranges[i].second <= last_pair_end) {
            ans++;
            continue;
        }
        // either pool has ranges or not
        int possible = pool.size() ? *prev(pool.end()) : -1;
        if (possible >= ranges[i].second) {
            ans += pool.size() - 1;
            last_pair_end = ranges[i].first;
            pool.clear();
            continue;
        }
        // insert end of the current range
        pool.insert(ranges[i].first);
    }

    ans += pool.size();

    cout << ans << endl;
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
