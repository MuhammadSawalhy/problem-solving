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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int u, v, inc = 0;
        cin >> u >> u;

        int cnt[n], cur = 1;
        for (int i = 0; i < n - 2; i++) {
            cin >> v;
            if (v < u) {
                cnt[inc++] = cur;
                cur = 1;
            } else {
                cur++;
            }
            u = v;
        }

        cnt[inc++] = cur;

        int prevlevel = 1, curlevel = 0;
        int ans = 0;

        debug_itr(cnt, cnt + inc);

        for (int i = 0; i < inc;) {
            curlevel = 0;
            for (int j = i; j < min(inc, i + prevlevel); j++)
                curlevel += cnt[j];
            ans++;
            i += prevlevel;
            prevlevel = curlevel;
        }

        cout << ans << '\n';
    }
    return 0;
}
