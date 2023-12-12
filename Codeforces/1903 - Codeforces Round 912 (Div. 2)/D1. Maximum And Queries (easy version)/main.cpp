// ﷽
// https://codeforces.com/contest/1903/problem/D1

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        b = a;
        int ans = 0;
        int KK;
        __int128 k, kk;
        cin >> KK, k = kk = KK;

        for (int i = 62; i >= 0; i--) {
            kk = k;
            for (int j = 0; j < n; j++) {
                if (b[j] & (1ll << i)) continue;
                k -= (1ll << i) - (b[j] & ((1ll << i) - 1));
            }
            if (k < 0) k = kk;
            else {
                for (int j = 0; j < n; j++) {
                    if (b[j] & (1ll << i)) continue;
                    b[j] += (1ll << i) - (b[j] & ((1ll << i) - 1));
                }
                ans |= 1ll << i;
            }
        }

        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
