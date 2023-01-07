// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
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

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (mp.count(x - a)) {
            cout << mp[x - a] << " " << i << endl;
            return 0;
        }
        mp[a] = i;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
