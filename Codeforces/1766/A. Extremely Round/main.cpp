// Date: 12-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
    int n;
    cin >> n;

    int p = 1;
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        for (int d = 1; d <= 9; d++) {
            ans += d * p <= n;
        }
        p *= 10;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
