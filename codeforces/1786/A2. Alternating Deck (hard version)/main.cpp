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

void solve() {
    int n;
    cin >> n;

    int cnt = 2;
    int a[2] = {1, 0}, b[2] = {};

    bool alice = 0;

    while (a[0] + a[1] + b[0] + b[1] + cnt + cnt + 1 <= n) {
        assert(cnt % 2 == 0);

        if (alice) {
            a[0] += (cnt + 1) / 2;
            a[1] += cnt / 2;
            cnt++;
            a[0] += (cnt + 1) / 2;
            a[1] += cnt / 2;
        } else {
            b[0] += cnt / 2;
            b[1] += (cnt + 1) / 2;
            cnt++;
            b[0] += cnt / 2;
            b[1] += (cnt + 1) / 2;
        }

        cnt++;
        alice ^= 1;
    }

    cnt = n - (a[0] + a[1] + b[0] + b[1]);
    debug(n, cnt);
    if (alice) {
        a[0] += (cnt + alice) / 2;
        a[1] += (cnt + !alice) / 2;
    } else {
        b[0] += (cnt + alice) / 2;
        b[1] += (cnt + !alice) / 2;
    }

    cout << a[0] << " " << a[1] << " " << b[0] << " " << b[1] << endl;
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
