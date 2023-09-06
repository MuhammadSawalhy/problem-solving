// ﷽
// https://codeforces.com/contest/1859/problem/C
// Codeforces -> Codeforces Round 892 (Div. 2) -> C. Another Permutation Problem

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

void solve() {
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int p = 1; p <= n; p++) {
            long long a = 0;
            long long mx = 0;
            for (int j = 1, k = 1; j <= n && k <= n; j++, j+= j == i, k++, k+= k == p) {
                a += k * j;
                mx = k * j;
            }

            if (mx > i * p) {
                a += i * p - mx;
            }

            ans = max(ans, a);
        }
    }

    cout << ans << '\n';
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
