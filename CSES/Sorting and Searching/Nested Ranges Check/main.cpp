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

    int n;
    cin >> n;
    bool contains[n], contained[n];
    memset(contains, 0, sizeof contains);
    memset(contained, 0, sizeof contained);

    vector<array<int, 4>> a;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back({l, -1, -r, i});
        a.push_back({r, 1, -l, i});
    }

    sort(all(a));

    // maximum right for not ended ranges
    int mr = 0;
    // maximum left for ended ranges
    int ml = 0;
    for (auto [x, type, lr, i]: a) {
        lr *= -1;
        if (type == -1) {
            if (mr >= lr) contained[i] = true;
            mr = max(mr, lr);
        } else {
            if (ml >= lr) contains[i] = true;
            ml = max(ml, lr);
        }
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << endl;

    return 0;
}
