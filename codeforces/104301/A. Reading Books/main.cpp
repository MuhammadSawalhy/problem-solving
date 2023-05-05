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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    for (int i = 1; i < m; i++) {
        b[i] += b[i - 1];
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && b[j] <= a[i]) j++;
        cout << j << ' ';
    }

    cout << '\n';
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
