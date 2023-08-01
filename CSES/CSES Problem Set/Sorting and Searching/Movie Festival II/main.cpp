// ﷽
#include <bits/stdc++.h>

using namespace std;

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int inf = 1e9;
    int n, k, a, b;
    cin >> n >> k;

    array<int, 2> ranges[n];
    for (int i = 0; i < n; i++) {
        cin >> ranges[i][1] >> ranges[i][0];
    }

    sort(ranges, ranges + n);
    
    multiset<int> s;

    for (int i = 0; i < k; i++) {
        s.insert(-inf);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        // find a good place for the current range
        auto it = s.upper_bound(ranges[i][1]);
        if (it != s.begin()) {
            ans++;
            it = prev(it);
            s.erase(it);
            s.insert(ranges[i][0]);
        }
        assert(s.size() == k);
    }

    cout << ans;

    return 0;
}
