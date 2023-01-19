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

    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int y = x - a[i] - a[j];
            if (mp.count(y)) {
                cout << mp[y].first + 1 << " " << mp[y].second + 1 << " " << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
        for (int j = i - 1; ~j; j--) {
            mp[a[i] + a[j]] = {j, i};
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
