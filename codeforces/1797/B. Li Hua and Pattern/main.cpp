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

void solve() {
    int n, k;
    cin >> n >> k;

    int v[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    int diff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            diff += v[i][j] != v[n - 1 - i][n - 1 - j];
    }

    assert(diff % 2 == 0);
    diff /= 2;

    if (diff > k) {
        cout << "NO\n";
        return;
    }

    if (((k - diff) % 2 == 0) || (n & 1)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
