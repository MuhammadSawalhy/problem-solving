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

    int n, m, t, p;
    cin >> n >> m;

    multiset<int> h;
    for (int i = 0; i < n; i++) {
        cin >> p;
        h.insert(p);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        auto f = h.upper_bound(t);
        if (f == h.begin()) {
            cout << -1 << endl;
            continue;
        }

        --f;
        cout << *f << endl; 
        h.erase(f);
    }

    return 0;
}
