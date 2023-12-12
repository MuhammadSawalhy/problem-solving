// ﷽
// https://codeforces.com/contest/1903/problem/D2

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

const int N = 1 << 20;
int a[N];
int dpcnt[N];
int dpsum[N][20];

void solve() {
    int n, q;
    cin >> n >> q;

    int OR = 0, AND = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        OR |= a[i];
        AND &= a[i];
    }

    int LIMIT = 62;
    while (LIMIT >= 0 && (OR >> LIMIT & 1 ^ 1)) LIMIT--;
    LIMIT++;

    // all zeros starting from limit

    int mn[64]{};

    for (int i = 62; i >= LIMIT; i--) {
        for (int j = 0; mn[i] <= 1e18 && j < n; j++) {
            mn[i] += (1ll << i) - a[j];
        }
    }

    for (int i = 0; i < n; i++) {
        dpcnt[a[i]]++;
        for (int j = 0; j < LIMIT; j++)
            dpsum[a[i]][j] += a[i] % (1ll << j);
    }

    for (int bit = 0; bit < LIMIT; bit++)
        for (int mask = 0; mask < 1 << LIMIT; mask++)
            if (mask & (1ll << bit)) dpcnt[mask ^ (1ll << bit)] += dpcnt[mask];

    for (int bit = 0; bit < LIMIT; bit++)
        for (int mask = 0; mask < 1 << LIMIT; mask++)
            if (mask & (1ll << bit))
                for (int pref = 0; pref < LIMIT; pref++)
                    dpsum[mask ^ (1ll << bit)][pref] += dpsum[mask][pref];

query:
    while (q--) {
        int k;
        cin >> k;
        for (int i = 62; i >= LIMIT; i--) {
            if (mn[i] > k) continue;
            int ans = 0;
            ans |= (1ll << i);
            k -= mn[i];

            for (int j = i - 1; j >= 0; j--) {
                if (k >= n * (1ll << j)) {
                    ans |= (1ll << j);
                    k -= n * (1ll << j);
                }
            }

            cout << ans << endl;

            goto query;
        }

        int ans = 0;

        for (int i = LIMIT - 1; i >= 0; i--) {
            int newans = ans | 1ll << i;
            int cnt = n - dpcnt[newans];
            int required = cnt * (1ll << i) - (dpsum[ans][i] - dpsum[newans][i]);
            if (required <= k) {
                k -= required;
                ans = newans;
            }
        }

        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
