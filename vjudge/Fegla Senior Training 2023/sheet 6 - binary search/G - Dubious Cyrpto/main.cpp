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

int l, r, m;

void solve() {
    cin >> l >> r >> m;

    for (int a = l; a <= r; a++) {
        // check if b is always r
        // check when c is always l
        int M = m / a * a;
        if (m - M <= r - l && M > 0) {
            int b = l;
            while (M + b - m < l) b++;
            cout << a << ' ' << b << ' ' << (M + b - m) << '\n';
            return;
        }

        M += a;
        if (M - m <= r - l) {
            int b = r;
            while (M + b - m > r) b--;
            cout << a << ' ' << b << ' ' << (M + b - m) << '\n';
            return;
        }
    }
    cout << "-1\n";
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
