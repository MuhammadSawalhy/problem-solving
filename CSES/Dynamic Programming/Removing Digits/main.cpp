// ﷽
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

    int ans = 0;
    while (n) {
        int md = 0, x = n;
        while (x) {
            md = max(md, x % 10);
            x /= 10;
        }
        n -= md;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
