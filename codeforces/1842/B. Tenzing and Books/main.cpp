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
#define all(v) v.begin(), v.end()

void solve() {
    int n, x;
    cin >> n >> x;

    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];


    int res = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & ~x) != 0) break;
        res |= a[i];
    }
    for (int i = 0; i < n; i++) {
        if ((b[i] & ~x) != 0) break;
        res |= b[i];
    }
    for (int i = 0; i < n; i++) {
        if ((c[i] & ~x) != 0) break;
        res |= c[i];
    }

    if (res == x) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
