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

const int N = 1e5 + 1;
vector<vector<int>> factors(N);

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int ans = 1e9;
    int cnt = 0;
    map<int, int> fr;
    for (int i = 0, j = 0; i < n; i++) {
        for (auto f: factors[a[i]]) {
            if (f <= m) {
                if (fr[f] == 0) cnt++;
                if (cnt >= m) {
                    ans = min(ans, a[i] - a[j]);
                }
                fr[f]++;
            }
        }

        while (j < i) {
            bool ok = true;
            for (auto f: factors[a[j]]) {
                if (f <= m) {
                    if (fr[f] == 1) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok) break;

            for (auto f: factors[a[j]]) {
                if (f <= m) {
                    fr[f]--;
                    assert(fr[f]);
                }
            }

            j++;

            if (cnt >= m)
                ans = min(ans, a[i] - a[j]);
        }
    }

    if (ans != 1e9) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            factors[j].push_back(i);
        }
    }
    debug(factors[12]);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
