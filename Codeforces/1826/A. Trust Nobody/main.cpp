// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    ll a[n];
    map<int, int> fr;
    for (int i = 0; i < n; i++) cin >> a[i], fr[a[i]]++;

    sort(a, a + n);
    int m = unique(a, a + n) - a;

    int x = 0;
    int i = 0;
    while (i < m && n - x >= a[i]) {
        x += fr[a[i++]];
    }

    for (int j = 0; j < i; j++) {
        if (n - x < a[j]) {
            cout << "-1\n";
            return;
        }
    }

    cout << n - x << endl;
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
