// ﷽
// 10 جُمادى الآخرة 1444
// Jan 02, 2023
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

    int q;
    cin >> q;

    while (q--) {
        ll n;
        cin >> n;
        ll prefix = 0, next = 9, cnt = 1, p = 1;
        n--;
        while (next <= n) {
            prefix = next;
            cnt++;
            p *= 10;
            // 10 * 9 * 2
            // 100 * 9 * 3
            // ...etc
            next += p * 9 * cnt;
        }

        n -= prefix;

        ll x = n / cnt;
        ll y = p + x;
        n -= x * cnt;
        assert(y >= p && y < p * 10);
        cout << to_string(y)[n] << endl;
    }

    return 0;
}
