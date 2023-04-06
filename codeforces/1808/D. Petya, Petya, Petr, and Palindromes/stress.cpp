// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    for (int i = 0; i + k <= n; i++) {
        for (int j = i, r = i + k - 1; j < r; j++, r--) {
            ans += a[j] != a[r];
        }
    }

    cout << ans;

    return 0;
}
