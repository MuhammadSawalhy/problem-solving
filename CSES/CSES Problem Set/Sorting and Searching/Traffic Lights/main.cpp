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

    int x, n;
    cin >> x >> n;

    multiset<int> ms;
    multiset<int> d;

    ms.insert(0);
    ms.insert(x);
    d.insert(x);

    while (n--) {
        int p;
        cin >> p;

        auto it = ms.lower_bound(p + 1);

        debug(p, *it);

        d.erase(d.find(*it - *prev(it)));
        d.insert(p - *prev(it));
        d.insert(*it - p);

        ms.insert(p);

        cout << *prev(d.end()) << " ";
    }

    cout << endl;

    return 0;
}
