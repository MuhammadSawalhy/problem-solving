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

#define ll long long
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p: primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    vector<int> min_power(n + 1, INT_MAX);
    vector<int> min_power_cnt(n + 1);
    vector<int> mult_cnt(n + 1);

    int g = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int gg = g;
        g = gcd(x, g);
        int lost = gg / g;
        debug(i, x, lost);

        while (lost > 1) {
            int pwr = 0;
            int p = minp[lost];
            bool ok = true;
            if (x % p == 0) ok = false; // not lost

            while (lost % p == 0) {
                lost /= p;
            }

            if (!ok) continue;

            if (min_power[p] > pwr) {
                min_power[p] = pwr;
                min_power_cnt[p] = 1;
            } else if (min_power[p] == pwr) {
                min_power_cnt[p]++;
            }

            ans = max(ans, mult_cnt[p]);
        }


        while (x > 1) {
            int pwr = 0;
            int p = minp[x];
            mult_cnt[p]++;

            if (i > 0 && min_power[p] == INT_MAX) {
                min_power[p] = 0;
            }

            while (x % p == 0) {
                pwr++;
                x /= p;
            }

            debug(p, pwr);

            if (min_power[p] > pwr) {
                min_power[p] = pwr;
                min_power_cnt[p] = 1;
            } else if (min_power[p] == pwr) {
                min_power_cnt[p]++;
            }

            if (min_power[p] == 0)
                ans = max(ans, mult_cnt[p]);
            else
                ans = max(ans, i + 1 - min_power_cnt[p]);

            debug(p, min_power[p], min_power_cnt[p], mult_cnt[p]);
            debug(ans);
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    sieve(2e5 + 5);

    int t;
    cin >> t;
    while (t--) {
        debug(t);
        solve();
    }

    return 0;
}
