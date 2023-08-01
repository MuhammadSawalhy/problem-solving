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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    array<int, 3> ranges[n];

    for (int i = 0; i < n; i++)
        cin >> ranges[i][0] >> ranges[i][1], ranges[i][2] = i;

    sort(ranges, ranges + n);

    debug_itr(ranges, n);
    
    int ans[n];

    int r = 1;
    set<int> rooms;
    set<pair<int, int>> ends;
    for (int i = 0; i < n; i++) {
        while (ends.lower_bound({ranges[i][0], -1}) != ends.begin()) {
            int i = ends.begin()->second;
            rooms.insert(ans[i]);
            ends.erase(ends.begin());
        }
        if (rooms.size()) {
            ans[ranges[i][2]] = *rooms.begin();
            rooms.erase(rooms.begin());
        } else {
            ans[ranges[i][2]] = r++;
        }
        ends.insert({ranges[i][1], ranges[i][2]});
    }

    cout << r - 1 << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
