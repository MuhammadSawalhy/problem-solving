// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int l, n, m;
    cin >> l >> n >> m;

    vector<pair<int, int>> a(n), b(m);
    for (int i = 0, j = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0, j = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }

    int ans = 0;

    int i = 0, j = 0;
    ll ii = 0, jj = 0, vi, vj;
    while (i < n || j < m) {
        while (i < n && ii <= jj) {
            auto [V, L] = a[i++];
            if (vi == -1) {
                vi = V;
                ii += L;
                continue;
            }

            if (ii + L > jj) {
                ans += (jj - ii) * (vj == V);
            } else {
                ans += L * (vj == V);
            }

            ii += L;
            vi = V;
        }

        while (j < m && jj < ii) {
            auto [V, L] = b[j++];

            if (jj + L > ii) {
                ans += (ii - jj) * (vi == V);
            } else {
                ans += L * (vi == V);
            }

            jj += L;
            vj = V;
        }
    }

    cout << ans << endl;

    return 0;
}
